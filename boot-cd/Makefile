
# Thanks to whoever made https://devhints.io/makefile!

include ../variables.mk
include ../variables-shared.mk

.PHONY: clean

all: $(BOOT_CD_FILES)

clean:
	$(RM) $(BOOT_CD_FILES)

$(BOOT_CD_FILES): ../loader/tonyhax.exe cd-e.xml cd-j.xml licensee.dat licensej.dat system.cnf
	mkpsxiso -y cd-e.xml; mkpsxiso -y cd-j.xml
