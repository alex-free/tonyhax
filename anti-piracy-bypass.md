# Anti-Piracy Bypass System

## Background Info

Starting in late 1998, some specific PSX games began implementing additional copy protection designed to prevent playing backup CD-R copies of a game. Different types of additional copy protection have been found in PSX games over the years.

## APv1

The very first kind of 'standardized' additional copy protection that appeared in later PSX games. The _APv1 style protection can only prevent a backup CD-R of a game from working on a console that has a 'non-stealth mod-chip' installed_. APv1 style protection **can not detect games booted with Tonyhax International** on a stock console without a _non-stealth_ mod-chip. This means that all games with this protection work already with Tonyhax International.

## APv2

Unlike APv1, APv2 does trigger when games are booted with Tonyhax International on a stock console **unless a game disc specific [APv2 Bypass](#apv2-bypasses) has been implemented for it in the Tonyhax International loader**. The good news is at this point almost all if not every single game with this protection now has a working bypass implemented.

The very early SCPH-3000 Japanese consoles, and all SCPH-1000 Japanese consoles are immune to tripping APv2 as long as they are stock and not containing a 'non-stealth' mod-chip. These consoles will work with every game without a bypass even being needed. In fact, Tonyhax International does not even apply the APv2 bypasses for these consoles when they are detected.

## What Happens When Additional Anti-Piracy Protection Is Triggered

![poporogue japan rev 0 apv1 triggered](images/poporogue-japan-non-stealth-mod-chip-apv1-triggered.png)

![dino crisis usa rev 0 apv2 triggered](images/dino-crisis-usa-rev-0-non-stealth-mod-chip-apv2-triggered.png)

![spyro year of the dragon usa rev 0 apv2 triggered](images/spyro-year-of-the-dragon-usa-rev-0-non-stealth-mod-chip-apv2-triggered.png)

When triggered, the APv1 and APv2 style copy protections will trigger an 'anti-piracy screen of death'. If you encounter an APv2 game that triggers this screen, then the specific game disc is not yet supported (this is a work in progress). In such a case please open an [Anti-Piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&template=antipiracy-issue.md&title=) on the [Tonyhax International Github](https://github.com/alex-free/tonyhax) to let me know about this specific game which contains APv2 protection. I would eventually like every game that can trigger the anti-piracy copy protection routine when booted via Tonyhax International on a stock console to have a  bypass implemented for 100% compatibility.

## EDC

In addition to [APv1](#apv1) or [APv2](#apv2) protection, [most Dance Dance Revolution PSX games](#edc-protected-psx-games) contain an EDC-based protection measure. For the affected games, this protection is triggered when you burn the EDC protected PSX CD image with standard CD burning software, which in most cases will changes the EDC data when burning an EDC protected PSX CD image.

### PSX EDC Anti-Piracy Protection

The idea of EDC/EEC based additional anti-piracy protection is a brilliantly flawed one. See, Sony's tools to generate disc images back in the day were [buggy](http://www.psxdev.net/forum/viewtopic.php?t=1475). One such bug appears to be that the [reserved sectors 12-15](http://problemkaputt.de/psx-spx.htm#cdromisovolumedescriptors), which are zero filled in the user data portion of the sector, _also_ **have an EDC checksum of zero**. The correct checksum for a zero-filled user data sector _should be_ `3F 13 B0 BE`, _but it isn't_. It's `00 00 00 00` like the rest of the sector besides the sync data. This actually doesn't matter in practice, so the bug went unoticed and the technically invalid sector 12-15s shipped on real licensed PSX CD-ROMs. This apparently got fixed eventually in some newer version of the `cdgen` Sony tool that created disc images.

Someone working on the Dance Dance Revolution PSX games noticed this strange behavior and figured out that it could be exploited as an additional anti-piracy protection measure. If the real licensed PSX CD-ROM discs were shipped with an EDC checksum of zero in sector 12-15, then when someone went to rip the real licensed PSX CD-ROM disc and then burn it back to a CD-R, the EDC checksum in sector 12-15 would no longer be `00 00 00 00`, it would be the expected `3F 13 B0 BE`. [Game code](https://github.com/socram8888/tonyhax/issues/121#issuecomment-1341381549) can read the EDC checksum on the disc at sector 12, and a routine could then lock up the game if the EDC data is non-zero to deter piracy.

### Burning EDC Protected PSX Games Correctly

I recommend using the latest CDRDAO v1.2.5 which unlike previous versions supports burning EDC Protected PSX games with CD audio tracks correctly using the `generic-mmc-raw` driver. There are pre-built portable releases of a new enough CDRDAO for Linux [available](https://alex-free.github.io/cdrdao).

**Run [edcre](https://alex-free.github.io/edcre) on the first data track bin file of the disc image before burning with the CDRDAO RAW driver** as described below.

`cdrdao write --speed 1 --driver generic-mmc-raw --swap -n --eject yourgame.cue`

![Burning Dance Dance Revolution 2nd Remix Japan](images/ddr2j-burning.png)

### CDRDAO Command Explanation

The `--speed 1` argument sets the writing speed to the slowest your CD burner supports.

The `--driver generic-mmc-raw` arguments specifies CDRDAO to use the `generic-mmc-raw` driver, which burns the CD image exactly as it is. The default driver used without specifiying these arguments is the **`generic-mmc` driver, which like the other drivers in CDRDAO will auto-regenerate EDC data as the CD image is burned.** This can change the EDC data read from the burned disc later, which some PSX games use as an additional anti-piracy check which if failed will lock up [the game](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#games-with-edc-protection).

The `--swap` argument is neccesary if the BIN/CUE CD image contains CD audio. Without it, you will get loud static when the CD audio tracks are played as they are by default byte-swapped by CDRDAO if this argument is not specified.

The `-n` argument disables the 10 second waiting period before burning.

The `--eject` argument will automatically eject the disc immediately after a successful burn.

### EDC Protected PSX Games

Every Dance Dance Revolution PSX game has EDC protection with the exception of the game [Dance Dance Revolution: Disney's Rave](http://redump.org/disc/37012/) / [Dance Dance Revolution: Disney Mix](http://redump.org/disc/13669/).

 Almost every Dance Dance Revolution PSX game containing EDC protection also have either [APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2) or [APv1](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv1) based anti-piracy detection code. [Tonyhax International](https://alex-free.github.io/tonyhax-international) has [APv2 Bypasses](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2-bypasses) implemented for all the known EDC protected games to ensure they run on stock consoles [when burned correctly](#burning-edc-protected-psx-games-correctly).

#### Dance Dance Revolution

- Versions Tested: [Japan](http://redump.org/disc/1562/), [USA](http://redump.org/disc/16075/).
- Versions With EDC Protection: Japan, USA.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first default option in the main  menu at start.
- Versions With Anti-Piracy Screen ([APv1](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv1)): Japan. **No bypass needed for unmodified consoles**.
- When Is The Anti-Piracy Screen Check: Immediately.

#### Dance Dance Revolution: Best Hits

- Versions Tested: [Japan](http://redump.org/disc/30601/).
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first default option in the main  menu at start.
- Versions With Anti-Piracy Screen ([APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2)): Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.


#### Dance Dance Revolution Konamix

- Versions Tested: [USA](http://redump.org/disc/1238/).
- When Is The EDC Protection: Immediately there is a `NOW LOADING` blinking text screen and the CD drive goes crazy.
- Versions With Anti-Piracy Screen: None

#### Dance Dance Revolution Extra Mix

- Versions Tested: [Japan](http://redump.org/disc/44438/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first option in the  start menu.
- Versions With Anti-Piracy Screen ([APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2)): Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

#### Dance Dance Revolution 2nd Remix

- Versions Tested: [Japan](http://redump.org/disc/9477/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: Immediately at first screen with text.
- Versions With Anti-Piracy Screen ([APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2)): Japan. _Note:_ this game also contains (disabled) [APv1](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv1) code.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

#### Dance Dance Revolution 3rd Mix

- Versions Tested: [Japan](http://redump.org/disc/9536/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first option in the  start menu.
- Versions With Anti-Piracy Screen ([APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2)): Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

#### Dance Dance Revolution 4th Mix

- Versions Tested: [Japan](http://redump.org/disc/34157/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu.
- Versions With Anti-Piracy Screen ([APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2)): Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

#### Dance Dance Revolution 5th Mix

- Versions Tested: [Japan](http://redump.org/disc/34157/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu.
- Versions With Anti-Piracy Screen ([APv2](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#apv2)): Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

## LibCrypt

Some PAL PSX games are using a different copy protection scheme known as LibCrypt protection. Similar to EDC protection, LibCrypt protection is triggered when you burn a LibCrypt protected PSX CD image with standard CD burning software, which in most cases changes the SubChannel data when burning such a protected PSX CD image.

LibCrypt protection can be bypassed by burning a backup CD-R of a LibCrypt game using [CloneCD](#clone-cd) in a very [specific](https://github.com/Kippykip/SBITools) way.

Real PAL LibCrypt discs booted via Tonyhax International on USA or Japanese consoles ('imports') will not trip the detection.

## CD Burning

### [CDRDAO-PLED](https://alex-free.github.io/cdrdao)

* Is Open Source?: Yes. Pre-built Linux x86_64 binaries are also [available](https://alex-free.github.io/cdrdao##downloads).
* Burns Standard PSX Backup CD-Rs?: Yes. For .bin/.cue CD images, the `--swap` argument is required.
* Burns PSX Backup CD-Rs With Additional EDC Protection Correctly?: Yes, After running [EDCRE](https://alex-free.github.io/edcre) use the `--swap` and  `--driver generic-mmc-raw` arguments.
* Burns PSX Backup CD-Rs With LibCrypt Protection Correctly?: CDRDAO can rip an authentic PAL PSX game disc containing LibCrypt protection correctly into a .toc/.bin CD image file. This file can be burned back by using the `generic-mmc-raw` driver. The much more common .bin/.cue/.sub CD image LibCrypt rips do not work directly however.

### [CloneCD](https://www.redfox.bz/en/clonecd.html)

* Is Open Source?: No, it is Windows only FreeWare with a free 'demo' version as well as a full paid version. The 'demo' version can be used however for PSX Backup CD-R burning without limitation.
* Burns Standard PSX Backup CD-Rs?: Yes, no special options required.
* Burns PSX Backup CD-Rs With Additional EDC Protection Correctly?: Yes, After running [EDCRE](https://alex-free.github.io/edcre) use [RAW](https://hydrogenaud.io/index.php?PHPSESSID=3voij6gqs993vdbd15mlmc2k7h&topic=42415.msg371328##msg371328) mode.
* Burns PSX Backup CD-Rs With LibCrypt Protection Correctly?: [Yes](https://github.com/Kippykip/SBITools), (with the proper BIN/CUE/SUB files).

### [ImgBurn](https://www.imgburn.com/)

* Is Open Source?: No, it is Windows only FreeWare.
* Burns Standard PSX Backup CD-Rs?: Yes.
* Burns PSX Backup CD-Rs With Additional EDC Protection Correctly?: No.
* Burns PSX Backup CD-Rs With LibCrypt Protection Correctly?: No.

## APv2 Bypasses

This is the complete list of games with bypasses anti-piracy measures that are supported by Tonyhax International. They will all boot and play correctly on stock consoles:

### Animetic Story Game 1: Card Captor Sakura

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/12000/), [Disc 2](http://redump.org/disc/11999/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Alundra 2

- Versions Tested: [Japan](http://redump.org/disc/15641/), [Japan Demo](http://redump.org/disc/6752/), [USA](http://redump.org/disc/2996/), [Europe](http://redump.org/disc/1089/), [German](http://redump.org/disc/11603/), [French](http://redump.org/disc/13396/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When first booting the game during the 'now loading' screen.
- Versions With Anti-Piracy Bypass Support: Japan.

### Arc The Lad III

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/5897/), [Disc 2](http://redump.org/disc/5898/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/34793/), [Disc 2](http://redump.org/disc/34794/)), USA ([Disc 1](http://redump.org/disc/674/), [Disc 2](http://redump.org/disc/675/)).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.

### Beatmania featuring Dreams Come True

- Versions Tested: [Japan](http://redump.org/disc/36188/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Beatmania Best Hits

- Versions Tested: [Japan Rev 0](http://redump.org/disc/36175/), [Japan Rev 1](http://redump.org/disc/44332/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.

### Beat Mania: The Sound of Tokyo

- Versions Tested: [Japan](http://redump.org/disc/36163/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Beat Mania 6thMix + Core Remix

- Versions Tested: [Japan](http://redump.org/disc/16285/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Boku no Natsuyasumi: Summer Holiday 20th Century

- Versions Tested: [Japan](http://redump.org/disc/4890/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Breath of Fire IV

- Versions Tested: [Japan](http://redump.org/disc/1554/), [E3 2000/Beta USA](http://redump.org/disc/59620/), [USA](http://redump.org/disc/1222/), [Europe](http://redump.org/disc/549/).
- Versions With Anti-Piracy Screen: Japan, E3 2000/Beta USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, E3 2000/Beta USA.

### Capcom vs. SNK: Millennium Fight 2000 Pro
- Versions Tested: [Japan](http://redump.org/disc/37359/
), [Japan Demo](http://redump.org/disc/62464/), [Europe](http://redump.org/disc/3904/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Chase The Express

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/5637/), [Disc 2](http://redump.org/disc/5638/)), [Japan Demo 1](http://redump.org/disc/6551/), [Japan Demo 2](http://redump.org/disc/19589/), Europe ([Disc 1](http://redump.org/disc/27257/), [Disc 2](http://redump.org/disc/27258/)), France ([Disc 1](http://redump.org/disc/28137/), [Disc 2](http://redump.org/disc/28138/)), Germany ([Disc 1](http://redump.org/disc/7507/), [Disc 2](http://redump.org/disc/7508/)), Italy ([Disc 1](http://redump.org/disc/28358/), [Disc 2](http://redump.org/disc/28359/)).
- Versions With Anti-Piracy Screen: Japan, Japan Demo 1, Japan Demo 2.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo 1, Japan Demo 2.

### Crash Bash

- Versions Tested: [Japan](http://redump.org/disc/3819/), [Japan Demo](http://redump.org/disc/53589/), [USA](http://redump.org/disc/512/), [USA Demo](http://redump.org/disc/49446/), [Europe](http://redump.org/disc/5483/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: 'Sony Computer Entertainment Presents' screen.
- Versions With Anti-Piracy Bypass Support: Japan, USA.

### Crash Bandicoot Racing

- Versions Tested: [Japan](http://redump.org/disc/3694/), [Japan Demo](http://redump.org/disc/53590/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: When first booting the game when the Naughty Dog box is first visible.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.

### Cool Boarders 2001

- Versions Tested: [USA](http://redump.org/disc/513/), [USA Demo](http://redump.org/disc/42467/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: During the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### Dance Dance Revolution: Best Hits

- Versions Tested: [Japan](http://redump.org/disc/30601/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan. **IMPORTANT: There is [EDC Protection](#edc) in addition to the standardized anti-piracy copy protection routine.**

### Dance Dance Revolution: Disney's Rave

- Versions Tested: [Japan](http://redump.org/disc/37012/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution Extra Mix

- Versions Tested: [Japan](http://redump.org/disc/44438/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution 2nd Remix

- Versions Tested: [Japan](http://redump.org/disc/9477/).
- Versions With [EDC Protection](#edc): Japan.
- When Is The EDC Protection: Immediately at first screen with text.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1

- Versions Tested: [Japan](http://redump.org/disc/23382/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When you use the 'disc change' feature found in Dance Dance Revolution 2nd Remix to boot the disc.
- Versions With Anti-Piracy Bypass Support: Japan. 
- This game works as intended/completely normal on USA and European consoles. On Japanese PS1 consoles, you must do a **perfect** [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles) in the 'disc change' feature found in Dance Dance Revolution 2nd Remix to get the game to boot AND for it to have working CD audio. You can not play this game currently on a Japanese PS2 due to the lack of a [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles) method for PS2s.

### Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2

- Versions Tested: [Japan](http://redump.org/disc/33339/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When you use the 'disc change' feature found in Dance Dance Revolution 2nd Remix to boot the disc.
- Versions With Anti-Piracy Bypass Support: Japan.
- This game works as intended/completely normal on USA and European consoles. On Japanese PS1 consoles, you must do a **perfect** [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles) in the 'disc change' feature found in Dance Dance Revolution 2nd Remix to get the game to boot AND for it to have working CD audio. You can not play this game currently on a Japanese PS2 due to the lack of a [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles) method for PS2s.

### Dance Dance Revolution 3rd Mix

- Versions Tested: [Japan](http://redump.org/disc/9536/).
- Versions With [EDC Protection](#edc): Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution 4th Mix

- Versions Tested: [Japan](http://redump.org/disc/34157/).
- Versions With [EDC Protection](#edc): Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dance Dance Revolution 5th Mix

- Versions Tested: [Japan](http://redump.org/disc/34157/).
- Versions With [EDC Protection](#edc): Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dancing Stage Featuring Dreams Come True

- Versions Tested: [Japan](http://redump.org/disc/17882/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first text screen after boot, until right before the first FMV.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dancing Stage Featuring True Kiss Destination

- Versions Tested: [Japan](http://redump.org/disc/15853/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first text screen after boot, until right before the first FMV.
- Versions With Anti-Piracy Bypass Support: Japan.

### Dino Crisis

- Versions Tested: [Japan](http://redump.org/disc/1598/), [USA Rev 0](http://redump.org/disc/459/), [USA Rev 1](http://redump.org/disc/473/), [USA Demo](http://redump.org/disc/2942/), [Europe](http://redump.org/disc/710/), [Italy](http://redump.org/disc/28171/), [Germany](http://redump.org/disc/7586/), [France](http://redump.org/disc/24278/), [Spain](http://redump.org/disc/27940/).
- Versions With Anti-Piracy Screen: Japan, USA Rev 0, USA Rev 1.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots.
- Versions With Anti-Piracy Bypass Support: Japan, USA Rev 0, USA Rev 1.

### Dino Crisis 2

- Versions Tested: [Japan](http://redump.org/disc/1600/), [Japan Demo](http://redump.org/disc/4407/), [USA](http://redump.org/disc/460/), [USA Demo](http://redump.org/disc/49242/), [Europe](http://redump.org/disc/1071/), [Italy](http://redump.org/disc/45993/), [Germany](http://redump.org/disc/10641/), [France](http://redump.org/disc/29514/), [Spain](http://redump.org/disc/27941/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.

### Disney's The Emperor's New Grove

- Versions With Anti-Piracy Screen: [USA](http://redump.org/disc/14583/), [Europe](http://redump.org/disc/7565/).
- When Is The Anti-Piracy Screen Check: Start a new game, after the first FMV on the first loading screen is when the check completes.
- Versions With Anti-Piracy Bypass Support: USA, Europe.

### Exciting Bass 2

- Versions Tested: [Japan](http://redump.org/disc/63487/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Exciting Bass 3

- Versions Tested: [Japan](http://redump.org/disc/59734/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner

- Versions: [Japan](http://redump.org/disc/20715/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

## Glint Glitters

- Versions Tested: [Japan](http://redump.org/disc/15969/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Goo! Goo! Soundry

- Versions Tested: [Japan](http://redump.org/disc/16027/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first 'now loading' screen at boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Grind Session

- Versions Tested: [USA](http://redump.org/disc/854/), [USA Demo](http://redump.org/disc/42794/), [Europe](http://redump.org/disc/3688/), [Scandinavia](http://redump.org/disc/53879/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: After going through the main menu and starting training/single player/a level.
- Versions With Anti-Piracy Bypass Support: USA.

### Guitar Freaks

- Versions Tested: [Japan](http://redump.org/disc/2277/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: At the loading screen with the spinning guitars.
- Versions With Anti-Piracy Bypass Support: Japan.

### Harlem Beat: You're The One

- Versions Tested: [Japan](http://redump.org/disc/36294/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: At the first loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Hyper Value 2800: Hanafuda

- Versions Tested: [Japan](http://redump.org/disc/15791/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Hyper Value 2800: Mahjong

- Versions Tested: [Japan](http://redump.org/disc/15793/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### i-mode mo Issho: Doko Demo Issho Tsuika Disc

- Versions Tested: [Japan](http://redump.org/disc/15793/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Jikkyou Powerful Pro Yakyuu '99: Ketteiban

- Versions Tested: [Japan](http://redump.org/disc/11091/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Jikkyou Powerful Pro Yakyuu '99: Kaimakuban

- Versions Tested: [Japan](http://redump.org/disc/1686/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### JoJo's Bizarre Adventure

- Versions Tested: [Japan](http://redump.org/disc/2871/), [USA](http://redump.org/disc/386/), [Europe](http://redump.org/disc/9983/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: First loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Koko Hore! Pukka

- Versions Tested: [Japan](http://redump.org/disc/4812/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Koneko mo Issho

- Versions Tested: [Japan](http://redump.org/disc/6329/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Legend Of Dragoon

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/22753/), [Disc 2](http://redump.org/disc/22754/), [Disc 3](http://redump.org/disc/22755/), [Disc 4](http://redump.org/disc/22756/)), USA ([Disc 1](http://redump.org/disc/153/), [Disc 2](http://redump.org/disc/154/), [Disc 3](http://redump.org/disc/155/), [Disc 4](http://redump.org/disc/156/)), Europe ([Disc 1](http://redump.org/disc/2379/), [Disc 2](http://redump.org/disc/2380/), [Disc 3](http://redump.org/disc/2381), [Disc 4](http://redump.org/disc/2382/)), France ([Disc 1](http://redump.org/disc/16750/), [Disc 2](http://redump.org/disc/16751/), [Disc 3](http://redump.org/disc/16752/), [Disc 4](http://redump.org/disc/16753/)), Germany ([Disc 1](http://redump.org/disc/15580/), [Disc 2](http://redump.org/disc/15581/), [Disc 3](http://redump.org/disc/15582/), [Disc 4](http://redump.org/disc/15583/)), Italy ([Disc 1](http://redump.org/disc/30643/), [Disc 2](http://redump.org/disc/30644/), [Disc 3](http://redump.org/disc/30645/), [Disc 4](http://redump.org/disc/30646/)).
- Versions With Anti-Piracy Screen: Japan, USA, Europe, France, Germany, Italy.
- When Is The Anti-Piracy Screen Check: First loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan, USA, Europe, France, Germany, Italy.

### Legend Of Mana

- Versions Tested: [Japan](http://redump.org/disc/1940/), [USA](http://redump.org/disc/96/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA.

### Love Hina: Ai wa Kotoba no Naka ni

- Versions Tested: [Japan](http://redump.org/disc/7369/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Love Hina 2: Kotoba wa Konayuki no You ni

- Versions Tested: [Japan](http://redump.org/disc/7370/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Marvel vs. Capcom: Clash of Super Heroes

- Versions Tested: [Japan](http://redump.org/disc/36384/), [Japan Demo](http://redump.org/disc/60646/), [USA](http://redump.org/disc/1235/), [Europe](http://redump.org/disc/3910/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately on boot.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.

### MediEvil II

- Versions Tested: [USA](http://redump.org/disc/2503/), [Europe Release 1](http://redump.org/disc/593/), [Europe Release 2](http://redump.org/disc/1547/), [Europe Demo](http://redump.org/disc/45822/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the Whitechapel level loading screen (quite far in the game).
- Versions With Anti-Piracy Bypass Support: USA.

### MLB 2002

- Versions Tested: [USA](http://redump.org/disc/826/), [USA Demo](http://redump.org/disc/43238/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### MLB 2003

- Versions Tested: [USA](http://redump.org/disc/16660/), [USA Demo](http://redump.org/disc/50864/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### MLB 2004

- Versions Tested: [USA](http://redump.org/disc/15325/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### My Garden

- Versions Tested: [Japan](http://redump.org/disc/8300/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### NBA Shootout 2001

- Versions Tested: [USA](http://redump.org/disc/16764/), [USA Demo](http://redump.org/disc/42465/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### NBA Shootout 2002

- Versions Tested: [USA](http://redump.org/disc/14527/), [USA Demo](http://redump.org/disc/44305/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### NBA Shootout 2003

- Versions Tested: [USA](http://redump.org/disc/14566/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NBA Shootout 2004

- Versions Tested: [USA](http://redump.org/disc/20551/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NCAA Final Four 2001

- Versions Tested: [USA](http://redump.org/disc/16765/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NCAA Game Breaker 2001

- Versions Tested: [USA](http://redump.org/disc/14374/), [USA Demo](http://redump.org/disc/43879/)
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: Second Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NFL GameDay 2001

- Versions Tested: [USA](http://redump.org/disc/21065/), [USA Demo](http://redump.org/disc/50868/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: First Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NFL GameDay 2002

- Versions Tested: [USA](http://redump.org/disc/2725/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Second Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NFL GameDay 2003

- Versions Tested: [USA](http://redump.org/disc/13364/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Third Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NFL GameDay 2004

- Versions Tested: [USA](http://redump.org/disc/14523/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Third Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NFL GameDay 2005

- Versions Tested: [USA](http://redump.org/disc/15995/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Third Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### NHL FaceOff 2001

- Versions Tested: [USA](http://redump.org/disc/12934/), [USA Demo](http://redump.org/disc/43880/)
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: When the main menu starts.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.

### Oha-Studio Dance Dance Revolution

- Versions Tested: [Japan](http://redump.org/disc/33938/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Ore no Ryouri

- Versions Tested: [Japan](http://redump.org/disc/39643/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pocket Jiman

- Versions Tested: [Japan](http://redump.org/disc/3189/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### PoPoLoCrois Monogatari II

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/1653/), [Disc 2](http://redump.org/disc/1654/), [Disc 3](http://redump.org/disc/1651/)), [Japan Demo](http://redump.org/disc/57327/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music: Animation Melody

- Versions Tested: [Japan](http://redump.org/disc/33223/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music: Disney Tunes

- Versions Tested: [Japan](http://redump.org/disc/34263/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music 2

- Versions Tested: [Japan](http://redump.org/disc/9774/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music 5

- Versions Tested: [Japan](http://redump.org/disc/9778/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Pop'n Music 6

- Versions Tested: [Japan](http://redump.org/disc/9777/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Resident Evil 3: The Last Escape

- Versions Tested: [Japan Rev 0](http://redump.org/disc/10/), [Japan Rev 1](http://redump.org/disc/8357/), [Japan Demo](http://redump.org/disc/11674/), [USA](http://redump.org/disc/126/), [USA Demo](http://redump.org/disc/7312/),[Europe](http://redump.org/disc/496/), [Europe Demo](http://redump.org/disc/9463/), [France](http://redump.org/disc/9753/), [Germany](http://redump.org/disc/5526/), [Italy](http://redump.org/disc/16397/), [Ireland](http://redump.org/disc/28197/), [Spain](http://redump.org/disc/1387/),
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots, pause there.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1, Japan Demo.

### Resident Evil: Survivor

- Versions Tested: [Japan](http://redump.org/disc/8102/), [USA](http://redump.org/disc/326/), [Europe](http://redump.org/disc/801/), [France](http://redump.org/disc/5826/).
- Versions With Anti-Piracy Screen: Japan, USA, Europe, France
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA, Europe, France.

### Robbit mon Dieu
- Versions Tested: [Japan](http://redump.org/disc/7227/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman

- Versions Tested: [Japan](http://redump.org/disc/6091/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 2: Dr. Wily no Nazo

- Versions Tested: [Japan](http://redump.org/disc/6092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 3: Dr. Wily no Saigo!?

- Versions Tested: [Japan](http://redump.org/disc/6092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 4: Aratanaru Yabou!!

- Versions Tested: [Japan](http://redump.org/disc/6094/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 5: Blues no Wana!?

- Versions Tested: [Japan](http://redump.org/disc/6095/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman X5

- Versions Tested: [Japan](http://redump.org/disc/4779/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman X6

- Versions Tested: [Japan](http://redump.org/disc/4778/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Rockman 6

- Versions Tested: [Japan](http://redump.org/disc/6096/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Spyro: Year Of The Dragon

- Versions Tested: [USA Rev 0](http://redump.org/disc/818/), [USA Rev 1](http://redump.org/disc/818/), [USA Demo](http://redump.org/disc/49449/), [Europe Rev 0](http://redump.org/disc/492/), [Europe Rev 1](http://redump.org/disc/19611/).
- Versions With Anti-Piracy Screen: USA Rev 0, USA Rev 1.
- When Is The Anti-Piracy Screen Check: Insomniac screen before start menu.
- Versions With Anti-Piracy Bypass Support: USA Rev 0, USA Rev 1.

**NOTE**: do not use the memory card GameShark feature to enable additional codes or the anti-tamper protection will trigger. There is also a ~15 second pause before the start menu appears, be patient and the game will unfreeze and work as intended! The protection is completely disabled by Tonyhax International so no issues will happen when playing.


### Street Fighter EX2 Plus

- Versions Tested: [Japan](http://redump.org/disc/12561/), [Japan Demo](http://redump.org/disc/68873/), [USA](http://redump.org/disc/1233/), [Europe](http://redump.org/disc/1006/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo, Europe, USA.

### Strider 2

- Versions Tested: [USA](http://redump.org/disc/1231/), [Europe](http://redump.org/disc/3917/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First now Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.

### Tokimeki Memorial 2

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/10670/), [Disc 2](http://redump.org/disc/10671/), [Disc 3](http://redump.org/disc/10672/), [Disc 4](http://redump.org/disc/10673/), [Disc 5](http://redump.org/disc/10674/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/24175/), [Disc 2](http://redump.org/disc/24177/), [Disc 3](http://redump.org/disc/24178/), [Disc 4](http://redump.org/disc/24179/), [Disc 5](http://redump.org/disc/24176/)), Japan Limited Box ([Disc 1](http://redump.org/disc/67613/), [Disc 2](http://redump.org/disc/67614/), [Disc 3](http://redump.org/disc/67615/), [Disc 4](http://redump.org/disc/67616/), [Disc 5](http://redump.org/disc/67617/)).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Limited Box.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0 ([Disc 1](http://redump.org/disc/10670/), [Disc 2](http://redump.org/disc/10671/), [Disc 3](http://redump.org/disc/10672/), [Disc 4](http://redump.org/disc/10673/), [Disc 5](http://redump.org/disc/10674/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/24175/), [Disc 2](http://redump.org/disc/24177/), [Disc 3](http://redump.org/disc/24178/), [Disc 4](http://redump.org/disc/24179/), [Disc 5](http://redump.org/disc/24176/)), Japan Limited Box ([Disc 1](http://redump.org/disc/67613/), [Disc 2](http://redump.org/disc/67614/), [Disc 3](http://redump.org/disc/67615/), [Disc 4](http://redump.org/disc/67616/), [Disc 5](http://redump.org/disc/67617/)).

### Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 1) (Minadzuki - Kotobuki - Sakura)

- Versions Tested: [Japan](http://redump.org/disc/53927/).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 2) (Akai - Ichimonji - Yae)

- Versions Tested: [Japan](http://redump.org/disc/53945/).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 3) (Shirayuki - Ijuin - Nozaki)

- Versions Tested: [Japan](http://redump.org/disc/53946/).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Tomba! 2: The Evil Swine Return

- Versions Tested: [USA](http://redump.org/disc/16475/), [USA Demo](http://redump.org/disc/32246/), [Europe](http://redump.org/disc/31192/), [France](http://redump.org/disc/31192/), [Germany](http://redump.org/disc/31192/), [Italy](http://redump.org/disc/41369/), [Spain](http://redump.org/disc/1582/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: USA.

### Tron ni Kobun

- Versions Tested: [Japan](http://redump.org/disc/10765/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Before first now loading screen.
- Versions With Anti-Piracy Bypass Support: Japan.

### Vandal Harts II

- Versions Tested: [Japan](http://redump.org/disc/4854/), [USA](http://redump.org/disc/4854/), [Europe](http://redump.org/disc/4854/), [Italy](http://redump.org/disc/4854/), [Spain](http://redump.org/disc/4854/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan (no patch required), USA.

### Wild Arms II

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/3924/), [Disc 2](http://redump.org/disc/3925/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/1902/), [Disc 2](http://redump.org/disc/1903/)), [Japan Demo](http://redump.org/disc/4799//), USA ([Disc 1](http://redump.org/disc/171/), [Disc 2](http://redump.org/disc/172/)), [USA Demo](http://redump.org/disc/42466/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo, USA, USA Demo.
- When Is The Anti-Piracy Screen Check: Right after the media vision logo screen fades to black.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0 (no patch required), Japan Rev 1 (no patch required), Japan Demo (no patch required), USA, USA Demo.

### World Soccer Jikkyou Winning Eleven 4

- Versions Tested: [Japan Rev 0](http://redump.org/disc/4934/), [Japan Rev 1](http://redump.org/disc/4934/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: As soon as the Japan Olympic Committee screen appears.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.

### XI[SAI] Jumbo

- Versions Tested: [Japan](http://redump.org/disc/8372/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.

### Yu-Gi-Oh! Forbidden Memories

- Versions Tested: [Japan](http://redump.org/disc/4173/), [Japan Genteiban Edition](http://redump.org/disc/51546/), [USA](http://redump.org/disc/820/), [Europe](http://redump.org/disc/1053/), [France](http://redump.org/disc/28263/), [Germany](http://redump.org/disc/1256/), [Spain](http://redump.org/disc/30673/), [Italy](http://redump.org/disc/35297/).
- Versions With Anti-Piracy Screen: Japan, Japan Genteiban Edition, USA, Europe, France, Germany, Spain, Italy.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Genteiban Edition, USA, Europe, France, Germany, Spain, Italy.
