/*
 * main.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "crc8.h"
#include "usart_ll.h"

void main(){
	usart_init();
	crc8_gen_table(0x7);

	trans_proto_echo();

	while(1){

	}
}
