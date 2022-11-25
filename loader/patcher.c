
#include "bios.h"
#include "debugscreen.h"
#include "str.h"
#include "patcher.h"

/*
MottZilla's original notes from his email to me:
Once this is all done, the Cheat Engine is installed and ready. Now you just have to add cheats.

The cheat list starts at 0xD000 and is in the following format.
; Code Object: AA = Address 32bit, DD = Data 16bit, JE = Joypad Enable Combo, JD = Joypad Disable Combo
; EN = Code Enabled or Disabled, CC = Compare Value
; AA.AA.AA.AA.DD.DD.CC.CC.JE.JE.JD.JD.EN.EN.EN.EN

You can ignore the Joypad stuff as it isn't implemented yet. I might add it in the future. If you look, each cheat entry is 0x10 (16) bytes. So the first cheat is at  0xD000,next at 0xD010, 0xD020, and it keeps going until you run out of cheats. Probably not a great idea to put a million cheats in. =)

So a GameShark code of 80XXXXXX:XXXX, you would write the first part to 0xD000. Then you'd write the second XXXX part to 0xD004 as a 16-bit integer. Then if you want to only write memory if the original value was a specific value you write that original value to 0xD006. Finally to turn the code on you would write any 32-bit non-zero number to 0xD00C.
*/

const uint32_t gs_enable = 0x01010101;

void enable_code_1(const uint32_t gs1, const uint16_t gs2, const uint16_t gs3) {
    memcpy((void*)0xD000, &gs1, 4);
    memcpy((void*)0xD004, &gs2, 2);
    memcpy((void*)0xD006, &gs3, 2);
    memcpy((void*)0xD00C, &gs_enable, 4);
}

void enable_code_2(const uint32_t gs4, const uint16_t gs5, const uint16_t gs6) {
    memcpy((void*)0xD010, &gs4, 4);
    memcpy((void*)0xD014, &gs5, 2);
    memcpy((void*)0xD016, &gs6, 2);
    memcpy((void*)0xD01C, &gs_enable, 4);
}

void enable_code_3(const uint32_t gs7, const uint16_t gs8, const uint16_t gs9) {
    memcpy((void*)0xD020, &gs7, 4);
    memcpy((void*)0xD024, &gs8, 2);
    memcpy((void*)0xD026, &gs9, 2);
    memcpy((void*)0xD02C, &gs_enable, 4);
}

void install_cheat_engine() {
	#if !defined STEALTH
		//debug_write("Installing MottZilla AP Engine");
	#endif

const unsigned char MZ_CheatEngine_220820_bin[] = {
  0xe0, 0xff, 0xbd, 0x27, 0x00, 0x00, 0xa4, 0xaf, 0x04, 0x00, 0xa5, 0xaf,
  0x08, 0x00, 0xa6, 0xaf, 0x0c, 0x00, 0xa7, 0xaf, 0x00, 0x00, 0x04, 0x3c,
  0x00, 0xd0, 0x84, 0x34, 0x00, 0x00, 0x87, 0x8c, 0x06, 0x00, 0x85, 0x94,
  0x1d, 0x00, 0xe0, 0x10, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x15, 0x00, 0xe0, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x86, 0x8c, 0x00, 0xff, 0x07, 0x3c,
  0x00, 0x00, 0xe7, 0x34, 0x24, 0x30, 0xe6, 0x00, 0x00, 0x80, 0x07, 0x3c,
  0x00, 0x00, 0xe7, 0x34, 0x0c, 0x00, 0xc7, 0x14, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x87, 0x8c, 0x05, 0x00, 0xa0, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00,
  0x04, 0x00, 0xc5, 0x14, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa4, 0x10, 0x00, 0x84, 0x24,
  0xe2, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xa4, 0x8f, 0x04, 0x00, 0xa5, 0x8f, 0x08, 0x00, 0xa6, 0x8f,
  0x0c, 0x00, 0xa7, 0x8f, 0x20, 0x00, 0xbd, 0x27, 0x01, 0x00, 0x1a, 0x3c,
  0xfc, 0xcf, 0x5a, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x40, 0x03,
  0x00, 0x00, 0x00, 0x00
};

	memcpy((void*)0xC000, (void*)MZ_CheatEngine_220820_bin, sizeof(MZ_CheatEngine_220820_bin)); // Copy MottZilla's cheat engine assembly binary to 0xC000
	const uint32_t b0_jump = (*(uint32_t*)0xB4) & 0xFFFF;
	#if !defined STEALTH
		//debug_write("Got jump address for B0 functions : %x", (uint32_t) b0_jump);
	#endif
	const uint32_t b0_base = (*(uint32_t*)(b0_jump + 4)) & 0xFFFF;
	#if !defined STEALTH
		//debug_write("Got base address for B0 table : %x", (uint32_t) b0_base);
	#endif
	const uint32_t b0_entry = b0_base + (0x17 * 4);
	#if !defined STEALTH
		//debug_write("Got B0 table entry address : %x", (uint32_t) b0_entry);
	#endif
	const uint32_t old_table_val = *(uint32_t*) b0_entry;
	#if !defined STEALTH
		//debug_write("B0 table entry to modify has the original contents : %x", (uint32_t) old_table_val);
	#endif
	memcpy((void*)0xCFFC, (void*)&old_table_val, sizeof(old_table_val)); // Copy the original 32 bit number of the B table entry we want to modify to 0xCFFC
	const uint16_t redirect = 0xC000;
	memcpy((void*)b0_entry, &redirect, 2); // Write the value 0xC000 to table entry we want to modify
   //for (volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause
}

void activate_anti_anti_piracy(const char * bootfile, const int32_t load_addr) 
{
	int32_t ver_check;
	uint8_t ver_check_val;

// Animetic Story Game 1: Card Captor Sakura
   	if(((strcmp("cdrom:\\SLPS_018.30;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLPS_018.31;1", bootfile)) == 0)) { // 2 disc game
   		#if !defined STEALTH
			//debug_write("Detected ASG 1: Card Captor Sakura");
		#endif
		/*
		D001516A 1040
		8001516A 1000
		code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_c.shtml
    	*/
    	enable_code_1(0x8001516A, 0x1000, 0x1040);
    	install_cheat_engine();
    }

// Alundra 2
	if((strcmp("cdrom:\\SCPS_101.15;1", bootfile)) == 0) { 
   		#if !defined STEALTH
			//debug_write("Detected Alundra 2 - JPN");
		#endif
		/*
		D004E91A 1040
		8004E91A 1000
		'skip mod check' code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_a.shtml
    	*/
    	enable_code_1(0x8004E91A, 0x1000, 0x1040);
    	install_cheat_engine();
    }

// Arc The Lad III
	if(((strcmp("cdrom:\\SCPS_101.06;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCPS_101.07;1", bootfile)) == 0)) { // 2 Japan versions and each have 2 discs but the same codes per revision
   		#if !defined STEALTH
			//debug_write("Detected ATL III - JPN");
		#endif
		ver_check = (load_addr + 0x20); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0x8C))
		{
			debug_write("REV 0");
			/*
			D0021DF6 1040
			80021DF6 1000
			code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_a.shtml
    		*/
    		enable_code_1(0x80021DF6, 0x1000, 0x1040);
    		install_cheat_engine();
    	} else {
			debug_write("REV 1");
 			// D0022206 1040 alex-free's code via aprip gameshark code conversion
			// 80022206 1000
    		enable_code_1(0x80022206, 0x1000, 0x1040);
    		install_cheat_engine();		
    	}
    }

// Beat Mania: The Sound of Tokyo
	if((strcmp("cdrom:\\SLPM_867.69;1", bootfile)) == 0) { 
   		#if !defined STEALTH
			//debug_write("Detected Beat Mania - The Sound of Tokyo");
		#endif
    	/*
		D0134C48 001E
		80134C48 0000
		alex-free's code to patch out readtoc
    	*/
    	enable_code_1(0x80134C48, 0x0000, 0x001E);
    	install_cheat_engine();
    }

// Beat Mania 6thMix + Core Remix
	if((strcmp("cdrom:\\SLPM_870.12;1", bootfile)) == 0) { 
   		#if !defined STEALTH
			//debug_write("Detected Beat Mania 6th Mix + Core Remix");
		#endif
		/*
		D0131B6C 001E
		80131B6C 001A
    	alex-free's code to patch out readtoc
    	*/
    	enable_code_1(0x80131B6C, 0x0000, 0x001E);
    	install_cheat_engine();
    }

// Biohazard 3: The Last Escape
   	if((strcmp("cdrom:\\SLPS_023.00;1", bootfile)) == 0) { // 2 different versions
   		#if !defined STEALTH
			//debug_write("Detected Biohazard 3 - JPN");
		#endif
		ver_check = (load_addr + 0x1B0); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0xF4))
		{
			debug_write("REV 0");
			/*
			D01840E2 1040
			801840E2 1000
			'skip check' code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
    		*/
    		enable_code_1(0x801840E2, 0x1000, 0x1040);
    		install_cheat_engine();
	    } else {
			debug_write("REV 1");
			/*
			D018418E 1040
			8018418E 1000 
			alex-free's code via aprip gameshark code conversion
    		*/
    		enable_code_1(0x8018418E, 0x1000, 0x1040);
    		install_cheat_engine();
	    }
	}

   	if((strcmp("cdrom:\\SLPM_804.85;1", bootfile)) == 0) { // Demo
   		#if !defined STEALTH
			//debug_write("Detected Bio Hazard 3 Demo");
		#endif
		/*
		D01800E2 1040
		801800E2 1000 
		my code via aprip gameshark code conversion
    	*/
    	enable_code_1(0x801800E2, 0x1000, 0x1040);
    	install_cheat_engine();
	}

// Chase The Express
   	if(((strcmp("cdrom:\\TRAIN\\SCPS_101.09;1", bootfile)) == 0) || ((strcmp("cdrom:\\TRAIN\\SCPS_101.10;1", bootfile)) == 0) || ((strcmp("cdrom:\\TRAIN\\PAPX_901.06;1", bootfile)) == 0) || ((strcmp("cdrom:\\TRAIN\\PCPX_961.89;1", bootfile)) == 0)) { // 2 discs and 2 demos all share the same code
   		#if !defined STEALTH
			//debug_write("Detected Chase The Express - JPN");
		#endif
		/*
		D00EA6DE 1040
		800EA6DE 1000
		'skip mod check' code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_c.shtml
    	*/
    	enable_code_1(0x800EA6DE, 0x1000, 0x1040);
    	install_cheat_engine();
    }

// Crash Bandicoot Racing
   	if((strcmp("cdrom:\\SCPS_101.18;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Crash Bandicoot Racing");
		#endif
		/*
		D001259A 1040
		8001259A 1000
		'skip mod check' code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml (yes it's on the wrong lettered page)
    	*/
    	enable_code_1(0x8001259A, 0x1000, 0x1040);
    	install_cheat_engine();
    }

   	if((strcmp("cdrom:\\PCPX_961.83;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Crash Bandicoot Racing Demo");
		#endif
		/*
    	D001255E 1040
    	8001255E 1040
		alex-free's code via aprip gameshark code conversion
    	*/
    	enable_code_1(0x8001255E, 0x1000, 0x1040);
    	install_cheat_engine();
    }

// Crash Bash
  	if((strcmp("cdrom:\\SCUS_945.70;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Crash Bash - USA");
		#endif
		/*
		D002D51E 1040
		8002D51E 1000
		code by https://gbatemp.net/members/m4x1mumrez.610331/
		*/
		enable_code_1(0x8002D51E, 0x1000, 0x1040);
		install_cheat_engine();
	}

   	if((strcmp("cdrom:\\SCPS_101.40;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Crash Bash - JPN");
		#endif
		/*
		D002D7EE 1040
		8002D7EE 1000
		code from GameHacking: https://gamehacking.org/game/93827
		*/
		enable_code_1(0x8002D7EE, 0x1000, 0x1040);
		install_cheat_engine();
	}

   	if((strcmp("cdrom:\\PCPX_962.02;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Crash Bash - JPN Demo");
		#endif
		/*
		D002D3BE 1040
		8002D3BE 1000
		code by https://gbatemp.net/members/m4x1mumrez.610331/
		*/
		enable_code_1(0x8002D3BE, 0x1000, 0x1040);
		install_cheat_engine();
	}

// Cool Boarders 2001
   	if((strcmp("cdrom:\\SCUS_946.25;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Cool Boarders 2001 - USA Demo");
		#endif
		/*
		D00B35B0 001E
		800B35B0 0000
		code generated via aprip
		*/
		enable_code_1(0x800B35B0, 0x0000, 0x001E);
		install_cheat_engine();
	}

   	if((strcmp("cdrom:\\SCUS_945.97;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Cool Boarders 2001 - USA");
		#endif
		/*
		D00B35B8 001E
		800B35B8 0000
		alex-free's code via aprip gameshark code conversion
		*/
		enable_code_1(0x800B35B8, 0x0000, 0x001E);
		install_cheat_engine();
	}

// Dance Dance Revolution - Best Hits
	if((strcmp("cdrom:\\SLPM_866.93;1", bootfile)) == 0) {
		#if !defined STEALTH
			//debug_write("Detected DDR - Best Hits");
		#endif
		/*
		D0102FA0 001E
		80102FA0 0000
		code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
		enable_code_1(0x80102FA0, 0x0000, 0x001E);
		install_cheat_engine();
	}

// Dancing Stage - Euro Mix
	if((strcmp("cdrom:\\SLES_029.41;1", bootfile)) == 0) {
		#if !defined STEALTH
			//debug_write("Detected Dancing Stage - Euro Mix");
		#endif
		/*
		D00F5A10 001E
		800F5A10 0000
		code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
		enable_code_1(0x800F5A10, 0x0000, 0x001E);
		install_cheat_engine();
	}
		
// Dancing Stage Featuring True Kiss Destination
   	if((strcmp("cdrom:\\SLPM_864.11;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Dancing Stage Ft. Kiss Destination");
		#endif
		/*
		D019117A 1040
		8019117A 1000
		code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml
		*/
		enable_code_1(0x8019117A, 0x1000, 0x1040);
		install_cheat_engine();
	}

// Dino Crisis
	if((strcmp("cdrom:\\SLUS_009.22;1", bootfile) == 0)) { // NTSC-U has 2 versions, rev 0 and rev 1 (greatest hits) see https://tcrf.net/Dino_Crisis_(PlayStation)#Revisional_Differences
		#if !defined STEALTH
			//debug_write("Detected Dino Crisis - USA");
		#endif
		ver_check = (load_addr + 0x61); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0xD0)) {
			#if !defined STEALTH
				debug_write("Rev 0");
			#endif
			/*
			D0149004 959C
			80149004 9E64
			Found independently by MottZilla, but actually turns out to be the same code by Epson found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml
			*/
  		  	enable_code_1(0x80149004, 0x9E64, 0x959C);
			install_cheat_engine();
		} else {
			#if !defined STEALTH
				debug_write("Rev 1");
			#endif
			/*
			D0148004 8658
			80148004 8F20
			alex-free's code, the anti-piracy table just moved memory addresses between versions :)
			*/
 		   	enable_code_1(0x80148004, 0x8F20, 0x8658);
			install_cheat_engine();
    	}
}

   	if((strcmp("cdrom:\\SLPS_021.80;1", bootfile)) == 0) { // Same as USA Rev 0
   		#if !defined STEALTH
			//debug_write("Detected Dino Crisis - JPN");
		#endif
		/*
		D0149004 959C
		80149004 9E64
		Found independently by MottZilla, but actually turns out to be the same code by Epson found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml . Yes this is the same code as the USA rev 0 one.
		*/
  		enable_code_1(0x80149004, 0x9E64, 0x959C);
		install_cheat_engine();
    }

// Dino Crisis 2
   	if((strcmp("cdrom:\\SLPM_866.27;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Dino Crisis 2 - JPN");
		#endif
  		/*
		D00D7714 001E
		800D7714 0000
		alex-free's code via aprip to disable readtoc
		*/
		enable_code_1(0x800D7714, 0x0000, 0x001E);
		install_cheat_engine();
    }

   	if((strcmp("cdrom:\\SLPM_805.73;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Dino Crisis 2 - JPN Demo");
		#endif
  		/*
		D00CB104 001E
		800CB104 0000
		alex-free's codevia aprip to disable readtoc
		*/
		enable_code_1(0x800CB104, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Disney's The Emperor's New Groove
   	if((strcmp("cdrom:\\SCUS_945.71;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Disney's The Emperor's New Groove - USA");
		#endif
  		/*
		D0063004 001E
		80063004 0000
		alex-free's code via aprip to disable readtoc
		*/
		enable_code_1(0x80063004, 0x0000, 0x001E);
		install_cheat_engine();
    }

   	if((strcmp("cdrom:\\SCES_030.10;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Disney's The Emperor's New Groove - EUR");
		#endif
  		/*
		D006351C 001E
		8006351C 0000
		alex-free's code via aprip to disable readtoc
		*/
		enable_code_1(0x8006351C, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Exciting Bass 2
   	if((strcmp("cdrom:\\SLPM_862.95;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Exciting Bass 2");
		#endif
		/*
		D00177BA 1040
		800177BA 1000	
		code found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_e.shtml
  		*/
  		enable_code_1(0x800177BA, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Exciting Bass 3
   	if((strcmp("cdrom:\\SLPM_867.29;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Exciting Bass 3");
		#endif
		/*
		D00B9170 001E
		800B9170 0000
		alex-free's code to patch out readtoc via aprip
  		*/
  		enable_code_1(0x800B9170, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner
   	if((strcmp("cdrom:\\SCPS_101.34;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner");
		#endif
		/*
		D0195D9C 001E
		80195D9C 0000
		alex-free's code to patch out readtoc via aprip
  		*/
  		enable_code_1(0x80195D9C, 0x0000, 0x001E);
  		install_cheat_engine();
    }

// Goo! Goo! Soundry
   	if((strcmp("cdrom:SLPM_862.50;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Goo Goo Soundry");
		#endif
		/*
		D0055278 001E
		80055278 0000
		alex-free's code to patch out readtoc via aprip
  		*/
  		enable_code_1(0x80055278, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Grind Session
   	if((strcmp("cdrom:\\SCUS_945.68;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Grind Session");
		#endif
		/*
		D0014274 52A9
		80014274 50BE
		code 1 of 2 by 'TheVoice' found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
		*/
  		enable_code_1(0x80014274, 0x50BE, 0x52A9);
		/*
		D00146FE 1040
		800146FE 1000
		code 2 of 2 by 'TheVoice' found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
		*/
  		enable_code_2(0x800146FE, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Guitar Freaks
   	if((strcmp("cdrom:\\SLPM_862.65;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Guitar Freaks");
		#endif
		/*
		D001654E 1040
		8001654E 1000
		code found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
		*/
  		enable_code_1(0x8001654E, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Harlem Beat: You're The One
   	if((strcmp("cdrom:SLPM_863.29;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Harlem Beat");
		#endif
		/*
		D01A411E 1040
		801A411E 1000
		code found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
		*/
  		enable_code_1(0x801A411E, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Hyper Value 2800: Mahjong
   	if((strcmp("cdrom:\\SLPM_862.92;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Hyper Value 2800 Mahjong");
		#endif
		/*
		D00A0186 1040
		800A0186 1000
		code found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
		*/
  		enable_code_1(0x800A0186, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Jikkyou Powerful Pro Yakyuu '99 Ketteiban
   	if((strcmp("cdrom:\\SLPM_864.33;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Jikkyou Powerful Pro Yakyuu '99 Ketteiban");
		#endif
  		/*
		D016B4D8 001E
		8016B4D8 0000
		alex-free's code to patch out readtoc via aprip
		*/
  		enable_code_1(0x8016B4D8, 0x0000, 0x001E);
		install_cheat_engine();
	}

// Jikkyou Powerful Pro Yakyuu '99: Kaimakuban
   	if((strcmp("cdrom:\\SLPM_862.53;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Jikkyou Powerful Pro Yakyuu '99 Kaimakuban");
		#endif
		/*
		D016B268 001E
		8016B268 0000
		alex-free's code to patch out readtoc via aprip
		*/
  		enable_code_1(0x8016B268, 0x0000, 0x001E);
		install_cheat_engine();
	}

// JoJo's Bizarre Adventure
   	if((strcmp("cdrom:\\SLPS_022.36;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected JoJo's Bizarre Adventure");
		#endif
		/*
		D0035C48 D91E
		80035C48 D733
		code 1 of 2 found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_j.shtml
		*/
  		enable_code_1(0x80035C48, 0xD733, 0xD91E);
  		/*
		D00360D2 1040
		800360D2 1000
		code 2 of 2 found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_j.shtml
		*/
  		enable_code_2(0x800360D2, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Kore Hore! Pukka
	if((strcmp("cdrom:\\SCPS_101.33;1", bootfile)) == 0) {
		#if !defined STEALTH
			//debug_write("Detected Kore Hore! Pukka");
		#endif
		/*
		D00A341C 001E
		800A341C 0000
		code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
  		enable_code_1(0x800A341C, 0x0000, 0x001E);
		install_cheat_engine();
	}

// Koukidou Gensou - Gunparade March
	if((strcmp("cdrom:\\SCPS_101.36;1", bootfile)) == 0) {
		#if !defined STEALTH
			//debug_write("Detected Gunparade March");
		#endif
		/*
		D00FC218 001E
		800FC218 0000
		code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
		enable_code_1(0x800FC218, 0x0000, 0x001E);
		install_cheat_engine();
	}

// Legend Of Dragoon
   	if(((strcmp("cdrom:\\SCPS_101.19;1", bootfile)) == 0) || ((strcmp("cdrom:\\scps_101.20;1", bootfile)) == 0) || ((strcmp("cdrom:\\scps_101.21;1", bootfile)) == 0) || ((strcmp("cdrom:\\scps_101.22;1", bootfile)) == 0)) { // 4 discs
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Dragoon - JPN");
		#endif
		/*
		D01BF172 1040
		801BF172 1000
		code found on copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
		*/
  		enable_code_1(0x801BF172, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if(((strcmp("cdrom:\\SCUS_944.91;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCUS_945.84;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCUS_945.85;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCUS_945.86;1", bootfile)) == 0)) { // 4 discs
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Dragoon - USA");
		#endif
		/*
		801BF6F6 1040
		801BF6F6 1000 
		alex-free's code via aprip's gameshark conversion
   		*/
  		enable_code_1(0x801BF6F6, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if(((strcmp("cdrom:\\SCES_030.43;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_130.43;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_230.43;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_330.43;1", bootfile)) == 0)) { // 4 discs
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Dragoon - EUR");
		#endif
		/*
		D01C0892 1040
		801C0892 1000
		alex-free's code via aprip's gameshark conversion
		*/
  		enable_code_1(0x801C0892, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if(((strcmp("cdrom:\\SCES_030.44;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_130.44;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_230.44;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_330.44;1", bootfile)) == 0)) { // 4 discs
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Dragoon - FRA");
		#endif
		/*
		D01C0872 1040
		801C0872 1040
		alex-free's code via aprip's gameshark conversion
		*/
  		enable_code_1(0x801C0872, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if(((strcmp("cdrom:\\SCES_030.45;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_130.45;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_230.45;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_330.45;1", bootfile)) == 0)) { // 4 discs
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Dragoon - GER");
		#endif
		/*
		D01C082E 1040
		801C082E 1000
		alex-free's code via aprip's gameshark conversion
  		*/
  		enable_code_1(0x801C082E, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if(((strcmp("cdrom:\\SCES_030.46;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_130.46;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_230.46;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCES_330.46;1", bootfile)) == 0)) { // 4 discs
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Dragoon - ITA");
		#endif
		/*
		D01C0826 1040
		801C0826 1000
		alex-free's code via aprip's gameshark conversion
		*/
  		enable_code_1(0x801C0826, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Legend Of Mana
   	if((strcmp("cdrom:SLPS_021.70;1", bootfile)) == 0) { // Japan
   		#if !defined STEALTH
			//debug_write("Detected Legend Of Mana");
		#endif
		/*
		D0050ECA 1040 
		80050ECA 1000
		code 1 of 2 from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
		*/
  		enable_code_1(0x80050ECA, 0x1000, 0x1040);
		/*
		D00360D2 1040
		800360D2 1000
		code 2 of 2 from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
		*/
 		enable_code_2(0x800360D2, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Love Hina: Ai wa Kotoba no Naka ni & Love Hina 2: Kotoba wa Konayuki no You ni 
   	if(((strcmp("cdrom:\\SLPM_866.52;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLPM_866.77;1", bootfile)) == 0)) { // Both share the same code
   		#if !defined STEALTH
			//debug_write("Detected Love Hina 1 or 2");
		#endif
		/*
		 D01011C0 001E
		 801011C0 0000
		code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
 		enable_code_1(0x801011C0, 0x0000, 0x001E);
 		install_cheat_engine();
    }

// Marvel vs. Capcom: Clash of Super Heroes
   	if(((strcmp("cdrom:\\SLPS_023.68;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLPM_805.08;1", bootfile)) == 0)) { // Japan/Japan Demo share same code
   		#if !defined STEALTH
			//debug_write("Detected Marvel vs. Capcom Clash of Super Heroes");
		#endif
		/*
		D00F0C3A 1040
		800F0C3A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
		*/
 		enable_code_1(0x800F0C3A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// My Garden
   	if((strcmp("cdrom:\\SLPS_022.13;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected My Garden");
		#endif
		/*
		D009E212 1040
		8009E212 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
		*/
 		enable_code_1(0x8009E212, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Ore no Ryouri
   	if((strcmp("cdrom:SCPS_100.99;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Ore no Ryouri");
		#endif
		/*
		D0031C1A 1040
		80031C1A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
		*/
 		enable_code_1(0x80031C1A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Pocket Jiman
   	if((strcmp("cdrom:\\SCPS_101.04;1", bootfile)) == 0) { // 3 discs
   		#if !defined STEALTH
			//debug_write("Detected Pocket Jiman");
		#endif
		/*
		 D0126BDC 001E
		 80126BDC 0000
		 code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
 		enable_code_1(0x80126BDC, 0x0000, 0x001E);
		install_cheat_engine();
    }

// PoPoLoCrois Monogatari II
   	if(((strcmp("cdrom:\\SCPS_101.12;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCPS_101.13;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCPS_101.14;1", bootfile)) == 0)) { // 3 discs
   		#if !defined STEALTH
			//debug_write("Detected PoPoLoCrois Monogatari II");
		#endif
		/*
		 D00B2612 1040
		 800B2612 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml
		*/
 		enable_code_1(0x800B2612, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Pop'n Music 2
   	if((strcmp("cdrom:\\SLPM_862.94;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Pop 'N Music 2");
		#endif
		/*
		D0015342 1040
		80015342 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml
		*/
 		enable_code_1(0x80015342, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Pop'n Music 5
   	if((strcmp("cdrom:\\SLPM_869.37;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Pop'n Music 5");
		#endif
   		/*
		D0048F34 001E
		80048F34 0000
		alex-free's code via aprip to patch out readtoc
		*/
 		enable_code_1(0x80048F34, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Pop'n Music 6
   	if((strcmp("cdrom:\\SLPM_870.89;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Pop'n Music 6");
		#endif
 		/*
		D004A24D 001E
		8004A24D 0000
		alex-free's code via aprip to patch out readtoc
		*/
 		enable_code_1(0x8004A24D, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Resident Evil Survivor
   	if((strcmp("cdrom:\\SLPS_025.53;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Resident Evil Survivor - JPN");
		#endif
		/*
		D0017962 1040
		80017962 1000
		'skip mod check' code is from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
		*/
		enable_code_1(0x80017962, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if((strcmp("cdrom:\\SLUS_010.87;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Resident Evil Survivor - USA");
		#endif
		/*
		D001714E 1040
		8001714E 1000
		converted code via aprip
		*/
		enable_code_1(0x8001714E, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if(((strcmp("cdrom:\\SLES_027.32;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLES_027.44;1", bootfile)) == 0)) { // Same code works on both Europe and France versions
   		#if !defined STEALTH
			//debug_write("Detected Resident Evil Survivor - EUR/FRA");
		#endif
		/*
		D001713E 1040
		8001713E 1000
		converted code via aprip
		*/
		enable_code_1(0x8001713E, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Robbit mon Dieu
   	if((strcmp("cdrom:SCPS_101.03;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Robbit Mon Dieu");
		#endif
		/*
		D001C646 1040
		8001C646 1000
		'skip mod check' code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
 		enable_code_1(0x8001C646, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Rockman
   	if((strcmp("cdrom:\\SLPS_022.20;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Rockman 1");
		#endif
		/*
		D006C92A 1040
		8006C92A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
 		enable_code_1(0x8006C92A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Rockman 2: Dr. Wily no Nazo
   	if((strcmp("cdrom:\\SLPS_022.55;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Rockman 2");
		#endif
		/*
		D006CA82 1040
		8006CA82 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
 		enable_code_1(0x8006CA82, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Rockman 3: Dr. Wily no Saigo!?
   	if((strcmp("cdrom:\\SLPS_022.62;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Rockman 3");
		#endif
		/*
		D006CA1A 1040
		8006CA1A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
 		enable_code_1(0x8006CA1A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Rockman 4: Aratanaru Yabou!!
   	if((strcmp("cdrom:\\SLPS_023.24;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Rockman 4");
		#endif
 		/*
 		D007009C 001E
		8007009C 0000
 		alex-free's code via aprip to patch out readtoc
		*/
 		enable_code_1(0x8007009C, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Rockman 6
   	if((strcmp("cdrom:\\SLPS_023.79;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Rockman 6");
		#endif
		/*
		D006DA7A 1040
		8006DA7A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
 		enable_code_1(0x8006DA7A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Street Fighter EX2 Plus
   	if((strcmp("cdrom:\\SLPS_025.08;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Street Fighter EX2 Plus");
		#endif
		/*
		D01BD48A 1040
		801BD48A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_s.shtml
		*/
 		enable_code_1(0x801BD48A, 0x1000, 0x1040);
		install_cheat_engine();
    }

   	if((strcmp("cdrom:\\SLPM_805.17;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Street Fighter EX2 Plus Demo");
		#endif
		/*
		D01BD13E 1040
		801BD13E 1000
		alex-free's code via aprip gameshark code conversion
		*/
 		enable_code_1(0x801BD48A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Tomba! 2: The Evil Swine Return
   	if((strcmp("cdrom:\\SCUS_944.54;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected TOMBA! 2 - USA");
		#endif
		/*
		D002542C 001E
		8002542C 0000
		alex-free's code via aprip
		*/
 		enable_code_1(0x8002542C, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Vandal Harts II
   	if((strcmp("cdrom:\\SLUS_009.40;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Vandal Harts II - USA");
		#endif
 		/*
		D00865FC 001E
		800865FC 0000
		alex-free's code via aprip to patch out readtoc
		*/
 		enable_code_1(0x800865FC, 0x0000, 0x001E);
		install_cheat_engine();
    }

// Wild Arms 2
   	if(((strcmp("cdrom:\\SCUS_944.84;1", bootfile)) == 0) || ((strcmp("cdrom:\\SCUS_944.98;1", bootfile)) == 0)) { // 2 discs
   		#if !defined STEALTH
			//debug_write("Detected Wild Arms 2 - USA");
		#endif
   		/*
   		D003A4E8 001E
   		8003A4E8 0000
 		alex-free's code via aprip to patch out readtoc
		*/
 		enable_code_1(0x8003A4E8, 0x0000, 0x001E);
		install_cheat_engine();
    }

   	if((strcmp("cdrom:\\SCUS_945.92;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected Wild Arms 2 - USA Demo");
		#endif
		/*
   		D003A5D4 001E
   		8003A5D4 0000
		alex-free's code via aprip gameshark code conversion on my own code (code-ception)
		*/
 		enable_code_1(0x8003A5D4, 0x0000, 0x001E);
		install_cheat_engine();
    }

// World Soccer Jikkyou Winning Eleven 4
   	if((strcmp("cdrom:SLPM_862.91;1", bootfile)) == 0) { // 2 revisions, same code works on rev 0 and rev 1
   		#if !defined STEALTH
			//debug_write("Detected Winning Eleven 4");
		#endif
		/*
   		D01030CA 1040
		801030CA 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_w.shtml
		*/
 		enable_code_1(0x801030CA, 0x1000, 0x1040);
		install_cheat_engine();
    }

// XI[SAI] Jumbo
   	if((strcmp("cdrom:\\SCPS_101.23;1", bootfile)) == 0) {
   		#if !defined STEALTH
			//debug_write("Detected XI[Sai] Jumbo");
		#endif
   		/*
   		D010178A 1040
		8010178A 1000
		code 1 of 3 from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_x.shtml
		*/
 		enable_code_1(0x8010178A, 0x1000, 0x1040);
 		/*
		D00A370A 1040
		800A370A 1000
		code 2 of 3 from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_x.shtml
		*/
 		enable_code_2(0x800A370A, 0x1000, 0x1040);
 		/*
		D0113C1A 1040
		80113C1A 1000
		code 3 of 3 from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_x.shtml
		*/
 		enable_code_3(0x80113C1A, 0x1000, 0x1040);
		install_cheat_engine();
    }

// Yu-Gi-Oh! Forbidden Memories
   	if(((strcmp("cdrom:SLPM_863.96;1", bootfile)) == 0) || ((strcmp("cdrom:SLPM_863.98;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLUS_014.11;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLES_039.47;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLES_039.48;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLES_039.49;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLES_039.50;1", bootfile)) == 0) || ((strcmp("cdrom:\\SLES_039.51;1", bootfile)) == 0)) { //same code skips mod check on ALL VERSIONS EVER!
   		#if !defined STEALTH
			//debug_write("Detected Yu-Gi-Oh! Forbidden Memories");
		#endif
		/*
		D016818A 1040
		8016818A 1000
		code from copyconsoleworld: https://consolecopyworld.com/psx/psx_game_codes_y.shtml
		*/
 		enable_code_1(0x8016818A, 0x1000, 0x1040);
		install_cheat_engine();
    }

}
