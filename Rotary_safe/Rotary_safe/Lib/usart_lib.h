/*
 * usart_lib.h
 *
 * Created: 3/22/2017 11:56:35 AM
 * Author : Kristian Nørgaard Jensen
 * Description: Usart Library
 */


#ifndef USART_LIB_H_
#define USART_LIB_H_

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#define CR 15
#define LF 12

#define ONE 1
#define TWO 2

#define EVEN 1
#define ODD 2
#define NONE 0

#include <avr/io.h>

void init_usart(uint16_t baud_rate, uint8_t parity_bits, uint8_t stop_bits);
void usart_transmit_char(unsigned char data);
unsigned char usart_Receive(void);
void usart_transmit_string(char *str);
void tostring(char str[], int num);

#endif /* USART_LIB_H_ */