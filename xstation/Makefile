
# Thanks to whoever made https://devhints.io/makefile!

include ../variables-shared.mk

.PHONY: clean

all: $(X_ROM_FILES)

clean:
	$(RM) $(X_ROM_FILES)

$(X_ROM_FILES): ../loader/tonyhax.exe cd.xml ../boot-cd/licensej.dat ../nxflash/CDFILES/system.cnf
	rm -f romfile.dat; rm -f ../xstation/tonyhax-international-x-$(TONYHAX_VERSION).rom; ./psexe2rom -d ../loader/tonyhax.exe ../xstation/tonyhax-international-x-$(TONYHAX_VERSION).rom; cp -r ../psexe2rom/romfile.dat ../boot-cd/licensej.dat ../nxflash/CDFILES/system.cnf ../nxflash/NXFLASH.EXE ../xstation; cd ../xstation; mkpsxiso -y cd.xml; rm -rf romfile.dat NXFLASH.EXE licensej.dat system.cnf ../psexe2rom/romfile.dat ../nxflash/tonyhax-international-x$(TONYHAX_VERSION).rom
