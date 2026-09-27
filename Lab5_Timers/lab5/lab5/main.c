#define F_CPU 2000000UL

#include "timer0.h"
#include "uart0.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>

int main(void)
{
    uart_init();
    timer0_measurement_init();

    sei();

    while (1)
    {
        if (timer0_measurement_ready())
        {
            uint8_t count;
            uint32_t frequency_x100;

            count = timer0_get_half_period_count();

            if (count != 0)
            {
                /*
                 * f = 1 / [2 x count x 128 us]
                 *
                 * f x 100 =
                 * 100,000,000 /
                 * [2 x count x 128]
                 */
                frequency_x100 =
                    100000000UL /
                    (2UL * count * 128UL);

                uart_print_string("Frequency: ");

                uart_print_uint16(
                    (uint16_t)(frequency_x100 / 100)
                );

                uart_transmit('.');

                uint8_t decimal =
                    (uint8_t)(frequency_x100 % 100);

                if (decimal < 10)
                {
                    uart_transmit('0');
                }

                uart_print_uint16(decimal);
                uart_print_string(" Hz\r\n");
            }
        }
    }
}