/************************************/
/*	Author  : Mohamed Essam			*/
/*	Date 	: 25/2/2022				*/
/*	Version : V01					*/
/************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;

#define STK ((volatile STK_t*)0xE000E010) // pointer to struct 

#endif
