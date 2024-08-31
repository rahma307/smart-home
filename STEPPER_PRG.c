/*  lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h" 
#define   F_CPU 8000000UL
#include  <util/delay.h>

/*  mcal layer */

#include   "DIO_INT.h"

/* hal */

#include "STEPPER_INT.h"
#include "STEPPER-CONFIG.h"
 



void STEPPER_voidmotion(u8 direction , u16 degree) {
u16 number_of_steps = (degree*2048UL)/360 ;
u16 number_of_iteration = number_of_steps/4 ;

/* TO ROTATE CLOCK WISE */	
switch(direction){

case CLOCK_WISE :

for( int i=0 ; i< number_of_iteration ; i++ ){
	
	/*  DISACTIVATE ALL PINS EXCEPT BLUE PIN */
	
	 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_HIGH);	
	 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE ,   LOGIC_LOW);
    _delay_ms(10);
	
	/*  DISACTIVATE ALL PINS EXCEPT PINK PIN */
	
     DIO_u8SetPinValue(PORTA , BLUE , LOGIC_HIGH);
	 DIO_u8SetPinValue(PORTA , YELLOW , LOGIC_HIGH);
	 DIO_u8SetPinValue(PORTA , ORANGE , LOGIC_HIGH);
	 DIO_u8SetPinValue(PORTA , PINK , LOGIC_LOW);
	 _delay_ms(10);
	 
	 /*  DISACTIVATE ALL PINS EXCEPT YELLOW PIN */
	 
	 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_LOW);
	 _delay_ms(10);
	 
	 /*  DISACTIVATE ALL PINS EXCEPT ORANGE  PIN */
	 
	 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE , LOGIC_LOW);
	 _delay_ms(10);
}

break ;

case ANTI_CLOCK_WISE :


for( int i=0 ; i< number_of_iteration ; i++ ){
	
	/*  DISACTIVATE ALL PINS EXCEPT ORANGE PIN */
	
	 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK ,  LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_HIGH);	
	 DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE ,   LOGIC_LOW);
    _delay_ms(10);
	
	/*  DISACTIVATE ALL PINS EXCEPT YELLOW PIN */
	
     DIO_u8SetPinValue(PORTA , BLUE , LOGIC_HIGH);
	 DIO_u8SetPinValue(PORTA , PINK , LOGIC_HIGH);
	 DIO_u8SetPinValue(PORTA , ORANGE , LOGIC_HIGH);
	 DIO_u8SetPinValue(PORTA , YELLOW , LOGIC_LOW);
	 _delay_ms(10);
	 
	 /*  DISACTIVATE ALL PINS EXCEPT PINK PIN */
	 
	 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK , LOGIC_LOW);
	 _delay_ms(10);
	 
	 /*  DISACTIVATE ALL PINS EXCEPT BLUE  PIN */
	 
	 DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK , LOGIC_HIGH);
	 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE , LOGIC_LOW);
	 _delay_ms(10);
}



}
	
}


void STEPPER_voidstop() {
	    DIO_u8SetPinValue(TRANSISTOR_PORT , ORANGE , LOGIC_HIGH);
		 DIO_u8SetPinValue(TRANSISTOR_PORT , YELLOW , LOGIC_HIGH);
		 DIO_u8SetPinValue(TRANSISTOR_PORT , PINK , LOGIC_HIGH);
		 DIO_u8SetPinValue(TRANSISTOR_PORT , BLUE , LOGIC_HIGH);
}
