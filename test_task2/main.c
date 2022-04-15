/*
 * main.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "adc_ll.h"
#include "gpio_ll.h"
#include "tim_ll.h"

void main(){
	adc_init();
	gpio_init();
	timer_init();

	while(1){
		printf("Averaged ADC value: %u\n", get_actual_adc_val());
		delay_ms(1000);
	}
}
