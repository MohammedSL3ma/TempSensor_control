/******************************************************************************
 *                                                                            *
 *************************  SWC     : LM35_program    *************************
 *************************  Date    : 14/01/2024      *************************
 *************************  Author  : kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

/* UTILES_LIB */
#include "../../LIB/stdtypes.h"
#include "../../LIB/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/ADC_V1/ADC_int.h"
#include "../../MCAL/DIO_V1/DIO_int.h"

/* HAL */
#include "../LM35_tempSen/LM35_config.h"
#include "../LM35_tempSen/LM35_interface.h"

#define  NULL   (void*) 0

void LM35_voidInit(void)
{
	DIO_u8setPinDirection(PORT_A, LM35_CHANNEL_NUM, INPUT);
	ADC_Init(ADC_REFERENCE_INTRNAL);
}


void LM35_voidGetTemperature(u16* copy_u16Temperature)
{
	if(copy_u16Temperature!=NULL)
	{
		u16 local_u16DigitalVal, local_u16AnalogVal;

		local_u16DigitalVal = ADC_u16Channelread(LM35_CHANNEL_NUM);
		
		// depend on Refrence volt AVCC (5V)
		local_u16AnalogVal = ((u32)local_u16DigitalVal*2560)/1024;

		*copy_u16Temperature = local_u16AnalogVal/10;
	}
	else
	{
		// return Error State
	}
}
