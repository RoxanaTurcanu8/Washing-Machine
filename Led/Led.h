/*
 * Led.h
 *
 * Created: 30 May 2020 14:24:06
 *  Author: Roxy
 */ 


#ifndef LED_H_
#define LED_H_

typedef enum{
	LED_ON = 0u,
	LED_OFF
}Led_State;

void Led_Init(void);
void Led_SetLed (Led_State State);


#endif /* LED_H_ */