/*
 * RottarySW.c
 *
 * Created: 30 May 2020 16:01:32
 *  Author: Roxy
 */ 

#include "RottarySW.h"
#include <avr/io.h>


void RottarySW_Init(void)
{
	DDRA  = DDRA  & 0xF1;  //am pus bitul A0 = 0 (operatia AND bitwise (0b1111_0001) )
	PORTA = PORTA & 0xF1; //disable PULLUP , portul comandat in 0 logic
}

RottarySW_State RottarySW_GetState (void)
{
	RottarySW_State State;
	if((PINA & 0x2) == 0)
	{
		State = ROTTARYSW_LEFT;
	}
	else if((PINA & 0x4) == 0)
	{
		State = ROTTARYSW_CENTER;
	}
	else
		State = ROTTARYSW_RIGHT;
		
return State;
}
