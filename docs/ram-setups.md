# RAM Layouts

## Files To Update Each Time You Switch Layouts:

*   `entrypoints/entry.S`
*   `loader/tonyhax-tpl.mcs`.
*   `loader/tonyhax-tpl-ff9.mcs`
*   `loader/secondary.ld`
*   `loader/generate-tonyhax-mcs.sh`

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

## Layout 4: Tonyhax International v1.4.4-??

Note: This uses PS1 Packer to decompress a larger exe, which no other layout previously did.

Tonyhax International v1.4.4 still has the maximum file size set to 0x7E00 (which is 2x the original size limit) as it has not yet increased past that. However I now use ps1-packer which compresses the actual file size stored to be less then even half that.

Load Address after decompression: 0x801F4380 (Final Fantasy IX save game exploit) or 0x801F6200 (literally everything else).

Executable max length: 0x7E00 (0x801FE000 is the maximum).

Load Address in secondary.ld: 0x801EF380 (0x801F4380 - 0x5000 bytes for decompression code to not overlap, 0x4000 offset still failed and wasn't enough space).
This fits in a memory card with one 'linked slots' shown in memcardrex.

Final Fantasy IX Oddity

Final Fantasy IX's save game exploits require a different load address then all other games and boot methods available in Tonyhax International. The standard 0x801F6200 can not be used to start the Tonyhax International loader from the Final Fantasy IX save game exploit, so a different address is specifically used: 0x801F4380. 

This was calculated by taking the address 0x801F8180 (the current Tonyhax International start addr since v1.1.1) and adding 0x4000 (the last Tonyhax International loader file size which worked with the FF9 exploit previously (v1.1.2)) to get 0x801FC180 (which is possibly the highest we can actually use from within FF9 for the exploit). 0x801FC180 as the max would mean 0x801FC180 - 0x7E00 (the current max size of the loader since v1.3.0) = 0x801F4380 should work for FF9 start addr.


