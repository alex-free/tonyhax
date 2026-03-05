
# Thanks to whoever made https://devhints.io/makefile!

include variables-shared.mk

PACKAGE_FILE = tonyhax-international-$(TONYHAX_VERSION).zip
PACKAGE_CONTENTS = $(ENTRY_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/entrypoints/%) $(ROM_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/rom/%) $(X_ROM_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/xstation/%) $(LOADER_OUTPUT_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/loader/%) $(FREEPSXBOOT_IMAGES:%=tonyhax-international-$(TONYHAX_VERSION)/freepsxboot/%) $(BOOT_CD_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/boot-cd/%) $(GSHAX_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/gshax/%) $(ENTRY_FILES:%=tonyhax-international-$(TONYHAX_VERSION)/entrypoints/%) tonyhax-international-$(TONYHAX_VERSION)/*.md tonyhax-international-$(TONYHAX_VERSION)/LICENSE tonyhax-international-$(TONYHAX_VERSION)/images/*

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
	$(MAKE) -C gshax clean
	$(RM) tonyhax-*.zip

deps:
	echo "Info: root privileges are required to install build dependencies.";
	@if [ "$(shell uname)" = "Linux" ]; then \
		echo "Linux detected."; \
		if command -v dnf > /dev/null; then \
			echo "Using dnf"; \
			sudo dnf -y install git autoconf automake g++ make libtool zlib-static magic_enum-devel texinfo help2man ncurses-devel tinyxml2-devel cmake cdrdao python libstdc++-static python3-numpy; \
		elif command -v apt > /dev/null; then \
			echo "Using apt"; \
			sudo apt install --yes build-essential libtinyxml2-dev git cmake cdrdao python3 python3-pip pipx autoconf texinfo help2man gawk libtool-bin libtool libmagicenum-dev ncurses-dev python3-numpy zip dpkg-dev; \
		else \
			echo "A Linux distro with DNF or the APT package manager was not found. The make deps rule requires one of these package managers to automatically install all of the required build dependencies."; \
		fi; \
	fi
	$(MAKE) -C pcsx-redux-support clean tools
	cd mkpsxiso; rm -rf ./build; cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release; cmake --build ./build
	cd psexe2rom; $(MAKE) clean; $(MAKE)

toolchain:
	psn00bsdk-builder/build.sh

clean-deps:
	$(MAKE) -C pcsx-redux-support clean
	cd mkpsxiso; rm -rf ./build
	cd psexe2rom; $(MAKE) clean