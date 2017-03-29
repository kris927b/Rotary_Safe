/*
 * Rotary_safe.c
 *
 * Created: 3/29/2017 2:16:15 PM
 * Author : Kristian Nørgaard Jensen & Matej Majtan
 */ 

#include <avr/io.h>
#include "Lib/std_lib.h"
#include "usart_lib.h"



int main(void) {
	//Init components
	int DR = 1; //Direction: 1 = CW & 0 = CCW
	int code[4] = {9, 3, 5, 1}; //Code for the safe
	int c_Digit = 0;
	int detent = 0;
	int locked = 1;

	//Main loop to handle the program
    while (1) {
		//Loop to handle the unlocking program
		while (locked) {
			//Read the Rotary encoder
			//Is the direction correct?
			//Yes:
				//detent++;
				//Is detent == to code[c_Digit]?
				//Yes:
					//c_digit++
					//Change the direction
					//Is c_digit > 3?
					//Yes:
						//Light up the LED
						//Set locked to 0
					//No:
						//break out of the if statements and read the RE again
				//No:
					//break out of the if statements and read the RE again
			//No: 
				//Blink the LED fast and reset everything
			delay(2);
		}
    }
}

