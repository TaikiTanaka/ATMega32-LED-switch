/*
 * lab1.c
 *
 * Created: 4/17/2018 12:41:41 PM
 * Author : Work
 */ 

#include "avr.h"

int main(void)
{
    /* Replace with your application code */
	SET_BIT(DDRB,0); // SETS B0/R1 = 1 as output -- LED
	CLR_BIT(DDRB,1);//Sets B1 = 0 as input -- connected to button
    while (1) 
    {
		if(GET_BIT(PINB,1))//if B1 is receiving current
		{
			//don't want LED to light up
			CLR_BIT(PORTB, 0);
		}	
		//B1 is grounded and no current is going to B0
		else 
		{
			//flash LED
			SET_BIT(PORTB, 0);
			wait_avr(500);
			CLR_BIT(PORTB,0);
			wait_avr(500);
		}
    }
}

