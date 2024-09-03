# [Tonyhax International](readme.md) -> Credits

## [MottZilla](https://github.com/danhans42/tonyhax_mcp)

* Help with the custom anti-piracy bypasses for Koneko mo Issho and i-mode mo Issho: Doko Demo Issho Tsuika Disc.

* Co-developed the 'fake PAL BIOS bypass' method for APv2 bypasses.

* Guidance on increasing the size of the Tonyhax International loader and my general goto mentor on this project.

* Co-developed the Spyro Year Of The Dragon GameShark code bypass method.

* Wrote the GameShark Code Engine, used first in the APv2 bypass system. With MottZilla's guidance this code has even been expanded and adapted for general use [GameShark Code Support](gameshark-code.md).

* The original sole creator of [PS1 DemoSwap Patcher v1.0](https://www.psx-place.com/threads/mctool-tonyhax-freepsxboot-installer.36569). MottZilla re-implemented the TOCPerfect concept into a much superior method, and included his implementation alongside of his DemoSwap idea in PS1 DemoSwap Patcher.

* Wrote the controller input support for Tonyhax International.

* Wrote the laser re-calibration function for VC2 and VC3 CDROM controllers.

* Developed the first Japanese save game exploit for Crash Bandicoot 2.

* Developed the PS-EXE loader used on GameShark/cheat cartridges to run Tonyhax International.

* Came up with reset+unlock technique for TOCPerfect booting on USA/PAL consoles.

* Originally came up with the idea to involve the SetSession 2 command in a fix for the older CDROM controllers which resulted in the eventual discovery of the SetSessionSuperUltraCommandSmash v2.

* Explained the save game checksum routines in both Tony Hawk Pro Skater 2 (Japanese version) & Castrol Honda VTR (Japanese version) to help me create SuccessCheckSumUpdater (SuccessCU).

* Explained to myself how to find/port save game exploits to new games or to different versions of games available in different regions (i.e. Japanese version).

## [Patchouli(karehaani)](https://www.psxdev.net/forum/memberlist.php?mode=viewprofile&u=6714)

* Doki Oki (Japan) save game exploit.

* Crash Bandicoot 3 (Japan) save game exploit.

* The Lengend Of Heroes I&II (Japan) save game exploit.

* Tekken 3 Japan/USA/PAL save game exploits (based off of previous work by [krystalgamer](https://github.com/socram8888/tonyhax/pull/20)).

* Tekken 2 Japan (rev 1 only)/USA (rev 0 only)/PAL save game exploits (based off of previous work by [krystalgamer](https://github.com/socram8888/tonyhax/pull/20)).

* Downhill Snow (Japan) save game exploit.

* Final Fantasy IX (Japan and USA) save game exploit.

## [SylverReZ (M4x1mumReZ)](https://gbatemp.net/members/sylverrez.610331/)

* Generated Aprip codes for APv2 bypasses for i-mode mo Issho: Doko Demo Issho Tsuika Disc, Koko Hore! Pukka, Love Hina: Ai wa Kotoba no Naka ni / Love Hina 2: Kotoba wa Konayuki no You ni, Pocket Jiman.

## [Nicholas Noble](https://github.com/nicolasnoble)

* Wrote PS1 Packer and released it as an easy to use [submodule](https://github.com/pcsx-redux/support). Helped implement it for the memory card boot methods.

* Corrected the CD_REGS value in `loader/cdrom.c` to use the right memory region.

* Came up with the best `cdrom:\\` text stripper for `CdGetLbn()` in `loader/secondary.c`

## [DanHans42](https://github.com/danhans42/)

* Wrote the initial implementation of the GameID Memcard Pro/SD2PSX/pico memcard support for his [fork](https://github.com/danhans42/tonyhax_mcp) of the o[riginal Tonyhax](https://github.com/danhans42/tonyhax_mcp). This was easy to adapt, expand, and improve into Tonyhax International.

## GameID

Tonyhax International implements the [protocol](https://gitlab.com/chriz2600/ps1-game-id-transmission) utilising the [Cybdyn MemCardPro library/code](https://github.com/Cybdyn-Systems/MemCardPro-ASM), which is releasd under these terms:

--Memcard Pro Library Licence Notice--

MemCard Pro Library
Copyright (C) 2021-2024 Cybdyn Systems. All Rights Reserved.
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

## Misc Acknowledgements

* [Berion](https://www.psx-place.com/members/berion.1431/) of [PSX-Place](https://psx-place.com) compressed the images of this document properly (this is the first time I've edited photos).

* Martin Korth for confirming the SetSession bug found in VC0A, VC0B, and VC1A CDROM controller BIOS versions, and for the priceless [PSX-SPX](http://problemkaputt.de/psx-spx.htm) document.

* [Peppe90](https://www.psx-place.com/members/peppe90.42412/) of [PSX-Place](https://psx-place.com) for testing NTSC gamems on a PAL PS2. His results have confirmed that the video mode can not be changed from PS1 software in PS1 mode on a PS1. It must be changed in PS1DRV from the PS2, as PS1 mode is set to always display the same video mode that the console shipped with (for the early PS2s that Tonyhax International supports). He mentioned that PS1VModeNeg v1.0.1 can be used to overcome this. The original Tonyhax [issue](https://github.com/socram8888/tonyhax/issues/25) explaining this also was helpful in figuring out how to bypass this PS2 level limitation.

* **Everyone else who tested, reported issues, or otherwise contributed to making Tonyhax International better!**

## O.G. Tonyhax Acknowledgements

[Socram8888](https://github.com/socram8888) is the original developer of the Tonyhax loader. The original Tonyhax loader credits are below, in alphabetical order:

* Alex Free for adding the boot CD image.

* ChampionLeake for documenting the Brunswick exploits at PlayStation dev wiki.

* Gerardo Rodriguez for suggesting Cool Boarders 4 on a YouTube comment.

* @FMecha for suggesting Castrol Honda VTR on Twitter.

* John Wilbert Villamor (aka Lameguy64) for creating mkpsxiso.

* Jose Silva for adding support for Sports Superbike II and XS Moto.

* Martin Korth for his super awesome technical documentation page that was vital for the development of this project, as well as for developing the no$psx emulator that was also essential for debugging.

* Patrick Vogt for testing on multiple development PS1 consoles.

* Everyone that's reported the issues on GitHub and helped Socram8888 make it better.
