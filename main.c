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

void initialize(void){ // Initialize microcontroller and board features.

    // Enable the clock for the GPIO port C peripheral.
    RCC->APB2ENR |= BIT(APB2ENR_IOPCEN); 

    // Configure GPIO port C bit 13 as a 10 MHz max speed output I/O pin.
    // Set CNF13 field to 0 (general purpose push-pull output)
    // Set MODE13 field to 1 (output has max speed of 10 MHz) 
    PORTC->CRH &= ~0x00F00000;
    PORTC->CRH |=  0x00100000;

    set_LED(ON);

    // Configure the systick timer for 1 msec tick rate (resolution of elapsed time measurements).
    set_systick_frequency(1000);
}

//-----------------------------------------------------------------------------

int main(){
    initialize();

    // Pulse the heartbeat LED (blink-blink-wait-wait) once/second
    const uint8_t pattern = 0x05;
    uint8_t index = 7;
    uint32_t ticker = get_ticker();
    for(;;){
        if(elapsed_ticks(ticker) >= 125){ // execute the heartbeat LED update code once every 125 msecs
            ticker = get_ticker();
            if(++index > 7){
                index = 0; // the pattern repeats once/second (8 * 125 msecs)
            }
            const uint8_t state = (pattern & BIT(index)) ? ON : OFF;
            set_LED(state);
        }
        // other code can run while waiting for the heartbead LED update interval to expire
    }
    return 0;
} 