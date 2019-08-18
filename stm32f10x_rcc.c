/* Minimal support to access the reset and clock control (RCC) registers */

#define __STM32F10X_RCC_DOT_C__

#include "stm32f10x_rcc.h" 

// Create a global variable that points to the RCC registers.
RCC_t* RCC = (RCC_t*)RCC_BASE;

#undef __STM32F10X_RCC_DOT_C__
