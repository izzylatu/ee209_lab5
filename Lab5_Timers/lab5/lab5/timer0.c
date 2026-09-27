#include "timer0.h"
#include "led.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

void timer0_init(){
	
	// Stop Timer0 while configuring it
	TCCR0A = 0;
	TCCR0B = 0;
	
	// Start counting from 0
	TCNT0 = 0;
	
	// Compare after 78 timer ticks (77+1) x 128us = 9.984ms
	OCR0A = 77;
	
	// CTC Mode
	TCCR0A = (1 << WGM01);
	
	// Clear any old compare match flags
	TIFR0 = (1 << OCF0A);
	
	// Prescaler 256
	TCCR0B = (1 << CS02);
}

uint8_t timer0_check_clear_compare(){
	
	// Check Output Compare Match A Flag
	if (TIFR0 & (1 << OCF0A)){
		
		// Clear compare flag
		TIFR0 = (1 << OCF0A);
		
		return 1;
	}
	return 0;
}