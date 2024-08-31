#ifndef DIO_CONFIG_H
#define DIO_CONFIG_H

/*  initial direction for all pins */


/*     Options : DIO_u8_INITIL_OUTPUT    
                 DIO_u8_INITIL_INPUT     */
				 
				 
				 
				 

/* PORTA */
#define DIO_u8_PA0_INTIAL_DIRECTION          DIO_u8_INITIL_OUTPUT // blue stepper
#define DIO_u8_PA1_INTIAL_DIRECTION          DIO_u8_INITIL_OUTPUT // pink stepper
#define DIO_u8_PA2_INTIAL_DIRECTION          DIO_u8_INITIL_OUTPUT // yellow stepper
#define DIO_u8_PA3_INTIAL_DIRECTION          DIO_u8_INITIL_OUTPUT  // orange stepper
#define DIO_u8_PA4_INTIAL_DIRECTION          DIO_u8_INITIL_OUTPUT  // room led
#define DIO_u8_PA5_INTIAL_DIRECTION          DIO_u8_INITIL_INPUT   // LDR
#define DIO_u8_PA6_INTIAL_DIRECTION          DIO_u8_INITIL_INPUT   // temp sensor
#define DIO_u8_PA7_INTIAL_DIRECTION          DIO_u8_INITIL_OUTPUT   // incorrect pass
								             
/* PORTB */                                   
#define DIO_u8_PB0_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT      // RS
#define DIO_u8_PB1_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT      // RW
#define DIO_u8_PB2_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT       // E
#define DIO_u8_PB3_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT        // DC MOTOR TIM0
#define DIO_u8_PB4_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT        // R1
#define DIO_u8_PB5_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT        // R2
#define DIO_u8_PB6_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT        // R3
#define DIO_u8_PB7_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT         // R4
								              
/* PORTC */                                  
#define DIO_u8_PC0_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT        // LCD DATA PORT
#define DIO_u8_PC1_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
#define DIO_u8_PC2_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
#define DIO_u8_PC3_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
#define DIO_u8_PC4_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
#define DIO_u8_PC5_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
#define DIO_u8_PC6_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
#define DIO_u8_PC7_INTIAL_DIRECTION           DIO_u8_INITIL_OUTPUT
								              
/* PORTD */                         
#define DIO_u8_PD0_INTIAL_DIRECTION         DIO_u8_INITIL_INPUT       // CL1
#define DIO_u8_PD1_INTIAL_DIRECTION         DIO_u8_INITIL_INPUT       // CL2
#define DIO_u8_PD2_INTIAL_DIRECTION         DIO_u8_INITIL_INPUT       // CL3
#define DIO_u8_PD3_INTIAL_DIRECTION         DIO_u8_INITIL_INPUT       // CL4
#define DIO_u8_PD4_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT
#define DIO_u8_PD5_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT     // SERVO
#define DIO_u8_PD6_INTIAL_DIRECTION         DIO_u8_INITIL_INPUT
#define DIO_u8_PD7_INTIAL_DIRECTION         DIO_u8_INITIL_OUTPUT



/*  initial value for all pins */


/*     Options : DIO_u8_OUTPUT_HIGH    
                 DIO_u8_OUTPUT_LOW 
                 DIO_u8_INPUT_FLOATTING
                 DIO_u8_INPUT_PULLUP				  
			 
				 */
				 
				 

/* PORTA */

#define DIO_u8_PA0_INTIAL_VALUE             DIO_u8_OUTPUT_LOW
#define DIO_u8_PA1_INTIAL_VALUE             DIO_u8_OUTPUT_LOW
#define DIO_u8_PA2_INTIAL_VALUE             DIO_u8_OUTPUT_LOW
#define DIO_u8_PA3_INTIAL_VALUE             DIO_u8_OUTPUT_LOW
#define DIO_u8_PA4_INTIAL_VALUE            DIO_u8_INPUT_FLOATTING
#define DIO_u8_PA5_INTIAL_VALUE            DIO_u8_INPUT_FLOATTING
#define DIO_u8_PA6_INTIAL_VALUE             DIO_u8_OUTPUT_LOW
#define DIO_u8_PA7_INTIAL_VALUE             DIO_u8_OUTPUT_LOW
					          
/* PORTB */                                   
#define DIO_u8_PB0_INTIAL_VALUE          DIO_u8_OUTPUT_LOW
#define DIO_u8_PB1_INTIAL_VALUE          DIO_u8_OUTPUT_LOW
#define DIO_u8_PB2_INTIAL_VALUE          DIO_u8_OUTPUT_LOW
#define DIO_u8_PB3_INTIAL_VALUE          DIO_u8_OUTPUT_LOW
#define DIO_u8_PB4_INTIAL_VALUE         DIO_u8_OUTPUT_HIGH
#define DIO_u8_PB5_INTIAL_VALUE         DIO_u8_OUTPUT_HIGH
#define DIO_u8_PB6_INTIAL_VALUE         DIO_u8_OUTPUT_HIGH
#define DIO_u8_PB7_INTIAL_VALUE         DIO_u8_OUTPUT_HIGH
								         
/* PORTC */                                  
#define DIO_u8_PC0_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC1_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC2_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC3_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC4_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC5_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC6_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
#define DIO_u8_PC7_INTIAL_VALUE           DIO_u8_OUTPUT_LOW
								              
/* PORTD */                         
#define DIO_u8_PD0_INTIAL_VALUE        DIO_u8_INPUT_PULLUP
#define DIO_u8_PD1_INTIAL_VALUE        DIO_u8_INPUT_PULLUP
#define DIO_u8_PD2_INTIAL_VALUE        DIO_u8_INPUT_PULLUP
#define DIO_u8_PD3_INTIAL_VALUE        DIO_u8_INPUT_PULLUP
#define DIO_u8_PD4_INTIAL_VALUE        DIO_u8_OUTPUT_LOW
#define DIO_u8_PD5_INTIAL_VALUE        DIO_u8_OUTPUT_LOW
#define DIO_u8_PD6_INTIAL_VALUE       DIO_u8_INPUT_PULLUP
#define DIO_u8_PD7_INTIAL_VALUE        DIO_u8_OUTPUT_LOW






#endif
