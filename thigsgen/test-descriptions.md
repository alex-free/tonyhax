# Test Descriptions

In this `gameshark` folder are various test-x.txt files which contain different sorts of codes for testing out the GameShark code functionality.

## test-1.txt

Game: [Rockman 2: Dr. Wily no Nazo](http://redump.org/disc/6092/) (Japan)
Codes: [Unlock All Extras](https://gamehacking.org/game/108274)
Tests: `50/80 pair`, `50/80 pair`
Functionality: Unlocks all database, modes, options, etc.

## test-2.txt

Game: [Parasite Eve (Disc 1)](http://redump.org/disc/116/) (USA)
Codes: [Warp To Debug Room](https://gamehacking.org/game/89569)
Tests: `D0/80 pair`, `D0/30 pair`
Functionality: Hit the `R2` + `L2` buttons at the same time while you can move Aya to warp to the debug room.

## test-3.txt

Game: [Duke Nukem: Total Meltdown](http://redump.org/disc/10812/)
Codes: [Hold Triangle To Moon Jump](https://gamehacking.org/game/88772)
Tests: `E0/80 pair`, `E0/80 pair`
Functionality: Press `R2` to jump. **IMMEDIATELY let go of R2 and while in mid-air without holding R2 hold the triangle button only**. You can move around with the joysticks just fine.

## test-4.txt

Game: [Parasite Eve II (Disc 1)](http://redump.org/disc/116/) (USA)
Codes: [All Parasite Abilities & They Are At LVL.3 Power](https://gamehacking.org/game/89569)
Tests: `50/30 pair`
Functionality: All parasite abilities enabled at level 3 power.

## test-5.txt

Game: [Herc's Adventures](http://redump.org/disc/19252/) (USA)
Codes: [Have All Items Set One](https://gamehacking.org/game/88957), [Have All Items Set Two](https://gamehacking.org/game/88957), [P1 Infinite Health](https://gamehacking.org/game/88957)
Tests: `80`
Functionality: All items and infinite health for player 1.

## test-6.txt

Game: [Parasite Eve (Disc 1)](http://redump.org/disc/116/) (USA)
Codes: [Outfit Modifier](https://gamehacking.org/game/89569)
Tests: `30`
Functionality: Changes Aya to always wear the dress. **NOTE** this code is buggy when Aya is performing actions like opening doors, etc. This buggy-ness *IS* expected from this code, it is reproducible using DuckStation's own native code support and GameShark Lite on real hardware. This is **NOT** an issue with the gameshark cheat engine used by Tonyhax International and just a GameShark code flaw.

## test-7.txt

Game: [Resident Evil: Director's Cut: Dual Shock Ver.](http://redump.org/disc/125/) (USA)
Codes: This is a code I made which only proves the observable behavior of this code type is correctly handled.
Tests: `E2/30 pair`
Functionality: At 8005D280 there is a 0x60 byte at least while the game starts up at the 'This game contains explicit scenes of violence and gore' disclaimer. **The code will change that 0x60 byte to 0x01 since it is lower then the comparison byte 0x61.**

## test-8.txt

Game: [Resident Evil: Director's Cut: Dual Shock Ver.](http://redump.org/disc/125/) (USA)
Codes: This is a code I made which only proves the observable behavior of this code type is correctly handled.
Tests: `E2/30 pair`
Functionality: At 8005D280 there is a 0x60 byte at least while the game starts up at the 'This game contains explicit scenes of violence and gore' disclaimer. **The code will not change that 0x60 byte to 0x01 since it is not lower then the comparison byte 0x60 (it is equal).**

## test-9.txt

Game: [Resident Evil: Director's Cut: Dual Shock Ver.](http://redump.org/disc/125/) (USA)
Codes: This is a code I made which only proves the observable behavior of this code type is correctly handled.
Tests: `E3/30 pair`
Functionality: At 8005D280 there is a 0x60 byte at least while the game starts up at the 'This game contains explicit scenes of violence and gore' disclaimer. **The code will change that 0x60 byte to 0x01 since it is higher then the comparison byte 0x59.**

## test-10.txt

Game: [Resident Evil: Director's Cut: Dual Shock Ver.](http://redump.org/disc/125/) (USA)
Codes: This is a code I made which only proves the observable behavior of this code type is correctly handled.
Tests: `E3/30 pair`
Functionality: At 8005D280 there is a 0x60 byte at least while the game starts up at the 'This game contains explicit scenes of violence and gore' disclaimer. **The code will not change that 0x60 byte to 0x01 since it is not higher then the comparison byte 0x60 (it is equal).**

## test-11.txt

Game: [Resident Evil: Director's Cut: Dual Shock Ver.](http://redump.org/disc/125/) (USA)
Codes: This is a code I made which only proves the observable behavior of this code type is correctly handled.
Tests: `D2/80 pair`
Functionality: At 8005D280 there is a 0x60 byte, at 8005D281 there is a 0x28 byte at least while the game starts up at the 'This game contains explicit scenes of violence and gore' disclaimer. **The code will change the 0x60 and 0x28 bytes to 0x01 0x02 since it is lower then the comparison bytes 0x61 and 0x29.**

## test-12.txt

Game: [Resident Evil: Director's Cut: Dual Shock Ver.](http://redump.org/disc/125/) (USA)
Codes: This is a code I made which only proves the observable behavior of this code type is correctly handled.
Tests: `D2/80 pair`
Functionality: At 8005D280 there is a 0x60 byte, at 8005D281 there is a 0x28 byte at least while the game starts up at the 'This game contains explicit scenes of violence and gore' disclaimer. **The code will not change the 0x60 and 0x28 bytes to 0x01 0x02 since it is not lower then the comparison bytes 0x60 and 0x28 (it is equal).**