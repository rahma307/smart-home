#ifndef ADC_PRV_H
#define ADC_PRV_H

/*Define For ADC Registers */

#define ADC_U8_ADMUX     *((volatile u8 *)(0x27))
#define ADC_U8_ADCSRA    *((volatile u8 *)(0x26))
#define ADC_U8_ADCH      *((volatile u8 *)(0x25))
#define ADC_U8_ADCL      *((volatile u8 *)(0x24))
#define ADC_U8_SEIOR     *((volatile u8 *)(0x50))
#define ADC_U16_ADC_REG   *((volatile u16*)(0x24)) // to read 10 bits



#endif 
