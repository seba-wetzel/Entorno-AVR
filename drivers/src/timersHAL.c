/*!
   \file "timerHAL"
   \brief "File with all the functions to manipulate timers and its events"
   \author "Sebastian Wetzel"
   \date "24"/"02"/"2018"
*/

#include "Arduino.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static volatile uint32_t counter = 0;

/*!
   \brief "Empty function to be override in main application"
*/
static void __empty() {

}
void timer0_OF(void) __attribute__ ((weak, alias("__empty")));
void timer1_OF(void) __attribute__ ((weak, alias("__empty")));


void timerConfigHAL(timer_s timer){

//Set prescalers
switch (timer.timer) {
  cli();

  case timer0: TCCR0B |= (timer.prescaler);
  break;
  case timer1: TCCR1B |= (timer.prescaler);  TCNT1 = 0;
  break;
  case timer2: TCCR2A |= (timer.prescaler);

}

sei();

};

uint32_t millisHAL (void){
  uint32_t m;
  uint8_t oldSREG = SREG;
  cli();
  m = counter;
  SREG = oldSREG;
  return m;
}

ISR(TIMER1_OVF_vect)
{
  timer1_OF();
}

ISR(TIMER0_OVF_vect)
{
  counter++;
  timer0_OF();
}
