/*
 * transport_protocol.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "tranport_protocol.h"
#include "usart_ll.h"
#include "crc8.h"

#define PAYLOAD_LEN_MAX			255U
#define PREAMBLE_VALUE			0xFFU
#define RX_TIMEOUT_VALUE		0xFFFFFFFFU

struct Packet {
	uint8_t preamble; 					// преамбула = 0xFF
	uint8_t cnt; 						// счетчик пакетов
	uint8_t type; 						// тип пакета
	uint8_t length; 					// длина поля данных
	uint8_t data[PAYLOAD_LEN_MAX + 1]; 	// массив данных, плюс место под CRC8
};

static struct Packet packet;

void trans_proto_echo(){
	while(1){
		/* Wait for preamble symbol */
		while(1){
			usart_read_blocking(&packet.preamble, sizeof(packet.preamble), RX_TIMEOUT_VALUE);
			if(packet.preamble == PREAMBLE_VALUE){
				/* Receive other header data */
				usart_read_blocking(&packet.cnt, sizeof(packet.cnt) + sizeof(packet.type) + sizeof(packet.length), RX_TIMEOUT_VALUE);
				break;
			}
		}

		/* Check length field and receive payload */
		if(packet.length > PAYLOAD_LEN_MAX + 1){
			/* Too big len, seems like here is some error */
			continue;
		}
		usart_read_blocking(&packet.data, packet.length, RX_TIMEOUT_VALUE);

		/* Data received, check crc */
		uint16_t crc_len = sizeof(packet.preamble) + sizeof(packet.cnt) + sizeof(packet.type) + sizeof(packet.length) + packet.length - 1;
		if(packet.data[packet.length - 1] != crc8((uint8_t)&packet, crc_len)){
			/* Wrong crc */
			continue;
		}

		/* Received packet is correct, form answer */
		/* Increment packet counter */
		packet.cnt++;

		/* Set MSB of packet type */
		packet.type |= (1 << 7);

		/* Calc crc */
		packet.data[packet.length - 1] = crc8((uint8_t)&packet, crc_len);

		/* Send response */
		usart_write((uint8_t*)&packet, crc_len + 1);
	}
}
