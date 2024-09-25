/*
 * ADC_int.h
 *
 *  Created on: Oct 13, 2021
 *      Author: hp
 */

#ifndef ADC_V1_ADC_INT_H_
#define ADC_V1_ADC_INT_H_

#define ADSC                 (u8) 6
#define AREF_EN              (u8)0b00000000
#define AVCC_EN              (u8)0b01000000

#define ADC0_AREF            (u8)0b00000000
#define ADC1_AREF            (u8)0b00000001
#define ADC2_AREF            (u8)0b00000010
#define ADC3_AREF            (u8)0b00000011
#define ADC4_AREF            (u8)0b00000100
#define ADC5_AREF            (u8)0b00000101
#define ADC6_AREF            (u8)0b00000110
#define ADC7_AREF            (u8)0b00000111

#define ADC0_AVCC            (u8)0b01000000
#define ADC1_AVCC            (u8)0b01000001
#define ADC2_AVCC            (u8)0b01000010
#define ADC3_AVCC            (u8)0b01000011
#define ADC4_AVCC            (u8)0b01000100
#define ADC5_AVCC            (u8)0b01000101
#define ADC6_AVCC            (u8)0b01000110
#define ADC7_AVCC            (u8)0b01000111

#define ADC_EN_PS_2          (u8)0b10000000
#define ADC_EN_PS_4          (u8)0b10000010
#define ADC_EN_PS_8          (u8)0b10000011
#define ADC_EN_PS_16         (u8)0b10000100
#define ADC_EN_PS_32         (u8)0b10000101
#define ADC_EN_PS_64         (u8)0b10000110
#define ADC_EN_PS_128        (u8)0b10000111

/* Enum for Reference Voltage */
typedef enum
{
	ADC_REFERENCE_AVCC,
	ADC_REFERENCE_AREF,
	ADC_REFERENCE_INTRNAL,
}ADC_refVolt_t;

/* Enum for Channel Number as Single Ended Input */
typedef enum{
	ADC_CHANNEL_0,
	ADC_CHANNEL_1,
	ADC_CHANNEL_2,
	ADC_CHANNEL_3,
	ADC_CHANNEL_4,
	ADC_CHANNEL_5,
	ADC_CHANNEL_6,
	ADC_CHANNEL_7,
}ADC_channelsIds;

void ADC_Init(ADC_refVolt_t copy_tReferenceVoltage);
u16 ADC_u16Channelread(u8 Copy_u8Channel);
#endif /* ADC_V1_ADC_INT_H_ */
