
.DELETE_ON_ERROR:

.PHONY: clean

SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))

# Common variables
TONYHAX_VERSION=v1.4.4

CC=mipsel-none-elf-gcc
CFLAGS=-Wno-error=array-bounds -G0 -Oz -Wall -Wextra -Wno-main -EL -march=r3000 -mabi=32 -mfp32 -mno-abicalls -fno-pic -fdata-sections -ffunction-sections -fno-builtin -nostdlib -DTONYHAX_VERSION=$(TONYHAX_VERSION)
# Original Tonyhax
#CFLAGS=-O1 -Wall -Wextra -Wno-main -EL -march=r3000 -mabi=32 -mfp32 -mno-abicalls -fno-pic -fdata-sections -ffunction-sections -fno-builtin -nostdlib -DTONYHAX_VERSION=$(TONYHAX_VERSION) -DSOFTUART_PATCH=$(SOFTUART_PATCH)

LD=mipsel-none-elf-ld
LDFLAGS=--gc-sections

OBJCOPY=mipsel-none-elf-objcopy
OBJCOPYFLAGS=-O binary

# Entry point variables

ENTRY_MCS := \
	$(patsubst $(SELF_DIR)/entrypoints/%-tpl.mcs, %.mcs, $(wildcard $(SELF_DIR)/entrypoints/*-tpl.mcs)) \
	FF9-A-JP/ff9-a-jp.mcs \
	FF9-B-JP/ff9-b-jp.mcs \
	FF9-A-US/ff9-a-us.mcs \
	FF9-B-US/ff9-b-us.mcs

ENTRY_RAW := \
	FF9-A-JP/BISLPS-0200000000-00 \
	FF9-B-JP/BISLPS-0200000000-00 \
	FF9-A-US/BASLUS-0125100000-00 \
	FF9-B-US/BASLUS-0125100000-00 \
	BISLPS-01391SKI00S \
	BISLPS-00300TEKKEN-2 \
	BISLPS-01300TEKKEN-3 \
	BISLPM-86922CHSVTRv1 \
	BISLPM-86489CHSv1 \
	BISLPM-86751CEEAG01 \
	BISLPM-86754DRACULA	\
	BISLPS-01323010001 \
    BISCPS-1004700000000 \
    BISCPS-1007300000000 \
    BISLPS-00130DOKIOH \
	BASCUS-9415400047975 \
	BASCUS-9424400000000 \
	BASCUS-9455916 \
	BASLUS-00213TEKKEN-2 \
	BASLUS-00402TEKKEN-3 \
	BASLUS-00571 \
	BASLUS-00856 \
	BASLUS-00882CHSv1 \
	BASLUS-01066TNHXG01 \
	BASLUS-01384DRACULA \
	BASLUS-01419TNHXG01 \
	BASLUS-01485TNHXG01 \
	BASLUS-01506XSMOTOv1 \
	BESCES-00255TEKKEN-2 \
	BESCES-01237TEKKEN-3 \
	BESCES-0096700765150 \
	BESCES-0142000000000 \
	BESCES-0228316 \
	BESLES_01182CHSv1 \
	BESLES-01376 \
	BESLES-02618 \
	BESLES-02908TNHXG01 \
	BESLES-02909TNHXG01 \
	BESLES-02910TNHXG01 \
	BESLES-02942CHSVTRv1 \
	BESLES-03057SSBv1 \
	BESLES-03645TNHXG01 \
	BESLES-03646TNHXG01 \
	BESLES-03647TNHXG01 \
	BESLES-03827SSII \
	BESLES-03954TNHXG01 \
	BESLES-03955TNHXG01 \
	BESLES-03956TNHXG01 \
	BESLES-04095XSMOTO

ENTRY_FILES := $(ENTRY_MCS) $(ENTRY_RAW) entry-bb.bin entry.bin

# Program loader variables

LOADER_FILES := orca.inc tonyhax.mcs HAX tonyhax.exe

LOADER_FILES_NO_MCS := orca.inc tonyhax.exe


# Loader output

LOADER_OUTPUT_FILES := HAX FF9 tonyhax.mcs tonyhax-ff9.mcs tonyhax.exe

# FreePSXBoot images

FREEPSXBOOT_IMAGES := \
    tonyhax_scph-1000_slot1.mcr \
    tonyhax_scph-1000_slot2.mcr \
    tonyhax_scph-3000_v1.1_slot1.mcr \
    tonyhax_scph-3000_v1.1_slot2.mcr \
    tonyhax_scph-3000_v2.1_slot1.mcr \
    tonyhax_scph-3000_v2.1_slot2.mcr \
    tonyhax_scph-3500_slot1.mcr \
    tonyhax_scph-3500_slot2.mcr \
    tonyhax_scph-5000_slot1.mcr \
    tonyhax_scph-5000_slot2.mcr \
    tonyhax_scph-5500_slot1.mcr \
    tonyhax_scph-5500_slot2.mcr \
    tonyhax_scph-7000_slot1.mcr \
    tonyhax_scph-7000_slot2.mcr \
    tonyhax_scph-7500_slot1.mcr \
    tonyhax_scph-7500_slot2.mcr \
    tonyhax_scph-9000_slot1.mcr \
    tonyhax_scph-9000_slot2.mcr \
    tonyhax_scph-100_slot1.mcr \
    tonyhax_scph-100_slot2.mcr \
	tonyhax_scph-1001_v2.0_slot1.mcr \
	tonyhax_scph-1001_v2.0_slot2.mcr \
	tonyhax_scph-1001_v2.1_slot1.mcr \
	tonyhax_scph-1001_v2.1_slot2.mcr \
	tonyhax_scph-1001_v2.2_slot1.mcr \
	tonyhax_scph-1001_v2.2_slot2.mcr \
	tonyhax_scph-1002_v2.0_slot1.mcr \
	tonyhax_scph-1002_v2.0_slot2.mcr \
	tonyhax_scph-1002_v2.1_slot1.mcr \
	tonyhax_scph-1002_v2.1_slot2.mcr \
	tonyhax_scph-1002_v2.2_slot1.mcr \
	tonyhax_scph-1002_v2.2_slot2.mcr \
	tonyhax_scph-5001_slot1.mcr \
	tonyhax_scph-5001_slot2.mcr \
	tonyhax_scph-5501_slot1.mcr \
	tonyhax_scph-5501_slot2.mcr \
	tonyhax_scph-5502_slot1.mcr \
	tonyhax_scph-5502_slot2.mcr \
	tonyhax_scph-5552_slot1.mcr \
	tonyhax_scph-5552_slot2.mcr \
	tonyhax_scph-7001_slot1.mcr \
	tonyhax_scph-7001_slot2.mcr \
	tonyhax_scph-7002_slot1.mcr \
	tonyhax_scph-7002_slot2.mcr \
	tonyhax_scph-7501_slot1.mcr \
	tonyhax_scph-7501_slot2.mcr \
	tonyhax_scph-7502_slot1.mcr \
	tonyhax_scph-7502_slot2.mcr \
	tonyhax_scph-9001_slot1.mcr \
	tonyhax_scph-9001_slot2.mcr \
	tonyhax_scph-9002_slot1.mcr \
	tonyhax_scph-9002_slot2.mcr \
	tonyhax_scph-101_v4.4_slot1.mcr \
	tonyhax_scph-101_v4.4_slot2.mcr \
	tonyhax_scph-101_v4.5_slot1.mcr \
	tonyhax_scph-101_v4.5_slot2.mcr \
	tonyhax_scph-102_v4.4_slot1.mcr \
	tonyhax_scph-102_v4.4_slot2.mcr \
	tonyhax_scph-102_v4.5_slot1.mcr \
	tonyhax_scph-102_v4.5_slot2.mcr

# Boot CD files

BOOT_CD_FILES := tonyhax-boot-cd-japan.bin tonyhax-boot-cd-japan.cue tonyhax-boot-cd-europe.bin tonyhax-boot-cd-europe.cue

# ROM files

ROM_FILES := tonyhax-international-$(TONYHAX_VERSION).rom tonyhax-rom-flasher.bin tonyhax-rom-flasher.cue

# XSTATION ROM files

X_ROM_FILES := tonyhax-international-x-$(TONYHAX_VERSION).rom tonyhax-x-rom-flasher.bin tonyhax-x-rom-flasher.cue

# GSHAX Files

GSHAX_FILES := wipeout-usa/wipeout-usa-gshax-code.txt wipeout-usa/CODELIST00 parasite-eve-usa/parasite-eve-usa-gshax-code.txt parasite-eve-usa/CODELIST00 ridge-racer-usa/ridge-racer-usa-gshax-code.txt ridge-racer-usa/CODELIST00

# THIGSGEN Files

THIGSGEN_FILES := linux_x86_64_static/thigsgen linux_x86_static/thigsgen windows_x86_64/thigsgen.exe windows_x86/thigsgen.exe
