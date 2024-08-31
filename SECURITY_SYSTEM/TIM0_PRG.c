/*  lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h" 

/* MCAL layer */

#include  "TIM0_INT.h"
#include  "TIM0_CONFIG .h"
#include  "TIM0_PRV.h"


/* Start timer */

void TIM0_INIT(void){

	/*SELECT TIMER MODER   => fast pwm  */

	SET_BIT(TIM0_TCCR0 ,TIM0_WGM00);
	SET_BIT(TIM0_TCCR0 ,TIM0_WGM01 );

/* Enable Interrupt => OVERFLOW */
/*
SET_BIT(TIMERS_TIMSK,TOIE0);
*/

/*  non inverting mode */

	SET_BIT(TIM0_TCCR0,TIM0_COM01);
	CLR_BIT(TIM0_TCCR0 ,TIM0_COM00 );

/* Select clk source >> CLK/8  */

SET_BIT(TIM0_TCCR0,TIM0_CS01);	
CLR_BIT(TIM0_TCCR0 ,TIM0_CS02);
CLR_BIT(TIM0_TCCR0 ,TIM0_CS00);

	
}


void TIM1_INTI(void){
	/* select timer1 mode =>> mode 14 */
	SET_BIT(TIM1_TCCR1A ,  1);
	CLR_BIT(TIM1_TCCR1A ,  0);
    SET_BIT(TIM1_TCCR1B ,4);
    SET_BIT(TIM1_TCCR1B ,3);

   /* clear oc1a >> D5  on compare match set on overflow  */
	SET_BIT(TIM1_TCCR1A ,  7);
	CLR_BIT(TIM1_TCCR1A ,  6);

	/* set top value in ICR1 REG */
	TIM1_ICR1 = 19999;   // period  = 20 ms



    /* Select clk source >> CLK/8  */

    		 SET_BIT(TIM1_TCCR1B,1);
    		 CLR_BIT(TIM1_TCCR1B,2);
    		 CLR_BIT(TIM1_TCCR1B,0);

}


void TIM1_OCR1AVAL(u16 val ){

	/* set angle of servo */

	     TIM1_OCR1A = val;
}



void TIMERS_TIM0SetCompareMatchVAlue(u8 val){
	TIM0_OCR0 = val ;

}



