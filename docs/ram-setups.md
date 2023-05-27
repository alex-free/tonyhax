# RAM Layouts

## Files To Update Each Time You Switch Layouts:

*   `entrypoints/entry.S`
*   `loader/tonyhax-tpl.mcs`.
*   `loader/tonyhax-tpl-ff9.mcs`
*   `loader/secondary.ld`
*   `loader/secondary-ff9.ld`

## Layout 1: Tonyhax OG/Tonyhax International v1.0-v1.1.0

The original Tonyhax loader (and International v1.0-v1.1.0) was setup like this (original size limit):
Load Address: 0x801FA100
Executable max length: 0x3F00 (0x801FE000 is the maximum)
This fits in a memory card file with one 'linked slot' shown in memcardrex.

## Layout 2: Tonyhax International v1.1.1-v1.2.9

Tonyhax International v1.1.1-1.2.9 increased in size past the original 0x3F00 maximum executable limit, so it was changed to increase the maximum executable size to 0x5E80. 0x3F00 / 2 = 0x1F80, 0x1F80 + 0x3F00 = 0x5E80 which is 1.5x the original size limit. The larger maximum executable size means that the Tonyhax International loader must be placed lower in memory.
Load Address: 0x801F8180
Executable max length: 0x5E80 (0x801FE000 is the maximum).
This fits in a memory card with two 'linked slots' shown in memcardrex.

Final Fantasy IX Oddity

Final Fantasy IX's save game exploits require a different load address then all other games and boot methods available in Tonyhax International. The standard 0x801F8180 can not be used to start the Tonyhax International loader from the Final Fantasy IX save game exploit, so a different address is specifically used: 0x801F6300. 

This was calculated by taking the address 0x801F8180 (the current Tonyhax International start addr since v1.1.1) and adding 0x4000 (the last Tonyhax International loader file size which worked with the FF9 exploit previously (v1.1.2)) to get 0x801FC180 (which is possibly the highest we can actually use from within FF9 for the exploit). 0x801FC180 as the max would mean 0x801FC180 - 0x5E80 (the current max size of the loader since v1.1.2) = 0x801F6300 should work for FF9 start addr.

## Layout 3: Tonyhax International v1.3.0-??

Tonyhax International v1.3.0 has increased in size past the previous 0x5E80 maximum executable limit, so it was changed to increase the maximum executable size to 0x5E80. 0x3F00 * 2 = 0x7E00 which is 2x the original size limit. The larger maximum executable size means that the Tonyhax International loader must be placed lower in memory.
Load Address: 0x801F6200
Executable max length: 0x7E00 (0x801FE000 is the maximum).
This fits in a memory card with two 'linked slots' shown in memcardrex.

Final Fantasy IX Oddity

Final Fantasy IX's save game exploits require a different load address then all other games and boot methods available in Tonyhax International. The standard 0x801F6200 can not be used to start the Tonyhax International loader from the Final Fantasy IX save game exploit, so a different address is specifically used: 0x801F4380. 

This was calculated by taking the address 0x801F8180 (the current Tonyhax International start addr since v1.1.1) and adding 0x4000 (the last Tonyhax International loader file size which worked with the FF9 exploit previously (v1.1.2)) to get 0x801FC180 (which is possibly the highest we can actually use from within FF9 for the exploit). 0x801FC180 as the max would mean 0x801FC180 - 0x7E00 (the current max size of the loader since v1.3.0) = 0x801F4380 should work for FF9 start addr.


