/*  lib layer */
#include "STD_TYPES.h"
#include  "BIT_MATH.h" 
#define   F_CPU 8000000UL
#include  <util/delay.h>

/*  mcal layer */

#include   "DIO_INT.h"

/* hal */
#include "KP_INT.h"
#include "KP_CONFIG.h"
#include "KP_PRV.h"

const  u8 KPD_Au8Keys[4][4]= KPD_Keys ;
 

const u8 Kpd_rows [4] ={KPD_RL1_PIN,KPD_RL2_PIN,KPD_RL3_PIN,KPD_RL4_PIN} ;
const u8 Kpd_cols [4] ={KPD_CL1_PIN,KPD_CL2_PIN,KPD_CL3_PIN ,KPD_CL4_PIN } ;

u8 KPD_u8KpdGetKeyState(u8 * Copy_pu8RteurnedKey){
	*Copy_pu8RteurnedKey = Kpd_keynotpressed ;

	 u8 LOCAL_ERROR_STATE = STD_TYPES_OK;
	 u8 local_u8Rowscounter ;
	 u8 local_u8CLScounter ;
	  u8 local_u8PinValue;
	  u8 local_flage =0 ;
	if(Copy_pu8RteurnedKey !=NULL){
	   /* Activation Each Row => for loop on the pins of rows */
	   
	   for(local_u8Rowscounter =0 ; local_u8Rowscounter <=3 ; local_u8Rowscounter++){
		   DIO_u8SetPinValue(KPD_PORT_row,  Kpd_rows[local_u8Rowscounter], LOGIC_LOW);
		   
		   for(local_u8CLScounter =0 ; local_u8CLScounter <= 2 ; local_u8CLScounter++){
			  
			   DIO_u8GetPinValue(KPD_PORT_col,Kpd_cols[local_u8CLScounter],&local_u8PinValue );
				  
			  if(local_u8PinValue == LOGIC_LOW){  /*Switch is presed */
				   _delay_ms(20); // FOR BOUNCING 
				   /* check if the pin is still low */
				   DIO_u8GetPinValue(KPD_PORT_col,Kpd_cols[local_u8CLScounter],&local_u8PinValue );
			     while(local_u8PinValue == LOGIC_LOW){  // TO TAKE READ OF PIN ONE TIME 
			    	 DIO_u8GetPinValue(KPD_PORT_col,Kpd_cols[local_u8CLScounter],&local_u8PinValue );
				 }
				 local_flage =1 ;
			  * Copy_pu8RteurnedKey = KPD_Au8Keys[local_u8Rowscounter][local_u8CLScounter];
			  break ; 
		   }	  }
		   
		   /* disactivate Row */
          DIO_u8SetPinValue(KPD_PORT_row,  Kpd_rows[local_u8Rowscounter], LOGIC_HIGH);
		   if(local_flage){
			   break ;
		   }
		   
	   }
	}
	else{
		
		LOCAL_ERROR_STATE = STD_TYPES_NOK;
	}
	
	return LOCAL_ERROR_STATE ;
}
