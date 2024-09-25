/*
 * DIO_int.h
 *
 *  Created on: Sep 17, 2021
 *      Author: hp
 */

#ifndef DIO_V1_DIO_INT_H_
#define DIO_V1_DIO_INT_H_

typedef enum
{
 PORT_A,
 PORT_B,
 PORT_C,
 PORT_D
}PORT_e;

typedef enum
{
 PIN_0,
 PIN_1,
 PIN_2,
 PIN_3,
 PIN_4,
 PIN_5,
 PIN_6,
 PIN_7
}PIN_e;

typedef enum
{
 INPUT,
 OUTPUT
}DIRECTION_e;

typedef enum
{
 LOW,
 HIGH
}STATE_e;

#define HALF_OUTPUT_HALF_INPUT    (u8) 0X0F
#define HALF_INPUT_HALF_OUTPUT    (u8) 0XF0
#define HALF_HIGH_HALF_LOW        (u8) 0X0F
#define HALF_LOW_HALF_HIGH        (u8) 0XF0
#define FULL_INPUT                (u8) 0X00
#define FULL_OUTPUT               (u8) 0XFF
#define FULL_LOW                (u8) 0X00
#define FULL_HIGH               (u8) 0XFF

u8 DIO_u8setPortDirection(PORT_e Copy_PORT_ePort, DIRECTION_e Copy_DIRECTION_eDirection);
u8 DIO_u8setPortValue(PORT_e Copy_PORT_ePort, STATE_e Copy_STATE_eValue);
u8 DIO_u8getPortValue(PORT_e Copy_PORT_ePort, u8 * Copy_pu8Value);

u8 DIO_u8setPinDirection(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin ,DIRECTION_e Copy_DIRECTION_eDirection);
u8 DIO_u8setPinValue(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin ,STATE_e Copy_STATE_eValue);
u8 DIO_u8getPinValue(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin ,u8 * Copy_pu8Value);
u8 DIO_u8togglePinValue(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin);
u8 DIO_u8setInputPullUpResistor(PORT_e Copy_PORT_ePort, PIN_e Copy_PIN_ePin);

#endif /* DIO_V1_DIO_INT_H_ */
