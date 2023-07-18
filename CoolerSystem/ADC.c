/*
 * ADC.c
 *
 * Created: 12/8/2022 8:24:13 AM
 *  Author: AhmedMabrouk
 */ 

#include "ADC.h"

void ADC_init(void) {
	ADMUX  |= (1<<REFS0);
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

int16_t ADC_read(uint8_t ch) {
	ADMUX &= 0b11100000;
	ADMUX |= ch;
	SETBIT(ADCSRA,ADSC);
	while(READBIT(ADCSRA,ADSC) == 1){}
	
	return ADC;
}