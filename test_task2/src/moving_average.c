/*
 * moving_average.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */
#include "moving_average.h"

#define AVER_WINDOW					32

static int n = 0;
static uint16_t vals_array[AVER_WINDOW] = {0};
static uint16_t y = 0;

uint16_t average(uint16_t x){
	y = y + (x - vals_array[n]);
	vals_array[n] = x;
	n = (n + 1) % AVER_WINDOW;
	return y/AVER_WINDOW;
}
