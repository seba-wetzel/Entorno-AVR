// AVR Includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Standard Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern FILE uart_output;
extern FILE uart_input;

#ifndef UART0_H_
#define UART0_H_

int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);
void serialBegin(void);

#endif

