/*
 * bcd.c
 *
 *  Created on: Dec 9, 2021
 *      Author: Anu
 */
#include<include/bcd.h>
void bcdDisplay_Init(port_e portNum, bcdPin_Config_t *setPin)
{
    if(portNum == PORT_1)
       {
           gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->a), OUTPUT);
           gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->b), OUTPUT);
           gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->c), OUTPUT);
           gpioInit(PORT_1, (pin_num_e)findBitPos(setPin->d), OUTPUT);
       }
       else
       {
           gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->a), OUTPUT);
           gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->b), OUTPUT);
           gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->c), OUTPUT);
           gpioInit(PORT_2, (pin_num_e)findBitPos(setPin->d), OUTPUT);

       }

}


void bcdDisplay_Set(port_e portNum, bcdPin_Config_t *setPin, uint8_t val)
{
    uint8_t portVal;

    switch(val)
    {
    case 0:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->d);
        gpioSetPort(portNum, portVal);     // display 0
        break;

    case 1:
        portVal = (setPin->a );
        gpioSetPort(portNum, portVal);     // display 0
        break;

    case 2:
        portVal = ( setPin->b );
        gpioSetPort(portNum, portVal);     // display 2
        break;

    case 3:
        portVal = (setPin->a + setPin->b);
        gpioSetPort(portNum, portVal);     // display 3
        break;
    case 4:
        portVal = ( setPin->c);
        gpioSetPort(portNum, portVal);     // display 4
        break;

   case 5:
       portVal = (setPin->a + setPin->c);
       gpioSetPort(portNum, portVal);     // display 5
       break;

    case 6:
        portVal = ( setPin->c + setPin->b );
        gpioSetPort(portNum, portVal);     // display 6
        break;

    case 7:
        portVal = (setPin->a + setPin->b + setPin->c);
        gpioSetPort(portNum, portVal);     // display 7
      break;

    case 8:
        portVal = ( setPin->d );
        gpioSetPort(portNum, portVal);    // display 8
        break;
    case 9:
        portVal = (setPin->a +  setPin->d );
        gpioSetPort(portNum, portVal);    // display 9
        break;

    default:
        portVal = ~(setPin->a + setPin->b + setPin->c + setPin->d);
        gpioSetPort(portNum, portVal);    // display -
        break;
    }
}
