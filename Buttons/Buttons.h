/*
 * Buttons.h
 *
 * Created: 30 May 2020 13:31:02
 *  Author: Roxy
 */ 


#ifndef BUTTONS_H_
#define BUTTONS_H_

typedef enum{
	BUTTON_PRESSED = 0u,
	BUTTON_NOT_PRESSED 
	}Buttons_State;

void Buttons_Init(void);
Buttons_State Buttons_GetState (void);



#endif /* BUTTONS_H_ */