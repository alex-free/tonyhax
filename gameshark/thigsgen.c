#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    printf("Tonyhax International GameShark Generator (THIGSGEN) v1.0.2 By Alex Free\n");

   if(argc != 2)
    {
        printf("Error, THIGSGEN requires 1 argument.\nUsage:\n\nthigsgen <txt file containing GameShark codes>\n");
        return(1);
    }

    
    if((txt = fopen(argv[1], "r")) == NULL)
    {
        printf("Error: Cannot read the input txt file: %s\n", argv[2]);
        return(1);
    }

    if((out = fopen("TONYHAXINTGS", "wb+")) == NULL)
    {
        printf("Error: Cannot create the output save file TONYHAXINTGS\n");
        fclose(txt);
        return(1);
    }

    fseek(out, 0, SEEK_SET);
    fseek(txt, 0, SEEK_SET);

    for(int i = 0; i < 0x2000; i++)
      fputc(0x00, out); 

    fseek(out, 0, SEEK_SET);
    for(int i = 0; i < 0x101; i++)
      fputc(save[i], out); 
    
    fseek(out, 0x103, SEEK_SET);

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

    fseek(out, 0x102, SEEK_SET);

    fwrite(&number_of_gameshark_codes, 1, 1, out);
    fclose(out);
    fclose(txt);
    printf("Generated Tonyhax International save file named: TONYHAXINTGS containing %d GameShark Codes\n", number_of_gameshark_codes);

}