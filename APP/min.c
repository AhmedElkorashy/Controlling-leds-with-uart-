
/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include <util/delay.h>
/*****************MCAL*******************/
#include "GIE_Interface.h"
#include "DIO_Interface.h"
#include "TIMERS_Interface.h"
#include "USART_Interface.h"

/*****************HAL*******************/


/********************************************************************************/
/***********Global Variables************/

/*************GLOBAL MACROS*************/
#define OVERFLOWS		4000

/**************Handlers*****************/
//void func(void)
//{
//	static  u16 Global_u8TickCounts = 0;
//	Global_u8TickCounts++;
//	/*
//	 * FCLK = 8 MHZ
//	 * PRESCALER = 1024
//	 * Preload = 0
//	 * Counts = 256 - preload = 256 - 0 = 256
//	 * N. of overflows = counts * (Pre-scaler / FCLK) = 32.768 msec
//	 * For make toggle every one second -> 1/0.032768 = 30 overflows
//	 */
//	if(Global_u8TickCounts == OVERFLOWS)
//	{
//		DIO_voidFlibPinLevel(DIO_PORTA,DIO_PIN1);
//		Global_u8TickCounts = 0;
//	}
//}


/********************************************************************************/
/*								ENTRY POINT <main>								*/
/********************************************************************************/
volatile u8 Global_u8RecieveRed_Led=0;
volatile u8 Global_u8RecieveYellow_Led=0;
volatile u8 Global_u8RecieveBlue_Led=0;
 u8 Global_Value;
/***************Handlers****************/
void func(void)
{
	USART_u8RecevieData(&Global_Value);
	if(Global_Value=='r')
	{
		if(Global_u8RecieveRed_Led==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);

			Global_u8RecieveRed_Led^=1;
			USART_u8SendStringSynch((u8 *)"Red led on\n\r\n");
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			Global_u8RecieveRed_Led^=1;
			USART_u8SendStringSynch((u8 *)"Red led OFF\n\r\n");
		}

	}
	if(Global_Value=='y')
	{
		if(Global_u8RecieveYellow_Led==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
			Global_u8RecieveYellow_Led^=1;
			USART_u8SendStringSynch((u8 *)"Yellow led on\n\r\n");
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
			Global_u8RecieveYellow_Led^=1;
			USART_u8SendStringSynch((u8 *)"Yellow led OFF\n\r\n");
		}

	}

	if(Global_Value=='b')
	{

		if(Global_u8RecieveBlue_Led==0)
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
			Global_u8RecieveBlue_Led^=1;
			USART_u8SendStringSynch((u8 *)"Red led on\n\r\n");
		}
		else
		{
			DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
			Global_u8RecieveBlue_Led^=1;
			USART_u8SendStringSynch((u8 *)"Red led OFF\n\r\n");
		}

	}

}


int main(void)
{
	/*Initialize GIE*/
	GIE_voidEnable();
	/*Initialize USART*/
	USART_voidInit();
	/*Initialize PA0 pin*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
	/*Initialize PA1 pin*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
	/*Initialize PA2 pin*/
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
	USART_u8SendStringSynch((u8 *)"Press r,y,b :\n\r\n");
	while(1)
	{

	}
	return 0;
}

