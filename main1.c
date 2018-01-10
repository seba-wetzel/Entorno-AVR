/*
 * main.c
 *
 *  Created on: 17 de abr. de 2017
 *      Author: xtian23
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "MyDefs.h"
#include "uart0.h"

int dato1=0;
int dato=0;

int dato2=0;
int dato3=0;
void PWM22 (int ICR1FIJO, int OCR1AVARIABLE, int OCR1BVARIABLE);

int main (void)
{

	DDRB |= (1 << DDB1)|(1 << DDB2); //configura salidas


PWM22(dato1,dato2,dato3);


}




void PWM22 (int ICR1FIJO, int OCR1AVARIABLE, int OCR1BVARIABLE)
{

	    ICR1 = ICR1FIJO;

	    TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
	    // set none-inverting mode
	    TCCR1A |= (1 << WGM11);
	    TCCR1B |= (1 << WGM12)|(1 << WGM13);
	    // set Fast PWM mode using ICR1 as TOP
	    TCCR1B |= (1 << CS10)|(1 << CS11);
	    //  prescaler

	    OCR1A = OCR1AVARIABLE;
	    OCR1B = OCR1BVARIABLE;

}

