#ifndef TIMER0_H_
#define TIMER0_H_

#include <stdint.h>

void timer0_measurement_init(void);
uint8_t timer0_measurement_ready(void);
uint8_t timer0_get_half_period_count(void);

#endif