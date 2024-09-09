#include "str.h"

const char * get_psx_exe_gameid(const unsigned char volume_creation_timestamp[17])
 {
           /*
            Special handling for PSX.EXE games with memcardpro. We have 2 lists: 
            * http://redump.org/discs/quicksearch/PSX.EXE/comments/only
            * http://redump.org/discs/quicksearch/PSXEXE/comments/only

            
            There are some false positives in the above 2 lists due to how redump search works/how they were listed. There are also some discs not listed that do have PSX.EXE. In addition ONLY officially licensed discs with PSX.EXE are supported. Beta and unlicensed discs are ignored (due to lacking a serial designation and to save exe space).

            ======================================================================
            Implementation Notes:

            WE DO NOT WANT TO DEPEND ON THE ABILITY TO LOAD THE ENTIRE PSX.EXE INTO RAM. As Tonyhax International gets larger we can't guarantee every PSX.EXE executable will fit into the RAM lower then Tonyhax International before we call do_execute(), sometimes we may need to load_and_exec() which means we can't depend on having the PSX.EXE in memory to check anything.

            Failed attempts to ID PSX.EXE games:

            1) CRC32 sector 16. This is great, but if you rebuild/modify the game with i.e. mkpsxiso you get a different checksum we can't possibly know, and fail the match.
            
            2) CRC32 sector 16 up to 0x48. The includes the Volume Identifier. This would probably even work with  mkpsxiso rebuilt disc images, BUT some ridiculous games such as http://redump.org/disc/21858/ have no identifiable information even here. Even the Volume Identifier at 0x28 is SPACES FOR THAT GAME! WHY?!

            ======================================================================
            SUCCESSFUL IMPLEMENTATION FOUND: 
            
            Check the date of creation ;) at 0x32D (Volume Creation Timestamp). MKPSXISO keeps that the same on rebuild.
            
            From NO$PSX SPX: https://problemkaputt.de/psx-spx.htm#cdromisovolumedescriptors

            ======================================================================
            Primary Volume Descriptor (sector 16 on PSX disks)

            000h 1    Volume Descriptor Type        (01h=Primary Volume Descriptor)
            001h 5    Standard Identifier           ("CD001")
            006h 1    Volume Descriptor Version     (01h=Standard)
            007h 1    Reserved                      (00h)
            008h 32   System Identifier             (a-characters) ("PLAYSTATION")
            028h 32   Volume Identifier             (d-characters) (max 8 chars for PSX?)
            048h 8    Reserved                      (00h)
            050h 8    Volume Space Size             (2x32bit, number of logical blocks)
            058h 32   Reserved                      (00h)
            078h 4    Volume Set Size               (2x16bit) (usually 0001h)
            07Ch 4    Volume Sequence Number        (2x16bit) (usually 0001h)
            080h 4    Logical Block Size in Bytes   (2x16bit) (usually 0800h) (1 sector)
            084h 8    Path Table Size in Bytes      (2x32bit) (max 800h for PSX)
            08Ch 4    Path Table 1 Block Number     (32bit little-endian)
            090h 4    Path Table 2 Block Number     (32bit little-endian) (or 0=None)
            094h 4    Path Table 3 Block Number     (32bit big-endian)
            098h 4    Path Table 4 Block Number     (32bit big-endian) (or 0=None)
            09Ch 34   Root Directory Record         (see next chapter)
            0BEh 128  Volume Set Identifier         (d-characters) (usually empty)
            13Eh 128  Publisher Identifier          (a-characters) (company name)
            1BEh 128  Data Preparer Identifier      (a-characters) (empty or other)
            23Eh 128  Application Identifier        (a-characters) ("PLAYSTATION")
            2BEh 37   Copyright Filename            ("FILENAME.EXT;VER") (empty or text)
            2E3h 37   Abstract Filename             ("FILENAME.EXT;VER") (empty)
            308h 37   Bibliographic Filename        ("FILENAME.EXT;VER") (empty)
            32Dh 17   Volume Creation Timestamp     ("YYYYMMDDHHMMSSFF",timezone)
            33Eh 17   Volume Modification Timestamp ("0000000000000000",00h)
            34Fh 17   Volume Expiration Timestamp   ("0000000000000000",00h)
            360h 17   Volume Effective Timestamp    ("0000000000000000",00h)
            371h 1    File Structure Version        (01h=Standard)
            372h 1    Reserved for future           (00h-filled)
            373h 141  Application Use Area          (00h-filled for PSX and VCD)
            400h 8    CD-XA Identifying Signature   ("CD-XA001" for PSX and VCD)
            408h 2    CD-XA Flags (unknown purpose) (00h-filled for PSX and VCD)
            40Ah 8    CD-XA Startup Directory       (00h-filled for PSX and VCD)
            412h 8    CD-XA Reserved                (00h-filled for PSX and VCD)
            41Ah 345  Application Use Area          (00h-filled for PSX and VCD)
            573h 653  Reserved for future           (00h-filled)
            =============================================================================================
            Volume Descriptor Timestamps
            The various timestamps occupy 17 bytes each, in form of

            "YYYYMMDDHHMMSSFF",timezone
            "0000000000000000",00h         ;empty timestamp

            The first 16 bytes are ASCII Date and Time digits (Year, Month, Day, Hour, Minute, Second, and 1/100 Seconds. The last byte is Offset from Greenwich Mean Time in number of 15-minute steps from -48 (West) to +52 (East); or actually: to +56 when recursing Kiribati's new timezone.
            Note: PSX games manufactured in year 2000 were accidently marked to be created in year 0000.
            =============================================================================================
            */

            // Ordered by serial number.

            if(strcmp( (char *)volume_creation_timestamp, "1994111009000000") == 0) { // Ridge Racer (Japan) - http://redump.org/disc/2679/
                return "cdrom:SLPS_000.01;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/R/SLPS-00001.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994110702000000") == 0) { // Gokujou Parodius Da! Deluxe Pack (Japan) - http://redump.org/disc/5337/
                return "cdrom:SLPS_000.02;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00002.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994102615231700") == 0) { // Tama: Adventurous Ball in Giddy Labyrinth (Japan) - http://redump.org/disc/6980/
                return "cdrom:SLPS_000.03;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00003.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1994110218594700") == 0) || // A Ressha de Ikou 4: Evolution (Japan) (Rev 0) - http://redump.org/disc/21858/
            (strcmp( (char *)volume_creation_timestamp, "1995030218052000") == 0) // A Ressha de Ikou 4: Evolution (Japan) (Rev 1) - http://redump.org/disc/21858/
            ) {
                return "cdrom:SLPS_000.04;1"; // Serial from CD case. Uses 15 MC blocks - https://psxdatacenter.com/games/J/A/SLPS-00004.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1994110722360400") == 0) || // Mahjong Station Mazin (Japan) (Rev 0) - http://redump.org/disc/63533/
            (strcmp( (char *)volume_creation_timestamp, "1994120610494900") == 0) // Mahjong Station Mazin (Japan) (Rev 1) - http://redump.org/disc/10881/
            ) {
                return "cdrom:SLPS_000.05;1"; // Serial from CD case. Uses 1 MC blocks - https://psxdatacenter.com/games/J/M/SLPS-00005.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994110407000000") == 0) { // Nekketsu Oyako (Japan) - http://redump.org/disc/10088/
                return "cdrom:SLPS_000.06;1"; // Serial from CD case. Uses 1 MC block -https://psxdatacenter.com/games/J/N/SLPS-00006.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111419300000") == 0) { // Geom Cube (Japan) - http://redump.org/disc/14660/
                return "cdrom:SLPS_000.07;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00007.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994121808190700") == 0) { // Metal Jacket (Japan) - http://redump.org/disc/5927/
                return "cdrom:SLPS_000.08;1"; // Serial from CD case. Uses 2 MC blocks - https://psxdatacenter.com/games/J/M/SLPS-00008.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994121917000000") == 0) { // Cosmic Race (Japan) - http://redump.org/disc/16058/
                return "cdrom:SLPS_000.09;1"; // Serial from CD case. Uses 7 MC blocks - https://psxdatacenter.com/games/J/C/SLPS-00009.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995052918000000") == 0) { // Falcata: Astran Pardma no Monshou (Japan) - http://redump.org/disc/1682/
                return "cdrom:SLPS_000.10;1"; // Serial from CD case. Uses 4 MC blocks - https://psxdatacenter.com/games/J/F/SLPS-00010.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994110220020600") == 0) { // A Ressha de Ikou 4: Evolution (Japan) (Hatsubai Kinen Gentei Set) - http://redump.org/disc/70160/
                return "cdrom:SLPS_000.11;1"; // Serial from CD case. Uses 15 MC blocks - https://psxdatacenter.com/games/J/A/SLPS-00011.html
            } else if

            // SLPS_00012 (https://psxdatacenter.com/games/J/S/SLPS-00012.html) bootfile is START.EXE with a SYSTEM.CNF. This is the discs Space Griffon VF-9(Japan) (Rev 0) - http://redump.org/disc/5914/ and Space Griffon VF-9(Japan) (Rev 1) - http://redump.org/disc/45998/.

            (strcmp( (char *)volume_creation_timestamp, "1994121518000000") == 0) { // Raiden Project (Japan) - http://redump.org/disc/3774/
                return "cdrom:SLPS_000.13;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/R/SLPS-00013.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994103000000000") == 0) { // Mahjong Gokuu Tenjiku (Japan) - http://redump.org/disc/17392/
                return "cdrom:SLPS_000.14;1"; // Serial from CD case. Uses 4 MC blocks - https://psxdatacenter.com/games/J/M/SLPS-00014.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994101813262400") == 0) { // TwinBee Taisen Puzzle-dama (Japan) - http://redump.org/disc/22905/
                return "cdrom:SLPS_000.15;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00015.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1994112617300000") == 0) || // Jikkyou Powerful Pro Yakyuu '95 (Japan) (Rev 0) - http://redump.org/disc/9552/
            (strcmp( (char *)volume_creation_timestamp, "1994121517300000") == 0) // // Jikkyou Powerful Pro Yakyuu '95 (Japan) (Rev 1) - http://redump.org/disc/27931/
            ) {
                return "cdrom:SLPS_000.16;1"; // Serial from CD case. 3 MC blocks - https://psxdatacenter.com/games/J/J/SLPS-00016.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111013000000") == 0) { // King's Field (Japan) - http://redump.org/disc/7072/
                return "cdrom:SLPS_000.17;1"; // Serial from CD case. Uses 5 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00017.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111522183200") == 0) { // Twin Goddesses (Japan) - http://redump.org/disc/7885/.
                return "cdrom:SLPS_000.18;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00018.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994112918000000") == 0) { // Kakinoki Shougi (Japan) - http://redump.org/disc/22869/
                return "cdrom:SLPS_000.19;1"; // Serial from CD case. Uses 4 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00019.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994111721302100") == 0) { // Houma Hunter Lime: Special Collection Vol. 1 (Japan) - http://redump.org/disc/18606/
                return "cdrom:SLPS_000.20;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/H/SLPS-00020.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994100617242100") == 0) { // Kikuni Masahiko Jirushi: Warau Fukei-san Pachi-Slot Hunter (Japan) - http://redump.org/disc/33816/
                return "cdrom:SLPS_000.21;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00021.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995030215000000") == 0) { //Starblade Alpha (Japan) - http://redump.org/disc/4664/
                return "cdrom:SLPS_000.22;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/S/SLPS-00022.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994122718351900") == 0) { //CyberSled (Japan) - http://redump.org/disc/7879/
                return "cdrom:SLPS_000.23;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/C/SLPS-00023.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994092920284600") == 0) { // Myst (Japan) (Rev 0) - http://redump.org/disc/4786/ / Myst (Japan) (Rev 1)  - http://redump.org/disc/33887/ /  Myst (Japan) (Rev 2)  - http://redump.org/disc/1488/
                return "cdrom:SLPS_000.24;1"; // CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00024.html
            } else if  

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1994113012000000") == 0) || // Toushinden (Japan) (Rev 0) - http://redump.org/disc/1560/
            (strcmp( (char *)volume_creation_timestamp, "1995012512000000") == 0) // Toushinden (Japan) (Rev 1) - http://redump.org/disc/23826/
            ) { // We don't care about revision differences!
                return "cdrom:SLPS_000.25;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/B/SLPS-00025.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995041921063500") == 0) { // Rayman (Japan) - http://redump.org/disc/33719/
                return "cdrom:SLPS_000.26;1"; // CD case serial. Uses 3 MC blocks - https://psxdatacenter.com/games/J/R/SLPS-00026.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1994121500000000") == 0) { // Kileak, The Blood (Japan) - http://redump.org/disc/14371/
                return "cdrom:SLPS_000.27;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00027.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1994121017582300") == 0) { // Jigsaw World (Japan) - http://redump.org/disc/14455/
                return "cdrom:SLPS_000.28;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/J/SLPS-00028.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995022623000000") == 0) { // Idol Janshi Suchie-Pai Limited (Japan) - http://redump.org/disc/33789/
                return "cdrom:SLPS_000.29;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/I/SLPS-00029.html
            } else if

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995050116000000") == 0) || // Game no Tatsujin (Japan) (Rev 0) -http://redump.org/disc/36035/
            (strcmp( (char *)volume_creation_timestamp, "1995060613000000") == 0) // Game no Tatsujin (Japan) (Rev 1) - http://redump.org/disc/37866/
            ) {
                return "cdrom:SLPS_000.30;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00030.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995021802000000") == 0) { // Kyuutenkai (Japan) - http://redump.org/disc/37548/
                return "cdrom:SLPS_000.31;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00031.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995021615022900") == 0) { // Uchuu Seibutsu Flopon-kun P! (Japan) - http://redump.org/disc/18814/.
                return "cdrom:SLPS_000.32;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/U/SLPS-00032.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995080809000000") == 0) { // Boxer's Road (Japan) (Rev 0) - http://redump.org/disc/2765/
                return "cdrom:SLPS_000.33;1"; // Serial from CD case. Uses 7 MC blocks - https://psxdatacenter.com/games/J/B/SLPS-00033.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995071821394900") == 0) { // Zeitgeist (Japan) - http://redump.org/disc/16333/
                return "cdrom:SLPS_000.34;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/Z/SLPS-00034.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995042506300000") == 0) { // Mobile Suit Gundam (Japan) - http://redump.org/disc/3080/
                return "cdrom:SLPS_000.35;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00035.html
            } else if

            // SLPS_000.36 has a proper bootfile: http://redump.org/disc/6599/

            (strcmp( (char *)volume_creation_timestamp, "1995011411551700") == 0) { // Pachio-kun: Pachinko Land Daibouken (Japan) - http://redump.org/disc/36504/
                return "cdrom:SLPS_000.37;1"; // CD case serial.
                //debug_write("Pachio-kun: Pachinko Land Daibouken (Japan)"); // 2 MC block - https://psxdatacenter.com/games/J/P/SLPS-00037.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995041311392800") == 0) { // Nichibutsu Mahjong: Joshikou Meijinsen (Japan) - http://redump.org/disc/35101/
                return "cdrom:SLPS_000.38;1"; // CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/N/SLPS-00038.html
            } else if

            // Metamor Panic: Doki Doki Youma Busters!! (Japan) - http://redump.org/disc/34086/ uses proper bootfile name SLPS_00039

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995031205000000") == 0) || // Tekken (Japan) (Rev 0) - http://redump.org/disc/671/
            (strcmp( (char *)volume_creation_timestamp, "1995061612000000") == 0) // Tekken (Japan) (Rev 1) - http://redump.org/disc/1807/
            ) { // We don't care about revision differences!
                return "cdrom:SLPS_000.40;1"; // Using CD case serial.
                //debug_write("Tekken (Japan) (Rev 0) / (Rev 1)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00040.html
            } else if

           (strcmp( (char *)volume_creation_timestamp, "1995040509000000") == 0) { // Gussun Oyoyo (Japan) - http://redump.org/disc/11336/
                return "cdrom:SLPS_000.41;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00041.html
            } else if

            // SLPS_00042 DOESN't EXIST??!! - https://github.com/julianxhokaxhiu/iPoPS/blob/master/PSXListOFGames.txt

           (strcmp( (char *)volume_creation_timestamp, "1995052612000000") == 0) { // Mahjong Ganryuu-jima (Japan) - http://redump.org/disc/33772/
                return "cdrom:SLPS_000.43;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00043.html
            } else if

           (strcmp( (char *)volume_creation_timestamp, "1995042500000000") == 0) { // Hebereke Station Popoitto (Japan) - http://redump.org/disc/36164/
                return "cdrom:SLPS_000.44;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/H/SLPS-00044.html
            } else if

            // SLPS_00045 DOESN't EXIST??!! - https://github.com/julianxhokaxhiu/iPoPS/blob/master/PSXListOFGames.txt

           // SLPS_00046 Universal Virtua Pachi-Slot: Hisshou Kouryakuhou (Japan) - http://redump.org/disc/36344/ uses bootfile 'PACH.EXE'

            (strcmp( (char *)volume_creation_timestamp, "1995033100003000") == 0) { // Missland (Japan) - http://redump.org/disc/10869/
                return "cdrom:SLPS_000.47;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/M/SLPS-00047.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995041400000000") == 0) { // Gokuu Densetsu: Magic Beast Warriors (Japan) - http://redump.org/disc/24258/
                return "cdrom:SLPS_000.48;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00048.html
            } else if

            // SLPS_00049 DOESN't EXIST??!! - https://github.com/julianxhokaxhiu/iPoPS/blob/master/PSXListOFGames.txt

            (strcmp( (char *)volume_creation_timestamp, "1995050413421800") == 0) { // Night Striker (Japan) - http://redump.org/disc/10931/
                return "cdrom:SLPS_000.50;1"; // CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/N/SLPS-00050.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995040509595900") == 0) { // Entertainment Jansou: That's Pon! (Japan) - http://redump.org/disc/34808/
                return "cdrom:SLPS_000.51;1"; // Serial from CD case. Uses 2 MC blocks - https://psxdatacenter.com/games/J/T/SLPS-00051.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995030103150000") == 0) { //Kanazawa Shougi '95 (Japan) - http://redump.org/disc/34246/
                return "cdrom:SLPS_000.52;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00052.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995100409235300") == 0) { //Thoroughbred Breeder II Plus (Japan) - http://redump.org/disc/33282/
                return "cdrom:SLPS_000.53;1"; // Serial from CD case. Uses 5 MC block - https://psxdatacenter.com/games/J/T/SLPS-00053.html
            } else if

            // SLPS_00054 Yaoi Jun'ichi Gokuhi Project: UFO o Oe!! (Japan) - http://redump.org/disc/28631/ has proper bootfile 'SLPS_000.54'

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1995060504013600") == 0) || // Cyberwar (Japan) (Disc 1) - http://redump.org/disc/30637/
            (strcmp( (char *)volume_creation_timestamp, "1995060319142200") == 0) || // Cyberwar (Japan) (Disc 2) - http://redump.org/disc/30638/
            (strcmp( (char *)volume_creation_timestamp, "1995060402110800") == 0) // Cyberwar (Japan) (Disc 3) - http://redump.org/disc/30639/
            ) {
                return "cdrom:SLPS_000.55;1"; // Using Disc 1 CD case serial: http://redump.org/disc/30637/. All CDs assigned to same memory card. SLPS_00056 is Disc 2, and SLPS_00057 is Disc 3. Uses 1 MC block - https://psxdatacenter.com/games/J/C/SLPS-00055.html.
            } else if

            // SLPS_0058 Ide Yousuke no Mahjong Kazoku (Japan) (Rev 0) - http://redump.org/disc/34169/ and Ide Yousuke no Mahjong Kazoku (Japan) (Rev 1) - http://redump.org/disc/33562/ have proper bootfile 'SLPS_00058'.

            (strcmp( (char *)volume_creation_timestamp, "1995081612000000") == 0) { // Taikyoku Shougi: Kiwame (Japan) - http://redump.org/disc/35288/
                return "cdrom:SLPS_000.59;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00059.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995051201000000") == 0) { // Aquanaut no Kyuujitsu (Japan) - http://redump.org/disc/16984/
                return "cdrom:SLPS_000.60;1"; // Serial from CD case. Uses 4 MC block - https://psxdatacenter.com/games/J/A/SLPS-00060.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995051700000000") == 0) { // Ace Combat (Japan) - http://redump.org/disc/1691/
                return "cdrom:SLPS_000.61;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/A/SLPS-00061.html
            } else if

            // SLPS_00062 Hyper Formation Soccer (Japan) - http://redump.org/disc/2602/ has a proper bootfile 'SLPS_00062'.

            (strcmp( (char *)volume_creation_timestamp, "1995051002471900") == 0) { // Keiba Saishou no Housoku '95 (Japan) - http://redump.org/disc/22944/
                return "cdrom:SLPS_000.63;1"; // Serial from CD case. Uses 15 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00063.html
            } else if

           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995083112000000") == 0) || // Tokimeki Memorial: Forever with You (Japan) (Rev 1) - http://redump.org/disc/6789/ / Tokimeki Memorial: Forever with You (Japan) (Shokai Genteiban) (Rev 1) - http://redump.org/disc/6788/
            (strcmp( (char *)volume_creation_timestamp, "1995111700000000") == 0) // Tokimeki Memorial: Forever with You (Japan) (Rev 2) - http://redump.org/disc/33338/
             // Tokimeki Memorial: Forever with You (Japan) (PlayStation The Best) - http://redump.org/disc/8876/ has it's own different serial and proper bootfile name, so already works with mcpro!
            ) {
                return "cdrom:SLPS_000.64;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00064.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1996033100000000") == 0) { // Tokimeki Memorial: Forever with You (Japan) (Rev 4) - http://redump.org/disc/6764/.
                return "cdrom:SLPS_000.65;1"; // Using CD case serial. Why it is different from the above? No clue. Not a typo though. Uses 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00065.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995051816000000") == 0) { // Kururin Pa! (Japan) - http://redump.org/disc/33413/
                return "cdrom:SLPS_000.66;1"; // Serial from CD case.
                //debug_write("Kururin Pa! (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00066.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995061418000000") == 0) { // Jikkyou Powerful Pro Yakyuu '95: Kaimakuban (Japan) - Jikkyou Powerful Pro Yakyuu '95: Kaimakuban
                return "cdrom:SLPS_000.67;1"; // Serial from CD case. Uses 3 MC blocks - https://psxdatacenter.com/games/J/J/SLPS-00067.html
            } else if

            ( 
            (strcmp( (char *)volume_creation_timestamp, "1995061911303400") == 0) || // J.League Jikkyou Winning Eleven (Japan) (Rev 0) - http://redump.org/disc/6740/
            (strcmp( (char *)volume_creation_timestamp, "1995072800300000") == 0) // // J.League Jikkyou Winning Eleven (Japan) (Rev 1) - http://redump.org/disc/2848/
            ) { // we don't care about any revision differences!
                return "cdrom:SLPS_000.68;1"; // Serial from CD case.
                //debug_write("J.League Jikkyou Winning Eleven (Japan) (Rev 0) / (Rev 1)"); // 1 MC block - https://psxdatacenter.com/games/J/J/SLPS-00068.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995061806364400") == 0) { // King's Field II (Japan) - http://redump.org/disc/5892/
                return "cdrom:SLPS_000.69;1"; // Serial from CD case. Uses 2-15 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00069.html
            } else if
            
            // King's Field II (Japan) (PlayStation the Best) (Rev 0) - http://redump.org/disc/7073/ and King's Field II (Japan) (PlayStation the Best) (Rev 1) - http://redump.org/disc/13338/ have a proper bootfile 'SLPS_910.03'.

            (strcmp( (char *)volume_creation_timestamp, "1995062922000000") == 0) { //Street Fighter: Real Battle on Film (Japan) - http://redump.org/disc/26158/
                return "cdrom:SLPS_000.70;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/S/SLPS-00070.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995040719355400") == 0) { // 3x3 Eyes: Kyuusei Koushu (Disc 1) (Japan) - http://redump.org/disc/7881/ / 3x3 Eyes: Kyuusei Koushu (Disc 2) (Japan) http://redump.org/disc/7880/
                return "cdrom:SLPS_000.71;1"; // Using disc 1 CD case serial: http://redump.org/disc/7881/. Disc 2 serial is SLPS_00072. All CDs assigned to same memory card.
                //debug_write("3x3 Eyes: Kyuusei Koushu (Disc 1) (Japan) / (Disc 2)"); // 1 MC block - https://psxdatacenter.com/games/J/0-9/SLPS-00071.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995061806364400") == 0) { // Dragon Ball Z: Ultimate Battle 22 (Japan) - http://redump.org/disc/10992/
                return "cdrom:SLPS_000.73;1"; // Serial from CD case.
                //debug_write("Dragon Ball Z: Ultimate Battle 22 (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/D/SLPS-00073.html
            } else if

            // SLPS_00074 Sparrow Garden: Namco Mahjong (Japan) - http://redump.org/disc/35289/ has a proper bootfile 'SLPS_000.74"

            // SLPS_00075 World Stadium EX (Japan) (Rev 0) - http://redump.org/disc/10903/ and  SLPS_00075 World Stadium EX (Japan) (Rev 1) - http://redump.org/disc/10904/ have a proper bootfile 'SLPS_000.75"

            // SLPS_00076 DOESN't EXIST??!! - https://github.com/julianxhokaxhiu/iPoPS/blob/master/PSXListOFGames.txt

            (strcmp( (char *)volume_creation_timestamp, "1995051015300000") == 0) { // Douga de Puzzle da! Puppukupuu (Japan) - http://redump.org/disc/11935/
                return "cdrom:SLPS_000.77;1"; // Serial from CD case. Uses 13 MC blocks - https://psxdatacenter.com/games/J/D/SLPS-00077.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995070302000000") == 0) { // Gakkou no Kowai Uwasa: Hanako-san ga Kita!! (Japan) - http://redump.org/disc/11935/
                return "cdrom:SLPS_000.78;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00078.html
            } else if

            // SLPS_00079E J.League Soccer: Prime Goal EX (Japan) (Lawson Station) - http://redump.org/disc/67854/ and  SLPS_00079 J.League Soccer: Prime Goal EX (Japan) - http://redump.org/disc/67854/ have a proper bootfile 'SLPS_000.79"

            // SLPS_00080 Street Fighter II Movie (Disc 1) (Japan) - http://redump.org/disc/18429/ has a proper bootfile 'SLPS_000.80"

            // SLPS_00081 Street Fighter II Movie (Disc 2) (Japan) - http://redump.org/disc/18430/ has a proper bootfile 'SLPS_000.81"

            // SLPS_00082 Shichuu Suimei Pitagraph (Japan) - http://redump.org/disc/33850/ has a proper bootfile 'SLPS_000.82"

            (strcmp( (char *)volume_creation_timestamp, "1995070523450000") == 0) { // Zero Divide (Japan) - http://redump.org/disc/99925/.
                return "cdrom:SLPS_000.83;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/Z/SLPS-00083.html
            } else if

            // SLPS_00084 Shin Nihon Pro Wrestling: Toukon Retsuden (Japan) - http://redump.org/disc/12635/ has a proper bootfile 'SLPS_000.84"

            (strcmp( (char *)volume_creation_timestamp, "1995072522004900") == 0) { // Houma Hunter Lime: Special Collection Vol. 2 (Japan) - http://redump.org/disc/18607/
                return "cdrom:SLPS_000.85;1"; // Serial from CD case.
                //debug_write("Houma Hunter Lime: Special Collection Vol. 2 (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/I/SLPS-00029.html
            } else if

            // SLPS_00086 Kaitei Daisensou: In the Hunt (Japan) - http://redump.org/disc/9478/ has a proper bootfile 'SLPS_000.86"

            // SLPS_00087 The Perfect Golf (Japan) - http://redump.org/disc/11332/ has a proper bootfile 'SLPS_000.87"

            (strcmp( (char *)volume_creation_timestamp, "1995070613170000") == 0) { // Ground Stroke: Advanced Tennis Game (Japan) - http://redump.org/disc/33778/
                return "cdrom:SLPS_000.88;1"; // Serial from CD case.
                //debug_write("Ground Stroke: Advanced Tennis Game (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/G/SLPS-00088.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995082517551900") == 0) { // The Oni Taiji!!: Mezase! Nidaime Momotarou (Japan) - http://redump.org/disc/33948/
                return "cdrom:SLPS_000.89;1"; // CD case serial.
                // debug_write("The Oni Taiji!!: Mezase! Nidaime Momotarou (Japan)"); // 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00089.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995082517551900") == 0) { // Eisei Meijin (Japan) (Rev 1) - http://redump.org/disc/37494/
                return "cdrom:SLPS_000.90;1"; // CD case serial. Uses 3 MC blocks - https://psxdatacenter.com/games/J/E/SLPS-00090.html
            } else if  

            // Eisei Meijin (Japan) (Rev 0) has never been dumped or may not exist??

            (strcmp( (char *)volume_creation_timestamp, "1995053117000000") == 0) { // Exector (Japan) - http://redump.org/disc/2814/
                return "cdrom:SLPS_000.91;1"; // CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/E/SLPS-00091.html
            } else if 

            (strcmp( (char *)volume_creation_timestamp, "1995081100000000") == 0) { // King of Bowling (Japan) - http://redump.org/disc/34727/
                return "cdrom:SLPS_000.92;1"; // CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/K/SLPS-00092.html
            } else if  

            (strcmp( (char *)volume_creation_timestamp, "1995071011035200") == 0) { // Oh-chan no Oekaki Logic (Japan) - http://redump.org/disc/7882/
                return "cdrom:SLPS_000.93;1"; // CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/O/SLPS-00093.html
            } else if




            (strcmp( (char *)volume_creation_timestamp, "1995080316000000") == 0) { // V-Tennis (Japan) - http://redump.org/disc/22684/.
                return "cdrom:SLPS_001.03;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/V/SLPS-00103.html
            } else if





            (strcmp( (char *)volume_creation_timestamp, "1995090516062841") == 0) { // Sotsugyou II: Neo Generation (Japan) - http://redump.org/disc/7885/.
                return "cdrom:SLPS_001.13;1"; // Using CD case serial. Uses 1 MC block - https://psxdatacenter.com/games/J/T/SLPS-00040.html
            } else if








           ( 
            (strcmp( (char *)volume_creation_timestamp, "1995102101350000") == 0) || // D no Shokutaku: Complete Graphics (Japan) (Disc 1) - http://redump.org/disc/763/
            (strcmp( (char *)volume_creation_timestamp, "1995102102521200") == 0) || // D no Shokutaku: Complete Graphics (Japan) (Disc 2) - http://redump.org/disc/764/
            (strcmp( (char *)volume_creation_timestamp, "1995102105003200") == 0) // D no Shokutaku: Complete Graphics (Japan) (Disc 3) - http://redump.org/disc/765/
            ) {
                return "cdrom:SLPS_001.33;1"; // Using disc 1 CD case serial: http://redump.org/disc/763/. All CDs assigned to same memory card. Use 13 MC blocks - https://psxdatacenter.com/games/J/D/SLPS-00133.html
            } else if     



            (strcmp( (char *)volume_creation_timestamp, "1995113010450000") == 0) { // Keiba Saishou no Housoku '96 Vol. 1 (Japan) - http://redump.org/disc/22945/
                return "cdrom:SLPS_001.46;1"; // Serial from CD case.
                //debug_write("Keiba Saishou no Housoku '96 Vol. 1"); // 15 MC blocks - https://psxdatacenter.com/games/J/K/SLPS-00146.html
            } else if





            (strcmp( (char *)volume_creation_timestamp, "1995121620000000") == 0) { // Alnam no Kiba: Juuzoku Juuni Shinto Densetsu (Japan) - http://redump.org/disc/11199/
                return "cdrom:SLPS_001.73;1"; // Serial from CD case. Uses 1 MC block - https://psxdatacenter.com/games/J/A/SLPS-00173.html
            } else if

            (strcmp( (char *)volume_creation_timestamp, "1995100209000000") == 0) { // Boxer's Road (Japan) (Rev 1) - http://redump.org/disc/6537/
                return "cdrom:SLPS_910.07;1"; // Serial from CD case. Uses 7 MC blocks - https://psxdatacenter.com/games/J/B/SLPS-91007.html
            } else {

            /*
            (strcmp( (char *)volume_creation_timestamp, "1998110515540400") == 0) { // Contender (USA) (Demo) - http://redump.org/disc/43176/
                //return "cdrom:SCUS_943.80;1"; // Serial from CD case.
                //debug_write("Contender (USA) (Demo)");
                //no_save_function = true; // Demos can't save.
            } else if
            */
       

            /*
            (strcmp( (char *)volume_creation_timestamp, "1997011500000000") == 0) { // The Great Battle VI (Japan) - http://redump.org/disc/37406/
                //return "cdrom:SLPS_007.19;1"; // Serial from CD case.
                //debug_write("The Great Battle VI (Japan)");
                //no_save_function = true; // https://psxdatacenter.com/games/J/T/SLPS-00719.html
            } else if
            */

            /*    
            (strcmp( (char *)volume_creation_timestamp, "1995070500000000") == 0) { // Zero Divide (Japan) (Demo) - http://redump.org/disc/99925/.
                //return "cdrom:SLPM_800.08;1"; // Using CD case serial.
                // Demos don't have save features.
                //debug_write("Zero Divide (Japan) (Demo)");
            */
            
                return "0"; // If not known say its "0".
            }
 }
