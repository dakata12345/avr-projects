/*
 * usart_test.c
 *
 * Created: 9/9/2018 14:36:48
 * Author : dakata
 */ 

#include <avr/io.h>
#include <stdio.h>
#include "lcd.h"
#define F_CPU 20000000UL
#include <util/delay.h>

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

#define RXEN 4
#define TXEN 3
#define URSEL 7
#define UCSZ0 1
#define UCSZ1 2
#define RXC0 7
#define UDRE0 5

int main (void)
{
	char ReceivedByte;
	lcd_init();
	lcd_on();
	UCSR0B = (1 << RXEN) | (1 << TXEN);   // Turn on the transmission and reception circuitry
	UCSR0C =  (1 << UCSZ0) | (1 << UCSZ1); // Use 8-bit character sizes
	UCSR0C &=~(1<<UMSEL00 | 1<<UMSEL01);
	UBRR0H = 0x00; // Load upper 8-bits of the baud rate value into the high byte of the UBRR register
	UBRR0L = 0x81; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register
	char buffer[10];
	//LCD_init();
	for (;;) // Loop forever
	{
		//while ((UCSR0A & (1 << RXC0)) == 0); // Do nothing until data have been received and is ready to be read from UDR
		//ReceivedByte = UDR0; // Fetch the received byte value into the variable "ByteReceived"
		//LCD_print("Salut!");
		//sprintf(buffer,"Caracter %c",ReceivedByte);
		lcd_puts("Salut");
		_delay_ms(1000);
		lcd_clear();
		lcd_puts("Sunt eu picasso");
			_delay_ms(1000);
			lcd_clear();
		//while ((UCSR0A & (1 << UDRE0)) == 0); // Do nothing until UDR is ready for more data to be written to it
		//UDR0 = ReceivedByte+1; // Echo back the received byte back to the computer
	}
}