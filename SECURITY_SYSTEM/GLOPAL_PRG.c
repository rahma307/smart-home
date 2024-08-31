/*  lib layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

/*MCAL*/
#include "GLOPAL_INT.h"

#define  SREG             *((volatile u8 *)(0x5f))


void  GI_voidEnable(void){
/* ENABLE  GIE */

SET_BIT(SREG,7);	
	
	
}
void  GI_voidDisAble(void){
	
	CLR_BIT(SREG,7);
	
}