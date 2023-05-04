#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "thigsgen.h"

FILE *out;
FILE *txt;

unsigned char *bytes;
unsigned char gameshark_code_type;
unsigned char number_of_gameshark_codes = 0;

unsigned int read_codes;
unsigned int gameshark_code_address;
unsigned int gameshark_code_address_2;
unsigned int gameshark_code_address_mod_val;
unsigned int gameshark_code_address_mod_comparison_val;

bool mcs = 0;
bool raw = 0;

void parse() {
    printf("GS Code Addr: %08X\n", gameshark_code_address);
    bytes=(unsigned char *)&gameshark_code_address;
    gameshark_code_address = bytes[3] + (bytes[2] << 8) + (bytes[1] << 16) + (bytes[0] << 24); 
    fwrite(&gameshark_code_address, 1, 4, out);

    gameshark_code_type = bytes[0];
    printf("GS Code Type: %02X\n", gameshark_code_type);

    printf("GS Code Mod Value: %08X\n", gameshark_code_address_mod_val);
    bytes=(unsigned char *)&gameshark_code_address_mod_val;
    gameshark_code_address_mod_val = bytes[1] + (bytes[0] << 8) + (bytes[2] << 16) + (bytes[3] << 24);
    fwrite(&gameshark_code_address_mod_val, 1, 2, out);

    bytes=(unsigned char *)&gameshark_code_address_2;
    gameshark_code_address_2 = bytes[3] + (bytes[2] << 8) + (bytes[1] << 16) + (bytes[0] << 24); 

    if(gameshark_code_type == 0xD0) {
      printf("GS Code Mod Comparison Value: %08X\n", gameshark_code_address_mod_comparison_val);
      bytes=(unsigned char *)&gameshark_code_address_mod_comparison_val;
      gameshark_code_address_mod_comparison_val = bytes[1] + (bytes[0] << 8) + (bytes[2] << 16) + (bytes[3] << 24);      
      fwrite(&gameshark_code_address_mod_comparison_val, 1, 2, out);

    } else if((gameshark_code_address != gameshark_code_address_2) && gameshark_code_address_2 != 0) {
      number_of_gameshark_codes++;
      gameshark_code_address_2 = bytes[3] + (bytes[2] << 8) + (bytes[1] << 16) + (bytes[0] << 24); 
      printf("GS Code Addr: %08X\n", gameshark_code_address_2);
      gameshark_code_address_2 = bytes[3] + (bytes[2] << 8) + (bytes[1] << 16) + (bytes[0] << 24); 
      fwrite(&gameshark_code_address_2, 1, 4, out);

      gameshark_code_type = bytes[0];
      printf("GS Code Type: %02X\n", gameshark_code_type);

      printf("GS Code Mod Value: %08X\n", gameshark_code_address_mod_comparison_val);
      bytes=(unsigned char *)&gameshark_code_address_mod_comparison_val;
      gameshark_code_address_mod_comparison_val = bytes[1] + (bytes[0] << 8) + (bytes[2] << 16) + (bytes[3] << 24);
      fwrite(&gameshark_code_address_mod_comparison_val, 1, 2, out);
    }
    gameshark_code_address = 0;
    gameshark_code_address_2 = 0;
}


int main (int argc, const char * argv[]) 
{

    printf("Tonyhax International GameShark Generator (THIGSGEN) v1.0 By Alex Free\n");

   if(argc != 4)
    {
        printf("Error, THIGSGEN requires 3 arguments.\nUsage:\n\nthigsgen <output mode> <txt file containing GameShark codes> <output save file>\n\n<output mode> -m for .mcs format. -r for raw format.\n\n<output save file> must be TONYHAXINTGS for raw format. It can however be anything you want for mcs format\n\nExamples:\n\nthigsgen -r gs.txt TONYHAXINTGS\n\nthigsgen -m gs.txt tonyhax-codes.mcs\n");
        return(1);
    }

    
    if((strcmp("-m", argv[1])) == 0) 
    {
      mcs = 1;
      printf("Output format: MCS\n\n");
    } else if((strcmp("-r", argv[1])) == 0) {
      raw = 1;
      printf("Output format: RAW\n\n");
    } else {
      printf("Error: 1st argument must be -r or -m\n");
      return(1);
    }
    
    if((out = fopen(argv[3], "wb+")) == NULL)
    {
        printf("Error: Cannot create the output file: %s\n", argv[3]);
        return(1);
    }


    if((txt = fopen(argv[2], "r")) == NULL)
    {
        printf("Error: Cannot create the output file: %s\n", argv[2]);
        return(1);
    }

    fseek(out, 0, SEEK_SET);
    fseek(txt, 0, SEEK_SET);

    if(mcs)
    {
      for(int i = 0; i < 128; i++)
        fputc(mcshead[i], out); 
    }

    for(int i = 0; i < 8192; i++)
      fputc(save[i], out); 
    
    if(mcs)
    {
      fseek(out, 0x181, SEEK_SET);
    } else if(raw) {
      fseek(out, 0x101, SEEK_SET);
    }

		while(1) 
    {
			read_codes = fscanf(txt, "%8X %4X\n%8X %4X", &gameshark_code_address, &gameshark_code_address_mod_val, &gameshark_code_address_2, &gameshark_code_address_mod_comparison_val);	
		
    	if(read_codes != EOF && read_codes != 0)
			{
		  		number_of_gameshark_codes++;
					parse();
			} else {
					printf("\nReading of txt file: %s is complete\n\n", argv[2]);
					break;
				}
    }	

    if(mcs)
    {
      fseek(out, 0x180, SEEK_SET);
    } else if(raw) {
      fseek(out, 0x100, SEEK_SET);
    }

    fwrite(&number_of_gameshark_codes, 1, 1, out);
    fclose(out);
    fclose(txt);
    printf("Generated Tonyhax International save file named: %s containing %d GameShark Codes\n", argv[3], number_of_gameshark_codes);

}