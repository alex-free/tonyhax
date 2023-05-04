
# Thanks to whoever made https://devhints.io/makefile!

include variables.mk

PACKAGE_FILE = tonyhax-$(TONYHAX_VERSION).zip
PACKAGE_CONTENTS = $(ENTRY_FILES:%=entrypoints/%) $(ROM_FILES:%=rom/%) loader/HAX loader/FF9 loader/tonyhax.mcs loader/tonyhax-ff9.mcs loader/tonyhax.exe $(FREEPSXBOOT_IMAGES:%=freepsxboot/%) $(BOOT_CD_FILES:%=boot-cd/%) gshax/wipeout-usa/wipeout-usa-gshax-code.txt gshax/wipeout-usa/CODELIST00 gshax/parasite-eve-usa/parasite-eve-usa-gshax-code.txt gshax/parasite-eve-usa/CODELIST00 gshax/ridge-racer-usa/ridge-racer-usa-gshax-code.txt gshax/ridge-racer-usa/CODELIST00 gameshark/linux_x86_64_static/thigsgen gameshark/linux_x86_static/thigsgen gameshark/windows_x86_64/thigsgen.exe gameshark/windows_x86/thigsgen.exe *.md images/* LICENSE

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
	
	$(MAKE) -C loader -f Makefile.freepsxboot all
	$(MAKE) -C freepsxboot all
	$(MAKE) -C loader clean

	$(MAKE) -C loader -f Makefile.rom all
	$(MAKE) -C rom all
	$(MAKE) -C loader clean

	$(MAKE) -C loader -f Makefile.ff9 all
	$(MAKE) -C loader clean
	
	$(MAKE) -C loader all
	$(MAKE) -C boot-cd all
	$(MAKE) -C gshax all

clean:
	$(MAKE) -C util clean
	$(MAKE) -C entrypoints clean
	$(MAKE) -C loader clean
	$(MAKE) -C loader -f Makefile.ff9 clean
	$(MAKE) -C freepsxboot clean
	$(MAKE) -C boot-cd clean
	$(MAKE) -C rom clean
	$(MAKE) -C gameshark clean
	$(MAKE) -C gshax clean
	$(RM) tonyhax-*.zip
