
.PHONY: clean

all: gshax-tool wipeout-usa parasite-eve-usa

clean:
	$(RM) wipeout-usa/wipeout-usa-gshax-code.txt wipeout-usa/CODELIST00 parasite-eve-usa/parasite-eve-usa-gshax-code.txt parasite-eve-usa/CODELIST00

gshax-tool: ../entrypoints/entry-bb.bin
	cd ../gshax-tool; make clean; make 
	
wipeout-usa: gshax-tool
	../gshax-tool/gshax -g 801FBDC8 8006C2C4 800CBA70 ../entrypoints/entry-bb.bin 0xb4 wipeout-usa/CODELIST00; ../gshax-tool/gshax -t 801FBDC8 8006C2C4 800CBA70 ../entrypoints/entry-bb.bin 0xb4 wipeout-usa/wipeout-usa-gshax-code.txt

parasite-eve-usa: gshax-tool
	../gshax-tool/gshax -g 80073BBC ../entrypoints/entry-bb.bin 0xb4 parasite-eve-usa/CODELIST00; ../gshax-tool/gshax -t 80073BBC ../entrypoints/entry-bb.bin 0xb4 parasite-eve-usa/parasite-eve-usa-gshax-code.txt
#80073BBC