/*
 * Project.c
 *
 * Created: 12/1/2022 7:37:11 PM
 * Author : AhmedMabrouk
 */ 

#include "std_macros.h"
#include "seven_segment_cfg.h"
#include "seven_segment.h"
#include "timer2.h"
#include "ADC.h"
#include "LCD_cfg.h"
#include "LCD.h"

int main(void)
{
	LCD_init();

	ADC_init();
	timer2_PWM_init();
	
	uint8_t duty = 0, temp;
	
	// duty = 0 ==> temp = 25 ==> ADC = 52
	// duty = ? ==> temp = 30 ==> ADC = 62
	// For 1 degree temp ==> motor speed increes by 10%
	
    while (1)
    {
		temp = (ADC_read(0) - 52)/2 + 25;
		
		if ((temp <= 35) && (temp > 25)) {
			duty = (temp-25)*10;
		} else if (temp >= 35) {
			duty = 100;
		} else {
			duty = 0;
		}
		
		LCD_write_command(0x80);
		LCD_write_number(temp);

		
		timer2_PWM_Duty(duty);
    }
	
}