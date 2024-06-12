# [Tonyhax International](readme.md) -> GameShark Code Support

Tonyhax International now has the ability to apply user-supplied GameShark codes to any game before starting it. This uses my save game GameShark storage system as well as MottZilla's 'Cheat Engine', the latter of which has only previously been put to use by Tonyhax International's built-in [anti-piracy bypass system](anti-piracy-bypass.md).

## How It Works

1) Create a save game file using the [THIGSGEN program](#tonyhax-international-gameshark-generator-thigsgen) supplied in each Tonyhax International release, found in the `gameshark` directory.

2) [Copy the `TONYHAXINTGS0` file to a memory card](#copying-files-to-a-ps1-memory-card), this takes up 1 Block of space. If you want to put multiple save files on the same memory card, replace the '0' in the `TONYHAXINTGS0` filename of additional save files you want on the memory card with a higher number (1-14) and rename the additional file(s) before copying it to the same memory card (i.e. a memory card could contain all of these: `TONYHAXINTGS0`, `TONYHAXINTGS1`, `TONYHAXINTGS2`, `TONYHAXINTGS14`). A blank memory card can have 15 different save files on it at one time (`TONYHAXINTGS0` through `TONYHAXINTGS14`). 2 memory card slots means you can have 30 different saves over 2 cards.

3) Put the memory card in your console. Start Tonyhax International using any [entry point](readme.md#loader-entry-points-ways-to-start-the-tonyhax-international-loader).

4) When you see the text `Press CIRCLE to load GameShark codes from a memory card` in the Tonyhax International loader, press the circle button on your controller. You will then see the text `Memory card init...` and the controls for selecting the memory card slot your memory card is inserted into will be displayed.

5) Press triangle to abort loading any codes and to get back to the main loader. Press cross to specify the memory card is in slot 1. Press circle to specify slot 2. You will then see the text `Select save file name for memory card in slot 1` (if you picked slot 1) or `Select save file name for memory card in slot 2` (if you picked slot 2).

6) At the bottom of the screen, you will see the current save file name selection (by default it is `bu00:TONYHAXINTGS0` for slot 1 or `bu10:TONYHAXINTGS0` for slot 2). Press the triangle button to increase the file name's number (so each time you press triangle, the selection goes from i.e. for slot 1 you go from `bu00:TONYHAXINTGS0` to `bu00:TONYHAXINTGS1`, to `bu00:TONYHAXINTGS2`, etc. all the way up to `bu00:TONYHAXINTGS14`). To decrease the file name's number press the cross button (so each time you press cross, the selection goes from i.e. for slot 2 from `bu10:TONYHAXINTGS14` to `bu10:TONYHAXINTGS13`, to `bu10:TONYHAXINTGS12`, etc. all the way down to `bu10:TONYHAXINTGS0`).

7) When the selection is correct, press the circle button to confirm it and load the save file. You will then see `X code lines detected` (where `X` is the number of code lines that were found in the save file selected previously). Please note that this can be more then the amount of lines in the txt file used to generate the save file due to how GameShark codes work.

5) Boot your game as normal, and enjoy the GameShark codes.

## Tonyhax International GameShark Generator (THIGSGEN)

This is a command line program found in the `gameshark` directory of each Tonyhax International release. There are 6 different builds available:

*   `thigsgen-v2.0.3-windows-i686-static` _Portable Release For Windows 95 OSR 2.5 and above, Pentium CPU minimum (32 bit)_

*   `thigsgen-v2.0.3-windows-x86_64-static` _Portable Release For x86_64 Windows (64 bit)_

*   `thigsgen-v2.0.3-linux-i386-static` _Portable Release For Linux 3.2.0 and above, 386 CPU minimum (32 bit)_

*   `thigsgen-v2.0.3-linux-i386-static.deb` _Deb package file For Linux 3.2.0 and above, 386 CPU minimum (32 bit)_

*   `thigsgen-v2.0.3-linux-x86_64-static` _Portable Release For x86_64 Linux 3.2.0 and above (64 bit)_

*   `thigsgen-v2.0.3-linux-x86_64-static.deb` _Deb package file for x86_64 Linux 3.2.0 and above (64 bit)_

Find the correct binary to use for your computer in one of the files above. It will be named `thigsgen.exe` (Windows) or `thigsgen` (Linux).

On Windows, and most Linux distros, you can simply drag and drop the **the txt file (containing each code line on it's own line, without any gaps)** on top of the `thigsgen.exe` or `thigsgen` executable file. This will generate the `TONYHAXINTGS0` raw save file containing the codes in the current directory.

_Note:_ If you put a code line in your txt that has a code prefix that isn't supported, the `TONYHAXINTGS0` file will **not** be generated. You can only have code lines with the above supported code prefixes.

![THIGSGEN Parasite Eve Debug Room Gen](images/thigsgen-parasite-eve-debug-room-gen.png)

## Supported Codes & Limits

All codes beginning with the one of the following prefixes are supported:

* `30`
* `50`
* `80`
* `D0`
* `D1`
* `D2`
* `D3`
* `E0`
* `E1`
* `E2`
* `E3`

More code types will be supported in future releases.

The amount of codes that may be enabled all at one time simultaneously is hard capped at 255. Up to 139 codes have been verified to work all at once on real PSX hardware.

## Games That Can't Be Used With The GameShark Feature

1) You can not use the GameShark feature with the [english translation](http://redump.org/disc/37878/) of [Planet Laika](http://redump.org/disc/37878/) due to the translation using the same RAM this uses.

2) You can not use the GameShark feature with Spyro Year Of The Dragon releases without tripping the anti-tamper anti-piracy measure.

## Copying Files To A PS1 Memory Card

So now you should have a `TONYHAXINTGS0` file (or multiple files, correctly numbered at the end of the filename with 0 through 14)containing the GameShark codes you desire to use. The next step is to copy the file(s) to your PS1 memory card.

You can use a PS2 console to copy the save files to a PS1 memory card from a USB flash drive.

Requirements:

* A FAT32 formatted USB flash drive that your PS2 console can read. Please note that not all USB flash drives seem to work with PS2 consoles (due to iffy USB 1.1 support found in some newer USB flash drives). You may need to do a bit of trial and error testing to find a USB flash drive that works.

* A soft-modded (or modchipped) PS2 console that can run [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF). You could do this with [FreeHDBoot](https://www.ps2-home.com/forum/viewtopic.php?t=5208) or [FreeMCBoot](https://www.ps2-home.com/forum/viewtopic.php?t=1248).

### Installation With A PS2:

* Copy the `TONYHAXINTGS0` file to the FAT32 USB flash drive using a computer.

* Eject the USB flash drive from your computer and insert it into your PS2 console. Insert a PS1 memory card into your PS2 as well. 

* Start the [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF) homebrew program on your PS2 console. Navigate to the `mass` device (this is your USB flash drive) with the `DPAD` on the controller, then select it with the `circle` button. 

* Using the `DPAD` to navigate, press the `cross` button on the controller to highlight the `TONYHAXINTGS0` file (and any other correctly numbered `TONYHAXINTGS*` files) that you previously copied to the USB flash drive. Press the `R1` button on the controller to make the file operations menu appear in [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF). Use the `DPAD` to move to the copy function and then press the `circle` button to select it.

* Press the `triangle` button to navigate out of the `mass` device. Use the `DPAD` and the circle button to navigate into either the `MC0` (if the PS1 memory card is in slot 1 of the PS2) or `MC1` (if the PS1 memory card is in slot 2 of the PS2) device. 

* Press the `R1` button to again make the file operations menu appear in [WLaunchELF](https://github.com/ps2homebrew/wLaunchELF). Use the `DPAD` to navigate to the paste option and press the `circle` button to finally paste the `TONYHAXINTGS0` file. Now you can press the `triangle` button to navigate out of the PS1 memory card device, and remove the memory card from the PS2 console (if you want to use it in a different console).

## YouTube Videos On This Functionality

Here's some awesome vids by my friend [JMaxxl](https://github.com/JMaxxL):

* [MemoryCard works as gameshark new homebrew update flashed rom PS1](https://www.youtube.com/watch?v=msFBSE9-_n4)
* [New Homebrew Turns MemoryCard into Gameshark 2 Cards PS1](https://www.youtube.com/watch?v=rxkbzgrx2zk)
* [HOW TO gameshark card for Tonyhax International - part 1 slot1](https://www.youtube.com/watch?v=CaTJwnGzPCo)
* [HOW TO 'Tonyhax International' w/gameshark - part 2 slot 2](https://www.youtube.com/watch?v=TNlltRoVvjk)
