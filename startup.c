#include <stdint.h>

extern uint32_t _DATA_ROM_START;
extern uint32_t _DATA_RAM_START;
extern uint32_t _DATA_RAM_END;
extern uint32_t _BSS_START;
extern uint32_t _BSS_END;

#define STACK_TOP 0x20005000

void RESET_ISR(void);

/*
From the ARM KEIL Compiler User Guide Compiler Specific Features section...

The __weak attribute instructs the compiler to export symbols weakly.
The __weak attribute can be applied to function and variable declarations, 
and to function definitions. 

For declarations, this storage class specifies an extern object declaration 
that, even if not present, does not cause the linker to fault an unresolved reference.

This allows the below interrupt vector table to be initialized, 
and for the coder to create their own implementation of any or all of the
weak interrupt service routines mentioned in the interrupt vector table.
*/

void NMI_ISR(void) __attribute__((weak));
void HARD_FAULT_ISR(void) __attribute__((weak)); 
void MEM_MANAGE_FAULT_ISR(void) __attribute__((weak));
void BUS_FAULT_ISR(void) __attribute__((weak)); 
void USAGE_FAULT_ISR(void) __attribute__((weak)); 
void SVC_ISR(void) __attribute__((weak)); 
void PendSV_ISR(void) __attribute__((weak)); 
void SysTick_ISR(void) __attribute__((weak)); 
void GPIO_INT0_ISR(void) __attribute__((weak)); 
void GPIO_INT1_ISR(void) __attribute__((weak)); 
void GPIO_INT2_ISR(void) __attribute__((weak)); 
void GPIO_INT3_ISR(void) __attribute__((weak)); 
void GPIO_INT4_ISR(void) __attribute__((weak)); 
void GPIO_INT5_ISR(void) __attribute__((weak)); 
void GPIO_INT6_ISR(void) __attribute__((weak)); 
void GPIO_INT7_ISR(void) __attribute__((weak)); 
void GINT0_ISR(void) __attribute__((weak)); 
void GINT1_ISR(void) __attribute__((weak)); 
void I2C1_ISR(void) __attribute__((weak)); 
void USART1_4_ISR(void) __attribute__((weak)); 
void USART2_3_ISR(void) __attribute__((weak)); 
void SCT0_1_ISR(void) __attribute__((weak)); 
void SSP1_ISR(void) __attribute__((weak)); 
void I2C0_ISR(void) __attribute__((weak)); 
void CT16B0_ISR(void) __attribute__((weak)); 
void CT16B1_ISR(void) __attribute__((weak)); 
void CT32B0_ISR(void) __attribute__((weak)); 
void CT32B1_ISR(void) __attribute__((weak)); 
void SSP0_ISR(void) __attribute__((weak)); 
void USART0_ISR(void) __attribute__((weak)); 
void USB_ISR(void) __attribute__((weak)); 
void USB_FIQ_ISR(void) __attribute__((weak)); 
void ADC_A_ISR(void) __attribute__((weak)); 
void RTC_ISR(void) __attribute__((weak)); 
void BOD_WDT_ISR(void) __attribute__((weak)); 
void FLASH_ISR(void) __attribute__((weak)); 
void DMA_ISR(void) __attribute__((weak)); 
void ADC_B_ISR(void) __attribute__((weak)); 
void USBWAKEUP_ISR(void) __attribute__((weak)); 

// The interrupt vector table.
uint32_t* interrupt_vectors[] __attribute__ ((section("vectors"))) = {
	/* -16 */ (uint32_t*) STACK_TOP,
	/* -15 */ (uint32_t*) RESET_ISR,
    /* -14 */ (uint32_t*) NMI_ISR,
    /* -13 */ (uint32_t*) HARD_FAULT_ISR,
    /* -12 */ (uint32_t*) MEM_MANAGE_FAULT_ISR,
    /* -11 */ (uint32_t*) BUS_FAULT_ISR,
    /* -10 */ (uint32_t*) USAGE_FAULT_ISR,
    /*  -9 */ (uint32_t*) 0,
    /*  -8 */ (uint32_t*) 0,
    /*  -7 */ (uint32_t*) 0,
    /*  -6 */ (uint32_t*) 0,
    /*  -5 */ (uint32_t*) SVC_ISR,
    /*  -4 */ (uint32_t*) 0,
    /*  -3 */ (uint32_t*) 0,
    /*  -2 */ (uint32_t*) PendSV_ISR,
    /*  -1 */ (uint32_t*) SysTick_ISR,
    /*   0 */ (uint32_t*) GPIO_INT0_ISR, 
    /*   1 */ (uint32_t*) GPIO_INT1_ISR, 
    /*   2 */ (uint32_t*) GPIO_INT2_ISR, 
    /*   3 */ (uint32_t*) GPIO_INT3_ISR, 
    /*   4 */ (uint32_t*) GPIO_INT4_ISR, 
    /*   5 */ (uint32_t*) GPIO_INT5_ISR, 
    /*   6 */ (uint32_t*) GPIO_INT6_ISR, 
    /*   7 */ (uint32_t*) GPIO_INT7_ISR, 
    /*   8 */ (uint32_t*) GINT0_ISR,    
    /*   9 */ (uint32_t*) GINT1_ISR,    
    /*  10 */ (uint32_t*) I2C1_ISR,     
    /*  11 */ (uint32_t*) USART1_4_ISR, 
    /*  12 */ (uint32_t*) USART2_3_ISR, 
    /*  13 */ (uint32_t*) SCT0_1_ISR,   
    /*  14 */ (uint32_t*) SSP1_ISR,     
    /*  15 */ (uint32_t*) I2C0_ISR,     
    /*  16 */ (uint32_t*) CT16B0_ISR,   
    /*  17 */ (uint32_t*) CT16B1_ISR,   
    /*  18 */ (uint32_t*) CT32B0_ISR,   
    /*  19 */ (uint32_t*) CT32B1_ISR,   
    /*  20 */ (uint32_t*) SSP0_ISR,     
    /*  21 */ (uint32_t*) USART0_ISR,   
    /*  22 */ (uint32_t*) USB_ISR,      
    /*  23 */ (uint32_t*) USB_FIQ_ISR,  
    /*  24 */ (uint32_t*) ADC_A_ISR,    
    /*  25 */ (uint32_t*) RTC_ISR,      
    /*  26 */ (uint32_t*) BOD_WDT_ISR,  
    /*  27 */ (uint32_t*) FLASH_ISR,    
    /*  28 */ (uint32_t*) DMA_ISR,      
    /*  29 */ (uint32_t*) ADC_B_ISR,    
    /*  30 */ (uint32_t*) USBWAKEUP_ISR,
    /*  31 */ (uint32_t*) 0
};

extern int main(void);

void RESET_ISR(void){
    uint32_t* pROM; // where to copy from
    uint32_t* pRAM; // where to copy to
    uint32_t* pEND; // when (where) to stop copying (to)

    /* Copy data from ROM to RAM to initialize variables. */
	pROM = &_DATA_ROM_START;
	pRAM = &_DATA_RAM_START;
	pEND = &_DATA_RAM_END;
	while(pRAM != pEND){
		*pRAM++ = *pROM++;
    }

    /* Zero fill the unitialized variables in RAM. */
	pRAM = &_BSS_START;
	pEND = &_BSS_END;
	while(pRAM != pEND){
		*pRAM++ = 0;
    }

    /* Call the "main" function */
	main();
}

// Default (infinite loop) interrupt service routines.
void NMI_ISR(void) { for(;;); }
void HARD_FAULT_ISR(void) { for(;;); }
void MEM_MANAGE_FAULT_ISR(void) { for(;;); }
void BUS_FAULT_ISR(void) { for(;;); }
void USAGE_FAULT_ISR(void) { for(;;); }
void SVC_ISR(void) { for(;;); }
void PendSV_ISR(void) { for(;;); }
void SysTick_ISR(void) { for(;;); }
void GPIO_INT0_ISR(void) { for(;;); }
void GPIO_INT1_ISR(void) { for(;;); }
void GPIO_INT2_ISR(void) { for(;;); }
void GPIO_INT3_ISR(void) { for(;;); }
void GPIO_INT4_ISR(void) { for(;;); }
void GPIO_INT5_ISR(void) { for(;;); }
void GPIO_INT6_ISR(void) { for(;;); }
void GPIO_INT7_ISR(void) { for(;;); }
void GINT0_ISR(void) { for(;;); }
void GINT1_ISR(void) { for(;;); }
void I2C1_ISR(void) { for(;;); }
void USART1_4_ISR(void) { for(;;); }
void USART2_3_ISR(void) { for(;;); }
void SCT0_1_ISR(void) { for(;;); }
void SSP1_ISR(void) { for(;;); }
void I2C0_ISR(void) { for(;;); }
void CT16B0_ISR(void) { for(;;); }
void CT16B1_ISR(void) { for(;;); }
void CT32B0_ISR(void) { for(;;); }
void CT32B1_ISR(void) { for(;;); }
void SSP0_ISR(void) { for(;;); }
void USART0_ISR(void) { for(;;); }
void USB_ISR(void) { for(;;); }
void USB_FIQ_ISR(void) { for(;;); }
void ADC_A_ISR(void) { for(;;); }
void RTC_ISR(void) { for(;;); }
void BOD_WDT_ISR(void) { for(;;); }
void FLASH_ISR(void) { for(;;); }
void DMA_ISR(void) { for(;;); }
void ADC_B_ISR(void) { for(;;); }
void USBWAKEUP_ISR(void) { for(;;); }
