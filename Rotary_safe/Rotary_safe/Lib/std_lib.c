/*
 * std_lib.c
 *
 * Created: 3/22/2017 14:00:00 AM
 * Author : Kristian Nørgaard Jensen
 * Description: Standard Library
 */

#include <avr/io.h>
#include "std_lib.h"

void pinMode(int pin, int mode, int pull_up) {
	//Handle port D pins
    if (pin >= 0 && pin <= 7) {
        switch (mode) {
            case OUTPUT:
                DDRD |= (1 << pin);
				PORTD &= ~(1 << pin);
                break;
            case INPUT:
				if (pull_up) {
					PORTD |= (1 << pin);
					DDRD &= ~(1 << pin);
				} else {
					PORTD &= ~(1 << pin);
					DDRD &= ~(1 << pin);
				}
                break;
        }
    } else if (pin >= 8 && pin <= 15) {
		//Handle port B pins
		int pin_ = pin - 8;
		switch (mode) {
			case OUTPUT:
			DDRB |= (1 << pin_);
			PORTB &= ~(1 << pin_);
			break;
			case INPUT:
			if (pull_up) {
				PORTB |= (1 << pin_);
				DDRB &= ~(1 << pin_);
				} else {
				PORTB &= ~(1 << pin_);
				DDRB &= ~(1 << pin_);
			}
			break;
		}
    } else if (pin >= 16 && pin <= 21) {
        //Handle port C pins
		int pin_ = pin - 16;
		switch (mode) {
			case OUTPUT:
			DDRC |= (1 << pin_);
			PORTC &= ~(1 << pin_);
			break;
			case INPUT:
			if (pull_up) {
				PORTC |= (1 << pin_);
				DDRC &= ~(1 << pin_);
				} else {
				PORTC &= ~(1 << pin_);
				DDRC &= ~(1 << pin_);
			}
			break;
		}
    }
}

void digitalWrite(int pin, int value) {
	//Handle port D pins
	if (pin >= 0 && pin <= 7) {
		switch (value) {
			case HIGH:
				PORTD |= (1 << pin);
				break;
			case LOW:
				PORTD &= ~(1 << pin);
				break;
		}
	} else if (pin >= 8 && pin <= 15) {
		//Handle port B pins
		int pin_ = pin - 8;
		switch (value) {
			case HIGH:
				PORTB |= (1 << pin_);
				break;
			case LOW:
				PORTB &= ~(1 << pin_);
				break;
		}
	} else if (pin >= 16 && pin <= 21) {
		//Handle port C pins
		int pin_ = pin - 14;
		switch (value) {
			case HIGH:
				PORTC |= (1 << pin_);
				break;
			case LOW:
				PORTC &= ~(1 << pin_);
				break;
		}
	}

}

/* Delay function by Farzad */
void delay(uint32_t ms) {
	uint32_t i = ms * 471;
	while(--i > 0);
}