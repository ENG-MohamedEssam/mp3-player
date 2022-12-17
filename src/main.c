/*
 * main.c
 *
 *  Created on: May 4, 2022
 *      Author: Mohamed Essam
 */

#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "DIO_private.h"
#include "STK_interface.h"
#include "file.h"

volatile u32 i = 0;

void voidSetDac(void)
{
	GPIOA_ODR = Habetak_raw[i];
	i++;
	if (i == 112000)
	{
		i = 0;
	}
}
int main (void)
{
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2); // Enable GPIOA Clock

	MGPIO_voidSetPinDirection(GPIOA,0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(GPIOA,7,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,voidSetDac);


	while(1)
	{

	}
	return 0;
}
