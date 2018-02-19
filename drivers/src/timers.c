#include "Aruino.h"

void timerConfig(timer_s timer){

//Set prescalers
switch (timer.timer) {
  case timer0: TCCR0 = timer.prescaler;
  break;
  case timer1: TCCR1B = timer.prescaler;
  break;
  case timer2: TCCR2 = timer.prescaler;

}



};
