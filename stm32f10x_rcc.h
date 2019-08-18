/* Minimal support to access the reset and clock control (RCC) registers */

#ifndef __STM32F10X_RCC_DOT_H__
#define __STM32F10X_RCC_DOT_H__

#include <stdint.h>

//-----------------------------------------------------------------------------
// RESET AND CLOCK CONTROL
//-----------------------------------------------------------------------------

#define RCC_BASE (0x40021000U) // Define the base address of the RCC register map.

typedef struct{
    uint32_t CR;       // clock control register
    uint32_t CFGR;     // clock configuration register
    uint32_t CIR;      // clock interrupt register
    uint32_t APB2RSTR; // APB2 peripheral reset register
    uint32_t APB1RSTR; // APB1 peripheral reset register
    uint32_t AHBENR;   // AHB peripheral clock enable register
    uint32_t APB2ENR;  // APB2 peripheral clock enable register
    uint32_t APB1ENR;  // APB1 peripheral clock enable register
    uint32_t BDCR;     // backup domain control register
    uint32_t CSR;      // control/status register
    uint32_t AHBSTR;   // AHB peripheral clock reset register
    uint32_t CFGR2;    // clock configuration register 2
}RCC_t; // reset and clock control register map

#ifndef __STM32F10X_RCC_DOT_C__
extern RCC_t* RCC; // This is the global pointer to the RCC registers.

#endif

// RCC APB2 peripheral clock enable register bits
#define APB2ENR_USART1EN (14U)
#define APB2ENR_SPI1EN   (12U)
#define APB2ENR_TIM1EN   (11U)
#define APB2ENR_ADC2EN   (10U)
#define APB2ENR_ADC1EN    (9U)
#define APB2ENR_IOPEEN    (6U)
#define APB2ENR_IOPDEN    (5U)
#define APB2ENR_IOPCEN    (4U)
#define APB2ENR_IOPBEN    (3U)
#define APB2ENR_IOPAEN    (2U)
#define APB2ENR_AFIOEN    (0U)

#endif
