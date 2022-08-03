#include <stdio.h>
#include <string.h>

/*
MottZilla's notes on how the checksums are calculated

=============================================
Tony Hawk Pro Skater 2 Japan

Raw save file:
Starting at offset $280 (640 in decimal) XOR all bytes together up to $1D00 (7424 in decimal).
7424-640=6784
The result of XORing all those bytes is stored at $204 (516 in decimal).

MCS save file:
MCS has a $80 byte header (128 in decimal), that's the only difference. So the new values for a MCS file are:
start checksum: 640+128=768
end checksum: 7424+128=7552
length of checked area: 7552-768=6784 (same length obviously)
checksum offset: 516+128=644

=============================================
Castrol Honda VTR Japan

Raw save file:
Starting at offset $0 (0 in decimal) add all bytes together up to $2EFF (12031 in decimal). Length of checked area = 12031 in decimal. This checksum offset is written to $2F00 (12032 in decimal).

The result of XORing all those bytes is stored at $2F01 (12033 in decimal)

MCS save file:
MCS has a $80 byte header (128 in decimal), that's the only difference. So the new values for a MCS file are:
start checksum: 0+128=128
end checksum: 12031+128=12159
length of checked area: 12159-128=12031
checksum offset (addition): 12032+128=12160
checksum offset (xor): 12033+128=12161
*/

FILE *game_save;

int prev, next, xord, sum, current_fpos, xord_checksum, checked_area_start, checked_area_length;

typedef enum { FALSE, TRUE } bool;

bool is_thps2, is_chvtr;

int main (int argc, const char * argv[]) {

    is_chvtr = 0;
    is_thps2 = 0;
    printf("Success Checksum Updater (SuccessCU) v1.0\nBy MottZilla & Alex Free\n");

    if(argc != 3)
    {
        printf("Error: Incorrect number of arguments\nUsage:\nsuccesscu <game> <mcs save game file>\n<game>     -t (Tony Hawk Pro Skater 2 Japan) or -c (Castrol Honda VTR Japan\n");
        return(1);
    } else {
        if((game_save = fopen(argv[2], "r+b")) != NULL)
        {
            printf("Successfully loaded save file: %s\n", argv[2]);
        } else {
            printf("Cannot open save file: %s\n", argv[2]);
            return(1);
        }
    }

    if(strcmp(argv[1], "-t") == 0 )
    {
        printf("Mode: Tony Hawk Pro Skater 2 Japan\n");
        is_thps2 = 1;
    } 
    else if(strcmp(argv[1], "-c") == 0 )
    {
        printf("Mode: Castrol Honda VTR Japan\n");
        is_chvtr = 1;
    } 
    else 
    {
        printf("Error: 2nd argument must be the game mode to patch -t (Tony Hawk Pro Skater 2 Japan) or -c (Castrol Honda VTR Japan\n");
        fclose(game_save);
        return(1);
    }

    if(is_thps2)
    {
        checked_area_start = 768;
        checked_area_length = 6784;
        xord_checksum = 644;
    }

    if(is_chvtr)
    {
        checked_area_start = 128;
        checked_area_length = 12031;
        xord_checksum = 12161;

        fseek(game_save, checked_area_start, SEEK_SET);
        prev = fgetc(game_save);
        current_fpos = 1;

        while(1)
        {
            if(current_fpos < checked_area_length)
            {
                next = fgetc(game_save);
                sum = prev + next;
                sum &= 0xFF;
                prev = sum;
                current_fpos++;
            } else {
                break;
            }
        }        
    
        printf("New addition checksum is %02X, writing to save file %s...\n", sum, argv[2]);
        fseek(game_save, 12160, SEEK_SET);
        fputc(sum, game_save);

    }

    fseek(game_save, checked_area_start, SEEK_SET);
    prev = fgetc(game_save);
    current_fpos = 1;

    while(1)
    {
        if(current_fpos < checked_area_length)
        {
            next = fgetc(game_save);
            xord = prev ^ next;
            prev = xord;
            current_fpos++;
        } else {
            break;
        }
    }

    printf("New xor checksum is %02X, writing to save file %s...\n", xord, argv[2]);
    fseek(game_save, xord_checksum, SEEK_SET);
    fputc(xord, game_save);
    fclose(game_save);

    return(0);
}