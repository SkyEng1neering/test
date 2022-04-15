/*
 * crc8.c
 *
 *  Created on: Apr 15, 2022
 *      Author: SkyEngineering
 */

#include "crc8.h"

static uint8_t crc8_table[256];

void crc8_gen_table(uint8_t polynomial) {
    int i, j;
    int curr;

    for (i = 0; i < 256; i++) {
        curr = i;
        for (j = 0; j < 8; ++j) {
            if ((curr & 0x80) != 0) {
                curr = (curr << 1) ^ (int) polynomial;
            } else {
                curr <<= 1;
            }
        }
        crc8_table[i] = curr & 0xff;
    }
}

uint8_t crc8(uint8_t *p, uint16_t len) {
    uint16_t i;
    uint16_t crc = 0x0;

    while (len--) {
        i = (crc ^ *p++) & 0xFF;
        crc = crc8_table[i];
    }
    return crc & 0xFF;
}
