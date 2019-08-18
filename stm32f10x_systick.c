#define __STM32F10X_SYSTICK_DOT_C__

#include "macros.h"
#include "stm32f10x_systick.h"

SYSTICK_t* SYSTICK = (SYSTICK_t*)SYSTICK_BASE; // create global pointer to SYSTICK registers;

//-----------------------------------------------------------------------------

#define USING_C_RUNTIME 0

#if USING_C_RUNTIME == 0
#define reload (uint32_t)((8000000.0f / 1000.0f)+0.5f) // ignore below frequency parameter and use 1 KHz instead
#endif

void set_systick_frequency(uint32_t frequency){
#if USING_C_RUNTIME == 1
    uint32_t reload = (uint32_t)(((float)8000000 / (float)frequency) + 0.5f);
#endif    
    SYSTICK->CTRL = 0;
    SYSTICK->CTRL |= BIT(2); // systick counter clock source = processor clock (AHB)
    SYSTICK->CTRL |= BIT(1); // Counting down to zero to asserts the SysTick exception request.
    SYSTICK->LOAD = reload;
    SYSTICK->CTRL |= BIT(0); // Enable the systick counter.
}

//-----------------------------------------------------------------------------

static ticker_t systick = 0; // counts systick timer ticks for elapsed time measurements

void SysTick_ISR(){ 
    // Cortex-M3 core systick timer interrupt service routine.
    ++systick;
}

//-----------------------------------------------------------------------------

ticker_t get_ticker(void){
    return systick;
}

int elapsed_ticks(ticker_t ticker){
    return systick - ticker;
}

#undef __STM32F10X_SYSTICK_DOT_C__
