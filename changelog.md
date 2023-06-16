# Changelog

## Version 1.3.4 (6/14/2023)

*   [tonyhax-international-v1.3.4](https://github.com/alex-free/tonyhax/releases/download/v1.3.4i/tonyhax-international-v1.3.4.zip)

Changes:

* Added a special [xStation ROM version](xstation.md) due to request by 
[L10N37](https://github.com/L10N37). This is actually super cool.

* Added more in-depth info to the [CD-R Media For PSX Backups](#cd-r-media-for-psx-backups) section thanks to [XxTriviumxX](https://github.com/XxTriviumxX).

* Added even more real hardware screen captures to the docs and improved documentation itself immensely with more in-depth steps (specifically related to the [FreePSXBoot exploit](freepsxboot-exploit.md) but also touched a few other pages).

* Updated [MKPSXISO](https://github.com/Lameguy64/mkpsxiso) to the latest version.

* Build system/source cleanup/comment improvements.

## Version 1.3.3 (6/5/2023)

*   [tonyhax-international-v1.3.3](https://github.com/alex-free/tonyhax/releases/download/v1.3.3i/tonyhax-international-v1.3.3.zip)

Changes:

* Added a [APv2 bypass](anti-piracy-bypass.md) for Boku no Natsuyasumi: Summer Holiday 20th Century Japan to close this [issue](https://github.com/alex-free/tonyhax/issues/28). Enjoy, [Bloom-Haven](https://github.com/Bloom-Haven)!!!

* Added a ton of real hardware screen captures to the docs and improved documentation itself immensely with more in-depth steps.

## Version 1.3.2 (6/3/2023)

*   [tonyhax-international-v1.3.2](https://github.com/alex-free/tonyhax/releases/download/v1.3.2i/tonyhax-international-v1.3.2.zip)

Added APv2 bypasses for Breath of Fire IV Japan, Breath of Fire IV E3 2000/USA Beta, Capcom vs. SNK: Millennium Fight 2000 Pro Japan, Glint Glitters, Hyper Value 2800: Hanafuda, Tokimeki Memorial 2 Emotional Voice System Append Discs 1-3, Tokimeki Memorial 2 rev 0, Tokimeki Memorial 2 rev 1, and Tokimeki Memorial 2 limited edition box version.

## Version 1.3.1 (5/28/2023)

*   [tonyhax-international-v1.3.1](https://github.com/alex-free/tonyhax/releases/download/v1.3.1i/tonyhax-international-v1.3.1.zip)

Changes:

* Fixed an issue caused by FreePSXBoot's builder program's `-fastload` option that resulted in failure to read GameShark codes from the memory card on BIOS v4.4-v4.5. This issue has now been resolved by removing that argument and having the same generate command as the original Tonyhax did.

* Fixed regressions in GameShark cheat engine due to some previous overly-aggressive optimizations.

## Version 1.3.0 (5/27/2023)

*   [tonyhax-international-v1.3.0](https://github.com/alex-free/tonyhax/releases/download/v1.3.0i/tonyhax-international-v1.3.0.zip)

Changes:

* Added [APv2 bypasses](anti-piracy-bypass.md) for Spyro: Year Of The Dragon USA Rev 0 and USA Rev 1!

* Updated the loader ram layout from last usable 24k to last usable 32k to allow for larger executable size. Tonyhax International `HAX` and `FF9` save files now take up 4 slots instead of 3 on a PSX memory card. **PLEASE** make sure to update your save game exploit files and or gshax codes/files.

## Version 1.2.9 (5/24/2023)

*   [tonyhax-international-v1.2.9](https://github.com/alex-free/tonyhax/releases/download/v1.2.9i/tonyhax-international-v1.2.9.zip)

Changes:

* Added [APv2 bypasses](anti-piracy-bypass.md) for Tron ni Kobun, NFL GameDay 2001, NFL GameDay 2001 Demo, NFL GameDay 2002, NFL GameDay 2003, NFL GameDay 2004, NFL GameDay 2005, NHL FaceOff 2001 Demo, NHL FaceOff 2001, NCAA Final Four 2001, NCAA Game Breaker 2001, NCAA Game Breaker 2001 Demo, NBA Shootout 2001, NBA Shootout 2001 Demo, NBA Shootout 2002, NBA Shootout 2002 demo, NBA Shootout 2003, NBA Shootout 2004, MLB 2002, MLB 2002 Demo, MLB 2003, MLB 2003 Demo, and MLB 2004.

## Version 1.2.8 (5/19/2023)

*   [tonyhax-international-v1.2.8](https://github.com/alex-free/tonyhax/releases/download/v1.2.8i/tonyhax-international-v1.2.8.zip)

Changes:

* Added support for GameShark code types `E1` and `D1`. Tonyhax International now [supports applying the following GameShark code types](gameshark-code-support.md): `50, 80, 30, D0, E0` `D1` `E1`.

* Significantly optimized the GameShark cheat engine (now at v1.0.2) with the help of MottZilla.

## Version 1.2.7 (5/17/2023)

*   [tonyhax-international-v1.2.7](https://github.com/alex-free/tonyhax/releases/download/v1.2.7i/tonyhax-international-v1.2.7.zip)

Changes:

* **REWROTE** the [GameShark functionality](gameshark-code-support.md) to support **ALL of the following GameShark code types: `50, 80, 30, D0, E0`**. This rewrite includes things like a `TONYHAXINTGS` save file checksum system, a new and improved GameShark cheat code engine, and optimizations to THIGSGEN, now at v2.0.

* Fixed an issue with the `-rom` version that would cause it to display the `Press X to boot Sony BIOS` text twice.

* Added back the PAL/European [Boot CD](boot-cd.md) image to releases since it is now useful for GameShark code support.

* Added some YouTube video tutorial links (by [Jay Time](https://www.youtube.com/@JLMtime)) to the [ROM](flashed-cheat-cart.md) and [GameShark Support](gameshark-code-support.md) pages.

## Version 1.2.6 (5/7/2023)

*   [tonyhax-1.2.6-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.6i/tonyhax-v1.2.6-international.zip)

Changes:

* Fixed the ability to apply your own [GameShark Codes](gameshark-code-support.md) to any game you want to boot for consoles that did not have BIOS v3.0. Only consoles with BIOS v3.0 were previously working, this has now been fixed and all PSX/PS2 consoles are now confirmed working correctly.

* Expanded the amount of codes able to be applied by the anti-piracy bypass system for future-proofing.

* The Tonyhax International loader ROM version now only displays the `Press X to access the Memory Card Manager/CD Player` text when the CD drive is open when the ROM version of the loader starts for Japanese consoles as well, to match the behavior of the other USA/PAL consoles for consistency.

* Updated [PSEXE2ROM](https://alex-free.github.io/psexe2rom) and [MKPSXISO](https://github.com/lameguy64/mkpsxiso) to the latest versions.

* Updated the Tonyhax International GameShark Generator program to v1.0.2. Now you can simply drag and drop the txt file of GameShark codes directly onto the `thigsgen.exe` or `thigsgen` executable file to generate the raw save file named `TONYHAXINTGS` which contains the GameShark codes you want to load with Tonyhax International.

* Added info about how the Final Fantasy IX save exploit file being present when using the SCPH-1000 memory card manager will lock up the console (so don't use it like that :)).

## Version 1.2.5 (5/4/2023)

*   [tonyhax-1.2.5-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.5i/tonyhax-v1.2.5-international.zip)

Changes:

* Added the ability to apply your own [GameShark Codes](gameshark-code-support.md) to any game you want to boot! Huge thanks to MottZilla's guidance on controller support as well as the original cheat engine used to power all of this.

* The Tonyhax International loader ROM version now only displays the `Press X to access the Memory Card Manager/CD Player` text when the CD drive is open when the ROM version of the loader starts, for a more clean interactive look.

## Version 1.2.4 (4/30/2023)

*   [tonyhax-1.2.4-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.4i/tonyhax-v1.2.4-international.zip)

Changes:

* Added the ability to boot into the stock Sony BIOS from the Tonyhax International ROM version. This allows you to access the Memory Card Manager/CD Player functionallity of the stock Sony BIOS without removing the Tonyhax International flashed cheat cart from the back of your console. To use this new feature, simply start your console with the CD drive open, and with the Tonyhax International flash cart in the back of your console. Once Tonyhax International starts, press `X` on a controller when you get to the text stating to insert a disc into the console to continue.

* Added info about how the `HAX` and `FF9` save files of the Tonyhax International loader for the [GameSharkHAX](gameshark-code.md) and [Save game exploit](save-game-exploit.md) can screw up filenames in the stock Sony BIOS memory card manager (a non-fatal, just annoying issue).

## Version 1.2.3 (4/28/2023)

*   [tonyhax-1.2.3-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.3i/tonyhax-v1.2.3-international.zip)

Changes:

* Optimized out many unnecessary functions, improving load speed of games slightly.

* (Really) fixed an issue with the `build.sh` script due to missing template folders in the `gshax` directory since the last update. Git is dumb about not being able to include empty folders so the `build.sh` script just creates them if they don't exit now.

* Added info related to a bug in the GameShark Lite itself.

[About previous versions](changelog.md).

## Version 1.2.2 (4/26/2023)

*   [tonyhax-1.2.2-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.2i/tonyhax-v1.2.2-international.zip)

Changes:

* The Tonyhax International loader now does `SetMemSize(8)`, `SysInitMemory (0xA000E000, 0x2000)`, and `InitDefInt(3)`. This makes it much more similar to how the real PSX BIOS boots games, and it fixes all known issues with booting games via the [GameShark Code](gameshark-code.md) method. 

* Fixed a race condition that rarely effected booting games via the [flashed cheat cart](flashed-cheat-cart.md) and [GameShark Code](gameshark-code.md). The issue was that sometimes the console BIOS would execute CD commmands before starting the ROM too closely to when Tonyhax International would call the first CD INIT on startup. This issue also could happen in GSHAX, when a game was sending CD commands right before the GSHAX exploit would trigger and then starting the Tonyhax International loader. The issue previously manifested as being stuck on the first `Initializing CD` text forever.

* Updated [GSHAX Tool](https://alex-free.github.io/gshax-tool) to v2.0.1, which auto-calculates the MIPS assembly binary offset during code generation in the build step.

* Fixed an issue with the `build.sh` script due to missing template folders in the `gshax` directory since the last update.

* Improved documentation.


## Version 1.2.1 (3/28/2023)

*   [tonyhax-1.2.1-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.1i/tonyhax-v1.2.1-international.zip)

Changes:

* Updated [GSHAX Tool](https://alex-free.github.io/gshax-tool) to v2.0. All [GameSharkHAX](gameshark-code.md) codes have been updated to improved versions. Usage has changed for the WipEout and Parasite Eve codes!

* Thanks to the new GSHAX Tool v2.0 update, a [GameSharkHAX](gameshark-code.md) code for Ridge Racer is now available.

* The first stage loaders: `entry.bin` and `entry-bb.bin` are now included in each release to aid in the development of [GameSharkHAX](gameshark-code.md) and [save game exploits](save-game-exploit.md).

* Added the missing source code to the GameShark cheat engine that MottZilla wrote to the source tree, as well as instructions on assembling it (available at `docs/mottzilla-gameshark-engine.txt`). It is not however 'dynamically generated' by the build system, yet... The compiled version is still hardcoded as an unsigned char array.

[About previous versions](changelog.md).

## Version 1.2.0 (3/17/2023)

*   [tonyhax-v1.2.0-international](https://github.com/alex-free/tonyhax/releases/download/v1.2.0i/tonyhax-v1.2.0-international.zip)

Changes:

* Fixes lockup/freezing that only occurred in specific games (i.e. Tekken 3) when using the FreePSXBoot exploit boot method. Now however, **Before starting any backup or import disc in the loader YOU MUST REMOVE THE FREEPSXBOOT MEMORY CARD to ensure successful booting of your backup or import disc. THIS APPLIES TO BOTH SLOT 1 AND SLOT 2 FREEPSXBOOT CARDS.** This enables more games to work through this boot method and simplifies the loader. The loader will tell you to remove the FreePSXBoot memory card as well now.

## Version 1.1.9 (3/9/2023)

*   [tonyhax-v1.1.9-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.9i/tonyhax-v1.1.9-international.zip)

Changes:

* Fixes potential lockups/freezing right before booting.

* Fixed the Cool Boarders 4 save game exploit not working correctly (thank you [AngelDavil88](https://gbatemp.net/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles-gameshark-cheat-cart-flasher.615892/post-10067707) for pointing this out)!

* The save game file template 'hack' I was using has been replaced with a proper equivalent for the 24KB `tonyhax.exe` maximum file size RAM setup currently in use (thanks [Shendo](http://www.psxdev.net/forum/viewtopic.php?f=66&t=3967&p=22130#p22130))!

* A new [GameSharkHAX](gameshark-code.md) code for Parasite Eve USA is now [available](gameshark-code.md#parasite-eve-usa).

* [GameSharkHAX](gameshark-code.md) codes are all now **auto-generated** in the build step thanks to my new program [GSHAX Tool](https://alex-free.github.io/gshax-tool).
 
* Added more info on the [GameSharkHAX](gameshark-code.md) code method, specifically on which exact GameShark model versions are useful with this boot method (even though all GameShark model versions work regardless of their usefulness).

* The documentation is now only in markdown format (the website is only using auto-generated HTML from said markdown via GitHub pages now). The pandoc requirement hence has been removed from the build step.

* The `build-tool-chain.sh` script now automatically compiles MKPSXISO at the end of building the MIPS toolchain for the PSX.

* Updated [MKPSXISO](https://github.com/lameguy64/mkpsxiso) to the latest commit as of 3/6/2023.

* Added info to the [Boot CD](boot-cd.md) documentation that explains how to use specific GameShark cartridge or GameShark CD versions to start the Tonyhax International Boot CD.

## Version 1.1.8 (1/11/2023)

*   [tonyhax-v1.1.8-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.8i/tonyhax-v1.1.8-international.zip)

Changes:

* A new and exciting boot method known as [GameSharkHAX](gameshark-code.md) has been added to Tonyhax International. This is a brand new 'way in' to the Tonyhax International loader for all PS1 and PS2 consoles that are supported by Tonyhax International (SCPH-1000-SCPH-39004). It uses GameShark codes to boot the Tonyhax International loader off a memory card file **mid-game.**
 
* Condensed the [Boot CD](boot-cd.md) back to just one BIN+CUE file set. It is not actually necessary to have 2 different versions of the Boot CD, the single BIN+CUE file set in all Tonyhax International releases from here on out will work in every supported use case.

* The documentation has been split into multiple markdown and html files. This makes it much more easy to maintain for me, and easier for you to comprehend, read, and share. The 'all in one html file' style before became unmanageable due to the sheer amount of info that has been added since the initial release.

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
