#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/*
select control port :
PORTA
PORTB
PORTC
PORTD
 
*/

#define LCD_CONTROLL_PORT  PORTB


/*
select DATA port :
PORTA
PORTB
PORTC
PORTD
 
*/

#define LCD_DATA_PORT  PORTC
 

#define  RS_PIN   PIN_0
#define  RW_PIN   PIN_1
#define  E_PIN    PIN_2

/*SELECT
 *PIN_0
 * OR
 * PIN1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7
 *
 */


#define LCD_MODE  LCD_u8_Mode_8_bit 

/*  options : LCD_u8_Mode_8_bit
              LCD_u8_Mode_4_bit
 
*/


 
#define LCD_4_BIT_START_PIN  PIN_0
#define LCD_4_BIT_END_PIN    PIN_3


/* OPTIONS :  

*PIN_0
 * OR
 * PIN1
 * OR
 * PIN_2
 * OR
 * PIN_3
 * OR
 * PIN_4
 * OR
 * PIN_5
 * OR
 * PIN_6
 * OR
 * PIN_7

*/

#endif 
