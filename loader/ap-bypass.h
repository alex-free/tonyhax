
#pragma once

void activate_anti_anti_piracy(char * bootfile, const int32_t load_addr);
void add_8bit_code(const uint32_t gs1, const uint8_t gs2, const uint8_t gs_code_type);
void add_16bit_code(const uint32_t gs1, const uint16_t gs2, const uint8_t gs_code_type);
void install_cheat_engine();

extern bool cheat_engine_installed;
extern bool is_beat_mania_append_gottamix;
