/*
 * lab5.c
 *
 * Created: 27/09/2026 6:20:19 pm
 * Author : mutil
 */ 

#define F_CPU 2000000UL

#include "timer0.h"
#include "led.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void){

	led_init();	
	timer0_init();
	
	// Enable global interrupts 
	sei();
	
	while(1){
	}
}