#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// Self Inlude
#include "main.h"
// Libraries Includes
#include "arduino.h"
#include "motorShield.h"



// Variables


char buffer [] = "Hola mundo!";


// User Funtions Prototypes
sipo_u sipo = {
								{B,0}, //Data port/pin
								{D,4}, //Clock port/pin
								{B,4} //Latch port/pin
};


// Main
int main(void) {
								init();
								serialBegin();
								pinMode(B,5,OUTPUT);
								pinMode(D,6,OUTPUT);
								digitalWrite(D,6, HIGH);
								shieldInit(sipo);



// Main Loop

								while (1) {
																digitalWrite(B,5,HIGH);
																_delay_ms(500);
																digitalWrite(B,5,LOW);
																_delay_ms(500);
																puts(buffer);
																motorRun(M4,FORWARD);
								}
								return 0;

}

// User Funtiones
