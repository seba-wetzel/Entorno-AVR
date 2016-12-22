#ifndef F_CPU
#define F_CPU 16000000UL
#endif

// Libraries Includes
#include "arduino.h"
#include "lcd.h"
#include "ds18b20.h"

// Self Inlude
#include "main.h"

// Variables
estado_u estado;
port_u puertoEncoder = D;
int pinBoton = 2;
int pinA    = 3;
int pinB    = 4;
int valor;

int encoder0Pos = 0;
estado_u encoder0PinALast = LOW;
estado_u n = LOW;
char buffer [20];


// User Funtions Prototypes



// Main
int main(void) {
								init();
								serialBegin();
								lcd_t lcd1 = lcd_struct_default;
								lcd1.initialize();
								lcd1.clear();
								lcd1.cursor_off();
								lcd1.home();
								lcd1.flash_text((const uint8_t*)PSTR("Hola mi amor"),0,0);
								lcd1.flash_text((const uint8_t*)PSTR("Cosita linda "),0,1);
								_delay_ms(1500);
								lcd1.clear();
								pinMode(B,5,OUTPUT);
								pinMode(B,4,INPUT);
								digitalWrite(B,4,HIGH);
								int temp;


// Main Loop

								while (1) {

																estado = digitalRead(puertoEncoder,pinBoton);
																if (estado) {

																								digitalWrite(B,5,HIGH);
																								lcd1.flash_text((const uint8_t*)PSTR("Morite de envidia"),0,2);
																}
																else{
																								digitalWrite(B,5,LOW);

																}

																n = digitalRead(puertoEncoder, pinA);

																if ((encoder0PinALast == LOW) && (n == HIGH)) {

																								if (digitalRead(puertoEncoder,pinB) == LOW) {
																																encoder0Pos--;
																								}
																								else {
																																encoder0Pos++;
																								}

																								sprintf(buffer, "%i", encoder0Pos);
																								puts(buffer);
																								lcd1.clear();
																								lcd1.printf(LCD_USE_FLASH,0,0,PSTR("%-5d"),encoder0Pos);
																								ds18b20convert( &PORTC, &DDRC, &PINC, ( 1 << 0 ), 0 );
																								_delay_ms(1000);
																								ds18b20read( &PORTC, &DDRC, &PINC, ( 1 << 0 ), 0, &temp );
																								temp = temp / 16;
																								lcd1.printf(LCD_USE_FLASH,0,1,PSTR("%i"),temp);

																}


																encoder0PinALast = n;
								}
								return 0;

}

// User Funtiones
