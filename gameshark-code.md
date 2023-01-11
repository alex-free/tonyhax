GameSharkHAX is the newest way to boot the Tonyhax International loader using special [game disc specific](#gamesharkhax-supported-game-discs) GameShark codes. GameSharkHAX enables you to use a [GameShark](#psx-gameshark-version-comparison) (or [other cheat device](#gshax-with-other-gameshark-cds-or-cheat-cartridges)) which **doesn't have a built-in swap trick** to stating the Tonyhax International loader.

## Requirements

*   Any PS1 console (SCPH-1000-SCPH-102) or supported early PS2 console (SCPH-10000-SCPH-39004).
*   A cheat device.
*   An authentic PSX game disc and [corresponding GameSharkHAX code](#gamesharkhax-supported-game-discs).
*   A PS1 memory card with enough free space to store the _Tonyhax International Loader_ file.
*   A way to copy file(s) to the PS1 memory card (a soft-modded ps2 can do this).

## History

All GameSharks up to version 3.2 were distributed as a cheat cart that plugs into the cartridge port found on older PSX console models. GameShark v2.0-v3.2 cheat carts are notable for having the [GameShark Cart Swap Trick](boot-cd.html#gameshark-cheat-cart-swap-trick), a well known back door that can be used to boot the Tonyhax International [Boot CD](boot-cd.html). These GameShark carts require an older PSX console to use (SCPH-1000 through the SCPH-7502 consoles) because the cartridge port was removed in all newer models.

In response to Sony removing the cartridge port on newer console models, the new GameShark version 3.3 (and all subsequent versions) where released as an unlicensed CD-ROM disc, which came with the following limitations:

*   Only works on USA consoles (since the console sees the CD-ROM as a real licensed SCEA game disc). The cartridge versions in comparison work on literally any console with a cartridge port, even the SCPH-1000.
*   Requires a standard PS1 memory card (GS Lite only) OR a proprietary code storage memory card like device (all other CD versions) to save and load existing codes from.
*   NO [GameShark Cart Swap Trick](boot-cd.html#gameshark-cheat-cart-swap-trick) ability.

The upside with the CD GameSharks however is obviously that they work on the newer SCPH-900X and SCPH-100 PSX consoles that lack the cartridge port.

The GameShark Lite even works on the early USA PS2 consoles that Tonyhax International supports (SCPH-30001-SCPH-39001) since it uses a standard PS1 memory card. All other PSX CD GameSharks from what I understand can only use the proprietary code storage memory card like device to save and load code from. I've heard that this proprietary code storage memory card like device will not fit into a PS2 console correctly but have not verified this myself yet.

I know of a PS2 specific GameShark CD known as the 'GameShark2 v1.0' for USA PS2s. This GameShark CD requires an apparently different fitting proprietary code storage memory card like device that does fit and work in a PS2 properly. It is unknown if this proprietary code storage memory card like device for the PS2 would work on a PS1 with an older PSX GameShark CD that requires such a device for code storage.

## PSX GameShark Version Comparison

_Note:_ No GameShark CD versions have a [built-in swap trick](#gameshark-swap-trick).

* GameShark v1.x (CART) - **does not have a [built-in swap trick](#gameshark-swap-trick)**, so entering GSHAX codes manually into such a cart is a useful method to start the Tonyhax International loader.
* GameShark v2.0-v3.2 (CART) - **has a [built-in swap trick](#gameshark-swap-trick)** which is more convenient then GSHAX codes to start the Tonyhax International.
* GameShark v3.3 CDX (CD) - Requires a proprietary memory card-like dongle to save/load codes from (which apparently prevents it from working with USA PS2s as it doesn't fit correctly).
* GameShark Lite (CD) - **The best version ever IMO**. It is the nly CD version that can save/load codes from a normal PS1 memory card. Works on USA PS2 consoles.
* GameShark v4 and v5 (CD) - Requires a proprietary memory card-like dongle to save/load codes from (which apparently prevents it from working with USA PS2s as it doesn't fit correctly).


## Using GSHAX Codes With The GameShark Lite CD

The GameShark Lite CD version is the only GameShark CD that can _load and save codes on a regular PS1 memory card_. From what I understand every other GameShark CD version requires a specific, proprietary memory card-like device to load and save codes, which is much more inconvenient.

For the GameShark Lite [game disc specific](#gamesharkhax-supported-game-discs) save game files have been created which **contains the GSHAX code already entered**. This negates the need to enter the _entire 94-line code manually into the GameShark Software_, and makes the GameSharkHAX method much more convenient to setup and use.

With the GameShark Lite game disc specific save game file, it's this easy to use the GameSharkHAX boot method:

*   Turn on your USA PSX or PS2 console with the GameShark Lite disc in the closed CD drive.
*   Wait for GameShark Lite to load through the `This product is NOT licensed or endorsed by SCEA` disclaimer, skip through the FMV, and then select the `Start GS lite` option in the GameShark Lite boot menu.
*   The GameShark Lite reads from the memory card in slot 1 of the console at boot, looking for any GameShark Lite CD save files. If it finds one it will display the message `Codes Loaded. Press O`.
*   After Pressing `O` you will be back at the GameShark Lite `Main Menu`. Use the `D-PAD` to navigate to the `Select Cheat Codes` option, and select it by pressing the `X` button.
*   Use the `D-PAD` to navigate to the game title that you are using GameSharkHAX with. Once the game title is highlighted, the codes for that game will be enabled. There are 2 codes for each GameSharkHAX game, so if you see in the bottom box the text `2 Cheat Codes Are On` then you can simply press the `O` button to return to the `Main Menu`. If you do not see that text in the bottom box, then there may be other codes that already exist for that game as well. In that case, you should use the `D-PAD` and `X` button to disable every code except the `GSHAX1` and `GSHAX2` ones, those are the only 2 codes that should be on. Once this is done, use the `O` button to return to the `Select Game` menu. Press the `O` button again to return back to the `Main Menu`.
*   Use the `D-PAD` to navigate to the `Start Game` option, and select it with the `X` button.
*   In the `Start Game Options` menu, the `Start Game With Selected Codes` option will already be highlighted. Press the `X` button to select it. You will see a text box which says `Open PlayStation CD lid. Remove GameShark CD. Insert Game CD. Close CD lid.` follow those instructions, inserting the GameSharkHAX compatible game disc.
*   Once the GameSharkHAX compatible game boots, follow the [disc-specific instructions](#gamesharkhax-supported-game-discs) to start the Tonyhax International loader from inside the game.


## PS2 Installation Method For GSHAX With The GameShark Lite

You can use a PS2 console to copy the save files to a PS1 memory card from a USB flash drive.

Requirements:

* A FAT32 formatted USB flash drive that your PS2 console can read. Please note that not all USB flash drives seem to work with PS2 consoles (due to iffy USB 1.1 support found in some newer USB flash drives). You may need to do a bit of trial and error testing to find a USB flash drive that works.

* A soft-modded (or modchipped) PS2 console that can run uLaunchELF (Models newer then the SCPH-39004 can therefore be used for copying the files to the PS1 memory card, but they can not be used to boot into Tonyhax International). You could do this with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248).

Installation With A PS2:

* Copy the `Tonyhax International Loader RAW File` file (`loader/HAX` in the release) and the `GameShark Lite Save RAW File` ([game disc specific](#gamesharkhax-supported-game-discs), found in the `gshax` directory to the FAT32 USB flash drive using a computer.

* Eject the USB flash drive from your computer and insert it into your PS2 console. Insert a PS1 memory card into your PS2 as well. 

* Start the uLaunchElf homebrew program on your PS2 console. Navigate to the `mass` device (this is your USB flash drive) with the `DPAD` on the controller, then select it with the `circle` button. 

* Using the `DPAD` to navigate, press the `cross` button on the controller to highlight both the `Tonyhax International Loader RAW` file and the `GameShark Lite CD Save RAW File` file that you previously copied to the USB flash drive. Press the `R1` button on the controller to make the file operations menu appear in uLaunchELF. Use the `DPAD` to move to the copy function and then press the `circle` button to select it.

* Press the `triangle` button to navigate out of the `mass` device. Use the `DPAD` and the circle button to navigate into either the `MC0` (if the PS1 memory card is in slot 1 of the PS2) or `MC1` (if the PS1 memory card is in slot 2 of the PS2) device. 

* Press the `R1` button to again make the file operations menu appear in uLaunchElF. Use the `DPAD` to navigate to the paste option and press the `circle` button to finally paste both the `Tonyhax International Loader RAW File` file and the `GameShark Lite CD Save RAW File` file. Now you can press the `triangle` button to navigate out of the PS1 memory card device, and remove the memory card from the PS2 console (if you want to use it in a different console).

* Power on your American PS1 console and boot the authentic GameShark Lite CD with the memory card containing the `Tonyhax International Loader RAW File` and the `GameShark Lite CD Save RAW File file` inserted into slot 1 of your console. After you start GameShark Lite, it will load and enable the codes pre-entered into the `GameShark Lite CD Save RAW File file` automatically.

* After the codes load from the memory card in slot 1, simply start the game with the codes on using the GameShark Lite. Insert the specific game disc that the GameSharkHAX code is for and play through the game as described in the [GameSharkHAX Game Discs list](#gamesharkhax-supported-game-discs) section.

## GSHAX With Other GameShark CDs Or Cheat Cartridges

For all other GameShark or cheat devices, you have to enter the _entire 94 line GameShark code_ manually at this time. You only need to do this once however, as you can save the code for future use. Each code can be found in `.txt` form in the `gshax` folder, the exact file name is specified in the [supported psx game discs list](#gamesharkhax-supported-game-discs). 

For GameSharks, each individual 'code entry' has a maximum of 64 lines. Since the code is 94 lines, you need to split the code into 2 'code entries'. Create a code called i.e. `GSHAX1`. Put the first 64 code lines found in the `.txt` file in this code and save it. Then create another code called i.e. `GSHAX2`. Put the remaining code lines found in the `.txt` file in this code entry and save it.

After creating both `GSHAX1` and `GSHAX2` code entries, enable both and start the target game with the codes on.

## PS2 Installation Method For GSHAX With Other GameShark CDs Or Cheat Cartridges

You can use a PS2 console to copy the save files to a PS1 memory card from a USB flash drive.

Requirements:

* A FAT32 formatted USB flash drive that your PS2 console can read. Please note that not all USB flash drives seem to work with PS2 consoles (due to iffy USB 1.1 support found in some newer USB flash drives). You may need to do a bit of trial and error testing to find a USB flash drive that works.

* A soft-modded (or modchipped) PS2 console that can run uLaunchELF (Models newer then the SCPH-39004 can therefore be used for copying the files to the PS1 memory card, but they can not be used to boot into Tonyhax International). You could do this with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248).

Installation With A PS2:

* Copy the `Tonyhax International Loader RAW File` file (`loader/HAX` in the release) to the FAT32 USB flash drive using a computer.

* Eject the USB flash drive from your computer and insert it into your PS2 console. Insert a PS1 memory card into your PS2 as well. 

* Start the uLaunchElf homebrew program on your PS2 console. Navigate to the `mass` device (this is your USB flash drive) with the `DPAD` on the controller, then select it with the `circle` button. 

* Using the `DPAD` to navigate, press the `cross` button on the controller to highlight the `Tonyhax International Loader RAW File` that you previously copied to the USB flash drive. Press the `R1` button on the controller to make the file operations menu appear in uLaunchELF. Use the `DPAD` to move to the copy function and then press the `circle` button to select it.

* Press the `triangle` button to navigate out of the `mass` device. Use the `DPAD` and the circle button to navigate into either the `MC0` (if the PS1 memory card is in slot 1 of the PS2) or `MC1` (if the PS1 memory card is in slot 2 of the PS2) device. 

* Press the `R1` button to again make the file operations menu appear in uLaunchElF. Use the `DPAD` to navigate to the paste option and press the `circle` button to finally paste the `Tonyhax International Loader RAW File` file. Now you can press the `triangle` button to navigate out of the PS1 memory card device, and remove the memory card from the PS2 console (if you want to use it in a different console).

* Power on your PS1 with the memory card containing the `Tonyhax International Loader RAW File` inserted into slot 1 of your console. Start the GameShark.

* Add the GameShark code for your [specific game disc](#gamesharkhax-supported-game-discs) to the GameShark. Official GameShark versions have a code line limit of 64. So you will need to create 2 seperate code entries: `GSHAX1` (containing the first 64 lines of the code) and `GSHAX2` (contains line 65 and above for the rest of the code).

* After adding every code line found in the `GameSharkHAX Code File` into the GameShark, ensure that the `GSHAX1` and `GSHAX2`codes are both enabled. Start the authentic PSX game disc of the game that the code is for using the `Start Game With Codes` option.

* Follow the [per-disc instructions](#gamesharkhax-supported-game-discs) to trigger the Tonyhax International loader from mid-gameplay.

## GameSharkHAX Supported Game Discs

_Note:_ Currently, I have only made one GameSharkHAX code, but more can easily be made and added in future versions of Tonyhax International.

### [WipEout (USA)](http://redump.org/disc/2772/)

* GameShark Code Game Title: `WIPEOUT`
* GameSharkHAX Code TXT File: `gshax/wipeout-usa/wipeout-usa-gshax-code.txt`
* GameShark Lite CD Save RAW File: `gshax/wipeout-usa/CODELIST00`
* Tonyhax International Loader RAW File: `loader/HAX`
* Tonyhax International Loader MCS File: `loader/tonyhax.mcs`
* Instructions: After starting Wipeout with the codes enabled, go through the intro FMV and anti-piracy screen to get to the start menu. Press the `start` button and wait a few seconds for the Tonyhax International loader to start.
