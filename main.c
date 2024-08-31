/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: hp
 */
/*  lib layer */
#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#define   F_CPU 8000000UL
#include  <util/delay.h>

/*  mcal layer */

#include   "DIO_INT.h"
#include   "TIM0_INT.h"
#include    "ADC_INT.h"
#include    "GLOPAL_INT.h"

/* hal */
#include "KP_INT.h"
#include "LCD_INT.h"
#include  "STEPPER_INT.h"




#define  Green     PIN_4
#define  red       PIN_7
#define  trans     PIN_7
#define  key       PIN_7
#define  ROOM_led  PIN_4
#define  key_pin       PIN_6

static u16 digital =0xffff ;

u8 pinvalue ;
u16 num_1=0 ;
u8 sign_1 ;
u8 temp ;
u8 led_flag =0 ;
u8 cond_flag =1 ;
u8 window_flag =0 ;
u8 fla =0 ;
void pass_correct_action(void){
	/*use tim1 ocra1 >>  500  to pen the door " servo angle 0"*/

	TIM1_OCR1AVAL(500); // angle 180
	/* led on */
    DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_HIGH );
    /* dc motor use tim0  compare match >> 170  t = 25 */
    TIMERS_TIM0SetCompareMatchVAlue(170);
   window_flag =0 ;
   fla=0 ;
    temp = 25 ;
    num_1=0 ;

}


void lcd_mode(void){
	  num_1=0;
	  LCD_WRITE_COMMAND(lcd_Clear);
	  LCD_WRITE_STRING(" 1_options");
	  LCD_GO_TO(line2 , 0);
	  LCD_WRITE_STRING("2_Turn Off All");
	  window_flag=0 ;
	  do{
	  	 KPD_u8KpdGetKeyState(&pinvalue);
	  }while(pinvalue == Kpd_keynotpressed);
	  sign_1 = pinvalue -'0';
	  if(sign_1 >=0 && sign_1<=9 ){
		  num_1 = (num_1*10) + (pinvalue -'0');
	  }
	 if(num_1 == 1){
		 num_1=0 ;
		 LCD_WRITE_COMMAND(lcd_Clear);
		 LCD_WRITE_STRING(" 1-Window 2-LED");
		 LCD_GO_TO(line2 , 0);
		 LCD_WRITE_STRING("3-Aircond 4-back");
		 do{
			 KPD_u8KpdGetKeyState(&pinvalue);
		}while(pinvalue == Kpd_keynotpressed);
		sign_1 = pinvalue -'0';
		if(sign_1 >=0 && sign_1<=9 ){
	    num_1 = (num_1*10) + (pinvalue -'0');
	 }
	 }
	 else if ( num_1 == 2){
		 // turn off all devices

		 for(int i=0 ; i<24 ; i++){       // window off
		 	  STEPPER_voidmotion(CLOCK_WISE , 15);
		 		 }
		 DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
		 TIMERS_TIM0SetCompareMatchVAlue(0 ); // air conditioner off
		 cond_flag=0 ;
		 num_1=0 ;
	 }

 }

void notification(u16 digitalvalue){  //  u16 digitalvalue = adc_reg "digital value "
  digital= digitalvalue;
}


u8 window(u8 n){

	switch (n) {
	case 1 :
		num_1 =0 ;
   if( fla==1){
		for(int i=0 ; i<24 ; i++){       // window off
		STEPPER_voidmotion(CLOCK_WISE , 15);
				 }
		fla=0;
		 window_flag=0 ;}

		break ;
	case 2:
		num_1 =0 ;
	if( window_flag ==0){
		for(int i=0 ; i<24 ; i++){       // window fully open
		  STEPPER_voidmotion(ANTI_CLOCK_WISE , 15);
			 }
		fla=1 ;
       window_flag=1 ;}
	window_flag=1 ;
	break ;

	case 3:
		num_1 =0 ;
		if( window_flag==0){
		for(int i=0 ; i<8 ; i++){       // window partially
		 STEPPER_voidmotion(ANTI_CLOCK_WISE , 15);

					 }
		fla=1 ;
		 window_flag=1 ;}
		window_flag=1 ;
		break ;
	case 4:
		num_1 =0 ;
		 LCD_WRITE_COMMAND(lcd_Clear);
    	  LCD_WRITE_STRING(" 1_options");
    	  LCD_GO_TO(line2 , 0);
    	  LCD_WRITE_STRING("2_Turn Off All");
    	  do{
    	  	 KPD_u8KpdGetKeyState(&pinvalue);
    	  }while(pinvalue == Kpd_keynotpressed);
    	  sign_1 = pinvalue -'0';
    	  if(sign_1 >=0 && sign_1<=9 ){
    		  num_1 = (num_1*10) + (pinvalue -'0');
			  }
    	 if ( num_1 == 2){  // turn off all devices

    	  	DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
    	  	TIMERS_TIM0SetCompareMatchVAlue(0 ); // air conditioner off
    	  	if(window_flag == 1 ){
    	  			  for(int i=0 ; i<24 ; i++){       // window off
    	  			  		      STEPPER_voidmotion(CLOCK_WISE , 15);
    	  			  		 	 }
    	  			     	 }
    	  	cond_flag=0 ;
    	  	num_1=0 ;
    	  	 }
    	 window_flag=0 ;
		break ;

	}


	return window_flag;

}


void led(u8 f){
switch (num_1){

 case 1 :
	 DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
	 num_1=0 ;
	 led_flag=0 ;
	 break ;
 case 2 :

    if( f == 0){
       DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_HIGH );
	  led_flag=1 ;
    } // room led  on}
	  else if( f==1 ) {
		  DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
	  led_flag=0 ;
	 	 num_1=0 ;}
	 break ;
 case 3 :

	 num_1 =0 ;
	 LCD_WRITE_COMMAND(lcd_Clear);
	 LCD_WRITE_STRING(" 1_options");
	 LCD_GO_TO(line2 , 0);
	 LCD_WRITE_STRING("2_Turn Off All");
	 do{
	 	 KPD_u8KpdGetKeyState(&pinvalue);
	 }while(pinvalue == Kpd_keynotpressed);
	 sign_1 = pinvalue -'0';
	 if(sign_1 >=0 && sign_1<=9 ){
		  num_1 = (num_1*10) + (pinvalue -'0');
		  }
	 if ( num_1 == 2){  // turn off all devices

	  DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
	  TIMERS_TIM0SetCompareMatchVAlue(0 ); // air conditioner off
	  if(window_flag == 1 ){
	  		  for(int i=0 ; i<24 ; i++){       // window off
	  		  		      STEPPER_voidmotion(CLOCK_WISE , 15);
	  		  		 	 }
	  		     	 }
	     	 }
	 cond_flag=0 ;
     num_1=0 ;
	 break ;

}



}




u8 air_conutioner(u8 n , u8 f){
 u16 count =0 ;
  switch(f){
	 case 0:

        num_1=0;
	     LCD_WRITE_COMMAND(lcd_Clear);
	 	LCD_WRITE_STRING(" 1-T=25 2-T=30");
	 	LCD_GO_TO(line2 , 0);
	 	LCD_WRITE_STRING(" 3-T=22 4-cont");
	 	 do{
	 	 	 KPD_u8KpdGetKeyState(&pinvalue);
	 	 }while(pinvalue == Kpd_keynotpressed);
	 	 sign_1 = pinvalue -'0';
	 	 if(sign_1 >=0 && sign_1<=9 ){
	 		  num_1 = (num_1*10) + (pinvalue -'0');
	 	 }
	 	 switch(num_1){
	 	 case 1:
		/* dc motor use tim0  compare match >> 170  t = 25 */
		    TIMERS_TIM0SetCompareMatchVAlue(170);
		    temp = 25 ;
		    cond_flag=1 ;
		    num_1=0 ;
	break ;
	case 2:
		/* dc motor use tim0  compare match >> 120  t = 30 */
		    TIMERS_TIM0SetCompareMatchVAlue(120);
		    temp = 30 ;
		    cond_flag=1 ;
		    num_1=0;
	break ;
	case 3:
		/* dc motor use tim0  compare match >> 250  t = 22 */
		    TIMERS_TIM0SetCompareMatchVAlue(250);
		    temp = 22 ;
		    cond_flag=1 ;
		    num_1=0 ;
	break ;
	case 4:

		num_1 =0 ;
		LCD_WRITE_COMMAND(lcd_Clear);
		LCD_WRITE_STRING(" 1-Turn OFF");
		LCD_GO_TO(line2 , 0);
		LCD_WRITE_STRING("3-back");
		 do{
		 	 KPD_u8KpdGetKeyState(&pinvalue);
		 }while(pinvalue == Kpd_keynotpressed);
		 sign_1 = pinvalue -'0';
		 if(sign_1 >=0 && sign_1<=9 ){
			  num_1 = (num_1*10) + (pinvalue -'0');
			 }

		switch(num_1){
		case 1:
			num_1=0 ;
			TIMERS_TIM0SetCompareMatchVAlue(0);
			cond_flag=0 ;
			break ;
		case 2 :

			 num_1 =0 ;
				 LCD_WRITE_COMMAND(lcd_Clear);
				 LCD_WRITE_STRING(" 1_options");
				 LCD_GO_TO(line2 , 0);
				 LCD_WRITE_STRING("2_Turn Off All");
				 do{
				 	 KPD_u8KpdGetKeyState(&pinvalue);
				 }while(pinvalue == Kpd_keynotpressed);
				 sign_1 = pinvalue -'0';
				 if(sign_1 >=0 && sign_1<=9 ){
					  num_1 = (num_1*10) + (pinvalue -'0');
					  }
				 if ( num_1 == 2){  // turn off all devices

				  DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
				  TIMERS_TIM0SetCompareMatchVAlue(0 ); // air conditioner off
				  if(window_flag == 1 ){
				 	  		  for(int i=0 ; i<24 ; i++){       // window off
				 	  		  		      STEPPER_voidmotion(CLOCK_WISE , 15);
				 	  		  		 	 }
				 	  		     	 }
				  cond_flag=0 ;
			     num_1=0 ;
			     window_flag=0 ;
  }
	break ;
	}}
	 break ;
	 case 1:
		 while(fla ==1){
		 	     num_1 =0 ;
		 	LCD_WRITE_COMMAND(lcd_Clear);
		   LCD_WRITE_STRING(" Window is open");
		   LCD_GO_TO(line2 , 0);
		   LCD_WRITE_STRING("close it");
           _delay_ms(1000);
		   LCD_WRITE_STRING("!!");
		   LCD_WRITE_COMMAND(lcd_Clear);
		   LCD_WRITE_STRING(" 1-Close ");
		     do{
		   	 KPD_u8KpdGetKeyState(&pinvalue);
		   	 count++ ;
		   	 }while(pinvalue == Kpd_keynotpressed && count <5000);
		    sign_1 = pinvalue -'0';
		     if(sign_1 >=0 && sign_1<=9 ){
		       num_1 = (num_1*10) + (pinvalue -'0');
		   	 }
		    if( num_1 ==1){
		     	 f=window(num_1);
		     	fla =0 ;
               num_1 =0 ;
               num_1=0;
              	     LCD_WRITE_COMMAND(lcd_Clear);
              	 	LCD_WRITE_STRING(" 1-T=25 2-T=30");
              	 	LCD_GO_TO(line2 , 0);
              	 	LCD_WRITE_STRING(" 3-T=22 4-cont");
              	 	 do{
              	 	 	 KPD_u8KpdGetKeyState(&pinvalue);
                   	 	 }while(pinvalue == Kpd_keynotpressed);
                   	 	 sign_1 = pinvalue -'0';
       	 	 if(sign_1 >=0 && sign_1<=9 ){
       	 		  num_1 = (num_1*10) + (pinvalue -'0');
       	 	 }
       	 	 switch(num_1){
       	 	 case 1:
       		/* dc motor use tim0  compare match >> 170  t = 25 */
       		    TIMERS_TIM0SetCompareMatchVAlue(170);
       		    temp = 25 ;
       		    cond_flag=1 ;
       		    num_1=0 ;
       	break ;
       	case 2:
       		/* dc motor use tim0  compare match >> 120  t = 30 */
       		    TIMERS_TIM0SetCompareMatchVAlue(120);
       		    temp = 30 ;
       		    cond_flag=1 ;
       		    num_1=0;
       	break ;
       	case 3:
       		/* dc motor use tim0  compare match >> 250  t = 22 */
       		    TIMERS_TIM0SetCompareMatchVAlue(250);
       		    temp = 22 ;
       		    cond_flag=1 ;
       		    num_1=0 ;
       	break ;
       	case 4:

       			num_1 =0 ;
       			LCD_WRITE_COMMAND(lcd_Clear);
       			LCD_WRITE_STRING(" 1-Turn OFF");
       			LCD_GO_TO(line2 , 0);
       			LCD_WRITE_STRING("3-back");
       			 do{
       			 	 KPD_u8KpdGetKeyState(&pinvalue);
       			 }while(pinvalue == Kpd_keynotpressed);
       			 sign_1 = pinvalue -'0';
       			 if(sign_1 >=0 && sign_1<=9 ){
       				  num_1 = (num_1*10) + (pinvalue -'0');
                   				 }

      	switch(num_1){
      	case 1:
      		num_1=0 ;
      		TIMERS_TIM0SetCompareMatchVAlue(0);
      		cond_flag=0 ;
      		break ;
      	case 2 :

      		 num_1 =0 ;
      			 LCD_WRITE_COMMAND(lcd_Clear);
      			 LCD_WRITE_STRING(" 1_options");
      			 LCD_GO_TO(line2 , 0);
      			 LCD_WRITE_STRING("2_Turn Off All");
      			 do{
      			 	 KPD_u8KpdGetKeyState(&pinvalue);
      			 }while(pinvalue == Kpd_keynotpressed);
      			 sign_1 = pinvalue -'0';
      			 if(sign_1 >=0 && sign_1<=9 ){
      				  num_1 = (num_1*10) + (pinvalue -'0');
      				  }
      			 if ( num_1 == 2){  // turn off all devices

      			  DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
      			  TIMERS_TIM0SetCompareMatchVAlue(0 ); // air conditioner off
      			  if(window_flag == 1 ){
      			 	  		  for(int i=0 ; i<24 ; i++){       // window off
      			 	  		  		      STEPPER_voidmotion(CLOCK_WISE , 15);
      			 	  		  		 	 }
      			 	  		     	 }
      			  cond_flag=0 ;
      		     num_1=0 ;
                   				     window_flag=0 ;

                   	  }

      	}}

       	 	 fla=0;
		    break ;

		    }
		 	     else if( f == 1){
		 	      	    	num_1 =0 ;
                        TIMERS_TIM0SetCompareMatchVAlue(0);
		 	    	    	 	    LCD_WRITE_COMMAND(lcd_Clear);
		 	    	    	 	    LCD_WRITE_STRING(" conditioner closed");
		 	    	    	 	    _delay_ms(2000);
		 	    	    	 	    cond_flag = 0 ;
		 	    	    	        cond_flag =0 ;
		 	    	    	        fla = 1 ;
		 	      	    	break;
		 	      	    }

		 }

		 break ;
	 }





  return cond_flag;
}


void setting(u16 num){
	static u8  c=0 ,  w=0;
	u16 coun =0 ;
	 u16 analog ;
	 u16 tamp ;
	ADC_GetDigitalValueAsynch(ADC_CHANNEL1,&notification);

 switch (num){

 case 1 :
	 // window
	 Lcd_voidDisplayNumber(num_1);
	 _delay_ms(500);
	 num_1=0;
	 LCD_WRITE_COMMAND(lcd_Clear);
	 LCD_WRITE_STRING(" 1-Close 2-fully");
	 LCD_GO_TO(line2 , 0);
	 LCD_WRITE_STRING("3-Partial 4-back");
	 do{
	 	 KPD_u8KpdGetKeyState(&pinvalue);
		}while(pinvalue == Kpd_keynotpressed);
	 sign_1 = pinvalue -'0';
	 if(sign_1 >=0 && sign_1<=9 ){
	  num_1 = (num_1*10) + (pinvalue -'0');
	 	}
  w=window(num_1);
	 break ;
 case 2:
	 Lcd_voidDisplayNumber(num_1);
	 _delay_ms(500);
	 num_1=0;
	 LCD_WRITE_COMMAND(lcd_Clear);
	 LCD_WRITE_STRING(" 1-OFF  2-ON");
	 LCD_GO_TO(line2 , 0);
	 LCD_WRITE_STRING(" 3-back  ");
	 do{
	 	KPD_u8KpdGetKeyState(&pinvalue);
	 	}while(pinvalue == Kpd_keynotpressed);
	  sign_1 = pinvalue -'0';
	  if(sign_1 >=0 && sign_1<=9 ){
	  num_1 = (num_1*10) + (pinvalue -'0');
	 	 	}
   led(w);
	 break ;

 case 3:
	 Lcd_voidDisplayNumber(num_1);
	 _delay_ms(500);
	 num_1=0;
	 if(digital != 0xffff){
	  analog =(digital*5000UL)/1024 ;
	   temp = analog/10;}
	 LCD_WRITE_COMMAND(lcd_Clear);
	 LCD_WRITE_STRING(" T out=");

	 Lcd_voidDisplayNumber(tamp);
	 LCD_GO_TO(line2 , 0);
	 LCD_WRITE_STRING("RoomT=   1-set");
	 LCD_GO_TO(line2 ,6);
	 Lcd_voidDisplayNumber(temp);

	do{
	  KPD_u8KpdGetKeyState(&pinvalue);
	  }while(pinvalue == Kpd_keynotpressed);
    sign_1 = pinvalue -'0';
    if(sign_1 >=0 && sign_1<=9 ){
		  num_1 = (num_1*10) + (pinvalue -'0');
		 	 	}
 c= air_conutioner(num_1 , w);
	 break ;

 case 4 :
	 num_1 =0 ;
		 LCD_WRITE_COMMAND(lcd_Clear);
		 LCD_WRITE_STRING(" 1_options");
		 LCD_GO_TO(line2 , 0);
		 LCD_WRITE_STRING("2_Turn Off All");
		 do{
		 	 KPD_u8KpdGetKeyState(&pinvalue);
		 }while(pinvalue == Kpd_keynotpressed);
		 sign_1 = pinvalue -'0';
		 if(sign_1 >=0 && sign_1<=9 ){
			  num_1 = (num_1*10) + (pinvalue -'0');
			  }
		 if ( num_1 == 2){  // turn off all devices

		  DIO_u8SetPinValue(PORTA ,ROOM_led , LOGIC_LOW );   // room led off
		  TIMERS_TIM0SetCompareMatchVAlue(0 ); // air conditioner off
		 if(w == 1 ){
		  for(int i=0 ; i<24 ; i++){       // window off
		  		      STEPPER_voidmotion(CLOCK_WISE , 15);
		  		 	 }
		     	 }}
		 cond_flag=0 ;
	     num_1=0 ;
     break ;

}

 while(fla==1  && cond_flag ==1 ){
 	     num_1 =0 ;
 		LCD_WRITE_COMMAND(lcd_Clear);
 	    LCD_WRITE_STRING(" Window is open");
 	    LCD_GO_TO(line2 , 0);
 	    LCD_WRITE_STRING("close it");
          _delay_ms(1000);
 	    	LCD_WRITE_STRING("!!");

 	    LCD_WRITE_COMMAND(lcd_Clear);
        LCD_WRITE_STRING(" 1-Close ");
          do{
 	    	  KPD_u8KpdGetKeyState(&pinvalue);
 	    	   coun++ ;
 	    	 }while(pinvalue == Kpd_keynotpressed && coun <5000);
 	     sign_1 = pinvalue -'0';
 	      if(sign_1 >=0 && sign_1<=9 ){
 	        num_1 = (num_1*10) + (pinvalue -'0');
 	    	 }
 	   if( num_1 ==1){
 		   LCD_WRITE_Char('j');
 	      w=window(1);
 	      fla =0 ;
 	      break ;
              }
 	  LCD_WRITE_Char('j');
 	        num_1 =0 ;
            TIMERS_TIM0SetCompareMatchVAlue(0);
 	    	 LCD_WRITE_COMMAND(lcd_Clear);
 	    	LCD_WRITE_STRING(" conditioner closed");
 	    	 _delay_ms(2000);
 	    	cond_flag = 0 ;
 	    	 c =0 ;
 	    	 window_flag=1 ;
 	    	 fla =1 ;

  }




}

int main(){

	DIO_voidInit();
	LCD_INIT();
	TIM0_INIT();
	TIM1_INTI();
	ADC_VoINIT();
	u16 pass = 292004;
	u8 count =6 ;
	u8 try_num = 3 ;
	u8 flage =0 ;
	u8 i=0;
    u8 key_1 ;

	while(1){


        if( try_num == 3  && flage ==0 ){   // flage == 1 when password is correct
		LCD_WRITE_STRING(" Enter password : ");
		 LCD_GO_TO(line2,0);
		/*take password  */
	 while(1){
      // servo angle 0 >> ocra1 == 1500
		 TIM1_OCR1AVAL(1500); // angle 180
		 do{
			 KPD_u8KpdGetKeyState(&pinvalue);
		 }while(pinvalue == Kpd_keynotpressed);
		 sign_1 = pinvalue -'0';
		 if(sign_1 >=0 && sign_1<=9 ){

        num_1 = (num_1*10) + (pinvalue -'0');
         LCD_WRITE_Char(pinvalue);
        	 _delay_ms(100);
        	 LCD_GO_TO(line2 , i);
        	  LCD_WRITE_Char('*');
        	        i++;
		  }
		 if( count ==1){
			 break;
		 }
		 else{

			 count-- ;
		 }
	 }



	   if(num_1 == pass ){
             i=0 ;
             num_1=0 ;
			flage=1;
			count =6 ;
		    LCD_WRITE_COMMAND(lcd_Clear);
		    LCD_GO_TO(line1 , 3);
		    LCD_WRITE_STRING("correct password");
			LCD_GO_TO(line2 ,0);
		    LCD_WRITE_STRING("Door open");
            _delay_ms(500);
            pass_correct_action();
         while(1){
            lcd_mode();
            setting(num_1);

            num_1=0 ;


         }
       }
		else{
			// servo angle 0 >> ocra1 == 1500
			TIM1_OCR1AVAL(1500); // angle 180
              try_num--;
             LCD_WRITE_COMMAND(lcd_Clear);
             LCD_GO_TO(line1 , 3);
              LCD_WRITE_STRING("Wrong password");
              _delay_ms(1000);
              LCD_WRITE_COMMAND(lcd_Clear);
              count =6 ;
              num_1 =0 ;
		}

		}

   else if( try_num<3  &&  try_num>0 && flage ==0){
	   // servo angle 0 >> ocra1 == 1500
	   LCD_GO_TO(line1 , 3);
	   LCD_WRITE_STRING("Try again : ");
	   LCD_GO_TO(line2,0);
	   i=0 ;
	   // servo angle 0 >> ocra1 == 1500
	  while(1){
	   TIM1_OCR1AVAL(1500); // angle 180
	  		 do{
	  			 KPD_u8KpdGetKeyState(&pinvalue);
	  		 }while(pinvalue == Kpd_keynotpressed);
	  		 sign_1 = pinvalue -'0';
	  		 if(sign_1 >=0 && sign_1<=9 ){

	          num_1 = (num_1*10) + (pinvalue -'0');
	           LCD_WRITE_Char(pinvalue);
	          	 _delay_ms(100);
	          	 LCD_GO_TO(line2 , i);
	          	  LCD_WRITE_Char('*');
	          	        i++;
	  		  }
		 	  if( count == 1){
		 	 	 break;
		 	  }
		   else{
		 	 	 count-- ;
		 		 }
	  }

		 if(num_1 == pass ){
			    num_1=0 ;
				flage=1;
				count =6 ;
			    LCD_WRITE_COMMAND(lcd_Clear);
			    LCD_GO_TO(line1 , 3);
			    LCD_WRITE_STRING(" correct password");
				LCD_GO_TO(line2 ,0);
			    LCD_WRITE_STRING(" Door open");
	            _delay_ms(500);
	            pass_correct_action();
	                   while(1){
	                      lcd_mode();
	                      setting(num_1);

	                      num_1=0 ;


	                   }
		 		}
		 else{
			 // servo angle 0 >> ocra1 == 1500
			 TIM1_OCR1AVAL(1500); // angle 180
			  LCD_WRITE_COMMAND(lcd_Clear);
			  LCD_GO_TO(line1 , 3);
			 LCD_WRITE_STRING(" Wrong password");
			 _delay_ms(1000);
			 LCD_WRITE_COMMAND(lcd_Clear);
		       try_num--;
		       count =6 ;
		       num_1=0 ;
		 		}
	}
   else if( try_num==0){
	   // servo angle 0 >> ocra1 == 1500
	   TIM1_OCR1AVAL(1500); // angle 180
	   DIO_u8SetPinValue(PORTD ,trans , LOGIC_HIGH);
	   DIO_u8SetPinValue(PORTA ,red, LOGIC_HIGH);
        DIO_u8GetPinValue(PORTD, PIN_6 , &key_1);
        LCD_WRITE_COMMAND(lcd_Clear);
        LCD_WRITE_STRING(" Door locked");
     while( key_1 ==1){
	   DIO_u8GetPinValue(PORTD, PIN_6 , &key_1);
        }
    count =6 ;
	   try_num=3 ;
	   flage =0 ;
	   num_1=0;
	   DIO_u8SetPinValue(PORTD ,trans , LOGIC_LOW);
	   LCD_WRITE_COMMAND(lcd_Clear);
	   DIO_u8SetPinValue(PORTA ,red, LOGIC_LOW);
	   i=0 ;
   }




	}

}

