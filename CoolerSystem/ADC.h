/*
 * ADC.h
 *
 * Created: 12/8/2022 8:24:26 AM
 *  Author: AhmedMabrouk
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "std_macros.h"

void ADC_init(void);
int16_t ADC_read(uint8_t);

#endif /* ADC_H_ */