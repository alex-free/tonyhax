
#include <stdbool.h>
#include <stdint-gcc.h>
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
#include "memcardpro.h"

// To test ROM functionality in emulation via boot CD, uncomment the following 2 lines:
//#undef ROM
//#define ROM

// To test XSTATION ROM functionality in emulation via boot CD, uncomment the following 4 lines:
//#undef XSTATION
//#define XSTATION
//#undef ROM
//#define ROM

//To test behavior without any anti-piracy bypasses enabled (useful for testing D0 AP bypass codes via save game file gameshark functionality rather then internal activate_anti_piracy() function), uncomment:
//#define AP_BYPASS_DISABLE

// To test MCPro code path on an emulator, uncomment the line below. This must be commented out for releases.
//#define FAKE_MCPRO

/*  
MCP/SD2PSX support added using danhans42's code in his tonyhax_mcp fork: https://github.com/danhans42/tonyhax_mcp/ as a base.

Implements the protocol which can be found here https://gitlab.com/chriz2600/ps1-game-id-transmission utilising the library/code found here https://github.com/Cybdyn-Systems/MemCardPro-ASM .

--Memcard Pro Library Licence Notice--
MemCard Pro Library
Copyright (C) 2021-2024 Cybdyn Systems. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

const char * p5_localized;
const char * region_name;

bool is_beat_mania_append_gottamix = false; // Special handling for no-swap bypass needed for anti-piracy bypass system
bool calibrate_laser = false; // Only Japanese VC2 and VC3 consoles need this so it is off by default
bool bugged_setsession = false; // VC0 A, VC0 B, and VC1 A CDROM Controller BIOS versions all have a buggy SetSession command that requires a special work around to use
bool enable_unlock = true; // Disabled on VC0A and VC0B Japanese CDROM Controller BIOS versions automatically. On VC1A+ the testregion command is run and if the region is Japan it is also disabled.
bool controller_input = false; // When enabled, debug_write does not display the repeat messages counter. This is so we can draw a blank line and then wait for controller input using vsync in debug_write.
bool dont_scroll = false; // When enabled, the screen doesn't scroll (for memory card save file selection)
bool installed_cheat_engine = false; // The cheat engine is installed when parse_memcard_save_gameshark_codes() completes. Some games may go on to set explicit anti-piracy bypass GameShark codes however, so to prevent the cheat engine from being installed twice (which is wasteful) we set a flag here.
bool did_read_mc = false; // We need to set the GameShark codes AFTER the last bios_reintialize(). I want to call bios_reinitialize() after reading the memory card data to prevent anything screwy in booting games, so we can just parse the data later after the final bios_reinitialize since it's still in RAM.

uint16_t mc_base = 0x102; // start of gs code data in memory card buffer

uint8_t number_of_gameshark_code_lines; // part of my basic format to store codes, this tells us how many we will activate
uint8_t * user_start = (uint8_t *) 0x80010000;

// Loading address of tonyhax, provided by the secondary.ld linker script
extern uint8_t __RO_START__, __BSS_START__, __BSS_END__;

uint8_t mcpro_check(uint8_t port){
	return MemCardPro_Ping(port);
}

uint8_t mcpro_sendid(char *gameid) {
    return  MemCardPro_SendGameID(MCPRO_PORT_0, strlen(gameid), gameid);
}

// for controller input functions
void * address;		// For Calculating BIOS Functions
uint8_t j;			// Joypad
uint8_t padbuf[2][0x22];	// Joypad Buffers

void try_boot_cd(); // for access in memory card features

// re-usable strings for debug_write(). Due to compiler optimzations for size already being enabled, this isn't as black and white as just put any repeated strings here. It has to make sense (and visibly reduce the size of secondary.elf) which it does in the below cases.
#define memory_card_in_slot "memory card in slot"
#define press_triangle "Press TRIANGLE to"
#define press_circle "Press CIRCLE to"
#define press_cross "Press CROSS to"


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

void memory_card_and_controller_wait() {
	for(volatile int i = 0; i < 0x100000; i++); // Pause to not spam a memory card read error message if a button is pressed down, and to ensure successful open/read of memory card which requires a waiting period in between calls
}

void save_file_number_select_wait() // 1/2 as responsive for quicker save file selection ui
{
	for(volatile int i = 0; i < 0x50000; i++); // Pause
}

void memory_card_init() {
	debug_write("Memory card init...");
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

	memory_card_and_controller_wait(); // all current functions calling this do it next so just do it once here
}

void read_memory_card_controls() { // we call this more then once
	debug_write("");
	debug_write("%s exit without enabling codes", press_triangle);
	debug_write("%s load codes from %s 1", press_cross, memory_card_in_slot);
	debug_write("%s load codes from %s 2", press_circle, memory_card_in_slot);
}


void read_memory_card_for_gameshark_codes() {
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

	int32_t mc_fd; // assign to slot 1 or slot 2 filepath 
	char slot;
	char * save_file;
	bool did_select_card = false; // can exit out before selecting
	bool card_select_unsuccessful = false; // detect errors in reading save file

	memory_card_init();
	read_memory_card_controls();

	while(!did_select_card) { 
		j = padbuf[0][3] ^ 0xFF;
		if(j == 0x40) { // X button
			memory_card_and_controller_wait();
			save_file = "bu00:TONYHAXINTGS";
			did_select_card = true;
			slot = 1;
		} else if(j == 0x20) { // Circle button
			memory_card_and_controller_wait();
			save_file = "bu10:TONYHAXINTGS";
			did_select_card = true;
			slot = 2;
		} else if(j == 0x10) { // Triangle button
			memory_card_and_controller_wait();
			break;	
		}

		if(did_select_card) {
			debug_write("Select save file name for %s %d", memory_card_in_slot, slot);
			debug_write("");
			debug_write("%s increase the save file name's number", press_triangle);
			debug_write("%s decrease the save file name's number", press_cross);
			debug_write("%s confirm save file name selection", press_circle);
			debug_write("");

			char save_file_number = 0;
			char previous_save_file_number = 0;
    		char selected_save_file_full_path[22]; // +2 for the number and the null terminator
			bool first_run = true;
			memory_card_and_controller_wait();

			dont_scroll = true; // beautiful!

			while(1)
			{
				j = padbuf[0][3] ^ 0xFF;

				if(j == 0x40) { // Cross button
					if(save_file_number > 0)
					{
						save_file_number--;
					}
				} else if(j == 0x10) { // Triangle button
					if(save_file_number < 14) // max number of save files per memory card is 15 (0-14)
					{
						save_file_number++;
					}
				} else if(j == 0x20) { // Circle button
					break;
				}

				if((save_file_number != previous_save_file_number) || (first_run)) {
					debug_write("%s%d", save_file, save_file_number);
					save_file_number_select_wait(); // slow down

					if(first_run) {
						first_run = false;
					}
				}

				previous_save_file_number = save_file_number; // only update display on new selection or first run for starting reference
			}
			dont_scroll = false;

    		// where we're going, we don't need sdks

    		for (int i = 0; i < 17; i++) {
        		selected_save_file_full_path[i] = save_file[i];
   	 		}

			// get ascii for string append
			if(save_file_number < 10) // single digit
			{
				save_file_number += 0x30; // add 0x30 for 0-9
				selected_save_file_full_path[17] = save_file_number;
				selected_save_file_full_path[18] = '\0'; // null terminate

				/* debug
				for(char i = 0; i < 19; i++)
					debug_write("%x", selected_save_file_full_path[i]);
				*/
			} else {
				selected_save_file_full_path[17] = 0x31; // 1

				if(save_file_number == 10) { // double digit values
					selected_save_file_full_path[18] = 0x30; // 0				
				} else if(save_file_number == 11) {
					selected_save_file_full_path[18] = 0x31; // 1			
				} else if(save_file_number == 12) {
					selected_save_file_full_path[18] = 0x32; // 2			
				} else if(save_file_number == 13) {
					selected_save_file_full_path[18] = 0x33; // 3
				} else if(save_file_number == 14) {
					selected_save_file_full_path[18] = 0x34; // 4				
				}
				
				selected_save_file_full_path[19] = '\0'; // null terminate
				/* debug
				for(char i = 0; i < 20; i++)
					debug_write("%x", selected_save_file_full_path[i]);
				*/
			}

			mc_fd = FileOpen(selected_save_file_full_path, FILE_READ);

			if(mc_fd == -1) {
				memory_card_and_controller_wait();
				debug_write("Can not open %s, read error %d", selected_save_file_full_path, GetLastError());
				#if defined FREEPSXBOOT
					debug_write("Verify that the FreePSXBoot memory card has already been removed");
				#endif
				did_select_card = false;
			} else if (mc_fd > 0) {
				int32_t read;

				read = FileRead(mc_fd, user_start, 0x2000); // read the entire file "TONYHAXINTGS" to the start of 'user RAM' (which will be cleared later before booting an executable). So 0x80010000-0x80012000 in RAM contains the contents of "TONYHAXINTGS". 
				// 8192 % 64 = 128
				FileClose(mc_fd);

				if (read == -1) {
					memory_card_and_controller_wait();
					debug_write("Can not read %s, read error %d", selected_save_file_full_path, GetLastError());
					did_select_card = false;
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
						debug_write("%s checksum: %x verified", selected_save_file_full_path, sum);
						did_read_mc = 1; // set flag to parse codes uploaded to RAM, right before clearing RAM itself and booting the game
					} else {
						debug_write("%s checksum: %x did not match the expected checksum: %x!", selected_save_file_full_path, sum, checksum_in_save_file);
						debug_write("No codes enabled, %s may be corrupted", selected_save_file_full_path);
						did_select_card = false;
					}
				}
			}

			if(!did_select_card) { // if this is untrue here we got an error, so display the controls again to user (we are still in gameshark code load loop pulling for input on if we should select the memory card in slot 1 or slot 2 to use)
				card_select_unsuccessful = true;
			}
		}

		if(card_select_unsuccessful) {
			read_memory_card_controls(); // tell user the updated controls since we are out of the previously ran loop
			card_select_unsuccessful = false; // only print to screen once
		} else {
			debug_write(""); // Vblank wait for controller input
		}
	}
	
	try_boot_cd(); // simply the easiest way to return
}

void format_memcard() {
	/*
	 B(41h) - FormatDevice(devicename)
	Erases all files on the device (ie. for formatting memory cards).
	Returns 1=okay, or 0=failed.
	*/

	bool did_format = false; // can exit out before formatting (also checks status of being successful)
	char slot = 0;

	memory_card_init();

	debug_write("%s exit without formatting", press_triangle);
	debug_write("%s FORMAT %s 1", press_cross, memory_card_in_slot);
	debug_write("%s FORMAT %s 2", press_circle, memory_card_in_slot);

	while(1) { 
		j = padbuf[0][3] ^ 0xFF;
		if(j == 0x40) { // Cross button
			memory_card_and_controller_wait();
			
			if(FormatDevice("bu00:") == 1) {
				did_format = true;			
			}

			slot = 1;
		} else if(j == 0x20) { // Circle button
			memory_card_and_controller_wait();

			if(FormatDevice("bu10:") == 1)
			{
				did_format = true;
			}

			slot = 2;
		} else if(j == 0x10) { // Triangle button
			memory_card_and_controller_wait();
			break;	// bail
		}

		if(did_format) {
			break;
		}

		if(slot > 0)
		{
			debug_write("Format error %d for %s %d", GetLastError(), memory_card_in_slot, slot);
			slot = 0;
		}

		debug_write(""); // Vblank wait for controller input
	}

	if(did_format) {
		debug_write("Format successful for %s %d", memory_card_in_slot, slot);
	}

	try_boot_cd(); // simply the easiest way to return
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
	
	if(strncmp(BIOS_VERSION + 11, "Version", 7) == 0) {
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
		debug_write(""); // Vblank wait for controller input

		#if defined ROM
			if(j == 0x40) { // X button
				controller_input_stop();
				run_shell(); // launch Sony BIOS
			} else if(j == 0x20) { // Circle button
				read_memory_card_for_gameshark_codes();
			} else if(j == 0x10) { // Triangle button
				format_memcard();
			}
		#else
			if(j == 0x20) { // Circle button
				read_memory_card_for_gameshark_codes();
			} else if(j == 0x10) { // Triangle button
				format_memcard();
			}
		#endif

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
	debug_write("BIOS re-int"); 
	bios_reinitialize();
	bios_inject_disc_error();
	debug_write("Stopping Motor"); // Significantly improves reading data from disc
	cd_command(CD_CMD_STOP, NULL, 0); cd_wait_int(); cd_wait_int();
	
	debug_write("CD init");
	if (!CdInit()) {
		debug_write("CD init failed");
		return;
	}
}

void try_boot_cd() {
	bool is_psx_exe = false;
	int32_t read;

// we don't use freepsxboot patches for maximum game compatibility
#if defined FREEPSXBOOT 
	debug_write("REMOVE THE FREEPSXBOOT MEMORY CARD FROM YOUR CONSOLE...");
	debug_write("BEFORE BOOTING ANY GAME!");
#endif

debug_write("");
#if defined ROM
	if(enable_unlock)
	{
		debug_write("%s with the CD drive open to boot the Sony BIOS", press_cross);
	} else {
		debug_write("%s boot the Sony BIOS", press_cross); // japanese consoles don't necessarily need the drive open at this point to do this behavior, it could be in a lid-sensor block state
	} 
#endif

	debug_write("%s load GameShark codes from a memory card", press_circle);
	debug_write("%s FORMAT A MEMORY CARD", press_triangle);
	debug_write("");

#if !defined XSTATION
	uint8_t cbuf[4]; // CD Command Buffer

#if !defined TOCPERFECT
	if(enable_unlock) {
		debug_write("Put in a backup/import disc, then close the drive to boot");
		wait_lid_status(true); // doesn't wait during the ROM method, unsure why but it is what we want as it allows us to auto-boot with the ROM boot method
		wait_lid_status(false);
	} else {
		if(is_lid_open() || !licensed_drive() ) {	// If lid is open drive is not licensed, and if lid is closed we check if it is licensed (if it is not licensed but not open then the drive is closed and the user can open it and license it)
			debug_write("To begin boot:");
			debug_write("Put in a real NTSC-J PSX game disc, then block the lid sensor");
			wait_lid_status(true);
			wait_lid_status(false); // Blocking lid sensor = 'closing lid'

            debug_write("CD init");	// Drive will be in licensed state after this is successful
			if (!CdInit()) {
				debug_write("CD Init failed");
				debug_write("Try unblocking then blocking the lid sensor again");
				return;
			}
		} // Drive is licensed and the lid is 'closed' at this point
		debug_write("Drive is licensed");
           
		debug_write("Stopping motor");
		cd_command(CD_CMD_STOP,0,0); cd_wait_int(); cd_wait_int();

		controller_input_start(); // stopped by wait_lid_status() previously. It still makes sense to accept controller input before finally confirming you want to boot the disc

		debug_write("(Keep the lid sensor blocked until turning off the console)");
		debug_write("Remove the real NTSC-J PSX game disc");
		debug_write("Put in a backup/import disc, then press CROSS to boot"); // Thanks MottZilla!
            
		while(1) { 
			j = padbuf[0][3] ^ 0xFF;

			if(j == 0x40) {
				break; // X button boots disc
			} else if(j == 0x20) { // Circle button enables codes
				read_memory_card_for_gameshark_codes(); // this allows Japanese console users to enable user supplied GameShark codes without having to unblock the lid sensor, resetting authentication which would just be more unnecessary steps.
			} else if(j == 0x10) { // Triangle button formats memory card
				format_memcard();
			}
			
			//debug_write("Button: %x", j);
			debug_write(""); // Vblank wait for controller input
		}
	}
	
    controller_input_stop(); // stop MC/controller input at this point

#endif // TOCPERFECT

	if(!enable_unlock) {
		if(bugged_setsession) {
			debug_write("Sending SetSessionSuperUltraCommandSmash v2, please wait"); // DuckStation can get stuck here if you swap the disc and don't wait a few seconds (DuckStation auto starts the motor on disc swap which is actually super annoying since if this executes while it is doing the emulated motor on it will lock up, and it doesn't even need to work like that since real hardware doesn't and game code always starts up a swap disc for i.e. multi-disc games). DuckStation also always emulates a VC1A which triggers this code path with any Japanese BIOS.
			
			int8_t session = CD_SET_SESSION_2;
			cd_command(CD_CMD_SET_SESSION, (unsigned char *)&session, 1); cd_wait_int(); cd_wait_int(); // There is a 3rd response we are ignoring by sending SetSession 1 next ASAP after SetSession 2.
			
			session = 1;
			cd_command(CD_CMD_SET_SESSION, (unsigned char *)&session, 1); cd_wait_int(); cd_wait_int();
		} else {
			debug_write("Sending SetSession 1");
			int8_t session = 1;			
			cd_command(CD_CMD_SET_SESSION, (unsigned char *)&session, 1); cd_wait_int(); cd_wait_int();
		
			if(calibrate_laser) { // VC2 and VC3s do auto Bias/Gain calibration when reading a newly inserted real NTSC-J PS1 disc. A swapped in CD-R or just a different disc in general needs this to be updated
        		debug_write("Calibrating laser");
        		cbuf[0] = 0x50; cbuf[1] = 0x38; cbuf[2] = 0x15; cbuf[3] = 0x0A;	// ModeCompensateTrackingAutoGain
				cd_command(CD_CMD_TEST, &cbuf[0], 4); 
				cd_wait_int();
			}		
		}
	}
#else // XSTATION DEFINED
	debug_write("Open and then close the CD drive lid to continue");
	wait_lid_status(true); // doesn't wait during the ROM method, unsure why but it is what we want as it allows us to auto-boot with the ROM boot method
	wait_lid_status(false);
#endif // XSTATION

	/*
	We have to re-initialize the BIOS, stop, and init in that order to prevent the process from possibly freezing at this point on Japanese consoles. 
	
	The first reason this is required is because the SetSessionSuperUltraCommandSmash screws up interrupts since we are sending the 2nd SetSession command before the possible 3rd interrupt (which is a second INT5 response sent if session 2 does not actually exist). 
		
	The second reason is because of how we are using the BIOS controller functions, to go back to a clean state a bios re-initialization also accomplishes that.
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

	// PS2s in PS1 mode can't switch video modes (at least like this from what we know), see https://github.com/socram8888/tonyhax/issues/25
	if((bios_is_ps1() == true) && (game_is_pal != gpu_is_pal())) {
		debug_write("Switching video mode to %s for game region %s", game_is_pal ? "PAL" : "NTSC", game_region);
		debug_switch_standard(game_is_pal);
	} else {
		debug_write("Game region is %s", game_region);
	}

	// Defaults if no SYSTEM.CNF file exists
	uint32_t tcb = BIOS_DEFAULT_TCB;
	uint32_t event = BIOS_DEFAULT_EVCB;
	uint32_t stacktop = BIOS_DEFAULT_STACKTOP;
	char * bootfile = "cdrom:PSX.EXE;1";

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
    } // Always has SYSTEM.CNF
#else
		if(config_get_string((char *) data_buffer, "BOOT", bootfilebuf)) {
			bootfile = bootfilebuf;
		} else {
			uint32_t errorCode = GetLastError();
			if (errorCode != FILEERR_NOT_FOUND) {
				debug_write("Open error %d", errorCode);
				return;
			}

			debug_write("Not found");
		}
	} else {
        debug_write("No SYSTEM.CNF");
		is_psx_exe = true;
	}
#endif

	// Use string format to reduce ROM usage
	debug_write(" * %s = %x", "TCB", tcb);
	debug_write(" * %s = %x", "EVENT", event);
	debug_write(" * %s = %x", "STACK", stacktop);
	debug_write(" * %s = %s", "BOOT", bootfile);
    
    // PSX.EXE games almost never have a SYSTEM.CNF (that's the point of naming it 'PSX.EXE'). However, there are exceptions:
    if(
    (strcmp(bootfile, "cdrom:\\psx.exe") == 0) || 
    // Cool Boarder's 3 (USA) (Beta) - http://redump.org/disc/75375/. Game does have save functionality, but we currently don't support betas.
    
    (strcmp(bootfile, "cdrom:\\PSX.EXE;1") == 0) || 
    // Dead Or Alive (USA) (Beta) (1-09-1998) - http://redump.org/disc/73759/. Game does not have save functionality yet implemented. We don't currently support betas either.
    // Gokuu Densetsu: Magic Beast Warriors (Japan) - http://redump.org/disc/24258/.
    
    (strcmp(bootfile, "cdrom:\\psx.exe;1") == 0) || 
    // The Great Battle IV (Japan) - https://psxdatacenter.com/games/J/T/SLPS-00719.html.
    
    (strcmp(bootfile, "cdrom:PSX.EXE;1") == 0)
    // Tokimeki Memorial: Forever with You (Japan) (Shokai Genteiban) - http://redump.org/disc/6788/.
    // Tokimeki Memorial: Forever with You (Japan) (Rev 1) - http://redump.org/disc/6789/.
    // Tokimeki Memorial: Forever with You (Japan) (Rev 2) - http://redump.org/disc/33338/.
    // Tokimeki Memorial: Forever with You (Japan) (Rev 4) - http://redump.org/disc/6764/.
    ) {
        is_psx_exe = true;
    }

#if defined FAKE_MCPRO
    debug_write("DEBUG: forcing MCPro code path");
#else
    int memcardpro_status = mcpro_check(MCPRO_PORT_0);
    memory_card_and_controller_wait(); // docs say to wait
	if(memcardpro_status == 0) {
		mcpro_sendid("");
        memory_card_and_controller_wait(); // docs say to wait
		debug_write("MCPRO/SD2PSX detected in slot 1"); // This is enough of a wait between the next one if needed.
#endif

        if(is_psx_exe) {
            /*
            Special handling for PSX.EXE games with memcardpro. We have 2 lists: 
            * http://redump.org/discs/quicksearch/PSX.EXE/comments/only
            * http://redump.org/discs/quicksearch/PSXEXE/comments/only

            
            There are some false positives in the above 2 lists due to how redump search works/how they were listed. There are also some discs not listed that do have PSX.EXE. In addition ONLY officially licensed discs with PSX.EXE are supported. Beta and unlicensed discs are ignored (due to lacking a serial designation and to save exe space).

            ======================================================================
            Implementation Notes:

            WE DO NOT WANT TO DEPEND ON THE ABILITY TO LOAD THE ENTIRE PSX.EXE INTO RAM. As Tonyhax International gets larger we can't guarantee every PSX.EXE executable will fit into the RAM lower then Tonyhax International before we call do_execute(), sometimes we may need to load_and_exec() which means we can't depend on having the PSX.EXE in memory to check anything.

            Failed attempts to ID PSX.EXE games:

            1) CRC32 sector 16. This is great, but if you rebuild/modify the game with i.e. mkpsxiso you get a different checksum we can't possibly know, and fail the match.
            
            2) CRC32 sector 16 up to 0x48. The includes the Volume Identifier. This would probably even work with  mkpsxiso rebuilt disc images, BUT some ridiculous games such as http://redump.org/disc/21858/ have no identifiable information even here. Even the Volume Identifier at 0x28 is SPACES FOR THAT GAME! WHY?!

            ======================================================================
            SUCCESSFUL IMPLEMENTATION FOUND: 
            
            Check the date of creation ;) at 0x32D (Volume Creation Timestamp). MKPSXISO keeps that the same on rebuild.
            
            From NO$PSX SPX: https://problemkaputt.de/psx-spx.htm#cdromisovolumedescriptors

            ======================================================================
            Primary Volume Descriptor (sector 16 on PSX disks)

            000h 1    Volume Descriptor Type        (01h=Primary Volume Descriptor)
            001h 5    Standard Identifier           ("CD001")
            006h 1    Volume Descriptor Version     (01h=Standard)
            007h 1    Reserved                      (00h)
            008h 32   System Identifier             (a-characters) ("PLAYSTATION")
            028h 32   Volume Identifier             (d-characters) (max 8 chars for PSX?)
            048h 8    Reserved                      (00h)
            050h 8    Volume Space Size             (2x32bit, number of logical blocks)
            058h 32   Reserved                      (00h)
            078h 4    Volume Set Size               (2x16bit) (usually 0001h)
            07Ch 4    Volume Sequence Number        (2x16bit) (usually 0001h)
            080h 4    Logical Block Size in Bytes   (2x16bit) (usually 0800h) (1 sector)
            084h 8    Path Table Size in Bytes      (2x32bit) (max 800h for PSX)
            08Ch 4    Path Table 1 Block Number     (32bit little-endian)
            090h 4    Path Table 2 Block Number     (32bit little-endian) (or 0=None)
            094h 4    Path Table 3 Block Number     (32bit big-endian)
            098h 4    Path Table 4 Block Number     (32bit big-endian) (or 0=None)
            09Ch 34   Root Directory Record         (see next chapter)
            0BEh 128  Volume Set Identifier         (d-characters) (usually empty)
            13Eh 128  Publisher Identifier          (a-characters) (company name)
            1BEh 128  Data Preparer Identifier      (a-characters) (empty or other)
            23Eh 128  Application Identifier        (a-characters) ("PLAYSTATION")
            2BEh 37   Copyright Filename            ("FILENAME.EXT;VER") (empty or text)
            2E3h 37   Abstract Filename             ("FILENAME.EXT;VER") (empty)
            308h 37   Bibliographic Filename        ("FILENAME.EXT;VER") (empty)
            32Dh 17   Volume Creation Timestamp     ("YYYYMMDDHHMMSSFF",timezone)
            33Eh 17   Volume Modification Timestamp ("0000000000000000",00h)
            34Fh 17   Volume Expiration Timestamp   ("0000000000000000",00h)
            360h 17   Volume Effective Timestamp    ("0000000000000000",00h)
            371h 1    File Structure Version        (01h=Standard)
            372h 1    Reserved for future           (00h-filled)
            373h 141  Application Use Area          (00h-filled for PSX and VCD)
            400h 8    CD-XA Identifying Signature   ("CD-XA001" for PSX and VCD)
            408h 2    CD-XA Flags (unknown purpose) (00h-filled for PSX and VCD)
            40Ah 8    CD-XA Startup Directory       (00h-filled for PSX and VCD)
            412h 8    CD-XA Reserved                (00h-filled for PSX and VCD)
            41Ah 345  Application Use Area          (00h-filled for PSX and VCD)
            573h 653  Reserved for future           (00h-filled)
            ======================================================================
            */

            bool no_save_function = false; // by default we assume games do need a unique MCPro GameID sent. If they don't have save functionality though we tell the user why we don't send anything. We save a bit of exe space by not sending the serial too if we don't need to.

            re_cd_init(); // Reset before next read

            if (CdReadSector(1, 16, data_buffer) != 1) { // No chance of overseek for PS2s because it is a very early sector at the inner part of the disc.
		        debug_write("Failed to read sector 16");
		        return;
	        }

            unsigned char volume_creation_timestamp[17]; // 16 bytes for Volume Creation Timestamp + termination From No $ PSX
            /*
            =============================================================================================
            Volume Descriptor Timestamps
            The various timestamps occupy 17 bytes each, in form of

            "YYYYMMDDHHMMSSFF",timezone
            "0000000000000000",00h         ;empty timestamp

            The first 16 bytes are ASCII Date and Time digits (Year, Month, Day, Hour, Minute, Second, and 1/100 Seconds. The last byte is Offset from Greenwich Mean Time in number of 15-minute steps from -48 (West) to +52 (East); or actually: to +56 when recursing Kiribati's new timezone.
            Note: PSX games manufactured in year 2000 were accidently marked to be created in year 0000.
            =============================================================================================
            */

            char * gameid = 0; // If not known stays 0, and reported to user.

            for(int i = 0; i < 16; i++) {
                volume_creation_timestamp[i] = data_buffer[0x32D + i];
                volume_creation_timestamp[16] = '\0';
            }

            debug_write("PSX.EXE ID: %s", (char *)volume_creation_timestamp); 

            if(strcmp( (char *)volume_creation_timestamp, "1995040719355400") == 0) { // 3x3 Eyes: Kyuusei Koushu (Disc 1) (Japan) - http://redump.org/disc/7881/ / 3x3 Eyes: Kyuusei Koushu (Disc 2) (Japan) http://redump.org/disc/7880/
                gameid = "cdrom:SLPS_000.71;1"; // Using disc 1 CD case serial: http://redump.org/disc/7881/. All CDs assigned to same memory card.
                //debug_write("3x3 Eyes: Kyuusei Koushu (Disc 1) (Japan) / (Disc 2)"); // 1 MC block - https://psxdatacenter.com/games/J/0-9/SLPS-00071.html
            } else if
            
            ( 
            (strcmp( (char *)volume_creation_timestamp, "1994110218594700") == 0) || // A Ressha de Ikou 4: Evolution (Japan) (Rev 0) - http://redump.org/disc/21858/
            (strcmp( (char *)volume_creation_timestamp, "1995030218052000") == 0) // A Ressha de Ikou 4: Evolution (Japan) (Rev 1) - http://redump.org/disc/21858/
            ) { // we don't care about any revision differences!
                gameid = "cdrom:SLPS_000.04;1"; // Serial from CD case.
                //debug_write("A Ressha de Ikou 4: Evolution (Japan) (Rev 0) / (Rev 1)"); // 15 MC blocks - https://psxdatacenter.com/games/J/A/SLPS-00004.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995051700000000") == 0) { // Ace Combat (Japan) - http://redump.org/disc/1691/
                gameid = "cdrom:SLPS_000.61;1"; // Serial from CD case.
                //debug_write("Ace Combat (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/A/SLPS-00061.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995121620000000") == 0) { // Alnam no Kiba: Juuzoku Juuni Shinto Densetsu (Japan) - http://redump.org/disc/11199/
                gameid = "cdrom:SLPS_001.73;1"; // Serial from CD case.
                //debug_write("Alnam no Kiba: Juuzoku Juuni Shinto Densetsu (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/A/SLPS-00173.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1995080809000000") == 0) || // Boxer's Road (Japan) (Rev 0) - http://redump.org/disc/2765/
            (strcmp( (char *)volume_creation_timestamp, "1995100209000000") == 0) // // Boxer's Road (Japan) (Rev 1) - http://redump.org/disc/6537/
            ) { // we don't care about any revision differences!
                gameid = "cdrom:SLPS_910.07;1"; // Serial from CD case.
                //debug_write("Boxer's Road (Japan) (Rev 0) / (Rev 1)"); // 7 MC blocks - https://psxdatacenter.com/games/J/B/SLPS-91007.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1998110515540400") == 0) { // Contender (USA) (Demo) - http://redump.org/disc/43176/
                //gameid = "cdrom:SCUS_943.80;1"; // Serial from CD case.
                //debug_write("Contender (USA) (Demo)");
                no_save_function = true; // Demos can't save.
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1995060504013600") == 0) || // Cyberwar (Japan) (Disc 1) - http://redump.org/disc/30637/
            (strcmp( (char *)volume_creation_timestamp, "1995060319142200") == 0) || // Cyberwar (Japan) (Disc 2) - http://redump.org/disc/30638/
            (strcmp( (char *)volume_creation_timestamp, "1995060402110800") == 0) // Cyberwar (Japan) (Disc 3) - http://redump.org/disc/30639/
            ) {
                gameid = "cdrom:SLPS_000.55;1"; // Using Disc 1 CD case serial: http://redump.org/disc/30637/. All CDs assigned to same memory card.
                //debug_write("Cyberwar (Japan) (Disc 1) / (Disc 2) / (Disc 3)"); // 1 MC block - https://psxdatacenter.com/games/J/C/SLPS-00055.html
            } else if

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995102101350000") == 0) || // D no Shokutaku: Complete Graphics (Japan) (Disc 1) - http://redump.org/disc/763/
            (strcmp( (char *)volume_creation_timestamp, "1995102102521200") == 0) || // D no Shokutaku: Complete Graphics (Japan) (Disc 2) - http://redump.org/disc/764/
            (strcmp( (char *)volume_creation_timestamp, "1995102105003200") == 0) // D no Shokutaku: Complete Graphics (Japan) (Disc 3) - http://redump.org/disc/765/
            ) {
                gameid = "cdrom:SLPS_001.33;1"; // Using disc 1 CD case serial: http://redump.org/disc/763/. All CDs assigned to same memory card.
                //debug_write("D no Shokutaku: Complete Graphics (Japan)"); // 13 MC blocks - https://psxdatacenter.com/games/J/D/SLPS-00133.html
            } else if            

            (strcmp( (char *)volume_creation_timestamp, "1995051015300000") == 0) { // Douga de Puzzle da! Puppukupuu (Japan) - http://redump.org/disc/11935/
                gameid = "cdrom:SLPS_000.77;1"; // Serial from CD case.
                //debug_write("Douga de Puzzle da! Puppukupuu"); // 13 MC blocks - https://psxdatacenter.com/games/J/D/SLPS-00077.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995061806364400") == 0) { // Dragon Ball Z: Ultimate Battle 22 (Japan) - http://redump.org/disc/10992/
                gameid = "cdrom:SLPS_000.73;1"; // Serial from CD case.
                //debug_write("Dragon Ball Z: Ultimate Battle 22 (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/D/SLPS-00073.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995040509595900") == 0) { // Entertainment Jansou: That's Pon! (Japan) - http://redump.org/disc/34808/
                gameid = "cdrom:SLPS_000.51;1"; // Serial from CD case.
                //debug_write("Entertainment Jansou: That's Pon! (Japan)"); // 2 MC blocks - https://psxdatacenter.com/games/J/T/SLPS-00051.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995052918000000") == 0) { // Falcata: Astran Pardma no Monshou (Japan) - http://redump.org/disc/1682/
                gameid = "cdrom:SLPS_000.10;1"; // Serial from CD case.
                //debug_write("Falcata: Astran Pardma no Monshou (Japan)"); // 4 MC blocks - https://psxdatacenter.com/games/J/F/SLPS-00010.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994110702000000") == 0) { // Gokujou Parodius Da! Deluxe Pack (Japan) - http://redump.org/disc/5337/
                gameid = "cdrom:SLPS_000.02;1"; // Serial from CD case.
                //debug_write("Gokujou Parodius Da! Deluxe Pack (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00002.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995041400000000") == 0) { // Gokuu Densetsu: Magic Beast Warriors (Japan) - http://redump.org/disc/24258/
                gameid = "cdrom:SLPS_000.48;1"; // Serial from CD case.
                //debug_write("Gokuu Densetsu: Magic Beast Warriors (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00048.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1997011500000000") == 0) { // The Great Battle VI (Japan) - http://redump.org/disc/37406/
                //gameid = "cdrom:SLPS_007.19;1"; // Serial from CD case.
                //debug_write("The Great Battle VI (Japan)");
                no_save_function = true; // https://psxdatacenter.com/games/J/T/SLPS-00719.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995070613170000") == 0) { // Ground Stroke: Advanced Tennis Game (Japan) - http://redump.org/disc/33778/
                gameid = "cdrom:SLPS_000.88;1"; // Serial from CD case.
                //debug_write("Ground Stroke: Advanced Tennis Game (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00088.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111721302100") == 0) { // Houma Hunter Lime: Special Collection Vol. 1 (Japan) - http://redump.org/disc/18606/
                gameid = "cdrom:SLPS_000.20;1"; // Serial from CD case.
                //debug_write("Houma Hunter Lime: Special Collection Vol. 1 (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/H/SLPS-00020.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995072522004900") == 0) { // Houma Hunter Lime: Special Collection Vol. 2 (Japan) - http://redump.org/disc/18607/
                gameid = "cdrom:SLPS_000.85;1"; // Serial from CD case.
                //debug_write("Houma Hunter Lime: Special Collection Vol. 2 (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/I/SLPS-00029.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995022623000000") == 0) { // Idol Janshi Suchie-Pai Limited (Japan) - http://redump.org/disc/33789/
                gameid = "cdrom:SLPS_000.29;1"; // Serial from CD case.
                //debug_write("Idol Janshi Suchie-Pai Limited (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/I/SLPS-00029.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1995061911303400") == 0) || // J.League Jikkyou Winning Eleven (Japan) (Rev 0) - http://redump.org/disc/6740/
            (strcmp( (char *)volume_creation_timestamp, "1995072800300000") == 0) // // J.League Jikkyou Winning Eleven (Japan) (Rev 1) - http://redump.org/disc/2848/
            ) { // we don't care about any revision differences!
                gameid = "cdrom:SLPS_000.68;1"; // Serial from CD case.
                //debug_write("J.League Jikkyou Winning Eleven (Japan) (Rev 0) / (Rev 1)"); // 1 MC block - https://psxdatacenter.com/games/J/J/SLPS-00068.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1994112617300000") == 0) || // Jikkyou Powerful Pro Yakyuu '95 (Japan) (Rev 0) -http://redump.org/disc/9552/
            (strcmp( (char *)volume_creation_timestamp, "1994121517300000") == 0) // // Jikkyou Powerful Pro Yakyuu '95 (Japan) (Rev 1) - http://redump.org/disc/14367/
            ) { // we don't care about any revision differences!
                gameid = "cdrom:SLPS_000.67;1"; // Serial from CD case.
                //debug_write("Jikkyou Powerful Pro Yakyuu '95 (Japan) (Rev 0) / (Rev 1)"); //  3 MC blocks - https://psxdatacenter.com/games/J/J/SLPS-00067.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995113010450000") == 0) { // Keiba Saishou no Housoku '96 Vol. 1 (Japan) - http://redump.org/disc/22945/
                gameid = "cdrom:SLPS_001.46;1"; // Serial from CD case.
                //debug_write("Keiba Saishou no Housoku '96 Vol. 1"); // 15 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00146.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994100617242100") == 0) { // Kikuni Masahiko Jirushi: Warau Fukei-san Pachi-Slot Hunter (Japan) - http://redump.org/disc/33816/
                gameid = "cdrom:SLPS_000.21;1"; // Serial from CD case.
               //debug_write("Kikuni Masahiko Jirushi: Warau Fukei-san Pachi-Slot Hunter"); // Too long to fit '(Japan)'. // 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00021.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994121500000000") == 0) { // Kileak, The Blood (Japan) - http://redump.org/disc/14371/
                gameid = "cdrom:SLPS_000.27;1"; // Serial from CD case.
                //debug_write("Kileak, The Blood (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00027.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111013000000") == 0) { // King's Field (Japan) - http://redump.org/disc/7072/
                gameid = "cdrom:SLPS_000.17;1"; // Serial from CD case.
                //debug_write("King's Field (Japan)"); // 5 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00017.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995051816000000") == 0) { // Kururin Pa! (Japan) - http://redump.org/disc/33413/
                gameid = "cdrom:SLPS_000.66;1"; // Serial from CD case.
                //debug_write("Kururin Pa! (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00066.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995033100003000") == 0) { // Missland (Japan) - http://redump.org/disc/10869/
                gameid = "cdrom:SLPS_000.47;1"; // Serial from CD case.
                //debug_write("Missland (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00047.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995042506300000") == 0) { // Mobile Suit Gundam (Japan) - http://redump.org/disc/3080/
                gameid = "cdrom:SLPS_000.35;1"; // Serial from CD case.
                //debug_write("Mobile Suit Gundam (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00035.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994092920284600") == 0) { // Myst (Japan) (Rev 0) - http://redump.org/disc/4786/ / Myst (Japan) (Rev 1)  - http://redump.org/disc/33887/ /  Myst (Japan) (Rev 2)  - http://redump.org/disc/1488/
                gameid = "cdrom:SLPS_000.24;1"; // CD case serial.
                //debug_write("Myst (Japan) (Rev 0) / (Rev 1) / (Rev 2)"); // 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00024.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995050413421800") == 0) { // Night Striker (Japan) - http://redump.org/disc/10931/
                gameid = "cdrom:SLPS_000.50;1"; // CD case serial.
                //debug_write("Night Striker (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/N/SLPS-00050.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995071011035200") == 0) { // Oh-chan no Oekaki Logic (Japan) - http://redump.org/disc/7882/
                gameid = "cdrom:SLPS_000.93;1"; // CD case serial.
                //debug_write("Oh-chan no Oekaki Logic (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/O/SLPS-00093.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995082517551900") == 0) { // The Oni Taiji!!: Mezase! Nidaime Momotarou (Japan) - http://redump.org/disc/33948/
                gameid = "cdrom:SLPS_000.89;1"; // CD case serial.
                // debug_write("The Oni Taiji!!: Mezase! Nidaime Momotarou (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00089.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995011411551700") == 0) { // Pachio-kun: Pachinko Land Daibouken (Japan) - http://redump.org/disc/36504/
                gameid = "cdrom:SLPS_000.37;1"; // CD case serial.
                //debug_write("Pachio-kun: Pachinko Land Daibouken (Japan)"); // 2 MC block - https://psxdatacenter.com/games/J/P/SLPS-00037.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995041921063500") == 0) { // Rayman (Japan) - http://redump.org/disc/33719/
                gameid = "cdrom:SLPS_000.26;1"; // CD case serial.
                //debug_write("Rayman (Japan)"); // 3 MC blocks - https://psxdatacenter.com/games/J/R/SLPS-00026.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1994111009000000") == 0) { // Ridge Racer (Japan) - http://redump.org/disc/2679/
                gameid = "cdrom:SLPS_000.01;1"; // Serial from CD case.
                //debug_write("Ridge Racer (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/R/SLPS-00001.htmls
            } else if

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995083112000000") == 0) || // Tokimeki Memorial: Forever with You (Japan) (Rev 1) - http://redump.org/disc/6789/ / Tokimeki Memorial: Forever with You (Japan) (Shokai Genteiban) (Rev 1) - http://redump.org/disc/6788/
            (strcmp( (char *)volume_creation_timestamp, "1995111700000000") == 0) // Tokimeki Memorial: Forever with You (Japan) (Rev 2) - http://redump.org/disc/33338/
             // Tokimeki Memorial: Forever with You (Japan) (PlayStation The Best) - http://redump.org/disc/8876/ has it's own different serial and proper bootfile name, so already works with mcpro!
            ) { // We don't care about revision differences!
                gameid = "cdrom:SLPS_000.64;1"; // Using CD case serial.
                //debug_write("Tokimeki Memorial: Forever with You (Japan) (Rev 1) / (Rev 2)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00064.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1996033100000000") == 0) { // Tokimeki Memorial: Forever with You (Japan) (Rev 4) - http://redump.org/disc/6764/.
                gameid = "cdrom:SLPS_000.65;1"; // Using CD case serial. Why it is different from the above? No clue. Not a typo though.
                //debug_write("Tokimeki Memorial: Forever with You (Japan) (Rev 4)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00065.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995090516062841") == 0) { // Sotsugyou II: Neo Generation (Japan) - http://redump.org/disc/7885/.
                gameid = "cdrom:SLPS_001.13;1"; // Using CD case serial.
                //debug_write("Sotsugyou II: Neo Generation (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00040.html
            } else if

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995031205000000") == 0) || // Tekken (Japan) (Rev 0) - http://redump.org/disc/671/
            (strcmp( (char *)volume_creation_timestamp, "1995061612000000") == 0) // Tekken (Japan) (Rev 1) - http://redump.org/disc/1807/
            ) { // We don't care about revision differences!
                gameid = "cdrom:SLPS_000.40;1"; // Using CD case serial.
                //debug_write("Tekken (Japan) (Rev 0) / (Rev 1)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00040.html
            } else if

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1994113012000000") == 0) || // Toushinden (Japan) (Rev 0) - http://redump.org/disc/1560/
            (strcmp( (char *)volume_creation_timestamp, "1995012512000000") == 0) // Toushinden (Japan) (Rev 1) - http://redump.org/disc/23826/
            ) { // We don't care about revision differences!
                gameid = "cdrom:SLPS_000.25;1"; // Using CD case serial.
                //debug_write("Toushinden (Japan) (Rev 0) / (Rev 1)"); //1 MC block - https://psxdatacenter.com/games/J/B/SLPS-00025.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111522183200") == 0) { // Twin Goddesses (Japan) - http://redump.org/disc/7885/.
                gameid = "cdrom:SLPS_000.18;1"; // Using CD case serial.
                //debug_write("Twin Goddesses (Japan)");// 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00018.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995021615022900") == 0) { // Uchuu Seibutsu Flopon-kun P! (Japan) - http://redump.org/disc/18814/.
                gameid = "cdrom:SLPS_000.32;1"; // Using CD case serial.
                //debug_write("Uchuu Seibutsu Flopon-kun P! (Japan)");// 1 MC block - https://psxdatacenter.com/games/J/U/SLPS-00032.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995080316000000") == 0) { // V-Tennis (Japan) - http://redump.org/disc/22684/.
                gameid = "cdrom:SLPS_001.03;1"; // Using CD case serial.
                debug_write("V-Tennis (Japan)");// 1 MC block - https://psxdatacenter.com/games/J/V/SLPS-00103.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995070523450000") == 0) { // Zero Divide (Japan) - http://redump.org/disc/99925/.
                gameid = "cdrom:SLPS_001.03;1"; // Using CD case serial.
                debug_write("Zero Divide (Japan)");// 1 MC block - https://psxdatacenter.com/games/J/Z/SLPS-00083.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995070500000000") == 0) { // Zero Divide (Japan) (Demo) - http://redump.org/disc/99925/.
                //gameid = "cdrom:SLPM_800.08;1"; // Using CD case serial.
                no_save_function = true; // Demos don't have save features.
                //debug_write("Zero Divide (Japan) (Demo)");
            }

            if(gameid != 0) {
                mcpro_sendid(gameid);
            } else {
                if(no_save_function) {
                    debug_write("Detected game that does not use memory cards"); // Still send bootfile to MCPro next because we want to switch off of a potential FreeMCBoot exploited memory card.
                } else {
                    debug_write("Unknown PSX.EXE ID, unique GameID unavailable.");
                }
                mcpro_sendid(bootfile); // as a last resort, we send PSX.EXE to mcpro
            }
        } else {
            mcpro_sendid(bootfile); // wow, that was a lot simpler then PSX.EXE!
        }

#if !defined FAKE_MCPRO
    }
#endif

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

	char * append_bypass_bootfile = "cdrom:\\APPEND.EXE;1";

// Only 2 known no-swap bypass games that work with the Append No Swap Bypass (By mdmdj) method
	if((strcmp("cdrom:\\SLPM_861.84;1", bootfile)) == 0) { // BeatMania Append 3rdMix
		bootfile = append_bypass_bootfile;
		//debug_write("Append No Swap Bypass detected");	
		// no anti-piracy other then key disc in this one
	}

	if((strcmp("cdrom:\\SLPM_862.29;1", bootfile)) == 0) { // BeatMania Append GottaMix
		bootfile = append_bypass_bootfile;
		is_beat_mania_append_gottamix = true; // used for anti-piracy bootfile match replacement
		//debug_write("Append No Swap Bypass detected");	
	}

	debug_write("Reading executable header");
	
	int32_t exe_fd = FileOpen(bootfile, FILE_READ);
	if (exe_fd <= 0) {
		debug_write("Open error %d", GetLastError());
		return;
	}

    file_control_block_t * exe_fcb = *BIOS_FCBS + exe_fd;
	read = FileRead(exe_fd, data_buffer, 2048);

	if (read != 2048) {
        debug_write("Missing header. Read %d, error %d.", read, exe_fcb->last_error);
		return;
	}

    exe_header_t * exe_header = (exe_header_t *) data_buffer;
	if (strncmp(exe_header->signature, "PS-X EXE", 8)) {
		debug_write("Header has invalid signature");
		return;
	}
    
    /*
	 * Patch executable header like stock does. Fixes issue #153 with King's Field (J) (SLPS-00017).
	 * https://github.com/grumpycoders/pcsx-redux/blob/a072e38d78c12a4ce1dadf951d9cdfd7ea59220b/src/mips/openbios/main/main.c#L380-L381
	 */
	exe_header->offsets.initial_sp_base = stacktop;
	exe_header->offsets.initial_sp_offset = 0;

    /*
	 * Patch executable load size, capping it to the file size.
	 *
	 * According to https://github.com/socram8888/tonyhax/issues/161,
	 * Kileak, The Blood (J) (SLPS-00027) specifies in its header a an invalid load size, larger
	 * than the actual executable.
	 *
	 * While the BIOS does not validate this, we do to ensure the file could be read in its
	 * entirety and detect possible CD read errors.
	 */
	uint32_t actual_exe_size = exe_fcb->size - 2048;
	if (actual_exe_size < exe_header->offsets.load_size) {
		exe_header->offsets.load_size = actual_exe_size;
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

	// If the file overlaps tonyhax, we will use the unstable LoadAndExecute function
	// since that's all we can do.
    if (exe_header->offsets.load_addr + exe_header->offsets.load_size >= &__RO_START__) {
    	debug_write("Executable won't fit. Using buggy BIOS call.");
		// Restore original error handler
		bios_restore_disc_error();

#if !defined XSTATION
#if !defined AP_BYPASS_DISABLE
		activate_anti_anti_piracy(bootfile, (int32_t) exe_header->offsets.load_addr);
#endif
#endif

		if((did_read_mc) && (!cheat_engine_installed)) {
			install_cheat_engine();
        }

		LoadAndExecute(
			bootfile,
			exe_header->offsets.initial_sp_base,
			exe_header->offsets.initial_sp_offset
		);
        return;
	}

    debug_write(
		"Loading executable (%d bytes @ %x)",
		exe_header->offsets.load_size,
		exe_header->offsets.load_addr
	);
    
    /*
    https://github.com/socram8888/tonyhax/issues/161

    Kileak, The Blood (Japan) - http://redump.org/disc/14371/ specifies the wrong executable filesize (offset 0x1C in PSX.EXE). The filesize given (643072) includes the PSX.EXE header sector, when it is mandated to NOT include it in the total filesize.
        
    From No $ PSX SPX:
    ===============================
    000h-007h ASCII ID "PS-X EXE"
    008h-00Fh Zerofilled
    010h Initial PC (usually 80010000h, or higher)
    014h Initial GP/R28 (usually 0)
    018h Destination Address in RAM (usually 80010000h, or higher)
    01Ch Filesize (must be N*800h) (excluding 800h-byte header) THIS RIGHT HERE
    020h Data section Start Address (usually 0)
    024h Data Section Size in bytes (usually 0)
    028h BSS section Start Address (usually 0) (when below Size=None)
    02Ch BSS section Size in bytes (usually 0) (0=None)
    030h Initial SP/R29 & FP/R30 Base (usually 801FFFF0h) (or 0=None)
    034h Initial SP/R29 & FP/R30 Offs (usually 0, added to above Base)
    038h-04Bh Reserved for A(43h) Function (should be zerofilled in exefile)
    04Ch-xxxh ASCII marker
    "Sony Computer Entertainment Inc. for Japan area"
    "Sony Computer Entertainment Inc. for Europe area"
    "Sony Computer Entertainment Inc. for North America area"
    (or often zerofilled in some homebrew files)
    (the BIOS doesn't verify this string, and boots fine without it)
    xxxh-7FFh Zerofilled
    800h... Code/Data (loaded to entry[018h] and up)
    ===============================
    */

    read = FileRead(exe_fd, exe_header->offsets.load_addr, exe_header->offsets.load_size);

	if (read != (int32_t) exe_header->offsets.load_size) {
		debug_write("Failed to load body. Read %d, error %d.", read, exe_fcb->last_error);
        return;
    }

	FileClose(exe_fd);

	debug_write("Starting");

	// Restore original error handler
	bios_restore_disc_error();

#if !defined XSTATION
#if !defined AP_BYPASS_DISABLE
	activate_anti_anti_piracy(bootfile, (int32_t) exe_header->offsets.load_addr);
#endif
#endif

	if((did_read_mc) && (!cheat_engine_installed)) {
		install_cheat_engine();
    }

	// Games from WarmBoot start with interrupts disabled
	EnterCriticalSection();

	// FlushCache needs to be called with interrupts disabled
	FlushCache();

    DoExecute(&exe_header->offsets, 0, 0);
}

void main() {

	uint8_t cd_controller_version[4];

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

	const int8_t version = CD_TEST_VERSION;
	cd_command(CD_CMD_TEST, (unsigned char *)&version, 1); cd_wait_int(); 
	cd_read_reply(cd_controller_version);	// Test Command $19,$20 gets the CDROM BIOS
	debug_write("CD BIOS: %x", *(uint32_t*) cd_controller_version);
   	if(cd_controller_version[0] == 0x94) {    
        bugged_setsession = true;
        enable_unlock = false; // VC0 A and VC0 B are both from 1994 and don't support the getregion command to figure out if it is unlockable or not.
    } 
    else if(cd_controller_version[1] == 0x05 && cd_controller_version[2] == 0x16 && cd_controller_version[0] == 0x95 && cd_controller_version[3] == 0xC1) {     
        bugged_setsession = true; // NOTE I don't think this will ever be triggered but just in case. Earliest SCPH-3000s and late SCPH-1000s are VC0B and later SCPH-3000s are VC1B. Only unlockable systems have VC1A it seems.
    }
    else if((cd_controller_version[3] == 0xC2) || (cd_controller_version[3] == 0xC3)) {   
        calibrate_laser = true;
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

		debug_write("BIOS re-int");
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
