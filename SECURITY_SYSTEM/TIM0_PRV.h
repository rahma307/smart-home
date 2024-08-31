#ifndef TIM0_PRV
#define TIM0_PRV

/* Register Definition */

#define  TIM0_TCCR0       *(volatile u8 *)(0x53) 
#define  TIM0_TCNT0       *(volatile u8 *)(0x52) 
#define  TIM0_OCR0        *(volatile u8 *)(0x5C) 
#define  TIMERS_TIMSK     *(volatile u8 *)(0x59)  // enable
#define  TIMERS_TIFR      *(volatile u8 *)(0x58)  // falg

#define  TIM1_TCCR1A       *(volatile u8 *)(0x4f)
#define  TIM1_TCCR1B       *(volatile u8 *)(0x4E)

#define  TIM1_TCCNT1        *(volatile u16 *)(0x4C)
#define  TIM1_OCR1A         *(volatile u16 *)(0x4A)

#define  TIM1_ICR1          *(volatile u16 *)(0x46)


/* TCCR0 bits */

/* act as comare match " if i want to do an action on T0 PIN
 without TCNT0 value equal to OC0 value
 I can put in this bit 1 to do any action on T0"*/

#define TIM0_FOC0          7

 

#define TIM0_WGM00         6
#define TIM0_WGM01         3


/* Select T0 pin Action
  COM01     COM00     Mode
    0         0        OC0 Disconected " this pin act as normal  DIO pin "  
    0         1        TOGGLE    
	1         0        CLEAR     
	1         1         SET      
 	
*/
 
#define TIM0_COM01          5
#define TIM0_COM00          4



/* Select T0 pin Action	
*/
#define TIM0_CS02          2
#define TIM0_CS01          1
#define TIM0_CS00          0

/* TIMSK BITS for TIMER0*/
#define  TOIE0              0    //  INTERRUPT >> OVERFLOW OF TCNT0
#define  OCIE0              1    //  INTERRUPT >> COMPARE MATCH

/*  TIFR BITS FOR TIMER0  */

#define  TOV0              0    //  FLAG >> OVERFLOW OF TCNT0
#define  OCF0              1    //  FLAG >> COMPARE MATCH

#endif
