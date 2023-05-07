
#pragma once

void activate_anti_anti_piracy(const char * bootfile, const int32_t load_addr);

void enable_code(const uint32_t gs1, const uint16_t gs2);

void enable_compare_code(uint32_t gs1, uint16_t gs2, uint16_t gs3);

void install_cheat_engine();

extern bool cheat_engine_installed;
