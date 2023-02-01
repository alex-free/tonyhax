
# Thanks to whoever made https://devhints.io/makefile!

include ../variables.mk

.PHONY: clean

all: gshax wipeout-usa

clean:
	$(RM) wipeout-usa/*.txt wipeout-usa/CODELIST00

gshax: ../entrypoints/entry-bb.bin
	cd ../gshax-tool; make clean; make; 
	
wipeout-usa: gshax
	../gshax-tool/gshax -g 801FBDC8 8006C2C4 800CBA70 ../entrypoints/entry-bb.bin 0xb4 wipeout-usa/CODELIST00; ../gshax-tool/gshax -t 801FBDC8 8006C2C4 800CBA70 ../entrypoints/entry-bb.bin 0xb4 wipeout-usa/wipeout-usa-gshax-code.txt
