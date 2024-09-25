/*
 * ADC_Prg.c
 *
 *  Created on: Oct 13, 2021
 *      Author: hp
 */
#include"../../LIB/stdtypes.h"
#include"../../LIB/BIT_MATH.h"

#include"../DIO_V1/DIO_int.h"

#include "ADC_int.h"
#include "ADC_reg.h"

#define RT_OK    (u8)   0
#define RT_NOK   (u8)   1

void ADC_Init(ADC_refVolt_t copy_tReferenceVoltage)
{
	switch(copy_tReferenceVoltage)
    {
	case ADC_REFERENCE_AREF:
	/*
      * VREF = AREF
      */
	CLR_BIT(ADC->MUX,6);
	CLR_BIT(ADC->MUX,7);
	break;

	case ADC_REFERENCE_AVCC:
		/*
	      * VREF = VCC
	      */
		SET_BIT(ADC->MUX,6);
		CLR_BIT(ADC->MUX,7);
		break;

	case ADC_REFERENCE_INTRNAL:
		/*
	      * VREF = internal 2.56V
	      */
		SET_BIT(ADC->MUX,6);
		SET_BIT(ADC->MUX,7);
		break;
    }
	/*
	 * RESOLUTION = 10bit
	 */
	CLR_BIT(ADC->MUX,5);
	/*
	 * ADC ENABLE
	 */
	SET_BIT(ADC->SRA,7);
	/*
	 * Prescaler = 128
	 */
	SET_BIT(ADC->SRA,0);
	SET_BIT(ADC->SRA,1);
	SET_BIT(ADC->SRA,2);
}

u16 ADC_u16Channelread(u8 Copy_u8Channel)
{
  // select the corresponding channel 0~7
  // ANDing with 7 will always keep the value
  // of Copy_u8Channel between 0 and 7
	ADC->MUX &= 0b11100000;  // AND operation with 0b11100000
	ADC->MUX |= ( Copy_u8Channel ); // clears the bottom 3 bits before ORing

  // start single convertion
  // write 1 to ADSC
	SET_BIT(ADC->SRA,6);

  // wait for conversion to complete
  // ADSC becomes 0 again
  // till then, run loop continuously
  u16 local_u16TimeoutCounter = 0;
  while(GET_BIT(ADC->SRA,4)==0);

  SET_BIT(ADC->SRA,4);
  return ADC->DATA;
}

