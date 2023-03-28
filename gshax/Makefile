
.PHONY: clean

all: gshax-tool wipeout-usa parasite-eve-usa ridge-racer-usa

clean:
	$(RM) wipeout-usa/wipeout-usa-gshax-code.txt wipeout-usa/CODELIST00 parasite-eve-usa/parasite-eve-usa-gshax-code.txt parasite-eve-usa/CODELIST00 ridge-racer-usa/ridge-racer-usa-gshax-code.txt ridge-racer-usa/CODELIST00

gshax-tool: ../entrypoints/entry-bb.bin
	cd ../gshax-tool; make clean; make 
	
wipeout-usa: gshax-tool
	../gshax-tool/gshax -g 8005798C -jal 8006C68C 8007E864 ../entrypoints/entry-bb.bin 0xb4 wipeout-usa/CODELIST00; ../gshax-tool/gshax -t 8005798C -jal 8006C68C 8007E864 ../entrypoints/entry-bb.bin 0xb4 wipeout-usa/wipeout-usa-gshax-code.txt

parasite-eve-usa: gshax-tool
	../gshax-tool/gshax -g 8018FAC8 -j 8018FB78 80193288 ../entrypoints/entry-bb.bin 0xb4 parasite-eve-usa/CODELIST00; ../gshax-tool/gshax -t 8018FAC8 -j 8018FB78 80193288 ../entrypoints/entry-bb.bin 0xb4 parasite-eve-usa/parasite-eve-usa-gshax-code.txt

ridge-racer-usa: gshax-tool
	../gshax-tool/gshax -g 8004EB1C -j 8004EB54 8007FA30 ../entrypoints/entry-bb.bin 0xb4 ridge-racer-usa/CODELIST00; ../gshax-tool/gshax -t 8004EB1C -j 8004EB54 8007FA30 ../entrypoints/entry-bb.bin 0xb4 ridge-racer-usa/ridge-racer-usa-gshax-code.txt