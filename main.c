/* Very simple app designed to help verify hardware and software tool setups */

#include <stdint.h>
#include "macros.h"
#include "stm32f10x.h"

//-----------------------------------------------------------------------------

enum{
    ON = 1,
    OFF = 0
};

void set_LED(const uint8_t state){
    // LED is on port C bit 13 and turns on when driven low
    if(state){
        PORTC->ODR &= ~BIT(13); // clear port C bit 13 (turn LED on)
    }else{
        PORTC->ODR |= BIT(13); // set port C bit 13 (turn LED off)
    }
}

//-----------------------------------------------------------------------------

// The default clock source on startup is an 8 MHz internal high speed clock.
#define CLOCK_FREQUENCY (8000000) // 8 MHz
#define CLOCK_SECONDS (1.0f/(float)CLOCK_FREQUENCY) // 125 usecs
#define CLOCKS_PER_DELAY_CYCLE (5)
#define DELAY_CYCLE_SECONDS ((float)CLOCKS_PER_DELAY_CYCLE*CLOCK_SECONDS) // 625 usecs

// Macros to compute num required delay cycles for seconds or milliseconds
#define DELAY_SECONDS(seconds) ((unsigned)((float)seconds/DELAY_CYCLE_SECONDS)+0.5f)
#define DELAY_MSECS(msecs)((unsigned)((float)DELAY_SECONDS((msecs)/1000.0f)+0.5))

void delay(uint32_t cycles){ // super-primitive el-cheapo-deluxe blocking delay function
    while(cycles--);
}

//-----------------------------------------------------------------------------

void initialize(void){ // Initialize microcontroller and board features.

    // Enable the clock for the GPIO port C peripheral.
    RCC->APB2ENR |= BIT(APB2ENR_IOPCEN); 

    // Configure GPIO port C bit 13 as an output I/O pin.
    // Clear CNF13 and MODE13 fields.
    PORTC->CRH &= ~0x00F00000;

    // CNF13=0 (general purpose push-pull output)
    // MODE13=1 (output has max speed of 10 MHz) 
    PORTC->CRH |=  0x00100000;

    set_LED(ON);
}

//-----------------------------------------------------------------------------

int main(){
    initialize();

    // Pulse the heartbeat LED (blink-blink-wait-wait) once/second
    const uint32_t delay_count = DELAY_MSECS(125);  
    const uint8_t pattern = 0x05;
    uint8_t index = 7;
    for(;;){
        if(++index > 7){
            index = 0; // the pattern repeats once/second (8 * 125 msecs)
        }
        const uint8_t state = (pattern & BIT(index)) ? ON : OFF;
        set_LED(state);
        delay(delay_count);
    }
    return 0;
} 