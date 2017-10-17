#include <avr/io.h>
#include <stdio.h>
#include <init.h>


/* Funcion para inicializar los puertos como entrada. */

void init (){
        DDRB = 0x00;
        DDRC = 0x00;
        DDRD = 0x00;
}

