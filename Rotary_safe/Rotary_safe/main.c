/*
 * Rotary_safe.c
 *
 * Created: 3/29/2017 2:16:15 PM
 * Author : Kristian Nørgaard Jensen & Matej Majtan
 */ 

#include <avr/io.h>
#include "Lib/std_lib.h"
#include "Lib/usart_lib.h"
#include "Lib/rotEncLib.h"

void reset(void); 

int DR = 1; //Direction: 1 = CW & 0 = CCW
int r_DR;
const int code[4] = {9, 3, 5, 1}; //Code for the safe
int c_Digit = 0;
int detent = 0;
int locked = 1;

int main(void) {
	//Init components
	init_comp();
	//Main loop to handle the program
    while (1) {
		//Loop to handle the unlocking program
		while (locked) {
			r_DR = read_rot_encoder();	//Read the Rotary encoder
			if (r_DR == DR){ //Is the direction correct?
				//Yes:
				detent++; //detent++;
				if (detent == code[c_Digit]){ //Is detent == to code[c_Digit]?
					//Yes:
					c_Digit++; //c_digit++
					DR = DR ? 0 : 1; //Change the direction
					detent = 0;
					if (c_Digit > 3) { //Is c_digit > 3?
						//Yes:
						digitalWrite(B5, HIGH); //Light up the LED
						locked = 0; //Set locked to 0
					}
				}
			} else {
				//No: 
				reset(); //Reset variables
				blink_LED();//Blink the LED fast and reset everything
			}
			delay(2);
		}
		if (bit_clear(PINB, PINB7)){
			locked = 1;
			reset();
			digitalWrite(B5, LOW);
		}
    }
}

void reset(void) {
	detent = 0;
	c_Digit = 0;
	DR = 1;
}
