/*
 * usart_ll.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "usart_ll.h"

#define USART_RX_BUF_LEN				1024

/* Circular buffer */
static uint8_t usart_rx_buf[USART_RX_BUF_LEN];

/* Position of rx data tail in rx buffer, changes when every new data chunk incoming
 * to USART (in uart irq handler, on Idle Line detecton interrupt)
 */
static volatile uint32_t rx_data_tail = 0;

/* Position of tag that corresponds to data amount that was read from rx buffer, changes
 * when usart_read function is called
 */
static volatile uint32_t read_pos = 0;

void usart_init(){
	//Initialize USART in DMA circular buffer mode, enable USART interrupts
}

/* Non blocking function that returns length of received data that was read from rx buffer
 * at the time, but not more then 'len' parameter
 */
uint32_t usart_read(uint8_t *rx_arr, uint32_t len){
	uint32_t data_was_read = 0;
	if(read_pos < rx_data_tail){
		/* Just read data between read_pos and rx_data_tail */
		data_was_read = (len <= rx_data_tail - read_pos) ? len : rx_data_tail - read_pos;
		memcpy(rx_arr, &usart_rx_buf[read_pos], data_was_read);
		read_pos += data_was_read;
	} else if(read_pos > rx_data_tail){
		/* Read data from read_pos to end of usart_rx_buf */
		data_was_read = (len <= USART_RX_BUF_LEN - read_pos) ? len : USART_RX_BUF_LEN - read_pos;
		memcpy(rx_arr, &usart_rx_buf[read_pos], data_was_read);
		read_pos += data_was_read;

		if(data_was_read < len){
			/* Append to rx_arr part of data from start circular buffer */
			uint32_t data_to_read = (len <= data_was_read + rx_data_tail) ? len - data_was_read : rx_data_tail;
			memcpy(&rx_arr[data_was_read], &usart_rx_buf[0], data_to_read);
			data_was_read += data_to_read;
			read_pos = data_to_read;
		}
	}
	return data_was_read;
}

/* Blocks until until all requested data copied to rx_arr, or timeout occured
 */
uint32_t usart_read_blocking(uint8_t *rx_arr, uint32_t len, uint32_t timeout_ms){
	uint32_t start_tick = get_tick_ms();
	uint32_t data_received_total = 0;
	while((data_received_total < len) && (get_tick_ms() - start_tick) < timeout_ms){
		data_received_total += usart_read(&rx_arr[data_received_total], len - data_received_total);
	}
	return data_received_total;
}

void usart_write(uint8_t *tx_arr, uint32_t len){
	//write data to usart
}
