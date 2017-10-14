#include "motorShield.h"

void shieldInit(sipo_u sipo){
	pinMode(sipo.data.port,  sipo.data.pin, OUTPUT);
	pinMode(sipo.clock.port, sipo.clock.pin,OUTPUT);
	pinMode(sipo.latch.port, sipo.latch.pin, OUTPUT);
}

void shiftOut(sipo_u sipo, uint8_t val){
								for (uint8_t i = 0; i < 8; i++)  {
																digitalWrite(sipo.data.port, sipo.data.pin, !!(val & (1 << i))); //Nos desplazamos por el byte, bit pot bit
																digitalWrite(sipo.clock.port, sipo.clock.pin, HIGH);
																digitalWrite(sipo.clock.port, sipo.clock.pin, LOW);
								}
								digitalWrite(sipo.latch.port, sipo.latch.pin, HIGH);
								digitalWrite(sipo.latch.port, sipo.latch.pin, LOW);
}
