/**************************
 *
 * @file    gpio.h
 *
 * @brief   This file contains functions for initializing msp430 gpio.
 *
 * @date    Aug 29, 2021
 *
 * @author  Vishakha Dixit, Anuradha
 *
 **************************/

#ifndef MSP_430_INCLUDE_GPIO_H_
#define MSP_430_INCLUDE_GPIO_H_

#include <include/common.h>

typedef enum direction
{
    INPUT  = 0,
    OUTPUT = 1
} dir_e;

void gpioInit(port_e portNum, pin_num_e pinNum, dir_e direction);

void gpioInitPort(port_e portNum, dir_e direction);

bool gpioGet(port_e portNum, pin_num_e pinNum);

void gpioSet(port_e portNum, pin_num_e pinNum, bool val);

void gpioSetPort(port_e portNum, uint8_t portVal);

void enableGpioInterrput(port_e portNum, pin_num_e pinNum);


#endif /* MSP_430_INCLUDE_GPIO_H_ */
