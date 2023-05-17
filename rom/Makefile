
# Thanks to whoever made https://devhints.io/makefile!

include ../variables.mk

.PHONY: clean

all: $(ROM_FILES)

clean:
	$(RM) $(ROM_FILES)

$(ROM_FILES): ../loader/tonyhax.exe cd.xml ../boot-cd/licensej.dat ../nxflash/CDFILES/system.cnf
	cd ../psexe2rom; make clean; make; rm -f romfile.dat; ./psexe2rom -d ../loader/tonyhax.exe ../rom/tonyhax-international-$(TONYHAX_VERSION).rom; cp -r ../psexe2rom/romfile.dat ../boot-cd/licensej.dat ../nxflash/CDFILES/system.cnf ../nxflash/NXFLASH.EXE ../rom; cd ../rom; mkpsxiso -y cd.xml; rm -rf romfile.dat NXFLASH.EXE licensej.dat system.cnf ../psexe2rom/romfile.dat ../nxflash/tonyhax-international-$(TONYHAX_VERSION).rom
