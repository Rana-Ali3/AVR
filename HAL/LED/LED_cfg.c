/*
 * LED_cfg.c
 *
 * Created: 12/9/2023 4:20:54 PM
 *  Author: Rana
 */ 

#include "LED_cfg.h"
#include "../../MCAL/PORT/port.h"


/******************************** array of LED structs ********************************/

LED_StrCFG LEDS[NUM_OF_LEDS]={
	
	/******************* accessing struct that contain configration of LED ************************/
	/* access port and pin and choose whether it is active high or active low and initial state is it ON or OFF */
	
	[LED1]={.LED_u8Port=PORT_enumPORTA,
	        .LED_u8Pin=PORT_enumPin0,
			.LED_u8ActiveState=ACTIVE_HIGH,
			.LED_u8State=OFF},
			
	[LED2]={.LED_u8Port=PORT_enumPORTA,
			.LED_u8Pin=PORT_enumPin1,
			.LED_u8ActiveState=ACTIVE_HIGH,
			.LED_u8State=OFF},
			
	[LED3]={.LED_u8Port=PORT_enumPORTA,
			.LED_u8Pin=PORT_enumPin2,
			.LED_u8ActiveState=ACTIVE_HIGH,
			.LED_u8State=OFF},
			
	[LED4]={.LED_u8Port=PORT_enumPORTA,
			.LED_u8Pin=PORT_enumPin3,
			.LED_u8ActiveState=ACTIVE_HIGH,
			.LED_u8State=OFF},
			
			
			
	};
