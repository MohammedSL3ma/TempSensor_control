/*
 * ADC_reg.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hp
 */

#ifndef MCAL_ADC_V1_ADC_REG_H_
#define MCAL_ADC_V1_ADC_REG_H_

typedef struct
{
   /*
	* ADC Data Register
	*/
   u16 DATA;
   /*
    * ADC Control & Status Register A
    */
   u8 SRA;
   /*
    * ADC Multiplexer Selection Register
    */
   u8 MUX;
}ADC_t;



#define   ADC   ((volatile ADC_t*)0X24)


/*
 * Special Function IO Register
 */
#define SFIO_REG        *((volatile u8*)0X50)


#endif /* MCAL_ADC_V1_ADC_REG_H_ */
