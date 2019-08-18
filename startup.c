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
    /* Copy data from ROM to RAM to initialize variables. */
	uint32_t* pROM_data_start = &_DATA_ROM_START;
	uint32_t* pRAM_data_start = &_DATA_RAM_START;
	uint32_t* pRAM_data_end = &_DATA_RAM_END;
	while(pRAM_data_start != pRAM_data_end)
    {
		*pRAM_data_start++ = *pROM_data_start++;
	}
    /* Zero fill the unitialized variables in RAM. */
	uint32_t* pBSS_start = &_BSS_START;
	uint32_t* pBSS_end = &_BSS_END;
	while(pBSS_start != pBSS_end)
	{
		*pBSS_start++ = 0;
	}
    /* Call the "main" function */
	main();
}