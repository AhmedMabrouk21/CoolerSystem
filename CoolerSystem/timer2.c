/*
 * timer2.c
 *
 * Created: 12/25/2022 11:54:00 AM
 *  Author: AhmedMabrouk
 */ 

#include "timer2.h"

void timer2_PWM_init(void) {
	SETBIT(DDRD,7); // set OC2 as output
	TCCR2 |= (1<<COM21) | (1<<WGM20) | (1<<WGM21) | (1<<CS22) | (1<<CS21) | (1<<CS20); // 1024 prescaler
}

void timer2_PWM_Duty(uint8_t duty) {
	OCR2 = duty*2.55;
}