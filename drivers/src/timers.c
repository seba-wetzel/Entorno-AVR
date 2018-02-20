#include "Arduino.h"
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

static void __empty() {
    // Empty function to be override in main application
}
void timer1_OF(void) __attribute__ ((weak, alias("__empty")));


void timerConfig(timer_s timer){

//Set prescalers
switch (timer.timer) {
  cli();

  case timer0: TCCR0A |= (timer.prescaler);
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
