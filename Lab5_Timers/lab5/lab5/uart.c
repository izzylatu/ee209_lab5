#define F_CPU 2000000UL

#include "uart0.h"

#include <avr/io.h>

void uart_init(void)
{
	// 9600 baud at 2 MHz, normal asynchronous mode:
	// UBRR0 = 2,000,000/(16*9600) - 1 ? 12
	UBRR0H = 0;
	UBRR0L = 12;

	// Enable transmitter
	UCSR0B = (1 << TXEN0);

	// 8 data bits, no parity, 1 stop bit
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_transmit(char data)
{
	while (!(UCSR0A & (1 << UDRE0)))
	{
	}

	UDR0 = data;
}

void uart_print_string(const char *text)
{
	while (*text != '\0')
	{
		uart_transmit(*text);
		text++;
	}
}

void uart_print_uint16(uint16_t value)
{
	char digits[5];
	uint8_t index = 0;

	if (value == 0)
	{
		uart_transmit('0');
		return;
	}

	while (value > 0)
	{
		digits[index] = (value % 10) + '0';
		value /= 10;
		index++;
	}

	while (index > 0)
	{
		index--;
		uart_transmit(digits[index]);
	}
}