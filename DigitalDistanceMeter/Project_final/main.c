#include <msp430g2553.h>
#include<include/gpio.h>
#include <msp430.h>
#include <include/timer.h>
#include <include/gpio.h>
#include <include/7segDisplay.h>
#include <include/bcd.h>
#include <stdbool.h>

int miliseconds;
int distance;
long sensor;
bool swithPress = false;

void main(void)
{
    int stDistmsb;
    int stDistlsb;
    int temp1,temp2,temp3;


  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;                     // submainclock 1mhz
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

  CCTL0 = CCIE;                             // CCR0 interrupt enabled
  CCR0 = 1000;                              // 1ms at 1mhz
  TACTL = TASSEL_2 + MC_1;                  // SMCLK, upmode
  bcdPin_Config_t bcd1;

      bcd1.a = BIT4;
      bcd1.b = BIT5;
      bcd1.c = BIT6;
      bcd1.d = BIT7;

      bcdPin_Config_t bcd2;

      bcd2.a = BIT0;
      bcd2.b = BIT1;
      bcd2.c = BIT2;
      bcd2.d = BIT3;

      bcdDisplay_Init(PORT_1, &bcd1);
      bcdDisplay_Init(PORT_2, &bcd2);

  P1IFG  = 0x00;                //clear all interrupt flags
  _BIS_SR(GIE);                         // global interrupt enable

 while(1){
    P1IE &= ~0x01;          // disable interupt
    P1DIR |= 0x02;          // trigger pin as output
    P1OUT |= 0x02;          // generate pulse
    __delay_cycles(10);             // for 10us
    P1OUT &= ~0x02;                 // stop pulse
    P1DIR &= ~0x04;         // make pin P1.2 input (ECHO)
        P1IFG = 0x00;                   // clear flag just in case anything happened before
    P1IE |= 0x04;           // enable interupt on ECHO pin
    P1IES &= ~0x04;         // rising edge on ECHO pin
    __delay_cycles(30000);          // delay for 30ms (after this time echo times out if there is no object detected)
    distance = sensor/58;           // converting ECHO lenght into cm
    temp1 = distance/10;
    temp2 = temp1%10;
    temp3 = temp1/10;
//    stDistmsb = (int)distance;
//    stDistlsb = (int)distance % 10;
    bcdDisplay_Set(PORT_1, &bcd1, temp3);
    bcdDisplay_Set(PORT_2, &bcd2, temp2);
 }
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{

    if(P1IFG&0x04)  //is there interrupt pending?
        {
          if(!(P1IES&0x04)) // is this the rising edge?
          {
            TACTL|=TACLR;   // clears timer A
            miliseconds = 0;
            P1IES |= 0x04;  //falling edge
          }
          else
          {
            sensor = (long)miliseconds*1000 + (long)TAR;    //calculating ECHO lenght

          }
    P1IFG &= ~0x04;             //clear flag
    }
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
    __disable_interrupt();
    miliseconds++;
    TA1CCTL1 &= ~(CCIFG);
    __enable_interrupt();
}
