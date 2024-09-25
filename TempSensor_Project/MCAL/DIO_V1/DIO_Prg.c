/*
 * DIO_Prg.c
 *
 *  Created on: Sep 17, 2021
 *      Author: hp
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/stdtypes.h"
#include "DIO_int.h"
#include "DIO_reg.h"
#define RT_OK    (u8)   0
#define RT_NOK   (u8)   1
#define NULL     (void *)0

static PORT_t * DIO[DIO_PERIPHERAL_NUM] = {DIOA, DIOB, DIOC, DIOD};

u8 DIO_u8setPortDirection(PORT_e Copy_PORT_ePort, DIRECTION_e Copy_DIRECTION_eDirection)
{
	u8 Local_u8errStatus = RT_OK;

	if(Copy_PORT_ePort <= PORT_D)
	{
		DIO[Copy_PORT_ePort]->DDR = Copy_DIRECTION_eDirection;
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}

	return Local_u8errStatus;
}

u8 DIO_u8setPortValue(PORT_e Copy_PORT_ePort, STATE_e Copy_STATE_eValue)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_PORT_ePort <= PORT_D)
	{
		DIO[Copy_PORT_ePort]->PORT = Copy_STATE_eValue;
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}

	return Local_u8errStatus;
}


u8 DIO_u8getPortValue(PORT_e Copy_PORT_ePort, u8 * Copy_pu8Value)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_pu8Value != NULL && Copy_PORT_ePort <= PORT_D)
	{
		*Copy_pu8Value = DIO[Copy_PORT_ePort]->PIN;
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}

u8 DIO_u8setPinDirection(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin ,DIRECTION_e Copy_DIRECTION_eDirection)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_PIN_ePin <= PIN_7 && Copy_PORT_ePort <= PORT_D)
	{
		switch(Copy_DIRECTION_eDirection)
		{
		case INPUT : CLR_BIT(DIO[Copy_PORT_ePort]->DDR , Copy_PIN_ePin); break;
		case OUTPUT : SET_BIT(DIO[Copy_PORT_ePort]->DDR , Copy_PIN_ePin); break;
		default : Local_u8errStatus = RT_NOK; break;
		}
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}

u8 DIO_u8setPinValue(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin ,STATE_e Copy_STATE_eValue)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_PIN_ePin <= PIN_7 && Copy_PORT_ePort <= PORT_D)
	{
		switch(Copy_STATE_eValue)
		{
		case LOW : CLR_BIT(DIO[Copy_PORT_ePort]->PORT , Copy_PIN_ePin); break;
		case HIGH : SET_BIT(DIO[Copy_PORT_ePort]->PORT , Copy_PIN_ePin); break;
		default : Local_u8errStatus = RT_NOK; break;
		}
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}


u8 DIO_u8getPinValue(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin ,u8 * Copy_pu8Value)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_pu8Value != NULL)
	{
		if(Copy_PIN_ePin <= PIN_7 && Copy_PORT_ePort <= PORT_D)
		{
		*Copy_pu8Value=GET_BIT(DIO[Copy_PORT_ePort]->PIN,Copy_PIN_ePin);
		}
		else
		{
			Local_u8errStatus = RT_NOK;
		}
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}

	return Local_u8errStatus;
}

u8 DIO_u8togglePinValue(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin)
{

	u8 Local_u8errStatus = RT_OK;
	if(Copy_PIN_ePin <= PIN_7 && Copy_PORT_ePort <= PORT_D)
	{
		TOG_BIT(DIO[Copy_PORT_ePort]->PORT,Copy_PIN_ePin);
	}

	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;

}

u8 DIO_u8setInputPullUpResistor(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin)
{
	u8 Local_u8errStatus = RT_OK;
	if(Copy_PIN_ePin <= PIN_7 && Copy_PORT_ePort <= PORT_D)
	{
		SET_BIT(DIO[Copy_PORT_ePort]->PORT,Copy_PIN_ePin);
	}
	else
	{
		Local_u8errStatus = RT_NOK;
	}
	return Local_u8errStatus;
}

