#ifndef MOTORSHIELD_H
#define MOTORSHIELD_H

#include "arduino.h"

// Bit positions in the 74HCT595 shift register output
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR4_A 0
#define MOTOR4_B 6
#define MOTOR3_A 5
#define MOTOR3_B 7




typedef struct{
  port_u port;
  uint8_t pin
} pins_u;

typedef struct{
  pins_u data;
  pins_u clock;
  pins_u latch
} sipo_u;


//Prototipos de funciones
void shieldInit(sipo_u);
void shiftOut(sipo_u , uint8_t val);













#endif
