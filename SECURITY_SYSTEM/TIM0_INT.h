#ifndef  TIM0_INT_H
#define  TIM0_INT_H

void TIM0_INIT(void);
u8 TIM0_SetCallBackoverflow (void (*pf)(void)) ;
void TIMERS_TIM0SetCompareMatchVAlue(u8 val);
u8 TIM0_SetCallBackctc (void (*pf)(void)) ;
void TIM1_INTI(void);

void TIM1_OCR1AVAL(u16 val );

#endif
