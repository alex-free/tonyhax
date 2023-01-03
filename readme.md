# [alex-free.github.io](https://alex-free.github.io)

# Tonyhax International: The Ultimate Backup/Import Disc Loader SoftMod Solution For The Original PlayStation & Early Models Of PlayStation 2

Brought to you by [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867), [Alex Free](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6018), and [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714). Built on the work of many [others](#credits).

Tonyhax International is a fork of the [Tonyhax](https://orca.pet/tonyhax/) "Software backup loader exploit thing for the Sony PlayStation 1" originally created by [Socram8888](https://github.com/socram8888). Tonyhax International is developed by Alex Free and MottZilla with many new features and upgrades compared to the original Tonyhax, some of which are listed below:

* Supports all PS1 Consoles (Japanese, American, European, SCPH-1000-SCPH-102) **and** Early PS2 Consoles (Japanese, American, European, SCPH-10000-SCPH-39004).

* Supports more [save game exploits](#save-game-exploit), enabling the use of even more PSX game discs to start the Tonyhax International loader.

* Supports [flashing](#romrom-flasher-cd) the Tonyhax International backup/import loader to a GameShark/Action Reply/cheat cartridge. Whenever the flashed cartridge is plugged into the back of a SCPH-1000-SCPH-7502 PS1 console when you power it on the Tonyhax International will boot instead of the shell program/BIOS (Sony screens/CD Player/Memory Card Manager).

* Uses the newer [FreePSXBoot](https://github.com/brad-lin/FreePSXBoot) exploit/patching methods to disable FreePSXBoot memory cards that boot Tonyhax International after the FreePSXBoot exploit starts the loader from the memory card on all BIOS versions.

* Supports more [games with additonal copy protection routines](#playing-games-with-additonal-copy-protection-routines) using a new anti-piracy bypass system.

* Completely automated testing/building/development suite of scripts in the source that supports building Tonyhax International on virtually any \*nix like OS.

### Usage

_Japanese PS1 Consoles (SCPH-1000-SCPH-100)_

*   [Japanese PS1 Console Loader Instructions](#japanese-ps1-console-loader-instructions)
*   [Playing Games That Span Multiple Discs On Japanese PS1 Consoles](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles)

_Japanese PS2 Consoles (SCPH-10000-SCPH-39000)_

*   [Japanese PS2 Console Loader Instructions](#japanese-ps2-console-loader-instructions)
*   [Using the Swap Magic Tool](#using-the-swap-magic-tool)
*   [Playing Games That Span Multiple Discs On Japanese PS2 Consoles](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles)
*   [Playing PAL Region Games On Japanese PS2 Consoles](#playing-pal-region-games-on-japanese-ps2-consoles)

_American/European PS1/PS2 Consoles (SCPH-1001-SCPH-39004)_

*   [American/European PS1/PS2 Console Loader Instructions](#americaneuropean-ps1ps2-console-loader-instructions)
*   [Playing Games That Span Multiple Discs On American/European PS1/PS2 Consoles](#playing-games-that-span-multiple-discs-on-americaneuropean-ps1ps2-consoles)
*   [Playing PAL Games On American PS2 Consoles](#playing-pal-games-on-american-ps2-consoles)
*   [Playing Japanese/American Games On PAL PS2 Consoles](#playing-japaneseamerican-games-on-pal-ps2-consoles)

_Boot Methods_

*   [ROM/ROM Flasher CD](#romrom-flasher-cd)
*   [FreePSXBoot Exploit Memory Card Images](#freepsxboot-exploit-memory-card-images)
*   [Boot CD](#boot-cd)
*   [Save Game Exploit](#save-game-exploit)

_More Info_

* [Playing Games With Additional Copy Protection Routines](#playing-games-with-additonal-copy-protection-routines)
* [List Of Games With Anti-Piracy Bypass Support](#list-of-games-with-anti-piracy-bypass-support)
* [Known Games That Need Anti-Piracy Bypasses Implemented](#known-games-that-need-anti-piracy-bypasses-implemented)
* [Bypassing Additional EDC Checks Found In Some Games](#bypassing-additional-edc-checks-found-in-some-games) 
* [CD-R Media For PSX Backups](#cd-r-media-for-psx-backups)
* [Burning PSX CD-Rs](#burning-psx-cd-rs)
* [Disc Read Errors And PS1 CD Drive Repair](https://alex-free.github.io/unofficial-ps1-cd-drive-service-manual/)
* [Building From Source](#building-from-source)
* [Known Incompatible Games](#known-incompatible-games)
* [Credits](#credits)

## External Links

*   [Tonyhax International Homepage](https://alex-free.github.io/tonyhax-international)
*   [Tonyhax International GitHub](https://github.com/alex-free/tonyhax)
*   [PSX-Place Thread](https://www.psx-place.com/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles.37925/)
*   [PSX-Place Tonyhax International Resource](https://www.psx-place.com/resources/tonyhax-international.1281/)
*   [CDRDAO-AF Fork](https://alex-free.github.io/cdrdao)
*   [PSXDEV Thread](http://www.psxdev.net/forum/viewtopic.php?f=66&t=3967)
*   [GBATemp Thread](https://gbatemp.net/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles-gameshark-cheat-cart-flasher.615892/#post-9922514)
*   [APrip Homepage](https://alex-free.github.io/aprip)
*   [PS1 DemoSwap Patcher Homepage](https://alex-free.github.io/ps1demoswap)
*   [PSEXE2ROM Homepage](https://alex-free.github.io/psexe2rom)
*   [FreePSXBoot](https://github.com/brad-lin/FreePSXBoot)
*   [Tonyhax (the original) Github](https://github.com/socram8888/tonyhax)
*   [Tonyhax (the original) Homepage](https://orca.pet/tonyhax)

## Downloads

### Version 1.1.7 (1/3/2023)

*   [tonyhax-v1.1.7-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.7i/tonyhax-v1.1.7-international.zip)

Changes:

*   Added [save game exploit](#save-game-exploit) support for Final Fantasy IX Japan, Final Fantasy IX USA Rev 0, and Final Fantasy IX USA Rev 1 thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714))!

* **Fixed the `tonyhax.mcs` and `HAX` loader files** for the [save game exploit](#save-game-exploit) boot method. Previously, only the `HAX` loader file _copied via uLaunchElf specifically to a memory card_ was working due to an error accommodating the larger size of the Tonyhax International loader since v1.1.3. **This issue has now been resolved and everything works as expected with both the `tonyhax.mcs` and `HAX` loader files as they are in the correct 'linked' format (you can see this in the memcardrex software for example)**.

* Updated [crosstool-ng](https://crosstool-ng.github.io/) to the latest version. Fixed and updated the crosstool-ng config file used to build the Tonyhax International toolchain to work with the latest version. The new config file also makes a more tuned PSX toolchain. The toolchain is set to be tuned for the r3000, for little-endian, for soft-float (no hardware float support), and for a 32-bit ABI. This means the previous CFLAGS setting these options explicitly are no longer necessary and have been removed from the various `variable.mk*` files in the source.

* Updated the APv2 decompilation documentation (from the latest official Tonyhax).

* Added more info on the RAM setups used by Tonyhax International and how they work. This information can be found in the `ram-setups.txt` file in the `docs` directory of the source.

* Substantially rewrote the documentation with more information.

### Version 1.1.6 (12/10/2022)

*   [tonyhax-v1.1.6-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.6i/tonyhax-v1.1.6-international.zip)

Changes:

* Implemented **many speed and size optimizations** for the tonyhax international loader. Can **boot games quicker in some cases**.

* Applied this [commit](https://github.com/socram8888/tonyhax/commit/7f22506857afe66c4f8419ee2e73f62306a125da) from OG [TonyHax](https://github.com/socram8888/tonyhax) to better simulate how the BIOS boots games. As of 12/10/2022, _where applicable_ Tonyhax International is current with the original Tonyhax.

* Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) in Strider 2, Rockman X5, Rockman X6, Rockman 5, Dance Dance Revolution: Best Hits, Dance Dance Revolution 2nd Remix, Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1, Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2.

* Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) in i-mode mo Issho: Doko Demo Issho Tsuika Disc (thanks [M4x1mumRez](https://github.com/M4x1mumReZ)).

* Added information on games with additional [EDC Checks](#bypassing-additional-edc-checks-found-in-some-games) found in some games (most notably such checks are found in the Dance Dance Revolution games that I've just added support for bypassing their additional anti-piracy measures). You must [burn](#burning-psx-cd-rs) games containing EDC Checks in a specific way for them to work.

### Version 1.1.5 (12/3/2022)

*   [tonyhax-v1.1.5-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.5i/tonyhax-v1.1.5-international.zip)

Changes:

* Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) in Koneko mo Issho.

* Fixed entry.S header temp buffer address.

* More size optimizations (specifcally in ap-bypass.c).

### Version 1.1.4 (12/2/2022)

*   [tonyhax-v1.1.4-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.4i/tonyhax-v1.1.4-international.zip)

Changes:

* Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) in Pop'n Music: Disney Tunes, Beatmania featuring Dreams Come True, Dancing Stage featuring Dreams Come True, Oha-Studio Dance Dance Revolution, Dance Dance Revolution: Disney's Rave, Dance Dance Revolution: Extra Mix, and Beatmania Best Hits (thanks [trappedinlimbo](https://www.psx-place.com/members/trappedinlimbo.156719/)).

* Controller input in Japanese consoles reverted to proper silent debug_write message polling as in v1.1.2 and below.

### Version 1.1.3 (11/30/2022)

*   [tonyhax-v1.1.3-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.3i/tonyhax-v1.1.3-international.zip)

Changes:

* Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) in Crash Bash/Crash Bandicoot Carnival, Koko Hore! Pukka, Love Hina: Ai wa Kotoba no Naka ni, and Love Hina 2: Kotoba wa Konayuki no You ni (thanks [M4x1mumRez](https://github.com/M4x1mumReZ)).

* Added a [Known Incompatible Games](#known-incompatible-games) section, which documents games that currently do not work with either the **original [Tonyhax](https://github.com/socram8888/tonyhax) OR Tonyhax International.**

* Rewrote the [Building From Source](#building-from-source) instructions for clarity and simplicity.

* Fixed Pop'n Music 6's anti-piracy bypass and 'boots to black screen' issue.

* Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) in Pop'N Music: Animation Melody (thanks [trappedinlimbo](https://www.psx-place.com/members/trappedinlimbo.156719/)).

* Merged **all new applicable changes** from the latest [O.G. Tonyhax](https://github.com/socram8888/tonyhax) where applicable (as of 11/30/2022 this is up to date with the current source tree). See commits [8284633c435a9325dcfd7028d9788bacae94de69](https://github.com/alex-free/tonyhax/commit/8284633c435a9325dcfd7028d9788bacae94de69), [b72b08e5ba814196f07993491b483e5ec8e3fc93](https://github.com/alex-free/tonyhax/commit/b72b08e5ba814196f07993491b483e5ec8e3fc93), and [8934a2bb614973064e45a6638e03fd0c7426e5fc](https://github.com/alex-free/tonyhax/commit/8934a2bb614973064e45a6638e03fd0c7426e5fc) for full details.

* Changed everything to be cleaner and closer to the latest source tree of the original Tonyhax. There will now be a diff comparing the `loader` directory of the current Tonyhax `loader` directory with the Tonyhax International `loader` directory, enabling easy comparison/documention/review of the current code differences between the fork and upstream. You can find this diff in the `docs/tonyhax-vs-tonyhax-international-diffs` directory in the source tree.


### Version 1.1.2 (11/9/2022)

*   [tonyhax-v1.1.2-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.2i/tonyhax-v1.1.2-international.zip)

Changes:

*	Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) found in all versions of Yu-Gi-Oh! Forbidden Memories, Cool Boarders 2001, Disney's The Emperor's New Grove, Resident Evil: Survivor, and Tomba! 2.

*	Added support for bypassing the [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) found in Pocket Jiman, thanks to the code by [m4x1mumrez](https://gbatemp.net/members/m4x1mumrez.610331/) generated with [APrip](https://alex-free.github.io/aprip).

*	Fixes a regression in version 1.1.1 that could possibly cause Japanese consoles to freeze before booting the game completely.


### Version 1.1.1 (10/29/2022)

*   [tonyhax-v1.1.1-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.1i/tonyhax-v1.1.1-international.zip)

Changes:

*	A completely new system to bypass [additional anti-piracy copy protection routines](#playing-games-with-additonal-copy-protection-routines) found in some later PSX games **which works on all consoles, including Japanese ones** has replaced the old Socram8888 bios patch. This improves Tonyhax International by giving it the ability to play many more games then ever before, and makes support just as good on the Japanese consoles. Huge thanks to MottZilla for the method to implement gameshark codes in Tonyhax International, which provides this functionality.
*	Optimized Tonyhax International's loader for size and speed. Cleaned up source tree.
*	Rewrote documentation in markdown.

### Version 1.1.0 (9/25/2022)

*   [tonyhax-v1.1.0-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.0i/tonyhax-v1.1.0-international.zip)

Changes:

*   Updated to FreePSXBoot v2.1 (my own [fork](https://github.com/alex-free/FreePSXBoot) for now so that it compiles on [Fedora](https://github.com/brad-lin/FreePSXBoot/pull/97)). This means among other things that those 'fake' 64KB chinese PS1 memory cards now work with the FreePSXBoot images.
*   **Tonyhax International [FreePSXBoot](#freepsxboot-exploit-memory-card-images) memory cards no longer need to be removed after booting the loader if they are in slot 2 of the console.** I have completely removed Socram8888's old FreePSXBoot patch. The new 'memory card timeout to disable' patch from the FreePSXBoot builder is now used instead of the 'pretend memory card is corrupted' patch from the original Tonyhax. The new patch works with all games, some games did not like the old patch method used. **The new patch also works correctly on every single PS1 BIOS version, including BIOS v1.0, v1.1, and v2.0.** The old patch never worked on BIOS v1.0, 1.1, or 2.0.
*   Added tonyhax\_scph-3000\_v1.1\_slot2.mcr, tonyhax\_scph-3000\_v1.1\_slot1.mcr, tonyhax\_scph-3000\_v2.1\_slot2.mcr, and tonyhax\_scph-3000\_v2.1\_slot1.mcr FreePSXBoot memory card files (as there are actually 2 different BIOS versions found in SCPH-3000 consoles).
*   All FreePSXBoot images are now created with the `-fastload` option on to improve how fast Tonyhax International starts with the FreePSXBoot exploit. The `-fastload` option also provides that cool loading screen you can see in [Unirom](https://unirom.github.io).
*   Japanese PlayStations with **VC2 and VC3** CDROM drive controllers are now re-calibrated to improve CD tracking and read performance for these CDROM controllers. VC1 and VC0 do not have equivalent commands, hardware, or even a need for this really since Bias and Gain can only be set manually.
*   TOCPerfect changes have been merged from [PS1 DemoSwap Patcher](https://alex-free.github.io/ps1demoswap).
*   Removed documentation on PS1 CD drive repair as it is getting it's own webpage/document in the near future. Reduced the size of releases dramatically by using better compressed images in this document (thanks [Berion](https://www.psx-place.com/members/berion.1431/) of [PSX-Place](https://psx-place.com)).
*   Added notes about video mode switching support on PS2s using [PS1VModeNeg v1.0.1](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/) (thanks [Berion](https://www.psx-place.com/members/berion.1431/) of [PSX-Place](https://psx-place.com))
*   Cleaned up source tree and we are back to a consistent coding style (Socram8888 would be [proud](https://github.com/socram8888/tonyhax/pull/129)).
*   Stock (non-modchipped) SCPH-1000 and early SCPH-3000 can now play **any real import discs or backup CD-Rs of games containing anti-piracy detection (excluding PAL region games that also contain libcrypt protection)** with 100% compatibility, even better then the anti-piracy bypass for American/European consoles actually.

### Version 1.0.8 (8/26/2022)

*   [tonyhax-v1.0.8-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.8i/tonyhax-v1.0.8-international.zip)

Changes:

*   Fixed the anti anti-piracy functionality regression for American/European consoles. You can now play backup or import PS1 games that have anti-piracy features (i.e. Dino Crisis) without issue on all American console and European consoles.
*   Removed the PAL licensed ROM flasher CD image, as it is not actually not needed. Any console that supports cheat carts (SCPH-1000 up to SCPH-750X models) will boot a CD-R burned via the current `tonyhax-rom-flasher.bin+tonyhax-rom-flasher.cue` files just fine.
*   Updated documentation on burning PS1 backups. Added info on games containing anti-piracy and or libcrypt protection. Also added info on replacing and modifying PS1 CD drives and changing bias/gain/laser resistance values.
*   Cleaned up build proccess and source tree.

### Version 1.0.7 (8/7/2022)

*   [tonyhax-v1.0.7-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.7i/tonyhax-v1.0.7-international.zip)

Changes:

*   The Tonyhax International loader memory card save file **is now named `HAX` instead of `BESLEM-99999TONYHAX` to allow for more exploitable games**. You will need to update both the save game exploit file for your game as well as the Tonyhax International loader file to use v1.0.7 if you are using a previou version of the save game exploit file for your game that is already on a memory card.
*   Removed the SetSessionSuperUltraCommandSmash and replaced it with [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867)'s new method of re-reading TOC data for VC0 A, VC0 B, and VC1 A CDROM Controller BIOS firmwares. **This change reduces the time it takes to re-read the TOC data on the backup CD-R or import PS1 disc from 2-10 minutes on the SCPH-1000, SCPH-3000, and some SCPH-3500 japanese consoles to around 30 seconds with 100% reliability!**
*   Added [save game exploit](#save-game-exploit) support for Tekken 3 Japan/USA/PAL thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)) and [krystalgamer](https://github.com/socram8888/tonyhax/pull/20).
*   Added [save game exploit](#save-game-exploit) support for Tekken 2 Japan (rev 1 only), USA (rev 0 only), and PAL thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=671)) and [krystalgamer](https://github.com/socram8888/tonyhax/pull/20).
*   Added [save game exploit](#save-game-exploit) support for Downhill Snow Japan thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)).

### Version 1.0.6 (8/3/2022)

*   [tonyhax-v1.0.6-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.6i/tonyhax-v1.0.6-international.zip)

Changes:

*   Added [save game exploit](#save-game-exploit) support for Castlevania Chronicle NTSC-J (only the first release, rev 1 is not working right now) (Alex Free) and 1500 Lite Series Castrol Honda Super Bike Racing NTSC-J (Alex Free).
*   Added [save game exploit](#save-game-exploit) support for Tony Hawk Pro Skater 2 NTSC-J (MottZilla) and 1500 Lite Series Castrol Honda VTR (MottZilla).

### Version 1.0.5 (7/27/2022)

*   [tonyhax-v1.0.5-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.5i/tonyhax-v1.0.5-international.zip)

Changes:

*   Added [save game exploit](#save-game-exploit) support for Doki Oki (NTSC-J), Crash Bandicoot 3 (NTSC-J), and The Legend Of Heroes I&II (NTSC-J). All these save game exploits were found by [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714).

### Version 1.0.4 (7/23/2022)

*   [tonyhax-v1.0.4-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.4i/tonyhax-v1.0.4-international.zip)

## Usage

The Tonyhax International loader is the program that is booted on any PS1 or an early PS2 that enables the use of backup CD-Rs or import PS1 discs. The Tonyhax International loader can be booted on your PS1 with a [GameShark/cheat cart](#romrom-flasher-cd), [flashed memory card](#freepsxboot-exploit-memory-card-images), [save game exploit](#save-game-exploit), or [CD-R](#boot-cd). It provides the ability to properly play backup and import discs on all PS1 consoles, and early PS2 consoles (Japanese, USA, and PAL models SCPH-10000-SCPH-39004).

If you are using **any Japanese console**, at least one real Japanese NTSC-J PS1 game disc is required (any officially licensed Japanese PS1 disc will do). If you are using a **Japanese PS2 console (SCPH-10000-SCPH-3900-)** a Swap Magic Tool is also required. Neither of these are needed if you are using an American or European PS1/PS2 console.

### Japanese PS1 Console Loader Instructions

Boot into the Tonyhax International loader using one of the boot methods below:

*   [ROM/ROM Flasher CD](#romrom-flasher-cd)
*   [FreePSXBoot Memory Card Images](#freepsxboot-exploit-memory-card-images)
*   [Boot CD](#boot-cd)
*   [Save Game Exploit](#save-game-exploit)

If you see the text `Put in a real NTSC-J PSX game disc, then block the lid sensor`:

*   Open the CD drive of your PS1 console.
*   Put in a real NTSC-J Japanese PS1 game disc in the CD drive, but don't close the CD drive lid.
*   The lid sensor is highlighted by the red circle and arrow in the pictures below. On the original grey fat PS1 consoles (SCPH-900X and earlier) it is located in the top right corner, it is is shaped like a circle. Ideally you press it down with a bent pen spring as shown. On the slim PSone consoles (SCPH-10X) it is in the lower right corner to the side of the edge of the CD drive. For these consoles it is best to use a piece of tape or paper to slide in and press it down as shown.

![ps1 lid sensor](images/ps1-lid-sensor.jpg)

![ps1 lid sensor blocked front](images/ps1-lid-sensor-blocked-front.jpg)

![ps1 lid sensor blocked side](images/ps1-lid-sensor-blocked-side.jpg)

![psone lid sensor](images/psone-lid-sensor.jpg)

![psone lid sensor blocked](images/psone-lid-sensor-blocked.jpg)

After blocking the lid sensor, your real Japanese PS1 game will spin up and then stop. Once you see the text `Put in a backup/import disc, then press X` remove either the real NTSC-J PSX game disc or Boot CD from your PS1 console's CD drive. Put in the backup CD-R or import PSX game disc you want to play **without unblocking the lid sensor**. Once you press X, the console will run some commands automatically, followed by the game booting with perfect CD audio playback. Note that you can not unblock the lid sensor while playing the game on **Japanese consoles**, if you do so the game will stop working.

### Playing Games That Span Multiple Discs On Japanese PS1 Consoles

There are some games which span multiple discs. And some of these games (such as Parasite Eve, Fear Effect, and Crono Cross) that span multiple discs require you to open the CD drive, remove disc 1, insert disc 2, and close the CD drive at some point in the game without providing a save game option at the disc swap. If you encounter this type of game on a Japanese PS1 console you have to do the "mid-game hot-swap trick":

*   When the game asks you to insert disc 2, unblock the lid sensor and remove the CD.
*   Put **any real authentic Japanese PSX disc** into the PS1 drive.
*   You will now be performing a _mid-game hot-swap trick_. Have the disc 2 you want to play in one hand, and whatever your using to block the lid sensor in another. Now block the lid sensor, freeing your one hand. Wait until the original real Japanese PSX disc stats spinning fast (~3 seconds) and **immediately** swap the disc with your free hand, and put in the actual disc 2 you want to play. You can now continue playing your game that spans multiple discs normally! This trick would work for games that span even more then 2 discs as well.

It is important to note however that most games that span multiple discs allow you to load a game save created on disc 1 while playing disc 2. This means you just need to save at the last point possible on disc 1, and then you can just boot disc 2 like normal and load your game save created earlier on disc 1. **Some games however do not allow this** as previously mentioned, so for those games you must use the **mid-game hot-swap trick** described above.

### Japanese PS2 Console Loader Instructions

Available Boot Methods:

*   [Boot CD](#boot-cd) (I don't know of anyway to boot this on an unmodified Japanese PS2 but it is available).
*   [Save game exploit](#save-game-exploit)

Japanese PS2 consoles **must have the DVD drive tray front panel removed to use Tonyhax International**. For the SCPH-10000, you can follow the method below (some newer consoles may slightly differ in the way to remove the DVD drive's front panel).

### Removing The DVD Drive Tray Front Panel

Turn on the Japanese PS2 console. Eject the DVD drive tray, and **while it is open** power off the console by either pulling the plug from the wall or PSU in the back of the console, or by flicking the power switch for the PSU on the back of the console. You can not use the power button because then the DVD drive tray will close before the console turns off. Now, flip the Japanese PS2 console upside down like in the image below:

![ps2 upside down](images/ps2-upside-down.jpg)

Now bring your focus to the bottom of the opened DVD drive tray. At the very top edge (highlighted in the picture above) is a tab. You want to jam a thin flat head screwdriver in between this tab and the DVD drive tray face plate as shown in the image below. Now, push with the flat head screwdriver to separate the DVD drive face plate from the rest of the DVD drive tray. **Be very gentle and only use a direct straight force towards the face plate. Do not go side to side when doing this or you risk breaking off an edge of the DVD drive tray. I am obviously not responsible for any damage you may do by doing this!** Once successful, the face plate will become removable. You are free to slide it back on at a later time, it just needs to be off for you to use the Japanese PS2 to boot backup/import PS1 games with Tonyhax International.

![ps2 drive tab](images/ps2-drive-tab.jpg)

With the DVD drive face plate off, flip over the Japanese PS2 console right side up. You can now see a gap at the bottom of the DVD drive. This is where you place the Swap Magic Tool in when using Tonyhax International on your Japanese PS2 console.

![ps2 drive cover removed](images/ps2-drive-cover-removed.jpg)

You can now use one of the supported boot methods to start the Tonyhax International loader on the Japanese PS2 console. You will most likely be using the [Save Game Exploit](#save-game-exploit), however you could be using some kind of intermediate boot disc to boot the [Boot CD](#boot-cd) as well if you find one that supports Japanese PS1 consoles. Once you see the text `Put in a backup/import disc, then press X` appear, you need to use a Swap Magic Slide Tool to release the DVD drive to gain access to it without pressing the eject switch. A [video tutorial](https://www.youtube.com/watch?v=Ffv5m52zlEI) is available that shows how to use the Swap Magic Tool (in general), although the exact steps are also explained below. Once you use the Swap Magic Tool to swap in your import/backup CD-R while booted in the Tonyhax International loader, just press the cross button on your PS2 or PS1 controller to boot and play your game.

Important note: **do not eject the PS1 import or backup CD-R from the Japanese PS2 console until your done playing the game**. Unlike American and European consoles (which do not have this limitation), if you do so your game will stop working, and you will have to start Tonyhax International all over again to boot your import/backup CD-R and start playing again.

### Using the Swap Magic Tool

Slide in the Swap Magic Tool like shown in the image below by the arrow. You need to feel around with the Swap Magic Tool to get the hook to latch on internally inside the DVD drive.

![ps2 insert slide tool](images/ps2-insert-slide-tool.jpg)

Now that your Swap Magic Tool is latched on internally inside the DVD drive, move it straight to the right side. This movement will feel correct and nice when you are properly using the Swap Magic Tool, reassuring you are using it correctly. Once you get to the end of this movement the DVD drive tray will begin to move forward out of the DVD drive, "releasing" it from it's locked state.

![ps2 slide tool inserted first slide](images/ps2-slide-tool-inserted-first-slide.jpg)

![ps2 slide tool moved to release drive](images/ps2-slide-tool-moved-to-release-drive.jpg)

Use your hand to pull out the DVD drive tray to gain access to the disc in it. Remove the original NTSC-J PSX game disc, and put in your import/backup CD-R.

![ps2 drive released](images/ps2-drive-released.jpg)

With your import/backup CD-R in the Japanese PS2 console, use your hand to push in the DVD drive tray as far as it will go back into the DVD drive.

![ps2 push in released drive](images/ps2-push-in-released-drive.jpg)

Now that the DVD drive tray is pushed all the way back in, the Swap Magic Tool can be used to "lock" the drive. Like before, slide in the Swap Magic Tool to the right most position like shown in the image below. Remember to feel around with the Swap Magic Tool to get the hook to latch on internally inside the DVD drive. Now that your Swap Magic Tool is once again latched on internally inside the DVD drive, move it straight to the left side. This movement will feel correct and nice when you are properly using the Swap Magic Tool, reassuring you are using it correctly. Once you get to the end of this movement (when you can't go any more to the left) the DVD drive tray will fully go back inside the DVD drive to put the DVD drive into the "locked" state.

![ps2 slide tool moved to lock drive](images/ps2-slide-tool-moved-to-lock-drive.jpg)

### Playing Games That Span Multiple Discs on Japanese PS2 Consoles

There are some games which span multiple discs. And **some of these games** (such as Parasite Eve, Fear Effect, and Crono Cross) that span multiple discs require you to open the CD drive, remove disc 1, insert disc 2, and close the CD drive at some point in the game. **Unfortunately only for Japanese PS2 consoles, you can not do this with Tonyhax International.** If you get to a point in a game that requires ejecting the drive and putting in a new game, you have to play this part of the game on a different console (Any PS1 or American/European PS2 works). It is important to note however that most games that span multiple discs allow you to load a game save created on disc 1 while playing disc 2. This means you just need to save at the last point possible on disc 1, and then you can just boot disc 2 with Tonyhax International like normal and load your game save created earlier on disc 1, bypassing this limitation for certain games that allow saving right at disc swap mid-game.

### Playing PAL Region Games On Japanese PS2 Consoles

The early PS2 models that Tonyhax International supports have the PS1 mode which runs PS1 software hard-coded to NTSC video mode. This can cause a problem with Tonyhax International if you want to play a European/PAL PS1 backup CD-R or import disc on a Japanese PS2 in PAL video mode. Since PS1 software can not change the video mode correctly from PS1 mode running on a PS2, you have to resort to the **PS2 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/)**. This software allows you to explicitly change the video mode to PAL. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects. Here are the steps below to change your Japanese PS2 console to PAL video mode for Tonyhax International:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.
*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Put in the real Japanese PS1 game disc that you are using with a [save game exploit.](#save-game-exploit) when in PS1VModeNeg. The video mode will be forced to PAL now in the PS1 mode of your Japanese PS2.
*   Playing through your Japanese PS1 game disc may look or act weird in PAL video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in a PAL region import disc or PAL region backup CD-R and the PAL PS1 game will boot in PAL video mode.

## American/European PS1/PS2 Console Loader Instructions

Available boot methods for American and European PS2 consoles:

*   [Boot CD](#boot-cd) (you can use something like the code breaker pro PS1 disc to boot it first)
*   [Save game exploit](#save-game-exploit)

Available boot methods for American and European PS1 consoles:

*   [ROM Flasher CD](#romrom-flasher-cd)
*   [FreePSXBoot Memory Card Images](#freepsxboot-memory-card-images)
*   [Boot CD](#boot-cd)
*   [Save Game Exploit](#save-game-exploit)

Once you see the text `Put in a backup/import disc` appear, eject the DVD drive (PS2) or open the CD drive (PS1).

*   If you are booting the Tonyhax International [Boot CD](#boot-cd), you'll want to remove the spring or whatever you have blocking down the lid sensor to "open" the CD drive and stop the disc from spinning, allowing you to remove the Boot CD from the console's CD drive (PS1) or DVD drive (PS2).
*   If you are booting Tonyhax International via a [Save Game Exploit](#save-game-exploit), after ejecting the DVD drive (PS2) or opening the CD drive (PS1) the real PS1 game disc you used with a save game exploit will stop spinning, allowing you to remove it from the console's CD drive (PS1) or DVD drive (PS2).

All other boot methods don't have a disc usually in the drive already, so there is no disc to remove. With no disc currently in your console, you can now put in the backup CD-R or import PSX game disc you want to play. Close the CD drive (PS1) or DVD drive (PS2). The console will detect that the drive has been closed and will spin up your disc. The console will then send some commands and boot the disc.

## Playing Games That Span Multiple Discs On American/European PS1/PS2 Consoles

All American and European consoles do not have the same limitations as the Japanese consoles and can play games that span multiple discs like normal.

## Playing PAL Games On American PS2 Consoles

The early PS2 models that Tonyhax International supports have the PS1 mode which runs PS1 software hard-coded to NTSC video mode. This can cause a problem with Tonyhax International if you want to play a European/PAL PS1 backup CD-R or import disc on a American PS2 in PAL video mode. Since PS1 software can not change the video mode correctly from PS1 mode running on a PS2, you have to resort to the **PS2 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/)**. This software allows you to explicitly change the video mode to PAL. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects. Here are the steps below to change your American PS2 console to PAL video mode for Tonyhax International:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.
*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Put in the real American PS1 game disc that you are using with a [save game exploit.](#save-game-exploit) when in PS1VModeNeg. The video mode will be forced to PAL now in the PS1 mode of your American PS2.
*   Playing through your American PS1 game disc may look or act weird in PAL video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in a PAL region import disc or PAL region backup CD-R and the PAL PS1 game will boot in PAL video mode.

## Playing Japanese/American Games On PAL PS2 Consoles

The early PS2 models that Tonyhax International supports have the PS1 mode which runs PS1 software hard-coded to NTSC video mode. This can cause a problem with Tonyhax International if you want to play a Japanese/American PS1 backup CD-R or import discs on a PAL PS2 in NTSC video mode. Since PS1 software can not change the video mode correctly from PS1 mode running on a PS2, you have to resort to the **PS2 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/)**. This software allows you to explicitly change the video mode to PAL. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects. Here are the steps below to change your PAL PS2 console to NTSC video mode for Tonyhax International:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.
*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Put in the real PAL PS1 game disc that you are using with a [save game exploit.](#save-game-exploit) when in PS1VModeNeg. The video mode will be forced to NTSC now in the PS1 mode of your PAL PS2.
*   Playing through your PAL PS1 game disc may look or act weird in NTSC video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in a NTSC disc and the NTSC PS1 import or backup disc will boot in NTSC video mode.

## Rom/ROM Flasher CD

You can overwrite the contents of a GameShark, Action Reply, or other PS1 cheat cartridge with the Tonyhax International ROM using a simple flasher CD-R that you burn or a combination of a home-made serial to USB cable, PC, and special program booted on your target PS1 console that supports flashing cheat cartridges over serial.

When you turn on any PS1 console with the flashed GameShark/Action Reply/cheat device installed to it's parallel port at the back the console, the system will instead boot into the Tonyhax International loader, rather then the BIOS/Shell (Sony screens/Memory Card/CD Player menu). A PS1 cheat cartridge flashed with the Tonyhax International ROM is essentially a plug and play modchip without any hardware modifications whatsoever.

### Requirements

*   GameShark, Action Reply, or other cheat cart that you are willing to overwrite with the Tonyhax International ROM.
*   A PS1 console with a parallel port for installing the GameShark or other cheat cart (SCPH-1000-SCPH-7502).
*   Blank CD-R (if burning a ROM flasher CD) or a serial cable, PC, and software which supports flashing a PS1 cheat cartridge over serial.

### How To Flash Your GameShark/Action Reply/Cheat Cart

Inside the Tonyhax International releases ([download](#downloads) above) in the `rom` directory are the following files:

*   tonyhax-rom-flasher.bin
*   tonyhax-rom-flasher.cue
*   tonyhax-v1.1.0-international.rom

The BIN+CUE files can be burned to a CD-R. The BIN+CUE files contain the [NXFlash](https://github.com/danhans42/nxflash) PS1 executable with the `tonyhax-v1.0.8-international.rom` file. This means when you boot the burned flasher CD-R on your PS1 console, you can connect your GameShark/cheat device and press the `R2` button (`RE-DETECT EEPROM`) to allow NXFLASH to detect the newly connected cheat cart. Next press the `start` button (`FLASH EEPROM FROM CD`), and then press X to flash your GameShark/Cheat device. Now you can simply reset or power off then power on your PS1 console and it will boot Tonyhax International from the GameShark/cheat cart immediately.

![rom flasher cd 1](images/rom-flasher-cd-1.jpg)

![rom flasher cd 2](images/rom-flasher-cd-2.jpg)

If you have an old enough PlayStation console you can simply use the CD Player Swap Trick method to start the NXFlasher CD containing the Tonyahx International ROM. These PlayStation models have the CD Player Swap Trick:

*   All SCPH-1000 consoles.
*   Early SCPH-3000 consoles. Compatible consoles have System BIOS v1.1J and CDROM Controller VC0B (example serial number: `A6956171`. Incompatible consoles have System BIOS v2.1J and CDROM Controller VC1B (example serial number: `A7543968`).
*   Early SCPH-1001 consoles. These consoles have a serial number lower then `U592XXXX` (where X can be any number) according to the original [Swap Trick Guide](https://gamefaqs.gamespot.com/ps/916392-playstation/faqs/4708) from 1996. These consoles are either System BIOS v2.0A and CDROM Controller VC1A (example serial number: `U5361469`, July 1995 manufacture date) or System BIOS v2.1A and CDROM Controller VC1A (example serial number: `U5860989`, October 1995 manufacture date).
*   Early SCPH-1002 consoles. No serial number based info is available for this console model at this time. There also appears to be no date of manufacture available (like Japanese consoles), so it is truly a roll of the dice if a specific SCPH-1002 console has the CD Player Swap Trick or not.

To boot the ROM Flasher CD with the CD Player Swap Trick:

*   Turn on the PlayStation with no game in it.
*   Start the CD player.
*   Open the PlayStation's lid, and put in a real PlayStation game that matches your console's region and plays normally.
*   Find something to block the lid sensor. The real PlayStation game will start and then stop spinning.
*   Once the real PlayStation game stops spinning, put in your burned ROM Flasher CD-R disc.
*   Exit the CD Player menu, and wait for NXFlash to start.

FreePSXBoot Exploit Memory Card Images
--------------------------------------

Memory card files are included in the `freepsxboot` directory found in the Tonyhax International releases ([downloadable](#downloads) above) for **all BIOS versions**. These memory card files must be 'restored' (a.k.a. written raw) to a PSX memory card. One such way to do this is to use [Memory Card Annihilator v2.0](https://www.ps2-home.com/forum/viewtopic.php?t=116) with a modded PS2 console and USB flash drive containing the memory card file. Please note that at this time Memory Card Annihilator v2.0 does not work on the SCPH-10000 or SCPH-18000 due to not having an expansion bay (which is not accounted for by the software). Anyways for all SCPH-30000 and newer PS2 consoles here are the steps below to flash your PS1 memory card with the Memory Card Annihilator homebrew software:

### Requirements

*   PS2 console that can run [wLaunchELF/uLaunchELF and](https://www.psx-place.com/resources/wlaunchelf.713/) [Memory Card Annihilator v2.0](https://www.ps2-home.com/forum/viewtopic.php?t=116). You need to soft-mod with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use these programs on your PS2 console.
*   Any PS1 console.
*   An authentic PS1 memory card you are willing to dedicate to the FreePSXBoot exploit.
*   A fat 32 formatted USB flash drive that your PS2 console can read (**not all USB flash drives seem to work**).

### Flashing The PS1 Memory Card Image To A PS1 Memory Card

Copy the correct memory card file for your PSX console's BIOS version from the `freepsxboot` directory found in Tonyhax international releases downloadable above to a FAT32 formatted USB flash drive that your PS2 console can read. **It is highly recommend to use the slot 2 memory card files as they do not require you to remove the memory card once booted into the Tonyhax International loader.**

Console models and the BIOS versions they contain are listed below:

*   SCPH-1000 - BIOS-1.0-1994-09-22-I
*   SCPH-1001 - BIOS-2.0-1995-05-07-A, BIOS-2.1-1995-07-17-A, or BIOS-2.2-1995-12-04-A
*   SCPH-1002 - BIOS-2.0-1995-05-10-E, BIOS-2.1-1995-07-17-E, or BIOS-2.2-1995-12-04-E
*   SCPH-3000 - BIOS-1.1-1995-01-22-I or BIOS-2.1-1995-07-17-I
*   SCPH-3500 - BIOS-2.1-1995-07-17-I
*   SCPH-5000 - BIOS-2.2-1995-12-04-I
*   SCPH-5001 - BIOS-3.0-1996-11-18-A
*   SCPH-5003 - BIOS-2.2-1995-12-04-A
*   SCPH-5500 - BIOS-3.0-1996-09-09-I
*   SCPH-5501 - BIOS-3.0-1996-11-18-A
*   SCPH-5502 - BIOS-3.0-1997-01-06-E
*   SCPH-5503 - BIOS-3.0-1996-11-18-A
*   SCPH-5552 - BIOS-3.0-1997-01-06-E
*   SCPH-5903 - BIOS-2.2-1995-12-04-A
*   SCPH-7000 - BIOS-4.0-1997-08-18-I
*   SCPH-7001 - BIOS-4.1-1997-12-16-A
*   SCPH-7002 - BIOS-4.1-1997-12-16-E
*   SCPH-7003 - BIOS-3.0-1996-11-18-A
*   SCPH-7500 - BIOS-4.0-1997-08-18-I
*   SCPH-7501 - BIOS-4.1-1997-12-16-A
*   SCPH-7502 - BIOS-4.1-1997-12-16-E
*   SCPH-7503 - BIOS-4.1-1997-12-16-A
*   SCPH-9000 - BIOS-4.0-1997-08-18-I
*   SCPH-9001 - BIOS-4.1-1997-12-16-A
*   SCPH-9002 - BIOS-4.1-1997-12-16-E
*   SCPH-9003 - BIOS-4.1-1997-12-16-A
*   SCPH-9903 - BIOS-4.1-1997-12-16-A
*   SCPH-100 - BIOS-4.3-2000-03-11-I
*   SCPH-101 - BIOS-4.4-2000-03-24-A or BIOS-4.5-2000-05-25-A
*   SCPH-102 - BIOS-4.4-2000-03-24-E or BIOS-4.5-2000-05-25-E
*   SCPH-103 - BIOS-4.5-2000-05-25-A

If you have a PSX console that can have multiple different BIOS versions, you may have to try each different memory card file one by one until you figure out what BIOS version you need for your PSX console.

After the correct memory card file is copied to the USB flash drive that your PS2 can read:

*   Download the [Memory Card Annihilator v2.0](https://www.ps2-home.com/forum/viewtopic.php?t=116) and extract it's .elf file.
*   Copy the Memory Card Annihilator v2 .elf file to a FAT32 formatted USB flash drive that your PS2 console can read.
*   Insert the PSX memory card and USB flash drive with the PS2 console off. Boot your modded PS2 (FreeHDBoot or FreeMCBoot, or something like that is required) and start the uLaunchElf program.
*   Navigate to the "mass" device and launch the Memory Card Annihilator v2 .elf file you previosly copied to the USB flash drive.
*   Select your PS1 memory card in the menu and then select restore. In the file picker navigate to the memory card file you copied to the USB flash drive previously.
*   Wait for the restore to complete and press X. Remove your memory card and put it into either Slot 1 or Slot 2 of your PS1 console depending on what memory card image you use.

Now you can turn on your PSX console without a disc in it, and then select the `Memory Card` option in the PS1's startup menu. This will start the Tonyhax international loader. **At this point, if you are using a FreePSXBoot memory card in slot 1 you must remove the FreePSXBoot memory card from slot 1 once the loader starts to ensure successful booting of your backup or import. If you are using a FreePSXBoot memory card in slot 2 you can just leave it in your console at all times**, no need to remove it! It will be disabled from use after booting a game with Tonyhax International.

## Boot CD

CD BIN+CUE files containing the Tonyhax International loader are available in each Tonyhax International release. The Boot CD can be booted by a swap trick, or an unofficial boot disc (i.e. PSX Change v2). Inside the Tonyhax International releases (downloadable above) in the `boot-cd` directory are the following files:

*   tonyhax-boot-cd-europe.bin
*   tonyhax-boot-cd-europe.cue
*   tonyhax-boot-cd-japan.bin
*   tonyhax-boot-cd-japan.cue

If you have a SCPH-102 use the `tonyhax-boot-cd-europe` BIN+CUE files. For every other console you can use the `tonyhax-boot-cd-japan` BIN+CUE file set.

## CD Player Swap Trick

If you have an old enough PlayStation console you can just use the CD Player Swap Trick to start the Tonyhax International Boot CD. This is in fact what I had in mind when I added the initial Boot CD support to the original Tonyhax. These PlayStation models have the CD Player Swap Trick:

*   All SCPH-1000 consoles.
*   Early SCPH-3000 consoles. Compatible consoles have System BIOS v1.1J and CDROM Controller VC0B (example serial number: `A6956171`. Incompatible consoles have System BIOS v2.1J and CDROM Controller VC1B (example serial number: `A7543968`).
*   Early SCPH-1001 consoles. These consoles have a serial number lower then `U592XXXX` (where X can be any number) according to the original [Swap Trick Guide](https://gamefaqs.gamespot.com/ps/916392-playstation/faqs/4708) from 1996. These consoles are either System BIOS v2.0A and CDROM Controller VC1A (example serial number: `U5361469`, July 1995 manufacture date) or System BIOS v2.1A and CDROM Controller VC1A (example serial number: `U5860989`, October 1995 manufacture date).
*   Early SCPH-1002 consoles. No serial number based info is available for this console model at this time. There also appears to be no date of manufacture available (like Japanese consoles), so it is truly a roll of the dice if a specific SCPH-1002 console has the CD Player Swap Trick or not.

To boot the Tonyhax International Boot CD-R with the CD Player Swap Trick:

*   Turn on the PlayStation with no game in it.
*   Start the CD player.
*   Open the PlayStation's lid, and put in a real PlayStation game that matches your console's region and plays normally.
*   Find something to block the lid sensor. The real PlayStation game will start and then stop spinning.
*   Once the real PlayStation game stops spinning, put in your burned Tonyhax International Boot CD-R disc.
*   Exit the CD Player menu, and wait for the Tonyhax International loader to start.

## Save Game Exploit

The original way to boot the Tonyhax International loader is with _a special game save file_ that is placed on a PS1 memory card that you load while playing a [specific, supported authentic PS1 game disc](#save-game-exploit-supported-games-list) on your console. To use this boot method, you need:

* A [supported authentic/'black' PS1 game disc](#save-game-exploit-supported-games-list) that your console can boot normally.

* A softmodded PS2 console capable of copying files from a USB flash drive or other storage device to a PS1 memory card. There are alternative methods to place the required files on a PS1 memory card with other hardware available, but the softmodded PS2 method is what is documented here in these instructions and what I use.

* A PS1 memory card with enough space for the special save game exploit file and for the Tonyhax International loader filed.

You need to copy the _Tonyhax International Loader_ file and the _Save Game Exploit_ file (specific to your exact exploitable PSX game disc) to the PS1 memory card. Then you can load the _Save Game Exploit_ file in a specific way tp trigger the exploit and start the Tonyhax International loader. Described below are 2 different methods to copy these files to a PS1 memory card. One involves using a PS2, the other involves using special hardware that allows you to write to PS1 memory cards connected directly to your computer.

### PS2 Installation Method

You can use a PS2 console to copy the save game exploit files to a PS1 memory card from a USB flash drive.

Requirements:

* A FAT32 formatted USB flash drive that your PS2 console can read. Please note that not all USB flash drives seem to work with PS2 consoles (due to iffy USB 1.1 support found in some newer USB flash drives). You may need to do a bit of trial and error testing to find a USB flash drive that works.

* A soft-modded (or modchipped) PS2 console that can run uLaunchELF (Models newer then the SCPH-39004 can therefore be used for copying the files to the PS1 memory card, but they can not be used to boot into Tonyhax International). You could do this with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248).

You want to **use the RAW save game exploit file for your exploitable game (in the `entrypoints` directory) and the RAW loader file (in the `loader` directory)** when using this installation method. The RAW filenames are in the [list below](#save-game-exploit-supported-games-list).

Installation:

* Copy the `Tonyhax International Loader RAW File` file and the `Save Game Exploit RAW` file to the FAT32 USB flash drive using a computer.

* Eject the USB flash drive from your computer and insert it into your PS2 console. Insert a PS1 memory card into your PS2 as well. 

* Start the uLaunchElf homebrew program on your PS2 console. Navigate to the `mass` device (this is your USB flash drive) with the `DPAD` on the controller, then select it with the `circle` button. 

* Using the `DPAD` to navigate, press the `cross` button on the controller to highlight both the `Tonyhax International Loader RAW` file and the `Save Game Exploit RAW` file that you previously copied to the USB flash drive. Press the `R1` button on the controller to make the file operations menu appear in uLaunchELF. Use the `DPAD` to move to the copy function and then press the `circle` button to select it.

* Press the `triangle` button to navigate out of the `mass` device. Use the `DPAD` and the circle button to navigate into either the `MC0` (if the PS1 memory card is in slot 1 of the PS2) or `MC1` (if the PS1 memory card is in slot 2 of the PS2) device. 

* Press the `R1` button to again make the file operations menu appear in uLaunchElF. Use the `DPAD` to navigate to the paste option and press the `circle` button to finally paste both the Tonyhax International Loader RAW File` file and the `Save Game Exploit RAW` file. Now you can press the `triangle` button to navigate out of the PS1 memory card device, and remove the memory card from the PS2 console (if you want to use it in a different console).

### PS3 Memory Card USB Adapter/DexDrive/Computer Installation Method

You can use a Dex Drive (or similar hardware which connects a PS1 memory card to your computer) in combination with a visual memory card editor (such as [OrionSoft's PS1 Memory Card Manager](http://onorisoft.free.fr/retro.htm?psx/psx.htm) or [Dex-plorer](https://archive.org/details/inter-act-dex-plorer-ver.-1.10.950)), to place the save game exploit and Tonyhax International loader files on the PS1 memory card. This method requires:

*   A DexDrive, PS3 Memory Card USB adapter, or other hardware that allows you to write and modify a PS1 memory card with a computer.
*   Software such as [OrionSoft's PS1 Memory Card Manager](http://onorisoft.free.fr/retro.htm?psx/psx.htm) (for the PS3 Memory Card USB adapter) or [Dex-plorer](https://archive.org/details/inter-act-dex-plorer-ver.-1.10.950) (for the DexDrive), or [MemcardRex](https://github.com/ShendoXT/memcardrex) (for general memory card file managment and manipulation).

You want to **use the MCS save game exploit file for your exploitable game (in the `entrypoints` directory) and the MCS loader file  (in the `loader` directory)** when using this installation method. The MCS filenames are in the list below.

## Save Game Exploit Supported Games List

_Notes:_ 

* Demo versions of games do not contain load/save game functions and are hence not exploitable.

* Some games have multiple different versions of the same regional release (Rev 0, Rev 1, etc.). Sometimes, one save game exploit file won't work on both versions and multiple different save game exploit files are required. Some specific game/version combinations also do not have a save game exploit file available yet, this is a work in progress. Please see each listing below to see if this is the case for your specific game.

* If you are using a Japanese PSX, it is recommended that you power off the console, put in the Japanese version of the game that has a save game exploit file available, block the lid sensor, and then turn on the console and have it boot the authentic PSX game disc which has a supported save game exploit. 

* The _Exploit Instructions_ in each game listing below explain the game specific steps to trigger the exploit which starts the Tonyhax International loader.

* The _Save Game Exploit_ file can be on a memory card inserted in slot 1 or slot 2 of your console (as long as the game supports loading a save game file from slot 2, **otherwise it must be in slot 1**).

* The _Tonyhax International Loader_ file **must be on a memory card inserted in slot 1** of your console.

### Brunswick Circuit Pro Bowling

* Versions Tested: [USA](http://redump.org/disc/13370/), [Europe](http://redump.org/disc/27347/).
* Versions With Save Game Exploit Support: USA, Europe.
* Save Game Exploit RAW file: `entrypoints/BASLUS-00571` (USA) or `entrypoints/BESLES-01376` (Europe).
* Save Game Exploit MCS file: `entrypoints/brunswick1-us.mcs` (USA) or `entrypoints/brunswick1-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`
* Exploit Instructions: At the main menu select `Load Game` and then the _Save Game Exploit_ file to trigger the exploit.

### Brunswick Circuit Pro Bowling 2

* Versions Tested: [USA](http://redump.org/disc/18447/), [Europe](http://redump.org/disc/11481/).
* Versions With Save Game Exploit Support: USA, Europe.
* Save Game Exploit RAW file: `entrypoints/BASLUS-00856` (USA) or `entrypoints/BESLES-02618` (Europe).
* Save Game Exploit MCS file: `entrypoints/brunswick2-us.mcs` (USA) or `entrypoints/brunswick2-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: At the main menu select `Load Game` and then the _Save Game Exploit_ file to trigger the exploit.

### Castlevania Chronicles

* Versions Tested: Japan ([Rev 0](http://redump.org/disc/7481/), [Rev 1](http://redump.org/disc/11230/)), [USA](http://redump.org/disc/9474/), [Europe](http://redump.org/disc/1117/).
* Versions With Save Game Exploit Support: Japan Rev 0, USA. **Japan Rev 1 and Europe versions are not yet supported**.
* Save Game Exploit RAW file: `entrypoints/BISLPM-86754DRACULA` (Japan) or `entrypoints/BASLUS-01384DRACULA` (USA).
* Save Game Exploit MCS file: `entrypoints/cc-jp.mcs` (Japan Rev 0) or `entrypoints/cc-us.mcs` (USA).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: At the title screen, select `ORIGINAL MODE`. Go through the intro text, and at the next title screen select `START GAME` to trigger the exploit.

### Castrol Honda Super Bike Racing

* Versions Tested: [Japan](http://redump.org/disc/33156/), [USA](http://redump.org/disc/78231/), [Europe](http://redump.org/disc/25546/).
* Versions With Save Game Exploit Support: Japan, USA, Europe.
* Save Game Exploit RAW file: `entrypoints/BISLPM-86489CHSv1` (Japan), `entrypoints/BASLUS-00882CHSv1` (USA), or `entrypoints/BESLES_01182CHSv1` (Europe).
* Save Game Exploit MCS file: `entrypoints/castrolsb-jp.mcs` (Japan), `entrypoints/castrolsb-us.mcs` (USA), or `entrypoints/castrolsb-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit instructions: If you are using the 'Europe' version select the English language in the language selection screen. On the main menu, choose Options. Select `Load Game` and load the _Save Game Exploit_ file. Back at the main menu, select either the `Single Race` or `Championship` option to trigger the exploit.

### Castrol Honda VTR

* Versions Tested: [Japan](http://redump.org/disc/37769/), [Europe](http://redump.org/disc/29332/).
* Versions With Save Game Exploit Support: Japan, Europe.
* Save Game Exploit RAW file: `entrypoints/BISLPM-86922CHSVTRv1` (Japan), `entrypoints/BESLES-02942CHSVTRv1` (Europe).
* Save Game Exploit MCS file: `entrypoints/castrolvtr-jp.mcs` (Japan), `entrypoints/castrolvtr-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit instructions: If you are using the 'Europe' version select the English language in the language selection screen. On the main menu, choose Options. Select `Load Game` and load the _Save Game Exploit_ file. Back at the main menu, select either the `Single Race` or `Championship` option to trigger the exploit.

### Cool Boarders 4

* Versions Tested: [Japan](http://redump.org/disc/4556/), [USA](http://redump.org/disc/5398/), [Europe](http://redump.org/disc/29332/).
* Versions With Save Game Exploit Support: USA, Europe. **Japan version is not yet supported.**
* Save Game Exploit RAW file: `entrypoints/BASCUS-9455916` (USA), `entrypoints/BESCES-0228316` (Europe).
* Save Game Exploit MCS file: `entrypoints/coolbrd4-us.mcs` (USA), `entrypoints/coolbrd4-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: When you get to the title screen, it should say that the records and settings have been automatically loaded. Select the `ONE PLAYER` option to trigger the exploit.

### Crash Bandicoot 2: Cortex Strikes Back

* Versions Tested: [Japan](http://redump.org/disc/2688/), [USA](http://redump.org/disc/2688/), [Europe](http://redump.org/disc/1056/), [Europe EDC](http://redump.org/disc/14827/).
* Versions With Save Game Exploit Support: Japan, USA, Europe, Europe EDC.
* Save Game Exploit RAW file: `entrypoints/BISCPS-1004700000000` (Japan), `entrypoints/BASCUS-9415400047975` (USA), `entrypoints/BESCES-0096700765150` (Europe/Europe EDC).
* Save Game Exploit MCS file: `entrypoints/crash2-jp.mcs` (Japan), `entrypoints/crash2-us.mcs` (USA), `entrypoints/crash2-eu.mcs` (Europe Rev 0 **and** Europe Rev 1).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: At the titlescreen select the `LOAD GAME` option. In the save game list, select the _Save Game Exploit_ file (named TONYHAX) to trigger the exploit.

### Crash Bandicoot 3: Warped

* Versions Tested: [Japan](http://redump.org/disc/3576/), [USA](http://redump.org/disc/5006/), [Europe](http://redump.org/disc/248/).
* Versions With Save Game Exploit Support: USA, Europe. **Japan version is not yet supported.**
* Save Game Exploit RAW file: `entrypoints/BASCUS-9424400000000` (USA), `entrypoints/BESCES-0142000000000` (Europe).
* Save Game Exploit MCS file: `entrypoints/crash3-us.mcs` (USA), `entrypoints/crash3-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: At the titlescreen select the `LOAD GAME` option. In the save game list, select the _Save Game Exploit_ file (named TONYHAX) to trigger the exploit.

### Dokiou-ki

* Versions Tested: [Japan](http://redump.org/disc/3982/).
* Versions With Save Game Exploit Support: Japan.
* Save Game Exploit RAW file: `entrypoints/BISLPS-00130DOKIOH` (Japan).
* Save Game Exploit MCS file: `entrypoints/dokiou-ki-jp.mcs` (Japan).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`
* Exploit Instructions: At the title screen, load the _Save Game Exploit_ file. If you don't know Japanese, you can just keep spamming the confirm button (`O`) to navigate through the menu and load the _Save Game Exploit_ file.

### Downhill Snow

* Versions Tested: [Japan](http://redump.org/disc/34593/).
* Versions With Save Game Exploit Support: Japan.
* Save Game Exploit RAW file: `entrypoints/BISLPS-01391SKI00S` (Japan).
* Save Game Exploit MCS file: `entrypoints/downhill-snow-jp.mcs` (Japan).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/doki-oki-jp.mcs`.
* Exploit Instructions: At the title screen, select `SCENARIO`, then `CONTINUE`. In the memory card file display screen select the _Save Game Exploit_ file. After loading the save game exploit file, select `CONFIG`, then `RANKING`, then `Moguls`. **Immeditely after select Moguls press the right directional key until the blue screen appears, then let go of all buttons on the controller.**

### Final Fantasy IX (Disc 1)

_Note_ Final Fantasy IX has 2 different types of exploits. Exploit type A works on consoles with BIOS versions 1.0-2.0. Exploit type B works on all newer BIOS versions (v2.1 to 5.0). 

Consoles with BIOS v1.0-v2.0:

* All SCPH-1000s.
* Very early SCPH-3000s, SCPH-1001s, and SCPH-1002s (the ones susceptible to the [CD Player Swap Trick](#cd-player-swap-trick)).

Consoles with BIOS v2.1-v5.0:

* Late SCPH-3000s, SCPH-1001s, SCPH-1002s, and **all newer models** (including PS2s) need to use the type B exploit for Final Fantasy IX.

* Versions Tested: [Japan](http://redump.org/disc/1968/), [USA](http://redump.org/disc/73/), [Spain](http://redump.org/disc/1113/), [Italy](http://redump.org/disc/2714/), [Germany](http://redump.org/disc/737/), [France](http://redump.org/disc/2455/), [Europe](http://redump.org/disc/2371/).
* Versions With Save Game Exploit Support: Japan, USA. **Spain, Italy, Germany, France, and Europe version are not yet supported**.
* Save Game Exploit RAW file (Type A Exploit for BIOS v1.0, v1.1, and v2.0 PS1 consoles): `entrypoints/FF9-A-JP/BISLPS-0200000000-00` (Japan) or `entrypoints/FF9-A-US/BASLUS-0125100000-00` (USA).
* Save Game Exploit RAW file (Type B Exploit for BIOS v2.1 and above, including all PS2s): `entrypoints/FF9-B-JP/BISLPS-0200000000-00` (Japan)  or `entrypoints/FF9-B-US/BASLUS-0125100000-00` (USA).
* Save Game Exploit MCS file (Type A Exploit for BIOS v1.0, v1.1, and v2.0 PS1 consoles): `entrypoints/FF9-A-JP/ff9-a-jp.mcs` (Japan) or `entrypoints/FF9-A-US/ff9-a-us.mcs` (USA).
* Save Game Exploit MCS file (Type B Exploit for BIOS v2.1 and above, including all PS2s): `entrypoints/FF9-B-JP/ff9-b-jp.mcs` (Japan) or `entrypoints/FF9-A-US/ff9-b-us.mcs` (USA).
* Tonyhax International Loader RAW file: `loader/FF9`.
* Tonyhax International Loader MCS file: `loader/tonyhax-ff9.mcs`.
* Exploit instructions: Select `Continue` at the title screen, and then the memory card with the _Save Game Exploit_ file. **Note: there are no colours displayed when using the Finaly Fantasy IX exploit, the screen will directly boot to the Tonyhax International loader in a few seconds after being triggered in-game.** Make sure you use the correct Type A or Type B exploit, or else the exploit won't trigger!

### Sports Superbike

* Versions Tested: [Europe](http://redump.org/disc/7824/).
* Versions With Save Game Exploit Support: Europe.
* Save Game Exploit RAW file: `entrypoints/BESLES-03057SSBv1` (Europe).
* Save Game Exploit MCS file: `entrypoints/superbike1-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit instructions: Select the English language in the language selection screen. Enter the Memory Card menu. Load game from the Memory Card. Click accept after it's done loading. Back at the main menu, select `Race`, then `Single Race`.

### Sports Superbike 2

* Versions Tested: [USA](http://redump.org/disc/15326/), [Europe](http://redump.org/disc/19224/).
* Versions With Save Game Exploit Support: Europe. **USA version is not yet supported**.
* Save Game Exploit RAW file: `entrypoints/BESLES-03827SSII` (Europe).
* Save Game Exploit MCS file: `entrypoints/superbike2-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit instructions: If you are using the Europe version, select the English language in the language selection screen. On the main menu, choose Options. Select `Load Game` and load the _Save Game Exploit_ file. Back at the main menu, select either the `Single Race` or `Championship` option.       

### Tekken 2

* Versions Tested: [Japan Rev 0](http://redump.org/disc/38475/), [Japan Rev 1](http://redump.org/disc/1155/), [USA Rev 0](http://redump.org/disc/1836/), [USA Rev 1](http://redump.org/disc/14017/), [Germany](http://redump.org/disc/45460/), [France](http://redump.org/disc/47269/).
* Versions With Save Game Exploit Support: Japan Rev 1, USA Rev 1, Germany, France. **Japan Rev 0 and USA Rev 0 are not yet supported**.
* Save Game Exploit RAW file: `entrypoints/BISLPS-00300TEKKEN-2` (Japan Rev 1), `entrypoints/BASLUS-00213TEKKEN-2` (USA Rev 1), `entrypoints/BESCES-00255TEKKEN-2` (France **and** Germany).
* Save Game Exploit MCS file: `entrypoints/tekken2-jp.mcs` (Japan Rev 1), `entrypoints/tekken2-us.mcs` (USA Rev 1), `entrypoints/tekken2-eu.mcs` (France **and** Germany).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: Start a round of `Survival Mode` at the title screen. Die at any point in surivival mode, and the game will go black and trigger the exploit in a few seconds. **Note: there are no colours displayed when using the Tekken exploits, the screen will directly boot to the Tonyhax International loader in a few seconds after being triggered in-game.**

### Tekken 3

* Versions Tested: [Japan Rev 0](http://redump.org/disc/588/), [Japan Rev 1](http://redump.org/disc/30736/), [USA](http://redump.org/disc/1464/), [Europe Rev 0](http://redump.org/disc/483/), [Europe Rev 1](http://redump.org/disc/449/).
* Versions With Save Game Exploit Support: Japan Rev 0, Japan Rev 1, USA, Europe Rev 0, Europe Rev 1.
* Save Game Exploit RAW file: `entrypoints/BISLPS-01300TEKKEN-3` (Japan Rev 0 **and** Japan Rev 1), `entrypoints/BASLUS-00402TEKKEN-3` (USA Rev 0 **and** USA Rev 1), `entrypoints/BESCES-01237TEKKEN-3` (Europe Rev 0 **and** Europe Rev 1).
* Save Game Exploit MCS file: `entrypoints/tekken3-jp.mcs` (Japan Rev 0 **and** Japan Rev 1), `entrypoints/tekken3-us.mcs` (USA Rev 0 **and** USA Rev 1), `entrypoints/tekken3-eu.mcs` (Europe Rev 0 **and** Europe Rev 1).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: Start a round of `Survival Mode` at the title screen. Die at any point in surivival mode, and the game will go black and trigger the exploit in a few seconds. **Note: there are no colours displayed when using the Tekken exploits, the screen will directly boot to the Tonyhax International loader in a few seconds after being triggered in-game.**


### The Legend of Heroes I & II: Eiyuu Densetsu

* Versions Tested: [Japan](http://redump.org/disc/47491/).
* Versions With Save Game Exploit Support: Japan.
* Save Game Exploit RAW file: `entrypoints/BISLPS-01323010001` (Japan).
* Save Game Exploit MCS file: `entrypoints/the-legend-of-heroes-1-and-2-jp.mcs` (Japan).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: At the main menu, **select `The Legend Of Heroes I` (the I button on the left)**, not `The Legend Of Heroes II` (the II button on the right). Once in `The Legend Of Heroes I` game, load the save game exploit file.

### Tony Hawk's Pro Skater 2

* Versions Tested: [Japan](http://redump.org/disc/35439/), [USA](http://redump.org/disc/1319/), [Germany](http://redump.org/disc/5899/), [France](http://redump.org/disc/27627/), [Europe/Australia](http://redump.org/disc/976/).
* Versions With Save Game Exploit Support: Japan, USA, Germany, France, Europe/Australia. **USA Preview, USA Demo, Australia Demo, and Europe Demo are not yet supported**.
* Save Game Exploit RAW file: `entrypoints/BISLPM-86751CEEAG01` (Japan), `entrypoints/BASLUS-01066TNHXG01` (USA), `entrypoints/BESLES-02910TNHXG01` (Germany), `entrypoints/BESLES-02909TNHXG01` (France), `entrypoints/BESLES-02908TNHXG01` (Europe/Australia).
* Save Game Exploit MCS file: `entrypoints/thps2-jp.mcs` (Japan), `entrypoints/thps2-us.mcs` (USA), `entrypoints/thps2-de.mcs` (Germany), `entrypoints/thps2-fr.mcs` (France), `entrypoints/thps2-eu.mcs` (Europe/Australia).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
At the main menu, wait until the save game exploit file is automatically loaded (it should say `Loading TONYHAX JP/US/EU/DE/FR`, depending on the game's region). Next, select `CREATE SKATER` and confirm the selection to start the exploit.

### Tony Hawk's Pro Skater 3

* Versions Tested: [USA](http://redump.org/disc/1320/), [Germany](http://redump.org/disc/3270/), [France](http://redump.org/disc/27628/), [Europe](http://redump.org/disc/1465/).
* Versions With Save Game Exploit Support: USA, Germany, France, Europe.
* Save Game Exploit RAW file: `entrypoints/BASLUS-01419TNHXG01` (USA), `entrypoints/BESLES-03647TNHXG01` (Germany), `entrypoints/BESLES-03646TNHXG01` (France), `entrypoints/BESLES-03645TNHXG01` (Europe).
* Save Game Exploit MCS file: `entrypoints/thps3-us.mcs` (USA), `entrypoints/thps3-de.mcs` (Germany), `entrypoints/thps3-fr.mcs` (France), `entrypoints/thps3-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
At the main menu, wait until the save game exploit file is automatically loaded (it should say `Loading TONYHAX US/EU/DE/FR`, depending on the game's region). Next, select `CREATE SKATER` and confirm the selection to start the exploit.

### Tony Hawk's Pro Skater 4

* Versions Tested: [USA](http://redump.org/disc/1321/), [Germany](http://redump.org/disc/5130/), [France](http://redump.org/disc/27629/), [Europe](http://redump.org/disc/15090/).
* Versions With Save Game Exploit Support: USA, Germany, France, Europe.
* Save Game Exploit RAW file: `entrypoints/BASLUS-01485TNHXG01` (USA), `entrypoints/BESLES-03955TNHXG01` (Germany), `entrypoints/BESLES-03956TNHXG01` (France), `entrypoints/BESLES-03954TNHXG01` (Europe).
* Save Game Exploit MCS file: `entrypoints/thps4-us.mcs` (USA), `entrypoints/thps4-de.mcs` (Germany), `entrypoints/thps4-fr.mcs` (France), `entrypoints/thps4-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit Instructions: At the main menu, wait until the save game exploit file is automatically loaded (it should say `Loading TONYHAX US/EU/DE/FR`, depending on the game's region). Next, select `CREATE SKATER` and confirm the selection to start the exploit.

### XS Moto

* Versions Tested: [USA](http://redump.org/disc/6604/), [Europe](http://redump.org/disc/17764/).
* Versions With Save Game Exploit Support: USA, Europe.
* Save Game Exploit RAW file: `entrypoints/BASLUS-01506XSMOTOv1` (USA), `entrypoints/BESLES-04095XSMOTO` (Europe).
* Save Game Exploit MCS file: `entrypoints/xsmoto-us.mcs` (USA), `entrypoints/xsmoto-eu.mcs` (Europe).
* Tonyhax International Loader RAW file: `loader/HAX`.
* Tonyhax International Loader MCS file: `loader/tonyhax.mcs`.
* Exploit instructions: If you are using the 'Europe' version select the English language in the language selection screen. On the main menu, choose Options. Select `Load Game` and load the _Save Game Exploit_ file. Back at the main menu, select either the `Single Race` or `Championship` option to trigger the exploit.

## CD-R Media For PSX Backups

**Only use high-quality CD-R media for PSX backups.** If you want good results burning backups for your PS1 your CD-R media should contain:

* High quality dye (SuperAZO, AZO, or Phthalocyanine).
* A highly reflective layer system.
* High quality polycarbonate and "sealing" process combining all parts of the CD-R.

_Ideally, you want to use 74 minute discs_. The PSX was never designed for the now more common 80 minute discs, and it is easier for the laser to track 74 minute discs due to their wider data spiral track. As of 2023, 74 minute discs are not really manufactured anymore and new old stock can get pricey, so it really may not be worth it as the PSX can read 80 minute discs fine. It just can read 74 minute discs easier as that is closer to what it was designed for originally (which was 72 minute pressed CD-ROMs).

I have found Verbatim DataLifePlus CD-Rs to be really good with PS1 consoles. Here is the ATIP information displayed by `cdrecord -atip` for a Verbatim DataLifePlus CD-R:

    ATIP info from disk:
      Indicated writing power: 4
    Disk Is not unrestricted
    Disk Is not erasable
      Disk sub type: Medium Type A, high Beta category (A+) (3)
      ATIP start of lead in:  -11077 (97:34/23)
      ATIP start of lead out: 359848 (79:59/73)
    Disk type:    Long strategy type (Cyanine, AZO or similar)
    Manuf. index: 11
    Manufacturer: Mitsubishi Chemical Corporation

Verbatim UltraLife Archival Grade Gold CD-Rs also are really good, although they are more expensive then Verbatim DataLifePlus. I think Verbatim DataLifePlus CD-Rs are slightly better with the PS1 as well, but they are an option. Here is the ATIP information displayed by `cdrecord -atip` for a Verbatim DataLifePlus CD-R:

    ATIP info from disk:
      Indicated writing power: 5
    Disk Is not unrestricted
    Disk Is not erasable
      Disk sub type: Medium Type B, low Beta category (B-) (4)
      ATIP start of lead in:  -12520 (97:15/05)
      ATIP start of lead out: 359849 (79:59/74)
    Disk type:    Short strategy type (Phthalocyanine or similar)
    Manuf. index: 26
    Manufacturer: TDK Corporation

**Do not use cheap/poor quality CD-R media, which is almost always all that is available in retail stores and most likely any CD-R that is not "archival grade"**. Poor quality cheap CD-R media _can_ result in:

*   Slower loading times/in-game lag because of CD drive tracking errors (bad noises from the CD drive).
*   Issues reading data off of the disc possibly resulting in a game to freeze and motor power off in the CD drive.
*   Skipping/silent audio and or music.

Later PS1 consoles (starting at the SCPH-5000 series and newer) and all PS2 consoles have a much greater tolerance to poor quality CD-R media, and _may_ work fine with it however in general it is still best to just always use Verbatim DataLifePlus/UltraLife CD-Rs or something of similar quality. Here is the ATIP information displayed by `cdrecord -atip` for a Maxell Music CD-R (which is a poor quality brand/CD-R media that is **highly not recommended**.

    ATIP info from disk:
      Indicated writing power: 4
    Disk Is unrestricted
    Disk Is not erasable
      Disk sub type: Medium Type A, low Beta category (A-) (2)
      ATIP start of lead in:  -12508 (97:15/17)
      ATIP start of lead out: 359845 (79:59/70)
    Disk type:    Short strategy type (Phthalocyanine or similar)
    Manuf. index: 22
    Manufacturer: Ritek Co.

If you are having issues booting discs in Tonyhax International, consider wiping with a clean microfiber cloth from the inner ring to the outer edge of the disc in all directions and then trying to boot the disc again.

## Burning PSX CD-Rs

Not all CD burning programs can correctly burn _all types_ of PSX discs. Below is a small list comparison of a few burning programs and their abilities. The recommended burning program is [my cdrdao fork](#cdrdao-af) due to it being open source and cross platform.

### [CDRDAO-AF](https://alex-free.github.io/cdrdao)

* Is Open Source?: Yes. Pre-built Linux x86_64 binaries are also [available](https://alex-free.github.io/cdrdao#downloads).
* Burns Standard PSX Backup CD-Rs?: Yes. For .bin/.cue CD images, the `--swap` argument is required.
* Burns PSX Backup CD-Rs With Additional EDC Protection Correctly?: Yes, for .bin/.cue CD images, the `--swap` argument is required. You also must use the `generic-mmc-raw` driver.
* Burns PSX Backup CD-Rs With LibCrypt Protection Correctly?: CDRDAO can rip an authentic PAL PSX game disc containing LibCrypt protection correctly into a .toc/.bin CD image file. This file can be burned back by using the `generic-mmc-raw` driver. The much more common .bin/.cue/.sub CD image LibCrypt rips do not work directly however.

### [CloneCD](https://www.redfox.bz/en/clonecd.html)

* Is Open Source?: No, it is Windows only FreeWare with a free 'demo' version as well as a full paid version. The 'demo' version can be used however for PSX Backup CD-R burning without limitation.
* Burns Standard PSX Backup CD-Rs?: Yes, no special options required.
* Burns PSX Backup CD-Rs With Additional EDC Protection Correctly?: Yes, if you use [RAW](https://hydrogenaud.io/index.php?PHPSESSID=3voij6gqs993vdbd15mlmc2k7h&topic=42415.msg371328#msg371328) mode.
* Burns PSX Backup CD-Rs With LibCrypt Protection Correctly?: [Yes](https://github.com/Kippykip/SBITools), (with the proper BIN/CUE/SUB files).

### [ImgBurn](https://www.imgburn.com/)

* IMGBurn is only available on Windows and is closed source free-ware.

* IMGBurn **can not burn** unmodified copies of game which contain additional [EDC related copy protection](#bypassing-additional-edc-checks-found-in-some-games). As long as the game does not have any EDC related copy protection however, IMGBurn will work for burning PSX CD-Rs.

## Playing Games With Additonal Copy Protection Routines

Starting in late 1998, some PSX games began including additional copy protection code that is designed to prevent playing backup CD-R copies of a game. This additional copy protection originally could only detect the first type of mod-chips (known as 'non-stealth') and would only fail if it detected one. **Tonyhax International does not trigger this type of anti-piracy copy protection on stock consoles and these games don't require any patching by Tonyhax International.**

Starting in mid 1999, the 'standardized' additional copy protection code was updated. This updated copy protection code can detect 'non-stealth' mod-chips, 'traditional' swap tricks (which don't update TOC data), and the authenticity of the disc currently running in the PSX console. This last check causes the anti-piracy copy protection routine to trigger on games booted with Tonyhax International _unless you are using a SCPH-1000 or early SCPH-3000 Japanese PSX console model, which are immune to triggering any addtional anti-piracy copy protection routines of any kind._ 

Tonyhax International is now capable of [game-specific](#list-of-games-with-anti-piracy-bypass-support) on the fly patching to bypass this type of anti-piracy copy protection routine on **all consoles**.

If you find a game which triggers the 'anti-piracy screen of death' that is yet supported please open an [Anti-Piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&template=antipiracy-issue.md&title=) on the [Tonyhax International Github](https://github.com/alex-free/tonyhax). I would eventually like every game that can trigger the anti-piracy copy protection routine when booted via Tonyhax International on a stock console to have a game specific bypass implemented for 100% compatibility.

There is currently a WIP 'todo' list of games that are [known](#known-games-that-need-anti-piracy-bypasses-implemented) to need anti-piracy bypasses, but are not yet supported.

_IMPORTANT NOTE **NUMBER 1**:_ Tonyhax International **does not bypass anti-piracy if your console has an actual non-stealth modchip installed.**

_IMPORTANT NOTE **NUMBER 2**:_ Some PAL games are using a different copy protection scheme known as LibCrypt protection. This protection can be bypassed by burning a backup CD-R in a [very specific way to keep the protection working](https://github.com/Kippykip/SBITools), or just by using an original authentic PAL PSX disc ('imported' for a different region console will work via the Tonyhax International loader).

## List Of Games With Anti-Piracy Bypass Support

### Animetic Story Game 1: Card Captor Sakura

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/12000/), [Disc 2](http://redump.org/disc/11999/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan.

### Alundra 2

- Versions Tested: [Japan](http://redump.org/disc/15641/), [Japan Demo](http://redump.org/disc/6752/), [USA](http://redump.org/disc/2996/), [Europe](http://redump.org/disc/1089/), [German](http://redump.org/disc/11603/), [French](http://redump.org/disc/13396/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When first booting the game during the 'now loading' screen.
- Versions With Anti-Piracy Bypass Support: Japan.

### Arc The Lad III

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/5897/), [Disc 2](http://redump.org/disc/5898/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/34793/), [Disc 2](http://redump.org/disc/34794/)), USA ([Disc 1](http://redump.org/disc/674/), [Disc 2](http://redump.org/disc/675/)).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.

### Beatmania featuring Dreams Come True

- Versions Tested: [Japan](http://redump.org/disc/36188/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Beatmania Best Hits

- Versions Tested: [Japan Rev 0](http://redump.org/disc/36175/), [Japan Rev 1](http://redump.org/disc/44332/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.

### Beat Mania: The Sound of Tokyo

- Versions Tested: [Japan](http://redump.org/disc/36163/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Beat Mania 6thMix + Core Remix

- Versions Tested: [Japan](http://redump.org/disc/16285/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Chase The Express

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/5637/), [Disc 2](http://redump.org/disc/5638/)), [Japan Demo 1](http://redump.org/disc/6551/), [Japan Demo 2](http://redump.org/disc/19589/), Europe ([Disc 1](http://redump.org/disc/27257/), [Disc 2](http://redump.org/disc/27258/)), France ([Disc 1](http://redump.org/disc/28137/), [Disc 2](http://redump.org/disc/28138/)), Germany ([Disc 1](http://redump.org/disc/7507/), [Disc 2](http://redump.org/disc/7508/)), Italy ([Disc 1](http://redump.org/disc/28358/), [Disc 2](http://redump.org/disc/28359/)).
- Versions With Anti-Piracy Screen: Japan, Japan Demo 1, Japan Demo 2.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo 1, Japan Demo 2.

### Crash Bash

- Versions Tested: [Japan](http://redump.org/disc/3819/), [Japan Demo](http://redump.org/disc/53589/), [USA](http://redump.org/disc/512/), [USA Demo](http://redump.org/disc/49446/), [Europe](http://redump.org/disc/5483/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: 'Sony Computer Entertainment Presents' screen.
- Versions With Anti-Piracy Bypass Support: Japan, USA.

### Crash Bandicoot Racing

- Versions Tested: [Japan](http://redump.org/disc/3694/), [Japan Demo](http://redump.org/disc/53590/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When first booting the game when the Naughty Dog box is first visible.
- Versions With Anti-Piracy Bypass Support: Japan.

### Cool Boarders 2001

- Versions Tested: [USA](http://redump.org/disc/513/), [USA Demo](http://redump.org/disc/42467/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: During the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### Dance Dance Revolution: Best Hits

- Versions Tested: [Japan](http://redump.org/disc/30601/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan. **IMPORTANT: There is an [EDC check](#bypassing-additional-edc-checks-found-in-some-games) in addition to the standardized anti-piracy copy protection routine.**

### Dance Dance Revolution: Disney's Rave

- Versions Tested: [Japan](http://redump.org/disc/37012/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution: Extra Mix

- Versions Tested: [Japan](http://redump.org/disc/44438/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution 2nd Remix

- Versions Tested: [Japan](http://redump.org/disc/9477/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan.
- **IMPORTANT: There is an [EDC check](#bypassing-additional-edc-checks-found-in-some-games) in addition to the standardized anti-piracy copy protection routine.**

### Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1

- Versions Tested: [Japan](http://redump.org/disc/23382/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When you use the 'disc change' feature found in Dance Dance Revolution 2nd Remix to boot the disc.
- Versions With Anti-Piracy Bypass Support: Japan. 
**IMPORTANT: There is an [EDC check](#bypassing-additional-edc-checks-found-in-some-games) in addition to the standardized anti-piracy copy protection routine.**
- This game works as intended/completely normal on USA and European consoles. On Japanese PS1 consoles, you must do a **perfect** [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles) in the 'disc change' feature found in Dance Dance Revolution 2nd Remix to get the game to boot AND for it to have working CD audio. You can not play this game currently on a Japanese PS2 due to the lack of a [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles) method for PS2s.

### Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2

- Versions Tested: [Japan](http://redump.org/disc/33339/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When you use the 'disc change' feature found in Dance Dance Revolution 2nd Remix to boot the disc.
- Versions With Anti-Piracy Bypass Support: Japan.
**IMPORTANT: There is an [EDC check](#bypassing-additional-edc-checks-found-in-some-games) in addition to the standardized anti-piracy copy protection routine.**
- This game works as intended/completely normal on USA and European consoles. On Japanese PS1 consoles, you must do a **perfect** [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles) in the 'disc change' feature found in Dance Dance Revolution 2nd Remix to get the game to boot AND for it to have working CD audio. You can not play this game currently on a Japanese PS2 due to the lack of a [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles) method for PS2s.

### Dancing Stage Featuring Dreams Come True

- Versions Tested: [Japan](http://redump.org/disc/17882/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first text screen after boot, until right before the first FMV.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dancing Stage Featuring True Kiss Destination

- Versions Tested: [Japan](http://redump.org/disc/15853/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first text screen after boot, until right before the first FMV.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dino Crisis

- Versions Tested: [Japan](http://redump.org/disc/1598/), [USA Rev 0](http://redump.org/disc/459/), [USA Rev 1](http://redump.org/disc/473/), [USA Demo](http://redump.org/disc/2942/), [Europe](http://redump.org/disc/710/), [Italy](http://redump.org/disc/28171/), [Germany](http://redump.org/disc/7586/), [France](http://redump.org/disc/24278/), [Spain](http://redump.org/disc/27940/).
- Versions With Anti-Piracy Screen: Japan, USA Rev 0, USA Rev 1.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots.
- Versions With Anti-Piracy Bypass Support: Japan, USA Rev 0, USA Rev 1.

### Dino Crisis 2

- Versions Tested: [Japan](http://redump.org/disc/1600/), [Japan Demo](http://redump.org/disc/4407/), [USA](http://redump.org/disc/460/), [USA Demo](http://redump.org/disc/49242/), [Europe](http://redump.org/disc/1071/), [Italy](http://redump.org/disc/45993/), [Germany](http://redump.org/disc/10641/), [France](http://redump.org/disc/29514/), [Spain](http://redump.org/disc/27941/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.

### Disney's The Emperor's New Grove

- Versions With Anti-Piracy Screen: [USA](http://redump.org/disc/14583/), [Europe](http://redump.org/disc/7565/).
- When Is The Anti-Piracy Screen Check: Start a new game, after the first FMV on the first loading screen is when the check completes.
- Versions With Anti-Piracy Bypass Support: USA, Europe.

### Exciting Bass 2

- Versions Tested: [Japan](http://redump.org/disc/63487/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Exciting Bass 3

- Versions Tested: [Japan](http://redump.org/disc/59734/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner

- Versions: [Japan](http://redump.org/disc/20715/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Goo! Goo! Soundry

- Versions Tested: [Japan](http://redump.org/disc/16027/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first 'now loading' screen at boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Grind Session

- Versions Tested: [USA](http://redump.org/disc/854/), [USA Demo](http://redump.org/disc/42794/), [Europe](http://redump.org/disc/3688/), [Scandinavia](http://redump.org/disc/53879/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: After going through the main menu and starting training/single player/a level.
- Versions With Anti-Piracy Bypass Support: USA.

### Guitar Freaks

- Versions Tested: [Japan](http://redump.org/disc/2277/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: At the loading screen with the spinning guitars.
- Versions With Anti-Piracy Bypass Support: Japan.

### Harlem Beat: You're The One

- Versions Tested: [Japan](http://redump.org/disc/36294/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: At the first loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Hyper Value 2800: Mahjong

- Versions Tested: [Japan](http://redump.org/disc/15793/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### i-mode mo Issho: Doko Demo Issho Tsuika Disc

- Versions Tested: [Japan](http://redump.org/disc/15793/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Jikkyou Powerful Pro Yakyuu '99: Ketteiban

- Versions Tested: [Japan](http://redump.org/disc/11091/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Jikkyou Powerful Pro Yakyuu '99: Kaimakuban

- Versions Tested: [Japan](http://redump.org/disc/1686/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### JoJo's Bizarre Adventure

- Versions Tested: [Japan](http://redump.org/disc/2871/), [USA](http://redump.org/disc/386/), [Europe](http://redump.org/disc/9983/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: First loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Koko Hore! Pukka

- Versions Tested: [Japan](http://redump.org/disc/4812/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan.

### Koneko mo Issho

- Versions Tested: [Japan](http://redump.org/disc/6329/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immeditely.
- Versions With Anti-Piracy Bypass Support: Japan.

### Legend Of Dragoon

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/22753/), [Disc 2](http://redump.org/disc/22754/), [Disc 3](http://redump.org/disc/22755/), [Disc 4](http://redump.org/disc/22756/)), USA ([Disc 1](http://redump.org/disc/153/), [Disc 2](http://redump.org/disc/154/), [Disc 3](http://redump.org/disc/155/), [Disc 4](http://redump.org/disc/156/)), Europe ([Disc 1](http://redump.org/disc/2379/), [Disc 2](http://redump.org/disc/2380/), [Disc 3](http://redump.org/disc/2381), [Disc 4](http://redump.org/disc/2382/)), France ([Disc 1](http://redump.org/disc/16750/), [Disc 2](http://redump.org/disc/16751/), [Disc 3](http://redump.org/disc/16752/), [Disc 4](http://redump.org/disc/16753/)), Germany ([Disc 1](http://redump.org/disc/15580/), [Disc 2](http://redump.org/disc/15581/), [Disc 3](http://redump.org/disc/15582/), [Disc 4](http://redump.org/disc/15583/)), Italy ([Disc 1](http://redump.org/disc/30643/), [Disc 2](http://redump.org/disc/30644/), [Disc 3](http://redump.org/disc/30645/), [Disc 4](http://redump.org/disc/30646/)).
- Versions With Anti-Piracy Screen: Japan, USA, Europe, France, Germany, Italy.
- When Is The Anti-Piracy Screen Check: First loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan, USA, Europe, France, Germany, Italy.

### Legend Of Mana

- Versions Tested: [Japan](http://redump.org/disc/1940/), [USA](http://redump.org/disc/96/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA.

### Love Hina: Ai wa Kotoba no Naka ni

- Versions Tested: [Japan](http://redump.org/disc/7369/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Love Hina 2: Kotoba wa Konayuki no You ni

- Versions Tested: [Japan](http://redump.org/disc/7370/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Marvel vs. Capcom: Clash of Super Heroes

- Versions Tested: [Japan](http://redump.org/disc/36384/), [Japan Demo](http://redump.org/disc/60646/), [USA](http://redump.org/disc/1235/), [Europe](http://redump.org/disc/3910/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately on boot.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.

### MediEvil II

- Versions Tested: [USA](http://redump.org/disc/2503/), [Europe Release 1](http://redump.org/disc/593/), [Europe Release 2](http://redump.org/disc/1547/), [Europe Demo](http://redump.org/disc/45822/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the Whitechapel level loading screen (quite far in the game).
- Versions With Anti-Piracy Bypass Support: USA.

### My Garden

- Versions Tested: [Japan](http://redump.org/disc/8300/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Oha-Studio Dance Dance Revolution

- Versions Tested: [Japan](http://redump.org/disc/33938/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Ore no Ryouri

- Versions Tested: [Japan](http://redump.org/disc/39643/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pocket Jiman

- Versions Tested: [Japan](http://redump.org/disc/3189/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### PoPoLoCrois Monogatari II

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/1653/), [Disc 2](http://redump.org/disc/1654/), [Disc 3](http://redump.org/disc/1651/)), [Japan Demo](http://redump.org/disc/57327/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music: Animation Melody

- Versions Tested: [Japan](http://redump.org/disc/33223/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music: Disney Tunes

- Versions Tested: [Japan](http://redump.org/disc/34263/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music 2

- Versions Tested: [Japan](http://redump.org/disc/9774/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music 5

- Versions Tested: [Japan](http://redump.org/disc/9778/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music 6

- Versions Tested: [Japan](http://redump.org/disc/9777/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Resident Evil 3: The Last Escape

- Versions Tested: [Japan Rev 0](http://redump.org/disc/10/), [Japan Rev 1](http://redump.org/disc/8357/), [Japan Demo](http://redump.org/disc/11674/), [USA](http://redump.org/disc/126/), [USA Demo](http://redump.org/disc/7312/),[Europe](http://redump.org/disc/496/), [Europe Demo](http://redump.org/disc/9463/), [France](http://redump.org/disc/9753/), [Germany](http://redump.org/disc/5526/), [Italy](http://redump.org/disc/16397/), [Ireland](http://redump.org/disc/28197/), [Spain](http://redump.org/disc/1387/),
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots, pause there.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1, Japan Demo.

### Resident Evil: Survivor

- Versions Tested: [Japan](http://redump.org/disc/8102/), [USA](http://redump.org/disc/326/), [Europe](http://redump.org/disc/801/), [France](http://redump.org/disc/5826/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA.

### Robbit mon Dieu
- Versions Tested: [Japan](http://redump.org/disc/7227/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman

- Versions Tested: [Japan](http://redump.org/disc/6091/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 2: Dr. Wily no Nazo

- Versions Tested: [Japan](http://redump.org/disc/6092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 3: Dr. Wily no Saigo!?

- Versions Tested: [Japan](http://redump.org/disc/6092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 4: Aratanaru Yabou!!

- Versions Tested: [Japan](http://redump.org/disc/6094/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

## Rockman 5: Blues no Wana!?

- Versions Tested: [Japan](http://redump.org/disc/6095/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman X5

- Versions Tested: [Japan](http://redump.org/disc/4779/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman X6

- Versions Tested: [Japan](http://redump.org/disc/4778/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 6

- Versions Tested: [Japan](http://redump.org/disc/6096/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Street Fighter EX2 Plus

- Versions Tested: [Japan](http://redump.org/disc/12561/), [Japan Demo](http://redump.org/disc/68873/), [USA](http://redump.org/disc/1233/), [Europe](http://redump.org/disc/1006/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo, Europe, USA.

### Strider 2

- Versions Tested: [USA](http://redump.org/disc/1231/), [Europe](http://redump.org/disc/3917/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First now Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### Tomba! 2: The Evil Swine Return

- Versions Tested: [USA](http://redump.org/disc/16475/), [USA Demo](http://redump.org/disc/32246/), [Europe](http://redump.org/disc/31192/), [France](http://redump.org/disc/31192/), [Germany](http://redump.org/disc/31192/), [Italy](http://redump.org/disc/41369/), [Spain](http://redump.org/disc/1582/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: USA.

### Vandal Harts II

- Versions Tested: [Japan](http://redump.org/disc/4854/), [USA](http://redump.org/disc/4854/), [Europe](http://redump.org/disc/4854/), [Italy](http://redump.org/disc/4854/), [Spain](http://redump.org/disc/4854/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan (no patch required), USA.

### Wild Arms II

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/3924/), [Disc 2](http://redump.org/disc/3925/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/1902/), [Disc 2](http://redump.org/disc/1903/)), [Japan Demo](http://redump.org/disc/4799//), USA ([Disc 1](http://redump.org/disc/171/), [Disc 2](http://redump.org/disc/172/)), [USA Demo](http://redump.org/disc/42466/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo, USA, USA Demo.
- When Is The Anti-Piracy Screen Check: Right after the media vision logo screen fades to black.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0 (no patch required), Japan Rev 1 (no patch required), Japan Demo (no patch required), USA, USA Demo.

### World Soccer Jikkyou Winning Eleven 4

- Versions Tested: [Japan Rev 0](http://redump.org/disc/4934/), [Japan Rev 1](http://redump.org/disc/4934/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: As soon as the Japan Olympic Committee screen appears.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.

### XI[SAI] Jumbo

- Versions Tested: [Japan](http://redump.org/disc/8372/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Yu-Gi-Oh! Forbidden Memories

- Versions Tested: [Japan](http://redump.org/disc/4173/), [Japan Genteiban Edition](http://redump.org/disc/51546/), [USA](http://redump.org/disc/820/), [Europe](http://redump.org/disc/1053/), [France](http://redump.org/disc/28263/), [Germany](http://redump.org/disc/1256/), [Spain](http://redump.org/disc/30673/), [Italy](http://redump.org/disc/35297/).
- Versions With Anti-Piracy Screen: Japan, Japan Genteiban Edition, USA, Europe, France, Germany, Spain, Italy.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Genteiban Edition, USA,

## Known Games That Need Anti-Piracy Bypasses Implemented

This is a small 'todo list' of games which need further investigation to defeat the additional anti-piracy routines contained within them. Currently there is no support for playing them in Tonyhax International.

### Glint Glitters

- Versions Tested: [Japan](http://redump.org/disc/15969/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.

### Hyper Value 2800: Hanafuda

- Versions Tested: [Japan](http://redump.org/disc/15791/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.

### Tokimeki Memorial 2

- Versions Tested: Japan Rev 0, Japan Rev 1, Japan Limited Box.
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Limited Box.
- When Is The Anti-Piracy Screen Check: Immediately.

## Bypassing Additional EDC Checks Found In Some Games

Some games may also have a different kind of anti-piracy measure, known as the EDC check. The EDC check can be defeated by **forcing the EDC to not be re-generated when [burning the disc image](#burning-psx-cd-rs)**. Below is a WIP list of games found with this type of protection:

* BeatMania Best Hits Japan ([Rev 0](http://redump.org/disc/36175/), [Rev 1](http://redump.org/disc/44332/)).
* Dance Dance Revolution [Japan](http://redump.org/disc/1562/), [USA](http://redump.org/disc/16075/).
* Dance Dance Revolution: Best Hits [Japan](http://redump.org/disc/30601/).
* Dance Dance Revolution 2nd Remix [Japan](http://redump.org/disc/9477/).
* Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1 [Japan](http://redump.org/disc/23382/).
* Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2 [Japan](http://redump.org/disc/33339/).
* Dance Dance Revolution 3rd Mix [Japan](http://redump.org/disc/9536/)
* Dance Dance Revolution 4th Mix [Japan](http://redump.org/disc/34157/)

## Known Incompatible Games

Here is where a list of games that don't work would be listed. At this time, there are no games which are known to not work for non-anti-piracy reasons. While there are definitely still some games which need an anti-piracy bypass [implemented](#known-games-that-need-anti-piracy-bypasses-implemented) for them to work, that is a seperate compatibility list in itself.

If you find such a game however, please open an issue on the [issue](https://github.com/alex-free/tonyhax/issues/new/choose) on Github.

## Building From Source

Obtain the **complete Tonyhax International current source tree from GitHub using git**, using the command below:

`git clone --recursive https://github.com/alex-free/tonyhax`

Next, install all the required dependencies:

* git 
* autoconf 
* automake
* g++ 
* make 
* libtool 
* texinfo 
* help2man 
* ncurses-devel 
* libtinyxml2-devel 
* cmake 
* cdrdao 
* python 
* pandoc

If you are running _Fedora or Debian_ (Windows Subsystem For Linux can run these operating systems on Windows to provide a sufficient build environment), you can download the build dependencies automatically with the `get-deps.sh` script found in the `scripts` folder of the Tonyhax International [source tree](https//alex-free.github.io/tonyhax). **For any other OS, you'll need to find the above packages and install them manually yourself.**

Next, you need to build the tool-chain. Execute the `build-tool-chain.sh` script, which is found in the `scripts` directory of the source tree. **This will take some time to build, depending on how fast your computer is.**

After that, build mkpsxsiso. Execute the `build-mkpsxiso.sh` script, which is found in the `scripts` directory of the source tree.

With everything installed, you can now build Tonyhax International with the `build.sh` script found in the `scripts` directory of the Tonyhax International source tree. After you build Tonyhax International a release `.zip` file will be generated in the root of the source directory.

## Credits

### MottZilla

*	Guidance on increasing the size of the Tonyhax International loader.

*	Wrote the GameShark Code Engine now used by the anti-piracy bypass features and explained how to use it.

*   The original sole creator of [PS1 DemoSwap Patcher v1.0](https://www.psx-place.com/threads/mctool-tonyhax-freepsxboot-installer.36569). MottZilla re-implemented the TOCPerfect concept into a much superior method, and included his implementation alongside of his DemoSwap idea in PS1 DemoSwap Patcher.
*   Wrote the controller input support for Tonyhax International.

*   Wrote the laser re-calibration function for VC2 and VC3 CDROM controllers.

*   Developed the first Japanese save game exploit for Crash Bandicoot 2.

*   Developed the PS-EXE loader used on GameShark/cheat cartridges to run Tonyhax International.

*   Came up with reset+unlock technique for TOCPerfect booting on USA/PAL consoles.

*   Helped debug the [FreePSXBoot](https://github.com/brad-lin/FreePSXBoot) builder's own patch to disable a FreePSXBoot memory card in slot 2.

*   Originally came up with the idea to involve the SetSession 2 command in a fix for the older CDROM controllers.

*   Explained the save game checksum routines in both Tonyhawk Pro Skater 2 (Japanese version) & Castrol Honda VTR (Japanese version) to help me create SuccessCheckSumUpdater (SuccessCU).

*   Explained to myself how to find/port save game exploits to new games or to different versions of games available in different regions (i.e. Japanese version).

### Patchouli(karehaani)

*   Doki Oki (Japan) save game exploit.

*   Crash Bandicoot 3 (Japan) save game exploit.

*   The Lengend Of Heroes I&II (Japan) save game exploit.

*   Tekken 3 Japan/USA/PAL save game exploits (based off of previous work by [krystalgamer](https://github.com/socram8888/tonyhax/pull/20)).

*   Tekken 2 Japan (rev 1 only)/USA (rev 0 only)/PAL save game exploits (based off of previous work by [krystalgamer](https://github.com/socram8888/tonyhax/pull/20)).

*   Downhill Snow (Japan) save game exploit.

### Misc Acknowledgements

*   [Berion](https://www.psx-place.com/members/berion.1431/) of [PSX-Place](https://psx-place.com) compressed the images of this document properly (this is the first time I've edited photos).
*   Martin Korth for confirming the SetSession bug found in VC0A, VC0B, and VC1A CDROM controller BIOS versions, and for the priceless [PSX-SPX](http://problemkaputt.de/psx-spx.htm) document.

*   [Peppe90](https://www.psx-place.com/members/peppe90.42412/) of [PSX-Place](https://psx-place.com) for testing NTSC gamems on a PAL PS2. His results have confirmed that the video mode can not be changed from PS1 software in PS1 mode on a PS1. It must be changed in PS1DRV from the PS2, as PS1 mode is set to always display the same video mode that the console shipped with (for the early PS2s that Tonyhax International supports). He mentioned that PS1VModeNeg v1.0.1 can be used to overcome this. The original Tonyhax [issue](https://github.com/socram8888/tonyhax/issues/25) explaining this also was helpful in figuring out how to bypass this PS2 level limitation.

### O.G. Tonyhax Acknowledgements

[Socram8888](https://github.com/socram8888) is the original developer of the Tonyhax loader. The original Tonyhax loader credits are below, in alphabetical order:

*   Alex Free for adding the boot CD image.
*   ChampionLeake for documenting the Brunswick exploits at PlayStation dev wiki.
*   Gerardo Rodriguez for suggesting Cool Boarders 4 on a YouTube comment.
*   @FMecha for suggesting Castrol Honda VTR on Twitter.
*   John Wilbert Villamor (aka Lameguy64) for creating mkpsxiso.
*   Jose Silva for adding support for Sports Superbike II and XS Moto.
*   Martin Korth for his super awesome technical documentation page that was vital for the development of this project, as well as for developing the no$psx emulator that was also essential for debugging.
*   Patrick Vogt for testing on multiple development PS1 consoles.
*   Everyone that's reported the issues on GitHub and helped Socram8888 make it better.