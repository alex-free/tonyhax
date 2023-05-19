
#include "bios.h"
//#include "debugscreen.h"
#include "str.h"
#include "ap-bypass.h"

bool cheat_engine_installed;

uint8_t gs_code_type;

int32_t code_address_ram_location = 0xD000;
int32_t code_compare_ram_location = 0xD004;
int32_t code_enable_ram_location = 0xD00C;  

void add_30_code(const uint32_t gs1, const uint8_t gs2) {
	gs_code_type = 0x30;
    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 1);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
	code_address_ram_location = (code_address_ram_location + 0x010);
	code_compare_ram_location = (code_compare_ram_location + 0x010);
	code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void add_E0_code(const uint32_t gs1, const uint8_t gs2) {
	gs_code_type = 0xE0;
    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 1);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
	code_address_ram_location = (code_address_ram_location + 0x010);
	code_compare_ram_location = (code_compare_ram_location + 0x010);
	code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void add_E1_code(const uint32_t gs1, const uint8_t gs2) {
	gs_code_type = 0xE1;
    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 1);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
	code_address_ram_location = (code_address_ram_location + 0x010);
	code_compare_ram_location = (code_compare_ram_location + 0x010);
	code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void add_80_code(const uint32_t gs1, const uint16_t gs2) {
	gs_code_type = 0x80;
    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 2);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
	code_address_ram_location = (code_address_ram_location + 0x010);
	code_compare_ram_location = (code_compare_ram_location + 0x010);
	code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void add_D0_code(const uint32_t gs1, const uint16_t gs2) {
	gs_code_type = 0xD0;
    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 2);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
	code_address_ram_location = (code_address_ram_location + 0x010);
	code_compare_ram_location = (code_compare_ram_location + 0x010);
	code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void add_D1_code(const uint32_t gs1, const uint16_t gs2) {
	gs_code_type = 0xD1;
    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 2);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
	code_address_ram_location = (code_address_ram_location + 0x010);
	code_compare_ram_location = (code_compare_ram_location + 0x010);
	code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void install_cheat_engine() {
// generate with `scripts/stealth-engine-xxd.sh` after compiling .EXE file with No $ PSX Assembler
const unsigned char cheat_engine_v1_0_2[] = {
0xe0, 0xff, 0xbd, 0x27, 0x00, 0x00, 0xa4, 0xaf,
  0x04, 0x00, 0xa5, 0xaf, 0x08, 0x00, 0xa6, 0xaf, 0x0c, 0x00, 0xa7, 0xaf,
  0x00, 0x00, 0x04, 0x3c, 0x00, 0xd0, 0x84, 0x34, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x86, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x53, 0x00, 0xc0, 0x10,
  0x30, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00, 0xc7, 0x10,
  0x80, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x13, 0x00, 0xc7, 0x10,
  0xe0, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x1a, 0x00, 0xc7, 0x10,
  0xd0, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0xc7, 0x10,
  0xe1, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0xc7, 0x10,
  0xd1, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x29, 0x00, 0xc7, 0x10,
  0x30, 0x00, 0x07, 0x34, 0x1c, 0x00, 0x86, 0x8c, 0x00, 0x00, 0x00, 0x00,
  0x2d, 0x00, 0xc7, 0x10, 0x80, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00,
  0x2f, 0x00, 0xc7, 0x10, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa4, 0x32, 0x00, 0x00, 0x18,
  0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe5, 0xa0, 0x2d, 0x00, 0x00, 0x18, 0x04, 0x00, 0x85, 0x90,
  0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90,
  0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0xc5, 0x14, 0x00, 0x00, 0x00, 0x00,
  0xe7, 0xff, 0x00, 0x18, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90, 0x00, 0x00, 0x00, 0x00,
  0x1c, 0x00, 0xc5, 0x10, 0x00, 0x00, 0x00, 0x00, 0xdf, 0xff, 0x00, 0x18,
  0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0xc5, 0x14,
  0x00, 0x00, 0x00, 0x00, 0xd7, 0xff, 0x00, 0x18, 0x04, 0x00, 0x85, 0x94,
  0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94,
  0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0xc5, 0x10, 0x00, 0x00, 0x00, 0x00,
  0xcf, 0xff, 0x00, 0x18, 0x14, 0x00, 0x85, 0x90, 0x10, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa0, 0x05, 0x00, 0x00, 0x18,
  0x14, 0x00, 0x85, 0x94, 0x10, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe5, 0xa4, 0x00, 0x00, 0x00, 0x18, 0x20, 0x00, 0x84, 0x24,
  0xae, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x84, 0x24,
  0xab, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, 0x8f,
  0x04, 0x00, 0xa5, 0x8f, 0x08, 0x00, 0xa6, 0x8f, 0x0c, 0x00, 0xa7, 0x8f,
  0x20, 0x00, 0xbd, 0x27, 0x01, 0x00, 0x1a, 0x3c, 0xfc, 0xcf, 0x5a, 0x8f,
  0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00
};

	//debug_write("Installing MottZilla AP Engine");
	memcpy((void*)0xC000, (void*)cheat_engine_v1_0_2, sizeof(cheat_engine_v1_0_2)); // Copy MottZilla's cheat engine assembly binary to 0xC000
	const uint32_t b0_jump = (*(uint32_t*)0xB4) & 0xFFFF;
	//debug_write("Got jump address for B0 functions : %x", (uint32_t) b0_jump);
	const uint32_t b0_base = (*(uint32_t*)(b0_jump + 4)) & 0xFFFF;
	//debug_write("Got base address for B0 table : %x", (uint32_t) b0_base);
	const uint32_t b0_entry = b0_base + (0x17 * 4);
	//debug_write("Got B0 table entry address : %x", (uint32_t) b0_entry);
	const uint32_t old_table_val = *(uint32_t*) b0_entry;
	//debug_write("B0 table entry to modify has the original contents : %x", (uint32_t) old_table_val);
	memcpy((void*)0xCFFC, (void*)&old_table_val, sizeof(old_table_val)); // Copy the original 32 bit number of the B table entry we want to modify to 0xCFFC
	const uint16_t redirect = 0xC000;
	memcpy((void*)b0_entry, &redirect, 2); // Write the value 0xC000 to table entry we want to modify
   //for (volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause
   cheat_engine_installed = 1;
}

void activate_anti_anti_piracy(const char * bootfile, const int32_t load_addr) 
{
	int32_t ver_check;
	uint8_t ver_check_val;
	int8_t bootfile_len = strlen(bootfile);

	// Aprip code type constants
	const uint16_t readtoc_compare_val = 0x001E;
	const uint16_t readtoc_patch_val = 0x0000;

	// Many pre-existing 'skip mod check' or 'force routine ok' type codes from back in the day seem to share these values, so they are a const
	const uint16_t common_routine_return_compare_val = 0x1040;
	const uint16_t common_routine_return_patch_val = 0x1000;

	if(bootfile_len > 13) {
		bootfile = &bootfile[bootfile_len-13]; // XXXX_XXX.XX;1 , we are only chaning the locally declared bootfile here, not in secondary.c
		//debug_write("Stripped Bootfile: %s", bootfile);
	} else if(bootfile_len < 13) {
		return; 
		// Speed optimization. All anti-piracy games currently have a bootfile name that is at least 13 uchars long when stripped. So if the bootfile happens to have something like 'MAIN.EXE;1' (which is 10 uchars long), we already know not to bother even checking for an anti-piracy bootfile match to apply codes for (which takes time in itself to do as well).
	}

// Animetic Story Game 1: Card Captor Sakura
   	if(((strcmp("SLPS_018.30;1", bootfile)) == 0) || ((strcmp("SLPS_018.31;1", bootfile)) == 0)) { // 2 disc game
   		//debug_write("Detected Animetic Story Game 1: Card Captor Sakura");
		/*
		D001516A 1040
		8001516A 1000
		code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_c.shtml
    	*/
    	add_D0_code(0x8001516A, common_routine_return_compare_val);
		add_80_code(0x8001516A, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Alundra 2
	((strcmp("SCPS_101.15;1", bootfile)) == 0) { 
   		//debug_write("Detected Alundra 2 - Japan");
		/*
		D004E91A 1040
		8004E91A 1000
		'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_a.shtml
    	*/
    	add_D0_code(0x8004E91A, common_routine_return_compare_val);
		add_80_code(0x8004E91A, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Arc The Lad III
	(((strcmp("SCPS_101.06;1", bootfile)) == 0) || ((strcmp("SCPS_101.07;1", bootfile)) == 0)) { // 2 Japan versions and each have 2 discs but the same codes per revision
   		//debug_write("Detected Arc The Lad III - Japan");
		ver_check = (load_addr + 0x20); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0x8C))
		{
			//debug_write("REV 0");
			/*
			D0021DF6 1040
			80021DF6 1000
			code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_a.shtml
    		*/
	    	add_D0_code(0x80021DF6, common_routine_return_compare_val);
			add_80_code(0x80021DF6, common_routine_return_patch_val);
    		install_cheat_engine();
    	} else {
			//debug_write("REV 1");
 			/*
			D0022206 1040 my code via aprip gameshark code conversion
			80022206 1000
    		*/
	    	add_D0_code(0x80022206, common_routine_return_compare_val);
			add_80_code(0x80022206, common_routine_return_patch_val);
    		install_cheat_engine();		
    	}
    } else if

// Beatmania featuring Dreams Come True
   	((strcmp("SLPM_865.97;1", bootfile)) == 0) {
   		//debug_write("Beatmania featuring Dreams Come True");
		/*
		D012255C 001E
		8012255C 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
	    add_D0_code(0x8012255C, readtoc_compare_val);
		add_80_code(0x8012255C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Beatmania Best Hits
   	((strcmp("Slpm_865.96;1", bootfile)) == 0) { // 2 different versions, same code works on both rev 0 and rev 1
   		//debug_write("Detected Beatmania Best Hits");
		/*
		D0151448 001E
		80151448 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
	    add_D0_code(0x80151448, readtoc_compare_val);
		add_80_code(0x80151448, readtoc_patch_val);
    	install_cheat_engine();
	} else if

// Beat Mania: The Sound of Tokyo
	((strcmp("SLPM_867.69;1", bootfile)) == 0) { 
   		//debug_write("Detected Beat Mania - The Sound of Tokyo");
    	/*
		D0134C48 001E
		80134C48 0000
		my code to patch out readtoc
    	*/
	    add_D0_code(0x80134C48, readtoc_compare_val);
		add_80_code(0x80134C48, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Beat Mania 6thMix + Core Remix
	((strcmp("SLPM_870.12;1", bootfile)) == 0) { 
   		//debug_write("Detected Beat Mania 6th Mix + Core Remix");
		/*
		D0131B6C 001E
		80131B6C 001A
    	my code to patch out readtoc
    	*/
	    add_D0_code(0x80131B6C, readtoc_compare_val);
		add_80_code(0x80131B6C, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Biohazard 3: The Last Escape
   	((strcmp("SLPS_023.00;1", bootfile)) == 0) { // 2 different versions
   		//debug_write("Detected Biohazard 3 - Japan");
		ver_check = (load_addr + 0x1B0); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0xF4))
		{
			//debug_write("REV 0");
			/*
			D01840E2 1040
			801840E2 1000
			'skip check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
    		*/
	    	add_D0_code(0x801840E2, common_routine_return_compare_val);
			add_80_code(0x801840E2, common_routine_return_patch_val);
    		install_cheat_engine();
	    } else {
			//debug_write("REV 1");
			/*
			D018418E 1040
			8018418E 1000 
			my code via aprip gameshark code conversion
    		*/
	    	add_D0_code(0x8018418E, common_routine_return_compare_val);
			add_80_code(0x8018418E, common_routine_return_patch_val);
    		install_cheat_engine();
	    }
	} else if

   	((strcmp("SLPM_804.85;1", bootfile)) == 0) { // Demo
   		//debug_write("Detected Bio Hazard 3 Demo");
		/*
		D01800E2 1040
		801800E2 1000 
		my code via aprip gameshark code conversion
    	*/
	    add_D0_code(0x801800E2, common_routine_return_compare_val);
		add_80_code(0x801800E2, common_routine_return_patch_val);
    	install_cheat_engine();
	} else if

// Chase The Express
   	(((strcmp("SCPS_101.09;1", bootfile)) == 0) || ((strcmp("SCPS_101.10;1", bootfile)) == 0) || ((strcmp("PAPX_901.06;1", bootfile)) == 0) || ((strcmp("PCPX_961.89;1", bootfile)) == 0)) { // 2 discs and 2 demos all share the same code
   		//debug_write("Detected Chase The Express - Japan");
		/*
		D00EA6DE 1040
		800EA6DE 1000
		'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_c.shtml
    	*/
	    add_D0_code(0x800EA6DE, common_routine_return_compare_val);
		add_80_code(0x800EA6DE, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Crash Bash
  	((strcmp("SCUS_945.70;1", bootfile)) == 0) {
   		//debug_write("Detected Crash Bash - USA");
		/*
		D002D51E 1040
		8002D51E 1000
		code from GameHacking: https://gamehacking.org/game/88640, skips mod check
    	*/
	    add_D0_code(0x8002D51E, common_routine_return_compare_val);
		add_80_code(0x8002D51E, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if 

   	((strcmp("SCPS_101.40;1", bootfile)) == 0) {
   		//debug_write("Detected Crash Bash - Japan");
		/*
		D002D7EE 1040
		8002D7EE 1000
		code from GameHacking: https://gamehacking.org/game/93827, skips mod check
    	*/
	    add_D0_code(0x8002D7EE, common_routine_return_compare_val);
		add_80_code(0x8002D7EE, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Crash Bandicoot Racing
   	((strcmp("SCPS_101.18;1", bootfile)) == 0) {
   		//debug_write("Detected Crash Bandicoot Racing");
		/*
		D001259A 1040
		8001259A 1000
		'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml (yes it's on the wrong lettered page)
    	*/
	    add_D0_code(0x8001259A, common_routine_return_compare_val);
		add_80_code(0x8001259A, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("PCPX_961.83;1", bootfile)) == 0) {
   		//debug_write("Detected Crash Bandicoot Racing Demo");
		/*
    	D001255E 1040
    	8001255E 1040
		my code via aprip gameshark code conversion
    	*/
	    add_D0_code(0x8001255E, common_routine_return_compare_val);
		add_80_code(0x8001255E, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Cool Boarders 2001
   	((strcmp("SCUS_946.25;1", bootfile)) == 0) {
   		//debug_write("Detected Cool Boarders 2001 - USA Demo");
		/*
		D00B35B0 001E
		800B35B0 0000
		code generated via aprip
    	*/
	    add_D0_code(0x800B35B0, readtoc_compare_val);
		add_80_code(0x800B35B0, readtoc_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("SCUS_945.97;1", bootfile)) == 0) {
   		//debug_write("Detected Cool Boarders 2001 - USA");
		/*
		D00B35B8 001E
		800B35B8 0000
		my code via aprip gameshark code conversion
    	*/
	    add_D0_code(0x800B35B8, readtoc_compare_val);
		add_80_code(0x800B35B8, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution: Best Hits
   	((strcmp("SLPM_866.93;1", bootfile)) == 0) {
   		//debug_write("Detected Dance Dance Revolution: Best Hits");
		/*
		D0102FA0 001E
		80102FA0 0000
		my code generated via aprip
    	*/
	    add_D0_code(0x80102FA0, readtoc_compare_val);
		add_80_code(0x80102FA0, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution: Disney's Rave
   	((strcmp("SLPM_866.67;1", bootfile)) == 0) {
   		//debug_write("Detected Dance Dance Revolution: Disney's Rave");
		/*
		D0192248 001E
		80192248 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
	    add_D0_code(0x80192248, readtoc_compare_val);
		add_80_code(0x80192248, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution: Extra Mix
   	((strcmp("SLPM_868.31;1", bootfile)) == 0) {
   		//debug_write("Detected Dance Dance Revolution: Extra Mix");
		/*
		D00EB364 001E
		800EB364 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
	    add_D0_code(0x800EB364, readtoc_compare_val);
		add_80_code(0x800EB364, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution 2nd Remix / Dance Dance Revolution 2nd Remix Append Club Vol 1 / Dance Dance Revolution 2nd Remix Append Club Vol 2
   	((strcmp("SLPM_862.52;1", bootfile)) == 0) { // Dance Dance Revolution 2nd Remix Append Club Vol 1 and Dance Dance Revolution 2nd Remix Append Club Vol 2 discs are booted with a 'disc change' feature within Dance Dance Revolution 2nd Remix (which is a 'base' disc when booting the others, kind of like DLC).
   		//debug_write("Detected Dance Dance Revolution 2nd Remix");
		/*
		Dance Dance Revolution 2nd Remix:
		D00200A6 1040
		800200A6 1000
		*/
	    add_D0_code(0x800200A6, common_routine_return_compare_val);
		add_80_code(0x800200A6, common_routine_return_patch_val);
		/*
		D0020D64 FFF2
		80020D64 0001
		*/
    	add_D0_code(0x80020D64, 0xFFF2);
    	add_80_code(0x80020D64, 0x0001);
		/*
		D01C1BE4 FFF2
		801C1BE4 0001
		*/
    	add_D0_code(0x801C1BE4, 0xFFF2);
    	add_80_code(0x801C1BE4, 0x0001);

		/*
		D01C1C7A 0C07
		801C1C7A 3002
		*/
    	add_D0_code(0x801C1C7A, 0x0C07);
    	add_80_code(0x801C1C7A, 0x3002);
		/*
		D01C2936 1040
		801C2936 1000
		*/
    	add_D0_code(0x801C2936, common_routine_return_compare_val);
    	add_80_code(0x801C2936, common_routine_return_patch_val);
		/*
		Dance Dance Revolution 2nd Remix Append Club Vol 1
		D01C2A18 0C92
		801C2A18 0AA7
		*/
    	add_D0_code(0x801C2A18, 0x0C92);
    	add_80_code(0x801C2A18, 0x0AA7);
		/*
		D01C2EA2 1040
		801C2EA2 1000
		*/
    	add_D0_code(0x801C2EA2,common_routine_return_compare_val);
    	add_80_code(0x801C2EA2, common_routine_return_patch_val);

		/*
		Dance Dance Revolution 2nd Remix Append Club Vol 2
		D01C2F32 1040
		801C2F32 1000
		*/
    	add_D0_code(0x801C2F32, common_routine_return_compare_val);
    	add_80_code(0x801C2F32, common_routine_return_patch_val);
		/*
		D01C2AA8 0CB6
		801C2AA8 0ACB
		*/
    	add_D0_code(0x801C2AA8, 0x0CB6);
    	add_80_code(0x801C2AA8, 0x0ACB);
		// codes are from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml . There are EDC releated codes provided, but they don't seem to actually work (another EDC check still prevents the game from fully starting) and we are not providing EDC bypasses as they can be circumvented by burning CD-Rs as raw without regnerating the EDC.
    	install_cheat_engine();
    } else if

// Dancing Stage featuring Dreams Come True
   	((strcmp("SLPM_865.05;1", bootfile)) == 0) {
   		//debug_write("Detected Dancing Stage featuring Dreams Come True");
		/*
		D019245C 001E
		8019245C 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
    	add_D0_code(0x8019245C, readtoc_compare_val);
    	add_80_code(0x8019245C, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dancing Stage featuring True Kiss Destination
   	((strcmp("SLPM_864.11;1", bootfile)) == 0) {
   		//debug_write("Detected Dancing Stage featuring True Kiss Destination");
		/*
		D019117A 1040
		8019117A 1000
		code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml
    	*/
    	add_D0_code(0x8019117A, common_routine_return_compare_val);
    	add_80_code(0x8019117A, common_routine_return_patch_val);

    	install_cheat_engine();
    } else if

// Dino Crisis
	((strcmp("SLUS_009.22;1", bootfile) == 0)) { // NTSC-U has 2 versions, rev 0 and rev 1 (greatest hits) see https://tcrf.net/Dino_Crisis_(PlayStation)#Revisional_Differences
		//debug_write("Detected Dino Crisis - USA");
		ver_check = (load_addr + 0x61); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0xD0)) {
			//debug_write("Rev 0");
			/*
			D0149004 959C
			80149004 9E64
			Found independently by MottZilla, but actually turns out to be the same code by Epson found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml
			*/
  		  	add_D0_code(0x80149004, 0x959C);
  		  	add_80_code(0x80149004, 0x9E64);
			install_cheat_engine();
		} else {
			//debug_write("Rev 1");
			/*
			D0148004 8658
			80148004 8F20
			my code, the anti-piracy table just moved memory addresses between versions :)
			*/
 			add_D0_code(0x80148004, 0x8658);
 			add_80_code(0x80148004, 0x8F20);
			install_cheat_engine();
    	}
	} else if

   	((strcmp("SLPS_021.80;1", bootfile)) == 0) { // Same as USA Rev 0
   		//debug_write("Detected Dino Crisis - Japan");
		/*
		D0149004 959C
		80149004 9E64
		Found independently by MottZilla, but actually turns out to be the same code by Epson found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml . Yes this is the same code as the USA rev 0 one.
		*/
  		add_D0_code(0x80149004, 0x959C);
  		add_80_code(0x80149004, 0x9E64);
		install_cheat_engine();
    } else if

// Dino Crisis 2
   	((strcmp("SLPM_866.27;1", bootfile)) == 0) {
   		//debug_write("Detected Dino Crisis 2 - Japan");
	  	/*
		D00D7714 001E
		800D7714 0000
		my code via aprip to disable readtoc
		*/
		add_D0_code(0x800D7714, readtoc_compare_val);
		add_80_code(0x800D7714, readtoc_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SLPM_805.73;1", bootfile)) == 0) {
   		//debug_write("Detected Dino Crisis 2 - Japan Demo");
	  		/*
		D00CB104 001E
		800CB104 0000
		my codevia aprip to disable readtoc
		*/
		add_D0_code(0x800CB104, readtoc_compare_val);
		add_80_code(0x800CB104, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Disney's The Emperor's New Groove
   	((strcmp("SCUS_945.71;1", bootfile)) == 0) {
   		//debug_write("Detected Disney's The Emperor's New Groove - USA");
	  		/*
		D0063004 001E
		80063004 0000
		my code via aprip to disable readtoc
		*/
		add_D0_code(0x80063004, readtoc_compare_val);
		add_80_code(0x80063004, readtoc_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SCES_030.10;1", bootfile)) == 0) {
   		//debug_write("Detected Disney's The Emperor's New Groove - EUR");
	  		/*
		D006351C 001E
		8006351C 0000
		my code via aprip to disable readtoc
		*/
		add_D0_code(0x8006351C, readtoc_compare_val);
		add_80_code(0x8006351C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Exciting Bass 2
   	((strcmp("SLPM_862.95;1", bootfile)) == 0) {
   		//debug_write("Detected Exciting Bass 2");
		/*
		D00177BA 1040
		800177BA 1000	
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_e.shtml
  		*/
  		add_D0_code(0x800177BA, common_routine_return_compare_val);
  		add_80_code(0x800177BA, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Exciting Bass 3
   	((strcmp("SLPM_867.29;1", bootfile)) == 0) {
   		//debug_write("Detected Exciting Bass 3");
		/*
		D00B9170 001E
		800B9170 0000
		my code to patch out readtoc via aprip
  		*/
		add_D0_code(0x800B9170, readtoc_compare_val);
		add_80_code(0x800B9170, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner
   	((strcmp("SCPS_101.34;1", bootfile)) == 0) {
   		//debug_write("Detected Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner");
		/*
		D0195D9C 001E
		80195D9C 0000
		my code to patch out readtoc via aprip
  		*/
		add_D0_code(0x80195D9C, readtoc_compare_val);
		add_80_code(0x80195D9C, readtoc_patch_val);
  		install_cheat_engine();
    } else if

// Goo! Goo! Soundry
   	((strcmp("SLPM_862.50;1", bootfile)) == 0) {
   		//debug_write("Detected Goo Goo Soundry");
		/*
		D0055278 001E
		80055278 0000
		my code to patch out readtoc via aprip
  		*/
		add_D0_code(0x80055278, readtoc_compare_val);
		add_80_code(0x80055278, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Grind Session
   	((strcmp("SCUS_945.68;1", bootfile)) == 0) {
   		//debug_write("Detected Grind Session");
		/*
		D0014274 52A9
		80014274 50BE
		code 1 of 2 by 'TheVoice' found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
    	*/
  		add_D0_code(0x80014274, 0x52A9);
  		add_80_code(0x80014274, 0x50BE);
		/*
		D00146FE 1040
		800146FE 1000
		code 2 of 2 by 'TheVoice' found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
		*/
  		add_D0_code(0x800146FE, common_routine_return_compare_val);
  		add_80_code(0x800146FE, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Guitar Freaks
   	((strcmp("SLPM_862.65;1", bootfile)) == 0) {
   		//debug_write("Detected Guitar Freaks");
		/*
		D001654E 1040
		8001654E 1000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
    	*/
  		add_D0_code(0x8001654E, common_routine_return_compare_val);
  		add_80_code(0x8001654E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Harlem Beat: You're The One
   	((strcmp("SLPM_863.29;1", bootfile)) == 0) {
   		//debug_write("Detected Harlem Beat");
		/*
		D01A411E 1040
		801A411E 1000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
    	*/
  		add_D0_code(0x801A411E, common_routine_return_compare_val);
  		add_80_code(0x801A411E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Hyper Value 2800: Mahjong
   	((strcmp("SLPM_862.92;1", bootfile)) == 0) {
   		//debug_write("Detected Hyper Value 2800 Mahjong");
		/*
		D00A0186 1040
		800A0186 1000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
    	*/
  		add_D0_code(0x800A0186, common_routine_return_compare_val);
  		add_80_code(0x800A0186, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// i-mode mo Issho: Doko Demo Issho Tsuika Disc
    ((strcmp("SCPS_101.41;1", bootfile)) == 0) {
        //debug_write("Detected i-mode mo Issho: Doko Demo Issho Tsuika Disc");
        /*
        D01698B4 001E
        801698B4 0000
        code generated via aprip by M4x1mumReZ: https://gbatemp.net/members/m4x1mumrez.610331/
        */
        add_D0_code(0x801698B4, readtoc_compare_val);
        add_80_code(0x801698B4, readtoc_patch_val);
        install_cheat_engine();
    } else if

// Jikkyou Powerful Pro Yakyuu '99 Ketteiban
   	((strcmp("SLPM_864.33;1", bootfile)) == 0) {
   		//debug_write("Detected Jikkyou Powerful Pro Yakyuu '99 Ketteiban");
	  		/*
		D016B4D8 001E
		8016B4D8 0000
		my code to patch out readtoc via aprip
		*/
        add_D0_code(0x8016B4D8, readtoc_compare_val);
        add_80_code(0x8016B4D8, readtoc_patch_val);
		install_cheat_engine();
	} else if

// Jikkyou Powerful Pro Yakyuu '99: Kaimakuban
   	((strcmp("SLPM_862.53;1", bootfile)) == 0) {
   		//debug_write("Detected Jikkyou Powerful Pro Yakyuu '99 Kaimakuban");
		/*
		D016B268 001E
		8016B268 0000
		my code to patch out readtoc via aprip
		*/
        add_D0_code(0x8016B268, readtoc_compare_val);
        add_80_code(0x8016B268, readtoc_patch_val);
		install_cheat_engine();
	} else if

// JoJo's Bizarre Adventure
   	((strcmp("SLPS_022.36;1", bootfile)) == 0) {
   		//debug_write("Detected JoJo's Bizarre Adventure");
		/*
		D0035C48 D91E
		80035C48 D733
		code 1 of 2 found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_j.shtml
    	*/
  		add_D0_code(0x80035C48, 0xD91E);
  		add_80_code(0x80035C48, 0xD733);
  		/*
		D00360D2 1040
		800360D2 1000
		code 2 of 2 found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_j.shtml
    	*/
  		add_D0_code(0x800360D2, common_routine_return_compare_val);
  		add_80_code(0x800360D2, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Koko Hore! Pukka
	((strcmp("SCPS_101.33;1", bootfile)) == 0) {
		//debug_write("Detected Kore Hore! Pukka");
		/*
		D00A341C 001E
		800A341C 0000
		code generated via aprip by https://gbatemp.net/members/m4x1mumrez.610331/
    	*/
  		add_D0_code(0x800A341C, readtoc_compare_val);
  		add_80_code(0x800A341C, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Koneko mo Issho
   	((strcmp("SCPS_101.27;1", bootfile)) == 0) {
   		//debug_write("Detected Koneko mo Issho");
		/*
		D016957C 001E
		8016957C 0000
		my code generated via aprip
		*/
  		add_D0_code(0x8016957C, readtoc_compare_val);
  		add_80_code(0x8016957C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Legend Of Dragoon
   	(((strcmp("SCPS_101.19;1", bootfile)) == 0) || ((strcmp("scps_101.20;1", bootfile)) == 0) || ((strcmp("scps_101.21;1", bootfile)) == 0) || ((strcmp("scps_101.22;1", bootfile)) == 0)) { // 4 discs
   		//debug_write("Detected Legend Of Dragoon - Japan");
		/*
		D01BF172 1040
		801BF172 1000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
    	*/
  		add_D0_code(0x801BF172, common_routine_return_compare_val);
  		add_80_code(0x801BF172, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(((strcmp("SCUS_944.91;1", bootfile)) == 0) || ((strcmp("SCUS_945.84;1", bootfile)) == 0) || ((strcmp("SCUS_945.85;1", bootfile)) == 0) || ((strcmp("SCUS_945.86;1", bootfile)) == 0)) { // 4 discs
   		//debug_write("Detected Legend Of Dragoon - USA");
		/*
		801BF6F6 1040
		801BF6F6 1000 
		my code via aprip's gameshark conversion
   		*/
  		add_D0_code(0x801BF6F6, common_routine_return_compare_val);
  		add_80_code(0x801BF6F6, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(((strcmp("SCES_030.43;1", bootfile)) == 0) || ((strcmp("SCES_130.43;1", bootfile)) == 0) || ((strcmp("SCES_230.43;1", bootfile)) == 0) || ((strcmp("SCES_330.43;1", bootfile)) == 0)) { // 4 discs
   		//debug_write("Detected Legend Of Dragoon - EUR");
		/*
		D01C0892 1040
		801C0892 1000
		my code via aprip's gameshark conversion
		*/
  		add_D0_code(0x801C0892, common_routine_return_compare_val);
  		add_80_code(0x801C0892, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(((strcmp("SCES_030.44;1", bootfile)) == 0) || ((strcmp("SCES_130.44;1", bootfile)) == 0) || ((strcmp("SCES_230.44;1", bootfile)) == 0) || ((strcmp("SCES_330.44;1", bootfile)) == 0)) { // 4 discs
   		//debug_write("Detected Legend Of Dragoon - FRA");
		/*
		D01C0872 1040
		801C0872 1040
		my code via aprip's gameshark conversion
		*/
  		add_D0_code(0x801C0872, common_routine_return_compare_val);
  		add_80_code(0x801C0872, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(((strcmp("SCES_030.45;1", bootfile)) == 0) || ((strcmp("SCES_130.45;1", bootfile)) == 0) || ((strcmp("SCES_230.45;1", bootfile)) == 0) || ((strcmp("SCES_330.45;1", bootfile)) == 0)) { // 4 discs
   		//debug_write("Detected Legend Of Dragoon - GER");
		/*
		D01C082E 1040
		801C082E 1000
		my code via aprip's gameshark conversion
  		*/
  		add_D0_code(0x801C082E, common_routine_return_compare_val);
  		add_80_code(0x801C082E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(((strcmp("SCES_030.46;1", bootfile)) == 0) || ((strcmp("SCES_130.46;1", bootfile)) == 0) || ((strcmp("SCES_230.46;1", bootfile)) == 0) || ((strcmp("SCES_330.46;1", bootfile)) == 0)) { // 4 discs
   		//debug_write("Detected Legend Of Dragoon - ITA");
		/*
		D01C0826 1040
		801C0826 1000
		my code via aprip's gameshark conversion
		*/
  		add_D0_code(0x801C0826, common_routine_return_compare_val);
  		add_80_code(0x801C0826, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Legend Of Mana
   	((strcmp("SLPS_021.70;1", bootfile)) == 0) { // Japan
   		//debug_write("Detected Legend Of Mana");
		/*
		D0050ECA 1040 
		80050ECA 1000
		code 1 of 2 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
		*/
  		add_D0_code(0x80050ECA, common_routine_return_compare_val);
  		add_80_code(0x80050ECA, common_routine_return_patch_val);
    	/*
		D00360D2 1040
		800360D2 1000
		code 2 of 2 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
		*/
  		add_D0_code(0x800360D2, common_routine_return_compare_val);
  		add_80_code(0x800360D2, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Love Hina: Ai wa Kotoba no Naka ni / Love Hina 2: Kotoba wa Konayuki no You ni
   	(((strcmp("SLPM_866.52;1", bootfile)) == 0) || ((strcmp("SLPM_866.77;1", bootfile)) == 0)) { // Same code works for both games
   		//debug_write("Detected Love Hina 1 or 2");
		/*
		 D01011C0 001E
		 801011C0 0000
		code generated via APrip by https://gbatemp.net/members/m4x1mumrez.610331/
    	*/
 		add_D0_code(0x801011C0, readtoc_compare_val);
 		add_80_code(0x801011C0, readtoc_patch_val);
 		install_cheat_engine();
    } else if

// Marvel vs. Capcom: Clash of Super Heroes
   	(((strcmp("SLPS_023.68;1", bootfile)) == 0) || ((strcmp("SLPM_805.08;1", bootfile)) == 0)) { // Japan/Japan Demo share same code
   		//debug_write("Detected Marvel vs. Capcom Clash of Super Heroes");
		/*
		D00F0C3A 1040
		800F0C3A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
    	*/
  		add_D0_code(0x800F0C3A, common_routine_return_compare_val);
  		add_80_code(0x800F0C3A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Medievil II
   	((strcmp("SCUS_945.64;1", bootfile)) == 0) {
   		//debug_write("Detected MediEvil II USA");
		/*
		D00E1A58 001E
		800E1A58 0000
		my code generated via aprip
		*/
  		add_D0_code(0x800E1A58, readtoc_compare_val);
  		add_80_code(0x800E1A58, readtoc_patch_val);
		install_cheat_engine();
    } else if


// My Garden
   	((strcmp("SLPS_022.13;1", bootfile)) == 0) {
   		//debug_write("Detected My Garden");
		/*
		D009E212 1040
		8009E212 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
    	*/
  		add_D0_code(0x8009E212, common_routine_return_compare_val);
  		add_80_code(0x8009E212, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Oha-Studio Dance Dance Revolution
   	((strcmp("SLPM_866.03;1", bootfile)) == 0) {
   		//debug_write("Detected Oha-Studio Dance Dance Revolution");
		/*
		D00FAE58 001E
		800FAE58 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
  		add_D0_code(0x800FAE58, readtoc_compare_val);
  		add_80_code(0x800FAE58, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Ore no Ryouri
   	((strcmp("SCPS_100.99;1", bootfile)) == 0) {
   		//debug_write("Detected Ore no Ryouri");
		/*
		D0031C1A 1040
		80031C1A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
    	*/
  		add_D0_code(0x80031C1A, common_routine_return_compare_val);
  		add_80_code(0x80031C1A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Pocket Jiman
   	((strcmp("SCPS_101.04;1", bootfile)) == 0) { // 3 discs
   		//debug_write("Detected Pocket Jiman");
		/*
		 D0126BDC 001E
		 80126BDC 0000
		 code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
		*/
  		add_D0_code(0x80126BDC, readtoc_compare_val);
  		add_80_code(0x80126BDC, readtoc_patch_val);
		install_cheat_engine();
    } else if

// PoPoLoCrois Monogatari II
   	(((strcmp("SCPS_101.12;1", bootfile)) == 0) || ((strcmp("SCPS_101.13;1", bootfile)) == 0) || ((strcmp("SCPS_101.14;1", bootfile)) == 0)) { // 3 discs
   		//debug_write("Detected PoPoLoCrois Monogatari II");
		/*
		 D00B2612 1040
		 800B2612 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml
		*/
  		add_D0_code(0x800B2612, common_routine_return_compare_val);
  		add_80_code(0x800B2612, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Pop'n Music: Animation Melody
   	((strcmp("SLPM_865.92;1", bootfile)) == 0) {
   		//debug_write("Pop'n Music: Animation Melody");
		/*
		D009E7E8 001E
		8009E7E8 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
  		add_D0_code(0x8009E7E8, readtoc_compare_val);
  		add_80_code(0x8009E7E8, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Pop'n Music: Disney Tunes
   	((strcmp("SLPM_866.70;1", bootfile)) == 0) {
   		//debug_write("Pop'n Music: Disney Tunes");
		/*
		D008A45C 001E
		8008A45C 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
  		add_D0_code(0x8008A45C, readtoc_compare_val);
  		add_80_code(0x8008A45C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Pop'n Music 2
   	((strcmp("SLPM_862.94;1", bootfile)) == 0) {
   		//debug_write("Detected Pop 'N Music 2");
		/*
		D0015342 1040
		80015342 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml
    	*/
  		add_D0_code(0x80015342, common_routine_return_compare_val);
  		add_80_code(0x80015342, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Pop'n Music 5
   	((strcmp("SLPM_869.37;1", bootfile)) == 0) {
   		//debug_write("Detected Pop'n Music 5");
	   		/*
		D0048F34 001E
		80048F34 0000
		my code via aprip to patch out readtoc
		*/
  		add_D0_code(0x80048F34, readtoc_compare_val);
  		add_80_code(0x80048F34, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Pop'n Music 6
   	((strcmp("SLPM_870.89;1", bootfile)) == 0) {
   		//debug_write("Detected Pop'n Music 6");
	 		/*
		D004A24C 001E
		8004A24C 0000
		my code via aprip to patch out readtoc
		*/
  		add_D0_code(0x8004A24C, readtoc_compare_val);
  		add_80_code(0x8004A24C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Resident Evil Survivor
   	((strcmp("SLPS_025.53;1", bootfile)) == 0) {
   		//debug_write("Detected Resident Evil Survivor - Japan");
		/*
		D0017962 1040
		80017962 1000
		'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
    	*/
  		add_D0_code(0x80017962, common_routine_return_compare_val);
  		add_80_code(0x80017962, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("SLUS_010.87;1", bootfile)) == 0) {
   		//debug_write("Detected Resident Evil Survivor - USA");
		/*
		D001714E 1040
		8001714E 1000
		converted code via aprip
    	*/
  		add_D0_code(0x8001714E, common_routine_return_compare_val);
  		add_80_code(0x8001714E, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

   	(((strcmp("SLES_027.32;1", bootfile)) == 0) || ((strcmp("SLES_027.44;1", bootfile)) == 0)) { // Same code works on both Europe and France versions
   		//debug_write("Detected Resident Evil Survivor - EUR/FRA");
		/*
		D001713E 1040
		8001713E 1000
		converted code via aprip
    	*/
  		add_D0_code(0x8001713E, common_routine_return_compare_val);
  		add_80_code(0x8001713E, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Robbit mon Dieu
   	((strcmp("SCPS_101.03;1", bootfile)) == 0) {
   		//debug_write("Detected Robbit Mon Dieu");
		/*
		D001C646 1040
		8001C646 1000
		'skip mod check' code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
  		add_D0_code(0x8001C646, common_routine_return_compare_val);
  		add_80_code(0x8001C646, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Rockman
   	((strcmp("SLPS_022.20;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman 1");
		/*
		D006C92A 1040
		8006C92A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
  		add_D0_code(0x8006C92A, common_routine_return_compare_val);
  		add_80_code(0x8006C92A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Rockman 2: Dr. Wily no Nazo
   	((strcmp("SLPS_022.55;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman 2");
		/*
		D006CA82 1040
		8006CA82 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
  		add_D0_code(0x8006CA82, common_routine_return_compare_val);
  		add_80_code(0x8006CA82, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

// Rockman 3: Dr. Wily no Saigo!?
   	((strcmp("SLPS_022.62;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman 3");
		/*
		D006CA1A 1040
		8006CA1A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
  		add_D0_code(0x8006CA1A, common_routine_return_compare_val);
  		add_80_code(0x8006CA1A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Rockman 4: Aratanaru Yabou!!
   	((strcmp("SLPS_023.24;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman 4");
	 	/*
 		D007009C 001E
		8007009C 0000
 		my code via aprip to patch out readtoc
		*/
  		add_D0_code(0x8007009C, readtoc_compare_val);
  		add_80_code(0x8007009C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Rockman 5: Blues no Wana!?
   	((strcmp("SLPS_023.38;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman 5");
		/*
		D006FD84 001E
		8006FD84 0000
		my code via aprip
		*/
  		add_D0_code(0x8006FD84, readtoc_compare_val);
  		add_80_code(0x8006FD84, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Rockman X5
   	((strcmp("SLPM_866.66;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman X5");
		/*
		D0070ED0 001E
		80070ED0 0000
		my code via aprip
		*/
  		add_D0_code(0x80070ED0, readtoc_compare_val);
  		add_80_code(0x80070ED0, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Rockman X6
   	((strcmp("SLPM_869.59;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman X6");
		/*
		D006EC40 001E
		8006EC40 0000
		my code via aprip
		*/
  		add_D0_code(0x8006EC40, readtoc_compare_val);
  		add_80_code(0x8006EC40, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Rockman 6
   	((strcmp("SLPS_023.79;1", bootfile)) == 0) {
   		//debug_write("Detected Rockman 6");
		/*
		D006DA7A 1040
		8006DA7A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
  		add_D0_code(0x8006DA7A, common_routine_return_compare_val);
  		add_80_code(0x8006DA7A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Street Fighter EX2 Plus
   	((strcmp("SLPS_025.08;1", bootfile)) == 0) {
   		//debug_write("Detected Street Fighter EX2 Plus");
		/*
		D01BD48A 1040
		801BD48A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_s.shtml
		*/
  		add_D0_code(0x801BD48A, common_routine_return_compare_val);
  		add_80_code(0x801BD48A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SLPM_805.17;1", bootfile)) == 0) {
   		//debug_write("Detected Street Fighter EX2 Plus Demo");
		/*
		D01BD13E 1040
		801BD13E 1000
		my code via aprip gameshark code conversion
		*/
  		add_D0_code(0x801BD48A, common_routine_return_compare_val);
  		add_80_code(0x801BD13E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Strider 2
   	((strcmp("SLUS_011.63;1", bootfile)) == 0) {
   		//debug_write("Detected Strider 2 - USA");
		/*
		D01F6570 001E
		801F6570 0000
		my code via aprip
		*/
  		add_D0_code(0x801F6570, readtoc_compare_val);
  		add_80_code(0x801F6570, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Tomba! 2: The Evil Swine Return
   	((strcmp("SCUS_944.54;1", bootfile)) == 0) {
   		//debug_write("Detected TOMBA! 2 - USA");
		/*
		D002542C 001E
		8002542C 0000
		my code via aprip
		*/
  		add_D0_code(0x8002542C, readtoc_compare_val);
  		add_80_code(0x8002542C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Vandal Harts II
   	((strcmp("SLUS_009.40;1", bootfile)) == 0) {
   		//debug_write("Detected Vandal Harts II - USA");
	 		/*
		D00865FC 001E
		800865FC 0000
		my code via aprip to patch out readtoc
		*/
  		add_D0_code(0x800865FC, readtoc_compare_val);
  		add_80_code(0x800865FC, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Wild Arms 2
   	(((strcmp("SCUS_944.84;1", bootfile)) == 0) || ((strcmp("SCUS_944.98;1", bootfile)) == 0)) { // 2 discs
   		//debug_write("Detected Wild Arms 2 - USA");
	   		/*
   		D003A4E8 001E
   		8003A4E8 0000
 		my code via aprip to patch out readtoc
    	*/
  		add_D0_code(0x8003A4E8, readtoc_compare_val);
  		add_80_code(0x8003A4E8, readtoc_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SCUS_945.92;1", bootfile)) == 0) {
   		//debug_write("Detected Wild Arms 2 - USA Demo");
		/*
   		D003A5D4 001E
   		8003A5D4 0000
		my code via aprip gameshark code conversion on my own code (code-ception)
    	*/
  		add_D0_code(0x8003A5D4, readtoc_compare_val);
  		add_80_code(0x8003A5D4, readtoc_patch_val);
		install_cheat_engine();
    } else if

// World Soccer Jikkyou Winning Eleven 4
   	((strcmp("SLPM_862.91;1", bootfile)) == 0) { // 2 revisions, same code works on rev 0 and rev 1
   		//debug_write("Detected Winning Eleven 4");
		/*
   		D01030CA 1040
		801030CA 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_w.shtml
    	*/
  		add_D0_code(0x801030CA, common_routine_return_compare_val);
  		add_80_code(0x801030CA, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// XI[SAI] Jumbo
   	((strcmp("SCPS_101.23;1", bootfile)) == 0) {
   		//debug_write("Detected XI[Sai] Jumbo");
	   	/*
   		D010178A 1040
		8010178A 1000
		code 1 of 3 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_x.shtml
    	*/
  		add_D0_code(0x8010178A, common_routine_return_compare_val);
  		add_80_code(0x8010178A, common_routine_return_patch_val);
 		/*
		D00A370A 1040
		800A370A 1000
		code 2 of 3 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_x.shtml
    	*/
  		add_D0_code(0x800A370A, common_routine_return_compare_val);
  		add_80_code(0x800A370A, common_routine_return_patch_val);
 		/*
		D0113C1A 1040
		80113C1A 1000
		code 3 of 3 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_x.shtml
    	*/
  		add_D0_code(0x80113C1A, common_routine_return_compare_val);
  		add_80_code(0x80113C1A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Yu-Gi-Oh! Forbidden Memories
   	(((strcmp("SLPM_863.96;1", bootfile)) == 0) || ((strcmp("SLPM_863.98;1", bootfile)) == 0) || ((strcmp("SLUS_014.11;1", bootfile)) == 0) || ((strcmp("SLES_039.47;1", bootfile)) == 0) || ((strcmp("SLES_039.48;1", bootfile)) == 0) || ((strcmp("SLES_039.49;1", bootfile)) == 0) || ((strcmp("SLES_039.50;1", bootfile)) == 0) || ((strcmp("SLES_039.51;1", bootfile)) == 0)) { //same code skips mod check on ALL VERSIONS EVER!
   		//debug_write("Detected Yu-Gi-Oh! Forbidden Memories");
		/*
		D016818A 1040
		8016818A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_y.shtml
    	*/
  		add_D0_code(0x8016818A, common_routine_return_compare_val);
  		add_80_code(0x8016818A, common_routine_return_patch_val);
		install_cheat_engine();
    }
}