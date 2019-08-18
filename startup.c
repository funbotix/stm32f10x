#include <stdint.h>

extern uint32_t _DATA_ROM_START;
extern uint32_t _DATA_RAM_START;
extern uint32_t _DATA_RAM_END;
extern uint32_t _BSS_START;
extern uint32_t _BSS_END;

#define STACK_TOP 0x20005000

void startup();

uint32_t* interrupt_vectors[] __attribute__ ((section("vectors"))) = 
{
	(uint32_t*) STACK_TOP, /* Initialize the stack pointer */
	(uint32_t*) startup /* Call the "startup" function when the microcontroller comes out of RESET. */
};

extern int main();

void startup()
{
    uint32_t* pROM; // where to copy from
    uint32_t* pRAM; // where to copy to
    uint32_t* pEND; // when (where) to stop copying (to)

    /* Copy data from ROM to RAM to initialize variables. */
	pROM = &_DATA_ROM_START;
	pRAM = &_DATA_RAM_START;
	pEND = &_DATA_RAM_END;
	while(pRAM != pEND)
	{
		*pRAM++ = *pROM++;
	}

    /* Zero fill the unitialized variables in RAM. */
	pRAM = &_BSS_START;
	pEND = &_BSS_END;
	while(pRAM != pEND)
	{
		*pRAM++ = 0;
	}

    /* Call the "main" function */
	main();
}