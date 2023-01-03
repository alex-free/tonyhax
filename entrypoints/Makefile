
# Thanks to whoever made https://devhints.io/makefile!

# Seek value = offset to start of entry loader, which will be updated on code changes to entry.S

include ../variables.mk

all: $(ENTRY_MCS) $(ENTRY_RAW)

$(ENTRY_RAW): $(ENTRY_MCS)
	bash ../util/mcs2raw.sh $(ENTRY_MCS)

# BES = PAL BAS = USA BIS = JAP

clean:
	$(RM) BES* BAS* BIS* $(ENTRY_MCS) *.elf *.bin FF9-A-JP/BIS* FF9-B-JP/BIS* FF9-A-US/BAS* FF9-B-US/BAS*

# Entry target

entry.elf: entry.S
	$(CC) $(CFLAGS) -DNOPAINT entry.S -o entry.elf

entry.bin: entry.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) -j .text $< $@

# Entry target for Tekken games (no color codes, no error handling, smallest size)

entry-bb.elf: entry.S
	$(CC) $(CFLAGS) -DBAREBONES entry.S -o entry-bb.elf

entry-bb.bin: entry-bb.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) -j .text $< $@

# Entry target for Final Fantasy IX (no color codes, no error handling, smallest size, and different load addr)

entry-ff9.elf: entry.S
	$(CC) $(CFLAGS) -DBAREBONES -DFF9 entry.S -o entry-ff9.elf

entry-ff9.bin: entry-ff9.elf
	$(OBJCOPY) $(OBJCOPYFLAGS) -j .text $< $@

# Brunswick Circuit Pro Bowling NTSC-US target
brunswick1-us.mcs: brunswick1-us-tpl.mcs entry.bin
	cp brunswick1-us-tpl.mcs brunswick1-us.mcs
	dd conv=notrunc if=entry.bin of=brunswick1-us.mcs bs=1 seek=2016

# Brunswick Circuit Pro Bowling PAL-EU target
brunswick1-eu.mcs: brunswick1-eu-tpl.mcs entry.bin
	cp brunswick1-eu-tpl.mcs brunswick1-eu.mcs
	dd conv=notrunc if=entry.bin of=brunswick1-eu.mcs bs=1 seek=2016

# Brunswick Circuit Pro Bowling 2 NTSC-US target
brunswick2-us.mcs: brunswick2-us-tpl.mcs entry.bin
	cp brunswick2-us-tpl.mcs brunswick2-us.mcs
	dd conv=notrunc if=entry.bin of=brunswick2-us.mcs bs=1 seek=2272

# Brunswick Circuit Pro Bowling 2 PAL-EU target
brunswick2-eu.mcs: brunswick2-eu-tpl.mcs entry.bin
	cp brunswick2-eu-tpl.mcs brunswick2-eu.mcs
	dd conv=notrunc if=entry.bin of=brunswick2-eu.mcs bs=1 seek=2272

# Castlevania Chronicles NTSC-J target (rev 0 only)(Alex Free)
cc-jp.mcs: cc-jp-tpl.mcs entry.bin
	cp cc-jp-tpl.mcs cc-jp.mcs
	dd conv=notrunc if=entry.bin of=cc-jp.mcs bs=1 seek=820

# Castlevania Chronicles NTSC-US target
cc-us.mcs: cc-us-tpl.mcs entry.bin
	cp cc-us-tpl.mcs cc-us.mcs
	dd conv=notrunc if=entry.bin of=cc-us.mcs bs=1 seek=820

# Castrol Honda Superbike Racing NTSC-J target (Alex Free)
castrolsb-jp.mcs: castrolsb-jp-tpl.mcs entry.bin
	cp castrolsb-jp-tpl.mcs castrolsb-jp.mcs
	dd conv=notrunc if=entry.bin of=castrolsb-jp.mcs bs=1 seek=1364

# Castrol Honda Superbike Racing NTSC-US target
castrolsb-us.mcs: castrolsb-us-tpl.mcs entry.bin
	cp castrolsb-us-tpl.mcs castrolsb-us.mcs
	dd conv=notrunc if=entry.bin of=castrolsb-us.mcs bs=1 seek=1360

# Castrol Honda Superbike Racing PAL-EU target
castrolsb-eu.mcs: castrolsb-eu-tpl.mcs entry.bin
	cp castrolsb-eu-tpl.mcs castrolsb-eu.mcs
	dd conv=notrunc if=entry.bin of=castrolsb-eu.mcs bs=1 seek=1760

# Castrol Honda VTR NTSC-J target (MottZilla - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867)
	cp castrolvtr-jp-tpl.mcs castrolvtr-jp.mcs
	dd conv=notrunc if=entry.bin of=castrolvtr-jp.mcs bs=1 seek=824	
	../util/successcu -c ./castrolvtr-jp.mcs

# Castrol Honda VTR PAL-EU target
castrolvtr-eu.mcs: castrolvtr-eu-tpl.mcs entry.bin
	cp castrolvtr-eu-tpl.mcs castrolvtr-eu.mcs
	dd conv=notrunc if=entry.bin of=castrolvtr-eu.mcs bs=1 seek=824

# Cool Boarders 4 NTSC-US target
coolbrd4-us.mcs: coolbrd4-us-tpl.mcs entry.bin
	cp coolbrd4-us-tpl.mcs coolbrd4-us.mcs
	dd conv=notrunc if=entry.bin of=coolbrd4-us.mcs bs=1 seek=3428
	bash fix-cb4-checksum.sh coolbrd4-us.mcs

# Cool Boarders 4 PAL-EU target
coolbrd4-eu.mcs: coolbrd4-eu-tpl.mcs entry.bin
	cp coolbrd4-eu-tpl.mcs coolbrd4-eu.mcs
	dd conv=notrunc if=entry.bin of=coolbrd4-eu.mcs bs=1 seek=3428
	bash fix-cb4-checksum.sh coolbrd4-eu.mcs

# Crash Bandicoot 2 NTSC-US target
crash2-us.mcs: crash2-us-tpl.mcs entry.bin
	cp crash2-us-tpl.mcs crash2-us.mcs
	dd conv=notrunc if=entry.bin of=crash2-us.mcs bs=1 seek=688
	bash fix-crash-checksum.sh crash2-us.mcs us2

# Crash Bandicoot 2 NTSC-J target (MottZilla - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867)
crash2-jp.mcs: crash2-jp-tpl.mcs entry.bin
	cp crash2-jp-tpl.mcs crash2-jp.mcs
	dd conv=notrunc if=entry.bin of=crash2-jp.mcs bs=1 seek=688
	bash fix-crash-checksum.sh crash2-jp.mcs us2

# Crash Bandicoot 2 PAL-EU target
# redump.org lists two versions of this game: with and without EDC
# This was tested with the non-EDC version (hash b077862d2c6e1b8060c2eae2fe82e708b228de7c)
# Not sure if it works on the EDC one
crash2-eu.mcs: crash2-eu-tpl.mcs entry.bin
	cp crash2-eu-tpl.mcs crash2-eu.mcs
	dd conv=notrunc if=entry.bin of=crash2-eu.mcs bs=1 seek=432
	bash fix-crash-checksum.sh crash2-eu.mcs eu2

# Crash Bandicoot 3 NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
crash3-jp.mcs: crash3-jp-tpl.mcs entry.bin
	cp crash3-jp-tpl.mcs crash3-jp.mcs
	dd conv=notrunc if=entry.bin of=crash3-jp.mcs bs=1 seek=688
	bash fix-crash-checksum.sh crash3-jp.mcs us3

# Crash Bandicoot 3 NTSC-US target
crash3-us.mcs: crash3-us-tpl.mcs entry.bin
	cp crash3-us-tpl.mcs crash3-us.mcs
	dd conv=notrunc if=entry.bin of=crash3-us.mcs bs=1 seek=688
	bash fix-crash-checksum.sh crash3-us.mcs us3

# Crash Bandicoot 3 PAL-EU target
crash3-eu.mcs: crash3-eu-tpl.mcs entry.bin
	cp crash3-eu-tpl.mcs crash3-eu.mcs
	dd conv=notrunc if=entry.bin of=crash3-eu.mcs bs=1 seek=432
	bash fix-crash-checksum.sh crash3-eu.mcs eu3

# Doki Oki NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
dokiou-ki-jp.mcs: dokiou-ki-jp-tpl.mcs entry.bin
	cp dokiou-ki-jp-tpl.mcs dokiou-ki-jp.mcs
	dd conv=notrunc if=entry.bin of=dokiou-ki-jp.mcs bs=1 seek=896

# Downhill Snow NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
downhill-snow-jp.mcs: downhill-snow-jp-tpl.mcs entry.bin
	cp downhill-snow-jp-tpl.mcs downhill-snow-jp.mcs
	dd conv=notrunc if=entry.bin of=downhill-snow-jp.mcs bs=1 seek=1780

# Final Fantasy IX Disc 1 CEX-1000 BIOS 1.0-2.0 NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
FF9-A-JP/ff9-a-jp.mcs: FF9-A-JP/ff9-a-jp-tpl.mcs entry-ff9.bin
	cp FF9-A-JP/ff9-a-jp-tpl.mcs FF9-A-JP/ff9-a-jp.mcs
	dd conv=notrunc if=entry-ff9.bin of=FF9-A-JP/ff9-a-jp.mcs bs=1 seek=132

# Final Fantasy IX Disc 1 BIOS 2.1 and above NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
FF9-B-JP/ff9-b-jp.mcs: FF9-B-JP/ff9-b-jp-tpl.mcs entry-ff9.bin
	cp FF9-B-JP/ff9-b-jp-tpl.mcs FF9-B-JP/ff9-b-jp.mcs
	dd conv=notrunc if=entry-ff9.bin of=FF9-B-JP/ff9-b-jp.mcs bs=1 seek=132

# Final Fantasy IX Disc 1 CEX-1000 BIOS 1.0-2.0 NTSC-U target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
FF9-A-US/ff9-a-us.mcs: FF9-A-US/ff9-a-us-tpl.mcs entry-ff9.bin
	cp FF9-A-US/ff9-a-us-tpl.mcs FF9-A-US/ff9-a-us.mcs
	dd conv=notrunc if=entry-ff9.bin of=FF9-A-US/ff9-a-us.mcs bs=1 seek=132

# Final Fantasy IX Disc 1 BIOS 2.1 and above NTSC-U target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
FF9-B-US/ff9-b-us.mcs: FF9-B-US/ff9-b-us-tpl.mcs entry-ff9.bin
	cp FF9-B-US/ff9-b-us-tpl.mcs FF9-B-US/ff9-b-us.mcs
	dd conv=notrunc if=entry-ff9.bin of=FF9-B-US/ff9-b-us.mcs bs=1 seek=132

# The Legend Of Heroes I&II NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)
the-legend-of-heroes-1-and-2-jp.mcs: the-legend-of-heroes-1-and-2-jp-tpl.mcs entry.bin
	cp the-legend-of-heroes-1-and-2-jp-tpl.mcs the-legend-of-heroes-1-and-2-jp.mcs
	dd conv=notrunc if=entry.bin of=the-legend-of-heroes-1-and-2-jp.mcs bs=1 seek=216

# Sports Superbike PAL-EU target
superbike1-eu.mcs: superbike1-eu-tpl.mcs entry.bin
	cp superbike1-eu-tpl.mcs superbike1-eu.mcs
	dd conv=notrunc if=entry.bin of=superbike1-eu.mcs bs=1 seek=1888

# Sports Superbike 2 PAL-EU target
superbike2-eu.mcs: superbike2-eu-tpl.mcs entry.bin
	cp superbike2-eu-tpl.mcs superbike2-eu.mcs
	dd conv=notrunc if=entry.bin of=superbike2-eu.mcs bs=1 seek=824

# Tekken 2 NTSC-J target (rev 1 only) (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714) ( krystalgamer - https://github.com/socram8888/tonyhax/pull/20)
tekken2-jp.mcs: tekken2-jp-tpl.mcs entry-bb.bin
	cp tekken2-jp-tpl.mcs tekken2-jp.mcs
	python3 ../util/tekken_decoder.py tekken2-jp.mcs tekken2-jp-decoded.bin
	dd conv=notrunc if=entry-bb.bin of=tekken2-jp-decoded.bin bs=1 seek=44
	python3 ../util/tekken_encoder.py tekken2-jp.mcs tekken2-jp-decoded.bin tekken2-jp.mcs
	rm tekken2-jp-decoded.bin

# Tekken 2 NTSC-U target (rev 0 only) (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714) ( krystalgamer - https://github.com/socram8888/tonyhax/pull/20)
tekken2-us.mcs: tekken2-us-tpl.mcs entry-bb.bin
	cp tekken2-us-tpl.mcs tekken2-us.mcs
	python3 ../util/tekken_decoder.py tekken2-us.mcs tekken2-us-decoded.bin
	dd conv=notrunc if=entry-bb.bin of=tekken2-us-decoded.bin bs=1 seek=44
	python3 ../util/tekken_encoder.py tekken2-us.mcs tekken2-us-decoded.bin tekken2-us.mcs
	rm tekken2-us-decoded.bin

# Tekken 2 PAL target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714) ( krystalgamer - https://github.com/socram8888/tonyhax/pull/20)
tekken2-eu.mcs: tekken2-eu-tpl.mcs entry-bb.bin
	cp tekken2-eu-tpl.mcs tekken2-eu.mcs
	python3 ../util/tekken_decoder.py tekken2-eu.mcs tekken2-eu-decoded.bin
	dd conv=notrunc if=entry-bb.bin of=tekken2-eu-decoded.bin bs=1 seek=44
	python3 ../util/tekken_encoder.py tekken2-eu.mcs tekken2-eu-decoded.bin tekken2-eu.mcs
	rm tekken2-eu-decoded.bin

#Tekken 3 NTSC-J target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714) ( krystalgamer - https://github.com/socram8888/tonyhax/pull/20)
tekken3-jp.mcs: tekken3-jp-tpl.mcs entry-bb.bin
	cp tekken3-jp-tpl.mcs tekken3-jp.mcs
	python3 ../util/tekken_decoder.py tekken3-jp.mcs tekken3-jp-decoded.bin
	dd conv=notrunc if=entry-bb.bin of=tekken3-jp-decoded.bin bs=1 seek=72
	python3 ../util/tekken_encoder.py tekken3-jp.mcs tekken3-jp-decoded.bin tekken3-jp.mcs
	rm tekken3-jp-decoded.bin

#Tekken 3 NTSC-U target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714) ( krystalgamer - https://github.com/socram8888/tonyhax/pull/20)
tekken3-us.mcs: tekken3-us-tpl.mcs entry-bb.bin
	cp tekken3-us-tpl.mcs tekken3-us.mcs
	python3 ../util/tekken_decoder.py tekken3-us.mcs tekken3-us-decoded.bin
	dd conv=notrunc if=entry-bb.bin of=tekken3-us-decoded.bin bs=1 seek=72
	python3 ../util/tekken_encoder.py tekken3-us.mcs tekken3-us-decoded.bin tekken3-us.mcs
	rm tekken3-us-decoded.bin

#Tekken 3 PAL target (Patchouli (karehaani) - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714) ( krystalgamer - https://github.com/socram8888/tonyhax/pull/20)
tekken3-eu.mcs: tekken3-eu-tpl.mcs entry-bb.bin
	cp tekken3-eu-tpl.mcs tekken3-eu.mcs
	python3 ../util/tekken_decoder.py tekken3-eu.mcs tekken3-eu-decoded.bin
	dd conv=notrunc if=entry-bb.bin of=tekken3-eu-decoded.bin bs=1 seek=72
	python3 ../util/tekken_encoder.py tekken3-eu.mcs tekken3-eu-decoded.bin tekken3-eu.mcs
	rm tekken3-eu-decoded.bin

# THPS2 NTSC-J target (MottZilla - http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867)
thps2-jp.mcs: thps2-jp-tpl.mcs entry.bin
	cp thps2-jp-tpl.mcs thps2-jp.mcs
	dd conv=notrunc if=entry.bin of=thps2-jp.mcs bs=1 seek=5336
	../util/successcu -t ./thps2-jp.mcs

# THPS2 NTSC-US target
thps2-us.mcs: thps2-us-tpl.mcs entry.bin
	cp thps2-us-tpl.mcs thps2-us.mcs
	dd conv=notrunc if=entry.bin of=thps2-us.mcs bs=1 seek=5208

# THPS2 PAL-EU target
thps2-eu.mcs: thps2-eu-tpl.mcs entry.bin
	cp thps2-eu-tpl.mcs thps2-eu.mcs
	dd conv=notrunc if=entry.bin of=thps2-eu.mcs bs=1 seek=5200

# THPS2 PAL-DE target
thps2-de.mcs: thps2-de-tpl.mcs entry.bin
	cp thps2-de-tpl.mcs thps2-de.mcs
	dd conv=notrunc if=entry.bin of=thps2-de.mcs bs=1 seek=5200

# THPS2 PAL-FR target
thps2-fr.mcs: thps2-fr-tpl.mcs entry.bin
	cp thps2-fr-tpl.mcs thps2-fr.mcs
	dd conv=notrunc if=entry.bin of=thps2-fr.mcs bs=1 seek=5200

# THPS3 NTSC-US target
thps3-us.mcs: thps3-us-tpl.mcs entry.bin
	cp thps3-us-tpl.mcs thps3-us.mcs
	dd conv=notrunc if=entry.bin of=thps3-us.mcs bs=1 seek=4612

# THPS3 PAL-EU target
thps3-eu.mcs: thps3-eu-tpl.mcs entry.bin
	cp thps3-eu-tpl.mcs thps3-eu.mcs
	dd conv=notrunc if=entry.bin of=thps3-eu.mcs bs=1 seek=4608

# THPS3 PAL-DE target
thps3-de.mcs: thps3-de-tpl.mcs entry.bin
	cp thps3-de-tpl.mcs thps3-de.mcs
	dd conv=notrunc if=entry.bin of=thps3-de.mcs bs=1 seek=4608

# THPS3 PAL-FR target
thps3-fr.mcs: thps3-fr-tpl.mcs entry.bin
	cp thps3-fr-tpl.mcs thps3-fr.mcs
	dd conv=notrunc if=entry.bin of=thps3-fr.mcs bs=1 seek=4608

# THPS4 NTSC-US target
thps4-us.mcs: thps4-us-tpl.mcs entry.bin
	cp thps4-us-tpl.mcs thps4-us.mcs
	dd conv=notrunc if=entry.bin of=thps4-us.mcs bs=1 seek=5260

# THPS4 PAL-EU target
thps4-eu.mcs: thps4-eu-tpl.mcs entry.bin
	cp thps4-eu-tpl.mcs thps4-eu.mcs
	dd conv=notrunc if=entry.bin of=thps4-eu.mcs bs=1 seek=5252

# THPS4 PAL-DE target
thps4-de.mcs: thps4-de-tpl.mcs entry.bin
	cp thps4-de-tpl.mcs thps4-de.mcs
	dd conv=notrunc if=entry.bin of=thps4-de.mcs bs=1 seek=5252

# THPS4 PAL-FR target
thps4-fr.mcs: thps4-fr-tpl.mcs entry.bin
	cp thps4-fr-tpl.mcs thps4-fr.mcs
	dd conv=notrunc if=entry.bin of=thps4-fr.mcs bs=1 seek=5252

# XS Moto NTSC-US target
xsmoto-us.mcs: xsmoto-us-tpl.mcs entry.bin
	cp xsmoto-us-tpl.mcs xsmoto-us.mcs
	dd conv=notrunc if=entry.bin of=xsmoto-us.mcs bs=1 seek=1760

# XS Moto PAL-EU target
xsmoto-eu.mcs: xsmoto-eu-tpl.mcs entry.bin
	cp xsmoto-eu-tpl.mcs xsmoto-eu.mcs
	dd conv=notrunc if=entry.bin of=xsmoto-eu.mcs bs=1 seek=1760
