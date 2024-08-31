/*  lib layer */
#include "STD_TYPES.h"
#include  "BIT_MATH.h" 
#define   F_CPU 8000000UL
#include  <util/delay.h>

/*  mcal layer */

#include   "DIO_INT.h"

/* hal */

#include "LCD_INT.h"
#include "LCD_CONFIG.h"
#include "LCD_PRV.h"


 
 
 void LCD_INIT(void){
#if LCD_MODE == LCD_u8_Mode_8_bit
 
	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);
	  _delay_ms(35);
	 LCD_WRITE_COMMAND(lcd_FunctionSet8bit);
	 _delay_ms(5);
	 LCD_WRITE_COMMAND(lcd_DisplayOn );
	 _delay_ms(5);
	 LCD_WRITE_COMMAND(lcd_Clear );
	 _delay_ms(5);
	 LCD_WRITE_COMMAND(lcd_EntryMode );
	 
#elif  LCD_MODE == LCD_u8_Mode_4_bit
	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);
	  _delay_ms(35);

	  LCD_WRITE_COMMAND(MODE_4_FINCTIONSET_P1);
	  LCD_WRITE_COMMAND(MODE_4_FINCTIONSET_P1 );
	  LCD_WRITE_COMMAND(MODE_4_FINCTIONSET_P2);

	  _delay_ms(50);
	  LCD_WRITE_COMMAND(MODE_4_DISPLAY_ON_OF_P1);
	  LCD_WRITE_COMMAND(MODE_4_DISPLAY_ON_OF_P2);
	  _delay_ms(50);
	 LCD_WRITE_COMMAND(MODE_4_CLEAR_P1  );
	 LCD_WRITE_COMMAND(MODE_4_CLEAR_P2   );
	  _delay_ms(50);
	 LCD_WRITE_COMMAND( MODE_4_ENTRYMODESET_P1  );
	 LCD_WRITE_COMMAND( MODE_4_ENTRYMODESET_P2   );

//	  LCD_WRITE_COMMAND(MODE_4_FINCTIONSET_P1);
//	  LCD_WRITE_COMMAND(MODE_4_FINCTIONSET_P1 );
//	  LCD_WRITE_COMMAND(MODE_4_FINCTIONSET_P2);
//	 	 _delay_ms(5);
//	 	 LCD_WRITE_COMMAND(lcd_DisplayOn );
//	 	 _delay_ms(5);
//	 	 LCD_WRITE_COMMAND(lcd_Clear );
//	 	 _delay_ms(5);
//	 	 LCD_WRITE_COMMAND(lcd_EntryMode );

	 
#endif
 }
 void LCD_WRITE_COMMAND(u8 Copy_u8command){
	
#if LCD_MODE == LCD_u8_Mode_8_bit
	/* step1 : RS =0  */  // PIN0 PORTA   SET THIS VALUES IN CONFIGRATION FILE 
	
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,  RS_PIN , LOGIC_LOW);
	 
	 /* Step2 : RW =0 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,RW_PIN  , LOGIC_LOW);  // PIN1 PORTA   SET THIS VALUES IN CONFIGRATION FILE
	
     DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);   // TO ENSURE THAT ENABLE PIN IS 0 BEFORE WE SEND DATA TO LCD 
	
	 /* Write Command */
	 
	 DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8command) ; // SET PORT NUMBER IN CONFIGURATION FILE 
	 
	 /*  E=1 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_HIGH);
 	 _delay_ms(1);
	 
	 /*  E=0 */
	 
	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);
#elif  LCD_MODE == LCD_u8_Mode_4_bit	 
// send command in 4 bit mode 


/* step1 : RS =0  */  // PIN0 PORTA   SET THIS VALUES IN CONFIGRATION FILE 
	
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,  RS_PIN , LOGIC_LOW);
	 
	 /* Step2 : RW =0 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,RW_PIN  , LOGIC_LOW);  // PIN1 PORTA   SET THIS VALUES IN CONFIGRATION FILE
	
     DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);   // TO ENSURE THAT ENABLE PIN IS 0 BEFORE WE SEND DATA TO LCD 
	
	 /* Write Command */

     DIO_u8SetPinValue(LCD_DATA_PORT,PIN_4,GET_BIT(Copy_u8command,PIN_4) );//command tends to command register
     DIO_u8SetPinValue(LCD_DATA_PORT,PIN_5,GET_BIT(Copy_u8command,PIN_5) );
     DIO_u8SetPinValue(LCD_DATA_PORT,PIN_6,GET_BIT(Copy_u8command,PIN_6) );
     DIO_u8SetPinValue(LCD_DATA_PORT,PIN_7,GET_BIT(Copy_u8command,PIN_7) );

     DIO_u8SetPinValue(LCD_CONTROLL_PORT,E_PIN,LOGIC_HIGH);
     	_delay_ms(1);
     	DIO_u8SetPinValue(LCD_CONTROLL_PORT,E_PIN,LOGIC_LOW);
//
//        DIO_u8SetPinValue(LCD_DATA_PORT,PIN_4,GET_BIT(Copy_u8command,PIN_0) );//command tends to command register
//          DIO_u8SetPinValue(LCD_DATA_PORT,PIN_5,GET_BIT(Copy_u8command,PIN_1) );
//          DIO_u8SetPinValue(LCD_DATA_PORT,PIN_6,GET_BIT(Copy_u8command,PIN_2) );
//          DIO_u8SetPinValue(LCD_DATA_PORT,PIN_7,GET_BIT(Copy_u8command,PIN_3) );
//
//          DIO_u8SetPinValue(LCD_CONTROLL_PORT,E_PIN,LOGIC_HIGH);
//          	_delay_ms(1);
//          	DIO_u8SetPinValue(LCD_CONTROLL_PORT,E_PIN,LOGIC_LOW);

//     	_delay_ms(1);
//   /*  E=1 */
//
//	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_HIGH);
// 	 _delay_ms(1);
//
//	 /*  E=0 */
//
//	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);
//
//	  /* Write Command */
//
//	j=0 ;
// for(u8 i =LCD_4_BIT_START_PIN ; i<= LCD_4_BIT_END_PIN ; i++ ){
//      DIO_u8SetPinValue(LCD_DATA_PORT,i,GET_BIT(Copy_u8command,PIN_0+j));
//       j++ ;
// }
//
//   /*  E=1 */
//
//	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_HIGH);
// 	 _delay_ms(1);
//
//	 /*  E=0 */
//
//	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);

	 #endif 
 }
 
 
 void LCD_WRITE_Char(u8 Copy_u8char){
#if LCD_MODE == LCD_u8_Mode_8_bit
	/* step1 : RS =1  */  // PIN0 PORTA   SET THIS VALUES IN CONFIGRATION FILE 
	
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,  RS_PIN , LOGIC_HIGH);
	 
	 /* Step2 : RW =0 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,RW_PIN  , LOGIC_LOW);  // PIN1 PORTA   SET THIS VALUES IN CONFIGRATION FILE
	
     DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);   // TO ENSURE THAT ENABLE PIN IS 0 BEFORE WE SEND DATA TO LCD 
	
	 /* Write Command */
	 
	 DIO_u8SetPortValue(LCD_DATA_PORT , Copy_u8char) ; // SET PORT NUMBER IN CONFIGURATION FILE
	 
	 /*  E=1 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_HIGH);
 	 _delay_ms(1);
	 
	 /*  E=0 */
	 
	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);
	 
#elif  LCD_MODE == LCD_u8_Mode_4_bit	 
// send command in 4 bit mode 


/* step1 : RS =0  */  // PIN0 PORTA   SET THIS VALUES IN CONFIGRATION FILE 
	
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,RS_PIN , LOGIC_HIGH);
	 
	 /* Step2 : RW =0 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,RW_PIN  , LOGIC_LOW);  // PIN1 PORTA   SET THIS VALUES IN CONFIGRATION FILE
	
     DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);   // TO ENSURE THAT ENABLE PIN IS 0 BEFORE WE SEND DATA TO LCD 
	
	 /* Write Command */
	  u8 j =0 ;
	 for(u8 i =LCD_4_BIT_START_PIN ; i<= LCD_4_BIT_END_PIN ; i++ ){
      DIO_u8SetPinValue(LCD_DATA_PORT,i,GET_BIT(Copy_u8char,(PIN_4+j)));
       j++ ;
 }
   /*  E=1 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_HIGH);
 	 _delay_ms(1);
	 
	 /*  E=0 */
	 
	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);
	 
	  /* Write Command */
	 
	j=0 ; 
 for(u8 i =LCD_4_BIT_START_PIN ; i<= LCD_4_BIT_END_PIN ; i++ ){
      DIO_u8SetPinValue(LCD_DATA_PORT,i,GET_BIT(Copy_u8char,(PIN_0+j)));
       j++ ;
 }

   /*  E=1 */
	 
	DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_HIGH);
 	 _delay_ms(1);
	 
	 /*  E=0 */
	 
	 DIO_u8SetPinValue(LCD_CONTROLL_PORT ,E_PIN , LOGIC_LOW);

	 #endif 
 }
 
 void LCD_WRITE_STRING(u8 *copy_string ){
	u16 i =0 ;
	while(copy_string[i] !='\0'){
		LCD_WRITE_Char(copy_string[i]);
		i++ ;

	}

 }


 void Lcd_voidDisplayNumber(s32 Copy_s32Number){
	 u8 arr[20];
	 u8  i =1 ;
	 u8  j  ;
	 if( Copy_s32Number < 0 ){
		 LCD_WRITE_Char('-');
	 		Copy_s32Number *= -1 ;
	 	}

	 while(Copy_s32Number !=0 ){
		u8 units = Copy_s32Number%10 ;
		arr[i]= ('0'+units);
		Copy_s32Number /= 10 ;
		 i++ ;
	 }

	 for ( j =i-1 ; j>0 ; --j) {
		LCD_WRITE_Char(arr[j]);
	}

 }

u8 LCD_GO_TO(u8 line , u8 colummn){
	u8 local_error_state = STD_TYPES_OK;
	
	if( colummn<=39){
		
		switch(line){
			case line1:  LCD_WRITE_COMMAND(0x80 +colummn ); break ;
			
			case line2:  LCD_WRITE_COMMAND(0xc0 +colummn ); break ;
			default:local_error_state = STD_TYPES_NOK;
			
		}
	}
	
	else{
		local_error_state = STD_TYPES_NOK;
	}
	
	
	return  local_error_state ;
}

void LCD_store_customchar(u8 index,u8 *customchar){  // number of pattern  
	if(index<8){
		LCD_WRITE_COMMAND(CG_RAM_ADDRESS +index*8);
		for(u8 i=0;i<8;i++){
			LCD_WRITE_Char(customchar[i]);
		}
	    LCD_GO_TO(line1 , 1) ;	 
	}
}
//***************************************************
void LCD_DISPLAY_CUSTOM_CHAR(u8 index){
	if(index<8){
		LCD_WRITE_Char(index);
	}
}
