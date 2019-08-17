SECTIONS
{
	. = 0x0; /* Flash ROM starts at 0x00000000. */
	.text :
	{
		*(vectors) /* The first thing in ROM is the interrupt vector table, */
		*(.text) /* which is followed by the program code, */
	}
	.rodata :
	{
		*(.rodata) /* which is followed by read only data. */
	}
	_DATA_ROM_START = .; /* This is where variables in ROM are that are used to initialize variables in SRAM. */
	. = 0x20000000; /* SRAM starts at 0x20000000. */
	_DATA_RAM_START = .; /* This is where variables in SRAM start (that are initialized from ROM values). */
	.data : AT(_DATA_ROM_START)
	{
		*(.data) /* Flash ROM data memory. */
	}
	_DATA_RAM_END = .;
	_BSS_START = .; /* This is where the BSS section (statically allocated unitialized variables) starts in SRAM. */
	.bss :
	{
		*(.bss) /* Zero-filled run time allocated data memory. */
	}
	_BSS_END = .; /* This is where BSS section ends in SRAM. */
}
