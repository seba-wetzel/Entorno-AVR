#include "motorShield.h"




void shiftOut(pins_u dataPin, pins_u clockPin, uint8_t val){
		for (uint8_t i = 0; i < 8; i++)  {
			digitalWrite(dataPin.puerto, dataPin.pin, !!(val & (1 << i)));   //Nos desplazamos por el byte, bit pot bit


		digitalWrite(clockPin.puerto, clockPin.pin, HIGH);
		digitalWrite(clockPin.puerto, clockPin.pin, LOW);
	}
}
