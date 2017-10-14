#ifndef MOTORSHIELD_H
#define MOTORSHIELD_H

#include "arduino.h"

typedef struct{
  port_u puerto;
  uint8_t pin
} pins_u;

//Prototipos de funciones

void shiftOut(pins_u dataPin, pins_u clockPin, uint8_t val);













#endif
