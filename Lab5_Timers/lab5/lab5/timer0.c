#include "timer0.h"

#include <avr/io.h>
#include <avr/interrupt.h>

static volatile uint8_t half_period_count = 0;
static volatile uint8_t measurement_ready = 0;

void timer0_measurement_init(void)
{
	// PD2 / INT0 is an input
	DDRD &= ~(1 << DDD2);

	// Configure Timer0 in normal mode, initially stopped
	TCCR0A = 0;
	TCCR0B = 0;
	TCNT0 = 0;

	// INT0 triggers on any logical change:
	// ISC01 = 0, ISC00 = 1
	EICRA &= ~(1 << ISC01);
	EICRA |=  (1 << ISC00);

	// Clear any old INT0 interrupt flag
	EIFR = (1 << INTF0);

	// Enable INT0
	EIMSK |= (1 << INT0);
}

ISR(INT0_vect)
{
	if (PIND & (1 << PIND2))
	{
		// PD2 is now high, so this was a rising edge.
		// Reset and start Timer0 with prescaler 256.
		TCNT0 = 0;

		TCCR0B = (1 << CS02);
	}
	else
	{
		// PD2 is now low, so this was a falling edge.
		// Stop the timer.
		TCCR0B = 0;

		// Save the measured high-time count.
		half_period_count = TCNT0;
		measurement_ready = 1;
	}
}

uint8_t timer0_measurement_ready(void)
{
	return measurement_ready;
}

uint8_t timer0_get_half_period_count(void)
{
	uint8_t result;

	// Protect shared data from interrupt access
	uint8_t old_sreg = SREG;
	cli();

	result = half_period_count;
	measurement_ready = 0;

	SREG = old_sreg;

	return result;
}