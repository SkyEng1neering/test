/*
 * timers_callbacks.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "tim_ll.h"
#include "gpio_ll.h"
#include "adc_ll.h"

/* Call this callback in timer1 irq handler (300 times per second)
 */
void timer1_overflow_callback(){
	static uint32_t counter;

	/* Calls 300 times per second */
	toggle_pin1();

	if(counter % 3){
		/* Calls 100 times per second */
		refresh_adc_value();//
	}
	counter++;
}

/* Call this callback in timer2 irq handler (10k times per second)
 */
void timer2_overflow_callback(){
	static uint32_t counter;

	/* Calls 10k times per second */
	toggle_pin3();

	if(counter % 10){
		/* Calls 1k times per second */
		toggle_pin2();
	}
	counter++;
}
