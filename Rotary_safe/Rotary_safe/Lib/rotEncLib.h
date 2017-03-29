#ifndef ROTENCLIB_H_
#define ROTENCLIB_H_

#include "std_lib.h"
#include <avr/io.h>

void init_comp();
uint8_t read_rot_encoder();
void blink_LED();
uint8_t readValue();

#endif