#ifndef UART_H_
#define UART_H_

#include <stdint.h>

void uart_init(void);
void uart_transmit(char data);
void uart_print_string(const char *text);
void uart_print_uint16(uint16_t value);

#endif