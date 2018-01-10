// AVR Inludes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Standard Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef ARDUINO_H
#define ARDUINO_H


// Prototipos de funciones serial
int uart_putchar(char c, FILE *stream);
int uart_getchar(FILE *stream);
void serialBegin(void);
extern FILE uart_output;
extern FILE uart_input;


// Definiciones de puertos I/O
typedef enum port_e {
        B,
        C,
        D,
} port_u;

typedef enum {
        LOW  = 0,
        HIGH = 1,
} estado_u;

typedef enum {
        INPUT  = 0,
        OUTPUT = 1,
} IO_u;

typedef struct {
        port_u port;
        uint8_t pin;
} pins_s;

//Definition of timers (add more if is needed or supported)
typedef enum{
  timer0,
  timer1,
  timer2
} timers_e;

//Definition of prescalers (add more if is needed or supported)
typedef enum {
  p0    =0b000,
  p1    =0b001,
  p8    =0b010,
  p64   =0b011,
  p256  =0b100,
  p1024 =0b101
} prescaler_e;

//Estructura de timer0
typedef struct{
  timers_e,
  prescaler_e
} timmer_s;

void init();
// Definiciones de puerto serie


// Prototipos de funciones I/O
void digitalWrite(port_u puerto,const int pin, estado_u estado);
void pinMode (port_u puerto,const int pin, IO_u tipo);
estado_u digitalRead (port_u puerto,const int pin);

//Prototipos de funciones de timmers
void timerConfig(timer_s);
uint32_t millis (void);

//Prototipos de funciones de ADC
void analogConfig(void);
void analogWrite(void);



#endif
