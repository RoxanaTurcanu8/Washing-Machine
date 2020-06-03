/*
 * RottarySW.h
 *
 * Created: 30 May 2020 16:01:49
 *  Author: Roxy
 */ 


#ifndef ROTTARYSW_H_
#define ROTTARYSW_H_

typedef enum{
	ROTTARYSW_LEFT = 0u,
	ROTTARYSW_CENTER ,
	ROTTARYSW_RIGHT
}RottarySW_State;

void RottarySW_Init(void);
RottarySW_State RottarySW_GetState (void);


#endif /* ROTTARYSW_H_ */