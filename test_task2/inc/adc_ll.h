/*
 * adc_ll.h
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#ifndef SRC_TEST_TASK2_ADC_LL_H_
#define SRC_TEST_TASK2_ADC_LL_H_

#include "stdint.h"

void adc_init();
void refresh_adc_value();
uint16_t get_actual_adc_val();

#endif /* SRC_TEST_TASK2_ADC_LL_H_ */
