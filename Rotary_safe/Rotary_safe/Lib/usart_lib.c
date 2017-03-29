/*
 * Usart_Lib.c
 *
 * Created: 3/22/2017 11:56:35 AM
 * Author : Kristian Nørgaard Jensen
 * Description: Usart Library
 */ 
#define BAUD(BAUD_RATE) ((((F_CPU / 16) + (BAUD_RATE / 2)) / (BAUD_RATE)) - 1)

#include <avr/io.h>
#include <string.h>
#include "usart_lib.h"

/* Function to initialize the Usart behavior						*/
/* baud_rate is a number as ex. 9600								*/
/* parity_bits can either be NONE, EVEN or ODD						*/
/* stop_bits can either be ONE or TWO								*/
/* parity_bits and stop_bits have been defined in the header file	*/
void init_usart(uint16_t baud_rate, uint8_t parity_bits, uint8_t stop_bits) {
	UCSR0B |= (1 << TXEN0) | (1 << RXEN0); //Enable USART Transmitter and receiver
	UBRR0H = (BAUD(baud_rate) >> 8);
	UBRR0L = BAUD(baud_rate); //Set the baud rate to 9600

	/* Setting the parity bits for USART transmission */
	switch (parity_bits) {
		case NONE:
			UCSR0C &= ~(1 << UPM00) & ~(1 << UPM01);
			break;
		case EVEN:
			UCSR0C |= (1 << UPM01);
			UCSR0C &= ~(1 << UPM00);
			break;
		case ODD:
			UCSR0C |= (1 << UPM00) | (1 << UPM01);
			break;
	}

	/* Setting the stop bits for USART transmission */
	switch (stop_bits) {
		case ONE:
			UCSR0C &= ~(1 << USBS0);
			break;
		case TWO:
			UCSR0C |= (1 << USBS0);
			break;
	}
	
	/* Transmit size is 8-bits */
	UCSR0C |= (3 << UCSZ00);
}


/* Receive data from USART							*/
/* Returns the received data in the format of char	*/
unsigned char usart_Receive(void) {
	/* Wait for data to be received */
	while ( !(UCSR0A & (1<<RXC0)) );
	/* Get and return received data from buffer */
	return UDR0;
}


/* Transmit data in the format of char				*/
/* Data is a single character from the ascii table	*/
void usart_transmit_char(unsigned char data) {
	while(!(UCSR0A & (1 << UDRE0))); //Wait for transmitter to be done
	UDR0 = data; //Transmit data
}


/* Transmit a string through USART	*/
/* str is an array of characters	*/
void usart_transmit_string(char *str) {
	uint16_t len = strlen(str); // Find the length of the string
	for(int i = 0; i < len; i++) { //Loop through the array of characters
		usart_transmit_char(str[i]);
	}
} 


/* Convert a number to a string						*/
/* str is an empty array to contain the new string	*/
/* num is the number to convert						*/
void tostring(char str[], int num) {
	int i, rem, len = 0, n;
	
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}

	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}