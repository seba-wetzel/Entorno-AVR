#include <avr/io.h>
#include <stdio.h>
#include <Arduino.h>


/*Funciones para el manejo de puertos de entrada/salida que
posee el microcontrolador. */



/* 'digitalWrite' --> Funcion para escribir el pin de un puerto.
Los parametros que recibe esta funcion son:

port_u puerto: Puerto B,C o D.
const int pin: Numero del pin a escribir.
estado_u estado: Estado del pin 'HIGH' o 'LOW'. */

void digitalWrite(port_u puerto,const int pin, estado_u estado){
        switch (puerto)
        {
        case B: PORTB = (estado<<pin);
                break;
        case C: PORTC = (estado<<pin);
                break;
        case D: PORTD = (estado<<pin);
                break;
        }
}

/* 'digitalRead' --> Funcion para leer el estado de un pin de 
uno de los puertos del uC. Los parametros que recibe esta 
funcion son:

port_u puerto: Puerto B,C o D.
const int pin: Numero del pin a leer. */

estado_u digitalRead (port_u puerto,const int pin){

        switch(puerto) {

        case B: if(PINB & (1 << pin)) {
                        return HIGH;
        }
                else {
                        return LOW;
                }

                break;
        case C: if(PINC & (1 << pin)) {
                        return HIGH;
        }
                else {
                        return LOW;
                }
                break;
        case D: if(PIND & (1 << pin)) {
                        return HIGH;
        }
                else {
                        return LOW;
                }
                break;
        }
        return LOW;
}

/* 'pinMode' --> Funcion para configurar un pin de uno de 
los puertos del uC. Los parametros que recibe esta funcion
son:

port_u puerto: Puerto B,C o D.
const int pin: Numero del pin a configurar.
IO_u tipo: El estado del pin 'INPUT' o 'OUTPUT' */

void pinMode (port_u puerto,const int pin, IO_u tipo){
        switch (puerto) {

        case B: DDRB |= (tipo<<pin);
                break;
        case C: DDRC |= (tipo<<pin);
                break;
        case D: DDRD |= (tipo<<pin);
                break;
        }
}


