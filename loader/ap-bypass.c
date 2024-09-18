
#include "bios.h"
#include "str.h"
#include "ap-bypass.h"
//#include "debugscreen.h"

bool cheat_engine_installed;

uint8_t gs_code_type;

int32_t code_address_ram_location = 0xD000;
int32_t code_compare_ram_location = 0xD004;
int32_t code_enable_ram_location = 0xD00C;  

void clear_gs_code_line_ram () {
    bzero((void*)0xD000, 0x600); 
// 255 code line limit * 6 bytes per code + 6 bytes of padding = 1536/0x600. 0xD000-0xD600 are to be zeroed out to ensure correct parsing by the cheat engine (used for gs codes loaded via memory card AND for APv2 bypasses). Every BIOS besides v3.0 has enough garbage? in this 'reserved' area to break the cheat engine parsing if we don't do this. Previously this zero-out was always done regardless of if the GameShark feature was actually being used. Now this is only done if the GameShark engine is active to fix issue 39: https://github.com/alex-free/tonyhax/issues/39 .
}

void add_8bit_code(const uint32_t gs1, const uint8_t gs2, const uint8_t gs_code_type) {
    if(code_address_ram_location == 0xD000)
        clear_gs_code_line_ram(); // before writing first code line clear RAM

    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 1);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
    code_address_ram_location = (code_address_ram_location + 0x010);
    code_compare_ram_location = (code_compare_ram_location + 0x010);
    code_enable_ram_location = (code_enable_ram_location + 0x010);
}

void add_16bit_code(const uint32_t gs1, const uint16_t gs2, const uint8_t gs_code_type) {

    if(code_address_ram_location == 0xD000)
        clear_gs_code_line_ram(); // before writing first code line clear RAM

    memcpy((void*)code_address_ram_location, &gs1, 4);
    memcpy((void*)code_compare_ram_location, &gs2, 2);
    memcpy((void*)code_enable_ram_location, &gs_code_type, 1);
// Update addresses to write to for an additional code
    code_address_ram_location = (code_address_ram_location + 0x010);
    code_compare_ram_location = (code_compare_ram_location + 0x010);
    code_enable_ram_location = (code_enable_ram_location + 0x010);
}

// size optimization wrapper, instead of specifying 0xD0 or 0x80 each time we add a code via built-in ap bypass system
void add_80_code(const uint32_t gs1, const uint16_t gs2) {
    add_16bit_code(gs1, gs2, 0x80);
}

void add_D0_code(const uint32_t gs1, const uint16_t gs2) {
    add_16bit_code(gs1, gs2, 0xD0);
}

void install_cheat_engine() {
// generate with `scripts/stealth-engine-xxd.sh` after compiling .EXE file with No $ PSX Emu Assembler
const unsigned char cheat_engine_v1_0_4[] = {
0xe0, 0xff, 0xbd, 0x27, 0x00, 0x00, 0xa4, 0xaf,
  0x04, 0x00, 0xa5, 0xaf, 0x08, 0x00, 0xa6, 0xaf, 0x0c, 0x00, 0xa7, 0xaf,
  0x00, 0x00, 0x04, 0x3c, 0x00, 0xd0, 0x84, 0x34, 0x00, 0x00, 0x00, 0x00,
  0x0c, 0x00, 0x86, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x9c, 0x00, 0xc0, 0x10,
  0xd0, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x3d, 0x00, 0xc7, 0x10,
  0xd1, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x4e, 0x00, 0xc7, 0x10,
  0xd2, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x61, 0x00, 0xc7, 0x10,
  0xd3, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x76, 0x00, 0xc7, 0x10,
  0xe0, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x27, 0x00, 0xc7, 0x10,
  0xe1, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0xc7, 0x10,
  0xe2, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x49, 0x00, 0xc7, 0x10,
  0xe3, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x5e, 0x00, 0xc7, 0x10,
  0x80, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0xc7, 0x10,
  0x30, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x00, 0xc7, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x07, 0x34, 0x00, 0x00, 0x00, 0x00,
  0x73, 0x00, 0xc7, 0x10, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x07, 0x34,
  0x1c, 0x00, 0x86, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x67, 0x00, 0xc7, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa0, 0x10, 0x00, 0x84, 0x24,
  0xcf, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94,
  0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa4,
  0x10, 0x00, 0x84, 0x24, 0xc8, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe6, 0x90, 0x00, 0x00, 0x00, 0x00, 0xe3, 0xff, 0xc5, 0x10,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0xbe, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00,
  0xd9, 0xff, 0xc5, 0x10, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24,
  0xb4, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90,
  0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90,
  0x00, 0x00, 0x00, 0x00, 0xcf, 0xff, 0xc5, 0x14, 0x00, 0x00, 0x00, 0x00,
  0x20, 0x00, 0x84, 0x24, 0xaa, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00, 0xc5, 0xff, 0xc5, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0xa0, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90, 0x00, 0x00, 0x00, 0x00,
  0x2b, 0x38, 0xc5, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb9, 0xff, 0xe0, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0x94, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00,
  0x2b, 0x38, 0xc5, 0x00, 0x00, 0x00, 0x00, 0x00, 0xad, 0xff, 0xe0, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0x88, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x90, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x90, 0x00, 0x00, 0x00, 0x00,
  0x2b, 0x38, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa1, 0xff, 0xe0, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0x7c, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x85, 0x94, 0x00, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe6, 0x94, 0x00, 0x00, 0x00, 0x00,
  0x2b, 0x38, 0xa6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x95, 0xff, 0xe0, 0x14,
  0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x84, 0x24, 0x70, 0xff, 0x00, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x85, 0x90, 0x10, 0x00, 0x87, 0x8c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa0, 0x20, 0x00, 0x84, 0x24,
  0x69, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x85, 0x94,
  0x10, 0x00, 0x87, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe5, 0xa4,
  0x20, 0x00, 0x84, 0x24, 0x62, 0xff, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xa4, 0x8f, 0x04, 0x00, 0xa5, 0x8f, 0x08, 0x00, 0xa6, 0x8f,
  0x0c, 0x00, 0xa7, 0x8f, 0x20, 0x00, 0xbd, 0x27, 0x01, 0x00, 0x1a, 0x3c,
  0xfc, 0xcf, 0x5a, 0x8f, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x40, 0x03,
  0x00, 0x00, 0x00, 0x00
};

    //debug_write("Installing MottZilla AP Engine");
    memcpy((void*)0xC000, (void*)cheat_engine_v1_0_4, sizeof(cheat_engine_v1_0_4)); // Copy MottZilla's cheat engine assembly binary to 0xC000
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
    cheat_engine_installed = true;
}

void activate_anti_anti_piracy(char * bootfile, const int32_t load_addr) 
{
    int32_t ver_check;
    uint8_t ver_check_val;
    int8_t bootfile_len = strlen(bootfile);
    /*
    lowest possible ap bootfile len is 19
    cdrom:\\XXXX_XXX.XX;1 = 21 len	
    cdrom:\XXXX_XXX.XX;1 = 20 len	
    cdrom:XXXX_XXX.XX;1 = 19 len		
    */
    //debug_write("Bootfile len: %d", bootfile_len);

    // Aprip fake VC0 bypass code type constants
    const uint16_t fake_vc0_bypass_compare_val = 0x001E;
    const uint16_t fake_vc0_bypass_patch_val = 0x0000;

    // Aprip fake PAL BIOS bypass code type constants
    const uint16_t fake_pal_bios_bypass_compare_val = 0x1062;
    const uint16_t fake_pal_bios_bypass_patch_val = 0x1800;

    // Many pre-existing 'skip mod check' or 'force routine ok' type codes from back in the day seem to share these values, so they are a const
    const uint16_t common_routine_return_compare_val = 0x1040;
    const uint16_t common_routine_return_patch_val = 0x1000;

    if(is_beat_mania_append_gottamix) // uses Append No Swap Bypass (By mdmdj) method so bootfile detection at this point in execution is not possible
    {
        /*
        D01C0838 2021
        801C0834 FFF6
        code 1/2 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
        */
        add_D0_code(0x801C0838, 0x2021);
        add_80_code(0x801C0834, 0xFFF6);
        /*
        D01C0838 2021
        801C0836 1000
        code 2/2 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
        */
        add_D0_code(0x801C0838, 0x2021);
        add_80_code(0x801C0836, 0x1000);
        install_cheat_engine();
        return;
    }

    // this is less expensive space-wise then using strncmp
    if(bootfile_len >= 19) {
        bootfile = &bootfile[bootfile_len-13]; // strip bootfile to last 13 bytes, XXXX_XXX.XX;1
        //debug_write("Bootfile stripped 1: %s", bootfile);
        bootfile[11] = 0; // replace ; with termination. So XXXX_XXX.XX;1 becomes XXXX_XXX.XX for less expensive (space-wise) strcmps
        //debug_write("Bootfile stripped 2: %s", bootfile);
        //for(volatile int i = 0; i < 0x100000; i++);  // won't be optimized out by -Os, pause	
    } else {
        return; 
        // Speed optimization. All anti-piracy games currently have an pre-stripped bootfile name that is at least 19 bytes long. So if the bootfile happens to have something like 'cdrom://MAIN.EXE;1' (which is 18 in length) , we already know not to bother even checking for an anti-piracy bootfile match to apply codes for (which takes time in itself to do as well).
    }

// Animetic Story Game 1: Card Captor Sakura
       if(
    ((strcmp("SLPS_018.30", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("SLPS_018.31", bootfile)) == 0) // Japan Disc 2
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
    ((strcmp("SCPS_101.15", bootfile)) == 0) { // Japan
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
    ((strcmp("SCPS_101.06", bootfile)) == 0) // Japan Rev 0/Rev 1 Disc 1
    || ((strcmp("SCPS_101.07", bootfile)) == 0) // Japan Rev 0/Rev 1 Disc 2
    ) {
        ver_check = (load_addr + 0x20); // First different byte between revisions
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0x8C) // Rev 0
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
            D0022206 1040
            80022206 1000
            my code via aprip gameshark code conversion
            */
            add_D0_code(0x80022206, common_routine_return_compare_val);
            add_80_code(0x80022206, common_routine_return_patch_val);
            install_cheat_engine();		
        }
    } else if

// Beatmania featuring Dreams Come True
       ((strcmp("SLPM_865.97", bootfile)) == 0) { // Japan
        /*
        D012129A 1040
        8012129A 1000
        skip routine code
        code from https://gamehacking.org/game/93343 by davintheravin
        did not need C1 code: "Code Execution Delay - Delays activation of codes by &value." because "Line starting w/ 'C1' needed for GS version 2.41 and up." and this tested okay. Info from "Info/Note" on that link
        */
        add_D0_code(0x8012129A, common_routine_return_compare_val);
        add_80_code(0x8012129A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Beatmania Best Hits
       ((strcmp("Slpm_865.96", bootfile)) == 0) { // Japan Rev 0/Rev 1
        // not a typo, weird asf filename
        /*
        D01500FE 1062
        801500FE 1800
        code generated via aprip
        */
        add_D0_code(0x801500FE, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801500FE, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Beat Mania: The Sound of Tokyo
    ((strcmp("SLPM_867.69", bootfile)) == 0) { // Japan
        /*
        D01338FE 1062
        801338FE 1800
        my code via aprip
        */
        add_D0_code(0x801338FE, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801338FE, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Beat Mania 6thMix + Core Remix
    ((strcmp("SLPM_870.12", bootfile)) == 0) { // Japan
        /*
        D0130822 1062
        80130822 1800
        my code generated via aprip
        */
        add_D0_code(0x80130822, fake_pal_bios_bypass_compare_val);
        add_80_code(0x80130822, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Bishi Bashi Special 2
    ((strcmp("SLPM_862.67", bootfile)) == 0) { // Japan
        /*
        D009818A 1040
        8009818A 1000
        code from https://consolecopyworld.com/psx/psx_game_codes_b.shtml
        */
        add_D0_code(0x8009818A, common_routine_return_compare_val);
        add_80_code(0x8009818A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Boku no Natsuyasumi: Summer Holiday 20th Century
    ((strcmp("SCPS_100.88", bootfile)) == 0) { // Japan
        /*
        D004921E 1062
        8004921E 1800
        my code generated via aprip
        */
        add_D0_code(0x8004921E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8004921E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Breath of Fire IV
       ((strcmp("SLPS_027.28", bootfile)) == 0) { // Japan / USA E3 2000 Beta Build
        /*
        D01CE39A 1062
        801CE39A 1800
        my code generated via aprip
        */
        add_D0_code(0x801CE39A, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801CE39A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Bust A Move 2: Dance Tengoku Mix
       ((strcmp("SLPM_862.19", bootfile)) == 0) { // Japan
        /*
        D008FB02 1040
        8008FB02 1000
        my code generated via aprip
        */
        add_D0_code(0x8008FB02, common_routine_return_compare_val);
        add_80_code(0x8008FB02, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Capcom vs. SNK: Millennium Fight 2000 Pro
       ((strcmp("SLPM_870.53", bootfile)) == 0) { // Japan
        /*
        D0033BCE 1062
        80033BCE 1800
        my code generated via aprip
        */
        add_D0_code(0x80033BCE, fake_pal_bios_bypass_compare_val);
        add_80_code(0x80033BCE, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Chase The Express
       (
    ((strcmp("SCPS_101.09", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("SCPS_101.10", bootfile)) == 0) // Japan Disc 2
    || ((strcmp("PAPX_901.06", bootfile)) == 0) // Japan Demo 1
    || ((strcmp("PCPX_961.89", bootfile)) == 0) // Japan Demo 2
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

// Chocobo Racing: Genkai e no Road
      ((strcmp("SLPS_019.51", bootfile)) == 0) { // Japan
        /*
        D00AB72A 1040
        800AB72A 1000
        code from https://consolecopyworld.com/psx/psx_game_codes_c.shtml (Bung Japan)
        */
        add_D0_code(0x800AB72A, common_routine_return_compare_val);
        add_80_code(0x800AB72A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if 

// Crash Bash
      ((strcmp("SCUS_945.70", bootfile)) == 0) { // USA
        /*
        D002D51E 1040
        8002D51E 1000
        code from GameHacking: https://gamehacking.org/game/88640, skips mod check
        */
        add_D0_code(0x8002D51E, common_routine_return_compare_val);
        add_80_code(0x8002D51E, common_routine_return_patch_val);
        install_cheat_engine();
    } else if 

       ((strcmp("SCPS_101.40", bootfile)) == 0) { // Japan
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
       ((strcmp("SCPS_101.18", bootfile)) == 0) { // Japan
        /*
        D001259A 1040
        8001259A 1000
        'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml (yes it's on the wrong lettered page)
        */
        add_D0_code(0x8001259A, common_routine_return_compare_val);
        add_80_code(0x8001259A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("PCPX_961.83", bootfile)) == 0) { // Japan Demo
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
       (
    ((strcmp("SCUS_946.25", bootfile)) == 0) // USA Demo
    || ((strcmp("SCUS_945.97", bootfile)) == 0) // USA
    )
    { 
        /*
        D00B1146 1062
        800B1146 1800
        my code generated via aprip
        */
        add_D0_code(0x800B1146, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800B1146, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dancing Blade Katte ni Momotenshi II: Tears of Eden
       (
    ((strcmp("SLPM_862.10", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("SLPM_862.11", bootfile)) == 0) // Japan Disc 2
    || ((strcmp("SLPM_862.12", bootfile)) == 0) // Japan Disc 3
    )
    { 
        /*
        D019E272 1040
        8019E272 1000
        force ok
        code from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        */
        add_D0_code(0x8019E272, common_routine_return_compare_val);
        add_80_code(0x8019E272, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Dance Dance Revolution
       ((strcmp("SLPM_862.22", bootfile)) == 0) { // Japan
        /*
        D001E160 FFF2
        8001E160 0001
        bypass checksum
        code from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        */
        add_D0_code(0x8001E160, 0xFFF2);
        add_80_code(0x8001E160, 0x0001);
        /*
        D01B6F20 0003
        801B6F20 0001
        pro action replay bypass
        code from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        */
        add_D0_code(0x801B6F20, 0x0003);
        add_80_code(0x801B6F20, 0x0001);
        /*
        D01B76A8 DE07
        801B76A8 DDFE
        mod-chip bypass
        code from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        */
        add_D0_code(0x801B76A8, 0xDE07);
        add_80_code(0x801B76A8, 0xDDFE);
        /*
        EDC code 1/3 from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        D004B4C0 0920
        8004B4C0 0900
        */
        add_D0_code(0x8004B4C0, 0x0920);
        add_80_code(0x8004B4C0, 0x0900);
        /*
        EDC code 2/3 from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        D01B6A68 0920
        801B6A68 0900
        */
        add_D0_code(0x801B6A68, 0x0920);
        add_80_code(0x801B6A68, 0x0900);
        /*
        EDC code 3/3 from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        D01B6BF0 0920
        801B6BF0 0900
        */
        add_D0_code(0x801B6BF0, 0x0920);
        add_80_code(0x801B6BF0, 0x0900);
        install_cheat_engine();
    } else if

       ((strcmp("SLUS_012.80", bootfile)) == 0) { // USA
        /*
        D010024E 1062
        8010024E 1800
        my code via aprip
        */
        add_D0_code(0x8010024E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8010024E, fake_pal_bios_bypass_patch_val);
        // todo: EDC bypass
        install_cheat_engine();
    } else if

// Dance Dance Revolution: Best Hits
       ((strcmp("SLPM_866.93", bootfile)) == 0) { // Japan
        /*
        D010024E 1062
        8010024E 1800
        my code generated via aprip
        */
        add_D0_code(0x8010024E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8010024E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dance Dance Revolution: Disney's Rave
       ((strcmp("SLPM_866.67", bootfile)) == 0) { // Japan
        /*
        D0190182 1062
        80190182 1800
        code generated via aprip
        */
        add_D0_code(0x80190182, fake_pal_bios_bypass_compare_val);
        add_80_code(0x80190182, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dance Dance Revolution: Extra Mix
       ((strcmp("SLPM_868.31", bootfile)) == 0) { // Japan
        /*
        D00E8266 1062
        800E8266 1800
        code generated via aprip
        */
        add_D0_code(0x800E8266, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800E8266, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dance Dance Revolution 2nd Remix
       ((strcmp("SLPM_862.52", bootfile)) == 0) { // Dance Dance Revolution 2nd Remix Append Club Vol 1 and Dance Dance Revolution 2nd Remix Append Club Vol 2 discs are booted with a 'disc change' feature within Dance Dance Revolution 2nd Remix (which is a 'base' disc when booting the others, kind of like DLC).
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
        D01C26DE 1062
        801C26DE 1800
        my code via aprip
        */
        add_D0_code(0x801C26DE,fake_pal_bios_bypass_compare_val);
        add_80_code(0x801C26DE, fake_pal_bios_bypass_patch_val);
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
        /*
        D01C276E 1062
        801C276E 1800
        my code via aprip
        */
        add_D0_code(0x801C276E,fake_pal_bios_bypass_compare_val);
        add_80_code(0x801C276E, fake_pal_bios_bypass_patch_val);
        // non-aprip generated codes are from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml 
        install_cheat_engine();
    } else if

// Dance Dance Revolution: 3rd Mix
       ((strcmp("SLPM_865.03", bootfile)) == 0) { // Japan
        /*
        D00C19A2 1062
        800C19A2 1800
        my code generated via aprip
        */
        add_D0_code(0x800C19A2, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800C19A2, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dance Dance Revolution: 4th Mix
       ((strcmp("SLPM_867.52", bootfile)) == 0) { // Japan
        /*
        D00E824E 1062
        800E824E 1800
        my code generated via aprip
        */
        add_D0_code(0x800E824E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800E824E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dance Dance Revolution: 5th Mix
       ((strcmp("SLPM_868.97", bootfile)) == 0) { // Japan
        /*
        D0174306 1062
        80174306 1800
        my code generated via aprip
        */
        add_D0_code(0x80174306, fake_pal_bios_bypass_compare_val);
        add_80_code(0x80174306, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dancing Stage featuring Dreams Come True
       ((strcmp("SLPM_865.05", bootfile)) == 0) { // Japan
        /*
        D0190182 1062
        80190182 1800
        code generated via aprip
        */
        add_D0_code(0x80190182, fake_pal_bios_bypass_compare_val);
        add_80_code(0x80190182, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Dancing Stage featuring True Kiss Destination
       ((strcmp("SLPM_864.11", bootfile)) == 0) { // Japan
        /*
        D019117A 1040
        8019117A 1000
        skip mod check
        code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        */
        add_D0_code(0x8019117A, common_routine_return_compare_val);
        add_80_code(0x8019117A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Dino Crisis
    ((strcmp("SLUS_009.22", bootfile)) == 0) { // USA Rev 0/USA Rev 1
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

       ((strcmp("SLPS_021.80", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPM_866.27", bootfile)) == 0) { // Japan
          /*
        D00D639E 1062
        800D639E 1800
        my code via aprip
        */
        add_D0_code(0x800D639E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800D639E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SLPM_805.73", bootfile)) == 0) { // Japan Demo
          /*
        D00C9DA6 1062
        800C9DA6 1800
        my code via aprip
        */
        add_D0_code(0x800C9DA6, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800C9DA6, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Disney's The Emperor's New Groove
       ((strcmp("SCUS_945.71", bootfile)) == 0) { // USA
          /*
        D004C6E2 1062
        8004C6E2 1800
        my code via aprip
        */
        add_D0_code(0x8004C6E2, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8004C6E2, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SCES_030.10", bootfile)) == 0) { // Europe
          /*
        D004CBDA 1062
        8004CBDA 1800
        my code via aprip
        */
        add_D0_code(0x8004CBDA, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8004CBDA, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Doko Demo Issho
    (
    ((strcmp("SCPS_100.92", bootfile)) == 0) // Japan Rev 0/Japan Rev 1
    || ((strcmp("SCPM_850.06", bootfile)) == 0) // Japan Calpis Water Version 
    ) { 
        /*
        these 3 codes work for Japan Rev 0, Japan Rev 1, and Japan Calpis Water Version.
        D01207E8 2021
        801207E4 FFF6
        code 1/3 from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
        */
          add_D0_code(0x801207E8, 0x2021);
          add_80_code(0x801207E4, 0xFFF6);
        /*
        D01207E8 2021
        801207E6 1000
        code 2/3 from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
          */
        add_D0_code(0x801207E8, 0x2021);
          add_80_code(0x801207E6, common_routine_return_patch_val);
        /*
        D0151AE2 1040
        80151AE2 1000
        code 3/3 from https://consolecopyworld.com/psx/psx_game_codes_d.shtml
          */
        add_D0_code(0x80151AE2, common_routine_return_compare_val);
          add_80_code(0x80151AE2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

    ((strcmp("PCPX_961.52", bootfile)) == 0) { // Japan Demo 1
        /*
        D0151D92 9222
        80151D92 A222
        force ok type B modpar generated code
        */
        add_D0_code(0x80151D92, 0x9222);
        add_80_code(0x80151D92, 0xA222);
        install_cheat_engine();
    } else if

    ((strcmp("PAPX_900.86", bootfile)) == 0) { // Japan Demo 2
        /*
        D0151D8A 9222
        80151D8A A222
        force ok type B modpar generated code
        */
        add_D0_code(0x80151D8A, 0x9222);
        add_80_code(0x80151D8A, 0xA222);
        install_cheat_engine();
    } else if
    
// Exciting Bass 2
       ((strcmp("SLPM_862.95", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPM_867.29", bootfile)) == 0) { // Japan
        /*
        D00225E2 1062
        800225E2 1800
        my code to patch out readtoc via aprip
          */
        add_D0_code(0x800225E2, fake_pal_bios_bypass_compare_val);
        add_80_code(0x800225E2, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Final Fantasy VIII
    (
       ((strcmp("SLPS_018.80", bootfile)) == 0) // Japan Disc 1
       || ((strcmp("SLPS_018.81", bootfile)) == 0) // Japan Disc 2
    || ((strcmp("SLPS_018.82", bootfile)) == 0) // Japan Disc 3
    || ((strcmp("SLPS_018.83", bootfile)) == 0) // Japan Disc 3
    ) {
        /*
        D009B182 0000
        8009B182 2402
        code from https://consolecopyworld.com/psx/psx_game_codes_f.shtml by Asian Game Shark Code Creator (NOTE: CODE has typo on consolecopyworld page)
        */
        add_D0_code(0x8009B182, 0x0000);
        add_80_code(0x8009B182, 0x2402);
        install_cheat_engine();
    } else if

// Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner
       ((strcmp("SCPS_101.34", bootfile)) == 0) { // Japan
        /*
        D016385E 1062
        8016385E 1800
        my code via aprip
          */
        add_D0_code(0x8016385E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8016385E, fake_pal_bios_bypass_patch_val);
          install_cheat_engine();
    } else if

// Glint Glitters
       ((strcmp("SLPM_862.00", bootfile)) == 0) { // Japan
        /*
        D01B2816 1040
        801B2816 1000
        code from https://gamehacking.org/game/94731
        this code is a 'force ok' type code. the whole routine still runs the test commands and readtoc, but it forces ok for the result of the test commands
          */
        add_D0_code(0x801B2816, common_routine_return_compare_val);
        add_80_code(0x801B2816, common_routine_return_patch_val);
        /*
        D01B3188 001E
        801B3188 0000
        my code via aprip. this disables readtoc so in combination with the code above this does allow a non-stealth mod-chip console to work as well as a stock console. Verified with SCPH-5501 non-stealth mod-chipped, and SCPH-101 stock.
          */
        add_D0_code(0x801B3188, fake_vc0_bypass_compare_val);
        add_80_code(0x801B3188, fake_vc0_bypass_patch_val);
        install_cheat_engine();
    } else if

// Global Force: Shin Sentou Kokka
       ((strcmp("SCPS_100.82", bootfile)) == 0) { // Japan Rev 0/Japan Rev 1
        // same codes works for both Japan Rev 0 and Japan Rev 1
        /*
        D01E8CC4 2021
        801E8CC0 FFF6
        code 1/2 from https://consolecopyworld.com/psx/psx_game_codes_g.shtml
        skips mod-check
        */
        add_D0_code(0x801E8CC4, 0x2021);
        add_80_code(0x801E8CC0, 0xFFF6);
        /*
        D01E8CC4 2021
        801E8CC2 1000
        code 2/2 from https://consolecopyworld.com/psx/psx_game_codes_g.shtml
        skips mod-check
        */
        add_D0_code(0x801E8CC4, 0x2021);
        add_80_code(0x801E8CC2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("PCPX_961.46", bootfile)) == 0) { // Japan Demo
        /*
        D01E91EC 2021
        801E91E8 FFF6
        code 1/2 via aprip conversion
        skips mod-check
        */
        add_D0_code(0x801E91EC, 0x2021);
        add_80_code(0x801E91E8, 0xFFF6);
        /*
        D01E91EC 2021
        801E91EA 1000
        code 2/2 via aprip conversion
        skips mod-check
        */
        add_D0_code(0x801E91EC, 0x2021);
        add_80_code(0x801E91EA, 0x1000);
        install_cheat_engine();
    } else if

// Goo! Goo! Soundry
       ((strcmp("SLPM_862.50", bootfile)) == 0) { // Japan
        /*
        D0012B66 1040
        80012B66 1000
        code from https://consolecopyworld.com/psx/psx_game_codes_g.shtml
        skips mod-check
        */
        add_D0_code(0x80012B66, common_routine_return_compare_val);
        add_80_code(0x80012B66, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Grind Session
       ((strcmp("SCUS_945.68", bootfile)) == 0) { // USA
        /*
        D0013F3A 1062
        80013F3A 1800
        my code via aprip
        */
          add_D0_code(0x80013F3A, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80013F3A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Guitar Freaks
       ((strcmp("SLPM_862.65", bootfile)) == 0) { // Japan
        /*
        D001654E 1040
        8001654E 1000
        skip mod check
        code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
        */
          add_D0_code(0x8001654E, common_routine_return_compare_val);
          add_80_code(0x8001654E, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Gungauge
       ((strcmp("SLPM_862.33", bootfile)) == 0) { // Japan
        /*
        D00E0206 1040
        800E0206 1000
        force ok
        code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_g.shtml
        */
          add_D0_code(0x800E0206, common_routine_return_compare_val);
          add_80_code(0x800E0206, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Harlem Beat: You're The One
       ((strcmp("SLPM_863.29", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPM_864.17", bootfile)) == 0) { // Japan
        /*
        D001844E 1440
        8001844E 1040
        my very first custom bypass developed in no $ psx emu! 
        skips mod-check completely	
        */
          add_D0_code(0x8001844E, 0x1440);
          add_80_code(0x8001844E, common_routine_return_compare_val);	
        install_cheat_engine();
    } else if

// Hyper Value 2800: Mahjong
       ((strcmp("SLPM_862.92", bootfile)) == 0) { // Japan
        /*
        D00A0186 1040
        800A0186 1000
        code found on consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_h.shtml
        */
          add_D0_code(0x800A0186, common_routine_return_compare_val);
          add_80_code(0x800A0186, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Hyper Value 2800: Hyper Pachinko
    ((strcmp("SLPM_864.18", bootfile)) == 0) { // Japan
        /*
        D01380FE 1062
        801380FE 1800
        first match for PAL BIOS (there are 2 matches)
        code generated via aprip
        */
          add_D0_code(0x801380FE, fake_pal_bios_bypass_compare_val);
          add_80_code(0x801380FE, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// i-mode mo Issho: Doko Demo Issho Tsuika Disc
    ((strcmp("SCPS_101.41", bootfile)) == 0) { // Japan
    /*
    D015205C 0062
    8015205C 0014
    D015205E 1202
    8015205E 1800
    aprip conversion from MottZilla and I's koneko mo isso bypass 
    force ok for test commands
    */
    add_D0_code(0x8015205C, 0x0062);
    add_80_code(0x8015205C, 0x0014);
    add_D0_code(0x8015205E, 0x1202);
    add_80_code(0x8015205E, 0x1800);
    /*
    D01698B4 001E
    801698B4 0000
    code generated via aprip by M4x1mumReZ: https://gbatemp.net/members/m4x1mumrez.610331/
    */
    add_D0_code(0x801698B4, fake_vc0_bypass_compare_val);
    add_80_code(0x801698B4, fake_vc0_bypass_patch_val);
    /*
    D01518D4 000A
    801518D4 0000
    D01518D6 1062
    801518D6 0000
    Fake a Non-PAL BIOS
    aprip conversion from MottZilla and I's koneko mo isso bypass 
    */
    add_D0_code(0x801518D4, 0x000A);
    add_80_code(0x801518D4, 0x0000);
    add_D0_code(0x801518D6, 0x1062);
    add_80_code(0x801518D6, 0x0000);
    install_cheat_engine();
    } else if

// I.Q Final
    (
    ((strcmp("PCPX_961.37", bootfile)) == 0) // Japan Demo 1
    || ((strcmp("PAPX_900.63", bootfile)) == 0) // Japan Demo 2
    ) {
        // Notice how the protection was not in the released retail version (this was supposed to be the second protected game after PoPoRoGue but the protection for PoPoRoGue Rev 0, the only protected game at the time, was broken for SCPH-1000 unmodified consoles): https://geocities.restorativland.org/SiliconValley/Station/8269/
        /*
        D00824CA 1040
        800824CA 1000
        force ok
        code from https://consolecopyworld.com/psx/psx_game_codes_i.shtml
        */
          add_D0_code(0x800824CA, common_routine_return_compare_val);
          add_80_code(0x800824CA, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Jikkyou Powerful Pro Yakyuu: Premium-ban
       ((strcmp("SLPM_872.16", bootfile)) == 0) { // Japan
          /*
        D016641A 1040
        8016641A 1000
        my code via aprip conversion, I dumped the RAM from the Jikkyou Powerful Pro Yakyuu 2000: Ketteiban game and used the GameShark conversion feature with the dumped ram from Jikkyou Powerful Pro Yakyuu: Premium-ban and it actually was similar enough to work		
        */
        add_D0_code(0x8016641A, common_routine_return_compare_val);
        add_80_code(0x8016641A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Jikkyou Powerful Pro Yakyuu '99 Ketteiban
       ((strcmp("SLPM_864.33", bootfile)) == 0) { // Japan
          /*
        D016A04E 1062
        8016A04E 1800
        my code via aprip
        */
        add_D0_code(0x8016A04E, fake_pal_bios_bypass_compare_val);
        add_80_code(0x8016A04E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Jikkyou Powerful Pro Yakyuu '99: Kaimakuban
       ((strcmp("SLPM_862.53", bootfile)) == 0) { // Japan
        /*
        D016A07A 1040
        8016A07A 1000
        code from copy console world: https://consolecopyworld.com/psx/psx_game_codes_j.shtml
        */
        add_D0_code(0x8016A07A, common_routine_return_compare_val);
        add_80_code(0x8016A07A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Jikkyou Powerful Pro Yakyuu 2000: Kaimakuban / Jikkyou Powerful Pro Yakyuu 2000: Ketteiban
    (
       ((strcmp("SLPM_865.78", bootfile)) == 0) // Jikkyou Powerful Pro Yakyuu 2000: Kaimakuban
    || ((strcmp("SLPM_866.94", bootfile)) == 0) // Jikkyou Powerful Pro Yakyuu 2000: Ketteiban
    ) {
        /*
        D016807A 1040
        8016807A 1000
        my code via aprip conversion, I dumped the RAM from the Jikkyou Powerful Pro Yakyuu '99: Kaimakuban game and used the GameShark conversion feature with the dumped ram from Jikkyou Powerful Pro Yakyuu 2000: Ketteiban and it actually was similar enough to work
        */
        add_D0_code(0x8016807A, common_routine_return_compare_val);
        add_80_code(0x8016807A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Jikkyou Powerful Pro Yakyuu 2001: Ketteiban / Jikkyou Powerful Pro Yakyuu 2001 / Jikkyou Powerful Pro Yakyuu 2002: Haru 
    (
       ((strcmp("SLPM_868.07", bootfile)) == 0) // Jikkyou Powerful Pro Yakyuu 2001
       || ((strcmp("SLPM_869.90", bootfile)) == 0) // Jikkyou Powerful Pro Yakyuu 2001: Ketteiban
    || ((strcmp("SLPM_870.33", bootfile)) == 0) // Jikkyou Powerful Pro Yakyuu 2002: Haru
    ) {
        /*
        D01D9646 1040
        801D9646 1000
        my code via aprip conversion, I dumped the RAM from the Jikkyou Powerful Pro Yakyuu 2000: Ketteiban game and used the GameShark conversion feature with the dumped ram from Jikkyou Powerful Pro Yakyuu 2001: Ketteiban and it actually was similar enough to work. Code conversion got 2 matches, first match worked.
        */
        add_D0_code(0x8016643A, common_routine_return_compare_val);
        add_80_code(0x8016643A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if
    
// Jikkyou Kyousouba Ikusei Simulation Game: Breeding Stud '99
       ((strcmp("SLPM_863.16", bootfile)) == 0) { // Japan
          /*
        D00A54D2 1040
        800A54D2 1000
        code from https://consolecopyworld.com/psx/psx_game_codes_b.shtml
        */
        add_D0_code(0x800A54D2, common_routine_return_compare_val);
        add_80_code(0x800A54D2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// JoJo's Bizarre Adventure
       ((strcmp("SLPS_022.36", bootfile)) == 0) { // Japan
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

// Shiritsu Justice Gakuen: Nekketsu Seishun Nikki 2
    ((strcmp("SLPS_021.20", bootfile)) == 0) { // Japan
        /*
        D00A6CFA 1040
        800A6CFA 1000
        force ok
        code from https://consolecopyworld.com/psx/psx_game_codes_j.shtml
        */
          add_D0_code(0x800A6CFA, common_routine_return_compare_val);
          add_80_code(0x800A6CFA, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Koko Hore! Pukka
    ((strcmp("SCPS_101.33", bootfile)) == 0) { // Japan
        /*
        D008694A 1062
        8008694A 1800
        code generated via aprip
        */
          add_D0_code(0x8008694A, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8008694A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Koneko mo Issho
       ((strcmp("SCPS_101.27", bootfile)) == 0) { // Japan
        /*
        D01520D8 0062
        801520D8 0014
        D01520DA 1202
        801520DA 1800
        bypass co-developed by me and MottZilla
        force ok for test commands
        */	
          add_D0_code(0x801520D8, 0x0062);
          add_80_code(0x801520D8, 0x0014);
          add_D0_code(0x801520DA, 0x1202);
          add_80_code(0x801520DA, 0x1800);
        /*
        D016957C 001E
        8016957C 0000
        code generated via aprip to patch out readtoc
        */
          add_D0_code(0x8016957C, fake_vc0_bypass_compare_val);
          add_80_code(0x8016957C, fake_vc0_bypass_patch_val);
        /*
        D0151950 000A
        80151950 0000
        D0151952 1062
        80151952 0000
        never lock up on PAL BIOS		
        */
        add_D0_code(0x80151950, 0x000A);
        add_80_code(0x80151950, 0x0000);
        add_D0_code(0x80151952, 0x1062);
        add_80_code(0x80151952, 0x0000);
        install_cheat_engine();
    } else if

// Konami 80's Arcade Gallery
    ((strcmp("SLPM_862.28", bootfile)) == 0) { // Japan
        /*
        D0013FD2 1440
        80013FD2 1000
        skip mod check
        code from https://consolecopyworld.com/psx/psx_game_codes_k.shtml
        */
          add_D0_code(0x80013FD2, common_routine_return_compare_val);
          add_80_code(0x80013FD2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Legend Of Dragoon
       (
    ((strcmp("SCPS_101.19", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("scps_101.20", bootfile)) == 0) // Japan Disc 2 (weird ass filename not a typo)
    || ((strcmp("scps_101.21", bootfile)) == 0) // Japan Disc 3 (weird ass filename not a typo)
    || ((strcmp("scps_101.22", bootfile)) == 0) // Japan Disc 4 (weird ass filename not a typo)
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
    ((strcmp("SCUS_944.91", bootfile)) == 0) // USA Disc 1
    || ((strcmp("SCUS_945.84", bootfile)) == 0) // USA Disc 2
    || ((strcmp("SCUS_945.85", bootfile)) == 0) // USA Disc 3
    || ((strcmp("SCUS_945.86", bootfile)) == 0) // USA Disc 4
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
    (strcmp("SCES_030.43", bootfile)) == 0) // Europe Disc 1
    || ((strcmp("SCES_130.43", bootfile)) == 0) // Europe Disc 2
    || ((strcmp("SCES_230.43", bootfile)) == 0) // Europe Disc 3
    || ((strcmp("SCES_330.43", bootfile)) == 0) // Europe Disc 4
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
    ((strcmp("SCES_030.44", bootfile)) == 0) // France Disc 1
    || ((strcmp("SCES_130.44", bootfile)) == 0) // France Disc 2
    || ((strcmp("SCES_230.44", bootfile)) == 0) // France Disc 3
    || ((strcmp("SCES_330.44", bootfile)) == 0) // France Disc 4
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
    ((strcmp("SCES_030.45", bootfile)) == 0) // Germany Disc 1
    || ((strcmp("SCES_130.45", bootfile)) == 0) // Germany Disc 2
    || ((strcmp("SCES_230.45", bootfile)) == 0) // Germany Disc 3
    || ((strcmp("SCES_330.45", bootfile)) == 0)// Germany Disc 4
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
    ((strcmp("SCES_030.46", bootfile)) == 0) // Italian Disc 1
    || ((strcmp("SCES_130.46", bootfile)) == 0) // Italian Disc 2
    || ((strcmp("SCES_230.46", bootfile)) == 0) // Italian Disc 3
    || ((strcmp("SCES_330.46", bootfile)) == 0)// Italian Disc 4
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
       ((strcmp("SLPS_021.70", bootfile)) == 0) { // Japan
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

// Lord Of Monsters
       ((strcmp("SCPS_100.86", bootfile)) == 0) { // Japan
          /*
        D0015F4A 1040
        80015F4A 1000
        force ok
        code from https://consolecopyworld.com/psx/psx_game_codes_l.shtml
        */
        add_D0_code(0x80015F4A, common_routine_return_compare_val);
        add_80_code(0x80015F4A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("PAPX_900.81", bootfile)) == 0) { // Japan Demo
          /*
        D005E7EA 1040
        8005E7EA 1000
        force ok
        code from aprip conversion
        */
        add_D0_code(0x8005E7EA, common_routine_return_compare_val);
        add_80_code(0x8005E7EA, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Love Hina: Ai wa Kotoba no Naka ni / Love Hina 2: Kotoba wa Konayuki no You ni
       (
    ((strcmp("SLPM_866.52", bootfile)) == 0) // Love Hina: Ai wa Kotoba no Naka ni
    || ((strcmp("SLPM_866.77", bootfile)) == 0) // Love Hina 2: Kotoba wa Konayuki no You ni
    ) { 
        /*
        D01009FE 1620
        801009FE 1220
        custom bypass developed by myself with no $ psx emu
        */
         add_D0_code(0x801009FE, 0x1620);
         add_80_code(0x801009FE, 0x1220);
         install_cheat_engine();
    } else if

// Magical Tetris Challenge featuring Mickey
       ((strcmp("SLPS_017.86", bootfile)) == 0) {
        /*
        D014C072 1040
        8014C072 1000
        force ok
        code from https://consolecopyworld.com/psx/psx_game_codes_m.shtml
        */
          add_D0_code(0x8014C072, common_routine_return_compare_val);
          add_80_code(0x8014C072, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Marvel vs. Capcom: Clash of Super Heroes
       (
    ((strcmp("SLPS_023.68", bootfile)) == 0) // Japan
    || ((strcmp("SLPM_805.08", bootfile)) == 0) // Japan Demo
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
       ((strcmp("SCUS_945.64", bootfile)) == 0) {
        /*
        D009877E 1062
        8009877E 1800
        my code via aprip
        */
          add_D0_code(0x8009877E, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8009877E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Minna no Golf 2
       ((strcmp("SCPS_100.93", bootfile)) == 0) { // Japan Rev 0 / Japan Rev 1
        /*
        D0050E3A 1040
        80050E3A 1000
        works on both Japan Rev 0 and Japan Rev 1
        code from https://consolecopyworld.com/psx/psx_game_codes_e.shtml
        */
          add_D0_code(0x80050E3A, common_routine_return_compare_val);
          add_80_code(0x80050E3A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// MLB 2002 Demo, MLB 2002, MLB 2003 Demo, MLB 2003, MLB 2004, MLB 2005
       (
    ((strcmp("SCUS_946.48", bootfile)) == 0) // MLB 2002 USA Demo
    || ((strcmp("SCUS_946.38", bootfile)) == 0) // MLB 2002 USA
    || ((strcmp("SCUS_946.72", bootfile)) == 0) // MLB 2003 USA Demo
    || ((strcmp("SCUS_946.53", bootfile)) == 0) // MLB 2003 USA
    || ((strcmp("SCUS_946.89", bootfile)) == 0) // MLB 2004 USA
    || ((strcmp("SCUS_946.92", bootfile)) == 0) // MLB 2005 USA
    ) {
        /*
        D002024A 1062
        8002024A 1800
        my code generated via aprip
        */
          add_D0_code(0x8002024A, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8002024A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Metal Gear Solid: Integral
    (
       ((strcmp("SLPM_862.47", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("SLPM_862.48", bootfile)) == 0) // Japan Disc 2
    ) {
        /*
        D00C3AB6 1040
        800C3AB6 1000
        skip mod check
        code 1/2 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
        */
          add_D0_code(0x800C3AB6, common_routine_return_compare_val);
          add_80_code(0x800C3AB6, common_routine_return_patch_val);
        /*
        D00C492A 1040
        800C492A 1000
        skip mod check
        code 2/2 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
        */
          add_D0_code(0x800C492A, common_routine_return_compare_val);
          add_80_code(0x800C492A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SLPM_862.49", bootfile)) == 0) { // Japan Disc 3
        /*
        D00C209A 1040
        800C209A 1000
        code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
        */
          add_D0_code(0x800C209A, common_routine_return_compare_val);
          add_80_code(0x800C209A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// My Garden
       ((strcmp("SLPS_022.13", bootfile)) == 0) { // Japan
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
       ((strcmp("SCUS_945.81", bootfile)) == 0) { // this game is nuts. Seriously what the fuck is this. The demo and retail versions share not only the same executable filename, the demo executable file is the exact same with 0 diffs compared to the retail version. I guess retail functionallity is being enabled by some other file in track 01 (which do in fact differ between the demo and retail versions). EVEN FUCKING WORSE is that the demo version has serial number SCUS_945.82, but the boot file is SCUS_945.81! For now we enable both demo and retail codes for both versions to ensure it boots, since we can't detect this off of bootfile alone. To do this in a less ugly way we would need to find the file in track 01 that differs (to enable retail functionallity) and then diff that in memory.
        /*
        D01AD562 1062
        801AD562 1800
        my code generated via aprip (USA)
        */
        add_D0_code(0x801AD562, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801AD562, fake_pal_bios_bypass_patch_val);
        /*
        D01ABF9A 1062
        801ABF9A 1800
        my code generated via aprip (USA Demo)
        */
        add_D0_code(0x801ABF9A, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801ABF9A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NBA Shootout 2002
       ((strcmp("SCUS_946.60", bootfile)) == 0) { // USA Demo
        /*
        D01AC5E6 1062
        801AC5E6 1800
        my code generated via aprip
        */
        add_D0_code(0x801AC5E6, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801AC5E6, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SCUS_946.41", bootfile)) == 0) { // USA
        /*
        D01ADD06 1062
        801ADD06 1800
        my code generated via aprip
        */
        add_D0_code(0x801ADD06, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801ADD06, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NBA Shootout 2003
       ((strcmp("SCUS_946.73", bootfile)) == 0) { // USA
        /*
        D01ADE42 1062
        801ADE42 1800
        my code generated via aprip
        */
        add_D0_code(0x801ADE42, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801ADE42, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NBA Shootout 2004
       ((strcmp("SCUS_946.91", bootfile)) == 0) { // USA
        /*
        D01ADF0A 1062
        801ADF0A 1800
        my code generated via aprip
        */
        add_D0_code(0x801ADF0A, fake_pal_bios_bypass_compare_val);
        add_80_code(0x801ADF0A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NCAA FinalFour 2001
       ((strcmp("SCUS_945.79", bootfile)) == 0) { // USA
        /*
        D001DE06 1062
        8001DE06 1800
        my code generated via aprip
        */
          add_D0_code(0x8001DE06, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8001DE06, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NCAA GameBreaker 2001
       (
    ((strcmp("SCUS_945.74", bootfile)) == 0) // USA
    || ((strcmp("SCUS_945.73", bootfile)) == 0) // USA Demo
    ) {
        /*
        D0100A5A 1062
        80100A5A 1800
        my code generated via aprip
        */
          add_D0_code(0x80100A5A, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80100A5A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NFL GameDay 2001
       (
    ((strcmp("SCUS_945.75", bootfile)) == 0) // USA
    || ((strcmp("SCUS_945.76", bootfile)) == 0) // USA Demo
    )
     {
        /*
        D010000E 1062
        8010000E 1800
        my code generated via aprip
        */
          add_D0_code(0x8010000E, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8010000E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NFL GameDay 2002, NFL GameDay 2003, NFL GameDay 2004, and NFL GameDay 2005
       (
    ((strcmp("SCUS_946.39", bootfile)) == 0) // NFL GameDay 2002 USA
    || ((strcmp("SCUS_946.65", bootfile)) == 0) // NFL GameDay 2003 USA
    || ((strcmp("SCUS_946.90", bootfile)) == 0) // NFL GameDay 2004 USA
    || ((strcmp("SCUS_946.95", bootfile)) == 0) // NFL GameDay 2005 USA
    ) {
        /*
        D002000E 1062
        8002000E 1800
        my code generated via aprip
        */
          add_D0_code(0x8002000E, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8002000E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// NHL FaceOff 2001
       ((strcmp("SCUS_945.77", bootfile)) == 0) { // USA
        /*
        D00F1126 1062
        800F1126 1800
        my code generated via aprip
        */
          add_D0_code(0x800F1126, fake_pal_bios_bypass_compare_val);
          add_80_code(0x800F1126, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SCUS_945.78", bootfile)) == 0) { // USA Demo
        /*
        D00F05EE 1062
        800F05EE 1800
        my code generated via aprip
        */
          add_D0_code(0x800F05EE, fake_pal_bios_bypass_compare_val);
          add_80_code(0x800F05EE, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Oha-Studio Dance Dance Revolution
       ((strcmp("SLPM_866.03", bootfile)) == 0) { // Japan
        /*
        D00F8236 1062
        800F8236 1800
        code generated via aprip
        */
          add_D0_code(0x800F8236, fake_pal_bios_bypass_compare_val);
          add_80_code(0x800F8236, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Omega Boost
       ((strcmp("SCPS_100.20", bootfile)) == 0) { // Japan
        /*
        D0120876 1040
        80120876 1000
        force ok
        code from https://consolecopyworld.com/psx/psx_game_codes_o.shtml
        */
          add_D0_code(0x80120876, common_routine_return_compare_val);
          add_80_code(0x80120876, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("PAPX_900.80", bootfile)) == 0) { // Japan
        /*
        D0120876 1040
        80120876 1000
        force ok
        code via aprip conversion (pattern length set to 10)
        */
          add_D0_code(0x80120962, common_routine_return_compare_val);
          add_80_code(0x80120962, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Ore no Ryouri / My Cooking
       ((strcmp("SCPS_100.99", bootfile)) == 0) { // Japan
        /*
        D0031C1A 1040
        80031C1A 1000
        code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_m.shtml
        */
          add_D0_code(0x80031C1A, common_routine_return_compare_val);
          add_80_code(0x80031C1A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Ore no Shikabane o Koete Yuke
       ((strcmp("SCPS_100.74", bootfile)) == 0) { // Japan
        /*
        D00C7DBE 1040
        800C7DBE 1000
        code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_o.shtml
        */
          add_D0_code(0x800C7DBE, common_routine_return_compare_val);
          add_80_code(0x800C7DBE, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Panekit: Infinitive Crafting Toy Case
       ((strcmp("SCPS_100.96", bootfile)) == 0) { // Japan Rev 0 / Japan Rev 1
        ver_check = (load_addr + 0x3E52C); // First different byte between rev 0 and rev 1
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0x40) { // Japan Rev 0
            /*
            skip mod check (3 codes)
            D00F290C 800B
            800F290E 1000
            code 1/3 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml
            */
              add_D0_code(0x800F290C, 0x800B);
              add_80_code(0x800F290E, common_routine_return_patch_val);
            /*
            D00F290C 800B
            800F290C 000E
            code 2/3 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml		
            */
              add_D0_code(0x800F290C, 0x800B);
              add_80_code(0x800F290C, 0x000E);
            /*
            D0052710 FFF8
            80052710 0001
            code 3/3 from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_p.shtml
            */
              add_D0_code(0x80052710, 0xFFF8);
              add_80_code(0x80052710, 0x0001);
            install_cheat_engine();
        } else { // 0x00 Japan Rev 1
            //debug_write("YES");
            /*
            skip mod check (3 codes)
            D0168AAC 800B
            80168AAE 1000
            code 1/3 converted via aprip
            */
              add_D0_code(0x80168AAC, 0x800B);
              add_80_code(0x80168AAE, common_routine_return_patch_val);
            /*
            D0168AAC 800B
            80168AAC 000E
            code 2/3 converted via aprip		
            */
              add_D0_code(0x80168AAC, 0x800B);
              add_80_code(0x80168AAC, 0x000E);
            /*
            D0052710 FFF8
            80052710 0001
            code 3/3 needed no conversion for rev 1: ./aprip D0052710 FFF8 paner0 paner1 4 shows this same address with a match
            */
              add_D0_code(0x80052710, 0xFFF8);
              add_80_code(0x80052710, 0x0001);
            install_cheat_engine();
        }
    } else if

// Planet Lakia
       ((strcmp("SLPM_862.64", bootfile)) == 0) { // Japan / English Translation
        ver_check = (load_addr + 0xC130); // First different byte between original and translation. Translation has it's own bypass implemented which causes the game to lock up if ours is also applied.
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0x00) { // Japan, English Translation has 0xC4 here
            /*
            D001F1C6 1402
            8001F1C6 1000
            force ok
            code 1/2 from https://gamehacking.org/game/107982
            */
              add_D0_code(0x8001F1C6, 0x1402);
              add_80_code(0x8001F1C6, common_routine_return_patch_val);
            /*
            D002DBA6 1040
            8002DBA6 1000
            code 2/2 from https://gamehacking.org/game/107982
            */
              add_D0_code(0x8002DBA6, common_routine_return_compare_val);
              add_80_code(0x8002DBA6, common_routine_return_patch_val);
            install_cheat_engine();
        }
    } else if

// Pocket Jiman
       ((strcmp("SCPS_101.04", bootfile)) == 0) { // Japan
        /*
        D01054D2 1062
        801054D2 1800
         code by https://gbatemp.net/members/m4x1mumrez.610331/ generated with APrip
        */
          add_D0_code(0x801054D2, fake_pal_bios_bypass_compare_val);
          add_80_code(0x801054D2, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Pocket MuuMuu
       ((strcmp("SCPS_100.76", bootfile)) == 0) { // Japan
        /*
        skip mod check
        D001F7F8 2021
        8001F7F4 FFF6
        code 1/2 from https://consolecopyworld.com/psx/psx_game_codes_p.shtml
        */
          add_D0_code(0x8001F7F8, 0x2021);
          add_80_code(0x8001F7F4, 0xFFF6);
        /*
        D001F7F8 2021
        8001F7F6 1000
        code 2/2 from https://consolecopyworld.com/psx/psx_game_codes_p.shtml
        */
          add_D0_code(0x8001F7F8, 0x2021);
          add_80_code(0x8001F7F6, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// PoPoLoCrois Monogatari II
       (
    ((strcmp("SCPS_101.12", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("SCPS_101.13", bootfile)) == 0) // Japan Disc 2
    || ((strcmp("SCPS_101.14", bootfile)) == 0) // Japan Disc 3
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

// PoPoRoGue
       ((strcmp("SCPS_100.50", bootfile)) == 0) { // Japan Rev 0 / Japan Rev 1
        ver_check = (load_addr + 0x8FC); // First different byte between rev 0 and rev 1.
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0x64) { // Japan Rev 0
            /*
            D008EF4E 1040
            8008EF4E 1000
            code from https://consolecopyworld.com/psx/psx_game_codes_p.shtml
            */
              add_D0_code(0x8008EF4E, common_routine_return_compare_val);
              add_80_code(0x8008EF4E, common_routine_return_patch_val);
            install_cheat_engine();
        } else { // 0x7C Rev 1
            /*
            D012E96C 0119
            8012E96C 0000
            code 1/4 generated via aprip
            */
              add_D0_code(0x8012E96C, 0x0119);
              add_80_code(0x8012E96C, 0x0000);
            /*
            D012E96E 0304
            8012E96E 0000
            code 2/4 generated via aprip
            */
              add_D0_code(0x8012E96E, 0x0304);
              add_80_code(0x8012E96E, 0x0000);
            /*
            D012E978 0119
            8012E978 0000
            code 3/4 generated via aprip
            */
              add_D0_code(0x8012E978, 0x0119);
              add_80_code(0x8012E978, 0x0000);	
            /*	
            D012E97A 0302
            8012E97A 0000
            code 4/4 generated via aprip
            */
              add_D0_code(0x8012E97A, 0x302);
              add_80_code(0x8012E97A, 0x0000);
            install_cheat_engine();
        }
    } else if

// Pop'n Music: Animation Melody
       ((strcmp("SLPM_865.92", bootfile)) == 0) { // Japan
        /*
        D0016112 1062
        80016112 1800
        code generated via aprip
        */
          add_D0_code(0x80016112, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80016112, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Pop'n Music: Disney Tunes
       ((strcmp("SLPM_866.70", bootfile)) == 0) { // Japan
        /*
        D0013332 1062
        80013332 1800
        code generated via aprip
        */
          add_D0_code(0x80013332, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80013332, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Pop'n Music 2
       ((strcmp("SLPM_862.94", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPM_869.37", bootfile)) == 0) { // Japan
           /*
        D0030E0E 1062
        80030E0E 1800
        my code via aprip
        */
          add_D0_code(0x80030E0E, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80030E0E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Pop'n Music 6
       ((strcmp("SLPM_870.89", bootfile)) == 0) { // Japan
        /*
        D0030F06 1062
        80030F06 1800
        my code via aprip
        */
          add_D0_code(0x80030F06, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80030F06, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Resident Evil 3: The Last Escape
       ((strcmp("SLPS_023.00", bootfile)) == 0) { // Japan Rev 0/ Japan Rev 1
        ver_check = (load_addr + 0x1B0); // First different byte between revisions
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0xF4) // Rev 0
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

       ((strcmp("SLPM_804.85", bootfile)) == 0) { // Japan Demo
        /*
        D01800E2 1040
        801800E2 1000 
        my code via aprip gameshark code conversion
        */
        add_D0_code(0x801800E2, common_routine_return_compare_val);
        add_80_code(0x801800E2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SLUS_900.64", bootfile)) == 0) { // USA Demo
        /*
        D01840E2 1040
        801840E2 1000
        my code via aprip gameshark code conversion
        */
        add_D0_code(0x801840E2, common_routine_return_compare_val);
        add_80_code(0x801840E2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Resident Evil Survivor
       ((strcmp("SLPS_025.53", bootfile)) == 0) { // Japan
        /*
        D0017962 1040
        80017962 1000
        'skip mod check' code is from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_b.shtml
        */
          add_D0_code(0x80017962, common_routine_return_compare_val);
          add_80_code(0x80017962, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SLUS_010.87", bootfile)) == 0) { // USA
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
    ((strcmp("SLES_027.32", bootfile)) == 0) // Europe
    || ((strcmp("SLES_027.44", bootfile)) == 0) // France
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
       ((strcmp("SCPS_101.03", bootfile)) == 0) { // Japan
        /*
        D001C646 1040
        8001C646 1000
        skip mod check
        code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_r.shtml
        */
          add_D0_code(0x8001C646, common_routine_return_compare_val);
          add_80_code(0x8001C646, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Rockman
       ((strcmp("SLPS_022.20", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPS_022.55", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPS_022.62", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPS_023.24", bootfile)) == 0) { // Japan
        /*
        D01D9E78 4042
        801D9E78 0042 
        force ok code
        */
          add_D0_code(0x801D9E78, 0x4042);
          add_80_code(0x801D9E78, 0x0042);
         /*
         D007009C 001E
        8007009C 0000
         my code via aprip to patch out readtoc
        */
          add_D0_code(0x8007009C, fake_vc0_bypass_compare_val);
          add_80_code(0x8007009C, fake_vc0_bypass_patch_val);
        install_cheat_engine();
    } else if

// Rockman 5: Blues no Wana!?
       ((strcmp("SLPS_023.38", bootfile)) == 0) { // Japan
        /*
        D006E0D6 1062
        8006E0D6 1800
        my code via aprip
        */
          add_D0_code(0x8006E0D6, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8006E0D6, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Rockman 6
       ((strcmp("SLPS_023.79", bootfile)) == 0) { // Japan
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
       ((strcmp("SLPM_866.66", bootfile)) == 0) { // Japan
        /*
        D0011EC6 1062
        80011EC6 1800
        my code via aprip
        */
          add_D0_code(0x80011EC6, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80011EC6, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Rockman X6
       ((strcmp("SLPM_869.59", bootfile)) == 0) { // Japan
        /*
        D001219E 1062
        8001219E 1800
        my code via aprip
        */
          add_D0_code(0x8001219E, fake_pal_bios_bypass_compare_val);
          add_80_code(0x8001219E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// SaGa Frontier II
       ((strcmp("SLPS_019.90", bootfile)) == 0) { // Japan
        /*
        D00DC7D6 1040
        800DC7D6 1000
        force ok test commands
        code from https://consolecopyworld.com/psx/psx_game_codes_s.shtml		
        */
          add_D0_code(0x800DC7D6, common_routine_return_compare_val);
          add_80_code(0x800DC7D6, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Saru! Get You! / Ape Escape
       ((strcmp("SCPS_100.91", bootfile)) == 0) { // Japan Rev 0 / Japan Rev 1
        ver_check = (load_addr + 0x68); // First different byte between revisions is 0x68
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0xA0) { // Japan Rev 0
        /*
        D0136A8A 1040
        80136A8A 1000
        force ok test commands
        code from https://consolecopyworld.com/psx/psx_game_codes_a.shtml
        */
          add_D0_code(0x80136A8A, common_routine_return_compare_val);
          add_80_code(0x80136A8A, common_routine_return_patch_val);
        } else { // 0xF0 Japan Rev 1
        /*
        D0136AAA 1040
        80136AAA 1000
        force ok test commands
        my code via aprip conversion
        */
          add_D0_code(0x80136AAA, common_routine_return_compare_val);
          add_80_code(0x80136AAA, common_routine_return_patch_val);			
        }
        install_cheat_engine();
    } else if

       ((strcmp("PAPX_900.79", bootfile)) == 0) { // Japan demo
        /*
        D0137A2A 1040
        80137A2A 1000
        force ok test commands
        my code via aprip conversion		
        */
          add_D0_code(0x80137A2A, common_routine_return_compare_val);
          add_80_code(0x80137A2A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Silent Hill
       ((strcmp("SLPM_861.92", bootfile)) == 0) { // Japan Rev 0/Japan Rev 1/Japan Rev 2
        // same code works for Japan Rev 0, Japan Rev 1, and Japan Rev 2
        /*
        D01E778E 1040
        801E778E 1000
        code from https://gamehacking.org/game/108601
        */
          add_D0_code(0x801E778E, common_routine_return_compare_val);
          add_80_code(0x801E778E, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Spyro The Dragon
       (
    ((strcmp("SCPS_100.85", bootfile)) == 0) // Japan
    || ((strcmp("SCPS_100.83", bootfile)) == 0)
    ) {
        /*
        D006003E 9222
        8006003E A222
        skip mod check
        codes from https://consolecopyworld.com/psx/psx_game_codes_s.shtml
        */
          add_D0_code(0x8006003E, 0x9222);
          add_80_code(0x8006003E, 0xA222);
        install_cheat_engine();
    } else if

// Spyro: Year Of The Dragon
    ((strcmp("SCUS_944.67", bootfile)) == 0) { // has 2 versions, rev 0 and rev 1
        ver_check = (load_addr); // First different byte between revisions is well the first byte :)
        //debug_write("Got address for version check: %x", (uint32_t) ver_check);
        ver_check_val = *(uint8_t*) ver_check;
        //debug_write("Ver check address has the contents : %x", (uint8_t) ver_check_val);
        if(ver_check_val == 0xF4) { // Rev 0
            /*
            D007F08C 0001
            8007F08C 0000
            D007F08C 0002
            8007F08C 0000
            D007F08C 0003
            8007F08C 0000
            D007F08C 0004
            8007F08C 0000
            D007F08C 0005
            8007F08C 0000
            D007F08C 0006
            8007F08C 0000
            D007F08C 0007
            8007F08C 0000
            D007F08C 0008
            8007F08C 0000
            D007F08C 0009
            8007F08C 0000
            D007F08C 000A
            8007F08C 0000
            D007F08C 000B
            8007F08C 0000
            D007F08C 000C
            8007F08C 0000
            D007F08C 000D
            8007F08C 0000
            D007F08C 000E
            8007F08C 0000
            codes co-developed by MottZilla (mostly) and myself.	
            */
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
            /*
            D007F23C 0001
            8007F23C 0000
            D007F23C 0002
            8007F23C 0000
            D007F23C 0003
            8007F23C 0000
            D007F23C 0004
            8007F23C 0000
            D007F23C 0005
            8007F23C 0000
            D007F23C 0006
            8007F23C 0000
            D007F23C 0007
            8007F23C 0000
            D007F23C 0008
            8007F23C 0000
            D007F23C 0009
            8007F23C 0000
            D007F23C 000A
            8007F23C 0000
            D007F23C 000B
            8007F23C 0000
            D007F23C 000C
            8007F23C 0000
            D007F23C 000D
            8007F23C 0000
            D007F23C 000E
            8007F23C 0000
            Codes manually converted to Rev 1 by myself	
            */
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

// Street Fighter EX2 Plus
       ((strcmp("SLPS_025.08", bootfile)) == 0) { // Japan
        /*
        D01BD48A 1040
        801BD48A 1000
        code from consolecopyworld: https://consolecopyworld.com/psx/psx_game_codes_s.shtml
        */
          add_D0_code(0x801BD48A, common_routine_return_compare_val);
          add_80_code(0x801BD48A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SLPM_805.17", bootfile)) == 0) { // Japan Demo
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
       ((strcmp("SLUS_011.63", bootfile)) == 0) { // USA
        /*
        D01F4D5E 1062
        801F4D5E 1800
        my code via aprip
        */
          add_D0_code(0x801F4D5E, fake_pal_bios_bypass_compare_val);
          add_80_code(0x801F4D5E, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Tokimeki Memorial 2 (soo many god damn discs/versions/bootfiles)
       (
    // main game (5 discs)
       ((strcmp("SLPM_863.55", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 1
    || ((strcmp("SLPM_863.50", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 1
    || ((strcmp("SLPM_863.56", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 2
    || ((strcmp("SLPM_863.51", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 2
    || ((strcmp("SLPM_863.57", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 3
    || ((strcmp("SLPM_863.52", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 3
    || ((strcmp("SLPM_863.58", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 4
    || ((strcmp("SLPM_863.53", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 4
    || ((strcmp("SLPM_863.59", bootfile)) == 0) // Tokimeki Memorial 2 Rev 0/Rev 1 Disc 5
    || ((strcmp("SLPM_863.54", bootfile)) == 0) // Tokimeki Memorial 2 Limited Box Disc 5
    // dlc evs (3 discs)
    || ((strcmp("SLPM_805.27", bootfile)) == 0) // Tokimeki Memorial 2 Emotional Voice System Append Disc 1
    || ((strcmp("SLPM_805.44", bootfile)) == 0) // Tokimeki Memorial 2 Emotional Voice System Append Disc 2
    || ((strcmp("SLPM_805.50", bootfile)) == 0) // Tokimeki Memorial 2 Emotional Voice System Append Disc 3
    ) {
        /*
        D00108C6 1040
        800108C6 1000
        code from https://gamehacking.org/game/109315
        force ok result of test commands
        */
          add_D0_code(0x800108C6, common_routine_return_compare_val);
          add_80_code(0x800108C6, common_routine_return_patch_val);
        /*
        D0011514 001E
        80011514 0000
        my code via aprip to disable readtoc
        */
          add_D0_code(0x80011514, fake_vc0_bypass_compare_val);
          add_80_code(0x80011514, fake_vc0_bypass_patch_val);
        install_cheat_engine();
    } else if

// Tokimeki Memorial Drama Series Vol. 3: Tabidachi no Uta
       (
    ((strcmp("SLPM_862.24", bootfile)) == 0) // Japan Disc 1
    || ((strcmp("SLPM_862.25", bootfile)) == 0) // Japan Disc 2
    ){ // Japan Disc 1
        /*
        D005C290 2021
        8005C28C FFF6
        code 1/3 from https://consolecopyworld.com/psx/psx_game_codes_t.shtml
        */
          add_D0_code(0x8005C290, 0x2021);
          add_80_code(0x8005C28C, 0xFFF6);
        /*
        D005C290 2021
        8005C28E 1000
        code 2/3 from https://consolecopyworld.com/psx/psx_game_codes_t.shtml
        */
          add_D0_code(0x8005C290, 0x2021);
          add_80_code(0x8005C28E, common_routine_return_patch_val);
        /*
        D001B3A6 1060
        8001B3A6 1000
        code 3/3 from https://consolecopyworld.com/psx/psx_game_codes_t.shtml
        */
          add_D0_code(0x8001B3A6, 0x1060);
          add_80_code(0x8001B3A6, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Tomba! 2: The Evil Swine Return
       ((strcmp("SCUS_944.54", bootfile)) == 0) { // USA
        /*
        D0011A1A 1062
        80011A1A 1800
        my code via aprip
        */
          add_D0_code(0x80011A1A, fake_pal_bios_bypass_compare_val);
          add_80_code(0x80011A1A, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// Tron ni Kobun
       ((strcmp("SLPS_021.08", bootfile)) == 0) {  // Japan
        /*
        D001277A 1040
        8001277A 1000
        code from https://gamehacking.org/game/109452
        force ok test command results
        */
          add_D0_code(0x8001277A, common_routine_return_compare_val);
          add_80_code(0x8001277A, common_routine_return_patch_val);
        /*
        D004E168 001E
        8004E168 0000
        my code via aprip to patch out readtoc
        */
          add_D0_code(0x8004E168, fake_vc0_bypass_compare_val);
          add_80_code(0x8004E168, fake_vc0_bypass_patch_val);
        // together these commands disable the routine effectively
        install_cheat_engine();
    } else if

// Um Jammer Lammy
// TODO: FIND Um Jammer Lammy Japan Tentou Houei-you and add support if needed
       ((strcmp("SCPS_180.11", bootfile)) == 0) { // Japan
         /*	
        D01DA7D8 2021
        801DA7D4 FFF6
        code 1/2 from https://consolecopyworld.com/psx/psx_game_codes_u.shtml
          */
        add_D0_code(0x801DA7D8, 0x2021);
          add_80_code(0x801DA7D4, 0xFFF6);
        /*
        D01DA7D8 2021
        801DA7D6 1000
        code 2/2 from https://consolecopyworld.com/psx/psx_game_codes_u.shtml
        */
          add_D0_code(0x801DA7D8, 0x2021);
          add_80_code(0x801DA7D6, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SCUS_943.98", bootfile)) == 0) { // USA Demo
         /*	
        D01DAB44 2021
        801DAB40 FFF6
        mod-check skip code via modpar https://consolecopyworld.com/psx/psx_utils_pn_cnv.shtml
          */
        add_D0_code(0x801DAB44, 0x2021);
          add_80_code(0x801DAB40, 0xFFF6);
         /*	
        D01DAB44 2021
        801DAB42 1000
        mod-check skip code via modpar https://consolecopyworld.com/psx/psx_utils_pn_cnv.shtml
          */
          add_D0_code(0x801DAB44, 0x2021);
          add_80_code(0x801DAB42, 0x1000);
        install_cheat_engine();
    } else if

       ((strcmp("SCES_017.53", bootfile)) == 0) { // Europe
         /*	
        D01D81B8 2021
        801D81B4 FFF6
        mod-check skip code via modpar https://consolecopyworld.com/psx/psx_utils_pn_cnv.shtml
          */
        add_D0_code(0x801D81B8, 0x2021);
          add_80_code(0x801D81B4, 0xFFF6);
         /*	
        D01D81B8 2021
        801D81B6 1000
        mod-check skip code via modpar https://consolecopyworld.com/psx/psx_utils_pn_cnv.shtml
          */
          add_D0_code(0x801D81B8, 0x2021);
          add_80_code(0x801D81B6, 0x1000);
        install_cheat_engine();
    } else if

// Vandal Hearts II
       ((strcmp("SLUS_009.40", bootfile)) == 0) { // USA
         /*	
        D0040C90 000B
        80040C92 1000 
        code from http://archive.thegia.com/news/9912/n09a.html
        */
          add_D0_code(0x80040C90, 0x000B);
          add_80_code(0x80040C92, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SLPM_862.51", bootfile)) == 0) { // Japan
         /*	
        D00C49A2 1040
        800C49A2 1000
        code from https://consolecopyworld.com/psx/psx_game_codes_v.shtml
        */
          add_D0_code(0x800C49A2, common_routine_return_compare_val);
          add_80_code(0x800C49A2, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

// Wild Arms 2
       (
    ((strcmp("SCPS_100.89", bootfile)) == 0) // Japan Rev 0 Disc 1 / Japan Rev 1 Disc 1
    || ((strcmp("SCPS_100.90", bootfile)) == 0) // Japan Rev 0 Disc 2 / Japan Rev 1 Disc 2
    ) {
           /*
           D002A51A 1040
        8002A51A 1000
         code from https://consolecopyworld.com/psx/psx_game_codes_w.shtml
        */
          add_D0_code(0x8002A51A, common_routine_return_compare_val);
          add_80_code(0x8002A51A, common_routine_return_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("PCPX_961.61", bootfile)) == 0) // Japan Demo 1
    {
           /*
        D002A594 2021
        8002A590 FFF6
         code 1/2 from https://consolecopyworld.com/psx/psx_game_codes_w.shtml
        */
          add_D0_code(0x8002A594, 0x2021);
          add_80_code(0x8002A590, 0xFFF6);
        /*
        D002A594 2021
        8002A592 1000
         code 2/2 from https://consolecopyworld.com/psx/psx_game_codes_w.shtml
        */
          add_D0_code(0x8002A594, 0x2021);
          add_80_code(0x8002A592, 0x1000);
        install_cheat_engine();

    } else if

       ((strcmp("PCPX_961.71", bootfile)) == 0) // Japan Demo 2
    {
           /*
        D002A590 2021
        8002A58C FFF6
         code 1/2 converted via aprip
        */
          add_D0_code(0x8002A590, 0x2021);
          add_80_code(0x8002A58C, 0xFFF6);
        /*
        D002A590 2021
        8002A58E 1000
         code 2/2 converted via aprip
        */
          add_D0_code(0x8002A590, 0x2021);
          add_80_code(0x8002A58E, 0x1000);
        install_cheat_engine();

    } else if
    (
    ((strcmp("SCUS_944.84", bootfile)) == 0) // USA Disc 1
    || ((strcmp("SCUS_944.98", bootfile)) == 0) // USA Disc 2
    ) {
           /*
           D00282CE 1062
        800282CE 1800
         my code via aprip
        */
          add_D0_code(0x800282CE, fake_pal_bios_bypass_compare_val);
          add_80_code(0x800282CE, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

       ((strcmp("SCUS_945.92", bootfile)) == 0) { // USA Demo
        /*
           D00283C6 1062
        800283C6 1800
        my code via aprip gameshark code conversion on my own code (code-ception)
        */
          add_D0_code(0x800283C6, fake_pal_bios_bypass_compare_val);
          add_80_code(0x800283C6, fake_pal_bios_bypass_patch_val);
        install_cheat_engine();
    } else if

// World Soccer Jikkyou Winning Eleven 4
       ((strcmp("SLPM_862.91", bootfile)) == 0) { // Japan Rev 0/Japan Rev 1
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
       ((strcmp("SCPS_101.23", bootfile)) == 0) { // Japan
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
    ((strcmp("SLPM_863.96", bootfile)) == 0) // Japan
    || ((strcmp("SLPM_863.98", bootfile)) == 0) // Japan Demo
    || ((strcmp("SLUS_014.11", bootfile)) == 0) // USA
    || ((strcmp("SLES_039.47", bootfile)) == 0) // Europe
    || ((strcmp("SLES_039.48", bootfile)) == 0) // France
    || ((strcmp("SLES_039.49", bootfile)) == 0) // Germany
    || ((strcmp("SLES_039.50", bootfile)) == 0) // Spain
    || ((strcmp("SLES_039.51", bootfile)) == 0) // Italy
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