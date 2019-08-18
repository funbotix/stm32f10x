/* Minimal support to access the GPIO port registers */

#ifndef __STM32F10X_GPIO_DOT_H__
#define __STM32F10X_GPIO_DOT_H__

#include <stdint.h>

//-----------------------------------------------------------------------------
// STM32F10x GENERAL PURPOSE I/O PINS
//-----------------------------------------------------------------------------

// Define the base addresses of the GPIO port register maps.
#define PORTA_BASE (0x40010800U)
#define PORTB_BASE (0x40010C00U)
#define PORTC_BASE (0x40011000U)
#define PORTD_BASE (0x40011400U)
#define PORTE_BASE (0x40011800U)

typedef struct{
    volatile uint32_t CRL;  // port configuration register low
    volatile uint32_t CRH;  // port configuration register high
    volatile uint32_t IDR;  // port input data register
    volatile uint32_t ODR;  // port output data register
    volatile uint32_t BSRR; // port bit set/reset register
    volatile uint32_t BRR;  // port bit reset register
    volatile uint32_t LCKR; // port configuration lock register
}GPIO_t; // general purpose I/O port register map

#ifndef  __STM32F10X_GPIO_DOT_C__
// These are the global pointers to the GPIO port registers.
extern GPIO_t* PORTA;
extern GPIO_t* PORTB;
extern GPIO_t* PORTC;
extern GPIO_t* PORTD;
extern GPIO_t* PORTE;
#endif

#endif
