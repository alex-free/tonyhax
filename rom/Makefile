
# Thanks to whoever made https://devhints.io/makefile!

include ../variables.mk

.PHONY: clean

all: $(ROM_FILES)

clean:
	$(RM) $(ROM_FILES)

$(ROM_FILES): ../loader/tonyhax.exe cd-e.xml cd-j.xml licensee.dat licensej.dat ../nxflash/CDFILES/system.cnf
	cd ../psexe2rom; make clean; make; ./psexe2rom ../loader/tonyhax.exe ../nxflash/tonyhax-$(TONYHAX_VERSION).rom; cd ../nxflash; wine romfile.exe; cp -r romfile.dat CDFILES/system.cnf NXFLASH.EXE tonyhax-$(TONYHAX_VERSION).rom ../rom; cd ../rom; mkpsxiso -y cd-e.xml; mkpsxiso -y cd-j.xml; rm -rf NXFLASH.EXE system.cnf romfile.dat ../nxflash/romfile.dat ../nxflash/tonyhax-$(TONYHAX_VERSION).rom
