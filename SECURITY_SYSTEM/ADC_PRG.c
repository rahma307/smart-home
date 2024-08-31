
/*  lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#define   F_CPU 8000000UL
#include  <util/delay.h>

/*  mcal layer */
#include  "ADC_INT.h"
#include  "ADC_CONFIG.h"
#include  "ADC_PRV.h"

 static void (* ptr)(u16)=NULL;
static u8 Adc_busy_flag =0 ;
void ADC_VoINIT(void){  // this initalization from datasheet 
	/* select Vref  >> vcc */
	
	CLR_BIT(ADC_U8_ADMUX,7);
	SET_BIT(ADC_U8_ADMUX,6);
	
	/* right adjust   */
	
	CLR_BIT(ADC_U8_ADMUX,5);
	
	/* disable to auto trigger " we choise  right adjust " */
	
	CLR_BIT(ADC_U8_ADCSRA,5);
	
	/* select clock/64 */
	
	SET_BIT(ADC_U8_ADCSRA,2);
	SET_BIT(ADC_U8_ADCSRA,1);
	CLR_BIT(ADC_U8_ADCSRA,0);
	
	/* enable ADC*/
	
	SET_BIT(ADC_U8_ADCSRA,7);
	
}

u8 ADC_GETDigitalValueSynchronusNonBlocking(u8 copy_u8Channel_num ,u16 *copy_digitalvalue ) {
	/* user in runtime choose channel number */
	u32 local_u32counter =0;
	u8 local_u8errorstate= STD_TYPES_OK ;
	if(copy_u8Channel_num<32 && copy_digitalvalue!=NULL && (Adc_busy_flag ==0)){

		/* set Flag to make ADC is Busy */

		Adc_busy_flag =1 ;
		/* clear mux4..0*/
		ADC_U8_ADMUX &= 0b11100000;
		/* select channel*/
		  ADC_U8_ADMUX |= (copy_u8Channel_num) ;
		 /* start conversion */
		SET_BIT(ADC_U8_ADCSRA,6);	
         /* wait flag =1 */
         while((GET_BIT(ADC_U8_ADCSRA,4) == 0)&& (local_u32counter<ADC_u32_counter_time_out)){
        	 local_u32counter++;
         }

		
        if((GET_BIT(ADC_U8_ADCSRA,4) != 0) )
         {  /* clear flag */

        	SET_BIT(ADC_U8_ADCSRA,4);
		
		/* Read the Digital value */
		
		*copy_digitalvalue = ADC_U16_ADC_REG ;
		Adc_busy_flag =0 ;
         }
        else{
        	local_u8errorstate= STD_TYPES_NOK ;

        }
		
	}
	else{
		
		local_u8errorstate= STD_TYPES_NOK ;
	}
	
	
	
	
	
	
	return local_u8errorstate;
	
	
}


u8 ADC_GetDigitalValueAsynch(u8 channel_num, void (*notification_func)(u16)){
	u8 local_u8errorstate= STD_TYPES_OK ;

	if(channel_num<32 &&(notification_func != NULL) && (Adc_busy_flag ==0)){

		/* set Flag to make ADC is Busy */

		Adc_busy_flag =1 ;

		/* Update Global Pointer to a Function */

           ptr = notification_func;

         /* Enable ADC interrupt */
           SET_BIT(ADC_U8_ADCSRA, 3);

           /* clear mux4..0*/
           ADC_U8_ADMUX &= 0b11100000;
           /* select channel*/
            ADC_U8_ADMUX |= (channel_num) ;
           /* start conversion */
           	SET_BIT(ADC_U8_ADCSRA,6);
    }
	else{

			local_u8errorstate= STD_TYPES_NOK ;
		}


	return local_u8errorstate;
}

u8 ADC_U8GetRegValue (u16 * value){
	u8 local_u8errorstate= STD_TYPES_OK ;
	if(value != NULL){
       *value =  ADC_U16_ADC_REG ;
	}
	else{
		local_u8errorstate= STD_TYPES_NOK ;
	}

	return local_u8errorstate;
}

/* prototype for ISR */

void __vector_16(void) __attribute__((signal));

void __vector_16(void) {
	if(ptr != NULL){
		/* clear flag */
		 Adc_busy_flag =0;
		/* Clear PIE of ADC*/
		   CLR_BIT(ADC_U8_ADCSRA, 3);

        /* calling notification function*/
	         ptr(ADC_U16_ADC_REG);

	}


}
