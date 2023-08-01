#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include "thigsgen.h"

FILE *out;
FILE *txt;

uint8_t *bytes;
uint8_t gameshark_code_type;
uint8_t number_of_gameshark_code_lines = 0;
uint8_t gameshark_patch_code_number_of_codes;
uint8_t gameshark_patch_code_offset_to_add_to_each_code_address;
uint8_t sum;
uint8_t prev = 0;
uint8_t next;

uint16_t gameshark_patch_code_offset_to_add_to_each_code_write_val;
uint16_t gameshark_code_address_mod_val;

uint32_t read_codes;
uint32_t gameshark_code_address;

bool parse()
{
  printf("GS Code Address/Prefix: %08X\n", gameshark_code_address);
  bytes = (uint8_t *)&gameshark_code_address;
  uint8_t gameshark_code_type = bytes[3];

  if(
    (gameshark_code_type != 0x50) &&

    (gameshark_code_type != 0x80) && 
    (gameshark_code_type != 0xD0) && 
    (gameshark_code_type != 0xD1) && 
    (gameshark_code_type != 0xD2) && 
    (gameshark_code_type != 0xD3) &&
 
    (gameshark_code_type != 0x30) && 
    (gameshark_code_type != 0xE0) && 
    (gameshark_code_type != 0xE1) && 
    (gameshark_code_type != 0xE2) && 
    (gameshark_code_type != 0xE3)
    )
  {
    printf("Error, unsupported code type: %02X, bailing...\n", gameshark_code_type);
    fclose(txt);
    fclose(out);
    remove("TONYHAXINTGS");
    return false;
  }

  if(gameshark_code_type == 0x50)
  {
    gameshark_patch_code_number_of_codes = bytes[1];
    printf("Number of 80 codes to be derived from 50 type code: 0x%02X\n", gameshark_patch_code_number_of_codes);
    gameshark_patch_code_offset_to_add_to_each_code_address = bytes[0];
    printf("Offset to add to each 80 code address: 0x%02X\n", gameshark_patch_code_offset_to_add_to_each_code_address);
    printf("Offset to add to each write val: 0x%hX\n", gameshark_patch_code_offset_to_add_to_each_code_write_val);
    fscanf(txt, "%08X %hX\n", &gameshark_code_address, &gameshark_code_address_mod_val); // get real vals from next line

    for (int i = 0; i < gameshark_patch_code_number_of_codes; i++)
    {
      printf("GS Code Address/Prefix: %08X\n", gameshark_code_address);
      printf("GS Code Mod Value: %02hX\n", gameshark_code_address_mod_val);
      fwrite(&gameshark_code_address, 1, 4, out);
      fwrite(&gameshark_code_address_mod_val, 1, 2, out);
      gameshark_code_address = (gameshark_code_address + gameshark_patch_code_offset_to_add_to_each_code_address);
      gameshark_code_address_mod_val = (gameshark_code_address_mod_val + gameshark_patch_code_offset_to_add_to_each_code_write_val);
      number_of_gameshark_code_lines++;
    }
  } else {
    fwrite(&gameshark_code_address, 1, 4, out);
    printf("GS Code Type/Prefix: 0x%02X\n", gameshark_code_type);
    printf("GS Code Mod Value: %hX\n", gameshark_code_address_mod_val);
    fwrite(&gameshark_code_address_mod_val, 1, 2, out);
    number_of_gameshark_code_lines++;
  }
  return true;
}

int main(int argc, const char *argv[])
{

  printf("Tonyhax International GameShark Generator (THIGSGEN) v2.0.2 By Alex Free\n");

  if (argc != 2)
  {
    printf("Error, THIGSGEN requires 1 argument.\nUsage:\n\nthigsgen <txt file containing GameShark codes>\n");
    return (1);
  }

  if ((txt = fopen(argv[1], "r")) == NULL)
  {
    printf("Error: Cannot read the input txt file: %s\n", argv[1]);
    return (1);
  }

  remove("TONYHAXINTGS"); // don't care if it exists yet or not

  if ((out = fopen("TONYHAXINTGS", "wb+")) == NULL)
  {
    printf("Error: Cannot create the output save file TONYHAXINTGS\n");
    fclose(txt);
    return (1);
  }

  fseek(out, 0, SEEK_SET);
  fseek(txt, 0, SEEK_SET);

  for (int i = 0; i < 0x2000; i++)
    fputc(0x00, out);

  fseek(out, 0, SEEK_SET);
  for (int i = 0; i < 0x101; i++)
    fputc(save[i], out);

  fseek(out, 0x104, SEEK_SET);

  printf("\n");

  while (1)
  {
    read_codes = fscanf(txt, "%08X %hX\n", &gameshark_code_address, &gameshark_code_address_mod_val);;

    if (read_codes != EOF && read_codes != 0)
    {
      if(!parse())
        return(1);
    }
    else
    {
      printf("\nReading of txt file: %s is complete\n\n", argv[1]);
      break;
    }
  }

  fseek(out, 0x103, SEEK_SET);

  fwrite(&number_of_gameshark_code_lines, 1, 1, out);

  fseek(out, 0x103, SEEK_SET); // checksum starting here

	for (int i = 0x103; i < 0x2000; i++)
	{
		next = fgetc(out);
		sum = prev + next;
		sum &= 0xFF;
		prev = sum;
	}

  fseek(out, 0x102, SEEK_SET);
  fwrite(&sum, 1, 1, out);
	printf("TONYHAXINTGS checksum: 0x%02X\n", sum);

  fclose(out);
  fclose(txt);
  printf("Generated Tonyhax International save file named: TONYHAXINTGS containing %d GameShark code lines\n", number_of_gameshark_code_lines);
}