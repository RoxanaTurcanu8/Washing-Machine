/*
* Buttons.c
*
* Created: 30 May 2020 13:30:41
*  Author: Roxy
*/
#include "Buttons.h"
#include <avr/io.h>

void Buttons_Init(void)
{
	DDRA  = DDRA  & 0xFE;  //am pus bitul A0 = 0 (operatia AND bitwise (0b1111_1110) )
	PORTA = PORTA & 0xFE; //disable PULLUP , portul comandat in 0 logic
}

Buttons_State Buttons_GetState(void)
{
	Buttons_State Value;
	if((PINA & 0x1) == 1)
	{
		Value = BUTTON_NOT_PRESSED;
	}
	else
	{
		Value = BUTTON_PRESSED;
	}
	
	return Value;
}