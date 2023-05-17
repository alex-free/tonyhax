
#pragma once

void activate_anti_anti_piracy(const char * bootfile, const int32_t load_addr);

void enable_code_16(const uint32_t gs1, const uint16_t gs2);

void enable_code_8(const uint32_t gs1, const uint8_t gs2);

void enable_compare_code_16(const uint32_t gs1, const uint16_t gs2);

void enable_compare_code_8(const uint32_t gs1, const uint8_t gs2);

void install_cheat_engine();

extern bool cheat_engine_installed;
