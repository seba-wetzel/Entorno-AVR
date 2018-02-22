#include "Arduino.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static void __empty() {
    // Empty function to be override in main application
}
void timer1_OF(void) __attribute__ ((weak, alias("__empty")));
void timer0_OF(void) __attribute__ ((weak, alias("__empty")));

void timerConfig(timer_s timer){

//Set prescalers
switch (timer.timer) {
  //cli();

  case timer0: TCCR0A |= (timer.prescaler);  TCNT0 = 0; if(timer.mode == CTC)
  break;
  case timer1: TCCR1B |= (timer.prescaler);  TCNT1 = 0;
  break;
  case timer2: TCCR2A |= (timer.prescaler);

}



};

ISR(TIMER1_OVF_vect)
{
  timer1_OF();
}

ISR(TIMER0_OVF_vect)
{
  timer0_OF();
}
