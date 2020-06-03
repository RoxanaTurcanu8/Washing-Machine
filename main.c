/*
* WashingMachine.c
*
* Created: 30 May 2020 13:29:26
* Author : Roxy
*/
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/delay.h>
#include "Buttons/Buttons.h"
#include "Led/Led.h"
#include "RottarySW/RottarySW.h"
#include "Digit/Digit.h"

typedef enum
{
	PROGRAM_IDLE = 0,
	PROGRAM_RUNNING,
	PROGRAM_DONE
}ProgramStatus;

static const unsigned char TextL[3] = {1,1,5};  //durata programului de spalare pt ROTTARYSW_LEFT
static const unsigned char TextR[3] = {0,3,0};  //durata programului de spalare pt ROTTARYSW_RIGHT
static unsigned char Current_Text[3];           //contine timpul afisat pe display
ProgramStatus Program;


void ArrayCopy(unsigned char Source[3], unsigned char Destination[3])
{
	for(unsigned char i=0; i<3;i++)
	{
		Destination[i] = Source[i];       //copiez valorile din Array Source in Destination;
	}
}

void CountDown(void)
{
	Current_Text[2]= Current_Text[2]-1;
	if(Current_Text[2]==255)
	{
		Current_Text[2]=9;
		
		Current_Text[1]= Current_Text[1]-1;
		if(Current_Text[1]==255)
		{
			Current_Text[1]=5;
			
			Current_Text[0]= Current_Text[0]-1;
			if(Current_Text[0]==255)
			{
				Program = PROGRAM_DONE;
				Current_Text[0]=0;
				Current_Text[1]=0;
				Current_Text[2]=0;
			}
		}
	}
}

int main(void)
{
	unsigned long Counter=0;


	/* Replace with your application code */
	Buttons_Init();
	Led_Init();
	Digit_Init();
	while (1)
	{
		
		Digit_Main();
		
		_delay_us(750);

		
		if(Buttons_GetState()==BUTTON_PRESSED )          //verific daca butonul este apasat
		{
			if(Program == PROGRAM_RUNNING){
				if(Counter >= 1000)
				{
					CountDown();
					Digit_SetText(Current_Text); //actualizare text
					Counter = 0;
				}
				Counter++;                    //numara milisecundele
				Led_SetLed(LED_ON);
			}
			else if(Program == PROGRAM_DONE)
			{
				if(Counter<500)
				{
					Led_SetLed(LED_OFF);
				}
				else if(Counter<1000)
				{
					Led_SetLed(LED_ON);
				}
				else
				{
					Counter=0;
				}
				Counter++;
			}

		}
		else
		{
			
			if(RottarySW_GetState() == ROTTARYSW_LEFT)
			{
				Program = PROGRAM_RUNNING;
				Set_LCDStatus(1);
				ArrayCopy(TextL,Current_Text);
				Digit_SetText(Current_Text);
				
			}
			else if(RottarySW_GetState() == ROTTARYSW_RIGHT)
			{
				Program = PROGRAM_RUNNING;
				Set_LCDStatus(1);
				ArrayCopy(TextR,Current_Text);
				Digit_SetText(Current_Text);
				
			}
			else
			{
				Program = PROGRAM_IDLE;
				Set_LCDStatus(0);
			}
		}
	}
	
}
