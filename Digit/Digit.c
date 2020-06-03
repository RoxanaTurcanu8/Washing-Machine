/*
* Digit.c
*
* Created: 30 May 2020 18:26:24
*  Author: Roxy
*/
#include "Digit.h"
#include <avr/io.h>

static const unsigned char Digit_PortValues[17] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00}; //contine cifrele de la 0-F
static unsigned char Digit_Text[3]= {0,0,0};             //initializarea lui Digit_Text
static unsigned char CurrentIndex;
static unsigned char LCDon;


void Digit_Init(void){
	DDRD  = DDRD  | 0x0E;   //am pus bitii D1,2,3 = 1 (setare ca output pentru comandare led)
	PORTD = PORTD | 0x0e;   // am pus bitii D1,2,3 = 1 (pentru a comanda pinii la nivel logic 1)
	DDRC  = DDRC  | 0xFF;
	PORTC = PORTC & 0x00;
	CurrentIndex = 0;
	
}

void Digit_Activate(unsigned char Digit) //selecteaza digitul tinta
{
	PORTD = 0x0e | PORTD;
	PORTD = PORTD & ~(1<<(Digit-1));
}

void Digit_Set (unsigned char Value, unsigned char Point)  //pun pe pini val pt a afisa o cifra si in functie de starea lui Point stiu daca trebuie activat sau nu
{
	if(LCDon == 1)
	{
		if(Point == 1)
		{
			PORTC = Digit_PortValues[Value];          //Pun pe PORTC valorile necesare pt afisarea cifrei
			PORTC = PORTC | 0x80;                     //Activare Point (pinul PC7)
		}
		else
		PORTC = Digit_PortValues[Value];
		
	}
	else
PORTC = 0x00;
}

void Set_LCDStatus (unsigned char Status)              //functie care seteeaza starea LCDului
{
	LCDon = Status;
}

void Digit_SetText(unsigned char Text[3])  //setez textul
{
	unsigned char i=0;
	for(i=0; i<3; i++)
	{
		Digit_Text[i] = Text[i];


	}
}

void Digit_Main(void)
{
	Digit_Activate(CurrentIndex+2);              //Selectez digitul curent
	if(CurrentIndex == 0)                        // Cand currentIndex==0 inseamna ca sunt pe Digit2 si setez Point=1
	{
		Digit_Set(Digit_Text[CurrentIndex],1);   //Setez digitul cu val dorita
	}
	else{
		Digit_Set(Digit_Text[CurrentIndex],0);      //Pe restul digitilor Point=0 (punctul nu este activ)
	}
	CurrentIndex = CurrentIndex+1;              //Current index max 2
	if(CurrentIndex == 3 )
	{
		CurrentIndex = 0;
	}
	
}