/*
 * usart_ll.h
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#ifndef SRC_TEST_TASK1_USART_LL_H_
#define SRC_TEST_TASK1_USART_LL_H_

#include "stdint.h"

uint32_t usart_read(uint8_t *rx_arr, uint32_t len);
uint32_t usart_read_blocking(uint8_t *rx_arr, uint32_t len, uint32_t timeout_ms);
void usart_write(uint8_t *tx_arr, uint32_t len);

#endif /* SRC_TEST_TASK1_USART_LL_H_ */
