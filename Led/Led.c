/*
* Led.c
*
* Created: 30 May 2020 14:23:49
*  Author: Roxy
*/
#include "Led.h"
#include <avr/io.h>

void Led_Init(void)
{
	DDRB  = DDRB  | 0x02;   //am pus bitul B1 = 1 (setare ca output pentru comandare led)
	PORTB = PORTB & 0xfd;	// am pus bit B1 = 0 (pentru a comanda pinul B1 la nivel logic 0)
}

void Led_SetLed (Led_State State)
{
	if(State == LED_ON)
	{
		PORTB = PORTB | 0x02;
	}
	else
	{
		PORTB = PORTB & 0xfd;
	}
	
}