#ifndef KP_CONFIG_H
#define KP_CONFIG_H

#define KPD_PORT_row  PORTB
#define KPD_PORT_col  PORTD

/*
select DATA port :
PORTA
PORTB
PORTC
PORTD
 
*/

#define KPD_CL1_PIN   PIN_0
#define KPD_CL2_PIN   PIN_1
#define KPD_CL3_PIN   PIN_2
#define KPD_CL4_PIN   PIN_3

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


#define KPD_RL1_PIN   PIN_4
#define KPD_RL2_PIN   PIN_5
#define KPD_RL3_PIN   PIN_6
#define KPD_RL4_PIN   PIN_7

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

#define  KPD_Keys   { {'1','2','3','#'}, \
	                  {'5','6','7','8'},  \
                      {'9','+','4','*'},  \
					 {'0','-','*','/'}}



#endif 
