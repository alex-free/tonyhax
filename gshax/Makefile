
# Thanks to whoever made https://devhints.io/makefile!

include ../variables.mk

.PHONY: clean

all: $(GSHAX_FILES)

clean:
	$(RM) $(GSHAX_FILES) gshax wipeout-usa/wipeout-usa-gshax-code.txt

gshax: ../entrypoints/entry-bb.bin
	rm -f gshax; gcc gshax.c -o gshax; 
	
wipeout-usa-gshax-code.txt: gshax
	cp wipeout-usa-gshax-code-tpl.txt wipeout-usa/wipeout-usa-gshax-code.txt; ./gshax 800CBA70 ../entrypoints/entry-bb.bin >> wipeout-usa/wipeout-usa-gshax-code.txt; truncate -s `head -94 wipeout-usa/wipeout-usa-gshax-code.txt | wc -c` wipeout-usa/wipeout-usa-gshax-code.txt