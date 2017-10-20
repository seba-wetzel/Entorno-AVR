#include <avr/io.h>
#include <stdio.h>
#include <Arduino.h>


#ifndef BAUD
#define BAUD 9600
#endif
#include <util/setbaud.h>

/* Funciones para el manejo del puerto serie. */

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(NULL, uart_getchar, _FDEV_SETUP_READ);


/* 'serialBegin' --> Funcion para inicializar el puerto serie. No
recibe ni devuelve parametros (void) y el BaudRate esta puesto a
9600 Baudios.*/

void serialBegin(void) {
        UBRR0H = UBRRH_VALUE;
        UBRR0L = UBRRL_VALUE;

        UCSR0C = _BV(UCSZ01) | _BV(UCSZ00); /* 8-bit data */
        UCSR0B = _BV(RXEN0) | _BV(TXEN0); /* Enable RX and TX */
        stdout = &uart_output;
        stdin  = &uart_input;
}

/* 'uart_putchar' --> Funcion */
int uart_putchar(char c, FILE *cadena) {
        if (c == '\n') {
                uart_putchar('\r', cadena);
        }
        loop_until_bit_is_set(UCSR0A, UDRE0);
        UDR0 = c;
        return 0;
}

/* 'uart_getchar' --> Funcion */

int uart_getchar(FILE *cadena) {
        loop_until_bit_is_set(UCSR0A, RXC0);
        return UDR0;
}

