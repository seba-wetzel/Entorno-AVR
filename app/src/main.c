

// Self Inlude
#include "main.h"
// Libraries Includes
#include "Arduino.h"
#include "motorShield.h"
#include "FreeRTOS_AVR.h"



// Variables

uint32_t millis = 0;
char buffer [] = "Hola mundo!";
char buffer1 [] = "Chau mundo!";


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
void Blink (void *pvParameters);



// Main
int main(void) {

								init();
								serialBegin();
								pinMode(B,5,OUTPUT);  //Pin 13 de arduino (el del led)
								//shieldInit(sipo, &motores, cantidad_motores);
                pinMode(B,4,OUTPUT);
								xTaskCreate(Blink,  "Tarea boton", 256, NULL, 1,  NULL);

								vTaskStartScheduler();




// Main Loop

								while (1) {
																// digitalWrite(B,5,HIGH);
																// motorRun(M3,FORWARD);
																// _delay_ms(2500);
																// motorRun(M3,BACKWARD);
																// _delay_ms(2500);
																// motorRun(M3,BRAKE);
																// _delay_ms(2500);
																// puts(buffer);



								}
								return 0;

}


void Blink (void *pvParameters) {
								while(1) {
																//puts(buffer);

																	digitalWrite(B,5,!(digitalRead(B,5)));
																	millis = millisHAL();
																	sprintf(buffer, "%06lu", millis/1000);
																	puts(buffer );
																	vTaskDelay(1000);



								}
}


void loop(){

}
