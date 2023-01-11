#include <stdio.h>
#include <stdlib.h>

FILE *exe;
unsigned int exe_size;
unsigned int current_fpos;
unsigned char *buf;
unsigned char *bytes;
unsigned int gameshark_write_bytes_1_address;
unsigned int gameshark_write_bytes_2_address;
unsigned int gameshark_write_bytes_3_address;
unsigned int gameshark_code_address;

int main (int argc, const char * argv[]) 
{
   if(argc != 3)
    {
        printf("GameSharkHAX Code Creator v1.0\nBy Alex Free\nError: gshax requires 2 arguments\n");
        return(1);
    }

    gameshark_code_address = strtoul(argv[1], NULL, 16);

    if((exe = fopen(argv[2], "rb+")) == NULL)
    {
        printf("Error: Cannot open the executable file: %s\n", argv[2]);
        return(1);
    }

    fseek(exe, 0, SEEK_END);
    exe_size = ftell(exe);
    fseek(exe, 0, SEEK_SET);
    buf = (unsigned char *)malloc(exe_size * sizeof(unsigned char));
    fread(buf, exe_size, 1, exe);
    current_fpos = 0;

    while(1)
    {
        if(current_fpos > exe_size)
            break;

        gameshark_write_bytes_1_address = buf[current_fpos];
        gameshark_write_bytes_2_address = buf[current_fpos + 1];

        printf("%08X %02X%02X\n", gameshark_code_address, gameshark_write_bytes_2_address, gameshark_write_bytes_1_address);
        current_fpos = (current_fpos + 2);
        gameshark_code_address = (gameshark_code_address + 2);
    }
}