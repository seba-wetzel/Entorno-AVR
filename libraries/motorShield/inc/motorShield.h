#ifndef MOTORSHIELD_H
#define MOTORSHIELD_H

#include "Arduino.h"


// Bit positions in the 74HCT595 shift register output
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR4_A 0
#define MOTOR4_B 6
#define MOTOR3_A 5
#define MOTOR3_B 7

typedef enum {
        M1,
        M2,
        M3,
        M4
}motor_e;

typedef struct{
  motor_e motor;
  pins_s pin;
}motors_s;

typedef enum {
        FORWARD,
        BACKWARD,
        BRAKE
}movement_e;



typedef struct {
        pins_s data;
        pins_s clock;
        pins_s latch;
        pins_s enable;
} sipo_u;

//Prototipos de funciones
void motorRun(motor_e,movement_e);

void shieldInit(sipo_u, motors_s *, uint8_t);
void shiftOut(sipo_u, uint8_t val);
void shiftOutLatch(sipo_u);













#endif
