/*
 * gpio_ll.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "gpio_ll.h"

/* Address of GPIO Port A peripheral */
#define GPIOA_BASE					0x40010800

/* Register ODR offset */
#define GPIO_ODR_OFFSET				0x0C

/* Address of ODR register for GPIO Port A */
#define GPIOA_ODR_ADDRESS			(GPIOA_BASE + GPIO_ODR_OFFSET)

struct GpioPort {
	uint16_t P0 : 1;
	uint16_t P1 : 1;
	uint16_t P2 : 1;
	uint16_t P3 : 1;
	uint16_t P4 : 1;
	uint16_t P5 : 1;
	uint16_t P6 : 1;
	uint16_t P7 : 1;
	uint16_t P8 : 1;
	uint16_t P9 : 1;
	uint16_t P10 : 1;
	uint16_t P11 : 1;
	uint16_t P12 : 1;
	uint16_t P13 : 1;
	uint16_t P14 : 1;
	uint16_t P15 : 1;
};

struct GpioPort* gpioPortA = (struct GpioPort*)(GPIOA_ODR_ADDRESS);

void gpio_init(){
	//init gpio that will be used as output push pull, i.e. port A
}

/* Function for toggling pin1 300Hz */
void toggle_pin1(){
	gpioPortA->P0 = (gpioPortA->P0 == 0) ? 1 : 0;
}

/* Function for toggling pin1 1kHz */
void toggle_pin2(){
	gpioPortA->P1 = (gpioPortA->P1 == 0) ? 1 : 0;
}

/* Function for toggling pin1 10kHz */
void toggle_pin3(){
	gpioPortA->P2 = (gpioPortA->P2 == 0) ? 1 : 0;
}
