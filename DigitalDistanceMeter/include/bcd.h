/*
 * bcd.h
 *
 *  Created on: Dec 9, 2021
 *      Author: Anu
 */
#ifndef ECGR_5101_MSP430_INCLUDE_BCD_H_
#define ECGR_5101_MSP430_INCLUDE_BCD_H_

#include <include/7segDisplay.h>

typedef struct bcdPin
{
    uint8_t d;
    uint8_t c;
    uint8_t b;
    uint8_t a;
}bcdPin_Config_t;
void bcdDisplay_Init(port_e portNum, bcdPin_Config_t *setPin);
 void bcdDisplay_Set(port_e portNum, bcdPin_Config_t *setPin, uint8_t val);


#endif /* ECGR_5101_MSP430_INCLUDE_BCD_H_ */
