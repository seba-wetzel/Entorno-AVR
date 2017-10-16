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

typedef enum {
        M1,
        M2,
        M3,
        M4
}motor_e;

typedef enum {
        FORWARD,
        BACKWARD,
        BRAKE
}movement_e;

typedef struct {
        port_u port;
        uint8_t pin;
} pins_s;

typedef struct {
        pins_s data;
        pins_s clock;
        pins_s latch;
} sipo_u;

//Prototipos de funciones
void motorRun(motor_e,movement_e);

void shieldInit(sipo_u);
void shiftOut(sipo_u, uint8_t val);
void shiftOutLatch(sipo_u);













#endif
