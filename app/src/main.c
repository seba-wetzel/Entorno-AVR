#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// Libraries Includes
#include "arduino.h"


// Self Inlude
#include "main.h"

// Variables


char buffer [] = "Hola mundo!";


// User Funtions Prototypes



// Main
int main(void) {
init();
serialBegin();
pinMode(B,5,OUTPUT);
								


// Main Loop

								while (1) {
digitalWrite(B,5,HIGH);
_delay_ms(500);
digitalWrite(B,5,LOW);
_delay_ms(500);
puts(buffer);
								}
								return 0;

}

// User Funtiones
