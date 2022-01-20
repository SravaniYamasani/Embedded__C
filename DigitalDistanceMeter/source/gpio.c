/**************************
 *
 * @file    gpio.c
 *
 * @brief   This file contains definition of functions for initializing msp430 gpio.
 *
 * @date    Aug 29, 2021
 *
 * @author  Vishakha Dixit, Anuradha
 *
 **************************/

#include "include/gpio.h"
#include <stdint.h>


/**************************
 * @brief       This function initializes the gpio pin based on the direction provided.
 *
 * @param [in]  portNum, pinNum, direction
 *
 * @return      NULL
 **************************/
void gpioInit(port_e portNum, pin_num_e pinNum, dir_e direction)
{
    if (portNum == PORT_1)
    {
        if( direction == INPUT )
        {
            //set direction
            P1DIR &= ~(1 << pinNum);
            //enable pull up resistor
            P1REN |= 1 << pinNum;
        }
        else
        {
            //set direction
            P1DIR |= 1 << pinNum;
        }

        //Setting initial value to 1
        P1OUT |= 1 << pinNum;
    }
    else
    {
        if( direction == INPUT )
        {
            //set direction
            P2DIR &= ~(1 << pinNum);
            //enable pull up resistor
            P2REN |= 1 << pinNum;
        }
        else
        {
            //set direction
            P2DIR |= 1 << pinNum;
        }

        //Select alternate function for using pins as GPIO
        if((pinNum == PIN_6) || (pinNum == PIN_7))
        {
            P2SEL &= ~(1 << pinNum);
            P2SEL2 &= ~(1 << pinNum);
        }

        //Setting initial value to 1
        P2OUT |= 1 << pinNum;
    }
}


/**************************
 * @brief       This function initializes the gpio port on the direction provided.
 *
 * @param [in]  portNum, direction
 *
 * @return      NULL
 **************************/
void gpioInitPort(port_e portNum, dir_e direction)
{
    //Set Input/Output direction for given port
    if( (portNum == PORT_1) && (direction == INPUT) )
    {
        P1DIR &= ~(0x0F);
    }
    else if( (portNum == PORT_1) && (direction == OUTPUT) )
    {
        P1DIR |= 0xFF;
    }
    else if(portNum == PORT_2)
    {
        if(direction == INPUT)
        {
            P2DIR &= ~(0xFF);
        }
        else
        {
            P2DIR |= 0xFF;
        }

        //Select alternate function for using pins 6, 7 as GPIO
        P2SEL &= ~(0xC0);
        P2SEL2 &= ~(0xC0);
    }

    //Setting initial value to 1
    P1OUT |= 0x00;
    P2OUT |= 0x00;
}


/**************************
 * @brief       This function is used to get the switch status
 *
 * @param [in]  portNum, pinNum
 *
 * @return      bool  Status of the switch
 **************************/
bool gpioGet(port_e portNum, pin_num_e pinNum)
{
    bool val;
    uint8_t pinMask;

    pinMask = 1 << pinNum;

    if (portNum == PORT_1)
    {
        val = (bool) (P1IN & pinMask);
    }
    else
    {
        val = (bool) (P2IN & pinMask);
    }

    return val;
}


/**************************
 * @brief       This function sets the gpio pin as either high or low based on switch status
 *
 * @param [in]  portNum, pinNum, val
 *
 * @return      NULL
 **************************/
void gpioSet(port_e portNum, pin_num_e pinNum, bool val)
{
    uint8_t pinMask;
    pinMask = 1 << pinNum;

    if(val == 1)
    {
        if (portNum == PORT_1)
        {
            P1OUT |= pinMask;
        }
        else
        {
            P2OUT |= pinMask;
        }
    }
    else
    {
        if (portNum == PORT_1)
        {
            P1OUT &= ~(pinMask);
        }
        else
        {
            P2OUT &= ~(pinMask);
        }
    }
}


/**************************
 * @brief       This function sets the gpio port pins as either high or low based on port num and value provided.
 *
 * @param [in]  portNum, portVal
 *
 * @return      NULL
 **************************/
void gpioSetPort(port_e portNum, uint8_t portVal)
{
    if (portNum == PORT_1)
    {
        P1OUT = portVal;
    }
    else
    {
        P2OUT = portVal;
    }
}

void enableGpioInterrput(port_e portNum, pin_num_e pinNum)
{
    uint8_t pinMask;
    pinMask = 1 << pinNum;

    if (portNum == PORT_1)
    {
        P1IE |= pinMask;                       //interrupt enabled
        P1IES |= pinMask;                      //Hi/lo edge
        P1IFG &= ~pinMask;                     //IFG cleared
    }
    else
    {
        P2IE |= pinMask;                       //interrupt enabled
        P2IES |= pinMask;                      //Hi/lo edge
        P2IFG &= ~pinMask;                     //IFG cleared
    }
}
