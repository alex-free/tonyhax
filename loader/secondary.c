#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "str.h"
#include "audio.h"
#include "bios.h"
#include "cdrom.h"
#include "cfgparse.h"
#include "debugscreen.h"
#include "gpu.h"
#include "patcher.h"
#include "io.h"
#include "crc.h"
#include "integrity.h"

uint8_t sscmd;

const char * p5_localized;
const char * region_name;

uint8_t cdcontrollerver[4];

bool calibrate_laser = 0; // Only Japanese VC2 and VC3 consoles need this so it is off by default
bool bugged_setsession = 0; // VC0 A, VC0 B, and VC1 A CDROM Controller BIOS versions all have a buggy SetSession command that requires a special work around to use
bool enable_unlock = 1; // Disabled on VC0 A, VC0 B, and VC1 A Japanese CDROM Controller BIOS versions automatically. On VC1+ the testregion command is run and if the region is Japan it is also disabled.
bool controller_input = 0; // When enabled, debug_write does not display the repeat messages counter. This is so we can draw a blank line and then wait for controller input using vsync in debug_write
bool first_rev = 0; // VC0 A and VC0 B do not need any anti-piracy patching as they are immune to addtional copy protection routines because of the lack of the ReadTOC command in the CDROM Controller BIOS Firmware

// Loading address of tonyhax, provided by the secondary.ld linker script
extern uint8_t __RO_START__, __BSS_START__, __BSS_END__;

void log_bios_version() {
	/*
	 * "System ROM Version 4.5 05/25/00 A"
	 * By adding 11 we get to Version, which we'll compare as a shortcut
	 */
	const char * version;

	if (strncmp(BIOS_VERSION + 11, "Version", 7) == 0) {
		version = BIOS_VERSION + 19;
	} else {
		version = "1.0 or older";
	}

	debug_write("Sys BIOS: %s", version);
}

bool backdoor_cmd(uint_fast8_t cmd, const char * string) {
	uint8_t cd_reply[16];

	// Send command
	cd_command(cmd, (const uint8_t *) string, strlen(string));

	// Check if INT5, else fail
	if (cd_wait_int() != 5) {
		return false;
	}

	// Check length
	uint_fast8_t reply_len = cd_read_reply(cd_reply);
	if (reply_len != 2) {
		return false;
	}

	// Check there is an error flagged
	if (!(cd_reply[0] & 0x01)) {
		return false;
	}

	// Check error code
	if (cd_reply[1] != 0x40) {
		return false;
	}

	return true;
}

bool unlock_drive() {
    #if !defined STEALTH
	    debug_write("Drive region: %s", region_name);
    #endif
	// Note the kernel's implementation of strlen returns 0 for nulls.
	if (!backdoor_cmd(0x50, NULL) || !backdoor_cmd(0x51, "Licensed by") || !backdoor_cmd(0x52, "Sony") || !backdoor_cmd(0x53, "Computer") || !backdoor_cmd(0x54, "Entertainment") || !backdoor_cmd(0x55, p5_localized) || !backdoor_cmd(0x56, NULL)) {
        #if !defined STEALTH
		    debug_write("Backdoor failed");
        #endif
		return false;
	}

	return true;
}

#if !defined TOCPERFECT
void wait_lid_status(bool open) {
	uint8_t cd_reply[16];
	uint8_t expected = open ? 0x10 : 0x00;

	do {
		// Issue Getstat command
		// We cannot issue the BIOS CD commands yet because we haven't called CdInit
		cd_command(CD_CMD_GETSTAT, NULL, 0);

		// Always returns 3, no need to check
		cd_wait_int();

		// Always returns one, no need to check either
		cd_read_reply(cd_reply);

	} while ((cd_reply[0] & 0x10) != expected);
}

bool is_lid_open() {
	uint8_t cd_reply[16];

	// Issue Getstat command
	// We cannot issue the BIOS CD commands yet because we haven't called CdInit
	cd_command(CD_CMD_GETSTAT, NULL, 0);

	// Always returns 3, no need to check
	cd_wait_int();

	// Always returns one, no need to check either
	cd_read_reply(cd_reply);

    if(cd_reply[0]==0x10) {
        return true;
	} else {
        return false;
    }   
}

bool licensed_drive() {
    uint8_t getid_response[9];
	unsigned char gid;

    while(1) {
    	cd_command(CD_CMD_GETID,0,0);
		gid = cd_wait_int();
		if(gid!=5)
			break;
	}
	
    cd_wait_int();
	cd_read_reply(getid_response);

    if(getid_response[0]==0x02 && getid_response[1]==0x00 && getid_response[2]==0x20 && getid_response[3]==0x00) {
        return true;
	} else {
        return false;
    }   
}
#endif

void try_boot_cd() {
	int32_t read;
	uint8_t cbuf[4]; // CD Command Buffer

	#if !defined TOCPERFECT
		if(enable_unlock) {
			debug_write("Put in a backup or import disc, then close the drive lid");
			wait_lid_status(true);
			wait_lid_status(false);
		} else {
            if(is_lid_open() || !licensed_drive()) {	// If lid is open drive is not licensed, and if lid is closed we check if it is licenesed (if it is not licensed but not open then the drive is closed and the user can open it and license it)    
				debug_write("Put in a real NTSC-J PSX game disc, then block the lid sensor");
				wait_lid_status(true);
				wait_lid_status(false); // Blocking lid sensor = 'closing lid'

	            debug_write("Initializing CD");	// Drive will be in licensed state after this is successful
				if (!CdInit()) {
					debug_write("Init failed");
                    debug_write("Try unblocking then blocking the lid sensor again");
					return;
				}
			} // Drive is licensed and the lid is 'closed' at this point
            debug_write("Drive is licensed");
            debug_write("Stopping motor");
			cd_command(CD_CMD_STOP,0,0); cd_wait_int(); cd_wait_int();
			
			void * address;		// For Calculating BIOS Functions
			uint8_t j;			// Joypad
			uint8_t padbuf[2][0x22];	// Joypad Buffers
			// BIOS Function InitPAD(buf1,sz1,buf2,sz2)
			address = (uint32_t *) GetB0Table()[0x12];
			((void (*)(uint8_t*,uint32_t,uint8_t*,uint32_t)) address)(padbuf[0],0x22,padbuf[1],0x22);
			// BIOS Function StartPAD()
			address = (void *) (GetB0Table()[0x13]);
			((void (*)(void)) address)();	// BIOS StartPad
			debug_write("Keep the lid sensor blocked until turning off the console");
            debug_write("Remove the real NTSC-J PSX game disc");
            debug_write("Put in a backup/import disc, then press X on controller 1"); // Thanks MottZilla!
            controller_input = 1; // disable the repeat counter used in debug_write until controller input is done
				while(1) { 
					j = padbuf[0][3] ^ 0xFF;
					if( j == 0x40)
						break;

					debug_write(" "); // Vblank wait for controller input
				}	
		    controller_input = 0; // Set debug_write back to normal (enable repeat counter) as controller input is done
			// StopPAD() as we are done using Joypad input
			address = (void *) (GetB0Table()[0x14]);
			((void (*)(void)) address)();	// BIOS StopPad
		}
	#endif

	if(!enable_unlock) {
		if(bugged_setsession) {
			#if !defined STEALTH
				debug_write("Sending SetSessionSuperUltraCommandSmash v2, please wait");
			#endif
			sscmd = 2; cd_command(CD_CMD_SET_SESSION,(unsigned char *)&sscmd,1); cd_wait_int(); cd_wait_int(); // There is a 3rd response we are ignoring by sending SetSession 1 next ASAP after SetSession 2.
			sscmd = 1; cd_command(CD_CMD_SET_SESSION,(unsigned char *)&sscmd,1); cd_wait_int(); cd_wait_int();
		} else {
			#if !defined STEALTH
				debug_write("Sending SetSession 1");
			#endif
			sscmd = 1; cd_command(CD_CMD_SET_SESSION,(unsigned char *)&sscmd,1); cd_wait_int(); cd_wait_int();
		}

		if(calibrate_laser) { // VC2 and VC3s do auto Bias/Gain calibration when reading the real NTSC-J PS1 disc. A swapped in CD-R or just a different disc in general needs this to be updated
        #if !defined STEALTH		
        	debug_write("Calibrating laser");
        #endif		
        	cbuf[0] = 0x50; cbuf[1] = 0x38; cbuf[2] = 0x15; cbuf[3] = 0x0A;	// ModeCompensateTrackingAutoGain
			cd_command(CD_CMD_TEST,&cbuf[0],4); 
			cd_wait_int();
		}
	}

    #if !defined STEALTH
        debug_write("Reinitializing kernel"); // We have to reinitilize, stop, and init in that order to prevent the process from possibly freezing at this point
    #endif
    bios_reinitialize();
	bios_inject_disc_error();

    #if !defined STEALTH
        debug_write("Stopping motor");
    #endif	
    cd_command(CD_CMD_STOP, NULL, 0); cd_wait_int(); cd_wait_int();

    #if !defined STEALTH
	    debug_write("Initializing CD");
    #endif
	if (!CdInit()) {
		#if !defined STEALTH
			debug_write("Init failed");
		#endif
		return;
	}

	/*
	 * Use the space the BIOS has allocated for reading CD sectors.
	 *
	 * The English translation of Mizzurna Falls (J) (SLPS-01783) depends on the header being
	 * present here (see issue #95 in GitHub).
	 *
	 * This address varies between PS1 and PS2.
	 */
	uint8_t * data_buffer = (uint8_t *) (bios_is_ps1() ? 0xA000B070 : 0xA000A8D0);

    #if !defined STEALTH
    	debug_write("Checking game region");
    #endif

    #if defined TOCPERFECT	
    	if (CdReadSector(1, 12, data_buffer) != 1) { // Real license data sector is copied to sector 12 by PS1 DemoSwap Patcher before it writes Japanese license data to sector 4
			#if !defined STEALTH
				debug_write("Failed to read sector");
			#endif
		return;
		}
	#else
    	if (CdReadSector(1, 4, data_buffer) != 1) {
			debug_write("Failed to read sector");
			return;
		}
	#endif

	#if !defined STEALTH
	    const char * game_region;
    #endif	
    bool game_is_pal = false;
	/*
	 * EU: "          Licensed  by          Sony Computer Entertainment Euro pe   "
	 * US: "          Licensed  by          Sony Computer Entertainment Amer  ica "
	 * JP: "          Licensed  by          Sony Computer Entertainment Inc.",0x0A
	 *                                                                  |- character we use, at 0x3C
	 */
	switch (data_buffer[0x3C]) {
		case 'E':
		    #if !defined STEALTH
			    game_region = "European";
            #endif			
            game_is_pal = true;
			break;
	#if !defined STEALTH
		case 'A':
			game_region = "American";
			break;
		case 'I':
			game_region = "Japanese";
			break;
		default:
			game_region = "unknown";
			break;
    #else
		default:
			break;
    #endif        
	}
    
    #if !defined STEALTH
    	debug_write("Game's region is %s. Using %s video.", game_region, game_is_pal ? "PAL" : "NTSC"); // Does not work on PS2, only on original PS1s.
    #endif

	// Defaults if no SYSTEM.CNF file exists, matches shell program behavior
	uint32_t tcb = BIOS_DEFAULT_TCB;
	uint32_t event = BIOS_DEFAULT_EVCB;
	uint32_t stacktop = BIOS_DEFAULT_STACKTOP;
	const char * bootfile = "cdrom:PSX.EXE;1";

	char bootfilebuf[32];

    #if defined TOCPERFECT
    	#if !defined STEALTH
    		debug_write("Loading SYSTEM.CN2");
    	#endif
		int32_t cnf_fd = FileOpen("cdrom:SYSTEM.CN2;1", FILE_READ);
    #else
    	#if !defined STEALTH
    		debug_write("Loading SYSTEM.CNF");
    	#endif
   		int32_t cnf_fd = FileOpen("cdrom:SYSTEM.CNF;1", FILE_READ);
   	#endif
    
	if (cnf_fd > 0) {
		read = FileRead(cnf_fd, data_buffer, 2048);
		FileClose(cnf_fd);

		if (read == -1) {
            #if !defined STEALTH
			    debug_write("Read error %d", GetLastError());
            #endif			
            return;
		}

		// Null terminate
		data_buffer[read] = '\0';

		config_get_hex((char *) data_buffer, "TCB", &tcb);
		config_get_hex((char *) data_buffer, "EVENT", &event);
		config_get_hex((char *) data_buffer, "STACK", &stacktop);
		if (config_get_string((char *) data_buffer, "BOOT", bootfilebuf)) {
			bootfile = bootfilebuf;
		}
	} else {
		uint32_t errorCode = GetLastError();
		if (errorCode != FILEERR_NOT_FOUND) {
			#if !defined STEALTH
				debug_write("Open error %d", errorCode);
			#endif
			return;
		}
		#if !defined STEALTH
			debug_write("Not found");
		#endif
	}

	// Use string format to reduce ROM usage
	debug_write(" * %s = %x", "TCB", tcb);
	debug_write(" * %s = %x", "EVENT", event);
	debug_write(" * %s = %x", "STACK", stacktop);
	debug_write(" * %s = %s", "BOOT", bootfile);

    #if !defined STEALTH
    	debug_write("Configuring kernel");
    #endif	   
    SetConf(event, tcb, stacktop);

    #if !defined STEALTH
	    debug_write("Clearing RAM");
    #endif	
    uint8_t * user_start = (uint8_t *) 0x80010000;
	bzero(user_start, &__RO_START__ - user_start);

    #if !defined STEALTH
    	debug_write("Reading executable header");
    #endif
	int32_t exe_fd = FileOpen(bootfile, FILE_READ);
	if (exe_fd <= 0) {
		#if !defined STEALTH
			debug_write("Open error %d", GetLastError());
		#endif
		return;
	}

	read = FileRead(exe_fd, data_buffer, 2048);

	if (read != 2048) {
		#if !defined STEALTH
			debug_write("Read error %d", GetLastError());
		#endif
		return;
	}

	exe_header_t * exe_header = (exe_header_t *) (data_buffer + 0x10);

	// If the file overlaps tonyhax, we will use the unstable LoadAndExecute function since that's all we can do.
	if (exe_header->load_addr + exe_header->load_size >= &__RO_START__) { // Comment out this line and the one mentioned below to force loadandexecute bios call
		#if !defined STEALTH
			debug_write("Executable won't fit. Using buggy BIOS call.");
		#endif
		if (game_is_pal != gpu_is_pal()) {
			#if !defined STEALTH
				debug_write("Switching video mode");
			#endif
			debug_switch_standard(game_is_pal);
		}

		if(!first_rev)
			activate_anti_anti_piracy(bootfile, (int32_t) exe_header->load_addr);

		// Restore original error handler
		bios_restore_disc_error();

		LoadAndExecute(bootfile, exe_header->initial_sp_base, exe_header->initial_sp_offset);
		return;
	} // Comment out this line and the one above to force loadandexecute bios call

    #if !defined STEALTH
    	debug_write("Loading executable (%d bytes @ %x)", exe_header->load_size, exe_header->load_addr);
    #endif

	if (FileRead(exe_fd, exe_header->load_addr, exe_header->load_size) != (int32_t) exe_header->load_size) {
		#if !defined STEALTH
			debug_write("Read error %d", GetLastError());
		#endif
		return;
	}
	
	if(!first_rev)
		activate_anti_anti_piracy(bootfile, (int32_t) exe_header->load_addr);

	FileClose(exe_fd);

	if (game_is_pal != gpu_is_pal()) {
		#if !defined STEALTH
			debug_write("Switching video mode");
		#endif
		debug_switch_standard(game_is_pal);
	}

	#if !defined STEALTH
		debug_write("Starting");
	#endif

	// Restore original error handler
	bios_restore_disc_error();

	// Games from WarmBoot start with interrupts disabled
	EnterCriticalSection();

	// FlushCache needs to be called with interrupts disabled
	FlushCache();

	DoExecute(exe_header, 0, 0);
}

void main() {
	// Undo all possible fuckeries during exploiting
	bios_reinitialize();
	// Mute the audio
	audio_halt();

	// Initialize debug screen
	debug_init();

    debug_write("Integrity check %sed", integrity_ok ? "pass" : "fail");
	if (!integrity_ok) {
		return;
	}

	bios_inject_disc_error();
    #if !defined STEALTH
	    log_bios_version();
        debug_write("Initializing CD");
    #endif	
    if (!cd_drive_init()) {
		#if !defined STEALTH
			debug_write("Init failed");
		#endif
		return;
	}

	sscmd = 0x20; cd_command(CD_CMD_TEST,(unsigned char *)&sscmd,1); cd_wait_int(); 
	cd_read_reply(cdcontrollerver);	// Test Command $19,$20 gets the CDROM BIOS
	#if !defined STEALTH
		debug_write("CD BIOS: %x", *(uint32_t*) cdcontrollerver);
	#endif
   	if(cdcontrollerver[0]==0x94) {    
        bugged_setsession = 1;
        enable_unlock = 0; // VC0 A and VC0 B are both from 1994 and don't support the getregion command to figure out if it is unlockable or not.
        first_rev = 1;
    } 
    else if(cdcontrollerver[1] == 0x05 && cdcontrollerver[2] == 0x16 && cdcontrollerver[0] == 0x95 && cdcontrollerver[3] == 0xC1) {     
        bugged_setsession = 1; // NOTE I don't think this will ever be triggered but just in case. Earliest SCPH-3000s and late SCPH-1000s are VC0B and later SCPH-3000s are VC1B. Only unlockable systems have VC1A it seems.
        bugged_setsession = 1;
    }
    else if((cdcontrollerver[3] == 0xC2) || (cdcontrollerver[3] == 0xC3)) {   
        calibrate_laser = 1;
    }

	if(enable_unlock) {
		uint8_t cd_reply[16];
		// Run "GetRegion" test
		uint8_t test = CD_TEST_REGION;
		cd_command(CD_CMD_TEST, &test, 1);

		// Should succeed with 3
		if (cd_wait_int() != 3) {
			#if !defined STEALTH
				debug_write("Region read failed");
			#endif
			return;
		}

		// Read actual region text and null terminate it
		int len = cd_read_reply(cd_reply);
		cd_reply[len] = 0;

		// Compare which is the fifth string we have to send to the backdoor
		if (strcmp((char *) cd_reply, "for Europe") == 0) {
			region_name = "European";
			p5_localized = "(Europe)";
		} else if (strcmp((char *) cd_reply, "for U/C") == 0) {
			region_name = "American";
			p5_localized = "of America";
		} else if (strcmp((char *) cd_reply, "for NETEU") == 0) {
			region_name = "NetYaroze (EU)";
			p5_localized = "World wide";
		} else if (strcmp((char *) cd_reply, "for NETNA") == 0) {
			region_name = "NetYaroze (US)";
			p5_localized = "World wide";
		} else if (strcmp((char *) cd_reply, "for Japan") == 0) {
			enable_unlock = 0;
		} else {
			// +4 to skip past "for "
			#if !defined STEALTH
			    debug_write("Unsupported region: %s", (char *) (cd_reply + 4));
			#endif
			return;
		}

		if(enable_unlock) { // Check again, this could be false now
			#if defined TOCPERFECT // Get TOC via reset + unlock instead of unlock + opening/closing the drive lid for auto loading in TOCPerfect, thanks MottZilla!
				#if !defined STEALTH
					debug_write("Resetting drive");
				#endif
				cd_drive_reset();
			#endif
				#if !defined STEALTH
					debug_write("Unlocking drive");
				#endif
			if (!unlock_drive())
				return;
		}
	}

	while (1) {
		try_boot_cd();

		#if !defined STEALTH
		    debug_write("Reinitializing kernel");
        #endif
    	bios_reinitialize();
    	bios_inject_disc_error();
	}
}

void __attribute__((section(".start"))) start() {
	// Clear BSS
	bzero(&__BSS_START__, &__BSS_END__ - &__BSS_START__);

	// Execute integrity test
	integrity_test();
	main();

	while(1);
}
