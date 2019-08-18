/* Minimal support to access the GPIO port registers */

#define __STM32F10X_GPIO_DOT_C__

#include "stm32f10x_gpio.h"

// Create global variables that point to the GPIO port registers.
GPIO_t* PORTA = (GPIO_t*)PORTA_BASE;
GPIO_t* PORTB = (GPIO_t*)PORTB_BASE;
GPIO_t* PORTC = (GPIO_t*)PORTC_BASE;
GPIO_t* PORTD = (GPIO_t*)PORTD_BASE;
GPIO_t* PORTE = (GPIO_t*)PORTE_BASE;

#undef __STM32F10X_GPIO_DOT_C__
