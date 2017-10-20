// AVR Includes
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Standard Includes
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


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


#ifndef GPIOS_H_
#define GPIOS_H_

// Prototipos de funciones I/O
void digitalWrite(port_u puerto,const int pin, estado_u estado);
void pinMode (port_u puerto,const int pin, IO_u tipo);
estado_u digitalRead (port_u puerto,const int pin);

#endif 
