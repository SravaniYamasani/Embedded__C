/**************************
 *
 * @file    gpio.c
 *
 * @brief   This file contains definition of functions for initializing 7 Segment Display and sets value on it.
 *
 * @date    Sept 08, 2021
 *
 * @author  Vishakha Dixit, Anuradha
 *
 **************************/

#include <include/7segDisplay.h>
#include <math.h>


/**************************
 * @brief       Utility function to find bit position for the given number.
 *
 * @param [in]  num
 *
 * @return      int8_t Bit position
 **************************/
 int8_t findBitPos(uint8_t num)
{
    int8_t retVal;
    if (num == 0)
        return 0;
    if ((num & (num-1)) == 0)
    {
        retVal = (int8_t)(log2f(num));
        return retVal;
    }
    else
        return -1;
}

/**************************
 * @brief       This function initializes the 7 segment display pins.
 *
 * @param [in]  portNum, *setPin
 *
 * @return      NULL
 **************************/
void sevenSegDisplay_Init(port_e portNum, sevenSegPin_Config_t *setPin)
{
    if(portNum == PORT_1)
    {
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->a), OUTPUT);
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->b), OUTPUT);
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->c), OUTPUT);
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->d), OUTPUT);
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->e), OUTPUT);
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->f), OUTPUT);
        gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->g), OUTPUT);
    }
    else
    {
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->a), OUTPUT);
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->b), OUTPUT);
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->c), OUTPUT);
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->d), OUTPUT);
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->e), OUTPUT);
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->f), OUTPUT);
        gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->g), OUTPUT);
    }
}


/**************************
 * @brief       This function displays the given value in 7 segment display.
 *
 * @param [in]  portNum, *setPin, val
 *
 * @return      NULL
 **************************/
void sevenSegDisplay_Set(port_e portNum, sevenSegPin_Config_t *setPin, uint8_t val)
{
    uint8_t portVal;

    switch(val)
    {
    case 0:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->d + setPin->e + setPin->f);
        gpioSetPort(portNum, portVal);     // display 0
        break;

    case 1:
        portVal = ~(setPin->b + setPin->c);
        gpioSetPort(portNum, portVal);     // display 1
        break;

    case 2:
        portVal = ~(setPin->a + setPin->b + setPin->d + setPin->e + setPin->g);
        gpioSetPort(portNum, portVal);     // display 2
        break;

    case 3:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->d + setPin->g);
        gpioSetPort(portNum, portVal);     // display 3
        break;

    case 4:
        portVal = ~(setPin->b + setPin->c + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);     // display 4
        break;

    case 5:
        portVal = ~(setPin->a + setPin->c + setPin->d + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);     // display 5
        break;

    case 6:
        portVal = ~(setPin->a + setPin->c + setPin->d + setPin->e + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);     // display 6
        break;

    case 7:
        portVal = ~(setPin->a + setPin->b + setPin->c);
        gpioSetPort(portNum, portVal);     // display 7
        break;

    case 8:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->d + setPin->e + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);    // display 8
        break;

    case 9:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->d + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);    // display 9
        break;

    case 10:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->e + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);    // display A
        break;

    case 11:
        portVal = ~(setPin->c + setPin->d + setPin->e + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);    // display b
        break;

    case 12:
        portVal = ~(setPin->a + setPin->d + setPin->e + setPin->f);
        gpioSetPort(portNum, portVal);    // display C
        break;

    case 13:
        portVal = ~(setPin->b + setPin->c + setPin->d + setPin->e + setPin->g);
        gpioSetPort(portNum, portVal);    // display d
        break;

    case 14:
        portVal = ~(setPin->a + setPin->d + setPin->e + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);    // display E
        break;

    case 15:
        portVal = ~(setPin->a + setPin->e + setPin->f + setPin->g);
        gpioSetPort(portNum, portVal);    // display F
        break;

    default:
        portVal = ~(setPin->g);
        gpioSetPort(portNum, portVal);    // display -
        break;
    }
}


