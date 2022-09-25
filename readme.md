tonyhax international 

[alex-free.github.io](https://alex-free.github.io)
==================================================

Tonyhax International: The Ultimate Backup/Import Disc Loader SoftMod Solution For The Original PlayStation & Early Models Of PlayStation 2
===========================================================================================================================================

Brought to you by [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867), [Alex Free](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6018), and [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714). Built on the work of many [others](#credits).

Tonyhax International is a fork of the [Tonyhax](https://orca.pet/tonyhax/) "Software backup loader exploit thing for the Sony PlayStation 1" originally created by [Socram8888](https://github.com/socram8888). Tonyhax International is developed by Alex Free and MottZilla with many new features and upgrades compared to the original Tonyhax:

*   Supports all PS1 Consoles (Japanese, American, European, SCPH-1000-SCPH-102) **and** Early PS2 Consoles (Japanese, American, European, SCPH-10000-SCPH-39004).
*   More [save game exploits](#savegame) are available.
*   You can [flash](#rom) the Tonyhax International backup/import loader to a GameShark/Action Reply/cheat cartridge. Whenever the flashed cartridge is plugged into the back of a SCPH-1000-SCPH-7502 PS1 console when you power it on the Tonyhax International will boot instead of the shell program/BIOS (Sony screens/CD Player/Memory Card Manager).
*   Uses the newer[FreePSXBoot](https://github.com/bradl-in/FreePSXBoot) exploit/patching methods to disable FreePSXBoot memory cards that boot Tonyhax International after the FreePSXBoot exploit starts the loader from the memory card on all BIOS versions.
*   Completely automated testing/building/development suite of scripts in the source that supports building Tonyhax International on virtually any \*nix like OS.

Table of Contents
-----------------

*   [Downloads](#downloads)
*   [Usage](#usage)

_Japanese PS1 Consoles_

*   [Japanese PS1 Console Loader Instructions](#jps1)
*   [Playing Games That Contain Anti-Piracy Features On Japanese PS1 Consoles](#apjps1)
*   [Playing Games That Span Multiple Discs On Japanese PS1 Consoles](#mdjps1)

_Japanese PS2 Consoles_

*   [Japanese PS2 Console Loader Instructions](#jps2)
*   [Using the Swap Magic Tool](#swapmagictool)
*   [Playing Games That Contain Anti-Piracy Features On Japanese PS2 Consoles](#apjps2)
*   [Playing Games That Span Multiple Discs On Japanese PS2 Consoles](#mdjps2)
*   [Playing European/PAL Games On Japanese PS2 Consoles](#paljps2)

_American/European PS1/PS2 Consoles_

*   [American/European PS1/PS2 Console Loader Instructions](#uu)
*   [Playing Games That Contain Anti-Piracy Features On American/European PS1/PS2 Consoles](#apu)
*   [Playing Games That Span Multiple Discs On American/European PS1/PS2 Consoles](#apu)
*   [Playing PAL Games On American PS2 Consoles](#palups2)
*   [Playing Japanese/American Games On PAL PS2 Consoles](#ntscpalps2)

_Boot Methods_

*   [ROM/ROM Flasher CD](#rom)
*   [FreePSXBoot Exploit Memory Card Images](#freepsxboot)
*   [Boot CD](#bootcd)
*   [Save Game Exploit](#savegame)

_Burning CD-R Backups_

*   [CD-R Media For PS1 Backups](#cdr)
*   [Burning Programs For PS1 Backups](#burning)

_More Info_

*   [Building From Source](#building)
*   [Credits](#credits)

Links
-----

*   [Tonyhax International Homepage](https://alex-free.github.io/tonyhax-international)
*   [Tonyhax International GitHub](https://github.com/alex-free/tonyhax)
*   [PSX-Place Thread](https://www.psx-place.com/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles.37925/)
*   [PSX-Place Tonyhax International Resource](https://www.psx-place.com/resources/tonyhax-international.1281/)
[](https://www.psx-place.com/resources/tonyhax-international.1281/)*   [](https://www.psx-place.com/resources/tonyhax-international.1281/)[PSXDEV Thread](http://www.psxdev.net/forum/viewtopic.php?f=66&t=3967)
*   [GBATemp Thread](https://gbatemp.net/threads/tonyhax-international-backup-loader-for-all-japanese-usa-and-pal-ps1-consoles-early-ps2-consoles-gameshark-cheat-cart-flasher.615892/#post-9922514)
*   [PS1 DemoSwap Patcher Homepage](https://alex-free.github.io/ps1demoswap)
*   [PSEXE2ROM Homepage](https://alex-free.github.io/psexe2rom)
*   [FreePSXBoot](https://github.com/brad-lin/FreePSXBoot)
*   [Tonyhax (the original) Github](https://github.com/socram8888/tonyhax)
*   [Tonyhax (the original) Homepage](https://orca.pet/tonyhax)

Downloads
---------

### Version 1.1.0 (9/25/2022)

*   [tonyhax-v1.1.0-international](https://github.com/alex-free/tonyhax/releases/download/v1.1.0i/tonyhax-v1.1.0-international.zip)
*   [source code](https://github.com/alex-free/tonyhax/archive/refs/tags/v1.1.0i.zip)

Changes:

*   Updated to FreePSXBoot v2.1 (my own [fork](https://github.com/alex-free/FreePSXBoot) for now so that it compiles on [Fedora](https://github.com/brad-lin/FreePSXBoot/pull/97)). This means among other things that those 'fake' 64KB chinese PS1 memory cards now work with the FreePSXBoot images.
*   **Tonyhax International [FreePSXBoot](#freepsxboot) memory cards no longer need to be removed after booting the loader if they are in slot 2 of the console.** I have completely removed Socram8888's old FreePSXBoot patch. The new 'memory card timeout to disable' patch from the FreePSXBoot builder is now used instead of the 'pretend memory card is corrupted' patch from the original Tonyhax. The new patch works with all games, some games did not like the old patch method used. **The new patch also works correctly on every single PS1 BIOS version, including BIOS v1.0, v1.1, and v2.0.** The old patch never worked on BIOS v1.0, 1.1, or 2.0.
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
*   [source code](https://github.com/alex-free/tonyhax/archive/refs/tags/v1.0.8i.zip)

Changes:

*   Fixed the anti anti-piracy functionality regression for American/European consoles. You can now play backup or import PS1 games that have anti-piracy features (i.e. Dino Crisis) without issue on all American console and European consoles.
*   Removed the PAL licensed ROM flasher CD image, as it is not actually not needed. Any console that supports cheat carts (SCPH-1000 up to SCPH-750X models) will boot a CD-R burned via the current `tonyhax-rom-flasher.bin+tonyhax-rom-flasher.cue` files just fine.
*   Updated documentation on burning PS1 backups. Added info on games containing anti-piracy and or libcrypt protection. Also added info on replacing and modifying PS1 CD drives and changing bias/gain/laser resistance values.
*   Cleaned up build proccess and source tree.

### Version 1.0.7 (8/7/2022)

*   [tonyhax-v1.0.7-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.7i/tonyhax-v1.0.7-international.zip)
*   [source code](https://github.com/alex-free/tonyhax/archive/refs/tags/v1.0.7i.zip)

Changes:

*   The Tonyhax International loader memory card save file **is now named `HAX` instead of `BESLEM-99999TONYHAX` to allow for more exploitable games**. You will need to update both the save game exploit file for your game as well as the Tonyhax International loader file to use v1.0.7 if you are using a previou version of the save game exploit file for your game that is already on a memory card.
*   Removed the SetSessionSuperUltraCommandSmash and replaced it with [MottZilla](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=867)'s new method of re-reading TOC data for VC0 A, VC0 B, and VC1 A CDROM Controller BIOS firmwares. **This change reduces the time it takes to re-read the TOC data on the backup CD-R or import PS1 disc from 2-10 minutes on the SCPH-1000, SCPH-3000, and some SCPH-3500 japanese consoles to around 30 seconds with 100% reliability!**
*   Added [save game exploit](#savegame) support for Tekken 3 Japan/USA/PAL thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=671)) and [krystalgamer](https://github.com/socram8888/tonyhax/pull/20).
*   Added [save game exploit](#savegame) support for Tekken 2 Japan (rev 1 only), USA (rev 0 only), and PAL thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=671)) and [krystalgamer](https://github.com/socram8888/tonyhax/pull/20).
*   Added [save game exploit](#savegame) support for Downhill Snow Japan thanks to Patchouli ([karehaani](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=671)).

### Version 1.0.6 (8/3/2022)

*   [tonyhax-v1.0.6-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.6i/tonyhax-v1.0.6-international.zip)
*   [source code](https://github.com/alex-free/tonyhax/archive/refs/tags/v1.0.6i.zip)

Changes:

*   Added [save game exploit](#savegame) support for Castlevania Chronicle NTSC-J (only the first release, rev 1 is not working right now) (Alex Free) and 1500 Lite Series Castrol Honda Super Bike Racing NTSC-J (Alex Free).
*   Added [save game exploit](#savegame) support for Tony Hawk Pro Skater 2 NTSC-J (MottZilla) and 1500 Lite Series Castrol Honda VTR (MottZilla).

### Version 1.0.5 (7/27/2022)

*   [tonyhax-v1.0.5-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.5i/tonyhax-v1.0.5-international.zip)
*   [source code](https://github.com/alex-free/tonyhax/archive/refs/tags/v1.0.5i.zip)

Changes:

*   Added [save game exploit](#savegame) support for Doki Oki (NTSC-J), Crash Bandicoot 3 (NTSC-J), and The Legend Of Heroes I&II (NTSC-J). All these save game exploits were found by [Patchouli (karehaani)](http://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714).

### Version 1.0.4 (7/23/2022)

*   [tonyhax-v1.0.4-international](https://github.com/alex-free/tonyhax/releases/download/v1.0.4i/tonyhax-v1.0.4-international.zip)
*   [source code](https://github.com/alex-free/tonyhax/archive/refs/tags/v1.0.4i.zip)

Usage
-----

The Tonyhax International loader is the program that is booted on any PS1 or an early PS2 that enables the use of backup CD-Rs or import PS1 discs. The Tonyhax International loader can be booted on your PS1 with a [GameShark/cheat cart](#rom), [flashed memory card](#freepsxboot), [save game exploit](#savegame), or [CD-R](#bootcd). It provides the ability to properly play backup and import discs on all PS1 consoles, and early PS2 consoles (Japanese, USA, and PAL models SCPH-10000-SCPH-39004).

If you are using **any Japanese console**, at least one real Japanese NTSC-J PS1 game disc is required (any officially licensed Japanese PS1 disc will do). If you are using a **Japanese PS2 console (SCPH-10000-SCPH-3900-)** a Swap Magic Tool is also required. Neither of these are needed if you are using an American or European PS1/PS2 console.

Japanese PS1 Console Loader Instructions
----------------------------------------

Boot into the Tonyhax International loader using one of the boot methods below:

*   [ROM/ROM Flasher CD](#rom)
*   [FreePSXBoot Memory Card Images](#freepsxboot)
*   [Boot CD](#bootcd)
*   [Save Game Exploit](#savegame)

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

Playing Games That Span Multiple Discs On Japanese PS1 Consoles
---------------------------------------------------------------

There are some games which span multiple discs. And some of these games (such as Parasite Eve, Fear Effect, and Crono Cross) that span multiple discs require you to open the CD drive, remove disc 1, insert disc 2, and close the CD drive at some point in the game without providing a save game option at the disc swap. If you encounter this type of game on a Japanese PS1 console you have to do the "mid-game hot-swap trick":

*   When the game asks you to insert disc 2, unblock the lid sensor and remove the CD.
*   Put **any real authentic Japanese PSX disc** into the PS1 drive.
*   You will now be performing a _mid-game hot-swap trick_. Have the disc 2 you want to play in one hand, and whatever your using to block the lid sensor in another. Now block the lid sensor, freeing your one hand. Wait until the original real Japanese PSX disc stats spinning fast (~3 seconds) and **immediately** swap the disc with your free hand, and put in the actual disc 2 you want to play. You can now continue playing your game that spans multiple discs normally! This trick would work for games that span even more then 2 discs as well.

It is important to note however that most games that span multiple discs allow you to load a game save created on disc 1 while playing disc 2. This means you just need to save at the last point possible on disc 1, and then you can just boot disc 2 like normal and load your game save created earlier on disc 1. **Some games however do not allow this** as previously mentioned, so for those games you must use the **mid-game hot-swap trick** described above.

Playing Games That Contain Anti-Piracy Features On Japanese PS1 Consoles
------------------------------------------------------------------------

Some of the later PS1 games included anti-piracy functionality designed to prevent playing backups or imported versions (i.e. NTSC-U/PAL region) of the game on a Japanese console. These anti-piracy measures have mod-chips and swap tricks in mind. **As long as you do not have a non-stealth modchip in an early SCPH-3000 or SCPH-1000 console** you can play any game containing anti-piracy detection with Tonyhax International if they do not also contain the libcrypt protection, found in some PAL region games. It is only possible to play these games if you use a patched backup copy which has this libcrypt protection removed.

You can find patches to remove anti-piracy and or libcrypt protection from games on websites such as [ConsoleCopyWorld](https://consolecopyworld.com/psx/psx_protected_games.shtml). For example here is a patch for [PoPoRogue](https://consolecopyworld.com/psx/psx_poporogue.shtml), found by browsing through the [Protected Games](https://consolecopyworld.com/psx/psx_protected_games.shtml) page on CopyConsoleWorld.

Japanese Console Model

Plays Real Import NTSC-U/PAL PS1 Discs Containing Anti-Piracy?

Plays Backup CD-R NTSC-J/NTSC-U/PAL Discs Containing Anti-Piracy?

Plays Backup CD-R NTSC-J/NTSC-U/PAL Discs With Anti-Piracy Patched Out?

Plays Backup CD-R NTSC-J/NTSC-U/PAL Discs Containing Anti-Piracy+Libcrypt?

Plays Backup CD-R NTSC-J/NTSC-U/PAL Discs With Anti-Piracy+Libcrypt Patched Out?

SCPH-1000 - Early SCPH-3000

YES, (unless you have a non-stealth modchip)

YES, (unless you have a non-stealth modchip)

YES

NO, hardware does not support it

YES

Late SCPH-3000 - SCPH-100

NO, support has not been added yet

NO, supported has not been added yet

YES

NO, support has not been added yet

YES

Japanese PS2 Console Loader Instructions (SCPH-10000-SCPH-39000)
----------------------------------------------------------------

Available Boot Methods:

*   [Boot CD](#bootcd) (I don't know of anyway to boot this on an unmodified Japanese PS2 but it is available).
*   [Save game exploit](#savegame)

Japanese PS2 consoles **must have the DVD drive tray front panel removed to use Tonyhax International**. For the SCPH-10000, you can follow the method below (some newer consoles may slightly differ in the way to remove the DVD drive's front panel).

### Removing The DVD Drive Tray Front Panel

Turn on the Japanese PS2 console. Eject the DVD drive tray, and **while it is open** power off the console by either pulling the plug from the wall or PSU in the back of the console, or by flicking the power switch for the PSU on the back of the console. You can not use the power button because then the DVD drive tray will close before the console turns off. Now, flip the Japanese PS2 console upside down like in the image below:

![ps2 upside down](images/ps2-upside-down.jpg)

Now bring your focus to the bottom of the opened DVD drive tray. At the very top edge (highlighted in the picture above) is a tab. You want to jam a thin flat head screwdriver in between this tab and the DVD drive tray face plate as shown in the image below. Now, push with the flat head screwdriver to separate the DVD drive face plate from the rest of the DVD drive tray. **Be very gentle and only use a direct straight force towards the face plate. Do not go side to side when doing this or you risk breaking off an edge of the DVD drive tray. I am obviously not responsible for any damage you may do by doing this!** Once successful, the face plate will become removable. You are free to slide it back on at a later time, it just needs to be off for you to use the Japanese PS2 to boot backup/import PS1 games with Tonyhax International.

![ps2 drive tab](images/ps2-drive-tab.jpg)

With the DVD drive face plate off, flip over the Japanese PS2 console right side up. You can now see a gap at the bottom of the DVD drive. This is where you place the Swap Magic Tool in when using Tonyhax International on your Japanese PS2 console.

![ps2 drive cover removed](images/ps2-drive-cover-removed.jpg)

You can now use one of the supported boot methods to start the Tonyhax International loader on the Japanese PS2 console. You will most likely be using the [Save Game Exploit](#savegame), however you could be using some kind of intermediate boot disc to boot the [Boot CD](#bootcd) as well if you find one that supports Japanese PS1 consoles. Once you see the text `Put in a backup/import disc, then press X` appear, you need to use a Swap Magic Slide Tool to release the DVD drive to gain access to it without pressing the eject switch. A [video tutorial](https://www.youtube.com/watch?v=Ffv5m52zlEI) is available that shows how to use the Swap Magic Tool (in general), although the exact steps are also explained below. Once you use the Swap Magic Tool to swap in your import/backup CD-R while booted in the Tonyhax International loader, just press the cross button on your PS2 or PS1 controller to boot and play your game.

Important note: **do not eject the PS1 import or backup CD-R from the Japanese PS2 console until your done playing the game**. Unlike American and European consoles (which do not have this limitation), if you do so your game will stop working, and you will have to start Tonyhax International all over again to boot your import/backup CD-R and start playing again.

Using the Swap Magic Tool
-------------------------

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

Playing Games That Contain Anti-Piracy Features On Japanese PS2 Consoles
------------------------------------------------------------------------

Some of the later PS1 games included anti-piracy functionality designed to prevent playing backups or imported versions (i.e. NTSC-U/PAL region) of the game on a Japanese console. These anti-piracy measures have mod-chips and swap tricks in mind.

There is currently no support yet for playing unmodified backup CD-Rs or imported NTSC-U/PAL region game disc that contain anti-piracy checks for Japanese PS2 consoles. You have to patch a backup copy CD image and burn that to a CD-R to play these games on Japanese PS2 consoles.

You can find patches to remove anti-piracy and or libcrypt protection from games on websites such as [ConsoleCopyWorld](https://consolecopyworld.com/psx/psx_protected_games.shtml). For example here is a patch for [PoPoRogue](https://consolecopyworld.com/psx/psx_poporogue.shtml), found by browsing through the [Protected Games](https://consolecopyworld.com/psx/psx_protected_games.shtml) page on CopyConsoleWorld.

Some **PAL region games contain an additional anti-piracy measure known as libcrypt**. It is only possible to play these games if you use a patched backup copy which has this libcrypt protection and the anti-piracy features removed.

Playing Games That Span Multiple Discs on Japanese PS2 Consoles
---------------------------------------------------------------

There are some games which span multiple discs. And **some of these games** (such as Parasite Eve, Fear Effect, and Crono Cross) that span multiple discs require you to open the CD drive, remove disc 1, insert disc 2, and close the CD drive at some point in the game. Unfortunately only for Japanese PS2 consoles, you can not do this with Tonyhax International. If you get to a point in a game that requires ejecting the drive and putting in a new game, you have to play this part of the game on a different console (Any PS1 or American/European PS2 works). It is important to note however that most games that span multiple discs allow you to load a game save created on disc 1 while playing disc 2. This means you just need to save at the last point possible on disc 1, and then you can just boot disc 2 with Tonyhax International like normal and load your game save created earlier on disc 1, bypassing this limitation for certain games that allow saving right at disc swap mid-game.

Playing PAL/European Games On Japanese PS2 Consoles
---------------------------------------------------

The early PS2 models that Tonyhax International supports have the PS1 mode which runs PS1 software hard-coded to NTSC video mode. This can cause a problem with Tonyhax International if you want to play a European/PAL PS1 backup CD-R or import disc on a Japanese PS2 in PAL video mode. Since PS1 software can not change the video mode correctly from PS1 mode running on a PS2, you have to resort to the PS1 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/). This software allows you to explicitly change the video mode to PAL. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects. Here are the steps below to change your Japanese PS2 console to PAL video mode for Tonyhax International:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.
*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Put in the real Japanese PS1 game disc that you are using with a [save game exploit.](#savegame) when in PS1VModeNeg. The video mode will be forced to PAL now in the PS1 mode of your Japanese PS2.
*   Playing through your Japanese PS1 game disc may look or act weird in PAL video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in a PAL region import disc or PAL region backup CD-R and the PAL PS1 game will boot in PAL video mode.

American/European PS1/PS2 Console Loader Instructions
-----------------------------------------------------

Available boot methods for American and European PS2 consoles:

*   [Boot CD](#bootcd) (you can use something like the code breaker pro PS1 disc to boot it first)
*   [Save game exploit](#savegame)

Available boot methods for American and European PS1 consoles:

*   [ROM/ROM Flasher CD](#rom)
*   [FreePSXBoot Memory Card Images](#freepsxboot)
*   [Boot CD](#bootcd)
*   [Save Game Exploit](#savegame)

Once you see the text `Put in a backup/import disc` appear, eject the DVD drive (PS2) or open the CD drive (PS1).

*   If you are booting the Tonyhax International [Boot CD](#bootcd), you'll want to remove the spring or whatever you have blocking down the lid sensor to "open" the CD drive and stop the disc from spinning, allowing you to remove the Boot CD from the console's CD drive (PS1) or DVD drive (PS2).
*   If you are booting Tonyhax International via a [Save Game Exploit](#savegame), after ejecting the DVD drive (PS2) or opening the CD drive (PS1) the real PS1 game disc you used with a save game exploit will stop spinning, allowing you to remove it from the console's CD drive (PS1) or DVD drive (PS2).

All other boot methods don't have a disc usually in the drive already, so there is no disc to remove. With no disc currently in your console, you can now put in the backup CD-R or import PSX game disc you want to play. Close the CD drive (PS1) or DVD drive (PS2). The console will detect that the drive has been closed and will spin up your disc. The console will then send some commands and boot the disc.

Playing Games That Contain Anti-Piracy Features On American/European PS1/PS2 Consoles
-------------------------------------------------------------------------------------

Since the original Tonyhax v1.4.3 release that Tonyhax International is based on there has been support for playing unmodified backup CD-R copies and or import discs of games that contain anti-piracy functionallity through the Tonyhax loader. Tonyhax International will boot these discs fine.

Some **PAL region games contain an additional anti-piracy measure known as libcrypt**. It is only possible to play these games with Tonyhax International if:

*   You burn a patched backup copy which has this libcrypt protection removed to a CD-R.
*   You use the original PAL region PS1 disc.
*   You burn a backup CD-R in a [special way](https://github.com/Kippykip/SBITools) to keep the libcrypt protection working.

Playing Games That Span Multiple Discs On American/European PS1/PS2 Consoles
----------------------------------------------------------------------------

All American and European consoles do not have the same limitations as the Japanese consoles and can play games that span multiple discs like normal.

Playing PAL Games On American PS2 Consoles
------------------------------------------

The early PS2 models that Tonyhax International supports have the PS1 mode which runs PS1 software hard-coded to NTSC video mode. This can cause a problem with Tonyhax International if you want to play a European/PAL PS1 backup CD-R or import disc on a American PS2 in PAL video mode. Since PS1 software can not change the video mode correctly from PS1 mode running on a PS2, you have to resort to the PS1 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/). This software allows you to explicitly change the video mode to PAL. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects. Here are the steps below to change your American PS2 console to PAL video mode for Tonyhax International:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.
*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Put in the real American PS1 game disc that you are using with a [save game exploit.](#savegame) when in PS1VModeNeg. The video mode will be forced to PAL now in the PS1 mode of your American PS2.
*   Playing through your American PS1 game disc may look or act weird in PAL video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in a PAL region import disc or PAL region backup CD-R and the PAL PS1 game will boot in PAL video mode.

Playing Japanese/American Games On PAL PS2 Consoles
---------------------------------------------------

The early PS2 models that Tonyhax International supports have the PS1 mode which runs PS1 software hard-coded to NTSC video mode. This can cause a problem with Tonyhax International if you want to play a Japanese/American PS1 backup CD-R or import discs on a PAL PS2 in NTSC video mode. Since PS1 software can not change the video mode correctly from PS1 mode running on a PS2, you have to resort to the PS1 homebrew software known as [PSVModeNeg](https://www.psx-place.com/threads/ps1vmodeneg-by-sp193.25050/). This software allows you to explicitly change the video mode to PAL. An older version of PSVModeNeg is required if you want to use it's effects with Tonyhax International, specifically [v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip). This version simply inverses the current video mode of the console, rather then reading the PS1 game disc to figure out what video mode the disc itself expects. Here are the steps below to change your PAL PS2 console to NTSC video mode for Tonyhax International:

*   Download [PSVModeNeg v1.0.1](https://alex-free.github.io/tonyhax-international/PS1VModeNeg-1.0.1.zip) and extract the file `PS1VModeNeg.elf`.
*   Copy the file `PS1VModeNeg.elf` to a FAT32 formatted USB flash drive that works with your soft-modded PS2. You can soft-mod your PS2 with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208), [FreeDVDBoot](https://github.com/CTurt/FreeDVDBoot) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248) to be able to use PS1VModeNEG on your PS2 console.
*   Using uLaunchELF or wLaunchELF load the `PS1VModeNeg.elf` file from the `mass` device (your flash drive).
*   Put in the real PAL PS1 game disc that you are using with a [save game exploit.](#savegame) when in PS1VModeNeg. The video mode will be forced to NTSC now in the PS1 mode of your PAL PS2.
*   Playing through your PAL PS1 game disc may look or act weird in NTSC video mode, ignore this. Just get to the exploit method and start Tonyhax International. Put in a NTSC disc and the NTSC PS1 import or backup disc will boot in NTSC video mode.

ROM/ROM Flasher CD
------------------

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

Boot CD
-------

CD BIN+CUE files containing the Tonyhax International loader are available. The Boot CD can be booted by a mod chip, swap trick, or unofficial boot disc (i.e. PSX Change v2). Inside the Tonyhax International releases (downloadable above) in the `boot-cd` directory are the following files:

*   tonyhax-boot-cd-europe.bin
*   tonyhax-boot-cd-europe.cue
*   tonyhax-boot-cd-japan.bin
*   tonyhax-boot-cd-japan.cue

If you have a SCPH-102 use the European BIN+CUE files. For everything else you can use the Japanese BIN+CUE file set.

If you have an old enough PlayStation console you can simply use the CD Player Swap Trick method to start the Tonyhax International Boot CD. These PlayStation models have the CD Player Swap Trick:

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

Save Game Exploit
-----------------

The original way to boot the Tonyhax International loader is through a special game save on a PS1 memory card that you load while in a specific, supported real PS1 game that you can play normally on your PS1 or early PS2 console (SCPH-10000-SCPH-39004 models). You need to copy the `HAX` file and the game exploit file **specific to the original real PS1 game you own** to the PS1 memory card, then load the save in a specific way in the exploitable game. Described below are 2 different methods to copy these files to a PS1 memory card. One involves using a PS2, the other involves using special hardware that allows you to write to the PS1 memory card directly from your computer.

### PS2 Installation Method Requirements

You can use a PS2 console to copy the save game exploit files to a PS1 memory card from a USB flash drive. This method of getting the required files on the PS1 memory card requires:

*   A real PS1 game disc that matches your console's region and has a save game exploit file available.
*   Any PS1 console, or early PS2 console (SCPH-39000 or lower model number).
*   An authentic PS1 memory card that has enough space to hold the hacked game save file and the Tonyhax International file.
*   A FAT32 formatted USB flash drive that your PS2 console can read (**not all USB flash drives seem to work, you may need to do a bit of trial and error testing to find one that you can use**).
*   A PS2 console that can run uLaunchELF (Models newer then SCPH-39000 can therefore be used for this step, but they can not be used to boot into Tonyhax International using the game save). You could do this with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248).

You want to **use the Raw save game exploit file for your exploitable game (in the `entrypoints` directory) and the Raw loader file `HAX` (in the `loader` directory)** when using the uLaunchELF/PS2 installation method. The Raw filenames for each save game exploit is available in the table below.

### PS3 Memory Card USB Adapter/DexDrive/Computer Installation Method

Instead of using a PS2 to copy the save game exploit files, you can use a Dex Drive or similar with a visual memory card editor (such as [OrionSoft's PS1 Memory Card Manager](http://onorisoft.free.fr/retro.htm?psx/psx.htm) or [Dex-plorer](https://archive.org/details/inter-act-dex-plorer-ver.-1.10.950)), to modify a PS1 memory card's contents directly with a computer. This way of adding the required save game exploit files would only require:

*   A real PS1 game disc that matches your console's region and that has save game exploit files available.
*   Any PS1 console, or early PS2 console (SCPH-10000 to SCPH-39000 models).
*   An authentic PS1 memory card that has enough space to hold the hacked game save file and the tonyhax file.
*   A DexDrive, PS3 Memory Card USB adapter, or other hardware that allows you to write and modify a PS1 memory card with a computer.
*   Software such as [OrionSoft's PS1 Memory Card Manager](http://onorisoft.free.fr/retro.htm?psx/psx.htm) (for the PS3 Memory Card USB adapter) or [Dex-plorer](https://archive.org/details/inter-act-dex-plorer-ver.-1.10.950) (for the DexDrive), or [MemcardRex](https://github.com/ShendoXT/memcardrex) (for general memory card file managment and manipulation).

You want to **use the MCS save game exploit file for your exploitable game (in the `entrypoints` directory) and the MCS loader file `tonyhax.mcs` (in the `loader` directory)** when using the uLaunchELF/PS2 installation method. The MCS filenames for each save game exploit is available in the table below.

Game

Region

Code

MCS file

Raw file

Brunswick Circuit Pro Bowling

NTSC-U

SLUS-00571

brunswick1-us.mcs

BASLUS-00571

Brunswick Circuit Pro Bowling

PAL-E

SLES-01376

brunswick1-eu.mcs

BESLES-01376

Brunswick Circuit Pro Bowling 2

NTSC-U

SLUS-00856

brunswick2-us.mcs

BASLUS-00856

Brunswick Circuit Pro Bowling 2

PAL-E

SLES-02618

brunswick2-eu.mcs

BESLES-02618

Castlevania Chronicle - Akumajou Dracula (only first release of the game (rev 0), rev 1 does not work right now)

NTSC-J

SLPM-86754

cc-jp.mcs

BISLPM-86754DRACULA

Castlevania Chronicles

NTSC-U

SLUS-01384

cc-us.mcs

BASLUS-01384DRACULA

Castrol Honda Superbike \[SuperLite 1500 Series\]

NTSC-J

SLPM-86489

castrolsb-jp.mcs

BISLPM-86489CHSv1

Castrol Honda Superbike Racing

NTSC-U

SLUS-00882

castrolsb-us.mcs

BASLUS-00882CHSv1

Castrol Honda Superbike Racing

PAL-E

SLES-01182

castrolsb-eu.mcs

BESLES\_01182CHSv1

Castrol Honda VTR \[SuperLite 1500 Series\]

NTSC-J

SLPM-86922

castrolvtr-jp.mcs

BISLPM-86922CHSVTRv1

Castrol Honda VTR

PAL-E

SLES-02942

castrolvtr-eu.mcs

BESLES-02942CHSVTRv1

Cool Boarders 4

NTSC-U

SCUS-94559

coolbrd4-us.mcs

BASCUS-9455916

Cool Boarders 4

PAL-E

SCES-02283

coolbrd4-eu.mcs

BESCES-0228316

Crash Bandicoot 2: Cortex Strikes Back

NTSC-J

SCPS-10047

crash2-jp.mcs

BISCPS-1004700000000

Crash Bandicoot 2: Cortex Strikes Back

NTSC-U

SCUS-94154

crash2-us.mcs

BASCUS-9415400047975

Crash Bandicoot 2: Cortex Strikes Back

PAL-E

SCES-00967

crash2-eu.mcs

BESCES-0096700765150

Crash Bandicoot 3: Warped

NTSC-J

SCPS-10073

crash3-jp.mcs

BISCPS-1007300000000

Crash Bandicoot 3: Warped

NTSC-U

SCUS-94244

crash3-us.mcs

BASCUS-9424400000000

Crash Bandicoot 3: Warped

PAL-E

SCES-01420

crash3-eu.mcs

BESCES-0142000000000

Doki Oki

NTSC-J

SLPS-00130

doki-oki-jp.mcs

BISLPS-00130DOKIOH

Downhill Snow

NTSC-J

SLPS-01391

downhill-snow-jp.mcs

BISLPS-01391SKI00S

Sports Superbike

PAL-E

SLES-03057

superbike1-eu.mcs

BESLES-03057SSBv1

Sports Superbike 2

PAL-E

SLES-03827

superbike2-eu.mcs

BESLES-03827SSII

Tekken 2 (only second release of the game (rev 1), rev 0 does not work right now)

NTSC-J

SLPS-00300

tekken2-jp.mcs

BISLPS-00300TEKKEN-2

Tekken 2 (only first release of the game (rev 0), rev 1 does not work right now)

NTSC-U

SLUS-00213

tekken2-us.mcs

BASLUS-00213TEKKEN-2

Tekken 2

PAL-E

SCES-00255

tekken2-eu.mcs

BESCES-00255TEKKEN-2

Tekken 3

NTSC-J

SLPS-01300

tekken3-jp.mcs

BISLPS-01300TEKKEN-3

Tekken 3

NTSC-U

SLUS-00402

tekken3-us.mcs

BASLUS-00402TEKKEN-3

Tekken 3

PAL-E

SCES-01237

tekken3-eu.mcs

BESCES-01237TEKKEN-3

The Legend Of Heroes I&II

NTSC-J

SLPS-01323

the-legend-of-heros-1-and-2-jp.mcs

BISLPS-01323010001

Tony Hawk's Pro Skater 2

NTSC-J

SLPM-86751

thps2-jp.mcs

BISLPM-86751CEEAG01

Tony Hawk's Pro Skater 2

NTSC-U

SLUS-01066

thps2-us.mcs

BASLUS-01066TNHXG01

Tony Hawk's Pro Skater 2

PAL-DE

SLES-02910

thps2-de.mcs

BESLES-02910TNHXG01

Tony Hawk's Pro Skater 2

PAL-E

SLES-02908

thps2-eu.mcs

BESLES-02908TNHXG01

Tony Hawk's Pro Skater 2

PAL-FR

SLES-02909

thps2-fr.mcs

BESLES-02909TNHXG01

Tony Hawk's Pro Skater 3

NTSC-U

SLUS-01419

thps3-us.mcs

BASLUS-01419TNHXG01

Tony Hawk's Pro Skater 3

PAL-DE

SLES-03647

thps3-de.mcs

BESLES-03647TNHXG01

Tony Hawk's Pro Skater 3

PAL-E

SLES-03645

thps3-eu.mcs

BESLES-03645TNHXG01

Tony Hawk's Pro Skater 3

PAL-FR

SLES-03646

thps3-fr.mcs

BESLES-03646TNHXG01

Tony Hawk's Pro Skater 4

NTSC-U

SLUS-01485

thps4-us.mcs

BASLUS-01485TNHXG01

Tony Hawk's Pro Skater 4

PAL-DE

SLES-03955

thps4-de.mcs

BESLES-03955TNHXG01

Tony Hawk's Pro Skater 4

PAL-E

SLES-03954

thps4-eu.mcs

BESLES-03954TNHXG01

Tony Hawk's Pro Skater 4

PAL-FR

SLES-03956

thps4-fr.mcs

BESLES-03956TNHXG01

XS Moto

NTSC-U

SLUS-01506

xsmoto-us.mcs

BASLUS-01506XSMOTOv1

XS Moto

PAL-E

SLES-04095

xsmoto-eu.mcs

BESLES-04095XSMOTO

### Copying The Files On Your PS1 Memory Card With A PS2

When using the PS2 to copy the files over, first copy the Raw loader file named `HAX` (found in the `loader` directory in each Tonyhax International release) and the Raw file for your compatible exploitable game (named in the table above, found in the `entrypoints` directory) to the FAT32 USB flash drive that your PS2 can read using a computer.

After the correct memory card save game exploit **Raw** file and the `HAX` file is copied to the FAT32 formatted USB flash drive that your PS2 can read, eject the USB flash drive from your computer and insert it and a PS1 memory card into the PS2. Start the uLaunchElf program and navigate to the `mass` device (this is your USB flash drive) with the `DPAD` on the controller, then select it with the `circle` button. Using the `DPAD` to navigate, press the `cross` button on the controller to highlight both the `HAX` and the **Raw** save game exploit file that you previously copied to the USB flash drive. Now Press the `R1` button on the controller to make the file operations menu appear in uLaunchELF. Use the `DPAD` to move to the copy function and then press the `circle` button to select it. Now press the `triangle` button to navigate out of the `mass` device and then use the `DPAD` and then the circle button to navigate into either the `MC0` (if the PS1 memory card is in slot 1 of the PS2) or `MC1` (if the PS1 memory card is in slot 2 of the PS2) device. Press the `R1` button to again make the file operations menu appear in uLaunchElF. Use the `DPAD` to navigate to the paste option and press the `circle` button to finally paste both the `HAX` and the raw save game exploit file. Now you can press the `triangle` button to navigate out of the PS1 memory card device, and remove the memory card from the PS2 console.

### Using The Save Game Exploit

Now that you have the save game exploit files on the PS1 memory card, start the real PS1 game on your console with the PS1 memory card containing the save game files inserted in it. If you are using a Japanese PS1, it is recommended that you power off the console, put in the Japanese version of the game that has a save game exploit file available, block the lid sensor, and then turn on the console and have it boot the game. In either case, follow the instructions for the real PS1 game you are using described below:

Game

Specific Instructions

Cool Boarders 4

Boot the game. It should say the records and settings have been automatically loaded. Click on `ONE PLAYER`.

Crash Bandicoot games

Boot the game, on the title menu, choose `LOAD GAME`. On the save game list, select `TONYHAX` and press X.

Brunswick games

Boot the game as you'd normally do. On the main menu, select `LOAD GAME`, then Select `MEMORY CARD 1`. After about three seconds tonyhax should be running.

Castrol Honda Superbike Racing and Sports Superbike 1

On the language selection screen, if prompted to, select the English language. Enter the Memory Card menu. Load game from the Memory Card. Click accept after it's done loading. On the main menu, select `Race`, then `Single race`.

Castrol Honda VTR, Sports Superbike 2 and XS Moto

If you are using the European version, on the language selection screen select the English language. On the main menu, choose `Options`. Select `Load game` and choose the memory card where the save is stored. Back on the main menu, click on either `Single Race` or `Championship`.

Doki Oki

Boot the game as you'd normally do. Press start, circle, circle, then circle one last time to navigate through the main menu and load the save file.

Downhill Snow

Boot the game as you'd normally do. Use the X button to select `SCENARIO`, then `CONTINUE`, now select the save file in slot 1 or slot2. On the next screen after loading the save file select `CONFIG`, then `RANKING`, then `Moguls`. Immeditely after select `Moguls` press the right directional key until the blue screen appears, then let go of all buttons on the controller.

The Legend Of Heroes I&II (single game compilation)

Boot the game as you'd normally do. On the main menu, select the Legend Of Heroes I (the I button on the left), **not The Legend Of Heroes II (the II button on the right)**. Once in The Legend Of Heroes I load the save file.

Tony Hawk Pro Skater games

Boot the game as you'd normally do. On the main menu, wait until the save file is automatically loaded (it should say `Loading TONYHAX EU/US/DE/FR`, depending on the game's region). After it's done, choose the `CREATE SKATER` menu and press X.

Tekken games

Boot the game as you'd normally do. On the main menu, select `Survival Mode`, and pick a character. Die at any point to end the survival round, press start on the stats screen, and wait. **The screen will fade to black, and in a few seconds the Tonyhax International loader will start. There are no colors displayed while the Tonyhax International loader is started with a Tekken save game exploit, unlike all other games.**

CD-R Media For PS1 Backups
--------------------------

Only use high-quality CD-R media. If you want good results burning backups for your PS1 your CD-R media should contain:

*   High quality dye (SuperAZO, AZO, or Phthalocyanine).
*   A highly reflective layer system.
*   High quality polycarbonate and "sealing" process combining all parts of the CD-R.

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

Do not use cheap/poor quality CD-R media, which is almost always all that is available in retail stores and most likely any CD-R that is not "archival grade". Poor quality cheap CD-R media _can_ result in:

*   Slower loading times/in-game lag because of CD drive tracking errors (bad noises from the CD drive).
*   Issues reading data off of the disc possibly resulting in a game to freeze and motor power off in the CD drive.
*   Skipping/silent audio and or music.

Later PS1 consoles (starting at the SCPH-5000 series and newer) and all PS2 consoles have a much greater tolerance to poor quality CD-R media, and _may_ work fine with it however in general it is still best to just always use Verbatim DataLifePlus/UltraLife CD-Rs or something of similar quality. Here is the ATIP information displayed by `cdrecord -atip` for a Maxell Music CD-R:

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

Burning Programs For PS1 Backups
--------------------------------

*   [IMGBurn](https://www.imgburn.com) (Windows).
*   [CDRDAO](http://cdrdao.sourceforge.net) (Mac OS X/Linux/\*BSD/Windows).

If you use cdrdao, you must use the `--swap` argument for discs with CDDA audio or the game will have no music! Example:

    cdrdao write --speed 1 --swap --eject yourgame.cue

Building From Source
--------------------

You can compile Tonyhax International from source using any operating system which supports [Crosstool-NG](https://crosstool-ng.github.io/) using a script that builds a local tool-chain within the source directory that does not install anything into your system.

If you are running _Fedora or Debian_ (Windows Subsystem For Linux can run these operating systems on Windows to provide a sufficient build environment), you can download the build dependencies automatically with the `get-deps` script, which is in the `scripts` folder found in the Tonyhax International [source](https//alex-free.github.io/tonyhax). **The only dependency the `get-deps` script does not install is `wine`.**Wine is currently required because the ROM file must be made into a [NXFlash](https://github.com/danhans42/nxflash) compatible format for the flasher CD, and currently that is done by the Windows program `romfile.exe` found in NXFlash.

If you are running some other Linux distribution, a \*BSD operating system, or something else that supports [Crosstool-NG](https://crosstool-ng.github.io/) but is not yet supported by the `get-deps` script, you need to install the equivelent packages or software, including wine. Then everything should work nicely in the next step.

Now that all the dependencies are installed, you can build the tool chain which compiles Tonyhax International. The way this works is actually highly unusual, but I think extremely elegant and clean. First execute the `build-local-tool-chain` script, which is in the `scripts` folder found in the Tonyhax International [source](https//alex-free.github.io/tonyhax). **As long as you installed all the required dependencies** a tool chain will be built and configured to be locally installed within the `crosstool-ng` sub module folder found in the Tonyhax International source. This means that _nothing is changed on your system_ by installing the tool chain with the `build-local-tool-chain` script as it is completely portable accessible in the Tonyhax International source itself.

The `build-local-tool-chain` script also ensures that all sub modules are downloaded by running `git submodule update --init --recursive`. Now we can finally use the local tool chain to build Tonyhax International by running the script `./build-with-local-tool-chain`, found in the `scripts` directory of each Tonyhax International release. After you build Tonyhax International a release `.zip` file will be generated in the root of the source directory.

Credits
-------

### Tonyhax Internationl - The Tonyhax Team

_Alex Free_

*   Created the original TOCPerfect concept, first released as [TOCPerfect v1.0](https://alex-free.github.io/tocperfect).
*   First discovered that SetSession is bugged on the VC0 A, VC0 B, and VC1 A CDROM BIOS versions, and came up with the initial bypass idea by mashing SetSession in frustration on MottZilla's PSX CDROM Debugger program that was created to debug the SetSession command on a early SCPH-1001, SCPH-1000, and SCPH-3000 consoles specifically. Since then Martin Korth has confirmed that SetSession is bugged on VC0 A, VC0 B, and VC1 A CDROM BIOS versions.
*   Later discovered that SetSession's bug on early hardware can be bypassed by sending SetSession for a non-existant Session 2, waiting for 2 out of 3 expected interrupts, and then immediately sending SetSession 1. The idea to involve SetSession 2 however was MottZilla's.
*   Wrote [PSEXE2ROM](https://alex-free.github.io/psexe2rom) to MottZilla's specifications so that it could be integrated into the source tree for ROM support.
*   Integrated support for all Japanese PS1 and early PS2 consoles (SCPH-1000-SCPH-39000).
*   Integrated support for all new save game exploits from MottZilla and Patchouli.
*   Wrote TOCPerfect support in the loader.
*   Ported the famous Castlevania Chronicles stack overflow exploit from the USA version to the Japanese Rev 0 version.
*   Ported the 1500 Lite Series Castrol Honda Super Bike Racing stack overflow exploit from the USA version to the Japanese version.

_MottZilla_

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

_Patchouli(karehaani)_

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

### Tonyhax Acknowledgements

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