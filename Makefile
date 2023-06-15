
# Thanks to whoever made https://devhints.io/makefile!

include variables.mk
include variables-shared.mk

PACKAGE_FILE = tonyhax-international-$(TONYHAX_VERSION).zip
PACKAGE_CONTENTS = $(ENTRY_FILES:%=entrypoints/%) $(ROM_FILES:%=rom/%) $(X_ROM_FILES:%=xstation/%) $(LOADER_OUTPUT_FILES:%=loader/%) $(FREEPSXBOOT_IMAGES:%=freepsxboot/%) $(BOOT_CD_FILES:%=boot-cd/%) $(GSHAX_FILES:%=gshax/%) $(THIGSGEN_FILES:%=gameshark/%) *.md LICENSE images/*

.PHONY: clean modules clean

all: modules $(PACKAGE_FILE)

$(PACKAGE_FILE): $(PACKAGE_CONTENTS) 
	$(RM) $(PACKAGE_FILE)
	zip -9 $(PACKAGE_FILE) $(PACKAGE_CONTENTS)

$(PACKAGE_CONTENTS):

modules:
	$(MAKE) -C util
	$(MAKE) -C entrypoints all
	$(MAKE) -C gameshark all
	$(MAKE) -C gshax all
	
	$(MAKE) -C loader -f Makefile.freepsxboot all
	$(MAKE) -C freepsxboot all
	$(MAKE) -C loader clean

	$(MAKE) -C loader -f Makefile.rom all
	$(MAKE) -C rom all
	$(MAKE) -C loader clean

	$(MAKE) -C loader -f Makefile.xstation all
	$(MAKE) -C xstation all
	$(MAKE) -C loader clean

	$(MAKE) -C loader -f Makefile.ff9 all
	$(MAKE) -C loader clean
	
	$(MAKE) -C loader all
	$(MAKE) -C boot-cd all

clean:
	$(MAKE) -C util clean
	$(MAKE) -C gshax-tool clean
	$(MAKE) -C entrypoints clean
	$(MAKE) -C loader clean
	$(MAKE) -C loader -f Makefile.ff9 clean
	$(MAKE) -C freepsxboot clean
	$(MAKE) -C boot-cd clean
	$(MAKE) -C rom clean
	$(MAKE) -C xstation clean
	$(MAKE) -C gameshark clean
	$(MAKE) -C gshax clean
	$(RM) tonyhax-*.zip
