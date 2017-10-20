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
								{B,4}, //Latch port/pin
								{D,7}  // Enable port/pin
};

motors_s motores [] = {
								{M3,{D,5}},
								{M4,{D,6}},
								{M3,{D,5}},
								{M2,{D,3}},
								{M1,{B,3}}
};
uint8_t cantidad_motores = sizeof(motores)/5;
// Main
int main(void) {
								init();
								serialBegin();
								pinMode(B,5,OUTPUT);  //Pin 13 de arduino (el del led)
								shieldInit(sipo, &motores, cantidad_motores);




// Main Loop

								while (1) {
																digitalWrite(B,5,HIGH);
																motorRun(M3,FORWARD);
																_delay_ms(2500);
																motorRun(M3,BACKWARD);
																_delay_ms(2500);
																motorRun(M3,BRAKE);
																_delay_ms(2500);
																puts(buffer);

  return 0;

}
}
// User Funtiones
