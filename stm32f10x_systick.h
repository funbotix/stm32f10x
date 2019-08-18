#ifndef __STM32F10X_SYSTICK_DOT_H__
#define __STM32F10X_SYSTICK_DOT_H__

#include <stdint.h>

//-----------------------------------------------------------------------------
// SYSTICK TIMER
//-----------------------------------------------------------------------------

typedef uint32_t ticker_t;

ticker_t get_ticker(void);
int elapsed_ticks(ticker_t ticker);
void set_systick_frequency(uint32_t frequency);

#define SYSTICK_BASE (0xE000E010U)

typedef struct{
    uint32_t CTRL;
    uint32_t LOAD;
    uint32_t VAL;
    uint32_t CALIB;
}SYSTICK_t;

#ifndef __STM32F10X_SYSTICK_DOT_C__ 
extern SYSTICK_t* SYSTICK; // global pointer to SYSTICK registers;
#endif

#endif