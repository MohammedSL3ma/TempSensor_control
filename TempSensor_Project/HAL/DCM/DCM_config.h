/******************************************************************************
 *                                                                            *
 *************************  SWC     : DCM_config      *************************
 *************************  Date    : 25/02/2024      *************************
 *************************  Author  : Kareem Hussein  *************************
 *************************  Version : 1.0             *************************
 *                                                                            *
 ******************************************************************************/

#ifndef DCM_CONFIG_H_
#define DCM_CONFIG_H_


                           /* Macros for H-Bridge Pins Configurations */

#define DCM_MOTOR_A_ENABLE_PORT			PORT_B
#define DCM_MOTOR_A_ENABLE_PIN			PIN_3

#define DCM_MOTOR_A_IN1_PORT			PORT_C
#define DCM_MOTOR_A_IN1_PIN  			PIN_3

#define DCM_MOTOR_A_IN2_PORT			PORT_C
#define DCM_MOTOR_A_IN2_PIN  			PIN_2


#define DCM_MOTOR_B_ENABLE_PORT			PORT_D
#define DCM_MOTOR_B_ENABLE_PIN			PIN_4

#define DCM_MOTOR_B_IN1_PORT			PORT_B
#define DCM_MOTOR_B_IN1_PIN  			PIN_2

#define DCM_MOTOR_B_IN2_PORT			PORT_D
#define DCM_MOTOR_B_IN2_PIN  			PIN_6


#endif /* DCM_CONFIG_H_ */
