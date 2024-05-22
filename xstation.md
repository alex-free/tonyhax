# [Tonyhax International](readme.md) -> XStation Flashed Cheat Cart

You can overwrite the contents of a GameShark, Action Reply, or other PS1 cheat cartridge with _a special version of the Tonyhax International loader_ to significantly speed up the boot time of consoles hard-modded with the xStation device. This feature was [asked for](https://github.com/alex-free/tonyhax/issues/29) by [L10N37](https://github.com/L10N37) after he pointed out that using the Tonyhax International loader via flashed cheat cart is significantly faster then the stock Sony BIOS when it comes to booting the xStation firmware.

The instructions for installing the xStation version of the Tonyhax International rom are identical to the normal [flashed cheat cart](flashed-cheat-cart.md) instructions, except you want to use these files in the `xstation` directory found in the Tonyhax International releases:

*   tonyhax-x-rom-flasher.bin
*   tonyhax-x-rom-flasher.cue
*   tonyhax-x-*-international.rom

If you use the `Fast Boot` option in the xStation firmware, your game will immediately start.

If you use the `Full Boot` option in the xStation firmware, Tonyhax International itself will load the game. You will need to open/close the drive lid after using the full boot method (which allows you to enter the Sony BIOS or enable [GameShark codes](gameshark-code-support.md) when the lid is open).
