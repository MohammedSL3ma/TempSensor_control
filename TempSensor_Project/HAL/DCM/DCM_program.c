/******************************************************************************
 *                                                                            *
 *************************  SWC     : DCM_program     *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/


/* UTILES_LIB */
#include "../../LIB/stdtypes.h"
#include "../../LIB/BIT_MATH.h"

/* MCAL */
#include "../../MCAL/DIO_V1/DIO_int.h"
#include "../../MCAL/Timer_V2/Timer_int.h"

/* HAL */
#include "DCM_interface.h"
#include "DCM_config.h"

#define DCM_USED_TIMER      TIMER_0

PWM_timers_config DCM_Speed;

void DCM_voidInit(u8 copy_u8MotorId)
{
	/* Initializ H-Bridge As Output Pins depend on motor id*/
	switch(copy_u8MotorId)
	{
	case DCM_MOTOR_A:

		DIO_u8setPinDirection(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, OUTPUT);
		DIO_u8setPinDirection(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, OUTPUT);
		DIO_u8setPinDirection(DCM_MOTOR_A_ENABLE_PORT, DCM_MOTOR_A_ENABLE_PIN, OUTPUT);
		break;

	case DCM_MOTOR_B:

		DIO_u8setPinDirection(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, OUTPUT);
		DIO_u8setPinDirection(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, OUTPUT);
		DIO_u8setPinDirection(DCM_MOTOR_B_ENABLE_PORT, DCM_MOTOR_B_ENABLE_PIN, OUTPUT);
		break;

	}
}


void DCM_voidOn(u8 copy_u8MotorId, u8 Copy_u8MotorDirection)
{
	/* Turn DC motor on using H-Bridge Pins depend on Copy_u8Direction*/
	switch(copy_u8MotorId)
	{
	case DCM_MOTOR_A:
		switch(Copy_u8MotorDirection)
		{
		case DCM_CLOCK_WISE:

			DIO_u8setPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, HIGH);
			DIO_u8setPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, LOW);
			break;

		case DCM_COUNTER_CLOCK_WISE:
			DIO_u8setPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, LOW);
			DIO_u8setPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, HIGH);
			break;
		}
		Timer_DeInit(DCM_USED_TIMER);
		DIO_u8setPinValue(DCM_MOTOR_A_ENABLE_PORT, DCM_MOTOR_A_ENABLE_PIN, HIGH);
		break;

		case DCM_MOTOR_B:
			switch(Copy_u8MotorDirection)
			{
			case DCM_CLOCK_WISE:
				DIO_u8setPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, HIGH);
				DIO_u8setPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, LOW);
				break;

			case DCM_COUNTER_CLOCK_WISE:
				DIO_u8setPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, LOW);
				DIO_u8setPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, HIGH);
				break;
			}
			Timer_DeInit(DCM_USED_TIMER);
			DIO_u8setPinValue(DCM_MOTOR_B_ENABLE_PORT, DCM_MOTOR_B_ENABLE_PIN, HIGH);
			break;
	}
}


void DCM_voidControlSpeed(u8 copy_u8MotorId, u8 Copy_u8MotorDirection, u8 Copy_u8Speed)
{
	DCM_Speed.timer = DCM_USED_TIMER;
	DCM_Speed.T0_T1_used_freq = TIMER_0_1_PRE_SCALER_e_8;
	DCM_Speed.PWM_Mode = FAST_PWM;
	/* Turn DC motor on with Controlling desired(motorId) DC motor speed using PWM0 by setting Duty Cycle and turn it on using H-Bridge
	 By Setting Dir and Enable pins depend on motorDirection*/
	switch(copy_u8MotorId)
	{
	    case DCM_MOTOR_A:
		switch(Copy_u8MotorDirection)
		{
		case DCM_CLOCK_WISE:
			DIO_u8setPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, HIGH);
			DIO_u8setPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, LOW);
			break;

		case DCM_COUNTER_CLOCK_WISE:
			DIO_u8setPinValue(DCM_MOTOR_A_IN1_PORT, DCM_MOTOR_A_IN1_PIN, LOW);
			DIO_u8setPinValue(DCM_MOTOR_A_IN2_PORT, DCM_MOTOR_A_IN2_PIN, HIGH);
			break;
		}
		DCM_Speed.set_duty_cycle = Copy_u8Speed;
		PWM_timers_init(&DCM_Speed);
		break;

		case DCM_MOTOR_B:
			switch(Copy_u8MotorDirection)
			{
			case DCM_CLOCK_WISE:
				DIO_u8setPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, HIGH);
				DIO_u8setPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, LOW);
				break;

			case DCM_COUNTER_CLOCK_WISE:
				DIO_u8setPinValue(DCM_MOTOR_B_IN1_PORT, DCM_MOTOR_B_IN1_PIN, LOW);
				DIO_u8setPinValue(DCM_MOTOR_B_IN2_PORT, DCM_MOTOR_B_IN2_PIN, HIGH);
				break;
			}
			DCM_Speed.set_duty_cycle = Copy_u8Speed;
			PWM_timers_init(&DCM_Speed);
			break;
	}
}


void DCM_voidOff(u8 copy_u8MotorId)
{
	switch(copy_u8MotorId)
	{
	    case DCM_MOTOR_A:
	    Timer_DeInit(DCM_USED_TIMER);
	    DIO_u8setPinValue(DCM_MOTOR_A_ENABLE_PORT, DCM_MOTOR_A_ENABLE_PIN, LOW);
		break;

	    case DCM_MOTOR_B:
	    Timer_DeInit(DCM_USED_TIMER);
	   	DIO_u8setPinValue(DCM_MOTOR_B_ENABLE_PORT, DCM_MOTOR_B_ENABLE_PIN, LOW);
	    break;
	}
}


