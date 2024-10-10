# Tonyhax International: The Ultimate Backup CD-R/Import Disc Loader Soft-Mod Solution For The Original PlayStation & Early Models Of PlayStation 2

_Brought to you by [Alex Free](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6018), [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867), [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714), and [SylverReZ (M4x1mumReZ)](https://gbatemp.net/members/sylverrez.610331/). Built on the work of many [others](credits.md)._

Tonyhax International is a fork of the [Tonyhax](https://orca.pet/tonyhax/) "Software backup loader exploit thing for the Sony PlayStation 1" originally created by [Socram8888](https://github.com/socram8888).  Developed by Alex Free and MottZilla with many new features and upgrades compared to the original Tonyhax.

## Additional Features

* Supports all PS1 console models (SCPH-1000 to SCPH-103). Supports early PS2 console models (SCPH-10000 to SCPH-39004). All console regions (including Japan) are supported.

* [GameID support](gameid.md). In addition, Tonyhax International is the first to provide GameID support for early Japanese games (PSX.EXE bootfile).

* Ensures 80 Minute CD-Rs on early PS2 models are booted correctly with a first of it's kind [software fix](ps2-80-minute-cd-rs.md).

* Supports more [games](additional-game-support.md). Bleeding edge of Tonyhax upstream.

* Automatic console detection and loader configuration.

* Additional [save game exploits](save-game-exploit.md) available as entry points.

* [Patch](https://alex-free.github.io/tocperfect) a Backup CD-R of a game to be started with the loader.

* Use [GameShark codes](gameshark-code.md) and a cheat CD or cartridge to start the loader. 

* Supports more games via the [FreePSXBoot](freepsxboot-exploit.md) exploit entry point then any other backup loader.

* [Flash](flashed-cheat-cart.md) a cheat cartridge to start the loader. Access the original Sony BIOS without removing the cheat cartridge.

* Format memory cards directly in the loader, including any with the [FreePSXBoot](freepsxboot-exploit.md) exploit.

* The most extensive [anti-piracy bypass system](anti-piracy-bypass.md) of any PS1 soft-mod seamlessly patches protected games on the fly. Non-stealth mod-chips and unmodified consoles essentially become stealth-modchipped consoles with software!

* Apply your own [GameShark codes](gameshark-code-support.md) loaded via memory card save files (up to 15 different save files per memory card, meaning you can have up to 30 different sets of GameShark codes available for selection!). Create the memory card save files on your PC, no need to type in super long codes on the console itself with a controller.

* Small loader size thanks to ps1-packer compression/decompression and space-conscious optimizations.

* Speed up your xStation's boot time with a [specialized xStation Tonyhax International ROM](xstation.md).

* Portable, new [build system](build.md) using bare-bones `mipsel-none-elf` toolchain and no SDK.

| [Homepage](https://alex-free.github.io/tonyhax-international) | [GitHub](https://github.com/alex-free/tonyhax) | [PSX-Place Thread](https://www.psx-place.com/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles.37925/) | [PSX-Place Resource](https://www.psx-place.com/resources/tonyhax-international.1281/) | [PSXDEV Thread](http://www.psxdev.net/forum/viewtopic.php?f=66&t=3967) | [GBATemp Thread](https://gbatemp.net/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles-gameshark-cheat-cart-flasher.615892/##post-9922514) |

## Table Of Contents

* [Downloads](#downloads)
* [Usage](#usage)
* [Frequently Asked Questions](#faq)
* [Relevant Software](#relevant-software)
* [Building From Source](build.md)
* [Credits](credits.md)

## Downloads

### Version 1.5.8 (10/10/2024)

* [tonyhax-international-v1.5.8](https://github.com/alex-free/tonyhax/releases/download/v1.5.8i/tonyhax-international-v1.5.8.zip)

----------------------------------

Changes:

* The loader now resets memory card/controller polling to a clean state during initial start up. This fixes a bug that caused the [ROM entrypoint](flashed-cheat-cart.md) to not detect GameID devices, since the BIOS is initializing the memory cards and controllers so close to the loader taking over execution from the BIOS. Thank you [@kimbapslice](https://github.com/kimbapslice) for bringing this [bug](https://github.com/alex-free/tonyhax/issues/69) to my attention and testing the fixes.

----------------------------------

[Previous versions](changelog.md).

## How To

* [Flash](flashed-cheat-cart.md) a cheat cartridge (GameShark/Action Replay, etc.).

* Use the [FreePSXBoot](freepsxboot-exploit.md)) Memory card exploit.

* Use Special game disc specific [GameShark Codes](gameshark-code.md) with a PSX cheat CD or cartridge (GameShark, Action Replay, etc.).

* Use Game disc specific [save game exploits](save-game-exploit.md).

* Use the [Boot CD](boot-cd.md) burned to a CD-R.

* Patch a game with [(TOCPerfect)](https://alex-free.github.io/tocperfect).

## Usage

* [Japanese PS1 Console Loader Instructions (SCPH-1000-SCPH-100)](japanese-ps1-instructions.md)
* [Japanese PS2 Console Loader Instructions (SCPH-10000-SCPH-39000)](japanese-ps2-instructions.md)
* [American/European PS1/PS2 Console Loader Instructions (SCPH-1001-SCPH-39004)](american-european-console-instructions.md)

## F.A.Q.

1) [Why is my game not booting/loading extremely slowly/crashing when loading/music is skipping/music stops playing/FMV is skipping/FMV stops playing?](#q-why-is-my-game-not-bootingloading-extremely-slowlycrashing-when-loadingmusic-is-skippingmusic-stops-playingfmv-is-skippingfmv-stops-playing)

2) [Why is removing the FreePSXBoot memory card before booting a game required?](#q-why-is-removing-the-freepsxboot-memory-card-before-booting-a-game-required)

3) [Can I use International to play protected games?](#q-can-i-use-international-to-play-protected-games)

4) [Can I play games that span multiple discs (i.e. Fear Effect) / have disc change features?](#q-can-i-play-games-that-span-multiple-discs-ie-fear-effect--have-disc-change-features)

5) [Why not combine Tonyhax and Tonyhax International into one project?](#q-why-not-combine-tonyhax-and-tonyhax-international-into-one-project)

6) [Why Can't Tonyhax/Tonyhax International Change The Video Mode From PAL to NTSC or vice versa on PS2s?](#q-why-cant-tonyhaxtonyhax-international-change-the-video-mode-from-pal-to-ntsc-or-vice-versa-on-ps2s)

7) [Why Are PAL Games Displaying a Black Screen On My Japanese or USA PSOne Slim with Tonyhax/Tonyhax International?](#q-why-are-pal-games-displaying-a-black-screen-on-my-japanese-or-usa-psone-slim)

8) [Why Are Newer PS2s Not Supported?](#q-why-are-newer-ps2s-not-supported)

9) [Why does the DuckStation emulator say backdoor failed?](#q-why-does-the-duckstation-emulator-say-backdoor-failed)

10) [How Can I Help?](#q-how-can-i-help)

### Q: Why is my game not booting/loading extremely slowly/crashing when loading/music is skipping/music stops playing/FMV is skipping/FMV stops playing? 

**A**: If this is an original official PlayStation CD-ROM in good known-working condition, your console's optical drive may need a refurbishment. See my [Unofficial PSX CD-ROM Drive Service Manual](https://alex-free.github.io/unofficial-ps1-cd-drive-service-manual/) for PS1 consoles. I don't have one for PS2 yet. 

If this is a CD-R and you've already refurbished the optical drive, your probably using a bad quality CD-R, a bad quality CD-R burner, and or a suboptimal burn speed. To learn more about high quality CD-Rs, high quality burners, and optimal burn speed please read [The Ultimate Guide To PSX CD-Rs](https://alex-free.github.io/psx-cdr). It is very important to know how to burn good PSX CD-Rs as the PSX is extremely sensitive to bad CD-R media.

If you have good CD-Rs, a good burner, optimal burn speed, and a working refurbished optical drive in your console you won't have disc read issues. If a game is still being problematic, please open a [generic issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=bug&projects=&template=generic-issue.md&title=) as this may be a Tonyhax International incompatibility with your game.

### Q: Why is removing the FreePSXBoot memory card before booting a game required?

**A**: The original Tonyhax and UniROM use 2 different methods to patch reading of a slot 2 FreePSXBoot memory card after starting the game. This is designed to avoid crashing/freezing issues in-game when the FreePSXBoot memory card is attempted to be parsed by game code. Unfortunatly these patches implemented by UniROM and the original Tonyhax are not 100% compatibile with all games. When enabled they cause some games to not boot up or crash. In the interest of maximum compatibility with all games, I use no patches in Tonyhax International (and simply tell users to remove the FreePSXBoot memory card). Not having these patches is why Tonyhax International can boot more games then any other loader using FreePSXBoot currently.

### Q: Can I use International to play protected games?

**A**: Yes, International automatically detects protected games and applies a bypass to enable play. Each game is supported on a game by game basis, and there is a [list](anti-piracy-bypass.md#protected-games-support). If you know of a protected game that isn't on the list, or isn't working in some situation, please open an [anti-piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&projects=&template=antipiracy-issue.md&title=) and tell me all about it.

### Q: Can I play games that span multiple discs (i.e. Fear Effect) / have disc change features?

**A**: If you have any USA or PAL console, yes. If you have a Japanese console without a mod-chip, it gets more complicated. Please see the [japanese ps1 instructions (playing multiple discs)](japanese-ps1-instructions.md) and [japanese ps2 instructions (playing multiple discs)](japanese-ps2-instructions.md#playing-games-with-multiple-discs) sections for full info.

### Q: Why not combine Tonyhax and Tonyhax International into one project?

**A**: Socram8888 does not own a Japanese console, nor is he interested in getting one. While Socram8888 and I do work together to fix issues that effect both the original Tonyhax and Tonyhax International, we have different goals in regards to what the project should support.

### Q: Why Can't Tonyhax/Tonyhax International Change The Video Mode From PAL to NTSC or vice versa on PS2s?

**A**: The early PS2 models that Tonyhax International supports do not have the ability to change the video mode from within PS1 mode from what we understand. 

You can change the video mode first while in PS2 mode however. For now you can resort to the **PS2 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/)**, this software allows you to explicitly change the video mode. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects (which is problematic when using the save game exploit since that disc must match your console's region). Here are the steps below to accomplish this:

* Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.

* Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.

* Using wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).

* Put in the real PSX game disc that you are using with a [save game exploit](save-game-exploit.md) when in PS1VModeNeg. The video mode will be forced to the inverse of the native one your console runs in.

* Playing through your real PSX game disc may look or act weird in the changed video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in the import disc or backup CD-R and the PS1 game will boot at last.

### Q: Why Are PAL Games Displaying a Black Screen On My Japanese or USA PSOne Slim with Tonyhax/Tonyhax International?

**A**: I have verified my SCPH-101 displays a black screen when switching to PAL vidoe mode (no matter if that is switched via Tonyhax original, Tonyhax International, or by the game code itself).

This is a strange oddity, considering the following effects (unmodified hardware):

* SCPH-1000-SCPH-9XXX will output PAL, but it will be in black and white if using composite AV.

* SCPH-101 (confirmed by myself) and SCPH-100 (unconfirmed) will display a black screen the entire time PAL video mode is active if using composite AV.

* SCPH-10000-SCPH-39004 stay in their native video mode always and ignore any request to change the video resolution (from within PS1 mode), using any output cables. There is a PS1VModeNeg workaround though, see the above question.

### Q: Why Are Newer PS2s Not Supported?

**A**: SCPH-50XXX - SCPH-90XXX PS2s are not supported because both `SetSession()` and the unlock commands do not function on these models. The laser re-calibration also seems to be ignored resulting in sub-optimal disc reading performance on the newer models. Technically it can still boot games but with no CD audio support and poor disc reading performance so it is not officially supported whatsoever.

### Q. Why does the DuckStation emulator say backdoor failed?

**A**: This is some incompatibility bug in all recent DuckStation versions that happens when the unlock drive function is used in the original Tonyhax and Tonyhax International loader. A sufficiently old enough DuckStation ([v0.1-6292](https://github.com/stenzek/duckstation/releases/tag/v0.1-6292)) works fine (as do all versions of no $ psx emu). Alternatively you can set your cdrom bios version to a japanese one in the advanced settings of DuckStation, and the most recent DuckStation will also work fine (as long as auto-detect region for the emulated console is selected like it is by default, or it is specified as japanese explicitly). This is because the unlock function is not used for japanese consoles.

### Q. How Can I Help?

**A**: There are many ways!

1) If you know C/MIPS assembly and can improve any of the code in International, open a [pull request](https://github.com/alex-free/tonyhax/pulls) with your changes. 

2) If you don't have programming experience something else that you could help out with is bring to my attention any protected games that are not yet supported in an [anti-piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&projects=&template=antipiracy-issue.md&title=).

3) If you can improve the documentation, open a [pull request](https://github.com/alex-free/tonyhax/pulls) with your changes. 

4) If you can help fund development, [donate!](https://github.com/sponsors/alex-free).

## Relevant Software

*   [PlayStation Disc Burner](https://github.com/alex-free/playstation-disc-burner) - recommended burning software for Linux.

*   [PSX80MP](https://github.com/alex-free/) - Patch PS1 and PS2 CD games to work on early PS2 models when burned to 80 minute/700MB CD-Rs. 

*   [TOCPerfect Patcher](https://alex-free.github.io/tocperfect) - patch the Tonyhax International loader into a disc image directly to expand the capabilities of the CD Player Swap Trick.

*   [EDCRE](https://alex-free.github.io/edcre) - EDC/EEC regenerator to allow patched EDC protected PSX games to be burned by CDRDAO-PLED's generic-mmc-raw driver correctly.

*   [APrip Homepage](https://alex-free.github.io/aprip) - created as a development aid for the [anti-piracy bypass system](anti-piracy-bypass.md).

*   [PS1 DemoSwap Patcher Homepage](https://alex-free.github.io/ps1demoswap) - a similar project that uses the Tonyhax International loader.

*   [PSEXE2ROM Homepage](https://alex-free.github.io/psexe2rom) - what generates the Tonyhax International ROM file.

*   [NXFLASH](https://github.com/danhans42/nxflash) - the software which flashes cheat carts with the Tonyhax International ROM.

*   [FreePSXBoot](https://github.com/brad-lin/FreePSXBoot) - an exploit used in a Tonyhax International boot method.

*   [Tonyhax (the original) Github](https://github.com/socram8888/tonyhax) - what Tonyhax International is based on (_International is not an official version and at this point deviates quite greatly_).

*   [Tonyhax (the original) Homepage](https://orca.pet/tonyhax)
