# [Tonyhax International](readme.md) -> Boot CD

The Boot CD is the disc version of Tonyhax International. The BIN+CUE file set can be found in the `boot-cd` directory of each Tonyhax International release.

If you have a PAL/European console, use the `tonyhax-boot-cd-europe` bin/cue files. If you have any other console use the `tonyhax-boot-cd-japan` bin/cue files.

## How To Use The Boot CD

You can not just put the boot CD into your console and have it start up like a real licensed PSX disc (unless you have a mod-chip), so you need to use one of the following methods:

* [CD Player Swap Trick](#cd-player-swap-trick)

* [GameShark Cartridge Swap Trick](#gameshark-cartridge-swap-trick)

* [GameShark CD Swap Trick](#gameshark-cd-swap-trick)

* [PS-X-Change Boot Disc](#ps-x-change-boot-disc)

* [Alien: Resurrection Back Door](#alien-resurrection-back-door)

All of the above methods come with the following limitations **when used alone, without using the Tonyhax International Boot CD as an intermediate boot disc**:

*   Can not play some multi-disc games without doing an additional 'mid-game hot-swap trick'.

*   Can not update the TOC for the backup CD-R or 'imported region disc'. This causes CD audio playback to not work as expected, as well as crashes even in some games.

*   Can not play PSX game discs which contain [additional copy protection](anti-piracy-bypass.md).

*   Does not recalibrate the CDROM controller for the swapped in disc (relevant to consoles with VC2/VC3 CDROM controllers, so circa SCPH-5500 and above) which results in poor disc reading performance for the swapped disc compared to the real PSX game disc used

## CD Player Swap Trick

This swap trick is why I did the initial Boot CD support for the original Tonyhax. It is the **only swap trick built into the console that does not involve swapping a moving disc**.

Requirements:

*   Any SCPH-1000 console.

*   The oldest SCPH-3000 consoles. Compatible SCPH-3000 consoles have System BIOS v1.1J and CDROM Controller VC0B (example serial number: `A6956171`). Incompatible SCPH-3000 consoles instead have System BIOS v2.1J and CDROM Controller VC1B (example serial number: `A7543968`).

*   The oldest SCPH-1001 consoles. Compatible consoles have a serial number lower then `U592XXXX` (where X can be any number) according to the original [Swap Trick Guide](https://gamefaqs.gamespot.com/ps/916392-PSX/faqs/4708) from 1996. Such consoles have either System BIOS v2.0A and CDROM Controller VC1A (example serial number: `U5361469`, July 1995 manufacture date) or System BIOS v2.1A and CDROM Controller VC1A (example serial number: `U5860989`, October 1995 manufacture date).

*   The oldest SCPH-1002 consoles. No serial number based info is available for this console model at this time. There also appears to be no date of manufacture available (like Japanese consoles), so it is truly a roll of the dice if a specific SCPH-1002 console has the CD Player Swap Trick or not. This is probably the most rare console model to find the trick in due to it's later release date.

How to:

1) Turn on the compatible PSX with no disc inserted.

2) Start the CD player.

3) Open the PSX CD drive lid, and put in **any real PSX game disc** (that is the same region as your console).

4) Find something to block the lid sensor. The real PSX game disc will start and then stop spinning after a few seconds.

5) Put in your burned Tonyhax International Boot CD-R.

6) Exit the CD Player, and wait for the Tonyhax International loader to start.

## GameShark Cartridge Swap Trick

Datel shipped a back door in some GameShark cartridges.

Requirements:

*   Any SCPH-1000-SCPH-7502 PSX console (newer models removed the parallel port that the cartridge plugs into).

*   A GameShark v2.0-v3.2 Cheat Cartridge with the original GameShark software. The earlier GameShark v1.x cartridges do not include the CD Player functionality, which is key to make this work.

How to:

1) Ensure that the GameShark cheat cart is firmly inserted into the back of your compatible PSX console. 

2) Find something to block the lid sensor. The CD drive lid should remain 'opened' with the lid sensor blocked for at least the rest of the Swap Trick.

3) Turn on the PSX with a real PSX game disc (that is the same region as your console) in the closed CD drive.

4) After the GameShark logo displays, use the `D-PAD` to navigate to the `Explorer` option in the GameShark main menu, then select it with the `X` button.

5) Use the `D-PAD` to navigate to the `Play CD Music` option in the `Explorer` sub-menu. You will see the message `Initializing CD System` for a few seconds, and then the `CD Audio Player` sub-menu will appear and the authentic PSX game disc will stop spinning.

6) Replace the authentic PSX game disc (that is the same region as your console) with the burned Tonyhax International Boot CD-R.

7) Press the `O` button to exit the `CD Audio Player` sub-menu, and to put you back at the `Explorer` sub-menu. Press the `O` button one last time to exit the `Explorer` menu, and to put you back at the main menu.

8) Use the `D-PAD` to navigate to the `Start Game` option, then select it with the `X` button. This will bring you to the `Start Game Options` sub-menu. Finally, press the `X` button one last time to select the `Start Game Without Codes` option which will boot the Tonyhax International Boot CD-R.

## GameShark CD Swap Trick

The swap trick ability of the PSX GameShark product line briefly disappeared when the product first shifted from a cartridge to a CD. **There is therefore no swap trick ability available in the GameShark CDX v3.3 or GameShark Lite CD discs** (use the [GameSharkHAX](gameshark-code.md) boot method as an alternative!). However, a different swap trick was added to the **GameShark v4.0 CD and all newer versions**.

Requirements:

*   SCPH-1001-SCPH-39001 USA PSX or PS2 console (these disc were only made for USA consoles).

*   GameShark CD v4.0 or newer.

How to:

1) Find something to block the lid sensor. The CD drive lid should remain 'opened' with the lid sensor blocked for the rest of the Swap Trick.

2) Turn on the console with the GameShark CD in the CD drive, it will spin up and start the GameShark software.

3) Once the GameShark software starts, **the GameShark CD will stop in the CD drive.**

4) Replace the GameShark CD with the burned Tonyhax International Boot CD-R.

5) Use the `D-PAD` to navigate to the `Start Game` option, then select it with the `X` button. This will bring you to the `Start Game Options` sub-menu. Press the `X` button to select the `Start Game Without Codes` option.

6) Press the `X` button one last time to boot the Tonyhax International Boot CD-R.

## PS-X-Change Boot Disc

For years, unlicensed 3rd party CD-ROM discs have been available which enable you to boot a backup CD-R using an artificial swap trick. The most famous of these is the PS-X-Change v2, which still seems to be sold through various distributors to this day.

The problem with these special CD-ROM discs is that they are limited by the technology of the time of which they were originally developed. They came out around the turn of the century, so they have all the same limitations as the other methods, crippling usability.

An important thing to remember about the Tonyhax International loader is that it resets the entire console state. This means any cheat codes entered in i.e. the PS-X-Change menu (by pressing `SELECT` button _instead of_ the `START` button when you see the `Please Insert Import Game and Press START` text) **will not be in effect after the loader starts.**

## Alien: Resurrection Back Door

On December 19th 2023 it was revealed by the YouTube channel [Modern Vintage Gamer](https://www.youtube.com/@ModernVintageGamer) that a [licensed PSX game](https://en.wikipedia.org/wiki/Alien_Resurrection_(video_game)) [shipped with a backdoor](https://www.youtube.com/watch?v=uRB7iUCX4KQ) that allows one to boot import and backup CD-Rs. This game is now however very expensive since this was disclosed.

Requirements:

*   A SCPH-1001-SCPH-39004 USA or PAL PS2.
*   An authentic Alien: Resurrection USA or PAL disc for your console.

How to:

1) Block the lid sensor of the console.

2) Power on the console with the lid sensor blocked, and Alien: Resurrection in the drive.

3) At the main menu, select `OPTIONS`.

4) In the options menu, enable the cheat menu with the button sequence: `CIRCLE` -> `DPAD-LEFT` -> `DPAD-RIGHT` -> `CIRCLE` -> `DPAD-UP` -> `R2`. Don't enter the `CHEAT MENU`.

5) Activate the advanced level select for the `CHEAT MENU` with the button sequence: `R1` -> `DPAD-DOWN` -> `R1` -> `DPAD-RIGHT` -> `L1` -> `DPAD-UP` -> `L2` -> `SQUARE`.

6) Enable the `Super Secret Code` with the button sequence: `DPAD-LEFT` -> `DPAD-UP` -> `DPAD-RIGHT` -> `DPAD-DOWN` -> `DPAD-RIGHT` -> `DPAD-UP` -> `DPAD-LEFT` -> `SQUARE` -> `TRIANGLE` -> `SQUARE` -> `TRIANGLE` -> `L1`.

7) Select the `CHEAT MENU` option, set the advanced level select to `LEVEL 6` `SECTION 1`.

8) Hold down `L1` and press the `CROSS` button once for the screen to go black and the disc drive to stop. Do not let go of `L1` yet, but change the Alien: Resurrection disc for the Tonyhax International boot CD.

9) Keep holding down `L1`, but also hold down `SQUARE` and `TRIANGLE` all at the same time.

10) Release all buttons to start the boot CD.
