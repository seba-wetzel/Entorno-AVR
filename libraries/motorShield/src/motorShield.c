#include "motorShield.h"

static sipo_u sipoU;


void shieldInit(sipo_u sipo, motors_s *motor, uint8_t motores){
								pinMode(sipo.data.port,  sipo.data.pin, OUTPUT);
								pinMode(sipo.clock.port, sipo.clock.pin,OUTPUT);
								pinMode(sipo.latch.port, sipo.latch.pin, OUTPUT);
								pinMode(sipo.enable.port, sipo.enable.pin, OUTPUT);
								digitalWrite(sipo.enable.port, sipo.enable.pin,LOW);
                sipoU = sipo;
								for (size_t i = 0; i < motores; i++) {
									/* Configuramos cada pin de Enable de cada motor como salida, y lo activamos */
                  pinMode(motor[i].pin.port, motor[i].pin.pin, OUTPUT);
									digitalWrite(motor[i].pin.port, motor[i].pin.pin, HIGH);
								}

}


void motorRun(motor_e motor,movement_e movement){
								static uint8_t byte_u = 0b00000000;
								uint8_t a,b;

								switch (motor) {
								case M1: a = MOTOR1_A; b = MOTOR1_B;
																break;
								case M2: a = MOTOR2_A; b = MOTOR2_B;
																break;
								case M3: a = MOTOR3_A; b = MOTOR3_B;
																break;
								case M4: a = MOTOR4_A; b = MOTOR4_B;
																break;
								}

								switch (movement) {
								case FORWARD:  byte_u &= ~_BV(a); byte_u |= _BV(b); 
																break;
								case BACKWARD: byte_u |= _BV(a);  byte_u &= ~_BV(b); 
																break;
								case BRAKE:    byte_u &= ~_BV(a); byte_u &= ~_BV(b);
																break;
								}
								for(uint8_t i=0; i<8; i++){
									uint8_t temp = byte_u >>i;
									temp = temp & 1;
									printf("%i", temp);
								}
								printf("\n");

								shiftOut(sipoU,byte_u);

};

void shiftOut(sipo_u sipo, uint8_t val){
								for (uint8_t i = 0; i < 8; i++)  {
																digitalWrite(sipo.data.port, sipo.data.pin, !!(val & (1 << (7 - i)))); //Nos desplazamos por el byte, bit pot bit
																digitalWrite(sipo.clock.port, sipo.clock.pin, HIGH);
																digitalWrite(sipo.clock.port, sipo.clock.pin, LOW);
								}
								shiftOutLatch(sipo);
}

void shiftOutLatch(sipo_u sipo){
								digitalWrite(sipo.latch.port, sipo.latch.pin, HIGH);
								digitalWrite(sipo.latch.port, sipo.latch.pin, LOW);
}
