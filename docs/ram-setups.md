# RAM Layouts

These are notes for mostly myself to not forget how to increase the size of the loader :)

## Files To Update When Switching Layouts:

*   `entrypoints/entry.S` (temp buffer address)
*   `loader/tonyhax-tpl.mcs` (if number of linked slots in save file is changed).
*   `loader/tonyhax-tpl-ff9.mcs` (if number of linked slots in save file is changed)
*   `loader/secondary.ld` (origin, length, sections)
*   `loader/generate-tonyhax-mcs.sh`(ro_start)
*   `loader/Makefile` (start addr)
*   `loader/Makefile.ff9` (start addr)

## General Notes:

*   As of right now to store the loader on the memory card is only taking up 2 slots (1 linked slot)! Incredible, considering the original Tonyhax is also taking up the same (due to no compression teqnique in the original). In the future if the compressed size gets above the capacity of 2 slots, more slots can be added easily by changing to a larger template `-tpl.mcs` file, I've already created them for when compression was not used before.

*   A 'gotcha!' to look out for is in the anti-piracy bypass system. Some bootfile matches are expecting the PS-EXE to always already be loaded at the time of `activate_anti_anti_piracy()` being called in order to do revision detection. This won't happen if the PS-EXE overlaps the tonyhax executable running... Revision detection is looking at the first different byte between revisions to determine what version the game is, since they share the same boot file name. As of right now no conflicts have occured, as in every game needing revision detection that also contain some bypassed anti-piracy are being loaded fully into user ram (via `exec()` codepath), fitting nicely without conflict and no need of `loadandexec()` to load and exec in place over any of the actual tonyhax executable (which is always in the highest possible RAM location according to layout provision). Whenever this (if ever) leads to a conflict, I'll need to write a function to partially load the exe to a size that still allows revision detection to some temp buffer. Any conflict could occur first for the Final Fantasy 9 exploit since you get slightly less user ram to work with.

## Layout 1: Tonyhax OG/Tonyhax International v1.0-v1.1.0

The original Tonyhax loader (and International v1.0-v1.1.0) was setup like this (original size limit):
Load Address: 0x801FA100
Executable max length: 0x3F00 (0x801FE000 is the maximum)
This fits in a memory card file with one 'linked slot' shown in memcardrex.

## Layout 2: Tonyhax International v1.1.1-v1.2.9

Tonyhax International v1.1.1-1.2.9 increased in size past the original 0x3F00 maximum executable limit, so it was changed to increase the maximum executable size to 0x5E80. 0x3F00 / 2 = 0x1F80, 0x1F80 + 0x3F00 = 0x5E80 which is 1.5x the original size limit. The larger maximum executable size means that the Tonyhax International loader must be placed lower in memory.
Load Address: 0x801F8180
Executable max length: 0x5E80 (0x801FE000 is the maximum).
This fits in a memory card with three 'linked slots' shown in memcardrex.

Final Fantasy IX Oddity

Final Fantasy IX's save game exploits require a different load address then all other games and boot methods available in Tonyhax International. The standard 0x801F8180 can not be used to start the Tonyhax International loader from the Final Fantasy IX save game exploit, so a different address is specifically used: 0x801F6300. 

This was calculated by taking the address 0x801F8180 (the current Tonyhax International start addr since v1.1.1) and adding 0x4000 (the last Tonyhax International loader file size which worked with the FF9 exploit previously (v1.1.2)) to get 0x801FC180 (which is possibly the highest we can actually use from within FF9 for the exploit). 0x801FC180 as the max would mean 0x801FC180 - 0x5E80 (the current max size of the loader since v1.1.2) = 0x801F6300 should work for FF9 start addr.

## Layout 3: Tonyhax International v1.3.0-1.4.3

Tonyhax International v1.3.0 has increased in size past the previous 0x5E80 maximum executable limit, so it was changed to increase the maximum executable size to 0x7E00. 0x3F00 * 2 = 0x7E00 which is 2x the original size limit. The larger maximum executable size means that the Tonyhax International loader must be placed lower in memory. Load Address: 0x801F6200 Executable max length: 0x7E00 (0x801FE000 is the maximum). This fits in a memory card with two 'linked slots' shown in memcardrex.

Final Fantasy IX Oddity

Final Fantasy IX's save game exploits require a different load address then all other games and boot methods available in Tonyhax International. The standard 0x801F6200 can not be used to start the Tonyhax International loader from the Final Fantasy IX save game exploit, so a different address is specifically used: 0x801F4380.

This was calculated by taking the address 0x801F8180 (the current Tonyhax International start addr since v1.1.1) and adding 0x4000 (the last Tonyhax International loader file size which worked with the FF9 exploit previously (v1.1.2)) to get 0x801FC180 (which is possibly the highest we can actually use from within FF9 for the exploit). 0x801FC180 as the max would mean 0x801FC180 - 0x7E00 (the current max size of the loader since v1.3.0) = 0x801F4380 should work for FF9 start addr.

## Layout 4: Tonyhax International v1.4.4-v1.5.1

Note: This uses PS1 Packer to decompress a larger exe, which no other layout previously did.

Tonyhax International v1.4.4 still has the maximum file size set to 0x7E00 (which is 2x the original size limit) as it has not yet increased past that. However I now use ps1-packer which compresses the actual file size stored to be less then even half that.

Load Address after decompression: 0x801F4380 (Final Fantasy IX save game exploit) or 0x801F6200 (literally everything else).

Executable max length: 0x7E00 (0x801FE000 is the maximum).

Load Address in secondary.ld: 0x801EF380 (0x801F4380 - 0x5000 bytes for decompression code to not overlap, 0x4000 offset still failed and wasn't enough space).
This fits in a memory card with one 'linked slots' shown in memcardrex.

Final Fantasy IX Oddity

Final Fantasy IX's save game exploits require a different load address then all other games and boot methods available in Tonyhax International. The standard 0x801F6200 can not be used to start the Tonyhax International loader from the Final Fantasy IX save game exploit, so a different address is specifically used: 0x801F4380. 

This was calculated by taking the address 0x801F8180 (the current Tonyhax International start addr since v1.1.1) and adding 0x4000 (the last Tonyhax International loader file size which worked with the FF9 exploit previously (v1.1.2)) to get 0x801FC180 (which is possibly the highest we can actually use from within FF9 for the exploit). 0x801FC180 as the max would mean 0x801FC180 - 0x7E00 (the current max size of the loader since v1.3.0) = 0x801F4380 works for FF9 start addr.

## Layout 5: Tonyhax International v1.5.2-??

Note: Uses PS1 Packer to decompress a larger exe.

0x3F00 (Original size of tonyhax) / 2 = 0x1F80 (half size of original tonyhax layout max size)
0x7E00 (last layout max size) + 0x1F80 (half size of original tonyhax) = 0x9D80 (2.5 times original size)

0x801FE000 (max) - 0x9D80 (current layout size) = 0x801F4280 Makefile tload/generate-tonyhax-mcs.sh
0x801F4280 (start) - 0x5000 (to not overlap PS1 Packer) = 0x801EF280 for secondary.ld/ps1 packer stage
0x801EF280 - 0x100 (temp buffer address for entry.S) = 0x801EF180 for entry.S temp buffer

0x801FC180 (max for ff9) - 0x9D80 (current layout size) = 0x801F2400 for Makefile tload/generate-tonyhax-mcs.sh
0x801F2400 (start for ff9) - 0x5000 (to not overlap PS1 Packer) = 0x801ED400 for secondary.ld/ps1 packer stage
0x801ED400 - 0x100 (temp buffer address for entry.S) = 0x801ED300 for entry.S temp buffer

Load Address after decompression: 0x801F4280 (Final Fantasy IX save game exploit) or 0x801F2400 (literally everything else).

Executable max length: 0x9D80

Load Address in secondary.ld: 0x801ED400 (Final Fantasy IX save game exploit) or 0x801EF280 (literally everything else)
This fits in a memory card with one 'linked slot' shown in memcardrex.


## Layout 6: Tonyhax International v1.5.3

Notes: 

* Uses PS1 Packer to decompress a larger exe.
* Same as Layout 5, but increased ps1 packer spacing from 0x5000 to 0x6000.

============================================================

0x3F00 (Original size of tonyhax) / 2 = 0x1F80 (half size of original tonyhax layout max size)
0x7E00 (last layout max size) + 0x1F80 (half size of original tonyhax) = 0x9D80 (2.5 times original size)

Files:

`loader/Makefile`

============================================================

0x801FE000 (max) - 0x9D80 (current layout size) = 0x801F4280 

Files:

`loader/Makefile`

`generate-tonyhax-mcs.sh`

0x801FC180 (max for ff9) - 0x9D80 (current layout size) = 0x801F2400

Files:

`loader/Makefile.ff9`

`generate-tonyhax-mcs.sh`

============================================================

0x801F4280 (start) - 0x6000 (to not overlap PS1 Packer) = 0x801EE280

Files:

`loader/secondary.ld`

0x801F2400 (start for ff9) - 0x6000 (to not overlap PS1 Packer) = 0x801EC400

Files:

`loader/secondary-ff9.ld`

============================================================

0x801EE280 - 0x100 (temp buffer address for entry.S) = 0x801EE180 

Files:

`entrypoints/entry.S`

0x801EC400 - 0x100 (ff9 temp buffer address for entry.S) = 0x801EC300

Files:

`entrypoints/entry.S`

============================================================

## Layout 6: Tonyhax International v1.5.4-??

Notes: 

* Uses PS1 Packer to decompress a larger exe.
* Same as Layout 6, but increased ps1 packer spacing from 0x5000 to 0x6000.

============================================================

0x3F00 (Original size of tonyhax) / 2 = 0x1F80 (half size of original tonyhax layout max size)
0x7E00 (last layout max size) + 0x1F80 (half size of original tonyhax) = 0x9D80 (2.5 times original size)

Files:

`loader/Makefile`

============================================================

0x801FE000 (max) - 0x9D80 (current layout size) = 0x801F4280 

Files:

`loader/Makefile`

`generate-tonyhax-mcs.sh`

0x801FC180 (max for ff9) - 0x9D80 (current layout size) = 0x801F2400

Files:

`loader/Makefile.ff9`

`generate-tonyhax-mcs.sh`

============================================================

0x801F4280 (start) - 0x8000 (to not overlap PS1 Packer) = 0x801EC280

Files:

`loader/secondary.ld`

0x801F2400 (start for ff9) - 0x8000 (to not overlap PS1 Packer) = 0x801EA400

Files:

`loader/secondary-ff9.ld`

============================================================

0x801EE280 - 0x100 (temp buffer address for entry.S) = 0x801EE180 

Files:

`entrypoints/entry.S`

0x801EC400 - 0x100 (ff9 temp buffer address for entry.S) = 0x801EC300

Files:

`entrypoints/entry.S`

============================================================
