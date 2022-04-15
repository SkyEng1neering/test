/*
 * adc_ll.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "adc_ll.h"
#include "moving_average.h"

volatile static uint16_t current_adc_value;

void adc_init(){
	//Initialise ADC in injected conversions mode
}

/* Return current ADC value */
static uint16_t get_adc_value(){
	uint16_t val = 0;
	//read ADC data to 'val'
	return val;
}

/* Function that should be called 100 times per second */
void refresh_adc_value(){
	current_adc_value = average(get_adc_value());
}

/* Return actual averaged ADC value */
uint16_t get_actual_adc_val(){
	return current_adc_value;
}
