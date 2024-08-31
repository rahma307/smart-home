 /*******************************************************/
 /************* name : rahma mostafa  ****************/
 /************* date 17/8/2024       ***************/
 /************** SWC : DIO          *****************/
 /************** version: 1.0      *****************/
  /*******************************************************/
  
#ifndef DIO_INT_H
#define DIO_INT_H


/****** PORTS*******/

#define PORTA    1
#define PORTB    2
#define PORTC    3
#define PORTD    4

/******* MODE********/

#define  INPUT    0
#define  OUTPUT   1

/******** PINS*********/

#define PIN_0     0
#define PIN_1     1
#define PIN_2     2
#define PIN_3     3
#define PIN_4     4
#define PIN_5     5
#define PIN_6     6
#define PIN_7     7



/******** port  mode   *************/
#define  INPUT_PORT    0
#define  OUTPUT_PORT   255

/******* output mode **********/

#define LOGIC_LOW   0
#define LOGIC_HIGH  1

void DIO_voidInit(void);
  
 u8  DIO_u8SetPinDirection(u8 COPY_u8PortId , u8 COPY_u8PinId ,u8 COPY_u8Direction);  // return  1 value >> indicator to check if function is correct or not 
 
 u8  DIO_u8SetPinValue(u8 COPY_u8PortId , u8 COPY_u8PinId ,u8 COPY_u8Value);  // output pin value 0v | 5v
 
 u8  DIO_u8GetPinValue(u8 COPY_u8PortId , u8 COPY_u8PinId ,u8 *COPY_Pu8PinValue); // return 2 values 1>> indicator to check if function is correct or not  2>> state of pin 
 
 u8  DIO_u8SetPortDirection(u8 COPY_u8PortId  ,u8 COPY_u8Direction) ;
 
 u8  DIO_u8SetPortValue(u8 COPY_u8PortId  ,u8 COPY_u8Value) ;
  
 u8  DIO_u8GetPortValue (u8 COPY_u8PortId , u8 *COPY_Pu8PortValue);   // pin register and port location that we need ti reed its pins 
 
 
 
  
 
 
 
 
#endif