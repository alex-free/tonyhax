
#pragma once

void activate_anti_anti_piracy(const char * bootfile, const int32_t load_addr);

void add_30_code(const uint32_t gs1, const uint8_t gs2);
void add_E0_code(const uint32_t gs1, const uint8_t gs2);
void add_E1_code(const uint32_t gs1, const uint8_t gs2);

void add_80_code(const uint32_t gs1, const uint16_t gs2);
void add_D0_code(const uint32_t gs1, const uint16_t gs2);
void add_D1_code(const uint32_t gs1, const uint16_t gs2);

void install_cheat_engine();

extern bool cheat_engine_installed;
