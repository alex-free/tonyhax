
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
const unsigned char cheat_engine_v1_0_3[] = {
0xe0, 0xff, 0xbd, 0x27, 0x00, 0x00, 0xa4, 0xaf,
  0x04, 0x00, 0xa5, 0xaf, 0x08, 0x00, 0xa6, 0xaf, 0x0c, 0x00, 0xa7, 0xaf,
  0x00, 0x00, 0x04, 0x3c, 0x00, 0xd0, 0x84, 0x34, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x86, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x00, 0xc0, 0x10,
  0x30, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0xc7, 0x10,
  0x80, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x16, 0x00, 0xc7, 0x10,
  0xe0, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x00, 0xc7, 0x10,
  0xd0, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x2e, 0x00, 0xc7, 0x10,
  0xe1, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x22, 0x00, 0xc7, 0x10,
  0xd1, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x31, 0x00, 0xc7, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x07, 0x34, 0x1c, 0x00, 0x86, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x35, 0x00, 0xc7, 0x10, 0x00, 0x00, 0x00, 0x00,
  0x80, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x37, 0x00, 0xc7, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa4, 0x3a, 0x00, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa0, 0x34, 0x00, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90, 0x00, 0x00, 0x00, 0x00,
  0x2a, 0x00, 0xc5, 0x14, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90, 0x00, 0x00, 0x00, 0x00,
  0x21, 0x00, 0xc5, 0x10, 0x00, 0x00, 0x00, 0x00, 0xda, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00,
  0x18, 0x00, 0xc5, 0x14, 0x00, 0x00, 0x00, 0x00, 0xd1, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00,
  0x0f, 0x00, 0xc5, 0x10, 0x00, 0x00, 0x00, 0x00, 0xc8, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x85, 0x90, 0x10, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa0, 0x07, 0x00, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x85, 0x94, 0x10, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa4, 0x01, 0x00, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0xa3, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x84, 0x24, 0xa0, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, 0x8f, 0x04, 0x00, 0xa5, 0x8f,
  0x08, 0x00, 0xa6, 0x8f, 0x0c, 0x00, 0xa7, 0x8f, 0x20, 0x00, 0xbd, 0x27,
  0x01, 0x00, 0x1a, 0x3c, 0xfc, 0xcf, 0x5a, 0x8f, 0x00, 0x00, 0x00, 0x00,
  0x08, 0x00, 0x40, 0x03, 0x00, 0x00, 0x00, 0x00
};

	//debug_write("Installing MottZilla AP Engine");
	memcpy((void*)0xC000, (void*)cheat_engine_v1_0_3, sizeof(cheat_engine_v1_0_3)); // Copy MottZilla's cheat engine assembly binary to 0xC000
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
   //for(volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause
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
		bootfile = &bootfile[bootfile_len-13]; // XXXX_XXX.XX;1 , we are only changing the locally declared bootfile here, not in secondary.c.
		//debug_write("Stripped Bootfile: %s", bootfile);
	} else if(bootfile_len < 13) {
		return; 
		// Speed optimization. All anti-piracy games currently have a bootfile name that is at least 13 uchars long when stripped. So if the bootfile happens to have something like 'MAIN.EXE;1' (which is 10 in length), we already know not to bother even checking for an anti-piracy bootfile match to apply codes for (which takes time in itself to do as well).
	}

// Animetic Story Game 1: Card Captor Sakura
   	if(
	((strcmp("SLPS_018.30;1", bootfile)) == 0) // Japan Disc 1
	|| ((strcmp("SLPS_018.31;1", bootfile)) == 0) // Japan Disc 2
	) { // 2 disc game
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
	((strcmp("SCPS_101.15;1", bootfile)) == 0) { // Japan
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
	(
	((strcmp("SCPS_101.06;1", bootfile)) == 0) // Japan Rev 0/Rev 1 Disc 1
	|| ((strcmp("SCPS_101.07;1", bootfile)) == 0) // Japan Rev 0/Rev 1 Disc 2
	) {
		ver_check = (load_addr + 0x20); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0x8C)) // Rev 0
		{
			/*
			D0021DF6 1040
			80021DF6 1000
			code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_a.shtml
    		*/
	    	add_D0_code(0x80021DF6, common_routine_return_compare_val);
			add_80_code(0x80021DF6, common_routine_return_patch_val);
    		install_cheat_engine();
    	} else { // Rev 1
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
   	((strcmp("SLPM_865.97;1", bootfile)) == 0) { // Japan
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
   	((strcmp("Slpm_865.96;1", bootfile)) == 0) { // Japan Rev 0/Rev 1
		// not a typo, weird asf filename
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
	((strcmp("SLPM_867.69;1", bootfile)) == 0) { // Japan
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
	((strcmp("SLPM_870.12;1", bootfile)) == 0) { // Japan
		/*
		D0131B6C 001E
		80131B6C 001A
    	my code to patch out readtoc
    	*/
	    add_D0_code(0x80131B6C, readtoc_compare_val);
		add_80_code(0x80131B6C, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Boku no Natsuyasumi: Summer Holiday 20th Century
	((strcmp("SCPS_100.88;1", bootfile)) == 0) { // Japan
		/*
		D0068B30 001E
		80068B30 0000
    	my code to patch out readtoc
    	*/
	    add_D0_code(0x80068B30, readtoc_compare_val);
		add_80_code(0x80068B30, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Breath of Fire IV
   	((strcmp("SLPS_027.28;1", bootfile)) == 0) { // Japan / USA E3 2000 Beta Build
		/*
		D01D0698 001E
		801D0698 0000
		my code via aprip gameshark code conversion
    	*/
	    add_D0_code(0x801D0698, readtoc_compare_val);
		add_80_code(0x801D0698, readtoc_patch_val);
    	install_cheat_engine();
	} else if

// Capcom vs. SNK: Millennium Fight 2000 Pro
   	((strcmp("SLPM_870.53;1", bootfile)) == 0) { // Japan
		/*
		D0051B60 001E
		80051B60 0000
		my code via aprip gameshark code conversion
    	*/
	    add_D0_code(0x80051B60, readtoc_compare_val);
		add_80_code(0x80051B60, readtoc_patch_val);
    	install_cheat_engine();
	} else if

// Chase The Express
   	(
	((strcmp("SCPS_101.09;1", bootfile)) == 0) // Japan Disc 1
	|| ((strcmp("SCPS_101.10;1", bootfile)) == 0) // Japan Disc 2
	|| ((strcmp("PAPX_901.06;1", bootfile)) == 0) // Japan Demo 1
	|| ((strcmp("PCPX_961.89;1", bootfile)) == 0) // Japan Demo 2
	) {
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
  	((strcmp("SCUS_945.70;1", bootfile)) == 0) { // USA
		/*
		D002D51E 1040
		8002D51E 1000
		code from GameHacking: https://gamehacking.org/game/88640, skips mod check
    	*/
	    add_D0_code(0x8002D51E, common_routine_return_compare_val);
		add_80_code(0x8002D51E, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if 

   	((strcmp("SCPS_101.40;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SCPS_101.18;1", bootfile)) == 0) { // Japan
		/*
		D001259A 1040
		8001259A 1000
		'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml (yes it's on the wrong lettered page)
    	*/
	    add_D0_code(0x8001259A, common_routine_return_compare_val);
		add_80_code(0x8001259A, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("PCPX_961.83;1", bootfile)) == 0) { // Japan Demo
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
   	((strcmp("SCUS_946.25;1", bootfile)) == 0) { // USA Demo
		/*
		D00B35B0 001E
		800B35B0 0000
		code generated via aprip
    	*/
	    add_D0_code(0x800B35B0, readtoc_compare_val);
		add_80_code(0x800B35B0, readtoc_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("SCUS_945.97;1", bootfile)) == 0) { // USA
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
   	((strcmp("SLPM_866.93;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_866.67;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_868.31;1", bootfile)) == 0) { // Japan
		/*
		D00EB364 001E
		800EB364 0000
		code generated via aprip by https://www.psx-place.com/members/trappedinlimbo.156719/
    	*/
	    add_D0_code(0x800EB364, readtoc_compare_val);
		add_80_code(0x800EB364, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution 2nd Remix
   	((strcmp("SLPM_862.52;1", bootfile)) == 0) { // Dance Dance Revolution 2nd Remix Append Club Vol 1 and Dance Dance Revolution 2nd Remix Append Club Vol 2 discs are booted with a 'disc change' feature within Dance Dance Revolution 2nd Remix (which is a 'base' disc when booting the others, kind of like DLC).
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
		// codes are from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml .
    	install_cheat_engine();
    } else if

// Dance Dance Revolution: 3rd Mix
   	((strcmp("SLPM_865.03;1", bootfile)) == 0) { // Japan
		/*
		D00C4260 001E 
		800C4260 0000
		my code generated via aprip
    	*/
    	add_D0_code(0x800C4260, readtoc_compare_val);
    	add_80_code(0x800C4260, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution: 4th Mix
   	((strcmp("SLPM_867.52;1", bootfile)) == 0) { // Japan
		/*
		D00EB3E4 001E
		800EB3E4 0000
		my code generated via aprip
    	*/
    	add_D0_code(0x800EB3E4, readtoc_compare_val);
    	add_80_code(0x800EB3E4, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dance Dance Revolution: 5th Mix
   	((strcmp("SLPM_868.97;1", bootfile)) == 0) { // Japan
		/*
		D0177140 001E 
		80177140 0000
		my code generated via aprip
    	*/
    	add_D0_code(0x80177140, readtoc_compare_val);
    	add_80_code(0x80177140, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Dancing Stage featuring Dreams Come True
   	((strcmp("SLPM_865.05;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_864.11;1", bootfile)) == 0) { // Japan
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
	((strcmp("SLUS_009.22;1", bootfile)) == 0) { // USA Rev 0/USA Rev 1
		ver_check = (load_addr + 0x61); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if(ver_check_val == 0xD0) { // Rev 0
			/*
			D0149004 959C
			80149004 9E64
			Found independently by MottZilla, but actually turns out to be the same code by Epson found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml
			*/
  		  	add_D0_code(0x80149004, 0x959C);
  		  	add_80_code(0x80149004, 0x9E64);
			install_cheat_engine();
		} else { // Rev 1
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

   	((strcmp("SLPS_021.80;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_866.27;1", bootfile)) == 0) { // Japan
	  	/*
		D00D7714 001E
		800D7714 0000
		my code via aprip to disable readtoc
		*/
		add_D0_code(0x800D7714, readtoc_compare_val);
		add_80_code(0x800D7714, readtoc_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SLPM_805.73;1", bootfile)) == 0) { // Japan Demo
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
   	((strcmp("SCUS_945.71;1", bootfile)) == 0) { // USA
	  	/*
		D0063004 001E
		80063004 0000
		my code via aprip to disable readtoc
		*/
		add_D0_code(0x80063004, readtoc_compare_val);
		add_80_code(0x80063004, readtoc_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SCES_030.10;1", bootfile)) == 0) { // Europe
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
   	((strcmp("SLPM_862.95;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_867.29;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SCPS_101.34;1", bootfile)) == 0) { // Japan
		/*
		D0195D9C 001E
		80195D9C 0000
		my code to patch out readtoc via aprip
  		*/
		add_D0_code(0x80195D9C, readtoc_compare_val);
		add_80_code(0x80195D9C, readtoc_patch_val);
  		install_cheat_engine();
    } else if

// Glint Glitters
   	((strcmp("SLPM_862.00;1", bootfile)) == 0) { // Japan
		/*
		D01B3188 001E
		801B3188 0000
		my code to patch out readtoc via aprip
  		*/
		add_D0_code(0x801B3188, readtoc_compare_val);
		add_80_code(0x801B3188, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Goo! Goo! Soundry
   	((strcmp("SLPM_862.50;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SCUS_945.68;1", bootfile)) == 0) { // USA
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
   	((strcmp("SLPM_862.65;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_863.29;1", bootfile)) == 0) { // Japan
		/*
		D01A411E 1040
		801A411E 1000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
    	*/
  		add_D0_code(0x801A411E, common_routine_return_compare_val);
  		add_80_code(0x801A411E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Hyper Value 2800: Hanafuda
   	((strcmp("SLPM_864.17;1", bootfile)) == 0) { // Japan
		/*
		D00A1188 001E
		800A1188 0000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
    	*/
  		add_D0_code(0x800A1188, readtoc_compare_val);
  		add_80_code(0x800A1188, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Hyper Value 2800: Mahjong
   	((strcmp("SLPM_862.92;1", bootfile)) == 0) { // Japan
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
    ((strcmp("SCPS_101.41;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_864.33;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_862.53;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPS_022.36;1", bootfile)) == 0) { // Japan
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
	((strcmp("SCPS_101.33;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SCPS_101.27;1", bootfile)) == 0) { // Japan
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
   	(
	((strcmp("SCPS_101.19;1", bootfile)) == 0) // Japan Disc 1
	|| ((strcmp("scps_101.20;1", bootfile)) == 0) // Japan Disc 2 (weird ass filename not a typo)
	|| ((strcmp("scps_101.21;1", bootfile)) == 0) // Japan Disc 3 (weird ass filename not a typo)
	|| ((strcmp("scps_101.22;1", bootfile)) == 0) // Japan Disc 4 (weird ass filename not a typo)
	) {
		/*
		D01BF172 1040
		801BF172 1000
		code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_l.shtml
    	*/
  		add_D0_code(0x801BF172, common_routine_return_compare_val);
  		add_80_code(0x801BF172, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(
	((strcmp("SCUS_944.91;1", bootfile)) == 0) // USA Disc 1
	|| ((strcmp("SCUS_945.84;1", bootfile)) == 0) // USA Disc 2
	|| ((strcmp("SCUS_945.85;1", bootfile)) == 0) // USA Disc 3
	|| ((strcmp("SCUS_945.86;1", bootfile)) == 0) // USA Disc 4
	) {
		/*
		801BF6F6 1040
		801BF6F6 1000 
		my code via aprip's gameshark conversion
   		*/
  		add_D0_code(0x801BF6F6, common_routine_return_compare_val);
  		add_80_code(0x801BF6F6, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(
	(
	(strcmp("SCES_030.43;1", bootfile)) == 0) // Europe Disc 1
	|| ((strcmp("SCES_130.43;1", bootfile)) == 0) // Europe Disc 2
	|| ((strcmp("SCES_230.43;1", bootfile)) == 0) // Europe Disc 3
	|| ((strcmp("SCES_330.43;1", bootfile)) == 0) // Europe Disc 4
	) {
		/*
		D01C0892 1040
		801C0892 1000
		my code via aprip's gameshark conversion
		*/
  		add_D0_code(0x801C0892, common_routine_return_compare_val);
  		add_80_code(0x801C0892, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(
	((strcmp("SCES_030.44;1", bootfile)) == 0) // France Disc 1
	|| ((strcmp("SCES_130.44;1", bootfile)) == 0) // France Disc 2
	|| ((strcmp("SCES_230.44;1", bootfile)) == 0) // France Disc 3
	|| ((strcmp("SCES_330.44;1", bootfile)) == 0) // France Disc 4
	) {
		/*
		D01C0872 1040
		801C0872 1040
		my code via aprip's gameshark conversion
		*/
  		add_D0_code(0x801C0872, common_routine_return_compare_val);
  		add_80_code(0x801C0872, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(
	((strcmp("SCES_030.45;1", bootfile)) == 0) // Germany Disc 1
	|| ((strcmp("SCES_130.45;1", bootfile)) == 0) // Germany Disc 2
	|| ((strcmp("SCES_230.45;1", bootfile)) == 0) // Germany Disc 3
	|| ((strcmp("SCES_330.45;1", bootfile)) == 0)// Germany Disc 4
	) { 
		/*
		D01C082E 1040
		801C082E 1000
		my code via aprip's gameshark conversion
  		*/
  		add_D0_code(0x801C082E, common_routine_return_compare_val);
  		add_80_code(0x801C082E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	(
	((strcmp("SCES_030.46;1", bootfile)) == 0) // Italian Disc 1
	|| ((strcmp("SCES_130.46;1", bootfile)) == 0) // Italian Disc 2
	|| ((strcmp("SCES_230.46;1", bootfile)) == 0) // Italian Disc 3
	|| ((strcmp("SCES_330.46;1", bootfile)) == 0)// Italian Disc 4
	) {
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
   	(
	((strcmp("SLPM_866.52;1", bootfile)) == 0) // Love Hina: Ai wa Kotoba no Naka ni
	|| ((strcmp("SLPM_866.77;1", bootfile)) == 0) // Love Hina 2: Kotoba wa Konayuki no You ni
	) { 
		// Same code works for both games
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
   	(
	((strcmp("SLPS_023.68;1", bootfile)) == 0) // Japan
	|| ((strcmp("SLPM_805.08;1", bootfile)) == 0) // Japan Demo
	) {
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
		/*
		D0098804 023A
		80098806 1000
		code via https://gamehacking.org/game/89269
		*/
  		add_D0_code(0x80098804, 0x023A);
  		add_80_code(0x80098806, 0x1000);
		install_cheat_engine();
    } else if

// MLB 2002 Demo, MLB 2002, MLB 2003 Demo, MLB 2003, MLB 2004
   	(
	((strcmp("SCUS_946.48;1", bootfile)) == 0) // MLB 2002 USA Demo
	|| ((strcmp("SCUS_946.38;1", bootfile)) == 0) // MLB 2002 USA
	|| ((strcmp("SCUS_946.72;1", bootfile)) == 0) // MLB 2003 USA Demo
	|| ((strcmp("SCUS_946.53;1", bootfile)) == 0) // MLB 2003 USA
	|| ((strcmp("SCUS_946.89;1", bootfile)) == 0) // MLB 2004 USA
	) {
		/*
		D0028DB4 001E
		80028DB4 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x80028DB4, readtoc_compare_val);
  		add_80_code(0x80028DB4, readtoc_patch_val);
		install_cheat_engine();
    } else if

// My Garden
   	((strcmp("SLPS_022.13;1", bootfile)) == 0) { // Japan
		/*
		D009E212 1040
		8009E212 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
    	*/
  		add_D0_code(0x8009E212, common_routine_return_compare_val);
  		add_80_code(0x8009E212, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// NBA Shootout 2001 and NBA Shootout 2001 Demo
   	((strcmp("SCUS_945.81;1", bootfile)) == 0) { // this game is nuts. Seriously what the fuck is this. The demo and retail versions share not only the same executable filename, the demo executable file is the exact same with 0 diffs compared to the retail version. I guess retail functionallity is being enabled by some other file in track 01 (which do in fact differ between the demo and retail versions). EVEN FUCKING WORSE is that the demo version has serial number SCUS_945.82, but the boot file is SCUS_945.81! For now we enable both demo and retail codes for both versions to ensure it boots, since we can't detect this off of bootfile alone. To do this in a less ugly way we would need to find the file in track 01 that differs (to enable retail functionallity) and then diff that in memory.
		/*
		D01D1340 001E
		801D1340 0000
		my code generated via aprip (USA)
		*/
		add_D0_code(0x801D1340, readtoc_compare_val);
		add_80_code(0x801D1340, readtoc_patch_val);
		/*
		D01CFD68 001E
		801CFD68 0000
		my code generated via aprip (USA Demo)
		*/
		add_D0_code(0x801CFD68, readtoc_compare_val);
		add_80_code(0x801CFD68, readtoc_patch_val);
		install_cheat_engine();
    } else if

// NBA Shootout 2002 Demo
   	((strcmp("SCUS_946.60;1", bootfile)) == 0) { // USA
		/*
		D01D0FF4 001E
		801D0FF4 0000
		my code generated via aprip
		*/
		add_D0_code(0x801D0FF4, readtoc_compare_val);
		add_80_code(0x801D0FF4, readtoc_patch_val);
		install_cheat_engine();
    } else if

// NBA Shootout 2002
   	((strcmp("SCUS_946.41;1", bootfile)) == 0) { // USA
		/*
		D01D2724 001E
		801D2724 0000
		my code generated via aprip
		*/
		add_D0_code(0x801D2724, readtoc_compare_val);
		add_80_code(0x801D2724, readtoc_patch_val);
		install_cheat_engine();
    } else if

// NBA Shootout 2003
   	((strcmp("SCUS_946.73;1", bootfile)) == 0) { // USA
		/*
		D01D2860 001E
		801D2860 0000
		my code generated via aprip
		*/
		add_D0_code(0x801D2860, readtoc_compare_val);
		add_80_code(0x801D2860, readtoc_patch_val);
		install_cheat_engine();
    } else if

// NBA Shootout 2004
   	((strcmp("SCUS_946.91;1", bootfile)) == 0) { // USA
		/*
		D01D2928 001E
		801D2928 0000
		my code generated via aprip
		*/
		add_D0_code(0x801D2928, readtoc_compare_val);
		add_80_code(0x801D2928, readtoc_patch_val);
		install_cheat_engine();
    } else if

// NCAA FinalFour 2001
   	((strcmp("SCUS_945.79;1", bootfile)) == 0) { // USA
		/*
		D005B6A8 001E
		8005B6A8 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x8005B6A8, readtoc_compare_val);
  		add_80_code(0x8005B6A8, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// NCAA GameBreaker 2001
   	(
	((strcmp("SCUS_945.74;1", bootfile)) == 0) // NCAA GameBreaker 2001 USA
	|| ((strcmp("SCUS_945.73;1", bootfile)) == 0) // NCAA GameBreaker 2001 USA Demo
	) {
		/*
		D0112338 001E
		80112338 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x80112338, readtoc_compare_val);
  		add_80_code(0x80112338, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// NFL GameDay 2001
   	((strcmp("SCUS_945.75;1", bootfile)) == 0) { // USA
		/*
		D0112404 001E
		80112404 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x80112404, readtoc_compare_val);
  		add_80_code(0x80112404, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// NFL GameDay 2001 Demo
   	((strcmp("SCUS_945.76;1", bootfile)) == 0) { // USA
		/*
		D0112388 001E
		80112388 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x80112388, readtoc_compare_val);
  		add_80_code(0x80112388, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// NFL GameDay 2002
   	((strcmp("SCUS_946.39;1", bootfile)) == 0) { // USA
		/*
		D0032640 001E
		80032640 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x80032640, readtoc_compare_val);
  		add_80_code(0x80032640, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// NFL GameDay 2003, NFL GameDay 2004, and NFL GameDay 2005 (lmao they gave up?)
   	(
	((strcmp("SCUS_946.65;1", bootfile)) == 0) // NFL GameDay 2003 USA
	|| ((strcmp("SCUS_946.90;1", bootfile)) == 0) // NFL GameDay 2004 USA
	|| ((strcmp("SCUS_946.95;1", bootfile)) == 0) // NFL GameDay 2005 USA
	) {
		/*
		D0032ACC 001E
		80032ACC 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x80032ACC, readtoc_compare_val);
  		add_80_code(0x80032ACC, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// NHL FaceOff 2001
   	((strcmp("SCUS_945.77;1", bootfile)) == 0) { // USA
		/*
		D00F2470 001E
		800F2470 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x800F2470, readtoc_compare_val);
  		add_80_code(0x800F2470, readtoc_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("SCUS_945.78;1", bootfile)) == 0) { // USA Demo
		/*
		D00F1938 001E
		800F1938 0000
		my code generated via aprip
    	*/
  		add_D0_code(0x800F1938, readtoc_compare_val);
  		add_80_code(0x800F1938, readtoc_patch_val);
    	install_cheat_engine();
    } else if

// Oha-Studio Dance Dance Revolution
   	((strcmp("SLPM_866.03;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SCPS_100.99;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SCPS_101.04;1", bootfile)) == 0) { // Japan
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
   	(
	((strcmp("SCPS_101.12;1", bootfile)) == 0) // Japan Disc 1
	|| ((strcmp("SCPS_101.13;1", bootfile)) == 0) // Japan Disc 2
	|| ((strcmp("SCPS_101.14;1", bootfile)) == 0) // Japan Disc 3
	) {
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
   	((strcmp("SLPM_865.92;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_866.70;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_862.94;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_869.37;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_870.89;1", bootfile)) == 0) { // Japan
		/*
		D004A24C 001E
		8004A24C 0000
		my code via aprip to patch out readtoc
		*/
  		add_D0_code(0x8004A24C, readtoc_compare_val);
  		add_80_code(0x8004A24C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Resident Evil 3: The Last Escape
   	((strcmp("SLPS_023.00;1", bootfile)) == 0) { // Japan Rev 0/ Japan Rev 1
		ver_check = (load_addr + 0x1B0); // First different byte between revisions
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if((ver_check_val == 0xF4)) // Rev 0
		{
			/*
			D01840E2 1040
			801840E2 1000
			'skip check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
    		*/
	    	add_D0_code(0x801840E2, common_routine_return_compare_val);
			add_80_code(0x801840E2, common_routine_return_patch_val);
    		install_cheat_engine();
	    } else { // Rev 1
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

   	((strcmp("SLPM_804.85;1", bootfile)) == 0) { // Japan Demo
		/*
		D01800E2 1040
		801800E2 1000 
		my code via aprip gameshark code conversion
    	*/
	    add_D0_code(0x801800E2, common_routine_return_compare_val);
		add_80_code(0x801800E2, common_routine_return_patch_val);
    	install_cheat_engine();
	} else if

// Resident Evil Survivor
   	((strcmp("SLPS_025.53;1", bootfile)) == 0) { // Japan
		/*
		D0017962 1040
		80017962 1000
		'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
    	*/
  		add_D0_code(0x80017962, common_routine_return_compare_val);
  		add_80_code(0x80017962, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

   	((strcmp("SLUS_010.87;1", bootfile)) == 0) { // USA
		/*
		D001714E 1040
		8001714E 1000
		converted code via aprip
    	*/
  		add_D0_code(0x8001714E, common_routine_return_compare_val);
  		add_80_code(0x8001714E, common_routine_return_patch_val);
    	install_cheat_engine();
    } else if

   	(
	((strcmp("SLES_027.32;1", bootfile)) == 0) // Europe
	|| ((strcmp("SLES_027.44;1", bootfile)) == 0) // France
	) {
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
   	((strcmp("SCPS_101.03;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPS_022.20;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPS_022.55;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPS_022.62;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPS_023.24;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPS_023.38;1", bootfile)) == 0) { // Japan
		/*
		D006FD84 001E
		8006FD84 0000
		my code via aprip
		*/
  		add_D0_code(0x8006FD84, readtoc_compare_val);
  		add_80_code(0x8006FD84, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Rockman 6
   	((strcmp("SLPS_023.79;1", bootfile)) == 0) { // Japan
		/*
		D006DA7A 1040
		8006DA7A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
		*/
  		add_D0_code(0x8006DA7A, common_routine_return_compare_val);
  		add_80_code(0x8006DA7A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Rockman X5
   	((strcmp("SLPM_866.66;1", bootfile)) == 0) { // Japan
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
   	((strcmp("SLPM_869.59;1", bootfile)) == 0) { // Japan
		/*
		D006EC40 001E
		8006EC40 0000
		my code via aprip
		*/
  		add_D0_code(0x8006EC40, readtoc_compare_val);
  		add_80_code(0x8006EC40, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Street Fighter EX2 Plus
   	((strcmp("SLPS_025.08;1", bootfile)) == 0) { // Japan
		/*
		D01BD48A 1040
		801BD48A 1000
		code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_s.shtml
		*/
  		add_D0_code(0x801BD48A, common_routine_return_compare_val);
  		add_80_code(0x801BD48A, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SLPM_805.17;1", bootfile)) == 0) { // Japan Demo
		/*
		D01BD13E 1040
		801BD13E 1000
		my code via aprip gameshark code conversion
		*/
  		add_D0_code(0x801BD48A, common_routine_return_compare_val);
  		add_80_code(0x801BD13E, common_routine_return_patch_val);
		install_cheat_engine();
    } else if

// Spyro: Year Of The Dragon
// codes co-developed by MottZilla (mostly) and myself. Get rekt anti-tamper/apv1/apv2
	((strcmp("SCUS_944.67;1", bootfile)) == 0) { // has 2 versions, rev 0 and rev 1
		ver_check = (load_addr); // First different byte between revisions is well the first byte :)
		//debug_write("Got address for version check: %x", (uint32_t) ver_check);
		ver_check_val = *(uint8_t*) ver_check;
		//debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
		if(ver_check_val == 0xF4) { // Rev 0
			add_D0_code(0x8007F08C, 0x0001);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0002);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0003);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0004);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0005);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0006);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0007);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0008);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x0009);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x000A);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x000B);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x000C);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x000D);
			add_80_code(0x8007F08C, 0x0000);
			add_D0_code(0x8007F08C, 0x000E);
			add_80_code(0x8007F08C, 0x0000);
			install_cheat_engine();
		} else { // 0x08 = Rev 1
			add_D0_code(0x8007F23C, 0x0001);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0002);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0003);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0004);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0005);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0006);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0007);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0008);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x0009);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x000A);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x000B);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x000C);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x000D);
			add_80_code(0x8007F23C, 0x0000);
			add_D0_code(0x8007F23C, 0x000E);
			add_80_code(0x8007F23C, 0x0000);
			install_cheat_engine();
    	}
	} else if

// Strider 2
   	((strcmp("SLUS_011.63;1", bootfile)) == 0) { // USA
		/*
		D01F6570 001E
		801F6570 0000
		my code via aprip
		*/
  		add_D0_code(0x801F6570, readtoc_compare_val);
  		add_80_code(0x801F6570, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Tokimeki Memorial 2 (soo many god damn discs/versions/bootfiles)
   	(
	// main game (5 discs)
	   ((strcmp("SLPM_863.55;1", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 1
	|| ((strcmp("SLPM_863.50;1", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 1
	|| ((strcmp("SLPM_863.56;1", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 2
	|| ((strcmp("SLPM_863.51;1", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 2
	|| ((strcmp("SLPM_863.57;1", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 3
	|| ((strcmp("SLPM_863.52;1", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 3
	|| ((strcmp("SLPM_863.58;1", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 4
	|| ((strcmp("SLPM_863.53;1", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 4
	|| ((strcmp("SLPM_863.59;1", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 5
	|| ((strcmp("SLPM_863.54;1", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 5
	// dlc evs (3 discs)
	|| ((strcmp("SLPM_805.27;1", bootfile)) == 0) // Tokimeki Memorial 2 Emotional Voice System Append Disc 1
	|| ((strcmp("SLPM_805.44;1", bootfile)) == 0) // Tokimeki Memorial 2 Emotional Voice System Append Disc 2
	|| ((strcmp("SLPM_805.50;1", bootfile)) == 0) // Tokimeki Memorial 2 Emotional Voice System Append Disc 3
	) {
		/*
		D0011514 001E
		80011514 0000
		my code via aprip
		*/
  		add_D0_code(0x80011514, readtoc_compare_val);
  		add_80_code(0x80011514, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Tomba! 2: The Evil Swine Return
   	((strcmp("SCUS_944.54;1", bootfile)) == 0) { // USA
		/*
		D002542C 001E
		8002542C 0000
		my code via aprip
		*/
  		add_D0_code(0x8002542C, readtoc_compare_val);
  		add_80_code(0x8002542C, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Tron ni Kobun
   	((strcmp("SLPS_021.08;1", bootfile)) == 0) {  // Japan
		/*
		D004E168 001E
		8004E168 0000
		my code via aprip
		*/
  		add_D0_code(0xD004E168, readtoc_compare_val);
  		add_80_code(0x8004E168, readtoc_patch_val);
		install_cheat_engine();
    } else if

// Vandal Harts II
   	((strcmp("SLUS_009.40;1", bootfile)) == 0) { // USA
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
   	(
	((strcmp("SCUS_944.84;1", bootfile)) == 0) // USA Disc 1
	|| ((strcmp("SCUS_944.98;1", bootfile)) == 0) // USA Disc 2
	) {
   		/*
   		D003A4E8 001E
   		8003A4E8 0000
 		my code via aprip to patch out readtoc
    	*/
  		add_D0_code(0x8003A4E8, readtoc_compare_val);
  		add_80_code(0x8003A4E8, readtoc_patch_val);
		install_cheat_engine();
    } else if

   	((strcmp("SCUS_945.92;1", bootfile)) == 0) { // USA Demo
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
   	((strcmp("SLPM_862.91;1", bootfile)) == 0) { // Japan Rev 0/Japan Rev 1
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
   	((strcmp("SCPS_101.23;1", bootfile)) == 0) { // Japan
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
   	(
	((strcmp("SLPM_863.96;1", bootfile)) == 0) // Japan
	|| ((strcmp("SLPM_863.98;1", bootfile)) == 0) // Japan Demo
	|| ((strcmp("SLUS_014.11;1", bootfile)) == 0) // USA
	|| ((strcmp("SLES_039.47;1", bootfile)) == 0) // Europe
	|| ((strcmp("SLES_039.48;1", bootfile)) == 0) // France
	|| ((strcmp("SLES_039.49;1", bootfile)) == 0) // Germany
	|| ((strcmp("SLES_039.50;1", bootfile)) == 0) // Spain
	|| ((strcmp("SLES_039.51;1", bootfile)) == 0) // Italy
	) {
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