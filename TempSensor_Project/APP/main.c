/*
 * main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: hp
 */
#include "../LIB/stdtypes.h"

#include "../MCAL/DIO_V1/DIO_int.h"
#include "../MCAL/ADC_V1/ADC_int.h"

#include "../HAL/LM35_tempSen/LM35_interface.h"
#include "../HAL/LCD_Handler/LCD_int.h"
#include "../HAL/DCM/DCM_interface.h"

#include <util/delay.h>

// The Mapping Function
u32 map(u32 Value, u32 in_min, u32 in_max, u32 out_min, u32 out_max)
{
	return (Value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void main(void)
{

	u16 Temp_C;
	LCD_4_BitvidInit();
	LM35_voidInit();
	DCM_voidInit(DCM_MOTOR_A);

while(1)
{
	u32 airFlow = map(Temp_C,21,39,127,255);
	u32 Prcn = map(airFlow,127,255,0,100);
	LM35_voidGetTemperature(&Temp_C);
	LCD_4_BitvidsendCommand(0b00000001);
	LCD_4_BitvidwriteString("TEMP = ");
	LCD_4_BitvidwriteInt(Temp_C);
	LCD_4_BitvidwriteCharacter('C');
	LCD_4_BitvidGoToXY(1,0);
	LCD_4_BitvidwriteString("Fan Speed = ");
	LCD_4_BitvidwriteInt((u8)Prcn);

	_delay_ms(250);

	if(Temp_C <= 20)
	{
	  DCM_voidOff(DCM_MOTOR_A);
	  airFlow = 0;
	}
	else if(Temp_C > 20 && Temp_C < 40)
	{

		DCM_voidControlSpeed(DCM_MOTOR_A,DCM_CLOCK_WISE,(u8)airFlow);
	}
	else
	{
        DCM_voidOn(DCM_MOTOR_A,DCM_CLOCK_WISE);
		airFlow = 255;
	}

}
}

