
# Thanks to whoever made https://devhints.io/makefile!

include variables.mk

PACKAGE_FILE = tonyhax-$(TONYHAX_VERSION).zip
PACKAGE_CONTENTS = $(ENTRY_FILES:%=entrypoints/%) $(ROM_FILES:%=rom/%) $(LOADER_FILES:%=loader/%) $(FREEPSXBOOT_IMAGES:%=freepsxboot/%) $(BOOT_CD_FILES:%=boot-cd/%) $(BOOT_CD_FILES:%=boot-cd/%) readme.html images/*.jpg readme.md LICENSE

.PHONY: clean modules clean

all: modules $(PACKAGE_FILE)

$(PACKAGE_FILE): $(PACKAGE_CONTENTS)
	$(RM) $(PACKAGE_FILE)
	zip -9 $(PACKAGE_FILE) $(PACKAGE_CONTENTS)

$(PACKAGE_CONTENTS): modules

modules:
	$(MAKE) -C entrypoints/successcu
	$(MAKE) -C entrypoints all
	$(MAKE) -C loader -f Makefile.freepsxboot all
	$(MAKE) -C freepsxboot all
	$(MAKE) -C loader clean
	$(MAKE) -C loader all
	$(MAKE) -C boot-cd all
	$(MAKE) -C rom all

clean:
	$(MAKE) -C entrypoints/successcu clean
	$(MAKE) -C entrypoints clean
	$(MAKE) -C loader clean
	$(MAKE) -C freepsxboot clean
	$(MAKE) -C boot-cd clean
	$(MAKE) -C rom clean
	$(RM) tonyhax-*.zip
