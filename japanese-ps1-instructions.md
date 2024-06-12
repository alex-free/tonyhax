# [Tonyhax International](readme.md) -> Japanese PS1 Console Loader Instructions

## Requirements:

* Any real Japanese (NTSC-J region) PS1 CD-ROM game disc.
* A swap magic tool.
* Being OK with modifying the DVD-ROM faceplate of the console.
* Anything else required by the entry point.

## Supported Entry Points

*   [TOCPerfect Patching](https://alex-free.github.io/tocperfect)
*   [GameShark Code](gameshark-code.md)
*   [ROM/ROM Flasher CD](flashed-cheat-cart.md)
*   [FreePSXBoot Memory Card Images](freepsxboot-exploit.md)
*   [Boot CD](boot-cd.md)
*   [Save Game Exploit](save-game-exploit.md)

If you see the text `Put in a real NTSC-J PSX game disc, then block the lid sensor`:

1) Open the CD drive of your PS1 console.
2) Put in a real NTSC-J Japanese PS1 game disc in the CD drive, but don't close the CD drive lid.
3) Block the lid sensor. 

The lid sensor is highlighted by the red circle and arrow in the pictures below. On the original grey fat PS1 consoles (SCPH-900X and earlier) it is located in the top right corner, it is is shaped like a circle. Ideally you press it down with a bent pen spring as shown. On the slim PSone consoles (SCPH-10X) it is in the lower right corner to the side of the edge of the CD drive. For these consoles it is best to use a piece of tape or paper to slide in and press it down as shown.

![ps1 lid sensor](images/ps1-lid-sensor.jpg)

![ps1 lid sensor blocked front](images/ps1-lid-sensor-blocked-front.jpg)

![ps1 lid sensor blocked side](images/ps1-lid-sensor-blocked-side.jpg)

![psone lid sensor](images/psone-lid-sensor.jpg)

![psone lid sensor blocked](images/psone-lid-sensor-blocked.jpg)

After blocking the lid sensor, your real Japanese PS1 game will spin up and then stop. Once you see the text `Put in a backup/import disc, then press X` remove either the real NTSC-J PSX game disc or Boot CD from your PS1 console's CD drive. 

![scph 1000 rom 1](images/scph-1000-rom-loader-1.png)

![scph 1000 rom 2](images/scph-1000-rom-loader-2.png)

Put in the backup CD-R or import PSX game disc you want to play **without unblocking the lid sensor**. Once you press X, the console will run some commands automatically, followed by the game booting with perfect CD audio playback. Note that you can not unblock the lid sensor while playing the game on **Japanese consoles**, if you do so the game will stop working.

![scph 1000 booting backup](images/scph-1000-loader-rom-booting-duke-nukem-total-meltdown-usa.png)

## Playing Games With Multiple Discs

Unlike USA/PAL consoles, Japanese consoles do not have the ability to play multi-disc games normally due to the lid sensor block. However, most multi-disc games allow you to save before prompting for disc change in-game. This allows you to reset the console, restart Tonyhax International, boot the next disc, and then load the save made from the previous disc. Some games don't allow this however, such as Parasite Eve, Chrono Chross, and Fear Effect. Let me know in a [Github Issue](https://github.com/alex-free/tonyhax/issues/new) if you have found other games like this. 

If you really must play a multi-disc game on your Japanese console without powering it off and starting up the next disc with the loader, **you can perform a mid-game hot-swap-trick but I highly don't recommend doing this since you risk damaging the console and your discs.** A proper software-based seamless workaround is planned for the Japanese consoles but not yet implemented. Anyways, here's how you do it:

1) When the game asks you to insert disc 2, unblock the lid sensor and remove the CD.
2) Put **any real authentic Japanese PSX disc** into the PS1 drive.
3) Place the target disc you want to play in one hand, and whatever your using to block the lid sensor in another. 
4) Block the lid sensor, freeing a hand in the proccess.
5) Wait until the original real Japanese PSX disc stats spinning fast (~3 seconds) and **immediately** swap the disc with your free hand, and put in the target disc. 