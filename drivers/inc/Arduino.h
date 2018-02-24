/*!
   \file "Arduino.h"
   \brief "C header with Arduino like API functions"
   \author "Sebastian Wetzel"
   \date "23"/"febrero"/"2018"
*/

// AVR Inludes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/sfr_defs.h>

// Standard Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef ARDUINO_H
#define ARDUINO_H

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#ifndef sbi
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#endif

#define noInterrupts() cli()

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

/**
 *Definition of timers (add more if is needed or supported)
 */
typedef enum{
  timer0, /**< Timer0 in atmega328, a 8bit timer */
  timer1, /**< Timer1 in atmega328, a 16bit timer */
  timer2 /**< Timer2 in atmega328, a 8bit timer */
} timers_e;

/**
 * Definition of prescalers (add more if is needed or supported)
 */
 typedef enum {
  p0    =0b000, /**< No prescaler, desactivated timer */
  p1    =0b001, /**< Prescaler in 1, same clock speed, no divider */
  p8    =0b010, /**< Prescaler divide clock by 8 */
  p64   =0b011, /**< Prescaler divide clock by 64 */
  p256  =0b100, /**< Prescaler divide clock by 265 */
  p1024 =0b101 /**< Prescaler divide clok by 1024 */
} prescaler_e;

//Mode of the timer
typedef enum{
  NORMAL = 0b000, /**< Run t'll reach the max and reset, no counter clear is performed(0xFF for timer0 and timer2, or 0xFFF for timer1) */
  CTC    = 0b010, /**< Reset to Zero when timmer reach TCNTx */
}mode_e;

typedef enum{
  none          = 0b000,
  overflow      = 0b001,
  compareMatchA = 0b010,
  compareMatchB = 0b100,
  inputCapture
} event_e;

//Estructura de timer
typedef struct{
  timers_e timer;
  prescaler_e  prescaler;
  mode_e mode;
  event_e event;
} timer_s;

void init();
// Definiciones de puerto serie


// Prototipos de funciones I/O
void digitalWrite(port_u puerto,const int pin, estado_u estado);
void pinMode (port_u puerto,const int pin, IO_u tipo);
estado_u digitalRead (port_u puerto,const int pin);

//Prototipos de funciones de timmers
void timerConfigHAL(timer_s);

uint32_t millisHAL (void);

//Prototipos de funciones de ADC
void analogConfig(void);
void analogWrite(void);



#endif
