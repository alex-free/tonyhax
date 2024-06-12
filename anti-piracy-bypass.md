# [Tonyhax International](readme.md) -> Anti-Piracy Bypass System

Starting in late 1998, some specific PSX games began implementing additional game-specific copy protection routines designed to prevent playing backup CD-R copies of a game or imported region discs. Several different [types of additional copy protection](#protection-types) have been found in PSX games over the years. **Tonyhax International supports such games on a game by game/protection type basis, with a goal of finding and adding the ability to play all protected games**. If your console is equipped with an old-style non-stealth mod-chip, a Tonyhax International bypass effectively makes your non-stealth mod-chip a stealth mod-chip (that doesn't trigger protections).

If you do not see your protected game in the list, can add more info,can correct something in the guide, etc.  please open an [Anti-Piracy issue](https://github.com/alex-free/tonyhax/issues/new?assignees=&labels=antipiracy&template=antipiracy-issue.md&title=) on the [Tonyhax International Github](https://github.com/alex-free/tonyhax) to let me know.

_List Notes:_ 

*   Name format is: Name (region) (revision) (disc number), all derived from info on [redump](https://redump.org). Listed alphabetical order.

*   Tonyhax International Bypass Support marked as YES means the protection does not trigger when booting the game with Tonyhax International. If it is marked as NO there are simply extra steps you need to take to play this game with Tonyhax International. 

* If one game release was found to have anti-piracy protections ([APv1](#apv1) or [APv2](#apv2)), all revisions, demos, and regional releases (listed on redump) were **tested for active protection code**. This is because many games were released in different regions with different anti-piracy code, or it was disabled entirely for unknown reasons. **This info is not listed on redump correctly due to false positives by some closed source automatic tool they are using to detect different protections. The only way to figure out if the protection is sent is by testing the actual game.**. The APv1 and APv2 distinction is also not listed on redump either.

*   Many games containing [LibCrypt](#libcrypt) protection have 'unknown' listed as when the protection triggers. This is because I haven't investigated each game. The game is confirmed to have LibCrypt protection due to a LibCrypt patch existing for it. This info will be added in the future (**or help me add it, open a [generic issue](https://github.com/alex-free/tonyhax/issues/new))**.

## List Of Protected PSX Game Discs
--------------------------------------------

| Game Disc  | [Protection Type](#protection-types) | Protection Trigged At | Tonyhax International Bypass Support |
| --------------- | ------------- | ------------- | ------------- |
| [Actua Ice Hockey 2 (Europe)](http://redump.org/disc/5120/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Alundra 2 (Europe)](http://redump.org/disc/1089/) | None | - | - |
| [Alundra 2 (France)](http://redump.org/disc/13396/) | None | - | - |
| [Alundra 2 (Germany)](http://redump.org/disc/11603/) | None | - | - |
| [Alundra 2 (Japan) (Demo)](http://redump.org/disc/6752/) | None | - | - |
| [Alundra 2 (Japan)](http://redump.org/disc/15641/) | [APv2](#apv2) | First `Now Loading` screen after boot. | YES |
| [Alundra 2 (USA)](http://redump.org/disc/2996/) | None | - | - |
| [Animetic Story Game 1: Card Captor Sakura (Japan) (Disc 1)](http://redump.org/disc/12000/) | [APv2](#apv2) | Boot. | YES |
| [Animetic Story Game 1: Card Captor Sakura (Japan) (Disc 2)](http://redump.org/disc/11999/) | [APv2](#apv2) | Boot. | YES |
| [Anstoss: Premier Manager (Germany)](http://redump.org/disc/3334/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Ape Escape (Europe)](http://redump.org/disc/6147/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Ape Escape (France)](http://redump.org/disc/995/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Ape Escape (Germany)](http://redump.org/disc/26604/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Ape Escape (Italy)](http://redump.org/disc/27680/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Ape Escape: La Invasion de los Monos (Spain)](http://redump.org/disc/1128/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Arc The Lad III (Japan) (Rev 0) (Disc 1)](http://redump.org/disc/5897/) | [APv2](#apv2) | Boot. | YES |
| [Arc The Lad III (Japan) (Rev 0) (Disc 2)](http://redump.org/disc/5898/) | [APv2](#apv2) | Boot. | YES |
| [Arc The Lad III (Japan) (Rev 1) (Disc 1)](http://redump.org/disc/34793/) | [APv2](#apv2) | Boot. | YES |
| [Arc The Lad III (Japan) (Rev 1) (Disc 2)](http://redump.org/disc/34794/) | [APv2](#apv2) | Boot. | YES |
| [Arc The Lad III (USA) (Disc 1)](http://redump.org/disc/674/) | None | - | YES |
| [Arc The Lad III (USA) (Disc 2)](http://redump.org/disc/675/) | None | - | YES |
| [Asterix: Mega Madness (Europe) (En,Fr,De,Es,It,Nl)](http://redump.org/disc/4873/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Aventure Equestre (France)](http://redump.org/disc/29560/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Race & Ride (Europe)](http://redump.org/disc/11318/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Race & Ride (Germany)](http://redump.org/disc/25241/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Race & Ride (Italy)](http://redump.org/disc/28330/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Race & Ride (Spain)](http://redump.org/disc/25983/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Sports Extreme (France)](http://redump.org/disc/28149/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Super Sport (Germany)](http://redump.org/disc/26734/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Super Sports (Europe)](http://redump.org/disc/29290/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Super Sports (Italy)](http://redump.org/disc/35294/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Barbie: Super Sports (Spain)](http://redump.org/disc/5579/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [BDFL Manager 2001 (Germany)](http://redump.org/disc/17767/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [BDFL Manager 2002 (Germany)](http://redump.org/disc/3320/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Beat Mania Append 3rdMix (Japan)](http://redump.org/disc/2306/) | [EDC], [Key Disc](#key-disc) | Key Disc Disc Change/Boot. | EDC - NO. Key Disc - YES, boot game directly from Tonyhax International, do not use a Key Disc to boot it. |
| [Beat Mania 6thMix + Core Remix (Japan)](http://redump.org/disc/16285/) | [APv2](#apv2) | Boot. | YES | 
| [Beat Mania Append GottaMix (Japan)](http://redump.org/disc/3550/) | [APv2](#apv2), [Key Disc](#key-disc) | Key Disc Disc Change/Boot. | APv2 - YES. Key Disc - YES, boot game directly from Tonyhax International, do not use a Key Disc to boot it. |
| [Beatmania Best Hits (Japan) (Rev 0)](http://redump.org/disc/36175/) | [APv2](#apv2) | Boot. | YES |
| [Beatmania Best Hits (Japan) (Rev 1)](http://redump.org/disc/44332/) | [APv2](#apv2) | Boot. | YES | 
| [Beatmania featuring Dreams Come True (Japan)](http://redump.org/disc/36188/) | [APv2](#apv2) | Boot. |  YES | 
| [Beat Mania: The Sound of Tokyo (Japan)](http://redump.org/disc/36163/) | [APv2](#apv2) | Boot. | YES | 
| [Bishi Bashi Special 2 (Japan)](http://redump.org/disc/14212) | [APv1](#apv1) | Boot. | YES | 
| [Boku no Natsuyasumi: Summer Holiday 20th Century (Japan)](http://redump.org/disc/4890/) | [APv2](#apv2) | Boot. | YES |
| [Breath of Fire IV (E3 2000/Beta USA)](http://redump.org/disc/59620/) | [APv2](#apv2) | Boot. | YES | 
| [Breath of Fire IV (Europe)](http://redump.org/disc/549/) | None | - | -|
| [Breath of Fire IV (Japan)](http://redump.org/disc/1554/) | [APv2](#apv2) | Boot. | YES | 
| [Breath of Fire IV (USA)](http://redump.org/disc/1222/) | None | - | - |
| [Bust A Move 2: Dance Tengoku Mix (Japan Demo)](http://redump.org/disc/6753/) | [APv1](#apv1) | Boot. | YES |
| [Bust A Move 2: Dance Tengoku Mix (Japan)](http://redump.org/disc/3723/) | [APv1](#apv1) | Boot. | YES |
| [Canal+ Premier Manager (Europe) (Fr,Es,It)](http://redump.org/disc/27297/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Capcom vs. SNK: Millennium Fight 2000 Pro (Europe)](http://redump.org/disc/3904/) | None | - | - |
| [Capcom vs. SNK: Millennium Fight 2000 Pro (Japan Demo)](http://redump.org/disc/62464/) | None | - | - |
| [Capcom vs. SNK: Millennium Fight 2000 Pro (Japan)](http://redump.org/disc/37359/) | [APv2](#apv2) | Boot. | YES |
| [Chase The Express (Europe) (Disc 1)](http://redump.org/disc/27257/) | [APv2](#apv2) | Boot. | YES |
| [Chase The Express (Europe) (Disc 2)](http://redump.org/disc/27258/) | [APv2](#apv2) | Boot. | YES |
| [Chase The Express (France) (Disc 1)](http://redump.org/disc/28137/) | None | - | - |
| [Chase The Express (France) (Disc 2)](http://redump.org/disc/28138/) | None | - | - |
| [Chase The Express (Germany) (Disc 1)](http://redump.org/disc/7507/) | None | - | - |
| [Chase The Express (Germany) (Disc 2)](http://redump.org/disc/7508/) | None | - | - |
| [Chase The Express (Italy) (Disc 1)](http://redump.org/disc/28358/) | None | - | - |
| [Chase The Express (Italy) (Disc 2)](http://redump.org/disc/28359/) | None | - | - |
| [Chase The Express (Japan Demo 1)](http://redump.org/disc/6551/) | [APv2](#apv2) | Boot. | YES |
| [Chase The Express (Japan Demo 2)](http://redump.org/disc/19589/) | [APv2](#apv2) | Boot. | YES |
| [Chase The Express (Japan) (Disc 1)](http://redump.org/disc/5637/) | [APv2](#apv2) | Boot. | YES |
| [Chase The Express (Japan) (Disc 2)](http://redump.org/disc/5638/) | [APv2](#apv2) | Boot. | YES |
| [Chocobo Racing (Europe)](http://redump.org/disc/25331/) | None | - | - |
| [Chocobo Racing: Genkai e no Road (Japan)](http://redump.org/disc/4042/) | [APv1](#apv1) | Boot. | YES |
| [Chocobo Racing (USA)](http://redump.org/disc/14966/) | None | - | - |
| [Cool Boarders 2001 (USA Demo)](http://redump.org/disc/42467/) | [APv2](#apv2) | First loading screen. | YES |
| [Cool Boarders 2001 (USA)](http://redump.org/disc/513/) | [APv2](#apv2) | First loading screen. | YES |
| [Crash Bandicoot Racing (Japan Demo)](http://redump.org/disc/53590/) | [APv2](#apv2) | When the Naughty Dog box is first visible. | YES |
| [Crash Bandicoot Racing (Japan)](http://redump.org/disc/3694/) | [APv2](#apv2) | When the Naughty Dog box is first visible. | YES |
| [Crash Bash (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/5483/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Crash Bash (Europe)](http://redump.org/disc/5483/) | None | - | - |
| [Crash Bash (Japan Demo)](http://redump.org/disc/53589/) | None | - |  - |
| [Crash Bash (Japan)](http://redump.org/disc/3819/) | [APv2](#apv2) | At the 'Sony Computer Entertainment Presents' screen. |  YES |
| [Crash Bash (USA Demo)](http://redump.org/disc/49446/) | None | - | - |
| [Crash Bash (USA)](http://redump.org/disc/512/) | [APv2](#apv2) | At the 'Sony Computer Entertainment Presents' screen. |  YES |
| [CTR: Crash Team Racing (Europe) (En,Fr,De,Es,It,Nl) (EDC)](http://redump.org/disc/897/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [CTR: Crash Team Racing (Europe) (En,Fr,De,Es,It,Nl) (No EDC)](http://redump.org/disc/798/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1 (Japan)](http://redump.org/disc/23382/) | [APv2](#apv2), [Key Disc](#key-disc) | On Disc Change. | APv2 - YES. Key Disc - **ONLY USA/PAL consoles, or a Japanese console with a mod-chip are supported**.
| [Dance Dance Revolution 2nd Remix: Append Club Version Vol. 2 (Japan)](http://redump.org/disc/33339/) | [APv2](#apv2), [Key Disc](#key-disc) | On Disc Change. | APv2 - YES. Key Disc - **ONLY USA/PAL consoles, or a Japanese console with a mod-chip are supported**.
| [Dance Dance Revolution 2nd Remix (Japan)](http://redump.org/disc/9477/) | [APv2](#apv2), [EDC](#edc) |  Immediately at first screen with text. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution 3rd Mix (Japan)](http://redump.org/disc/9536/). | [APv2](#apv2), [EDC](#edc) | First `NOW LOADING` blinking text screen after selecting the first option in the start menu. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution 4th Mix (Japan)](http://redump.org/disc/34157/) | [APv2](#apv2), [EDC](#edc) | First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution 5th Mix (Japan)](http://redump.org/disc/37558/) | [APv2](#apv2), [EDC](#edc) | First `NOW LOADING` blinking text screen after selecting the `TRAINING` option in the  start menu. | APv2 - YES EDC - NO, [burn disc in special way](#edc) |
| [Dance Dance Revolution: Best Hits (Japan)](http://redump.org/disc/30601) | [APv2](#apv2), [EDC](#edc) |  Boot. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution: Disney's Rave (Japan)](http://redump.org/disc/37012/) | [APv2](#apv2), [EDC](#edc) |  Boot. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution Extra Mix (Japan)](http://redump.org/disc/44438/) | [APv2](#apv2), [EDC](#edc) | First `NOW LOADING` blinking text screen after selecting the first option in the  start menu. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution (Japan)](http://redump.org/disc/1562/) | [APv1](#apv1), [EDC](#edc) |  First `NOW LOADING` blinking text screen after selecting the first default option in the main  menu at start. | APv1 - YES.  EDC - YES. |
| [Dance Dance Revolution Konamix (USA)](http://redump.org/disc/1238/) | [EDC](#edc) | Immediately there is a `NOW LOADING` blinking text screen and the CD drive goes crazy. | NO, [burn disc in special way](#edc). |
| [Dance Dance Revolution (USA)](http://redump.org/disc/1562/) | [APv2], [EDC](#edc) | APv2 - `KCET` logo. EDC - after selecting a mode in the main menu there is a `NOW LOADING` blinking text screen that never loads. | APv2 - YES. EDC - NO, [burn disc in special way](#edc). |
| [Dancing Blade Katte ni Momotenshi II: Tears of Eden (Japan) (Disc 1)](http://redump.org/disc/14229/) | [APv1](#apv1) | First Konami logo screen. | YES |
| [Dancing Blade Katte ni Momotenshi II: Tears of Eden (Japan) (Disc 2)](http://redump.org/disc/14230/) | [APv1](#apv1) | First Konami logo screen. | YES |
| [Dancing Blade Katte ni Momotenshi II: Tears of Eden (Japan) (Disc 3)](http://redump.org/disc/14228/) | [APv1](#apv1) | First Konami logo screen. | YES |
| [Dancing Stage Featuring Dreams Come True (Japan)](http://redump.org/disc/17882/) | [APv2](#apv2) | On the first text screen after boot, before first FMV. | YES |
| [Dancing Stage Featuring True Kiss Destination (Japan)](http://redump.org/disc/15853/) | [APv2](#apv2) | On the first text screen after boot, before first FMV. | YES |
| [Dino Crisis 2 (Europe)](http://redump.org/disc/1071/) | None | - | - |
| [Dino Crisis 2 (France)](http://redump.org/disc/29514/) | None | - | - |
| [Dino Crisis 2 (Germany)](http://redump.org/disc/10641/) | None | - | - |
| [Dino Crisis 2 (Italy)](http://redump.org/disc/45993/) | None | - | - |
| [Dino Crisis 2 (Japan Demo)](http://redump.org/disc/4407/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis 2 (Japan)](http://redump.org/disc/1600/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis 2 (Spain)](http://redump.org/disc/27941/) | None | - | - |
| [Dino Crisis 2 (USA Demo)](http://redump.org/disc/49242/) | None | - | - |
| [Dino Crisis 2 (USA)](http://redump.org/disc/460/) | None | - | - |
| [Dino Crisis (Europe)](http://redump.org/disc/710/) | [LibCrypt](#libcrypt) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis (Europe)](http://redump.org/disc/710/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Dino Crisis (France)](http://redump.org/disc/24278/) | [LibCrypt](#libcrypt) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis (France)](http://redump.org/disc/24278/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Dino Crisis (Germany)](http://redump.org/disc/7586/) | [LibCrypt](#libcrypt) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis (Germany)](http://redump.org/disc/7586/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Dino Crisis (Italy)](http://redump.org/disc/28171/) | [LibCrypt](#libcrypt) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis (Italy)](http://redump.org/disc/28171/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Dino Crisis (Japan)](http://redump.org/disc/15853/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis (Spain)](http://redump.org/disc/27940/) | [LibCrypt](#libcrypt) | On the disclaimer screen after the game boots. | YES |
| [Dino Crisis (Spain)](http://redump.org/disc/27940/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Dino Crisis (USA Demo)](http://redump.org/disc/2942/) | None | - | - |
| [Dino Crisis (USA) (Rev 0)](http://redump.org/disc/459/) | [APv2](#apv2) | On the disclaimer screen after the game boots. |YES |
| [Dino Crisis (USA) (Rev 1)](http://redump.org/disc/473/) | [APv2](#apv2) | On the disclaimer screen after the game boots. |YES |
| [Disney Fais Ton Histoire! Mulan (France)](http://redump.org/disc/27819/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney Libro Animato Creativo: Mulan (Italy)](http://redump.org/disc/28327/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney Libro Animato Creativo: Mulan (Italy)](http://redump.org/disc/28327/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disneyn Tarzan (Finland)](http://redump.org/disc/48938/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). | 
| [Disney's 102 Dalmatians: Puppies to the Rescue (Europe) (Fr,De,Es,It,Nl)](http://redump.org/disc/19140/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's 102 Dalmatians: Puppies to the Rescue (Europe)](http://redump.org/disc/58589/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's 102 Dalmatians: Puppies to the Rescue (Scandinavia)](http://redump.org/disc/53874/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's Aventura Interactiva: Mulan (Spain)](http://redump.org/disc/17311/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disneys Interaktive Abenteuer: Mulan (Germany)](http://redump.org/disc/19124/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's Mulan: Story Studio (Europe)](http://redump.org/disc/6887/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disneys Tarzan (Denmark)](http://redump.org/disc/51711/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's Tarzan (Europe)](http://redump.org/disc/29818/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disneys Tarzan (Germany)](http://redump.org/disc/19124/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disneys Tarzan (Italy)](http://redump.org/disc/27824/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disneys Tarzan (Netherlands)](http://redump.org/disc/27067/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's Tarzan (Sweden)](http://redump.org/disc/6885/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney's The Emperor's New Grove (Europe)](http://redump.org/disc/7565/) | [APv2](#apv2) | Start a new game, after the first FMV on the first loading screen is when the check completes. | YES |
| [Disney's The Emperor's New Grove (USA)](http://redump.org/disc/14583/) | [APv2](#apv2) | Start a new game, after the first FMV on the first loading screen is when the check completes. | YES |
| [Disney's Verhalenstudio: Mulan (Netherlands)](http://redump.org/disc/27076/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney Tarzan (France)](http://redump.org/disc/29462/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Disney Tarzan (Spain)](http://redump.org/disc/27287/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Doko Demo Issho (Japan) (Demo 1)](http://redump.org/disc/6755/) | [APv1](#apv1) | Boot. | YES |
| [Doko Demo Issho (Japan) (Demo 2)](http://redump.org/disc/83081/) | [APv1](#apv1) | Boot. | YES |
| [Doko Demo Issho (Japan) (Rev 0)](http://redump.org/disc/1335/) | [APv1](#apv1) | Boot. | YES |
| [Doko Demo Issho (Japan) (Rev 1)](http://redump.org/disc/20288/) | [APv1](#apv1) | Boot. | YES |
| [Doko Demo Issho (Japan) (Water Calpis Version)](http://redump.org/disc/49161/) | [APv1](#apv1) | Boot. | YES |
| [Eagle One: Harrier Attack (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/880/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [EA Sports Superbike 2000 (Europe) (En,Fr,De,Es,It,Sv)](http://redump.org/disc/26580/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Esto es Futbol (Spain)](http://redump.org/disc/25328/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Exciting Bass 2 (Japan)](http://redump.org/disc/63487/) | [APv2](#apv2) | Boot. | YES |
| [Exciting Bass 3 (Japan)](http://redump.org/disc/59734/) | [APv2](#apv2) | Boot. | YES |
| [F1 2000 (Europe) (En,Es,Sv,Da,Fi)](http://redump.org/disc/6867/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [F1 2000 (Europe) (En,Fr,De,Nl)](http://redump.org/disc/4311/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [F1 2000 (Italy)](http://redump.org/disc/29597/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Europe) (Disc 1)](http://redump.org/disc/2371/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Europe) (Disc 2)](http://redump.org/disc/2370/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Europe) (Disc 3)](http://redump.org/disc/2370/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Europe) (Disc 4)](http://redump.org/disc/2373/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (France) (Disc 1)](http://redump.org/disc/2455/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (France) (Disc 2)](http://redump.org/disc/2456/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (France) (Disc 3)](http://redump.org/disc/2457/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (France) (Disc 4)](http://redump.org/disc/2458/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Germany) (Disc 1)](http://redump.org/disc/737/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Germany) (Disc 2)](http://redump.org/disc/738/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Germany) (Disc 3)](http://redump.org/disc/739/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Germany) (Disc 4)](http://redump.org/disc/740/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Italy) (Disc 1)](http://redump.org/disc/2714/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Italy) (Disc 2)](http://redump.org/disc/2714/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Italy) (Disc 3)](http://redump.org/disc/2714/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Italy) (Disc 4)](http://redump.org/disc/2714/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Spain) (Disc 1)](http://redump.org/disc/1113/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Spain) (Disc 2)](http://redump.org/disc/1114/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Spain) (Disc 3)](http://redump.org/disc/1115/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy IX (Spain) (Disc 4)](http://redump.org/disc/1114/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe, Australia) (Disc 1)](http://redump.org/disc/866/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe, Australia) (Disc 2)](http://redump.org/disc/875/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe, Australia) (Disc 3)](http://redump.org/disc/873/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe, Australia) (Disc 4)](http://redump.org/disc/874/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe) (Demo 1)](http://redump.org/disc/2627/) | None | - | - |
| [Final Fantasy VIII (Europe) (Demo 2)](http://redump.org/disc/53142/) | None | - | - |
| [Final Fantasy VIII (Europe) (Disc 1)](http://redump.org/disc/866/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe) (Disc 2)](http://redump.org/disc/875/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe) (Disc 3)](http://redump.org/disc/873/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Europe) (Disc 4)](http://redump.org/disc/874/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (France) (Demo)](http://redump.org/disc/4717/) | None. | - | - |
| [Final Fantasy VIII (France) (Disc 1)](http://redump.org/disc/4028/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (France) (Disc 2)](http://redump.org/disc/4029/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (France) (Disc 3)](http://redump.org/disc/4030/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (France) (Disc 4)](http://redump.org/disc/4031/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Germany) (Disc 1)](http://redump.org/disc/733/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Germany) (Disc 2)](http://redump.org/disc/734/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Germany) (Disc 3)](http://redump.org/disc/735/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Germany) (Disc 4)](http://redump.org/disc/736/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Italy) (Disc 1)](http://redump.org/disc/1587/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Italy) (Disc 2)](http://redump.org/disc/1588/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Italy) (Disc 3)](http://redump.org/disc/1589/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Italy) (Disc 4)](http://redump.org/disc/1590/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Japan) (Disc 1)](http://redump.org/disc/1422/) | [APv1](#apv1) | Boot. | YES |
| [Final Fantasy VIII (Japan) (Disc 2)](http://redump.org/disc/1423/) | [APv1](#apv1) | Boot. | YES |
| [Final Fantasy VIII (Japan) (Disc 3)](http://redump.org/disc/1424/) | [APv1](#apv1) | Boot. | YES |
| [Final Fantasy VIII (Japan) (Disc 4)](http://redump.org/disc/1425/) | [APv1](#apv1) | Boot. | YES |
| [Final Fantasy VIII (Spain) (Disc 1)](http://redump.org/disc/1109/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Spain) (Disc 2)](http://redump.org/disc/1110/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Spain) (Disc 3)](http://redump.org/disc/1111/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (Spain) (Disc 4)](http://redump.org/disc/1112/) | [LibCrypt](#libcrypt) | Boot. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Final Fantasy VIII (USA) (Disc 1)](http://redump.org/disc/69/) | None | - | - |
| [Final Fantasy VIII (USA) (Disc 2)](http://redump.org/disc/70/) | None | - | - |
| [Final Fantasy VIII (USA) (Disc 3)](http://redump.org/disc/71) | None | - | - |
| [Final Fantasy VIII (USA) (Disc 4)](http://redump.org/disc/72/) | None | - | - |
| [Football Manager Campionato 2001 (Italy)](http://redump.org/disc/29597/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Football Manager Campionato 2002 (Italy)](http://redump.org/disc/48369/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Formula One 99 (Europe) (En,Es,Fi)](http://redump.org/disc/31126/) | [LibCrypt](#libcrypt) | Loading a level crashes game. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Formula One 99 (Europe) (En,Fr,De,It) (Beta 9/9/1999)](http://redump.org/disc/64499/) | [LibCrypt](#libcrypt) | Loading a level crashes game. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Formula One 99 (Europe) (En,Fr,De,It)](http://redump.org/disc/969/) | [LibCrypt](#libcrypt) | Loading a level crashes game. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| Formula One 99 (Europe) (En,Fr,De,It) (prototype 8/12/1999) - find it on hiddenpalace, no redump page exists! | [LibCrypt](#libcrypt) | Loading a level crashes game. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Frontschweine (Germany)](http://redump.org/disc/19539/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Fussball Live (Germany)](http://redump.org/disc/4385/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Fussball Manager 2001 (Germany)](http://redump.org/disc/7516/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (Europe) (Disc 1)](http://redump.org/disc/7420/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (Europe) (Disc 2)](http://redump.org/disc/7421/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (Europe) (Disc 3)](http://redump.org/disc/7422/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (France) (Disc 1)](http://redump.org/disc/13382/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (France) (Disc 2)](http://redump.org/disc/13383/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (France) (Disc 3)](http://redump.org/disc/13384/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (Germany) (Disc 1)](http://redump.org/disc/7695/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (Germany) (Disc 2)](http://redump.org/disc/7696/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Galerians (Germany) (Disc 3)](http://redump.org/disc/7697/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Gekido: Urban Fighters (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/833/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Gekitotsu Toma L'Arc - L'Arc en Ciel vs Tomarunner (Japan)](http://redump.org/disc/20715/) | [APv2](#apv2) | Boot. | YES |
| [Glint Glitters (Japan)](http://redump.org/disc/15969/) | [APv2](#apv2) | Boot. | YES |
| [Global Force: Shin Sentou Kokka (Japan) (Demo)](http://redump.org/disc/4819/) | [APv1](#apv1) | Boot. | YES |
| [Global Force: Shin Sentou Kokka (Japan) (Rev 0)](http://redump.org/disc/20715/) | [APv1](#apv1) | Boot. | YES |
| [Global Force: Shin Sentou Kokka (Japan) (Rev 1)](http://redump.org/disc/7588/) | [APv1](#apv1) | Boot. | YES |
| [Goo! Goo! Soundry (Japan)](http://redump.org/disc/16027/) | [APv2](#apv2) | First now loading screen. | YES |
| [Grind Session (Europe)](http://redump.org/disc/3688/) |  None | - | - |
| [Grind Session (Scandinavia)](http://redump.org/disc/53879/) | None | - | - |
| [Grind Session (USA) (Demo)](http://redump.org/disc/42794/) | None | - | - |
| [ Grind Session (USA)](http://redump.org/disc/854/) | [APv2](#apv2) | After going through the main menu and starting training/single player/a level. | YES |
| [Guitar Freaks (Japan)](http://redump.org/disc/2277/) | [APv2](#apv2) | At the loading screen with the spinning guitars. | YES |
| [Gungauge (Japan)](http://redump.org/disc/6328/) | [APv2](#apv2) | At the loading screen with the spinning guitars. | YES |
| [Harlem Beat: You're The One (Japan)](http://redump.org/disc/36294/) | [APv2](#apv2) | First loading screen. | YES |
| [Hogs of War (Europe)](http://redump.org/disc/703/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Hogs of War: Nati per Soffritto](http://redump.org/disc/48020/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Hyper Value 2800: Hanafuda (Japan)](http://redump.org/disc/15791/) | [APv2](#apv2) | Boot. | YES |
| [Hyper Value 2800: Hyper Pachinko (Japan)](http://redump.org/disc/15792/) | [APv2](#apv2) | Boot. | YES |
| [Hyper Value 2800: Mahjong (Japan)](http://redump.org/disc/15793/) | [APv2](#apv2) | Boot. | YES |
| [i-mode mo Issho: Doko Demo Issho Tsuika Disc (Japan)](http://redump.org/disc/15793/) | [APv2](#apv2), [PAL BIOS Detection](#pal-bios-detection) | Boot. | APv2 - YES. PAL BIOS Detection - YES. |
| [I.Q Final (Japan) (Demo 1)](http://redump.org/disc/6649/) | [APv1](#apv1) | Boot. | YES |
| [I.Q Final (Japan) (Demo 2)](http://redump.org/disc/32988/) | [APv1](#apv1) | Boot. | YES |
| [I.Q Final (Japan)](http://redump.org/disc/1504/) | None | - | - |
| [Jackie Chan Stuntmaster (Europe)](http://redump.org/disc/3985/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Jackie Chan Stuntmaster (Europe) (Recalled)](http://redump.org/disc/64315/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Jikkyou Kyousouba Ikusei Simulation Game: Breeding Stud '99 (Japan)](http://redump.org/disc/8762/) | [APv1](#apv1) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu 2000: Kaimakuban (Japan)](http://redump.org/disc/9553/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu 2000: Ketteiban (Japan)](http://redump.org/disc/11092/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu 2001 (Japan)](http://redump.org/disc/9554/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu 2001: Ketteiban (Japan)](http://redump.org/disc/17257/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu 2002: Haru (Japan)](http://redump.org/disc/9551/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu '99: Kaimakuban (Japan)](http://redump.org/disc/1686/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu '99: Ketteiban (Japan)](http://redump.org/disc/11091/) | [APv2](#apv2) | Boot. | YES |
| [Jikkyou Powerful Pro Yakyuu: Premium-ban (Japan)](http://redump.org/disc/11090/) | [APv2](#apv2) | Boot. | YES |
| [JoJo's Bizarre Adventure (Europe)](http://redump.org/disc/9983/) | None | - | - |
| [JoJo's Bizarre Adventure (Japan)](http://redump.org/disc/2871/) | [APv2](#apv2) | First loading screen. | YES |
| [JoJo's Bizarre Adventure (USA)](http://redump.org/disc/386/) | None | - | - |
| [Koko Hore! Pukka (Japan)](http://redump.org/disc/4812/) | [APv2](#apv2) | Boot. | YES |
| [Konami 80's Arcade Gallery (Japan)](http://redump.org/disc/16955/) | [APv1](#apv1) | Boot. | YES |
| [Koneko mo Issho (Japan)](http://redump.org/disc/6329/) | [APv2](#apv2), [PAL BIOS Detection](#pal-bios-detection) | Boot. | APv2 - YES. PAL Bios Detection - YES. |
| [Legacy of Kain: Soul Reaver (Europe)](http://redump.org/disc/1177/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Legacy of Kain: Soul Reaver (France)](http://redump.org/disc/24279)
| [Legacy of Kain: Soul Reaver (Germany)](http://redump.org/disc/393/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Legacy of Kain: Soul Reaver (Italy)](http://redump.org/disc/28167/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Legacy of Kain: Soul Reaver (Spain)](http://redump.org/disc/27944/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Legend Of Dragoon (Europe) (Disc 1)](http://redump.org/disc/2379/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Europe) (Disc 2)](http://redump.org/disc/2380/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Europe) (Disc 3)](http://redump.org/disc/2381/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Europe) (Disc 4)](http://redump.org/disc/2382/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (France) (Disc 1)](http://redump.org/disc/16750/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (France) (Disc 2)](http://redump.org/disc/16751/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (France) (Disc 3)](http://redump.org/disc/16752/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (France) (Disc 4)](http://redump.org/disc/16753/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Germany) (Disc 1)](http://redump.org/disc/15580/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Germany) (Disc 2)](http://redump.org/disc/15581/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Germany) (Disc 3)](http://redump.org/disc/15582/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Germany) (Disc 4)](http://redump.org/disc/15583/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Italy) (Disc 1)](http://redump.org/disc/30643/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Italy) (Disc 2)](http://redump.org/disc/30644/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Italy) (Disc 3)](http://redump.org/disc/30645/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Italy) (Disc 4)](http://redump.org/disc/30646/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Japan) (Disc 1)](http://redump.org/disc/22753/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Japan) (Disc 2)](http://redump.org/disc/22754/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Japan) (Disc 3)](http://redump.org/disc/22755/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (Japan) (Disc 4)](http://redump.org/disc/22756/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (USA) (Disc 1)](http://redump.org/disc/153/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (USA) (Disc 2)](http://redump.org/disc/154/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (USA) (Disc 3)](http://redump.org/disc/155/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Dragoon (USA) (Disc 4)](http://redump.org/disc/156/) | [APv2](#apv2) | First loading screen. | YES |
| [Legend Of Mana (Japan)](http://redump.org/disc/1940/) | [APv2](#apv2) | Boot. | YES |
| [Legend Of Mana (USA)](http://redump.org/disc/96/) | [APv2](#apv2) | Boot. | YES |
| [Le Mans 24 Hours (Europe) (En,Fr,De,Es,It,Pt)](http://redump.org/disc/1659/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Le Monde des Bleus: Le Jeu Officiel de l'Équipe de France (France)](http://redump.org/disc/8346/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Les Cochons de Guerre (France) (Rev 0)](http://redump.org/disc/33070/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Les Cochons de Guerre (France) (Rev 1)](http://redump.org/disc/99695/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [LMA Manager 2001 (Europe) (Beta 02/26/2001)](http://redump.org/disc/92303/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [LMA Manager 2001 (Europe)](http://redump.org/disc/6847/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [LMA Manager 2002 (Europe)](http://redump.org/disc/26750/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Lord Of Monsters (Japan) (Demo)](http://redump.org/disc/68358/) | [APv1](#apv1) | Boot. | YES |
| [Lord Of Monsters (Japan)](http://redump.org/disc/58023/) | [APv1](#apv1) | Boot. | YES |
| [Love Hina 2: Kotoba wa Konayuki no You ni (Japan)](http://redump.org/disc/7370/) | [APv2](#apv2) | Boot. | YES |
| [Love Hina: Ai wa Kotoba no Naka ni (Japan)](http://redump.org/disc/7369/) | [APv2](#apv2) | Boot. | YES |
| [Lucky Luke: Western Fever (Europe) (En,Fr,De,Es,It,Nl)](http://redump.org/disc/19142/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Magical Tetris Challenge featuring Mickey (Japan)](http://redump.org/disc/19170/) | [APv1](#apv1) | Boot. | YES |
| [Manager de Liga 2001 (Spain)](http://redump.org/disc/48045/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Manager de Liga 2002 (Spain)](http://redump.org/disc/48045/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Manager de Liga (Spain) (Beta)](http://redump.org/disc/3413/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Marranos en Guerra (Spain)](http://redump.org/disc/48791/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Marvel vs. Capcom: Clash of Super Heroes (Europe)](http://redump.org/disc/3910/) | None | - | - |
| [Marvel vs. Capcom: Clash of Super Heroes (Japan) (Demo)](http://redump.org/disc/60646/) | [APv2](#apv2) | Boot. | YES |
| [Marvel vs. Capcom: Clash of Super Heroes (Japan)](http://redump.org/disc/36384/) | [APv2](#apv2) | Boot. | YES |
| [Marvel vs. Capcom: Clash of Super Heroes (USA)](http://redump.org/disc/1235/) | None | - | - |
| [MediEvil 2 (Europe) (En,Fr,De)](http://redump.org/disc/593/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil 2 (Europe) (Es,It,Pt)](http://redump.org/disc/1547/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil 2 (Russia)](http://redump.org/disc/2625/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil (Europe)](http://redump.org/disc/592/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil (France)](http://redump.org/disc/13389/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil (Germany)](http://redump.org/disc/25542/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil II (Europe) (Demo)](http://redump.org/disc/45822/) | None | - | - |
| [MediEvil II (Europe) (Rev 0)](http://redump.org/disc/593/) | None | - | - |
| [MediEvil II (Europe) (Rev 1)](http://redump.org/disc/1547/) | None | - | - |
| [MediEvil II (USA)](http://redump.org/disc/2503/) | [APv2](#apv2) | At the Whitechapel level loading screen (quite far in the game). | YES |
| [MediEvil (Italy)](http://redump.org/disc/29475/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MediEvil (Spain)](http://redump.org/disc/1584/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Men in Black: The Series: Crashdown (Europe)](http://redump.org/disc/30764/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Men in Black: The Series: Crashdown (France)](http://redump.org/disc/28185/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Men in Black: The Series: Crashdown (Germany)](http://redump.org/disc/17711/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Men in Black: The Series: Crashdown (Italy)](http://redump.org/disc/28025/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Men in Black: The Series: Crashdown (Spain)](http://redump.org/disc/27937/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Metal Gear Solid: Integral (Japan) (Disc 1)](http://redump.org/disc/423/) | [APv1](#apv1) | Boot. | YES |
| [Metal Gear Solid: Integral (Japan) (Disc 2)](http://redump.org/disc/424/) | [APv1](#apv1) | Boot. | YES |
| [Metal Gear Solid: Integral (Japan) (Disc 3)](http://redump.org/disc/426/) | [APv1](#apv1) | Boot. | YES |
| [Michelin Rally Masters: Race of Champions (Europe) (En,De,Sv)](http://redump.org/disc/25913/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Michelin Rally Masters: Race of Champions (Europe) (Fr,Es,It)](http://redump.org/disc/28160/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Mike Tyson Boxing (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/5823/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Minna no Golf 2 / Everybody's Golf 2 (Europe)](http://redump.org/disc/19905/) | None | Boot. | YES |
| [Minna no Golf 2 / Everybody's Golf 2 (Japan) (Rev 0)](http://redump.org/disc/2290/) | [APv2](#apv2) | Boot. | YES |
| [Minna no Golf 2 / Everybody's Golf 2 (Japan) (Rev 1)](http://redump.org/disc/2291/) | [APv2](#apv2) | Boot. | YES |
| [Mission: Impossible (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/1176/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [MLB 2002 (USA) (Demo)](http://redump.org/disc/43238/) | [APv2](#apv2) | First loading screen. | YES |
| [MLB 2002 (USA)](http://redump.org/disc/826/) | [APv2](#apv2) | First loading screen. | YES |
| [MLB 2003 (USA) (Demo)](http://redump.org/disc/50864/) | [APv2](#apv2) | First loading screen. | YES |
| [MLB 2003 (USA)](http://redump.org/disc/16660/) | [APv2](#apv2) | First loading screen. | YES |
| [MLB 2004 (USA)](http://redump.org/disc/15325/) | [APv2](#apv2) | First loading screen. | YES |
| [MLB 2005 (USA)](http://redump.org/disc/7212/) | [APv2](#apv2) | First loading screen. | YES |
| [MoHo (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/15091/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Monde des Bleus, Le: Le jeu officiel de l'equipe de France (France)](http://redump.org/disc/8346/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [My Garden (Japan)](http://redump.org/disc/8300/) | [APv2](#apv2) | Boot. | YES |
| [NBA Shootout 2001 (USA) (Demo)](http://redump.org/disc/42465/) | [APv2](#apv2) | At the end of the first loading screen. | YES |
| [NBA Shootout 2001 (USA)](http://redump.org/disc/16764/) | [APv2](#apv2) | At the end of the first loading screen. | YES |
| [NBA Shootout 2002 (USA) (Demo)](http://redump.org/disc/44305/) | [APv2](#apv2) | At the end of the first loading screen. | YES |
| [NBA Shootout 2002 (USA)](http://redump.org/disc/14527/) | [APv2](#apv2) | At the end of the first loading screen. | YES |
| [NBA Shootout 2003 (USA)](http://redump.org/disc/14566/) | [APv2](#apv2) | At the end of the first loading screen. | YES |
| [NBA Shootout 2004 (USA)](http://redump.org/disc/20551/) | [APv2](#apv2) | At the end of the first loading screen. | YES |
| [NCAA Final Four 2001 (USA)](http://redump.org/disc/16765/) | [APv2](#apv2) | First loading screen. | YES |
| [NCAA Game Breaker 2001 (USA) (Demo)](http://redump.org/disc/43879/) | [APv2](#apv2) | Second loading screen. | YES |
| [NCAA Game Breaker 2001 (USA)](http://redump.org/disc/14374/) | [APv2](#apv2) | Second loading screen. | YES |
| [Need for Speed: Porsche 2000 (Europe) (En,De,Sv)](http://redump.org/disc/622/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Need for Speed: Porsche 2000 (Europe) (Fr,Es,It)](http://redump.org/disc/3933/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [NFL GameDay 2001 (USA) (Demo)](http://redump.org/disc/50868/) | [APv2](#apv2) | First loading screen. |  YES |
| [NFL GameDay 2001 (USA)](http://redump.org/disc/21065/) | [APv2](#apv2) | First loading screen. | YES |
| [NFL GameDay 2002 (USA)](http://redump.org/disc/2725/) | [APv2](#apv2) | First loading screen. | YES |
| [NFL GameDay 2003 (USA)](http://redump.org/disc/13364/) | [APv2](#apv2) | Third loading screen. | YES |
| [NFL GameDay 2004 (USA)](http://redump.org/disc/14523/) | [APv2](#apv2) | Third loading screen. | YES |
| [NFL GameDay 2005 (USA)](http://redump.org/disc/15995/) | [APv2](#apv2) | Third loading screen. | YES |
| [N-Gen Racing (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/1010/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [NHL FaceOff 2001 (USA) (Demo)](http://redump.org/disc/43880/) | [APv2](#apv2) | When the main menu starts. | YES |
| [NHL FaceOff 2001 (USA)](http://redump.org/disc/12934/) | [APv2](#apv2) | When the main menu starts. | YES |
| [Oha-Studio Dance Dance Revolution (Japan)](http://redump.org/disc/33938/) | [APv2](#apv2) | Boot. | YES |
| [Ore no Ryouri / My Cooking (Japan)](http://redump.org/disc/39643/) | [APv2](#apv2) | Boot. | YES |
| [Ore no Shikabane o Koete Yuke (Japan) (Demo)](http://redump.org/disc/82897/) | None | - | - |
| [Ore no Shikabane o Koete Yuke (Japan)](http://redump.org/disc/3983/) | [APv2](#apv2) | Start a new game and proceed through the beginning intro text, it is quite a bit to go through to see it trigger. Once you finish making your character it will trigger, google translate is your friend here. | YES |
| [OverBlood 2 (Europe) (Disc 1) (v1.0)](http://redump.org/disc/26606/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [OverBlood 2 (Europe) (Disc 2) (v1.0)](http://redump.org/disc/26607/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [OverBlood 2 (Italy) (Disc 1)](http://redump.org/disc/35017/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [OverBlood 2 (Italy) (Disc 2)](http://redump.org/disc/35018/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Panekit: Infinitive Crafting Toy Case (Japan) (Rev 0)](http://redump.org/disc/5364/) | [APv1](#apv1) | Boot. | YES |
| [Panekit: Infinitive Crafting Toy Case (Japan) (Rev 1)](http://redump.org/disc/75024/) | [APv1](#apv1) | Boot. | YES |
| [Parasite Eve II (Europe) (Disc 1)](http://redump.org/disc/118/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Europe) (Disc 2)](http://redump.org/disc/119/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (France) (Disc 1)](http://redump.org/disc/13381/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (France) (Disc 2)](http://redump.org/disc/13380/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Germany) (Disc 1)](http://redump.org/disc/4307/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Germany) (Disc 2)](http://redump.org/disc/4308/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Italy) (Disc 1)](http://redump.org/disc/29442/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Italy) (Disc 2)](http://redump.org/disc/29443/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Spain) (Disc 1)](http://redump.org/disc/1122/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Parasite Eve II (Spain) (Disc 2)](http://redump.org/disc/1123/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [PGA European Tour Golf (Europe) (En,De)](http://redump.org/disc/772/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [PGA European Tour Golf (Fr, It, Es) (Alt) (Europe)](http://redump.org/disc/56471/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [PGA European Tour Golf (Fr, It, Es) (Europe)](http://redump.org/disc/46131/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Planet Laika (Japan)](http://redump.org/disc/75024/) | [APv1](#apv1) | Boot. | YES. **TONYHAX INTERNATIONAL GAMESHARK CODE FEATURES CAN NOT BE USED WITH THE ENGLISH TRANSLATION PATCHED GAME DISC**. The translation uses the same memory for that feature. GameShark codes with the original Japanese release has no issues. |
| [Pocket Jiman (Japan)](http://redump.org/disc/3189/) | [APv2](#apv2) | Boot. | YES |
| [Pocket MuuMuu (Japan)](http://redump.org/disc/16166/) | [APv1](#apv1) | Boot. | YES |
| [Pop'n Music 2 (Japan)](http://redump.org/disc/9774/) | [APv2](#apv2) | Boot. | YES |
| [Pop'n Music 5 (Japan)](http://redump.org/disc/9778/) | [APv2](#apv2) | Boot. | YES |
| [Pop'n Music 6 (Japan)](http://redump.org/disc/9777/) | [APv2](#apv2) | Boot. | YES |
| [Pop'n Music: Animation Melody (Japan)](http://redump.org/disc/33223/) | [APv2](#apv2) | Boot. | YES |
| [Pop'n Music: Disney Tunes (Japan)](http://redump.org/disc/34263/) | [APv2](#apv2) | Boot. | YES |
| [PoPoLoCrois Monogatari II (Japan) (Demo)](http://redump.org/disc/57327/) | None | - |
| [PoPoLoCrois Monogatari II (Japan) (Disc 1)](http://redump.org/disc/1653/) | [APv2](#apv2) | Boot. | YES |
| [PoPoLoCrois Monogatari II (Japan) (Disc 2)](http://redump.org/disc/1654/) | [APv2](#apv2) | Boot. | YES |
| [PoPoLoCrois Monogatari II (Japan) (Disc 3)](http://redump.org/disc/1651/) | [APv2](#apv2) | Boot. | YES |
| [PoPoRoGue (Japan) (Demo)](http://redump.org/disc/35068/) | None | - | - |
| [PoPoRoGue (Japan) (Rev 0)](http://redump.org/disc/1552/) | [APv1](#apv1) | Boot. | YES |
| [PoPoRoGue (Japan) (Rev 1)](http://redump.org/disc/8313/) | [APv1](#apv1) | Boot. | YES |
| [Premier Manager 2000 (Europe)](http://redump.org/disc/3619/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Prince Naseem Boxing (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/3309/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Radikal Bikers (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/25908/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [RC Revenge (Europe) (En,Fr,De,Es)](http://redump.org/disc/5127/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: Nemesis (Europe)](http://redump.org/disc/496/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: Nemesis (France)](http://redump.org/disc/9753/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: Nemesis (Germany)](http://redump.org/disc/5526/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: Nemesis (Ireland)](http://redump.org/disc/28197/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: Nemesis (Italy)](http://redump.org/disc/16397/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: Nemesis (Spain)](http://redump.org/disc/1387/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Resident Evil 3: The Last Escape (Europe) (Demo)](http://redump.org/disc/9463/) | None | - | - |
| [Resident Evil 3: The Last Escape (Europe)](http://redump.org/disc/496/) | None | - | - |
| [Resident Evil 3: The Last Escape (France)](http://redump.org/disc/9753/) | None | - | - |
| [Resident Evil 3: The Last Escape (Germany)](http://redump.org/disc/5526/) | None | - | - |
| [Resident Evil 3: The Last Escape (Ireland)](http://redump.org/disc/28197/) | None | - | - |
| [Resident Evil 3: The Last Escape (Italy)](http://redump.org/disc/16397/) | None | - | - |
| [Resident Evil 3: The Last Escape (Japan) (Demo)](http://redump.org/disc/11674/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Resident Evil 3: The Last Escape (Japan) (Rev 0)](http://redump.org/disc/10/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Resident Evil 3: The Last Escape (Japan) (Rev 1)](http://redump.org/disc/8357/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Resident Evil 3: The Last Escape (Spain)](http://redump.org/disc/1387/) | None | - | - |
| [Resident Evil 3: The Last Escape (USA) (Demo)](http://redump.org/disc/7312/) | [APv2](#apv2) | On the disclaimer screen after the game boots. | YES |
| [Resident Evil 3: The Last Escape (USA)](http://redump.org/disc/126/) | None | - | - |
| [Resident Evil: Survivor (Europe)](http://redump.org/disc/801/) | [APv2](#apv2) | Boot. | YES |
| [Resident Evil: Survivor (France)](http://redump.org/disc/5826/) | [APv2](#apv2) | Boot. | YES |
| [Resident Evil: Survivor (Japan)](http://redump.org/disc/8102/) | [APv2](#apv2) | Boot. | YES |
| [Resident Evil: Survivor (USA)](http://redump.org/disc/326/) | [APv2](#apv2) | Boot. | YES |
| [Robbit mon Dieu (Japan)](http://redump.org/disc/7227/) | [APv2](#apv2) | Boot. | YES |
| [Rockman 2: Dr. Wily no Nazo (Japan)](http://redump.org/disc/6092/) | [APv2](#apv2) | Boot. | YES |
| [Rockman 3: Dr. Wily no Saigo!? (Japan)](http://redump.org/disc/6093/) | [APv2](#apv2) | Boot. | YES |
| [Rockman 4: Aratanaru Yabou!! (Japan)](http://redump.org/disc/6094/) | [APv2](#apv2) | Boot. | YES |
| [Rockman 5: Blues no Wana!? (Japan)](http://redump.org/disc/6095/) | [APv2](#apv2) | Boot. | YES |
| [Rockman 6 (Japan)](http://redump.org/disc/6096/) | [APv2](#apv2) | Boot. | YES |
| [Rockman (Japan)](http://redump.org/disc/6091/) | [APv2](#apv2) | Boot. | YES |
| [Rockman X5 (Japan)](http://redump.org/disc/4779/) | [APv2](#apv2) | Boot. | YES |
| [Rockman X6 (Japan)](http://redump.org/disc/4778/) | [APv2](#apv2) | Boot. | YES |
| [Roger Lemerre: La Sélection des Champions 2002 (France)](http://redump.org/disc/49266/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Ronaldo V-Football (Europe) (De,Es,It,Pt)](http://redump.org/disc/7755)
| [Ronaldo V-Football (Europe) (En,Fr,Nl,Sv)](http://redump.org/disc/17746/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [SaGa Frontier 2 (Europe)](http://redump.org/disc/280/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [SaGa Frontier 2 (France)](http://redump.org/disc/28278/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [SaGa Frontier 2 (Germany)](http://redump.org/disc/2605/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [SaGa Frontier II (Japan)](http://redump.org/disc/1605/) | [APv1](#apv1) | Boot. | YES |
| [SaGa Frontier II (USA)](http://redump.org/disc/1535/) | None | - | - |
| [Saru! Get You!/Ape Escape (Europe) (Demo)](http://redump.org/disc/995/) | None | - | - |
| [Saru! Get You!/Ape Escape (Europe)](http://redump.org/disc/6147/) | [LibCrypt](#libcrypt) | Controller does not work at main menu. | No, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Saru! Get You!/Ape Escape (France)](http://redump.org/disc/28260/) | None | - | - |
| [Saru! Get You!/Ape Escape (Germany)](http://redump.org/disc/26604/) | None | - | - |
| [Saru! Get You!/Ape Escape (Italy)](http://redump.org/disc/27680/) | None | - | - |
| [Saru! Get You!/Ape Escape (Japan) (Demo)](http://redump.org/disc/5668/) | [APv1](#apv1) | Boot. | YES |
| [Saru! Get You!/Ape Escape (Japan) (Rev 0)](http://redump.org/disc/17061/) | [APv1](#apv1) | Boot. | YES |
| [Saru! Get You!/Ape Escape (Japan) (Rev 1)](http://redump.org/disc/17062/) | [APv1](#apv1) | Boot. | YES |
| [Saru! Get You!/Ape Escape (USA) (Demo 1)](http://redump.org/disc/49055/) | None | - | - |
| [Saru! Get You!/Ape Escape (USA) (Demo 2)](http://redump.org/disc/12309/) | None | - | - |
| [Saru! Get You!/Ape Escape (USA) (Demo Toys R US)](http://redump.org/disc/50386/) | None | - | - |
| [Saru! Get You!/Ape Escape (USA)](http://redump.org/disc/3086/) | None | - | - |
| [Shiritsu Justice Gakuen: Nekketsu Seishun Nikki 2 (Japan)](http://redump.org/disc/33493/) | [APv1](#apv1) | After title screen, first loading screen. | YES |
| [Silent Hill (Japan) (Demo)](http://redump.org/disc/33473/) | None | - | - |
| [Silent Hill (Japan) (Rev 0)](http://redump.org/disc/134/) | [APv1](#apv1) | Boot. | YES |
| [Silent Hill (Japan) (Rev 1)](http://redump.org/disc/82898/) | [APv1](#apv1) | Boot. | YES |
| [Silent Hill (Japan) (Rev 2)](http://redump.org/disc/18251/) | [APv1](#apv1) | Boot. | YES |
| [SnoCross Championship Racing (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/3705/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Space Debris (Europe)](http://redump.org/disc/29918/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Space Debris (France)](http://redump.org/disc/29512/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Space Debris (Germany) (Beta 11/11/1999)](http://redump.org/disc/85814/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Space Debris (Germany)](http://redump.org/disc/20213/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Space Debris (Italy)](http://redump.org/disc/29592/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Space Debris (Spain)](http://redump.org/disc/48046/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Speed Freaks (Europe)](http://redump.org/disc/1250/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Spyro 2: Gateway to Glimmer (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/1250/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Spyro The Dragon (Japan) (Demo)](http://redump.org/disc/68768/) | [APv1](#apv1) | Immediately after the universal logo. | YES |
| [Spyro The Dragon (Japan)](http://redump.org/disc/42739/) | [APv1](#apv1) |Immediately after the universal logo. | YES |
| [Spyro The Dragon (Japan) (Shokai Genteiban)](http://redump.org/disc/11432/) | [APv1](#apv1) | Immediately after the universal logo. | YES |
| [Spyro: Year of the Dragon (Europe) (En,Fr,De,Es,It) (Rev 0)](http://redump.org/disc/492/) | [LibCrypt](#libcrypt) | Insomniac screen before start menu. | No, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). **NOTE: DO NOT USE THE GAMESHARK CODE FEATURE OF TONYHAX INTERNATIONAL WITH THIS DISC or the anti-tamper protection will trigger.** |
| [Spyro: Year of the Dragon (Europe) (En,Fr,De,Es,It) (Rev 1)](http://redump.org/disc/19611/) | [LibCrypt](#libcrypt) | Insomniac screen before start menu. | No, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). **NOTE: DO NOT USE THE GAMESHARK CODE FEATURE OF TONYHAX INTERNATIONAL WITH THIS DISC or the anti-tamper protection will trigger.** |
| [Spyro: Year of the Dragon (USA) (Demo)](http://redump.org/disc/49449/) | None | - | - |
| [Spyro: Year of the Dragon (USA) (Rev 0)](http://redump.org/disc/818/) | [APv2](#apv2) | Insomniac screen before start menu. |  YES. **NOTE: DO NOT USE THE GAMESHARK CODE FEATURE OF TONYHAX INTERNATIONAL WITH THIS DISC or the anti-tamper protection will trigger.** There is also a ~15 second pause before the start menu appears, be patient and the game will unfreeze and work as intended! The protection is completely disabled by Tonyhax International so no issues will happen when playing. |
| [Spyro: Year of the Dragon (USA) (Rev 1)](http://redump.org/disc/1217/) | [APv2](#apv2) | Insomniac screen before start menu. | YES. **NOTE: DO NOT USE THE GAMESHARK CODE FEATURE OF TONYHAX INTERNATIONAL WITH THIS DISC or the anti-tamper protection will trigger.** There is also a ~15 second pause before the start menu appears, be patient and the game will unfreeze and work as intended! The protection is completely disabled by Tonyhax International so no issues will happen when playing. |
| [Street Fighter EX2 Plus (Europe)](http://redump.org/disc/1006/) | None | - | - |
| [Street Fighter EX2 Plus (Japan) (Demo)](http://redump.org/disc/68873/) | [APv2](#apv2) | Boot. | YES |
| [Street Fighter EX2 Plus (Japan)](http://redump.org/disc/12561/) | [APv2](#apv2) | Boot. | YES |
| [Street Fighter EX2 Plus (USA)](http://redump.org/disc/1233/) | None | - | - |
| [Strider 2 (Europe)](http://redump.org/disc/3917/) | None | - | - |
| [Strider 2 (USA)](http://redump.org/disc/1231/) | [APv2](#apv2) | Boot. | YES |
| [Sydney 2000 (Australia)](http://redump.org/disc/62664/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Sydney 2000 (Europe)](http://redump.org/disc/7460/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Sydney 2000 (France)](http://redump.org/disc/15759/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Sydney 2000 (Germany)](http://redump.org/disc/15759/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Sydney 2000 (Spain)](http://redump.org/disc/27884/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TechnoMage: De Terugkeer der Eeuwigheid (Netherlands)](http://redump.org/disc/27310/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TechnoMage: Die Rueckkehr der Ewigkeit (Germany)](http://redump.org/disc/25284/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Technomage: El Retorno de la Eternidad (Spain)](http://redump.org/disc/49569/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TechnoMage: En Quete de L'Eternite (France)](http://redump.org/disc/27310/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TechnoMage: Return of Eternity (Europe)](http://redump.org/disc/12627/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TechnoMage: Ritorno all'Eternità (Italy)](http://redump.org/disc/46130/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [The F.A. Premier League Football Manager 2001 (Europe)](http://redump.org/disc/6867/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [The Italian Job (Europe) (Fr,De,Es)](http://redump.org/disc/5819/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [The Italian Job (Europe)](http://redump.org/disc/617/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [The Italian Job (Italy)](http://redump.org/disc/47605/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Theme Park World (Europe) (En,Fr,De,Es,It,Nl,Sv)](http://redump.org/disc/910/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [This Is Football (Europe) (Fr,Nl)](http://redump.org/disc/19757/) | [LibCrypt](#libcrypt) | After starting a game with two teams selected the loading bar gets stuck at approximately 80-85%. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [This Is Football (Europe)](http://redump.org/disc/4004/) | [LibCrypt](#libcrypt) | After starting a game with two teams selected the loading bar gets stuck at approximately 80-85%. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [This Is Football (Italy)](http://redump.org/disc/28048/) | [LibCrypt](#libcrypt) | After starting a game with two teams selected the loading bar gets stuck at approximately 80-85%. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [This Is Soccer (Australia)](http://redump.org/disc/46676/) | [LibCrypt](#libcrypt) | After starting a game with two teams selected the loading bar gets stuck at approximately 80-85%. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TOCA World Touring Cars (Europe) (En,Fr,De)](http://redump.org/disc/615/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [TOCA World Touring Cars (Europe) (Es,It)](http://redump.org/disc/27567/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 1) (Minadzuki - Kotobuki - Sakura) (Japan)](http://redump.org/disc/53927/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 2) (Akai - Ichimonji - Yae) (Japan)](http://redump.org/disc/53945/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 Emotional Voice System Append Disc (Disc 3) (Shirayuki - Ijuin - Nozaki) (Japan)](http://redump.org/disc/53946/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Limited Box) (Disc 1)](http://redump.org/disc/67613/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Limited Box) (Disc 2)](http://redump.org/disc/67614/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Limited Box) (Disc 3)](http://redump.org/disc/67615/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Limited Box) (Disc 4)](http://redump.org/disc/67616/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Limited Box) (Disc 5)](http://redump.org/disc/67617/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 0) (Disc 1)](http://redump.org/disc/10670/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 0) (Disc 2)](http://redump.org/disc/10671/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 0) (Disc 3)](http://redump.org/disc/10672/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 0) (Disc 4)](http://redump.org/disc/10673/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 0) (Disc 5)](http://redump.org/disc/10674/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 1) (Disc 1)](http://redump.org/disc/24175/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 1) (Disc 2)](http://redump.org/disc/24177/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 1) (Disc 3)](http://redump.org/disc/24178/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 1) (Disc 4)](http://redump.org/disc/24179/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial 2 (Japan) (Rev 1) (Disc 5)](http://redump.org/disc/24176/) | [APv2](#apv2) | Boot. | YES |
| [Tokimeki Memorial Drama Series Vol. 3: Tabidachi no Uta (Japan) (Disc 1)](http://redump.org/disc/29081/) | [APv1](#apv1) | Press start on title screen and go through it, happens right before you name the character. | YES |
| [Tokimeki Memorial Drama Series Vol. 3: Tabidachi no Uta (Japan) (Disc 2)](http://redump.org/disc/29082/) | [APv1](#apv1) | Press start on title screen and go through it, happens right before you name the character. | YES |
| [Tomba! 2: The Evil Swine Return (USA) (Demo)](http://redump.org/disc/16475/) | None | - | - |
| [Tomba! 2: The Evil Swine Return (USA)](http://redump.org/disc/16475/) | [APv2](#apv2) | Boot. | YES |
| [Tomba! The Wild Adventures (Japan) (Demo)](http://redump.org/disc/41762/) | None | - | - |
| [Tomba! The Wild Adventures (Japan) ](http://redump.org/disc/38533/) | None | - | - |
| [Tombi! 2: Contra los Cerdiablos (Spain)](http://redump.org/disc/1582/) | None | - | - |
| [Tombi! 2 (Europe)](http://redump.org/disc/31192/) | None | - | - |
| [Tombi! 2 (France)](http://redump.org/disc/13403/) | None | - | - |
| [Tombi! 2 (Germany)](http://redump.org/disc/25235/) | None | - | - |
| [Tombi! 2 (Italy)](http://redump.org/disc/41369/) | None | - | - |
| [Tron ni Kobun (Japan) ](http://redump.org/disc/10765/) | [APv2](#apv2) | Before first now loading screen. | YES |
| [UEFA Euro 2000 (Europe)](http://redump.org/disc/1793/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [UEFA Euro 2000 (France)](http://redump.org/disc/28153/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [UEFA Euro 2000 (Germany)](http://redump.org/disc/5528/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [UEFA Euro 2000 (Italy)](http://redump.org/disc/28346/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [UEFA Euro 2000 (Spain)](http://redump.org/disc/50591/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [UEFA Striker (Europe) (En,Fr,De,Es,It,Nl)](http://redump.org/disc/7446/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Um Jammer Lammy (Europe)](http://redump.org/disc/5510/) | [APv1](#apv1) | After `Sony Computer Entertainment Presents` screen. | YES |
| [Um Jammer Lammy (Japan)](http://redump.org/disc/3582/) | [APv1](#apv1) |  After `Sony Computer Entertainment Presents` screen. | YES |
| [Um Jammer Lammy (Japan) (Tentou Houei-you)](http://redump.org/disc/97015/) | None | - | - |
| [Um Jammer Lammy (USA) (Demo)](http://redump.org/disc/10990/) | [APv1](#apv1) |  After `Sony Computer Entertainment Presents` screen. | YES |
| [Um Jammer Lammy (USA)](http://redump.org/disc/1399/) | None | - | - |
| [Urban Chaos (Europe) (En,Es,It)](http://redump.org/disc/618/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Urban Chaos (France)](http://redump.org/disc/50247/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Urban Chaos (Germany)](http://redump.org/disc/17768/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Vagrant Story (Europe)](http://redump.org/disc/9978/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Vagrant Story (France)](http://redump.org/disc/12636/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Vagrant Story (Germany)](http://redump.org/disc/548/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Vandal Harts II  (Europe)](http://redump.org/disc/4854/) | None | - | - |
| [Vandal Harts II  (Italy)](http://redump.org/disc/4854/) | None | - | - |
| [Vandal Harts II  (Spain)](http://redump.org/disc/4854/) | None | - | - |
| [Vandal Harts II: Tenjou no Mon (Japan)](http://redump.org/disc/4854/) | [APv1](#apv1) | Boot. | YES |
| [Vandal Harts II (USA)](http://redump.org/disc/1550/) | [APv2](#apv2) | Boot. | YES |
| [V-Rally: Championship Edition 2 (Europe) (En,Fr,De)](http://redump.org/disc/1063/) | [LibCrypt](#libcrypt) | After choosing your car and game mode, the game will permanently get stuck on the loading screen with the ECG patterns and heartbeats played consistently. | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Walt Disney World Quest: Magical Racing Tour (Europe) (En,Fr,De,Es,It,Nl,Sv,No,Da)](http://redump.org/disc/1848/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [Wild Arms II (Japan) (Demo 1)](http://redump.org/disc/4799/) | [APv1](#apv1) | `MEDIAVISION` logo after Boot. | YES |
| [Wild Arms II (Japan) (Demo 2)](http://redump.org/disc/74502/) | [APv1](#apv1) | `MEDIAVISION` logo after Boot. | YES |
| [Wild Arms II (Japan) (Rev 0) (Disc 1)](http://redump.org/disc/3924/) | [APv1](#apv1) | `MEDIAVISION` logo after Boot. | YES |
| [Wild Arms II (Japan) (Rev 0) (Disc 2)](http://redump.org/disc/3925/) | [APv1](#apv1) | `MEDIAVISION` logo after Boot. | YES |
| [Wild Arms II (USA) (Demo)](http://redump.org/disc/42466/) | [APv2](#apv2) | `MEDIAVISION` logo after Boot. | YES |
| [Wild Arms II (USA) (Disc 1)](http://redump.org/disc/171/) | [APv2](#apv2) | `MEDIAVISION` logo after Boot. | YES |
| [Wild Arms II (USA) (Disc 2)](http://redump.org/disc/172/) | [APv2](#apv2) | `MEDIAVISION` logo after Boot. | YES |
| [Wip3out (Europe) (En,Fr,De,Es,It)](http://redump.org/disc/355/) | [LibCrypt](#libcrypt) | Unknown | NO, patch disc with [LibCrypt patcher](https://alex-free.github.io/libcrypt-patcher). |
| [World Soccer Jikkyou Winning Eleven 4 (Japan) (Rev 0)](http://redump.org/disc/4934/) | [APv2](#apv2) | As soon as the Japan Olympic Committee screen appears. | YES |
| [World Soccer Jikkyou Winning Eleven 4 (Japan) (Rev 1)](http://redump.org/disc/6889/) | [APv2](#apv2) | As soon as the Japan Olympic Committee screen appears. | YES |
| [XI[SAI] Jumbo (Japan)](http://redump.org/disc/8372/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (Europe)](http://redump.org/disc/1053/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (France)](http://redump.org/disc/28263/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (Germany)](http://redump.org/disc/1256/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (Italy)](http://redump.org/disc/35297/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (Japan) (Genteiban)](http://redump.org/disc/51546/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (Japan)](http://redump.org/disc/4173/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (Spain)](http://redump.org/disc/30673/) | [APv2](#apv2) | Boot. | YES |
| [Yu-Gi-Oh! Forbidden Memories (USA)](http://redump.org/disc/820/) | [APv2](#apv2) | Boot. | YES |

## Protection Types

*   [APv1](#apv1)
*   [APv2](#apv2)
*   [EDC](#apv1)
*   [PAL Bios Detection](#pal-bios-detection)
*   [LibCrypt](#libcrypt)
*   [KeyDisc/Append Disc](#key-discappend-disc)

### APv1

_Info:_ The very first kind of 'standardized' additional copy protection that appeared in later PSX games. It is found in all regions. The _APv1 style protection can only prevent a backup CD-R of a game from working on a console that has a 'non-stealth mod-chip' installed_. APv1 style protection can not detect games booted with Tonyhax International on a stock console without a _non-stealth_ mod-chip. 

_Found In:_ Japanese, USA, and PAL games.

_Support In Tonyhax International:_ bypasses this protection in every known game containing it.

Without a bypass, this protection triggers an 'anti-piracy screen of death':

![poporogue japan rev 0 apv1 triggered](images/poporogue-japan-non-stealth-mod-chip-apv1-triggered.png)

### APv2

_Info:_ Unlike APv1, APv2 detects both soft-mods and non-stealth mod-chips. It is found in all regions. It is the only protection besides EDC ever implemented for USA releases. Very early SCPH-3000 Japanese consoles, and all SCPH-1000 Japanese consoles are immune to tripping APv2 as long as they are not containing a 'non-stealth' mod-chip. These consoles will work with every APv2 game without a bypass even being needed. Bypasses are still needed for `non-stealth mod-chip` SCPH-1000 and early SCPH-3000s which is why the bypasses are still enabled for those models.

_Found In:_ Japanese, USA, and PAL games.

_Support In Tonyhax International:_ yes, bypasses this protection in every known game containing it.

_Effect:_ this protection triggers an 'anti-piracy screen of death':

![dino crisis usa rev 0 apv2 triggered](images/dino-crisis-usa-rev-0-non-stealth-mod-chip-apv2-triggered.png)

![spyro year of the dragon usa rev 0 apv2 triggered](images/spyro-year-of-the-dragon-usa-rev-0-non-stealth-mod-chip-apv2-triggered.png)

### EDC

_Info:_ Some games may contain an EDC-based protection measure. For the affected games, this protection is triggered when you burn the EDC protected PSX CD image with standard CD burning software (like IMGBurn) that forces invalid EDC data to be corrected before writing it the disc. If valid EDC is found where an invalid EDC was expected, then when played on a real PSX will cause the game to trip the protection and lock up. Emulators usually ignore EDC/EEC entirely, so they do not trigger the protection.

_Found In:_ Japanese, USA, and PAL games.

_Bypass support in Tonyhax International Status:_ yes. However most games don't have a bypass yet. For such games, you can follow my [Ultimate Guide To PSX CD-Rs](https://alex-free.github.io/psx-cdr#burning-software) for an example on how to burn a disc which defeats the protection with CDRDAO. Using Alchol 120% or Clone CD can also be done as long as you ignore EDC/EEC errors when burning in RAW DAO mode. Basically, burn the games with SafeDisc 1 type settings, as this is basically the same protection/detection scheme.

_Effect:_ Locks up.

### PAL BIOS Detection

_Info:_ Some games are detecting a PAL BIOS and disabling all anti-piracy protections. On the flipside, some games are detecting a PAL BIOS and locking up as an additional protection.

_Found In:_ Japanese games.

_Bypass support in Tonyhax International Status:_ bypasses this protection in every known game containing it.

_Effect:_ Locks up.

### LibCrypt

_Info:_ Some PAL PSX games are using a different copy protection scheme known as LibCrypt protection. Similar to EDC protection, LibCrypt protection is triggered when you burn a LibCrypt protected PSX CD image with standard CD burning software, which in most cases 'helpfully corrects' the SubChannel data when burning such a protected PSX CD image.

_Found In:_ PAL games.

_Bypass support in Tonyhax International:_ No. LibCrypt protection can be bypassed entirely by ripping the disc image, patching it with the [LibCrypt Patcher](https://alex-free.github.io/libcrypt-patcher), and then burning the patched disc image to a CD-R using any burning software.

_Effect:_ Various.

### Key Disc/Append Disc

_Found In:_ Japanese games.

_About:_ Some games were released as essentially a DLC expansion pack. The way this works is a specific [Key Disc](https://remywiki.com/KEY_DISC) is booted first. The Key Disc has the ability to boot specific [Append Discs](https://remywiki.com/APPEND_DISC) with a built-in disc change feature that runs a bunch of protection code.

_Bypass support in Tonyhax International:_ limited. Currently, only one game is fully bypassed, Beat Mania Append: GottaMix (Japan). The way to use the Tonyhax International bypass for it is to simply use Tonyhax International as the Key Disc. Boot Beat Mania Append: GottaMix (Japan) directly from Tonyhax International for it to work.

There are 2 other games with partial bypasses in Tonyhax International, they are Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1 (Japan) and Dance Dance Revolution 2nd Remix: Append Club Version Vol. 1 (Japan). They both are fully bypassed for all USA and PAL consoles. Japanese consoles only work if they have a mod-chip (including non-stealth which would normally trigger the protection). Unmodified Japanese consoles are the only ones not yet supported by the bypass for these specific games in Tonyhax International. 

_Effect:_ Anti-Piracy Screen of Death or locks up.

