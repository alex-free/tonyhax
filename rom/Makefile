
# Thanks to whoever made https://devhints.io/makefile!

include ../variables-shared.mk

.PHONY: clean

all: $(ROM_FILES)

clean:
	$(RM) romfile.dat $(ROM_FILES)

$(ROM_FILES): 
	../psexe2rom/psexe2rom -d ../loader/tonyhax.exe tonyhax-international-$(TONYHAX_VERSION).rom; ../mkpsxiso/build/mkpsxiso -y cd.xml; rm romfile.dat 
