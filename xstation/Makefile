
# Thanks to whoever made https://devhints.io/makefile!

include ../variables-shared.mk

.PHONY: clean

all: $(X_ROM_FILES)

clean:
	$(RM) romfile.dat $(X_ROM_FILES)

$(X_ROM_FILES): 
	../psexe2rom/psexe2rom -d ../loader/tonyhax.exe tonyhax-international-x-$(TONYHAX_VERSION).rom; ../mkpsxiso/build/mkpsxiso -y cd.xml; rm romfile.dat 
