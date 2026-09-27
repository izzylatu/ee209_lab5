/*
 * lab5.c
 *
 * Created: 27/09/2026 6:20:19 pm
 * Author : mutil
 */ 

#include <avr/io.h>

void led_init(void) {
	DDRB |= (1 << PORTB);
	DDRC = 0x00;
	DDRD = 0x00;
}

int main(void)
{
    
	led_init();
	
    while (1) 
    {
    }
}

