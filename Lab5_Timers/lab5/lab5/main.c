/*
 * lab5.c
 *
 * Created: 27/09/2026 6:20:19 pm
 * Author : mutil
 */ 

#define F_CPU 2000000UL

#include <avr/io.h>
#include <util/delay.h>

void led_init(void) {
	DDRC = 0x00;
	DDRD = 0x00;
}

int main(void)

{
	
	// 2Hz frequency and 75% duty cycle
	// Period of 0.5s, Ton = 0.375s and Toff = 0.125s
	
	led_init();
	
    while (1) 
    {
		// LED on
		PORTB |= (1 << PORTB5);
		_delay_ms(375);
		
		// LED off
		PORTB &= ~(1 << PORTB5);
		_delay_ms(125);
    }
}

