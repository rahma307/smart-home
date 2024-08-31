#ifndef ADC_INT_H
#define ADC_INT_H

void ADC_VoINIT(void);

u8 ADC_GETDigitalValueSynchronusNonBlocking(u8 copy_u8Channel_num ,u16 *copy_digitalvalue ) ;
u8 ADC_U8GetRegValue (u16 * value);
u8 ADC_GetDigitalValueAsynch(u8 channel_num, void (*notification_func)(u16));
 /* CHANNEL FOR SINGLE CONVERSION */
#define  ADC_CHANNEL0  0
#define  ADC_CHANNEL1  1
#define  ADC_CHANNEL2  2
#define  ADC_CHANNEL3  3
#define  ADC_CHANNEL4  4
#define  ADC_CHANNEL5  5
#define  ADC_CHANNEL6  6
#define  ADC_CHANNEL7  7





#endif 
