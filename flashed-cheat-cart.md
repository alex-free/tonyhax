# Flashed Cheat Cart

You can overwrite the contents of a GameShark, Action Reply, or other PS1 cheat cartridge with the Tonyhax International ROM using a simple flasher CD-R that you burn or a combination of a home-made serial to USB cable, PC, and special program booted on your target PS1 console that supports flashing cheat cartridges over serial.

When you turn on any PS1 console with the flashed GameShark/Action Reply/cheat device installed to it's parallel port at the back the console, the system will instead boot into the Tonyhax International loader, rather then the BIOS/Shell (Sony screens/Memory Card/CD Player menu). A PS1 cheat cartridge flashed with the Tonyhax International ROM is essentially a plug and play mod-chip without any hardware modifications whatsoever.

## Requirements

*   GameShark, Action Reply, or other cheat cart that you are willing to overwrite with the Tonyhax International ROM.
*   A PS1 console with a parallel port for installing the GameShark or other cheat cart (SCPH-1000-SCPH-7502).
*   A Blank high quality CD-R (if burning a ROM flasher CD) or a serial cable, PC, and software which supports flashing a PS1 cheat cartridge over serial.

## How To Flash Your GameShark/Action Reply/Cheat Cart

Inside each Tonyhax International release in the `rom` directory are the following files:

*   tonyhax-rom-flasher.bin
*   tonyhax-rom-flasher.cue
*   tonyhax-*-international.roms

The BIN+CUE files can be burned to a CD-R. The BIN+CUE files contain the [NXFlash](https://github.com/danhans42/nxflash) PS1 executable with the `tonyhax-*-international.rom` file. This means when you boot the burned flasher CD-R on your PS1 console, you can connect your GameShark/cheat device and press the `R2` button (`RE-DETECT EEPROM`) to allow NXFLASH to detect the newly connected cheat cart. Next press the `start` button (`FLASH EEPROM FROM CD`), and then press X to flash your GameShark/Cheat device. Now you can simply reset or power off then power on your PS1 console and it will boot Tonyhax International from the GameShark/cheat cart immediately.

![rom flasher cd 1](images/rom-flasher-cd-1.jpg)

![rom flasher cd 2](images/rom-flasher-cd-2.jpg)

If you have an old enough PlayStation console you can simply use the [CD Player Swap Trick](boot-cd.html#cd-player-swap-trick) method to start the NXFlasher CD containing the Tonyahx International ROM. Otherwise, you can use [GameSharkHAX](gameshark-code.md), [Save Game Exploit](save-game-exploit.md), or even the [FreePSXBoot](freepsxboot-exploit.md) methods to start the disc.