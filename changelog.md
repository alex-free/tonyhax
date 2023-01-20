## Version 1.1.7 (1/3/2023)

*   [tonyhax-v1.1.7-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.7i/tonyhax-v1.1.7-international.zip)

Changes:

*   Added [save game exploit](save-game-exploit.html) support for Final Fantasy IX Japan, Final Fantasy IX USA Rev 0, and Final Fantasy IX USA Rev 1 thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714))!

* **Fixed the `tonyhax.mcs` and `HAX` loader files** for the [save game exploit](save-game-exploit.html) boot method. Previously, only the `HAX` loader file _copied via uLaunchElf specifically to a memory card_ was working due to an error accommodating the larger size of the Tonyhax International loader since v1.1.3. **This issue has now been resolved and everything works as expected with both the `tonyhax.mcs` and `HAX` loader files as they are in the correct 'linked' format (you can see this in the memcardrex software for example)**.

* Updated [crosstool-ng](https://crosstool-ng.github.io/) to the latest version. Fixed and updated the crosstool-ng config file used to build the Tonyhax International toolchain to work with the latest version. The new config file also makes a more tuned PSX toolchain. The toolchain is set to be tuned for the r3000, for little-endian, for soft-float (no hardware float support), and for a 32-bit ABI. This means the previous CFLAGS setting these options explicitly are no longer necessary and have been removed from the various `variable.mk*` files in the source.

* Updated the APv2 decompilation documentation (from the latest official Tonyhax).

* Added more info on the RAM setups used by Tonyhax International and how they work. This information can be found in the `ram-setups.txt` file in the `docs` directory of the source.

* Substantially rewrote the documentation with more information.

## Version 1.1.6 (12/10/2022)

*   [tonyhax-v1.1.6-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.6i/tonyhax-v1.1.6-international.zip)

Changes:

* Implemented **many speed and size optimizations** for the tonyhax international loader. Can **boot games quicker in some cases**.

* Applied this [commit](https://github.com/socram8888/tonyhax/commit/7f22506857afe66c4f8419ee2e73f62306a125da) from OG [TonyHax](https://github.com/socram8888/tonyhax) to better simulate how the BIOS boots games. As of 12/10/2022, _where applicable_ Tonyhax International is current with the original Tonyhax.

* Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) in Strider 2, Rockman X5, Rockman X6, Rockman 5, Dance Dance Revolution: Best Hits, Dance Dance Revolution 2nd Remix, Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1, Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2.

* Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) in i-mode mo Issho: Doko Demo Issho Tsuika Disc (thanks [M4x1mumRez](https://github.com/M4x1mumReZ)).

* Added information on games with additional [EDC Checks](anti-piracy-bypass.md#edc) found in some games (most notably such checks are found in the Dance Dance Revolution games that I've just added support for bypassing their additional anti-piracy measures). You must burn games containing EDC Checks in a specific way for them to work.

## Version 1.1.5 (12/3/2022)

*   [tonyhax-v1.1.5-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.5i/tonyhax-v1.1.5-international.zip)

Changes:

* Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) in Koneko mo Issho.

* Fixed entry.S header temp buffer address.

* More size optimizations (specifcally in ap-bypass.c).

## Version 1.1.4 (12/2/2022)

*   [tonyhax-v1.1.4-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.4i/tonyhax-v1.1.4-international.zip)

Changes:

* Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) in Pop'n Music: Disney Tunes, Beatmania featuring Dreams Come True, Dancing Stage featuring Dreams Come True, Oha-Studio Dance Dance Revolution, Dance Dance Revolution: Disney's Rave, Dance Dance Revolution: Extra Mix, and Beatmania Best Hits (thanks [trappedinlimbo](https://www.psx-place.com/members/trappedinlimbo.156719/)).

* Controller input in Japanese consoles reverted to proper silent debug_write message polling as in v1.1.2 and below.

## Version 1.1.3 (11/30/2022)

*   [tonyhax-v1.1.3-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.3i/tonyhax-v1.1.3-international.zip)

Changes:

* Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) in Crash Bash/Crash Bandicoot Carnival, Koko Hore! Pukka, Love Hina: Ai wa Kotoba no Naka ni, and Love Hina 2: Kotoba wa Konayuki no You ni (thanks [M4x1mumRez](https://github.com/M4x1mumReZ)).

* Rewrote the Building From Source instructions for clarity and simplicity.

* Fixed Pop'n Music 6's anti-piracy bypass and 'boots to black screen' issue.

* Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) in Pop'N Music: Animation Melody (thanks [trappedinlimbo](https://www.psx-place.com/members/trappedinlimbo.156719/)).

* Merged **all new applicable changes** from the latest [O.G. Tonyhax](https://github.com/socram8888/tonyhax) where applicable (as of 11/30/2022 this is up to date with the current source tree). See commits [8284633c435a9325dcfd7028d9788bacae94de69](https://github.com/alex-free/tonyhax/commit/8284633c435a9325dcfd7028d9788bacae94de69), [b72b08e5ba814196f07993491b483e5ec8e3fc93](https://github.com/alex-free/tonyhax/commit/b72b08e5ba814196f07993491b483e5ec8e3fc93), and [8934a2bb614973064e45a6638e03fd0c7426e5fc](https://github.com/alex-free/tonyhax/commit/8934a2bb614973064e45a6638e03fd0c7426e5fc) for full details.

* Changed everything to be cleaner and closer to the latest source tree of the original Tonyhax. There will now be a diff comparing the `loader` directory of the current Tonyhax `loader` directory with the Tonyhax International `loader` directory, enabling easy comparison/documention/review of the current code differences between the fork and upstream. You can find this diff in the `docs/tonyhax-vs-tonyhax-international-diffs` directory in the source tree.


## Version 1.1.2 (11/9/2022)

*   [tonyhax-v1.1.2-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.2i/tonyhax-v1.1.2-international.zip)

Changes:

*	Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) found in all versions of Yu-Gi-Oh! Forbidden Memories, Cool Boarders 2001, Disney's The Emperor's New Grove, Resident Evil: Survivor, and Tomba! 2.

*	Added support for bypassing the [additional anti-piracy copy protection routines](anti-piracy-bypass.html) found in Pocket Jiman, thanks to the code by [m4x1mumrez](https://gbatemp.net/members/m4x1mumrez.610331/) generated with [APrip](https://alex-free.github.io/aprip).

*	Fixes a regression in version 1.1.1 that could possibly cause Japanese consoles to freeze before booting the game completely.


## Version 1.1.1 (10/29/2022)

*   [tonyhax-v1.1.1-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.1i/tonyhax-v1.1.1-international.zip)

Changes:

*	A completely new system to bypass [additional anti-piracy copy protection routines](anti-piracy-bypass.html) found in some later PSX games **which works on all consoles, including Japanese ones** has replaced the old Socram8888 bios patch. This improves Tonyhax International by giving it the ability to play many more games then ever before, and makes support just as good on the Japanese consoles. Huge thanks to MottZilla for the method to implement gameshark codes in Tonyhax International, which provides this functionality.
*	Optimized Tonyhax International's loader for size and speed. Cleaned up source tree.
*	Rewrote documentation in markdown.

## Version 1.1.0 (9/25/2022)

*   [tonyhax-v1.1.0-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.0i/tonyhax-v1.1.0-international.zip)

Changes:

*   Updated to FreePSXBoot v2.1 (my own [fork](https://github.com/alex-free/FreePSXBoot) for now so that it compiles on [Fedora](https://github.com/brad-lin/FreePSXBoot/pull/97)). This means among other things that those 'fake' 64KB chinese PS1 memory cards now work with the FreePSXBoot images.
*   **Tonyhax International [FreePSXBoot](freepsxboot-exploit.md) memory cards no longer need to be removed after booting the loader if they are in slot 2 of the console.** I have completely removed Socram8888's old FreePSXBoot patch. The new 'memory card timeout to disable' patch from the FreePSXBoot builder is now used instead of the 'pretend memory card is corrupted' patch from the original Tonyhax. The new patch works with all games, some games did not like the old patch method used. **The new patch also works correctly on every single PS1 BIOS version, including BIOS v1.0, v1.1, and v2.0.** The old patch never worked on BIOS v1.0, 1.1, or 2.0.
*   Added tonyhax\_scph-3000\_v1.1\_slot2.mcr, tonyhax\_scph-3000\_v1.1\_slot1.mcr, tonyhax\_scph-3000\_v2.1\_slot2.mcr, and tonyhax\_scph-3000\_v2.1\_slot1.mcr FreePSXBoot memory card files (as there are actually 2 different BIOS versions found in SCPH-3000 consoles).
*   All FreePSXBoot images are now created with the `-fastload` option on to improve how fast Tonyhax International starts with the FreePSXBoot exploit. The `-fastload` option also provides that cool loading screen you can see in [Unirom](https://unirom.github.io).
*   Japanese PlayStations with **VC2 and VC3** CDROM drive controllers are now re-calibrated to improve CD tracking and read performance for these CDROM controllers. VC1 and VC0 do not have equivalent commands, hardware, or even a need for this really since Bias and Gain can only be set manually.
*   TOCPerfect changes have been merged from [PS1 DemoSwap Patcher](https://alex-free.github.io/ps1demoswap).
*   Removed documentation on PS1 CD drive repair as it is getting it's own webpage/document in the near future. Reduced the size of releases dramatically by using better compressed images in this document (thanks [Berion](https://www.psx-place.com/members/berion.1431/) of [PSX-Place](https://psx-place.com)).
*   Added notes about video mode switching support on PS2s using [PS1VModeNeg v1.0.1](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/) (thanks [Berion](https://www.psx-place.com/members/berion.1431/) of [PSX-Place](https://psx-place.com))
*   Cleaned up source tree and we are back to a consistent coding style (Socram8888 would be [proud](https://github.com/socram8888/tonyhax/pull/129)).
*   Stock (non-modchipped) SCPH-1000 and early SCPH-3000 can now play **any real import discs or backup CD-Rs of games containing anti-piracy detection (excluding PAL region games that also contain libcrypt protection)** with 100% compatibility, even better then the anti-piracy bypass for American/European consoles actually.

## Version 1.0.8 (8/26/2022)

*   [tonyhax-v1.0.8-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.8i/tonyhax-v1.0.8-international.zip)

Changes:

*   Fixed the anti anti-piracy functionality regression for American/European consoles. You can now play backup or import PS1 games that have anti-piracy features (i.e. Dino Crisis) without issue on all American console and European consoles.
*   Removed the PAL licensed ROM flasher CD image, as it is not actually not needed. Any console that supports cheat carts (SCPH-1000 up to SCPH-750X models) will boot a CD-R burned via the current `tonyhax-rom-flasher.bin+tonyhax-rom-flasher.cue` files just fine.
*   Updated documentation on burning PS1 backups. Added info on games containing anti-piracy and or libcrypt protection. Also added info on replacing and modifying PS1 CD drives and changing bias/gain/laser resistance values.
*   Cleaned up build proccess and source tree.

## Version 1.0.7 (8/7/2022)

*   [tonyhax-v1.0.7-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.7i/tonyhax-v1.0.7-international.zip)

Changes:

*   The Tonyhax International loader memory card save file **is now named `HAX` instead of `BESLEM-99999TONYHAX` to allow for more exploitable games**. You will need to update both the save game exploit file for your game as well as the Tonyhax International loader file to use v1.0.7 if you are using a previou version of the save game exploit file for your game that is already on a memory card.
*   Removed the SetSessionSuperUltraCommandSmash and replaced it with [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867)'s new method of re-reading TOC data for VC0 A, VC0 B, and VC1 A CDROM Controller BIOS firmwares. **This change reduces the time it takes to re-read the TOC data on the backup CD-R or import PS1 disc from 2-10 minutes on the SCPH-1000, SCPH-3000, and some SCPH-3500 japanese consoles to around 30 seconds with 100% reliability!**
*   Added [save game exploit](save-game-exploit.html) support for Tekken 3 Japan/USA/PAL thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)) and [krystalgamer](https://github.com/socram8888/tonyhax/pull/20).
*   Added [save game exploit](save-game-exploit.html) support for Tekken 2 Japan (rev 1 only), USA (rev 0 only), and PAL thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=671)) and [krystalgamer](https://github.com/socram8888/tonyhax/pull/20).
*   Added [save game exploit](save-game-exploit.html) support for Downhill Snow Japan thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)).

## Version 1.0.6 (8/3/2022)

*   [tonyhax-v1.0.6-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.6i/tonyhax-v1.0.6-international.zip)

Changes:

*   Added [save game exploit](save-game-exploit.html) support for Castlevania Chronicle NTSC-J (only the first release, rev 1 is not working right now) (Alex Free) and 1500 Lite Series Castrol Honda Super Bike Racing NTSC-J (Alex Free).
*   Added [save game exploit](save-game-exploit.html) support for Tony Hawk Pro Skater 2 NTSC-J (MottZilla) and 1500 Lite Series Castrol Honda VTR (MottZilla).

## Version 1.0.5 (7/27/2022)

*   [tonyhax-v1.0.5-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.5i/tonyhax-v1.0.5-international.zip)

Changes:

*   Added [save game exploit](save-game-exploit.html) support for Doki Oki (NTSC-J), Crash Bandicoot 3 (NTSC-J), and The Legend Of Heroes I&II (NTSC-J). All these save game exploits were found by [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714).

## Version 1.0.4 (7/23/2022)

*   [tonyhax-v1.0.4-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.4i/tonyhax-v1.0.4-international.zip)