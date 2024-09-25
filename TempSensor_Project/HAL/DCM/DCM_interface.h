/******************************************************************************
 *                                                                            *
 *************************  SWC     : DCM_interface   *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/


#ifndef DCM_INTERFACE_H_
#define DCM_INTERFACE_H_


/* Macros for DC motor Id */
#define DCM_MOTOR_A                     1
#define DCM_MOTOR_B                     2

/* Macros for DC motor Direction */
#define DCM_CLOCK_WISE                  1
#define DCM_COUNTER_CLOCK_WISE			2


                         /*************** APIS PROTOTYPES ***************/

void DCM_voidInit        (u8 copy_u8MotorId);
void DCM_voidOn          (u8 copy_u8MotorId, u8 Copy_u8MotorDirection);
void DCM_voidControlSpeed(u8 copy_u8MotorId, u8 Copy_u8MotorDirection, u8 Copy_u8Speed);
void DCM_voidOff         (u8 copy_u8MotorId);


#endif /* DCM_INTERFACE_H_ */
