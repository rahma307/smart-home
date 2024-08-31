 /*******************************************************/
 /************* name : rahma mostafa  ****************/
 /************* date 17/8/2024       ***************/
 /************** SWC : DIO          *****************/
 /************** version: 1.0      *****************/
 /*******************************************************/

#ifndef DIO_PRV_H_  
#define DIO_PRV_H_

/************** DEFINETION OF  DDR REGISTERs  **********************/


#define DDRA_REGISTER   *((volatile u8 *)(0x3A))  // address from data sheet
#define DDRB_REGISTER   *((volatile u8 *)(0x37))
#define DDRC_REGISTER   *((volatile u8 *)(0x34))
#define DDRD_REGISTER   *((volatile u8 *)(0x31))




/**************     DEFINETION OF  PORT  REGISTERs    ******************/

#define PORTA_REGISTER   *((volatile u8 *)(0x3B))
#define PORTB_REGISTER   *((volatile u8 *)(0x38))
#define PORTC_REGISTER   *((volatile u8 *)(0x35))
#define PORTD_REGISTER    *((volatile u8 *)(0x32))


/************   DEFINETION OF  pin  REGISTERs  ***************/

#define PINA_REGISTER   *((volatile u8 *)(0x39))
#define PINB_REGISTER   *((volatile u8 *)(0x36))
#define PINC_REGISTER   *((volatile u8 *)(0x33))
#define PIND_REGISTER   *((volatile u8 *)(0x30))

/* macros for pins Directions */

#define DIO_u8_INITIL_OUTPUT     1 
#define DIO_u8_INITIL_INPUT      0

/* macros for pins values   */
#define  DIO_u8_OUTPUT_HIGH       1 
#define  DIO_u8_OUTPUT_LOW        0
#define  DIO_u8_INPUT_FLOATTING   0
#define  DIO_u8_INPUT_PULLUP	  1


#define Conc(b7,b6,b5,b4,b3,b2,b1,b0)           Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_Help(b7,b6,b5,b4,b3,b2,b1,b0)      0b##b7##b6##b5##b4##b3##b2##b1##b0


  
#endif /* V_H_ */
