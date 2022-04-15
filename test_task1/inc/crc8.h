/*
 * crc8.h
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#ifndef SRC_TEST_TASK1_CRC8_H_
#define SRC_TEST_TASK1_CRC8_H_

#include "stdint.h"

void crc8_gen_table(uint8_t polynomial);
uint8_t crc8(uint8_t *p, uint16_t len);


#endif /* SRC_TEST_TASK1_CRC8_H_ */
