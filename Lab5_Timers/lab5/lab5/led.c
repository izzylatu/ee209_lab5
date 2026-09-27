#include "led.h"

#include <avr/io.h>

void led_init() {
	// PB5 is an output
	DDRB |= (1 << DDB5);
	// LED should initially be off
	PORTB &= ~(1 << PORTB5);
}

void led_toggle(){
	// Writing 1 to PB5 toggles the PB5 output
	PORTB ^= (1 << PORTB5);
}