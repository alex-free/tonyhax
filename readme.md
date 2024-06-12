# Tonyhax International: The Ultimate Backup CD-R/Import Disc Loader Soft-Mod Solution For The Original PlayStation & Early Models Of PlayStation 2

_Brought to you by [Alex Free](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6018), [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867), [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714), and [SylverReZ (M4x1mumReZ)](https://gbatemp.net/members/sylverrez.610331/). Built on the work of many [others](credits.md)._

Tonyhax International is a fork of the [Tonyhax](https://orca.pet/tonyhax/) "Software backup loader exploit thing for the Sony PlayStation 1" originally created by [Socram8888](https://github.com/socram8888).  Developed by Alex Free and MottZilla with many new features and upgrades compared to the original Tonyhax.

## Compatibility

Compatible with all PS1 consoles (SCPH-1000 - SCPH-103) **and** Early PS2 Consoles (SCPH-10000 - SCPH-39004). All regions are supported (including japan). Newer PS2s _probably already work_, but this is not documented or tested for _yet_. If you got a newer 'unofficially supported' PS2 model (SCPH-50000 - SCPH-90XXX) and want to test some stuff out, let me know how it goes in a [Github issue](https://github.com/alex-free/tonyhax/issues).

## Loader Entry Points (Ways To Start The Tonyhax International Loader)

* [Flash](flashed-cheat-cart.md) a cheat cartridge (GameShark/Action Replay, etc.) with the loader.

* [Memory card exploit](freepsxboot-exploit.md).

* Special game disc specific [GameShark Codes](gameshark-code.md) with a PSX cheat CD or cartridge such as GameShark or Action Replay.

* Gane disc specific [save game exploits](save-game-exploit.md) (many more then the [original Tonyhax](https://github.com/socram8888/tonyhax) are available).

* [Boot CD](boot-cd.md).

* [Patch a Backup CD-R directly](https://alex-free.github.io/tocperfect).

## Additional Features

* Automatic console detection and loader configuration.

* Enter the originial Sony BIOS without removing the cheat cart containing the loader (for [ROM entrypoint](flashed-cheat-cart.md)).

* Format memory cards directly in the loader program, including any with the [FreePSXBoot](freepsxboot-exploit.md) exploit.

* Small loader size thanks to ps1-packer compression/decompression and space-concious optimizations.

* Boots more games via the [FreePSXBoot](freepsxboot-exploit.md) exploit successfully then any other backup loader.

* The most extensive [anti-piracy bypass system](anti-piracy-bypass.md) of any PS1 soft-mod seemlessly patches protected games on the fly. Non-stealth mod-chips and unmodified consoles essentially become stealth-modded consoles.

* Apply your own [GameShark codes](gameshark-code-support.md) loaded via memory card save files (up to 15 different save files per memory card, meaning you can have up to 30 different sets of GameShark codes available for selection!). Create the memory card save files on your PC, no need to type in super long codes on the console itself with a controller.

* Speeds up your xStation's boot time with a [specialized xStation Tonyhax International ROM](xstation.md).

* Portable [build system](build.md) using bare-bones `mipsel-none-elf` toolchain and no SDK.

| [Homepage](https://alex-free.github.io/tonyhax-international) | [GitHub](https://github.com/alex-free/tonyhax) | [PSX-Place Thread](https://www.psx-place.com/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles.37925/) | [PSX-Place Resource](https://www.psx-place.com/resources/tonyhax-international.1281/) | [PSXDEV Thread](http://www.psxdev.net/forum/viewtopic.php?f=66&t=3967) | [GBATemp Thread](https://gbatemp.net/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles-gameshark-cheat-cart-flasher.615892/##post-9922514) |

## Table Of Contents

* [Downloads](#downloads)
* [Usage](#usage)
* [Frequently Asked Questions](#faq)
* [Relevant Software](#relevant-software)
* [Building From Source](build.md)
* [Credits](credits.md)

## Downloads

### Version 1.5.2 (6/12/2024)

*   [tonyhax-international-v1.5.2](https://github.com/alex-free/tonyhax/releases/download/v1.5.2i/tonyhax-international-v1.5.2.zip)

----------------------------------

Changes:

*   Added ability to [load gameshark codes from different save files on memory cards](gameshark-code-support.md) in slot 1 and slot 2. Up to 15 different save files containing GameShark codes can be on a memory card, so you can have up to 30 different sets of GameShark codes available for selection from within the loader now!

*   Updated thigsgen to v2.0.4. The default output save file name is now `TONYHAXINTGS0`. THIGSGEN releases are now distributed in the `gameshark` folder already decompressed for you, the `.deb` files remain as they are.

*   Added ability to update text in-place for `debug_write()`, implemented beautifully in the newly re-written gameshark memory card save file name select function.

*   Added official support for Beat Mania Append 3rdMix Key Disc bypass. You can boot the game with Tonyhax International directly instead of having to use an intended key disc first to do so.

*   Improved memory card formatter function's UX.

*   Modifed RAM layout for larger executable decompressed size. `HAX` and `FF9` loader files are still only taking up 2 memory card slots though thanks to PS1 Packer compression.

*   Added back seperate `secondary-ff9.ld`. When using anything other then the Final Fantasy IX [save game exploit](save-game-exploit.md), you get a bit more user RAM and hence higher chance to load a target PS-EXE with `exec()` (`loadandexec()` still overcomes any such issues with overlap, but it is nice to have the full target exe loaded while the loader itself is running).

*   Loader optimizations for efficiency and size. Rewrote controller input parsing, memory card formatting, and gameshark code save file reading. Cleaned up code to use some local declarations instead of global ones when possible. Added some more comments.

*   Changed video mode switching (NTSC to PAL or PAL to NTSC) to happen as early as possible. The idea with this is we only need one call to change the video mode (instead of doing it 2 different places depending on if we are using exec() or loadandexec() bios functions based on target PS-EXE size). Not only does that save some complexity, it also just makes sense. You'd want to see PAL video in the loader if your playing a PAL game (and you have everything else setup for it to actually display correctly with a NTSC PS1 that can do video mode switching), as early as possible.

*   Releases now include `entry-bb.bin`, `entry-bb.elf`, `entry.bin`, `entry.elf`, `entry-ff9.bin`, and `entry-ff9.elf` (which are used to develop [save game exploits](save-game-exploit.md) and [gshax codes](https://alex-free.github.io/gshax-tool)). Distributing these files in the Tonyhax International releases negates the need to compile them yourself if you don't want to, and could allow more people to submit these to me.

*   Improved [documentation on RAM layout of executable](https://github.com/alex-free/tonyhax/blob/master/docs/ram-setups.md).

*   Other [general documentation improvements](readme.md#faq).

----------------------------------

[Previous versions](changelog.md).

## Usage

*   [Japanese PS1 Console Loader Instructions (SCPH-1000-SCPH-100)](japanese-ps1-instructions.md)
*   [Japanese PS2 Console Loader Instructions (SCPH-10000-SCPH-39000)](japanese-ps2-instructions.md)
*   [American/European PS1/PS2 Console Loader Instructions (SCPH-1001-SCPH-39004)](american-european-console-instructions.md)

## F.A.Q.

1) [Does the type of CD-R I am using matter?](#q-does-the-type-of-cd-r-i-am-using-matter)

2) [My console isn't reading discs?](#q-my-console-isnt-reading-discs)

3) [Why is my game not booting, locking up/crashing, audio stuttering, or FMV freezing?](#q-why-is-my-game-not-booting-locking-upcrashing-audio-stuttering-or-fmv-freezing)

4) [Can I use International to play protected games?](#q-can-i-use-international-to-play-protected-games)

5) [Can I play games that span multiple discs (i.e. Fear Effect) / have disc change features?](#q-can-i-play-games-that-span-multiple-discs-ie-fear-effect--have-disc-change-features)

6) [Why not combine Tonyhax and Tonyhax International into one project?](#q-why-not-combine-tonyhax-and-tonyhax-international-into-one-project)

7) [Why Can't Tonyhax/Tonyhax International Change The Video Mode From PAL to NTSC or vice versa on PS2s?](#q-why-cant-tonyhaxtonyhax-international-change-the-video-mode-from-pal-to-ntsc-or-vice-versa-on-ps2s)

8) [Why Are PAL Games Displaying a Black Screen On My Japanese or USA PSOne Slim with Tonyhax/Tonyhax International?](#q-why-are-pal-games-displaying-a-black-screen-on-my-japanese-or-usa-psone-slim)

9) [Why Are Newer PS2s Not Supported?](#q-why-are-newer-ps2s-not-supported)

10) [Why is removing the FreePSXBoot memory card before booting a game required?](#q-why-is-removing-the-freepsxboot-memory-card-before-booting-a-game-equired)

11) [Why does the DuckStation emulator say backdoor failed?](#q-why-does-the-duckstation-emulator-say-backdoor-failed)

12) [How Can I Help?](#q-how-can-i-help)

### Q: Does the type of CD-R I am using matter?

**A**: Yes, and so does the burner you use. I have wrote about my findings and put together [The Ultimate Guide To PSX CD-Rs](https://alex-free.github.io/psx-cdr).

### Q: My console isn't reading discs?

**A**: If your already following the [The Ultimate Guide To PSX CD-Rs](https://alex-free.github.io/psx-cdr), your console's optical drive may need a refurbishment. See my [Unofficial PSX CD-ROM Drive Service Manual](https://alex-free.github.io/unofficial-ps1-cd-drive-service-manual/) for PS1 consoles. I don't have one for PS2 yet.

### Q: Why is my game not booting, locking up/crashing, audio stuttering, or FMV freezing?

**A**: This is probably a disc read issue. Ensure you are using high quality CD-Rs, a good burner, and your console's optical drive is in good condition (see above question). If all of that doesn't help, maybe there is an issue in International. In such a case, please open a [generic issue](https://alex-free.github.io/unofficial-ps1-cd-drive-service-manual/).

### Q: Can I use International to play protected games?

**A**: Yes, International automatically detects protected games and applies a bypass to enable play. Each game is supported on a game by game basis, and there is a [list](anti-piracy-bypass.md#protected-games-support). If you know of a protected game that isn't on the list, or isn't working in some situation, please open an [anti-piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&projects=&template=antipiracy-issue.md&title=) and tell me all about it.

### Q: Can I play games that span multiple discs (i.e. Fear Effect) / have disc change features?

**A**: If you have any USA or PAL console, yes. If you have a Japanese console without a mod-chip, it gets more complicated. Please see the [japanese ps1 instructions (playing multiple discs)](japanese-ps1-instructions.md) and [japanese ps2 instructions (playing multiple discs)](japanese-ps2-instructions.md#playing-games-with-multiple-discs) sections for full info.

### Q: Why not combine Tonyhax and Tonyhax International into one project?

**A**: Socram8888 does not own a Japanese console, nor is he interested in getting one. While Socram8888 and I do work together to fix issues that effect both the original Tonyhax and Tonyhax International, we have different goals in regards to what the project should support so it makes the most sense to keep these 2 projects separate.

### Q: Why Can't Tonyhax/Tonyhax International Change The Video Mode From PAL to NTSC or vice versa on PS2s?

**A**: The early PS2 models that Tonyhax International supports do not have the ability to change the video mode from within PS1 mode from what we understand. 

You can change the video mode first while in PS2 mode however. For now you can resort to the **PS2 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/)**, this software allows you to explicitly change the video mode. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects (which is problematic when using the save game exploit since that disc must match your console's region). Here are the steps below to accomplish this:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.

*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.

*   Using wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).

*   Put in the real PSX game disc that you are using with a [save game exploit](save-game-exploit.md) when in PS1VModeNeg. The video mode will be forced to the inverse of the native one your console runs in.

*   Playing through your real PSX game disc may look or act weird in the changed video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in the import disc or backup CD-R and the PS1 game will boot at last.

### Q: Why Are PAL Games Displaying a Black Screen On My Japanese or USA PSOne Slim with Tonyhax/Tonyhax International?

**A**: I have verified my SCPH-101 displays a black screen when switching to PAL vidoe mode (no matter if that is switched via Tonyhax original, Tonyhax International, or by the game code itself).

This is a strange oddity, considering the following effects (unmodified hardware):
1) SCPH-1000-SCPH-9XXX will output PAL, but it will be in black and white if using composite AV.
2) SCPH-101 (confirmed by myself) and SCPH-100 (unconfirmed) will display a black screen the entire time PAL video mode is active if using composite AV.
3) SCPH-10000-SCPH-39004 stay in their native video mode always and ignore any request to change the video resolution (from within PS1 mode), using any output cables. There is a PS1VModeNeg workaround though, see the above question.

### Q: Why Are Newer PS2s Not Supported?

**A**: They may be already supported, but this isn't verified or documented in any way (yet). This will hopefully be investigated by myself soon.

### Q: Why is removing the FreePSXBoot memory card before booting a  game equired?

**A**: The original Tonyhax and UniROM use 2 different methods to patch reading of a slot 2 FreePSXBoot memory card after starting the game. This is designed to avoid crashing/freezing issues in-game when the FreePSXBoot memory card is attempted to be parsed by game code. Unfortunatly these patches implemented by UniROM and the original Tonyhax are not 100% compatibile with all games. When enabled they cause some games to not boot up or crash. In the interest of maximum compatibility with all games, I use no patches in Tonyhax International (and simply tell users to remove the FreePSXBoot memory card). Not having these patches is why Tonyhax International can boot more games then any other loader using FreePSXBoot currently.

### Q. Why does the DuckStation emulator say backdoor failed?

**A**: This is some incompatibility bug in all recent DuckStation versions that happens when the unlock drive function is used in the original Tonyhax and Tonyhax International loader. A sufficently old enough DuckStation version works fine (as do all versions of no $ psx emu). Alternatively you can set your cdrom bios version to a japanese one in the advanced settings of DuckStation, and the most recent DuckStation will also work fine (as long as auto-detect region for the emulated console is selected like it is by default, or it is specified as japanese explicitly). This is because the unlock function is not used for japanese consoles.

### Q. How Can I Help?

**A**: If you know C/MIPS assembly and can improve any of the code in International, open a [pull request](https://github.com/alex-free/tonyhax/pulls) with your changes. 

If you don't have programming experience something else that you could help out with is bring to my attention any protected games that are not yet supported in an [anti-piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&projects=&template=antipiracy-issue.md&title=). 

## Relevant Software

*   [TOCPerfect Patcher](https://alex-free.github.io/tocperfect) - patch the Tonyhax International loader into a disc image directly to expand the capabilities of the CD Player Swap Trick.

*   [CDRDAO-PLED](https://alex-free.github.io/cdrdao) - recommended burning software for Linux.

*   [EDCRE](https://alex-free.github.io/edcre) - EDC/EEC regenerator to allow patched EDC protected PSX games to be burned by CDRDAO-PLED's generic-mmc-raw driver correctly.

*   [APrip Homepage](https://alex-free.github.io/aprip) - created as a devlopement aid for the [anti-piracy bypass system](anti-piracy-bypass.md).

*   [PS1 DemoSwap Patcher Homepage](https://alex-free.github.io/ps1demoswap) - a similar project that uses the Tonyhax International loader.

*   [PSEXE2ROM Homepage](https://alex-free.github.io/psexe2rom) - what generates the Tonyhax International ROM file.

*   [NXFLASH](https://github.com/danhans42/nxflash) - the software which flashes cheat carts with the Tonyhax International ROM.

*   [FreePSXBoot](https://github.com/brad-lin/FreePSXBoot) - an exploit used in a Tonyhax International boot method.

*   [Tonyhax (the original) Github](https://github.com/socram8888/tonyhax) - what Tonyhax International is based on (_International is not an official version and at this point deviates quite greatly_).

*   [Tonyhax (the original) Homepage](https://orca.pet/tonyhax)
