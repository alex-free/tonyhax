
# Thanks to whoever made https://devhints.io/makefile!

include ../variables-shared.mk

LOADER_AUTOGEN := orca.inc
LOADER_HEADERS := $(wildcard *.h) $(LOADER_AUTOGEN)
LOADER_OBJECTS := $(patsubst %.c, %.o, $(patsubst %.S, %.o, $(wildcard *.c *.S)))

all: $(LOADER_FILES)

clean:
	$(RM) $(LOADER_FILES) *.o *.elf *.raw $(LOADER_AUTOGEN)

# Intermediate objects

%.o: %.c $(LOADER_HEADERS)
	$(CC) $(CFLAGS) -c $<

%.o: %.S $(LOADER_HEADERS)
	$(CC) $(CFLAGS) -c $<

orca.inc: orca.img
	bash ../util/bin2h.sh ORCA_IMAGE orca.img orca.inc

secondary.elf: secondary.ld $(LOADER_OBJECTS)
	$(LD) $(LDFLAGS) -T secondary.ld $(LOADER_OBJECTS) -o $@
	bash insert-tonyhax-crc.sh secondary.elf

# Results

tonyhax.mcs: secondary.elf
	../pcsx-redux-support/ps1-packer secondary.elf -tload 0x801F2300 -raw -o secondary.raw
	bash generate-tonyhax-mcs.sh secondary.raw tonyhax-tpl-16kb.mcs tonyhax.mcs $(TONYHAX_VERSION)

HAX: tonyhax.mcs
	bash ../util/mcs2raw.sh tonyhax.mcs

tonyhax.exe: secondary.elf
	../pcsx-redux-support/ps1-packer secondary.elf -tload 0x801F2300 -o tonyhax.exe
