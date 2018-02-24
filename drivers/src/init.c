#include <avr/io.h>
#include <stdio.h>
#include <Arduino.h>


/* Funcion para inicializar los puertos como entrada. */

void init (){
        DDRB = 0x00;
        DDRC = 0x00;
        DDRD = 0x00;
        sbi(TCCR0A, WGM01);
        sbi(TCCR0A, WGM00);
        sbi(TCCR0B, CS01);
        sbi(TCCR0B, CS00);
        sbi(TIMSK0, TOIE0);
}
