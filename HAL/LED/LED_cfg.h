#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"

#ifndef LED_cfg_H_

#define NUM_OF_LEDS   4
 /********************* LED LIST ************************/
 
 #define LED1   0
 #define LED2   1
 #define LED3   2
 #define LED4   3
 
 /************** struct to store LED configration ***********/
 typedef struct  
 {
	 u8 LED_u8Port;
	 u8 LED_u8Pin;
	 u8 LED_u8ActiveState;
	 u8 LED_u8State;
	 
 }LED_StrCFG;
 /********************* configure led state on(high) or off(low) *****************************/
 #define ON 1
 #define OFF  0
 
 /********************* configure led mode active high or active low *****************************/
 #define ACTIVE_HIGH  1
 #define ACTIVE_LOW   0
 


#endif