# Anti-Piracy Bypass System

## Background Info

Starting in late 1998, some specific PSX games began implementing additional copy protection designed to prevent playing backup CD-R copies of a game. Different types of additional copy protection have been found in PSX games over the years. Tonyhax International supports such games on a game by game basis, with a goal of finding and adding the ability to play all such games eventually.

## [Full Supported Protected Games List](#protected-games-support)

## Types Of Protection

*   [APv1](#apv1) - only effects non-stealth mod-chip consoles.
*   [APv2](#apv2) - effects both non-stealth mod-chip consoles and stock, unmodified consoles.
*   [EDC](#edc).
*   [LibCrypt](#libcrypt).

## APv1

The very first kind of 'standardized' additional copy protection that appeared in later PSX games. This is only found in some Japanese games. The _APv1 style protection can only prevent a backup CD-R of a game from working on a console that has a 'non-stealth mod-chip' installed_. APv1 style protection can not detect games booted with Tonyhax International on a stock console without a _non-stealth_ mod-chip. 

Quite a few of the many APv1 games have support at this time. Newer updates to International will add support for more APv1 games.

## APv2

Unlike APv1, APv2 detects both soft-mods and non-stealth mod-chips. It is found in some Japanese games, some USA games, and a few PAL games. 

At this point almost all if not every single game with this protection now has a working bypass implemented.

The very early SCPH-3000 Japanese consoles, and all SCPH-1000 Japanese consoles are immune to tripping APv2 as long as they are not containing a 'non-stealth' mod-chip. These consoles will work with every game without a bypass even being needed.

## What Happens When Additional Anti-Piracy Protection Is Triggered

![poporogue japan rev 0 apv1 triggered](images/poporogue-japan-non-stealth-mod-chip-apv1-triggered.png)

![dino crisis usa rev 0 apv2 triggered](images/dino-crisis-usa-rev-0-non-stealth-mod-chip-apv2-triggered.png)

![spyro year of the dragon usa rev 0 apv2 triggered](images/spyro-year-of-the-dragon-usa-rev-0-non-stealth-mod-chip-apv2-triggered.png)

When triggered, the APv1 and APv2 style copy protections will trigger an 'anti-piracy screen of death'. If you encounter an APv2 game that triggers this screen, then the specific game disc is not yet supported (this is a work in progress). In such a case please open an [Anti-Piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&template=antipiracy-issue.md&title=) on the [Tonyhax International Github](https://github.com/alex-free/tonyhax) to let me know about this specific game which contains APv2 protection. I would eventually like every game that can trigger the anti-piracy copy protection routine when booted via Tonyhax International on a stock console to have a  bypass implemented for 100% compatibility.

## EDC

Some games may contain an EDC-based protection measure. For the affected games, this protection is triggered when you burn the EDC protected PSX CD image with standard CD burning software that by default usually corrects invalid EDC data it detects before writing said data to the disc, which when played on a real PSX will cause the game to trip the protection and lock up.

I recommend using the latest CDRDAO v1.2.5 which unlike previous versions supports burning EDC Protected PSX games with CD audio tracks correctly using the `generic-mmc-raw` driver (though you can also use [Clone CD](#cd-burning-software-for-protected-games)). There are pre-built portable releases of a new enough CDRDAO for Linux [available](https://alex-free.github.io/cdrdao). This is the syntax of the command needed to burn EDC protected games correctly with CDRDAO:

`cdrdao write --speed 1 --driver generic-mmc-raw --swap -n --eject yourgame.cue`

![Burning Dance Dance Revolution 2nd Remix Japan](images/ddr2j-burning.png)

An explanation of the cdrdao arguments is below:

The `--speed 1` argument sets the writing speed to the slowest your CD burner supports.

The `--driver generic-mmc-raw` arguments specifies CDRDAO to use the `generic-mmc-raw` driver, which burns the CD image exactly as it is. The default driver used without specifiying these arguments is the **`generic-mmc` driver, which like the other drivers in CDRDAO will auto-regenerate EDC data as the CD image is burned.** This can change the EDC data read from the burned disc later, which some PSX games use as an additional anti-piracy check which if failed will lock up [the game](https://alex-free.github.io/tonyhax-international/anti-piracy-bypass.html#games-with-edc-protection).

The `--swap` argument is neccesary if the BIN/CUE CD image contains CD audio. Without it, you will get loud static when the CD audio tracks are played as they are by default byte-swapped by CDRDAO if this argument is not specified.

The `-n` argument disables the 10 second waiting period before burning.

The `--eject` argument will automatically eject the disc immediately after a successful burn.

## LibCrypt

Some PAL PSX games are using a different copy protection scheme known as LibCrypt protection. Similar to EDC protection, LibCrypt protection is triggered when you burn a LibCrypt protected PSX CD image with standard CD burning software, which in most cases changes the SubChannel data when burning such a protected PSX CD image.

LibCrypt protection can be bypassed by burning a backup CD-R of a LibCrypt game using [CloneCD](#clone-cd) in a very [specific](https://github.com/Kippykip/SBITools) way, however non-stealth mod-chip consoles will still trigger the protection for some games. This will only work for stock, unmodified consoles currently.

## CD Burning Software For Protected Games

### [CDRDAO](https://alex-free.github.io/cdrdao)

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

## Protected Games Support

This is the complete list of all protected games with bypasses for the additional anti-piracy measures that are supported by Tonyhax International. They will all boot and play correctly on both stock, unmodified consoles and consoles with any kind of mod-chip installed (including non-stealth mod-chipped consoles).

### Animetic Story Game 1: Card Captor Sakura

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/12000/), [Disc 2](http://redump.org/disc/11999/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Alundra 2

- Versions Tested: [Japan](http://redump.org/disc/15641/), [Japan Demo](http://redump.org/disc/6752/), [USA](http://redump.org/disc/2996/), [Europe](http://redump.org/disc/1089/), [German](http://redump.org/disc/11603/), [French](http://redump.org/disc/13396/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When first booting the game during the 'now loading' screen.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Arc The Lad III

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/5897/), [Disc 2](http://redump.org/disc/5898/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/34793/), [Disc 2](http://redump.org/disc/34794/)), USA ([Disc 1](http://redump.org/disc/674/), [Disc 2](http://redump.org/disc/675/)).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.
- Anti-Piracy Version: APv2.

### Beat Mania Append GottaMix

- Versions Tested: [Japan](http://redump.org/disc/3550/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Beatmania featuring Dreams Come True

- Versions Tested: [Japan](http://redump.org/disc/36188/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Beatmania Best Hits

- Versions Tested: [Japan Rev 0](http://redump.org/disc/36175/), [Japan Rev 1](http://redump.org/disc/44332/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.
- Anti-Piracy Version: APv2.

### Beat Mania: The Sound of Tokyo

- Versions Tested: [Japan](http://redump.org/disc/36163/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Beat Mania 6thMix + Core Remix

- Versions Tested: [Japan](http://redump.org/disc/16285/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Bishi Bashi Special 2

- Versions Tested: [Japan](http://redump.org/disc/14212/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Boku no Natsuyasumi: Summer Holiday 20th Century

- Versions Tested: [Japan](http://redump.org/disc/4890/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Breath of Fire IV

- Versions Tested: [Japan](http://redump.org/disc/1554/), [E3 2000/Beta USA](http://redump.org/disc/59620/), [USA](http://redump.org/disc/1222/), [Europe](http://redump.org/disc/549/).
- Versions With Anti-Piracy Screen: Japan, E3 2000/Beta USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, E3 2000/Beta USA.
- Anti-Piracy Version: APv2.

### Bust A Move 2: Dance Tengoku Mix

- Versions Tested: [Japan](http://redump.org/disc/3723/), [Japan Demo](http://redump.org/disc/6753/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Capcom vs. SNK: Millennium Fight 2000 Pro

- Versions Tested: [Japan](http://redump.org/disc/37359/
), [Japan Demo](http://redump.org/disc/62464/), [Europe](http://redump.org/disc/3904/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Chase The Express

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/5637/), [Disc 2](http://redump.org/disc/5638/)), [Japan Demo 1](http://redump.org/disc/6551/), [Japan Demo 2](http://redump.org/disc/19589/), Europe ([Disc 1](http://redump.org/disc/27257/), [Disc 2](http://redump.org/disc/27258/)), France ([Disc 1](http://redump.org/disc/28137/), [Disc 2](http://redump.org/disc/28138/)), Germany ([Disc 1](http://redump.org/disc/7507/), [Disc 2](http://redump.org/disc/7508/)), Italy ([Disc 1](http://redump.org/disc/28358/), [Disc 2](http://redump.org/disc/28359/)).
- Versions With Anti-Piracy Screen: Japan, Japan Demo 1, Japan Demo 2.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo 1, Japan Demo 2.
- Anti-Piracy Version: APv2.

### Chocobo Racing: Genkai e no Road

- Versions Tested: [Japan](http://redump.org/disc/4042/), [USA](http://redump.org/disc/14966/), [Europe](http://redump.org/disc/14966/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Crash Bash

- Versions Tested: [Japan](http://redump.org/disc/3819/), [Japan Demo](http://redump.org/disc/53589/), [USA](http://redump.org/disc/512/), [USA Demo](http://redump.org/disc/49446/), [Europe](http://redump.org/disc/5483/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: 'Sony Computer Entertainment Presents' screen.
- Versions With Anti-Piracy Bypass Support: Japan, USA.
- Anti-Piracy Version: APv2.

### Crash Bandicoot Racing

- Versions Tested: [Japan](http://redump.org/disc/3694/), [Japan Demo](http://redump.org/disc/53590/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: When first booting the game when the Naughty Dog box is first visible.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.
- Anti-Piracy Version: APv2.

### Cool Boarders 2001

- Versions Tested: [USA](http://redump.org/disc/513/), [USA Demo](http://redump.org/disc/42467/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: During the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.
- Anti-Piracy Version: APv2.

### Dancing Blade Katte ni Momotenshi II: Tears of Eden (Disc 1)
- Versions Tested: Japan ([Disc 1](http://redump.org/disc/14229/), [Disc 2](http://redump.org/disc/14230/), [Disc 3](http://redump.org/disc/14228/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: During the Konami logo screen.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Dance Dance Revolution

- Versions Tested: [Japan](http://redump.org/disc/1562/), [USA](http://redump.org/disc/16075/).
- Versions With EDC Protection: Japan, USA.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first default option in the main  menu at start.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Dance Dance Revolution: Best Hits

- Versions Tested: [Japan](http://redump.org/disc/30601/).
- Versions With EDC Protection: Japan.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dance Dance Revolution: Disney's Rave

- Versions Tested: [Japan](http://redump.org/disc/37012/).
- Versions With EDC Protection: Japan.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

#### Dance Dance Revolution Konamix

- Versions Tested: [USA](http://redump.org/disc/1238/).
- When Is The EDC Protection: Immediately there is a `NOW LOADING` blinking text screen and the CD drive goes crazy.
- Versions With Anti-Piracy Screen: None

### Dance Dance Revolution Extra Mix

- Versions Tested: [Japan](http://redump.org/disc/44438/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dance Dance Revolution 2nd Remix

- Versions Tested: [Japan](http://redump.org/disc/9477/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: Immediately at first screen with text.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1

- Versions Tested: [Japan](http://redump.org/disc/23382/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When you use the 'disc change' feature found in Dance Dance Revolution 2nd Remix to boot the disc.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.
- This game works as intended/completely normal on USA and European consoles. On Japanese PS1 consoles, you must do a **perfect** [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles) in the 'disc change' feature found in Dance Dance Revolution 2nd Remix to get the game to boot AND for it to have working CD audio. You can not play this game currently on a Japanese PS2 due to the lack of a [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles) method for PS2s.

### Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2

- Versions Tested: [Japan](http://redump.org/disc/33339/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: When you use the 'disc change' feature found in Dance Dance Revolution 2nd Remix to boot the disc.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.
- This game works as intended/completely normal on USA and European consoles. On Japanese PS1 consoles, you must do a **perfect** [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps1-consoles) in the 'disc change' feature found in Dance Dance Revolution 2nd Remix to get the game to boot AND for it to have working CD audio. You can not play this game currently on a Japanese PS2 due to the lack of a [mid-game hot-swap trick](#playing-games-that-span-multiple-discs-on-japanese-ps2-consoles) method for PS2s.

### Dance Dance Revolution 3rd Mix

- Versions Tested: [Japan](http://redump.org/disc/9536/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the first option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dance Dance Revolution 4th Mix

- Versions Tested: [Japan](http://redump.org/disc/34157/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dance Dance Revolution 5th Mix

- Versions Tested: [Japan](http://redump.org/disc/34157/).
- Versions With EDC Protection: Japan.
- When Is The EDC Protection: First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu.
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dancing Stage Featuring Dreams Come True

- Versions Tested: [Japan](http://redump.org/disc/17882/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first text screen after boot, until right before the first FMV.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dancing Stage Featuring True Kiss Destination

- Versions Tested: [Japan](http://redump.org/disc/15853/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first text screen after boot, until right before the first FMV.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Dino Crisis

- Versions Tested: [Japan](http://redump.org/disc/1598/), [USA Rev 0](http://redump.org/disc/459/), [USA Rev 1](http://redump.org/disc/473/), [USA Demo](http://redump.org/disc/2942/), [Europe](http://redump.org/disc/710/), [Italy](http://redump.org/disc/28171/), [Germany](http://redump.org/disc/7586/), [France](http://redump.org/disc/24278/), [Spain](http://redump.org/disc/27940/).
- Versions With Anti-Piracy Screen: Japan, USA Rev 0, USA Rev 1.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots.
- Versions With Anti-Piracy Bypass Support: Japan, USA Rev 0, USA Rev 1.
- Anti-Piracy Version: APv2.

### Dino Crisis 2

- Versions Tested: [Japan](http://redump.org/disc/1600/), [Japan Demo](http://redump.org/disc/4407/), [USA](http://redump.org/disc/460/), [USA Demo](http://redump.org/disc/49242/), [Europe](http://redump.org/disc/1071/), [Italy](http://redump.org/disc/45993/), [Germany](http://redump.org/disc/10641/), [France](http://redump.org/disc/29514/), [Spain](http://redump.org/disc/27941/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.
- Anti-Piracy Version: APv2.

### Disney's The Emperor's New Grove

- Versions tested: [USA](http://redump.org/disc/14583/), [Europe](http://redump.org/disc/7565/).
- Versions With Anti-Piracy Screen: [USA](http://redump.org/disc/14583/), [Europe](http://redump.org/disc/7565/).
- When Is The Anti-Piracy Screen Check: Start a new game, after the first FMV on the first loading screen is when the check completes.
- Versions With Anti-Piracy Bypass Support: USA, Europe.
- Anti-Piracy Version: APv2.

### Doko Demo Issho

- Versions tested: [Japan Rev 0](http://redump.org/disc/1335/), [Japan Rev 1](http://redump.org/disc/20288/), [Japan Water Calpis Version](http://redump.org/disc/49161/), [Japan Demo 1](http://redump.org/disc/6755/).
- Versions With Anti-Piracy Screen: [Japan Rev 0](http://redump.org/disc/1335/), [Japan Rev 1](http://redump.org/disc/20288/), [Japan Water Calpis Version](http://redump.org/disc/49161/), [Japan Demo 1](http://redump.org/disc/6755/), [Japan Demo 2](http://redump.org/disc/83081/).
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1, Japan Water Calpis Version, Japan Demo 1. **NOTE: I can not find Japan Demo 2, someone please send me it so I can add support.**
- Anti-Piracy Version: APv1.

### Exciting Bass 2

- Versions Tested: [Japan](http://redump.org/disc/63487/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Exciting Bass 3

- Versions Tested: [Japan](http://redump.org/disc/59734/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Final Fantasy VIII

- Versions Tested: Japan([Disc 1](http://redump.org/disc/1422/), [Disc 2](http://redump.org/disc/1423/), [Disc 3](http://redump.org/disc/1424/), [Disc 4](http://redump.org/disc/1425/)), USA ([Disc 1](http://redump.org/disc/69/), [Disc 2](http://redump.org/disc/70/), [Disc 3](http://redump.org/disc/71/), [Disc 4](http://redump.org/disc/72/)), Europe ([Disc 1](http://redump.org/disc/866/), [Disc 2](http://redump.org/disc/875/), [Disc 3](http://redump.org/disc/873/), [Disc 4](http://redump.org/disc/874/)), [Europe Demo 1](http://redump.org/disc/2627/), [Europe Demo 2](http://redump.org/disc/53142/), Italy ([Disc 1](http://redump.org/disc/4028/), [Disc 2](http://redump.org/disc/4029/), [Disc 3](http://redump.org/disc/4030/), [Disc 4](http://redump.org/disc/4031/)), [Italy Demo](http://redump.org/disc/4717/), Germany ([Disc 1](http://redump.org/disc/733/), [Disc 2](http://redump.org/disc/734/), [Disc 3](http://redump.org/disc/735/), [Disc 4](http://redump.org/disc/736/)), Italy ([Disc 1](http://redump.org/disc/1587/), [Disc 2](http://redump.org/disc/1588/), [Disc 3](http://redump.org/disc/1589/), [Disc 4](http://redump.org/disc/1590/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner

- Versions: [Japan](http://redump.org/disc/20715/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

## Glint Glitters

- Versions Tested: [Japan](http://redump.org/disc/15969/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

## Global Force: Shin Sentou Kokka

- Versions: [Japan](http://redump.org/disc/20715/), [Japan Rev 1](http://redump.org/disc/4819/), [Japan Demo](http://redump.org/disc/4819/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1, Japan Demo.
- Anti-Piracy Version: APv1.

### Goo! Goo! Soundry

- Versions Tested: [Japan](http://redump.org/disc/16027/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: On the first 'now loading' screen at boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Grind Session

- Versions Tested: [USA](http://redump.org/disc/854/), [USA Demo](http://redump.org/disc/42794/), [Europe](http://redump.org/disc/3688/), [Scandinavia](http://redump.org/disc/53879/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: After going through the main menu and starting training/single player/a level.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### Guitar Freaks

- Versions Tested: [Japan](http://redump.org/disc/2277/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: At the loading screen with the spinning guitars.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Gungauge

- Versions Tested: [Japan](http://redump.org/disc/6328/), [Europe](http://redump.org/disc/7315/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Harlem Beat: You're The One

- Versions Tested: [Japan](http://redump.org/disc/36294/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: At the first loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Hyper Value 2800: Hanafuda

- Versions Tested: [Japan](http://redump.org/disc/15791/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Hyper Value 2800: Hyper Pachinko

- Versions Tested: [Japan](http://redump.org/disc/15792/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Hyper Value 2800: Mahjong

- Versions Tested: [Japan](http://redump.org/disc/15793/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### i-mode mo Issho: Doko Demo Issho Tsuika Disc

- Versions Tested: [Japan](http://redump.org/disc/15793/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### I.Q Final

- Versions Tested: [Japan](http://redump.org/disc/1504/), [Japan Demo 1](http://redump.org/disc/6649/), [Japan Demo 2](http://redump.org/disc/32988/).
- Versions With Anti-Piracy Screen: Japan Demo 1, Japan Demo 2.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan Demo 1, Japan Demo 2.
- Anti-Piracy Version: APv1.


### Jikkyou Kyousouba Ikusei Simulation Game: Breeding Stud '99

- Versions Tested: [Japan](http://redump.org/disc/8762/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Jikkyou Powerful Pro Yakyuu: Premium-ban

- Versions Tested: [Japan](http://redump.org/disc/11090/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu '99: Ketteiban

- Versions Tested: [Japan](http://redump.org/disc/11091/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu '99: Kaimakuban

- Versions Tested: [Japan](http://redump.org/disc/1686/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu 2000: Ketteiban

- Versions Tested: [Japan](http://redump.org/disc/11092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu 2000: Kaimakuban

- Versions Tested: [Japan](http://redump.org/disc/9553/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu 2001

- Versions Tested: [Japan](http://redump.org/disc/9554/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu 2001: Ketteiban

- Versions Tested: [Japan](http://redump.org/disc/17257/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Jikkyou Powerful Pro Yakyuu 2002: Haru

- Versions Tested: [Japan](http://redump.org/disc/9551/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### JoJo's Bizarre Adventure

- Versions Tested: [Japan](http://redump.org/disc/2871/), [USA](http://redump.org/disc/386/), [Europe](http://redump.org/disc/9983/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: First loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Shiritsu Justice Gakuen: Nekketsu Seishun Nikki 2

- Versions Tested: [Japan](http://redump.org/disc/33493/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: After title screen on first loading screen.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Koko Hore! Pukka

- Versions Tested: [Japan](http://redump.org/disc/4812/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Koneko mo Issho

- Versions Tested: [Japan](http://redump.org/disc/6329/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Konami 80's Arcade Gallery

- Versions Tested: [Japan](http://redump.org/disc/16955/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Legend Of Dragoon

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/22753/), [Disc 2](http://redump.org/disc/22754/), [Disc 3](http://redump.org/disc/22755/), [Disc 4](http://redump.org/disc/22756/)), USA ([Disc 1](http://redump.org/disc/153/), [Disc 2](http://redump.org/disc/154/), [Disc 3](http://redump.org/disc/155/), [Disc 4](http://redump.org/disc/156/)), Europe ([Disc 1](http://redump.org/disc/2379/), [Disc 2](http://redump.org/disc/2380/), [Disc 3](http://redump.org/disc/2381), [Disc 4](http://redump.org/disc/2382/)), France ([Disc 1](http://redump.org/disc/16750/), [Disc 2](http://redump.org/disc/16751/), [Disc 3](http://redump.org/disc/16752/), [Disc 4](http://redump.org/disc/16753/)), Germany ([Disc 1](http://redump.org/disc/15580/), [Disc 2](http://redump.org/disc/15581/), [Disc 3](http://redump.org/disc/15582/), [Disc 4](http://redump.org/disc/15583/)), Italy ([Disc 1](http://redump.org/disc/30643/), [Disc 2](http://redump.org/disc/30644/), [Disc 3](http://redump.org/disc/30645/), [Disc 4](http://redump.org/disc/30646/)).
- Versions With Anti-Piracy Screen: Japan, USA, Europe, France, Germany, Italy.
- When Is The Anti-Piracy Screen Check: First loading screen after boot.
- Versions With Anti-Piracy Bypass Support: Japan, USA, Europe, France, Germany, Italy.
- Anti-Piracy Version: APv2.

### Legend Of Mana

- Versions Tested: [Japan](http://redump.org/disc/1940/), [USA](http://redump.org/disc/96/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA.
- Anti-Piracy Version: APv2.

### Lord Of Monsters

- Versions Tested: [Japan](http://redump.org/disc/58023/), [Japan Demo](http://redump.org/disc/68358/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.
- Anti-Piracy Version: APv1.

### Love Hina: Ai wa Kotoba no Naka ni

- Versions Tested: [Japan](http://redump.org/disc/7369/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Love Hina 2: Kotoba wa Konayuki no You ni

- Versions Tested: [Japan](http://redump.org/disc/7370/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Magical Tetris Challenge featuring Mickey

- Versions Tested: [Japan](http://redump.org/disc/19170/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Marvel vs. Capcom: Clash of Super Heroes

- Versions Tested: [Japan](http://redump.org/disc/36384/), [Japan Demo](http://redump.org/disc/60646/), [USA](http://redump.org/disc/1235/), [Europe](http://redump.org/disc/3910/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately on boot.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo.
- Anti-Piracy Version: APv2.

### MediEvil II

- Versions Tested: [USA](http://redump.org/disc/2503/), [Europe Release 1](http://redump.org/disc/593/), [Europe Release 2](http://redump.org/disc/1547/), [Europe Demo](http://redump.org/disc/45822/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the Whitechapel level loading screen (quite far in the game).
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### Metal Gear Solid: Integral

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/423/), [Disc 2](http://redump.org/disc/424/), [Disc 3](http://redump.org/disc/426/)).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Minna no Golf 2 / Everybody's Golf 2

- Versions Tested: [Japan Rev 0](http://redump.org/disc/2290/), [Japan Rev 1](http://redump.org/disc/2291/), [Europe](http://redump.org/disc/2291/).
- Versions With Anti-Piracy Screen: Japan Rev 0/Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.
- Anti-Piracy Version: APv2.

### MLB 2002

- Versions Tested: [USA](http://redump.org/disc/826/), [USA Demo](http://redump.org/disc/43238/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.
- Anti-Piracy Version: APv2.

### MLB 2003

- Versions Tested: [USA](http://redump.org/disc/16660/), [USA Demo](http://redump.org/disc/50864/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.
- Anti-Piracy Version: APv2.

### MLB 2004

- Versions Tested: [USA](http://redump.org/disc/15325/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### MLB 2005

- Versions Tested: [USA](http://redump.org/disc/7212/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### My Garden

- Versions Tested: [Japan](http://redump.org/disc/8300/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### NBA Shootout 2001

- Versions Tested: [USA](http://redump.org/disc/16764/), [USA Demo](http://redump.org/disc/42465/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.
- Anti-Piracy Version: APv2.

### NBA Shootout 2002

- Versions Tested: [USA](http://redump.org/disc/14527/), [USA Demo](http://redump.org/disc/44305/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.
- Anti-Piracy Version: APv2.

### NBA Shootout 2003

- Versions Tested: [USA](http://redump.org/disc/14566/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NBA Shootout 2004

- Versions Tested: [USA](http://redump.org/disc/20551/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: At the end of the first loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NCAA Final Four 2001

- Versions Tested: [USA](http://redump.org/disc/16765/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NCAA Game Breaker 2001

- Versions Tested: [USA](http://redump.org/disc/14374/), [USA Demo](http://redump.org/disc/43879/)
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: Second Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NFL GameDay 2001

- Versions Tested: [USA](http://redump.org/disc/21065/), [USA Demo](http://redump.org/disc/50868/).
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: First Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NFL GameDay 2002

- Versions Tested: [USA](http://redump.org/disc/2725/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Second Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NFL GameDay 2003

- Versions Tested: [USA](http://redump.org/disc/13364/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Third Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NFL GameDay 2004

- Versions Tested: [USA](http://redump.org/disc/14523/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Third Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NFL GameDay 2005

- Versions Tested: [USA](http://redump.org/disc/15995/)
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Third Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### NHL FaceOff 2001

- Versions Tested: [USA](http://redump.org/disc/12934/), [USA Demo](http://redump.org/disc/43880/)
- Versions With Anti-Piracy Screen: USA, USA Demo.
- When Is The Anti-Piracy Screen Check: When the main menu starts.
- Versions With Anti-Piracy Bypass Support: USA, USA Demo.
- Anti-Piracy Version: APv2.

### Oha-Studio Dance Dance Revolution

- Versions Tested: [Japan](http://redump.org/disc/33938/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Ore no Ryouri / My Cooking

- Versions Tested: [Japan](http://redump.org/disc/39643/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Ore no Shikabane o Koete Yuke

- Versions Tested: [Japan](http://redump.org/disc/3983/), [Japan Demo](http://redump.org/disc/82897/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Start a new game and proceed through the beginning intro text, it is quite a bit to go through to see it trigger. Once you finish making your character it will trigger, google translate is your friend here.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Panekit: Infinitive Crafting Toy Case

- Versions Tested: [Japan Rev 0](http://redump.org/disc/5364/), [Japan Rev 1](http://redump.org/disc/5364/) - **NOTE: Japan Rev 1 should work but I can not find a copy of it to confirm.**
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.
- Anti-Piracy Version: APv1.

### Planet Laika

- Versions Tested: [Japan](http://redump.org/disc/37878/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.
- Note: The fan english translation already has this bypassed and International explicitly does not set it's own bypass for this game to prevent it from locking up.

### Pocket Jiman

- Versions Tested: [Japan](http://redump.org/disc/3189/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Pocket MuuMuu

- Versions Tested: [Japan](http://redump.org/disc/16166/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### PoPoLoCrois Monogatari II

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/1653/), [Disc 2](http://redump.org/disc/1654/), [Disc 3](http://redump.org/disc/1651/)), [Japan Demo](http://redump.org/disc/57327/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### PoPoRoGue

- Versions Tested: [Japan Rev 0](http://redump.org/disc/1552/), [Japan Rev 1](http://redump.org/disc/8313/), [Japan Demo](http://redump.org/disc/1552/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: Sony Computer Entertainment presents screen.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.
- Anti-Piracy Version: APv1.

### Pop'n Music: Animation Melody

- Versions Tested: [Japan](http://redump.org/disc/33223/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Pop'n Music: Disney Tunes

- Versions Tested: [Japan](http://redump.org/disc/34263/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Pop'n Music 2

- Versions Tested: [Japan](http://redump.org/disc/9774/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Pop'n Music 5

- Versions Tested: [Japan](http://redump.org/disc/9778/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Pop'n Music 6

- Versions Tested: [Japan](http://redump.org/disc/9777/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Resident Evil 3: The Last Escape

- Versions Tested: [Japan Rev 0](http://redump.org/disc/10/), [Japan Rev 1](http://redump.org/disc/8357/), [Japan Demo](http://redump.org/disc/11674/), [USA](http://redump.org/disc/126/), [USA Demo](http://redump.org/disc/7312/),[Europe](http://redump.org/disc/496/), [Europe Demo](http://redump.org/disc/9463/), [France](http://redump.org/disc/9753/), [Germany](http://redump.org/disc/5526/), [Italy](http://redump.org/disc/16397/), [Ireland](http://redump.org/disc/28197/), [Spain](http://redump.org/disc/1387/),
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo, USA Demo.
- When Is The Anti-Piracy Screen Check: On the disclaimer screen after the game boots, pause there.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1, Japan Demo.
- Anti-Piracy Version: APv2.

### Resident Evil: Survivor

- Versions Tested: [Japan](http://redump.org/disc/8102/), [USA](http://redump.org/disc/326/), [Europe](http://redump.org/disc/801/), [France](http://redump.org/disc/5826/).
- Versions With Anti-Piracy Screen: Japan, USA, Europe, France
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA, Europe, France.
- Anti-Piracy Version: APv2.

### Robbit mon Dieu
- Versions Tested: [Japan](http://redump.org/disc/7227/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately after boot.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman

- Versions Tested: [Japan](http://redump.org/disc/6091/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman 2: Dr. Wily no Nazo

- Versions Tested: [Japan](http://redump.org/disc/6092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman 3: Dr. Wily no Saigo!?

- Versions Tested: [Japan](http://redump.org/disc/6092/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman 4: Aratanaru Yabou!!

- Versions Tested: [Japan](http://redump.org/disc/6094/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman 5: Blues no Wana!?

- Versions Tested: [Japan](http://redump.org/disc/6095/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman X5

- Versions Tested: [Japan](http://redump.org/disc/4779/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman X6

- Versions Tested: [Japan](http://redump.org/disc/4778/)
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Rockman 6

- Versions Tested: [Japan](http://redump.org/disc/6096/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### SaGa Frontier II

- Versions Tested: [Japan](http://redump.org/disc/1605/), [USA](http://redump.org/disc/1535/), [Europe](http://redump.org/disc/280/), [France](http://redump.org/disc/28278/), [Germany](http://redump.org/disc/2605/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Saru! Get You!/Ape Escape

- Versions Tested: [Japan Rev 0](http://redump.org/disc/17061/), [Japan Rev 1](http://redump.org/disc/17062/), [Japan Demo](http://redump.org/disc/5668/), [USA](http://redump.org/disc/3086/), [USA Demo 1](http://redump.org/disc/12309/), [USA Demo Toys R Us](http://redump.org/disc/50386/), [USA Demo 2](http://redump.org/disc/12309/), [Europe](http://redump.org/disc/6147/), [Europe Demo](http://redump.org/disc/995/), [France](http://redump.org/disc/28260/), [Germany](http://redump.org/disc/26604/), [Italy](http://redump.org/disc/27680/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0 (APv1), Japan Rev 1 (APv1), Japan Demo (APv1).
- Anti-Piracy Version: APv1.

### Silent Hill

- Versions Tested: [Japan Rev 0](http://redump.org/disc/134/), [Japan Rev 1](http://redump.org/disc/82898/),  [Japan Demo](http://redump.org/disc/33473/), [Japan Rev 2](http://redump.org/disc/18251/) **Note: Need to find Japan Rev 2 to confirm it works as well**.
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Rev 2.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1, Japan Rev 2.
- Anti-Piracy Version: APv1.

### Spyro The Dragon

- Versions Tested: [Japan](http://redump.org/disc/42739/), [Shokai Genteiban](http://redump.org/disc/11432/),  [Japan Demo](http://redump.org/disc/68768/).
- Versions With Anti-Piracy Screen: Japan, Shokai Genteiban.
- When Is The Anti-Piracy Screen Check: Immediately after the universal logo.
- Versions With Anti-Piracy Bypass Support: Japan, Shokai Genteiban.
- Anti-Piracy Version: APv1.

### Spyro: Year Of The Dragon

- Versions Tested: [USA Rev 0](http://redump.org/disc/818/), [USA Rev 1](http://redump.org/disc/818/), [USA Demo](http://redump.org/disc/49449/), [Europe Rev 0](http://redump.org/disc/492/), [Europe Rev 1](http://redump.org/disc/19611/).
- Versions With Anti-Piracy Screen: USA Rev 0, USA Rev 1.
- When Is The Anti-Piracy Screen Check: Insomniac screen before start menu.
- Versions With Anti-Piracy Bypass Support: USA Rev 0, USA Rev 1.
- Anti-Piracy Version: APv2.

**NOTE**: do not use the memory card GameShark feature to enable additional codes or the anti-tamper protection will trigger. There is also a ~15 second pause before the start menu appears, be patient and the game will unfreeze and work as intended! The protection is completely disabled by Tonyhax International so no issues will happen when playing.

### Street Fighter EX2 Plus

- Versions Tested: [Japan](http://redump.org/disc/12561/), [Japan Demo](http://redump.org/disc/68873/), [USA](http://redump.org/disc/1233/), [Europe](http://redump.org/disc/1006/).
- Versions With Anti-Piracy Screen: Japan, Japan Demo.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Demo, Europe, USA.
- Anti-Piracy Version: APv2.

### Strider 2

- Versions Tested: [USA](http://redump.org/disc/1231/), [Europe](http://redump.org/disc/3917/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: First now Loading screen.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### Tokimeki Memorial 2

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/10670/), [Disc 2](http://redump.org/disc/10671/), [Disc 3](http://redump.org/disc/10672/), [Disc 4](http://redump.org/disc/10673/), [Disc 5](http://redump.org/disc/10674/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/24175/), [Disc 2](http://redump.org/disc/24177/), [Disc 3](http://redump.org/disc/24178/), [Disc 4](http://redump.org/disc/24179/), [Disc 5](http://redump.org/disc/24176/)), Japan Limited Box ([Disc 1](http://redump.org/disc/67613/), [Disc 2](http://redump.org/disc/67614/), [Disc 3](http://redump.org/disc/67615/), [Disc 4](http://redump.org/disc/67616/), [Disc 5](http://redump.org/disc/67617/)).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Limited Box.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0 ([Disc 1](http://redump.org/disc/10670/), [Disc 2](http://redump.org/disc/10671/), [Disc 3](http://redump.org/disc/10672/), [Disc 4](http://redump.org/disc/10673/), [Disc 5](http://redump.org/disc/10674/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/24175/), [Disc 2](http://redump.org/disc/24177/), [Disc 3](http://redump.org/disc/24178/), [Disc 4](http://redump.org/disc/24179/), [Disc 5](http://redump.org/disc/24176/)), Japan Limited Box ([Disc 1](http://redump.org/disc/67613/), [Disc 2](http://redump.org/disc/67614/), [Disc 3](http://redump.org/disc/67615/), [Disc 4](http://redump.org/disc/67616/), [Disc 5](http://redump.org/disc/67617/)).
- Anti-Piracy Version: APv2.

### Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 1) (Minadzuki - Kotobuki - Sakura)

- Versions Tested: [Japan](http://redump.org/disc/53927/).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 2) (Akai - Ichimonji - Yae)

- Versions Tested: [Japan](http://redump.org/disc/53945/).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 3) (Shirayuki - Ijuin - Nozaki)

- Versions Tested: [Japan](http://redump.org/disc/53946/).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Tokimeki Memorial Drama Series Vol. 3: Tabidachi no Uta

- Versions Tested: Japan ([Disc 1](http://redump.org/disc/29081/), [Disc 2](http://redump.org/disc/29081/)).
- Versions With Anti-Piracy Screen: Japan
- When Is The Anti-Piracy Screen Check: Press start on title screen and go through it, happens right before you name the character.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Tomba! 2: The Evil Swine Return

- Versions Tested: [USA](http://redump.org/disc/16475/), [USA Demo](http://redump.org/disc/32246/), [Europe](http://redump.org/disc/31192/), [France](http://redump.org/disc/31192/), [Germany](http://redump.org/disc/31192/), [Italy](http://redump.org/disc/41369/), [Spain](http://redump.org/disc/1582/).
- Versions With Anti-Piracy Screen: USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: USA.
- Anti-Piracy Version: APv2.

### Tron ni Kobun

- Versions Tested: [Japan](http://redump.org/disc/10765/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Before first now loading screen.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Um Jammer Lammy

- Versions Tested: [Japan](http://redump.org/disc/3582/), [Japan Tentou Houei-you](http://redump.org/disc/97015/), [USA](http://redump.org/disc/1399/), [USA Demo](http://redump.org/disc/10990/), [Europe](http://redump.org/disc/5510/)). **NOTE: I can not find Japan Tentou Houei-you, someone please send me it so I can add support.**
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Before first now loading screen.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv1.

### Vandal Harts II

- Versions Tested: [Japan](http://redump.org/disc/4854/), [USA](http://redump.org/disc/4854/), [Europe](http://redump.org/disc/4854/), [Italy](http://redump.org/disc/4854/), [Spain](http://redump.org/disc/4854/).
- Versions With Anti-Piracy Screen: Japan, USA.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, USA.
- Anti-Piracy Version: Japan release is APv1. USA release is APv2. Onlyu known game to have APv1 or Japan and then APv2 for USA.

### Wild Arms II

- Versions Tested: Japan Rev 0 ([Disc 1](http://redump.org/disc/3924/), [Disc 2](http://redump.org/disc/3925/)), Japan Rev 1 ([Disc 1](http://redump.org/disc/1902/), [Disc 2](http://redump.org/disc/1903/)), [Japan Demo](http://redump.org/disc/4799//), USA ([Disc 1](http://redump.org/disc/171/), [Disc 2](http://redump.org/disc/172/)), [USA Demo](http://redump.org/disc/42466/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1, Japan Demo, USA, USA Demo.
- When Is The Anti-Piracy Screen Check: Right after the media vision logo screen fades to black.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0 (no patch required), Japan Rev 1 (no patch required), Japan Demo (no patch required), USA, USA Demo.
- Anti-Piracy Version: APv2.

### World Soccer Jikkyou Winning Eleven 4

- Versions Tested: [Japan Rev 0](http://redump.org/disc/4934/), [Japan Rev 1](http://redump.org/disc/4934/).
- Versions With Anti-Piracy Screen: Japan Rev 0, Japan Rev 1.
- When Is The Anti-Piracy Screen Check: As soon as the Japan Olympic Committee screen appears.
- Versions With Anti-Piracy Bypass Support: Japan Rev 0, Japan Rev 1.
- Anti-Piracy Version: APv2.

### XI[SAI] Jumbo

- Versions Tested: [Japan](http://redump.org/disc/8372/).
- Versions With Anti-Piracy Screen: Japan.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan.
- Anti-Piracy Version: APv2.

### Yu-Gi-Oh! Forbidden Memories

- Versions Tested: [Japan](http://redump.org/disc/4173/), [Japan Genteiban Edition](http://redump.org/disc/51546/), [USA](http://redump.org/disc/820/), [Europe](http://redump.org/disc/1053/), [France](http://redump.org/disc/28263/), [Germany](http://redump.org/disc/1256/), [Spain](http://redump.org/disc/30673/), [Italy](http://redump.org/disc/35297/).
- Versions With Anti-Piracy Screen: Japan, Japan Genteiban Edition, USA, Europe, France, Germany, Spain, Italy.
- When Is The Anti-Piracy Screen Check: Immediately.
- Versions With Anti-Piracy Bypass Support: Japan, Japan Genteiban Edition, USA, Europe, France, Germany, Spain, Italy.
- Anti-Piracy Version: APv2.

## NEEDED GAMES

I can not find the below specific versions/releases of these protected games. Tonyhax International aims to support every release, every revision of every game with anti-piracy protection, so if you can provide these in any manner it would help immensly.

*   [Panekit: Infinitive Crafting Toy Case Japan Rev 1](http://redump.org/disc/75024/). This is the 'PS2 compatible' re-release.
*   [Doko Demo Issho Japan Demo 2](http://redump.org/disc/83081/).
*   [Silent Hill Japan Rev 2](http://redump.org/disc/18251/).
*   [Um Jammer Lammy Japan Tentou Houei-you](http://redump.org/disc/97015/). _Probably_ no protection since this is a non-playable rolling 'movie disc' accroding to redump.org.