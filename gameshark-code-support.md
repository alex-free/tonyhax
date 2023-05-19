# GameShark Code Support

Tonyhax International now has the ability to apply user-supplied GameShark codes to any game before starting it. This uses my save game GameShark storage system as well as MottZilla's 'Cheat Engine', the latter of which has only previously been put to use by the [APv2 bypass system](anti-piracy-bypass.md).

## How It Works

1) Create a save game file using the new THIGSGEN program supplied in each Tonyhax International release, found in the `gameshark` directory.

2) Copy the `TONYHAXINTGS` file to a memory card, this takes up 1 Block of space.

3) Put the memory card in Slot 1 of your PSX console. Start Tonyhax International using any boot method.

4) When you see the text `Press O to enable GS codes` in the Tonyhax International loader, press the circle button on your controller. You will then see the text `Reading MC...`, followed by `X code lines detected` (where `X` is the number of code lines that were found in the save file. Please note that this can be more then the amount of lines in the txt file used to generate the save file due to how GameShark codes work.
5) Boot your game as normal, and enjoy the GameShark codes.

## YouTube Videos On This Functionality

Here's some awesome vids by my friend [JMaxxl](https://github.com/JMaxxL):

* [MemoryCard works as gameshark new homebrew update flashed rom PS1](https://www.youtube.com/watch?v=msFBSE9-_n4)
* [New Homebrew Turns MemoryCard into Gameshark 2 Cards PS1](https://www.youtube.com/watch?v=rxkbzgrx2zk)
* [HOW TO gameshark card for Tonyhax International - part 1 slot1](https://www.youtube.com/watch?v=CaTJwnGzPCo)
* [HOW TO 'Tonyhax International' w/gameshark - part 2 slot 2](https://www.youtube.com/watch?v=TNlltRoVvjk)

## Supported Codes & Limits

All codes beginning with the one of the following prefixes are supported:

* `30`
* `50`
* `80`
* `D0`
* `D1`
* `E0`
* `E1`

More code types will be supported in future releases.

The amount of codes that may be enabled all at one time simultaneously is hard capped at 255. Up to 139 codes have been verified to work all at once on real PSX hardware.

## Usage

### Tonyhax International GameShark Generator (THIGSGEN)

This is a command line program found in the `gameshark` directory of each Tonyhax International release. There are 4 different binaries available:

*   `windows_x86` - For Windows 95 OSR 2.5 and newer.
*   `windows_x86_64` - For 64bit Windows.
*   `linux_x86_static` - For 32bit Linux distros.
*   `linux_x86_64_static` - For 64bit Linux distros.

So find the correct binary to use for your computer in one of the folders above. It will be named `thigsgen.exe` (Windows) or `thigsgen` (Linux). 

On Windows, and most Linux distros, you can simply drag and drop the **the txt file (containing each code line on it's own line, without any gaps)** on top of the `thigsgen.exe` or `thigsgen` executable file. This will generate the `TONYHAXINTGS` raw save file containing the codes.

_Note:_ If you put a code line in your txt that has a code prefix that isn't supported, the `TONYHAXINTGS` file will not be generated. You can only have code lines with the above supported code prefixes.

## Copying The TONYHAXINGS File To A PSX Memory Card

So now you should have a TONYHAXINTGS file containing the GameShark codes you desire to use. The next step is to copy this file to your PSX memory card.

You can use a PS2 console to copy the save files to a PS1 memory card from a USB flash drive.

Requirements:

* A FAT32 formatted USB flash drive that your PS2 console can read. Please note that not all USB flash drives seem to work with PS2 consoles (due to iffy USB 1.1 support found in some newer USB flash drives). You may need to do a bit of trial and error testing to find a USB flash drive that works.

* A soft-modded (or modchipped) PS2 console that can run [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF) (Models newer then the SCPH-39004 can therefore be used for copying the files to the PS1 memory card, but they can not be used to boot into Tonyhax International). You could do this with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248).

Installation With A PS2:

* Copy the `TONYHAXINTGS` file to the FAT32 USB flash drive using a computer.

* Eject the USB flash drive from your computer and insert it into your PS2 console. Insert a PS1 memory card into your PS2 as well. 

* Start the [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF) homebrew program on your PS2 console. Navigate to the `mass` device (this is your USB flash drive) with the `DPAD` on the controller, then select it with the `circle` button. 

* Using the `DPAD` to navigate, press the `cross` button on the controller to highlight the `TONYHAXINTGS` file that you previously copied to the USB flash drive. Press the `R1` button on the controller to make the file operations menu appear in [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF). Use the `DPAD` to move to the copy function and then press the `circle` button to select it.

* Press the `triangle` button to navigate out of the `mass` device. Use the `DPAD` and the circle button to navigate into either the `MC0` (if the PS1 memory card is in slot 1 of the PS2) or `MC1` (if the PS1 memory card is in slot 2 of the PS2) device. 

* Press the `R1` button to again make the file operations menu appear in [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF). Use the `DPAD` to navigate to the paste option and press the `circle` button to finally paste the `TONYHAXINTGS` file. Now you can press the `triangle` button to navigate out of the PS1 memory card device, and remove the memory card from the PS2 console (if you want to use it in a different console).

## Using GameShark Codes In The Tonyhax International loader

Start the Tonyhax International loader using any boot method. When you see the text `Press O to enable GS codes` do so on your controller. Then boot the game that the codes are for as usual. Enjoy!