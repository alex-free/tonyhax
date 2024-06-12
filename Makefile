
# Thanks to whoever made https://devhints.io/makefile!

include variables-shared.mk

PACKAGE_FILE = tonyhax-international-$(TONYHAX_VERSION).zip
PACKAGE_CONTENTS = $(ENTRY_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/entrypoints/%) $(ROM_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/rom/%) $(X_ROM_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/xstation/%) $(LOADER_OUTPUT_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/loader/%) $(FREEPSXBOOT_IMAGES:%=tonyhax-international-$(TONYHAX_VERSION)/freepsxboot/%) $(BOOT_CD_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/boot-cd/%) $(GSHAX_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/gshax/%) $(ENTRY_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/entrypoints/%) $(THIGSGEN_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/gameshark/*%) tonyhax-international-$(TONYHAX_VERSION)/*.md tonyhax-international-$(TONYHAX_VERSION)/LICENSE tonyhax-international-$(TONYHAX_VERSION)/images/*

.PHONY: clean modules clean

all: modules $(PACKAGE_FILE)

# zip a directory of files, not files themselves
$(PACKAGE_FILE): $(PACKAGE_CONTENTS) 
	$(RM) $(PACKAGE_FILE)
	cd ../; cp -r tonyhax tonyhax-international-$(TONYHAX_VERSION); zip -9 tonyhax/$(PACKAGE_FILE) $(PACKAGE_CONTENTS); yes | rm -r tonyhax-international-$(TONYHAX_VERSION)

$(PACKAGE_CONTENTS):

modules:
	$(MAKE) -C util
	$(MAKE) -C entrypoints all
	$(MAKE) -C thigsgen all
	cd gameshark && unzip -q '*.zip'
	$(MAKE) -C gshax all
	$(MAKE) -C loader clean	
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
	$(MAKE) -C thigsgen clean-build
	scripts/test-thigsgen.sh --clean
	$(MAKE) -C gshax clean
	$(RM) tonyhax-*.zip

deps:
	scripts/get-deps.sh
	$(MAKE) -C pcsx-redux-support clean tools
	cd mkpsxiso; rm -rf ./build; cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release; cmake --build ./build
	cd psexe2rom; $(MAKE) clean; $(MAKE)

clean-deps:
	$(MAKE) -C pcsx-redux-support clean
	cd mkpsxiso; rm -rf ./build
	cd psexe2rom; $(MAKE) clean