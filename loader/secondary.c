
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include "str.h"
#include "audio.h"
#include "bios.h"
#include "cdrom.h"
#include "cfgparse.h"
#include "crc.h"
#include "debugscreen.h"
#include "gpu.h"
#include "ap-bypass.h"
#include "integrity.h"
#include "io.h"

//to test ROM functionality in emulation via boot CD, uncomment the following 2 lines:
//#undef ROM
//#define ROM

//to test XSTATION ROM functionality in emulation via boot CD, uncomment the following 4 lines:
//#undef XSTATION
//#define XSTATION
//#undef ROM
//#define ROM

//to test behavior without any APv2 bypasses enabled (useful for testing D0 AP bypass codes via save game file gameshark functionality rather then internal activate_anti_piracy() function), uncomment:
//#define AP_BYPASS_DISABLE

uint8_t sscmd;
uint8_t cdcontrollerver[4];

const char * p5_localized;
const char * region_name;

bool calibrate_laser = 0; // Only Japanese VC2 and VC3 consoles need this so it is off by default
bool bugged_setsession = 0; // VC0 A, VC0 B, and VC1 A CDROM Controller BIOS versions all have a buggy SetSession command that requires a special work around to use
bool enable_unlock = 1; // Disabled on VC0A and VC0B Japanese CDROM Controller BIOS versions automatically. On VC1A+ the testregion command is run and if the region is Japan it is also disabled.
bool controller_input = 0; // When enabled, debug_write does not display the repeat messages counter. This is so we can draw a blank line and then wait for controller input using vsync in debug_write.
bool first_rev = 0; // VC0 A and VC0 B do not need any anti-piracy patching as they are immune to additional copy protection routines because of the lack of the ReadTOC command in the CDROM Controller BIOS Firmware.
bool installed_cheat_engine = 0; // The cheat engine is installed when parse_memcard_save_gameshark_codes() completes. Some games may go on to set explicit anti-piracy bypass GameShark codes however, so to prevent the cheat engine from being installed twice (which is wasteful) we set a flag here.
bool did_read_mc = 0; // We need to set the GameShark codes AFTER the last bios_reintialize(). I want to call bios_reinitilize() after reading the memory card data to prevent anything screwy in booting games, so we can just parse the data later after the final bios_reinitialize since it's still in RAM.
uint8_t number_of_gameshark_code_lines; // part of my basic format to store codes, this tells us how many we will activate
uint8_t * user_start = (uint8_t *) 0x80010000;
uint16_t mc_base = 0x102; // start of gs code data in memory card buffer

// Loading address of tonyhax, provided by the secondary.ld linker script
extern uint8_t __RO_START__, __BSS_START__, __BSS_END__;

// for controller input functions
void * address;		// For Calculating BIOS Functions
uint8_t j;			// Joypad
uint8_t padbuf[2][0x22];	// Joypad Buffers

#if !defined TOCPERFECT
#if defined ROM
void run_shell() {
	// runs Sony BIOS. Can access CD Player/Memory Card Manager. Can not boot any discs, even ones that normally work without the flash cart inserted in the console. This has been adapted code from the SCPH-1001 decomp: https://github.com/ogamespec/psxdev/blob/97fbb2d03e5aff4449097afd2b59690002cb2341/reverse/Main.c#L395

	debug_write("Starting Sony BIOS...");
	memcpy((void*)0x80030000, (void*)0xBFC18000, 0x67FF0); // uses 0x80030000-0x80077FF0
	FlushCache();
	((void (*)(void))0x80030000)();
}
#endif

void controller_input_start() {
	controller_input = 1; // disable the repeat counter used in debug_write until controller input is done, see debugscreen.c
	// BIOS Function InitPAD(buf1,sz1,buf2,sz2)
	address = (uint32_t *) GetB0Table()[0x12];
	((void (*)(uint8_t*,uint32_t,uint8_t*,uint32_t)) address)(padbuf[0],0x22,padbuf[1],0x22); // BIOS InitPAD(buf1,sz1,buf2,sz2) exec
	// BIOS Function StartPAD()
	address = (void *) (GetB0Table()[0x13]);
	((void (*)(void)) address)();	// BIOS StartPad exec
}

void controller_input_stop() { // this doubles as 'closing' the memory card functions
	controller_input = 0; // Set debug_write back to normal (enable repeat counter) as controller input is done
	// BIOS Function StopPAD()
	address = (void *) (GetB0Table()[0x14]);
	// StopPAD() as we are done using Joypad input
	((void (*)(void)) address)();	// BIOS StopPad exec
}

void mc_controller_wait_on_error() {
	for(volatile int i = 0; i < 0x100000; i++); // Pause to not spam a memory card read error message if O is pressed down
}

void read_memcard() {
/*
PSX Official Docs

InitCARD
Initialize Memory Card BIOS.
Library Header File Introduced Documentation Date
libcard.lib libapi.h 3.0 12/14/98
Syntax
void InitCARD(
long val) Specify sharing with controller
Explanation
Initializes the Memory Card BIOS and enters an idle state. val specifies whether or not there is sharing with
the controller. (0: not shared; 1: shared.)
When the BIOS is subsequently put into operation by StartCARD(), the low-level interface functions that
begin with “ _card” can be used directly.
The Memory Card file system uses these interfaces internally, so InitCARD() needs to be executed before
_bu_init().
There is no effect on the controller.
*/

/*
No $ PSX SPX File Error info

File Error Numbers for B(54h) and B(55h)
  00h okay (though many successful functions leave old error code unchanged)
  02h file not found
  06h bad device port number (tty2 and up)
  09h invalid or unused file handle
  10h general error (physical I/O error, unformatted, disk changed for old fcb)
  11h file already exists error (create/undelete/rename)
  12h tried to rename a file from one device to another device
  13h unknown device name
  16h sector alignment error, or fpos>=filesize, unknown seektype or ioctl cmd
  18h not enough free file handles
  1Ch not enough free memory card blocks
  FFFFFFFFh invalid or unused file handle passed to B(55h) function
*/
	debug_write("Reading MC...");
	int32_t read;
	// BIOS Function InitCard(pad_enable)
	int32_t pad_enable = 1; 
	address = (uint32_t *) GetB0Table()[0x4A];
	((void (*)(int32_t*)) address)(&pad_enable);
	// BIOS Function StartCard()
	address = (void *) (GetB0Table()[0x4B]);
	((void (*)(void)) address)();
	// BIOS Function _bu_init()
	address = (void *) (GetB0Table()[0x55]);
	((void (*)(void)) address)();
	int32_t mc_fd = FileOpen("bu00:TONYHAXINTGS", FILE_READ);

	// The kernel will fail to read if we don't wait a bit (here, ~1/10th of a second) (NOTE: this is not exactly 1/10th of a second, what I'm doing here, it is a bit more). This is a known issue as specified in LIBOVR46.PDF section 5-11: "If read() or write() is issued immediately after open(), an error occurs". I noticed that entry.S does this so I do it here as well now
	mc_controller_wait_on_error();

	if(mc_fd == -1) {
		mc_controller_wait_on_error();
		debug_write("Can not read MC, read error %d", GetLastError());
		#if defined FREEPSXBOOT
			debug_write("Ensure the FreePSXBoot memory card has been removed");
		#endif
		debug_write("Please try reinserting MC");
	}

	if (mc_fd > 0) {
		read = FileRead(mc_fd, user_start, 0x2000); // read the entire file "TONYHAXINTGS" to the start of 'user RAM' (which will be cleared later before booting an executable). So 0x80010000-0x80012000 in RAM contains the contents of "TONYHAXINTGS". 
		// 8192 % 64 = 128
		FileClose(mc_fd);
		
		if (read == -1) {
			mc_controller_wait_on_error();
			debug_write("TONYHAXINTGS read error %d", GetLastError());
		} else {
			number_of_gameshark_code_lines = user_start[mc_base + 1];
			debug_write("%d code lines detected", number_of_gameshark_code_lines);

			uint8_t sum;
			uint8_t prev = 0;
			uint8_t next;
			uint8_t checksum_in_save_file = user_start[mc_base];

			for (int i = 0x103; i < 0x2000; i++)
			{
				//debug_write("%x: @ %x", &user_start[i], user_start[i]);
				next = user_start[i];
				sum = prev + next;
				sum &= 0xFF;
				prev = sum;
			}

			if(checksum_in_save_file == sum) {
				debug_write("Checksum: %x Verified", sum);
				did_read_mc = 1; // set flag to parse codes uploaded to RAM, right before clearing RAM itself and booting the game
			} else {
				debug_write("Checksum: %x did not match the expected checksum %x!", sum, checksum_in_save_file);
				debug_write("No codes enabled, the TONYHAXINTGS file may corrupted");
			}
		}
	}
}

void parse_memcard_save_gameshark_codes() {
	/*
	TONYHAXINTGS format:

	0x00-0x101 = static save file data

	0x102 = checksum generated by thigsgen

	0x103 = number of code lines in hex

	0x104-0x107 = gameshark code address (may or may not include code prefix i.e. D0, E0, 30, or 80 could be 0x104)

	0x108-0x109 = gameshark code mod value
		
	0x110-0x103 = 2nd gameshark code address

	0x114-0x115 = 2nd gameshark code mod value (and then so on and so on for number of code lines in hex number)
	*/

	uint32_t gameshark_code_address;
	uint8_t gs_code_type;

	/*
	uint32_t sum;
	uint8_t prev = 0;
	uint8_t next;
	for (int i = 0; i < 0x2000; i++)
	{
		debug_write("%x: @ %x", &user_start[i], user_start[i]);
		next = user_start[i];
		sum = prev + next;
		sum &= 0xFF;
		prev = sum;
	}
	debug_write("Memory card buffer checksum: %x", sum);
	for (volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause
	*/

	for(int i = 0; i < number_of_gameshark_code_lines; i++) {
		
		gs_code_type = user_start[mc_base + 5];
			
		if(
			(gs_code_type == 0xD0) || 
			(gs_code_type == 0xD1) || 
			(gs_code_type == 0xD2) || 
			(gs_code_type == 0xD3) || 
			(gs_code_type == 0xE0) || 
			(gs_code_type == 0xE1) ||
			(gs_code_type == 0xE2) || 
			(gs_code_type == 0xE3) || 
			(gs_code_type == 0x30)
		) {
			user_start[mc_base + 5] = 0x80; // we need to convert the prefix to the real address first byte of 0x80 for the cheat engine
		}

		gameshark_code_address = user_start[mc_base + 2] + (user_start[mc_base + 3] << 8) + (user_start[mc_base + 4] << 16) + (user_start[mc_base + 5] << 24);
		//debug_write("GS Code Addr: %x", gameshark_code_address);

		if(
			(gs_code_type == 0x80) || 
			(gs_code_type == 0xD0) || 
			(gs_code_type == 0xD1) || 
			(gs_code_type == 0xD2) || 
			(gs_code_type == 0xD3)

		) {
			uint16_t gameshark_code_mod_val = user_start[mc_base + 6] + (user_start[mc_base + 7] << 8);
			//debug_write("GS Code Mod Val: %x", gameshark_code_mod_val);
			add_16bit_code(gameshark_code_address, gameshark_code_mod_val, gs_code_type);
		}

		if(
			(gs_code_type == 0x30) || 
			(gs_code_type == 0xE0) || 
			(gs_code_type == 0xE1) || 
			(gs_code_type == 0xE2) || 
			(gs_code_type == 0xE3) 

		) {
			uint8_t gameshark_code_mod_val = user_start[mc_base + 6];
			//debug_write("GS Code Mod Val: %x", gameshark_code_mod_val);
			add_8bit_code(gameshark_code_address, gameshark_code_mod_val, gs_code_type);
		}
			
		mc_base = (mc_base + 6); // advance 6 bytes from current val
	}
}
#endif // TOCPERFECT

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

	debug_write("Console: %s", bios_is_ps1() ? "PS1": "PS2");
	debug_write("System BIOS: %s", version);
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
	debug_write("Drive region: %s", region_name);

	// Note the kernel's implementation of strlen returns 0 for nulls.
	if (
			!backdoor_cmd(0x50, NULL) ||
			!backdoor_cmd(0x51, "Licensed by") ||
			!backdoor_cmd(0x52, "Sony") ||
			!backdoor_cmd(0x53, "Computer") ||
			!backdoor_cmd(0x54, "Entertainment") ||
			!backdoor_cmd(0x55, p5_localized) ||
			!backdoor_cmd(0x56, NULL)
	) {
		debug_write("Backdoor failed");
		return false;
	}

	return true;
}

#if !defined TOCPERFECT
void wait_lid_status(bool open) {
	uint8_t cd_reply[16];
	
	controller_input_start();

	uint8_t expected = open ? 0x10 : 0x00;
	do {

		j = padbuf[0][3] ^ 0xFF;
		debug_write(" "); // Vblank wait for controller input

#if defined ROM // this is more optimized for variable button presses then otherwise if we didn't test both statements in an else if
		if(j == 0x40) { // X button
			controller_input_stop();
			run_shell(); // launch Sony BIOS
		} else if(j == 0x20) { // Circle button
			read_memcard();
		}
#else // booting the shell is unnecessary for every other boot method besides the ROM so we don't include it
		if(j == 0x20) { // Circle button
			read_memcard();
		}
#endif // ROM

		// Issue Getstat command
		// We cannot issue the BIOS CD commands yet because we haven't called CdInit
		cd_command(CD_CMD_GETSTAT, NULL, 0);

		// Always returns 3, no need to check
		cd_wait_int();

		// Always returns one, no need to check either
		cd_read_reply(cd_reply);

	} while ((cd_reply[0] & 0x10) != expected);

	controller_input_stop();
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
#endif // TOCPERFECT

void re_cd_init() {
	debug_write("Reinitializing kernel"); 
	bios_reinitialize();
	bios_inject_disc_error();
	debug_write("Stopping Motor"); // Significantly improves reading data from disc
	cd_command(CD_CMD_STOP, NULL, 0); cd_wait_int(); cd_wait_int();
	
	debug_write("Initializing CD");
	if (!CdInit()) {
		debug_write("Init failed");
		return;
	}
}

void try_boot_cd() {
	int32_t read;
#if defined FREEPSXBOOT
	debug_write("Remove the FreePSXBoot memory card now from your console");
#elif defined ROM
	debug_write("With the CD drive open, press X to boot the Sony BIOS or");
	debug_write("Press O to enable GS codes");
#endif

#if !defined XSTATION
	uint8_t cbuf[4]; // CD Command Buffer

#if !defined TOCPERFECT
	if(enable_unlock) {
		#if !defined ROM
		debug_write("With the CD drive open, press O to enable GS codes");
		#endif
		debug_write("Put in a backup or import disc, then close the drive lid");
		wait_lid_status(true); // doesn't wait during the ROM method, unsure why but it is what we want as it allows us to auto-boot with the ROM boot method
		wait_lid_status(false);
	} else {
		if(is_lid_open() || !licensed_drive()) {	// If lid is open drive is not licensed, and if lid is closed we check if it is licensed (if it is not licensed but not open then the drive is closed and the user can open it and license it)
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

		debug_write("Press O to enable GS codes");
		controller_input_start();

		debug_write("Keep the lid sensor blocked until turning off the console");
		debug_write("Remove the real NTSC-J PSX game disc");
		debug_write("Put in a backup/import disc, then press X"); // Thanks MottZilla!
            
		while(1) { 
			j = padbuf[0][3] ^ 0xFF;

			if(j == 0x40) {
				break; // X button boots disc
			} else if(j == 0x20) { // Circle button enables codes
				read_memcard(); // this allows Japanese console users to enable user supplied GameShark codes without having to unblock the lid sensor, resetting authentication which would just be more unnecessary steps.
			}

			debug_write(" "); // Vblank wait for controller input
		}
	    controller_input_stop();
	}
#endif // TOCPERFECT

	if(!enable_unlock) {
		if(bugged_setsession) {
			debug_write("Sending SetSessionSuperUltraCommandSmash v2, please wait"); // always works on real hardware, DuckStation can get stuck here rarely though since it is not that accurate when it comes to emulating the early VC0A/VC0B/VC1A CDROM behavior
			sscmd = 2; cd_command(CD_CMD_SET_SESSION,(unsigned char *)&sscmd,1); cd_wait_int(); cd_wait_int(); // There is a 3rd response we are ignoring by sending SetSession 1 next ASAP after SetSession 2.
			sscmd = 1; cd_command(CD_CMD_SET_SESSION,(unsigned char *)&sscmd,1); cd_wait_int(); cd_wait_int();
		} else {
			debug_write("Sending SetSession 1");
			sscmd = 1; cd_command(CD_CMD_SET_SESSION,(unsigned char *)&sscmd,1); cd_wait_int(); cd_wait_int();
		
			if(calibrate_laser) { // VC2 and VC3s do auto Bias/Gain calibration when reading a newly inserted real NTSC-J PS1 disc. A swapped in CD-R or just a different disc in general needs this to be updated
        		debug_write("Calibrating laser");
        		cbuf[0] = 0x50; cbuf[1] = 0x38; cbuf[2] = 0x15; cbuf[3] = 0x0A;	// ModeCompensateTrackingAutoGain
				cd_command(CD_CMD_TEST,&cbuf[0],4); 
				cd_wait_int();
			}		
		}
	}
#else // XSTATION DEFINED
	debug_write("Open and then close the CD drive lid");
	wait_lid_status(true); // doesn't wait during the ROM method, unsure why but it is what we want as it allows us to auto-boot with the ROM boot method
	wait_lid_status(false);
#endif // XSTATION

	/*
	We have to re-initilize the BIOS, stop, and init in that order to prevent the process from possibly freezing at this point on Japanese consoles. 
	
	The first reason this is required is because the SetSessionSuperUltraCommandSmash screws up interrupts since we are sending the 2nd SetSession command before the possible 3rd interrupt (which is a second INT5 response sent if session 2 does not actually exist). 
		
	The second reason is because of how we are using the BIOS controller functions, to go back to a clean state a bios re-intialization also accomplishes that.
	*/

	re_cd_init();

	/*
	 * Use the space the BIOS has allocated for reading CD sectors.
	 *
	 * The English translation of Mizzurna Falls (J) (SLPS-01783) depends on the header being
	 * present here (see issue #95 in GitHub).
	 *
	 * This address varies between PS1 and PS2.
	 */
	uint8_t * data_buffer = (uint8_t *) (bios_is_ps1() ? 0xA000B070 : 0xA000A8D0);

	debug_write("Checking game region");
#if defined TOCPERFECT	
    if (CdReadSector(1, 15, data_buffer) != 1) { // Real license data sector is copied to sector 15 by TOCPerfect Patch before it writes Japanese license data to sector 4 to allow booting via CD Player Swap Trick on early SCPH-3000 models
		debug_write("Failed to read sector");
		return;
	}
#else
    if (CdReadSector(1, 4, data_buffer) != 1) {
		debug_write("Failed to read sector");
		return;
	}
#endif

	const char * game_region;
	bool game_is_pal = false;
	/*
	 * EU: "          Licensed  by          Sony Computer Entertainment Euro pe   "
	 * US: "          Licensed  by          Sony Computer Entertainment Amer  ica "
	 * JP: "          Licensed  by          Sony Computer Entertainment Inc.",0x0A
	 *                                                                  |- character we use, at 0x3C
	 */
	switch (data_buffer[0x3C]) {
		case 'E':
			game_region = "European";
			game_is_pal = true;
			break;

		case 'A':
			game_region = "American";
			break;

		case 'I':
			game_region = "Japanese";
			break;

		default:
			game_region = "unknown";
	}

	debug_write("Game's region is %s. Using %s video.", game_region, game_is_pal ? "PAL" : "NTSC");

	// Defaults if no SYSTEM.CNF file exists
	uint32_t tcb = BIOS_DEFAULT_TCB;
	uint32_t event = BIOS_DEFAULT_EVCB;
	uint32_t stacktop = BIOS_DEFAULT_STACKTOP;
	const char * bootfile = "cdrom:PSX.EXE;1";

	char bootfilebuf[32];
	debug_write("Loading SYSTEM.CNF");

	int32_t cnf_fd = FileOpen("cdrom:SYSTEM.CNF;1", FILE_READ);
	if (cnf_fd > 0) {
		read = FileRead(cnf_fd, data_buffer, 2048);
		FileClose(cnf_fd);

		if (read == -1) {
			debug_write("Read error %d", GetLastError());
			return;
		}

		// Null terminate
		data_buffer[read] = '\0';

		config_get_hex((char *) data_buffer, "TCB", &tcb);
		config_get_hex((char *) data_buffer, "EVENT", &event);
		config_get_hex((char *) data_buffer, "STACK", &stacktop);

#if defined TOCPERFECT
		if (config_get_string((char *) data_buffer, "BOOY", bootfilebuf)) {
			bootfile = bootfilebuf;
		} else {
			uint32_t errorCode = GetLastError();
			if (errorCode != FILEERR_NOT_FOUND) {
				debug_write("Open error %d", errorCode);
				return;
			}

			debug_write("Not found");
		}
#else
		if (config_get_string((char *) data_buffer, "BOOT", bootfilebuf)) {
			bootfile = bootfilebuf;
		} else {
			uint32_t errorCode = GetLastError();
			if (errorCode != FILEERR_NOT_FOUND) {
				debug_write("Open error %d", errorCode);
				return;
			}

			debug_write("Not found");
		}
#endif
	}

	// Use string format to reduce ROM usage
	debug_write(" * %s = %x", "TCB", tcb);
	debug_write(" * %s = %x", "EVENT", event);
	debug_write(" * %s = %x", "STACK", stacktop);
	debug_write(" * %s = %s", "BOOT", bootfile);

	re_cd_init(); // Reset one last time to avoid potential lockups (here be dragons)

	/*
	 * SetConf is run by BIOS with interrupts disabled.
	 *
	 * If an interrupt happens while the BIOS is reinitializing the TCBs (thread control blocks),
	 * the interrupt handler will store the current thread state in the zero address, wiping
	 * vital data, like the interrupt trampoline at 0x80.
	 *
	 * We do not need to reenable the interrupts because SetConf already does it for us.
	 */
	debug_write("Configuring kernel");
	EnterCriticalSection();
	SetConf(event, tcb, stacktop);

#if !defined TOCPERFECT
	if(did_read_mc) // before clearing RAM (which contains our mem card buffer if applicable) but after last bios_reinitalize/setconf()
		parse_memcard_save_gameshark_codes();
#endif

	debug_write("Clearing RAM");
	bzero(user_start, &__RO_START__ - user_start);

	debug_write("Reading executable header");
	int32_t exe_fd = FileOpen(bootfile, FILE_READ);
	if (exe_fd <= 0) {
		debug_write("Open error %d", GetLastError());
		return;
	}

	read = FileRead(exe_fd, data_buffer, 2048);

	if (read != 2048) {
		debug_write("Read error %d", GetLastError());
		return;
	}

	/*
	uint32_t sum;
	uint8_t prev = 0;
	uint8_t next;
	uint8_t * ce = (uint8_t *) 0xC000;

	for (int i = 0; i < 0x100; i++)
	{
		//debug_write("%x: @ %x", &ce[i], ce[i]);
		next = ce[i];
		sum = prev + next;
		sum &= 0xFF;
		prev = sum;
	}
	debug_write("Cheat engine checksum: %x", sum);
	for (volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause
	
	uint8_t * codes = (uint8_t *) 0xD000;

	for (int i = 0; i < 0x1FFB; i++)
	{
		//debug_write("%x: @ %x", &codes[i], codes[i]);
		next = codes[i];
		sum = prev + next;
		sum &= 0xFF;
		prev = sum;
	}
	debug_write("Cheat engine enabled codes Checksum: %x", sum);
	for (volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause
	*/

	exe_header_t * exe_header = (exe_header_t *) (data_buffer + 0x10);

	// If the file overlaps tonyhax, we will use the unstable LoadAndExecute function
	// since that's all we can do.
	if (exe_header->load_addr + exe_header->load_size >= &__RO_START__) {
		debug_write("Executable won't fit. Using buggy BIOS call.");

		if (game_is_pal != gpu_is_pal()) {
			debug_write("Switching video mode");
			debug_switch_standard(game_is_pal);
		}

		// Restore original error handler
		bios_restore_disc_error();

		#if !defined XSTATION
		#if !defined AP_BYPASS_DISABLE
		if(!first_rev)
			activate_anti_anti_piracy(bootfile, (int32_t) exe_header->load_addr);
		#endif
		#endif

		if((did_read_mc) && (!cheat_engine_installed))
			install_cheat_engine();

		LoadAndExecute(bootfile, exe_header->initial_sp_base, exe_header->initial_sp_offset);
		return;
	}

	debug_write("Loading executable (%d bytes @ %x)", exe_header->load_size, exe_header->load_addr);

	if (FileRead(exe_fd, exe_header->load_addr, exe_header->load_size) != (int32_t) exe_header->load_size) {
		debug_write("Read error %d", GetLastError());
		return;
	}

	FileClose(exe_fd);

	if (game_is_pal != gpu_is_pal()) {
		debug_write("Switching video mode");
		debug_switch_standard(game_is_pal);
	}

	debug_write("Starting");

	// Restore original error handler
	bios_restore_disc_error();

#if !defined XSTATION
#if !defined AP_BYPASS_DISABLE
	if(!first_rev)
		activate_anti_anti_piracy(bootfile, (int32_t) exe_header->load_addr);
#endif
#endif

	if((did_read_mc) && (!cheat_engine_installed))
		install_cheat_engine();

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
	log_bios_version();
    
	debug_write("Resetting Drive");
	cd_drive_init();

	sscmd = 0x20; cd_command(CD_CMD_TEST,(unsigned char *)&sscmd,1); cd_wait_int(); 
	cd_read_reply(cdcontrollerver);	// Test Command $19,$20 gets the CDROM BIOS
	debug_write("CD BIOS: %x", *(uint32_t*) cdcontrollerver);
   	if(cdcontrollerver[0] == 0x94) {    
        bugged_setsession = 1;
        enable_unlock = 0; // VC0 A and VC0 B are both from 1994 and don't support the getregion command to figure out if it is unlockable or not.
        first_rev = 1;
    } 
    else if(cdcontrollerver[1] == 0x05 && cdcontrollerver[2] == 0x16 && cdcontrollerver[0] == 0x95 && cdcontrollerver[3] == 0xC1) {     
        bugged_setsession = 1; // NOTE I don't think this will ever be triggered but just in case. Earliest SCPH-3000s and late SCPH-1000s are VC0B and later SCPH-3000s are VC1B. Only unlockable systems have VC1A it seems.
    }
    else if((cdcontrollerver[3] == 0xC2) || (cdcontrollerver[3] == 0xC3)) {   
        calibrate_laser = 1;
    }

#if !defined XSTATION
	if(enable_unlock) {
		uint8_t cd_reply[16];
		// Run "GetRegion" test
		uint8_t test = CD_TEST_REGION;
		cd_command(CD_CMD_TEST, &test, 1);

		// Should succeed with 3
		if (cd_wait_int() != 3) {
			debug_write("Region read failed");
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
			debug_write("Unsupported region: %s", (char *) (cd_reply + 4));
			return;
		}

		if(enable_unlock) { // Check again, this could be false now
			#if defined TOCPERFECT // Get TOC via reset + unlock instead of unlock + opening/closing the drive lid for auto loading in TOCPerfect, thanks MottZilla!
				debug_write("Resetting drive");
				cd_drive_reset();
			#endif
			debug_write("Unlocking drive");
			if (!unlock_drive())
				return;
		}
	}
#endif // XSTATION

	while (1) {
		try_boot_cd();

		debug_write("Reinitializing kernel");
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
