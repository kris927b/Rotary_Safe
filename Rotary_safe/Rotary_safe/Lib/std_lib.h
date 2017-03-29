/*
 * std_lib.h
 *
 * Created: 3/22/2017 14:00:00 AM
 * Author : Kristian Nørgaard Jensen
 * Description: Standard Library
 */

#ifndef STD_LIB_H_
#define STD_LIB_H_

#define D0 0
#define D1 1
#define D2 2
#define D3 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7

#define B0 8
#define B1 9
#define B2 10
#define B3 11
#define B4 12
#define B5 13
#define B6 14
#define B7 15

#define C0 16
#define C1 17
#define C2 18
#define C3 19
#define C4 20
#define C5 21

#define OUTPUT 1
#define INPUT 0

#define ENABLED 1
#define DISABLED 0

#define LOW 0
#define HIGH 1

#define bit_clear(reg, bit) (!(reg & (1 << bit)))
#define bit_set(reg, bit) (reg & (1 << bit))
#define loop_bit_clear(reg, bit) do {} while (bit_set(reg, bit))
#define loop_bit_set(reg, bit) do {} while (bit_clear(reg, bit))

#include <avr/io.h>

void pinMode(int pin, int mode, int pull_up);
void digitalWrite(int pin, int value);
void delay(uint32_t ms);

#endif /* STD_LIB_H_ */