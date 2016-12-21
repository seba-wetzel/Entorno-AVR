#include <avr/io.h>
#include <stdio.h>
#include "arduino.h"

#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

// Funciones simil Arduino serial

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);

void serialBegin(void) {
    UBRR0H = UBRRH_VALUE;
    UBRR0L = UBRRL_VALUE;

    UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
    UCSR0B = _BV(RXEN0) | _BV(TXEN0);   /* Enable RX and TX */
    stdout = &uart_output;
    stdin  = &uart_input;
}

int uart_putchar(char c, FILE *cadena) {
    if (c == '\n') {
        uart_putchar('\r', cadena);
    }
    loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return 0;
}

int uart_getchar(FILE *cadena) {
    loop_until_bit_is_set(UCSR0A, RXC0);
    return UDR0;
}
// Funciones simil Arduino I/O

void digitalWrite(port_u puerto,const int pin, estado_u estado){
 switch (puerto)
 {
 case B: PORTB = (estado<<pin);
 break;
 case C: PORTC = (estado<<pin);
 break;
 case D: PORTD = (estado<<pin);
 break;
 }
}

estado_u digitalRead (port_u puerto,const int pin){

 switch (puerto)
 {
 case B: if(PINB & (1 << pin)){
		return HIGH;
}
	else{
		return LOW;
}

 break;
 case C: if(PINC & (1 << pin)){
		return HIGH;
}
	else{
		return LOW;
}
 break;
 case D: if(PIND & (1 << pin)){
		return HIGH;
}
	else{
		return LOW;
}
 break;
 }
return LOW;
}

void pinMode (port_u puerto,const int pin, IO_u tipo){
 switch (puerto)
 {
 case B: DDRB |= (tipo<<pin);
 break;
 case C: DDRC |= (tipo<<pin);
 break;
 case D: DDRD |= (tipo<<pin);
 break;
 }
}

void init (){
DDRB = 0x00;
DDRC = 0x00;
DDRD = 0x00;
}
