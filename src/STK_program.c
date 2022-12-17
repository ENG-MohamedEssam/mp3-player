/************************************/
/*	Author  : Mohamed Essam			*/
/*	Date 	: 25/2/2022				*/
/*	Version : V01					*/
/************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_private.h"
#include "STK_interface.h"
#include "STK_config.h"

void (* CallBack) (void); //pointer to function
static u8 Interval_Mode;

void MSTK_voidInit(void)
{
	/* Clock Source Selection */
	#if Clock_Source == AHB
	CLR_BIT(STK -> CTRL,2); 
	#else if Clock_Source == AHB_8
	SET_BIT(STK -> CTRL,2);
	#endif
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks) // delay function
{
	STK -> LOAD = Copy_u32Ticks;
	/* Enable Systic */
	SET_BIT(STK -> CTRL,0);
	
	while (GET_BIT((STK -> CTRL),16) == 0);
	/* Disable Systic and reset load and current value */
	CLR_BIT(STK -> CTRL,0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
	
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*Copy_ptr)(void))// run timer once 
{
	STK -> LOAD = Copy_u32Ticks;
	/* Enable Interrupt and enable Systick*/
	SET_BIT(STK -> CTRL,1);
	SET_BIT(STK -> CTRL,0);
	Interval_Mode = 0;
	CallBack = Copy_ptr;
}	
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*Copy_ptr)(void)) // run timer periodically
{
	STK -> LOAD = Copy_u32Ticks;
	/* Enable Interrupt and enable Systick*/
	SET_BIT(STK -> CTRL,1);
	SET_BIT(STK -> CTRL,0);
	Interval_Mode = 1;
	CallBack = Copy_ptr;
}
void MSTK_voidStopInterval(void) // stop and reset timer 
{
	/* Disable Interrupt and Disable Systick*/
	CLR_BIT(STK -> CTRL,1);
	CLR_BIT(STK -> CTRL,0);
	/* Disable Systic and reset load and current value */
	CLR_BIT(STK -> CTRL,0);
	STK -> LOAD = 0;
	STK -> VAL  = 0;
}
u32  MSTK_u32GetElapsedTime(void)
{
	return ((STK -> LOAD) - (STK -> VAL));
}

u32  MSTK_u32GetRemainingTime(void)
{
	return ((STK -> VAL));
}


void SysTick_Handler(void)
{
	if (Interval_Mode == 0)
	{
		MSTK_voidStopInterval();
	}
	CallBack();
}

/* 9000 Counts = 1ms */
void MSTK_Delay_ms(u16 Copy_u16Delayms)
{
	u32 Local_u32Ticks = Copy_u16Delayms * 9000;
	MSTK_voidSetBusyWait(Local_u32Ticks);
}
