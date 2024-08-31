 
#include "STD_TYPES.h"
#include  "BIT_MATH.h" 
#include   "DIO_PRV.h"
#include   "DIO_INT.h"
#include   "DIO_CONFIG.h"
 
 
 void DIO_voidInit(void)
{
	 DDRA_REGISTER = Conc(DIO_u8_PA7_INTIAL_DIRECTION,DIO_u8_PA6_INTIAL_DIRECTION,DIO_u8_PA5_INTIAL_DIRECTION,DIO_u8_PA4_INTIAL_DIRECTION,
						   DIO_u8_PA3_INTIAL_DIRECTION,DIO_u8_PA2_INTIAL_DIRECTION,DIO_u8_PA1_INTIAL_DIRECTION,DIO_u8_PA0_INTIAL_DIRECTION);

	 DDRB_REGISTER = Conc(DIO_u8_PB7_INTIAL_DIRECTION,DIO_u8_PB6_INTIAL_DIRECTION,DIO_u8_PB5_INTIAL_DIRECTION,DIO_u8_PB4_INTIAL_DIRECTION,
						   DIO_u8_PB3_INTIAL_DIRECTION,DIO_u8_PB2_INTIAL_DIRECTION,DIO_u8_PB1_INTIAL_DIRECTION,DIO_u8_PB0_INTIAL_DIRECTION);

	 DDRC_REGISTER = Conc(DIO_u8_PC7_INTIAL_DIRECTION,DIO_u8_PC6_INTIAL_DIRECTION,DIO_u8_PC5_INTIAL_DIRECTION,DIO_u8_PC4_INTIAL_DIRECTION,
						   DIO_u8_PC3_INTIAL_DIRECTION,DIO_u8_PC2_INTIAL_DIRECTION,DIO_u8_PC1_INTIAL_DIRECTION,DIO_u8_PC0_INTIAL_DIRECTION);

	 DDRD_REGISTER = Conc(DIO_u8_PD7_INTIAL_DIRECTION,DIO_u8_PD6_INTIAL_DIRECTION,DIO_u8_PD5_INTIAL_DIRECTION,DIO_u8_PD4_INTIAL_DIRECTION,
						   DIO_u8_PD3_INTIAL_DIRECTION,DIO_u8_PD2_INTIAL_DIRECTION,DIO_u8_PD1_INTIAL_DIRECTION,DIO_u8_PD0_INTIAL_DIRECTION);

	 PORTA_REGISTER = Conc(DIO_u8_PA7_INTIAL_VALUE,DIO_u8_PA6_INTIAL_VALUE,DIO_u8_PA5_INTIAL_VALUE,DIO_u8_PA4_INTIAL_VALUE,
						   DIO_u8_PA3_INTIAL_VALUE,DIO_u8_PA2_INTIAL_VALUE,DIO_u8_PA1_INTIAL_VALUE,DIO_u8_PA0_INTIAL_VALUE);

	 PORTB_REGISTER = Conc(DIO_u8_PB7_INTIAL_VALUE,DIO_u8_PB6_INTIAL_VALUE,DIO_u8_PB5_INTIAL_VALUE,DIO_u8_PB4_INTIAL_VALUE,
						   DIO_u8_PB3_INTIAL_VALUE,DIO_u8_PB2_INTIAL_VALUE,DIO_u8_PB1_INTIAL_VALUE,DIO_u8_PB0_INTIAL_VALUE);

	 PORTC_REGISTER = Conc(DIO_u8_PC7_INTIAL_VALUE,DIO_u8_PC6_INTIAL_VALUE,DIO_u8_PC5_INTIAL_VALUE,DIO_u8_PC4_INTIAL_VALUE,
						   DIO_u8_PC3_INTIAL_VALUE,DIO_u8_PC2_INTIAL_VALUE,DIO_u8_PC1_INTIAL_VALUE,DIO_u8_PC0_INTIAL_VALUE);

	 PORTD_REGISTER = Conc(DIO_u8_PD7_INTIAL_VALUE,DIO_u8_PD6_INTIAL_VALUE,DIO_u8_PD5_INTIAL_VALUE,DIO_u8_PD4_INTIAL_VALUE,
						   DIO_u8_PD3_INTIAL_VALUE,DIO_u8_PD2_INTIAL_VALUE,DIO_u8_PD1_INTIAL_VALUE,DIO_u8_PD0_INTIAL_VALUE);
}
 
 u8  DIO_u8SetPinDirection(u8 COPY_u8PortId , u8 COPY_u8PinId ,u8 COPY_u8Direction)
 {
	 u8 Local_u8ErrorState = STD_TYPES_OK ;    // flage 
	  
	if( (COPY_u8PortId <= PORTD)   && ( COPY_u8PinId <=PIN_7 ) &&  ((COPY_u8Direction == INPUT) ||(COPY_u8Direction == OUTPUT) ) ) {   //  ظˆط¯ظٹ   ط¹ظ…ط±ظ‡ط§ ظ…ط§ ظ‡طھط¬ظٹط¨ ط±ظ‚ظ…ط³ط§ظ„ط¨u8ظ…ط³طھط­ظٹظ„ ط±ظ‚ظ… ط§ظ„ط¨ظˆط±طھ ظٹط¨ظ‚ظٹ ط§ظ‚ظ„ ظ…ظ† طµظپط± ظ„ط§ظ† ط§ظ„ظ†ظˆط¹ ط¨طھط§ط¹ظ‡  
	 switch(COPY_u8PortId ){

	case PORTA :
		if(COPY_u8Direction == INPUT){
			CLR_BIT(DDRA_REGISTER ,COPY_u8PinId );
		}
		else if(COPY_u8Direction == OUTPUT){
			SET_BIT(DDRA_REGISTER ,COPY_u8PinId );
		}
	 break ;

	case PORTB :
		if(COPY_u8Direction == INPUT){
				CLR_BIT(DDRB_REGISTER ,COPY_u8PinId);
			}
			else if(COPY_u8Direction == OUTPUT){
				SET_BIT(DDRB_REGISTER ,COPY_u8PinId );
			}

		 break ;

	case PORTC :

		if(COPY_u8Direction == INPUT){
				CLR_BIT(DDRC_REGISTER ,COPY_u8PinId);
			}
			else if(COPY_u8Direction == OUTPUT){
				SET_BIT(DDRC_REGISTER ,COPY_u8PinId );
			}


			break ;

	case PORTD :

		if(COPY_u8Direction == INPUT){
				CLR_BIT(DDRD_REGISTER ,COPY_u8PinId );
			}
			else if(COPY_u8Direction == OUTPUT){
				SET_BIT(DDRD_REGISTER ,COPY_u8PinId );
			}
		 break ;



	}}
	
	
	else{ 
		
		Local_u8ErrorState =STD_TYPES_NOK;
	}

return   Local_u8ErrorState ;
	 
 } 
 u8  DIO_u8SetPinValue(u8 COPY_u8PortId , u8 COPY_u8PinId ,u8 COPY_u8Value){
	  u8 Local_u8ErrorState = STD_TYPES_OK ;    // flage 
	  
	if( (COPY_u8PortId <= PORTD)   && ( COPY_u8PinId <=PIN_7 ) &&  ((COPY_u8Value == LOGIC_LOW) ||(COPY_u8Value == LOGIC_HIGH) ) ) {   //  ظˆط¯ظٹ   ط¹ظ…ط±ظ‡ط§ ظ…ط§ ظ‡طھط¬ظٹط¨ ط±ظ‚ظ…ط³ط§ظ„ط¨u8ظ…ط³طھط­ظٹظ„ ط±ظ‚ظ… ط§ظ„ط¨ظˆط±طھ ظٹط¨ظ‚ظٹ ط§ظ‚ظ„ ظ…ظ† طµظپط± ظ„ط§ظ† ط§ظ„ظ†ظˆط¹ ط¨طھط§ط¹ظ‡  
	 switch(COPY_u8PortId ){

	case PORTA :
		if(COPY_u8Value == LOGIC_LOW){
			CLR_BIT(PORTA_REGISTER ,COPY_u8PinId );
		}
		else if(COPY_u8Value == LOGIC_HIGH){
			SET_BIT(PORTA_REGISTER ,COPY_u8PinId );
		}
	 break ;

	case PORTB :
		if(COPY_u8Value == LOGIC_LOW){
				CLR_BIT(PORTB_REGISTER ,COPY_u8PinId);
			}
			else if(COPY_u8Value == LOGIC_HIGH){
				SET_BIT(PORTB_REGISTER  ,COPY_u8PinId );
			}

		 break ;

	case PORTC :

		if(COPY_u8Value == LOGIC_LOW){
				CLR_BIT(PORTC_REGISTER  ,COPY_u8PinId);
			}
			else if(COPY_u8Value == LOGIC_HIGH){
				SET_BIT(PORTC_REGISTER  ,COPY_u8PinId );
			}


			break ;

	case PORTD :

		if(COPY_u8Value == LOGIC_LOW){
				CLR_BIT(PORTD_REGISTER  ,COPY_u8PinId );
			}
			else if(COPY_u8Value == LOGIC_HIGH){
				SET_BIT(PORTD_REGISTER  ,COPY_u8PinId );
			}
		 break ;



	}}
	
	
	else{ 
		
		Local_u8ErrorState =STD_TYPES_NOK;
	}

return   Local_u8ErrorState ;
	 
	 
 }   
 
 u8  DIO_u8GetPinValue(u8 COPY_u8PortId , u8 COPY_u8PinId ,u8 *COPY_Pu8PinValue) {
 u8 Local_u8ErrorState = STD_TYPES_OK ; 	 
 u8 Local_u8PinValue ;  // to ensure that the fuction get_BIT_value will return 0 or 1  if true we will store the value in pointer 
if( (COPY_u8PortId <= PORTD)   && ( COPY_u8PinId <=PIN_7 )  && (COPY_Pu8PinValue != NULL  ) ) { // ptr >> is a variable in main to store the state of pin on it

	 switch(COPY_u8PortId ){

	 	 	case PORTA :
	 	 		 Local_u8PinValue =  GET_BIT(PINA_REGISTER , COPY_u8PinId);
				 if( Local_u8PinValue  == 0 ){
					*COPY_Pu8PinValue = LOGIC_LOW ;
				 }
				 else if ( Local_u8PinValue  == 1 ){
					 *COPY_Pu8PinValue = LOGIC_HIGH ;
				 }
	 	 	 break ;

	 	 	case PORTB :
	 	 		  Local_u8PinValue =  GET_BIT(PINB_REGISTER , COPY_u8PinId);
				 if( Local_u8PinValue  == 0 ){
					*COPY_Pu8PinValue = LOGIC_LOW ;
				 }
				 else if ( Local_u8PinValue  == 1 ){
					 *COPY_Pu8PinValue = LOGIC_HIGH ;
				 }
	 	 		 break ;

	 	 	case PORTC :
	 	 		  Local_u8PinValue =  GET_BIT(PINC_REGISTER , COPY_u8PinId);
				 if( Local_u8PinValue  == 0 ){
					*COPY_Pu8PinValue = LOGIC_LOW ;
				 }
				 else if ( Local_u8PinValue  == 1 ){
					 *COPY_Pu8PinValue = LOGIC_HIGH ;
				 }
	 	 			break ;

	 	 	case PORTD :
	 	 		 Local_u8PinValue =  GET_BIT(PIND_REGISTER , COPY_u8PinId);
				 if( Local_u8PinValue  == 0 ){
					*COPY_Pu8PinValue = LOGIC_LOW ;
				 }
				 else if ( Local_u8PinValue  == 1 ){
					 *COPY_Pu8PinValue = LOGIC_HIGH ;
				 }
	 	 		 break ;

}}

else{
	Local_u8ErrorState =STD_TYPES_NOK;
}

	return   Local_u8ErrorState ; 
 } 
 
 
 u8  DIO_u8SetPortDirection(u8 COPY_u8PortId  ,u8 COPY_u8Direction) {
	u8 Local_u8ErrorState = STD_TYPES_OK ;  
	 if( (COPY_u8PortId <= PORTD)   &&  ((COPY_u8Direction == INPUT) ||(COPY_u8Direction == OUTPUT) ) ){
	 
	  switch (COPY_u8PortId){
    case PORTA:
    	DDRA_REGISTER = COPY_u8Direction;
    	break ;
    case PORTB:
       	DDRB_REGISTER = COPY_u8Direction;
       	break ;
    case PORTC:
        DDRC_REGISTER = COPY_u8Direction;
        break ;
    case PORTD:
       DDRB_REGISTER = COPY_u8Direction;
           	break ;

	 }}
	 
	 else{
	Local_u8ErrorState =STD_TYPES_NOK;
}

	return   Local_u8ErrorState ; 
	 
 }
 
 u8  DIO_u8SetPortValue(u8 COPY_u8PortId  ,u8 COPY_u8Value) {
	u8 Local_u8ErrorState = STD_TYPES_OK ;   
     if( (COPY_u8PortId <= PORTD)){
	
	switch(COPY_u8PortId ){

			 	case PORTA :
			 		 PORTA_REGISTER = COPY_u8Value ;
			 	 break ;

			 	case PORTB :
			 		 PORTB_REGISTER = COPY_u8Value ;
			 		 break ;

			 	case PORTC :

			 		 PORTC_REGISTER = COPY_u8Value ;
			 			break ;

			 	case PORTD :
			 		 PORTD_REGISTER = COPY_u8Value ;
			 		 break ;



			 	}
	 }
	 return   Local_u8ErrorState ; 
 }
  
 u8  DIO_u8GetPortValue (u8 COPY_u8PortId , u8 *COPY_Pu8PortValue){
	 
u8 Local_u8ErrorState = STD_TYPES_OK ; 	 
  
 
if( (COPY_u8PortId <= PORTD)  && (COPY_Pu8PortValue != NULL  ) ) { // ptr >> is a variable in main to store the state of pin on it

	 switch(COPY_u8PortId ){

	 	 	case PORTA :
	 	 		*COPY_Pu8PortValue = PINA_REGISTER;
				 
	 	 	 break ;

	 	 	case PORTB :
	 	 		 *COPY_Pu8PortValue = PINB_REGISTER;
	 	 		 break ;

	 	 	case PORTC :
	 	 		 *COPY_Pu8PortValue = PINC_REGISTER;
	 	 			break ;

	 	 	case PORTD :
	 	 		 *COPY_Pu8PortValue = PIND_REGISTER ;
	 	 		 break ;

}}

else{
	Local_u8ErrorState =STD_TYPES_NOK;
}

	return   Local_u8ErrorState ; 	 
	 
	 
	 
 }
