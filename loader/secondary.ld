MEMORY {
	ram(wrx)	:ORIGIN = 0x801EA300, LENGTH = 0xBD00
}
SECTIONS {
	. = 0x801EA300;
	PROVIDE(__RO_START__ = .);
	.text :
	{
		*(.start)
		*(.text .text.*)
	} >ram
	.rodata :
	{
		*(.rodata .rodata.*)
	} >ram
	.data :
	{
		*(.data .data.*)
	} >ram
	PROVIDE(__CRC_START__ = .);
	.crc :
	{
		*(.crc .crc.*)
	} >ram
	PROVIDE(__BSS_START__ = .);
	.bss :
	{
		*(.bss .bss.*)
	} >ram
	PROVIDE(__BSS_END__ = .);
	/DISCARD/ :
	{
		*(*)
	}
}
ENTRY (start)
