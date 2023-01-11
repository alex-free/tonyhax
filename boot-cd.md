The Boot CD is the disc version of Tonyhax International. The BIN+CUE file set can be found in the `boot-cd` directory of each Tonyhax International release.

## Requirements

*   Any PS1 console (SCPH-1000-SCPH-102) or supported early PS2 console (SCPH-10000-SCPH-39004).
*   A high quality CD-R to burn the Tonyhax International Boot CD to.
*   A way to start the Boot CD, such as the [CD Player Swap Trick](#cd-player-swap-trick), [GameShark Cart Swap Trick](#gameshark-cheat-cart-swap-trick), or an unlicensed boot disc such as the PS-X-Change v2 disc).
*   A supported PS1 or PS2 console.

## PS-X-Change Disc (Or Similar Boot Disc)

For years special unlicensed 3rd party CD-ROM discs have been available which enable you to boot a backup CD-R using an artificial swap trick. The most famous of these is the PS-X-Change v2, which still seems to be sold through various distributors to this day.

The problem with these special CD-ROM discs is that they are limited by the technology of the time of which they were originally developed. They came out around the turn of the century, and have these problems:

*   Can not play some multi-disc games without doing an additional 'mid-game hot-swap trick'.
*   Can not update the TOC for the backup CD-R or 'imported region disc'. This causes CD audio playback to not work as expected, as well as crashes even in some games.
*   Can not play PSX game discs which contain the [APv2 additional copy protection](anti-piracy-bypass.md) without manually entering cheat codes each time you start the PS-X-Change v2 disc.

Instead of booting the backup CD-R or 'imported region disc' that you want to actually play with the PS-X-Change disc, you can boot the Tonyhax International Boot CD-R from the PS-X-Change disc. This starts the Tonyhax International loader with all of it's advantages. You can then boot the actual backup CD-R or 'imported region disc'.

An important thing to remember about the Tonyhax International loader is that it resets the entire console state. This means any cheat codes entered in i.e. the PS-X-Change menu (by pressing `SELECT` button _instead of_ the `START` button when you see the `Please Insert Import Game and Press START` text) **will not be in effect after the loader starts.**

## CD Player Swap Trick

This swap trick is why I did the initial Boot CD support for the original Tonyhax. It is the **only swap trick built into the console that does not involve swapping a moving disc**. It is found in:

*   All SCPH-1000 consoles.
*   The oldest SCPH-3000 consoles. Compatible SCPH-3000 consoles have System BIOS v1.1J and CDROM Controller VC0B (example serial number: `A6956171`). Incompatible SCPH-3000 consoles instead have System BIOS v2.1J and CDROM Controller VC1B (example serial number: `A7543968`).
*   The oldest SCPH-1001 consoles. Compatible consoles have a serial number lower then `U592XXXX` (where X can be any number) according to the original [Swap Trick Guide](https://gamefaqs.gamespot.com/ps/916392-PSX/faqs/4708) from 1996. Such consoles have either System BIOS v2.0A and CDROM Controller VC1A (example serial number: `U5361469`, July 1995 manufacture date) or System BIOS v2.1A and CDROM Controller VC1A (example serial number: `U5860989`, October 1995 manufacture date).
*   The oldest SCPH-1002 consoles. No serial number based info is available for this console model at this time. There also appears to be no date of manufacture available (like Japanese consoles), so it is truly a roll of the dice if a specific SCPH-1002 console has the CD Player Swap Trick or not. This is probably the most rare console model to find the trick in due to it's later release date.

To boot the Tonyhax International Boot CD-R with the CD Player Swap Trick:

*   Turn on the compatible PSX with no disc inserted.
*   Start the CD player.
*   Open the PSX CD drive lid, and put in **any real PSX game disc** (that is the same region as your console).
*   Find something to block the lid sensor. The real PSX game disc will start and then stop spinning after a few seconds.
*   Put in your burned Tonyhax International Boot CD-R.
*   Exit the CD Player, and wait for the Tonyhax International loader to start.

## GameShark Cheat Cart Swap Trick

Some versions of the official GameShark cheat cartridge software have a built-in back door that enables an artificial CD Player Swap Trick. This swap trick is found only in **GameShark v2.0-v3.2 cheat cartridges.** This means that as long as you have such a GameShark version, you can use the GameShark Swap Trick on any PSX console model that has a cartridge port on the back (SCPH-1000-SCPH-7502 models).

To boot the Tonyhax International Boot CD-R with the GameShark Cheat Cart Swap Trick:

*   Ensure that the GameShark cheat cart is firmly inserted into the back of your compatible PSX console. 
*   Find something to block the lid sensor. The CD drive lid should remain 'opened' with the lid sensor blocked for at least the rest of the Swap Trick.
*   Turn on the PSX with a real PSX game disc (that is the same region as your console) in the closed CD drive.
*   After the GameShark logo displays, use the `D-PAD` to navigate to the `Explorer` option in the GameShark main menu, then select it with the `X` button.
*   Use the `D-PAD` to navigate to the `Play CD Music` option in the `Explorer` sub-menu. You will see the message `Initializing CD System` for a few seconds, and then the `CD Audio Player` sub-menu will appear and the authentic PSX game disc will stop spinning.
*   Replace the authentic PSX game disc (that is the same region as your console) with the burned Tonyhax International Boot CD-R.
*   Press the `O` button to exit the `CD Audio Player` sub-menu, and to put you back at the `Explorer` sub-menu. Press the `O` button one last time to exit the `Explorer` menu, and to put you back at the main menu.
*   Use the `D-PAD` to navigate to the `Start Game` option, then select it with the `X` button. This will bring you to the `Start Game Options` sub-menu. Finally, press the `X` button one last time to select the `Start Game Without Codes` option which will boot the Tonyhax International Boot CD-R.