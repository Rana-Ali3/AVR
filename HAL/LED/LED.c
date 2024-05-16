/*
 * LED.c
 *
 * Created: 12/9/2023 4:21:19 PM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"
#include "../../MCAL/PORT/port_config.h"

#include "LED.h"
/******************** extern array of switches which contain switch configration *****************/

extern LED_StrCFG LEDS[NUM_OF_LEDS];

/*********************** Function to init LED ************************************/
void LED_init()
{
	/* loop on number of the switches */
	for(u8 i=0;i<NUM_OF_LEDS;i++)
	{
		Portcfg_t CurrLed;
		/**** accessing LED through PORT,PIN, and state and mode wehther it is active high or avtive low *****/
		
		CurrLed.PORT_u8port=LEDS[i].LED_u8Port;
		CurrLed.PORT_u8pin=LEDS[i].LED_u8Pin;
		/* check if it is active high */
		if(LEDS[i].LED_u8ActiveState==ACTIVE_HIGH)
		{
		/* give led configration to be as it is chosen high=high,low=low */	
		CurrLed.PORT_u8ConfigType=LEDS[i].LED_u8State;
		}
		else
		{
		/* give led configration  oppisite to be as it is chosen high=low,low=high */
		CurrLed.PORT_u8ConfigType=!LEDS[i].LED_u8State;
		}
		/* sending this config to port config function */
		Port_setcfg(&CurrLed);
		
	}
	
}
/************* function to make led on *********************/

void LED_ON(LED_StrCFG* ledOn)
{
	
	Portcfg_t cur_led;
	/* assign led port and pin to struct refer to port driver */
	cur_led.PORT_u8port=ledOn->LED_u8Port;
	cur_led.PORT_u8pin=ledOn->LED_u8Pin;
	/* check if mode of led is active high */
	if(ledOn->LED_u8ActiveState==ACTIVE_HIGH)
	{
		/* then make the led state to be on */
		ledOn->LED_u8State=ON;
		
	}
	else
	{
		/* else make it OFF */
		ledOn->LED_u8State=OFF;
	}
	/* assign the state to struct of led which refer to port driver */ 
	cur_led.PORT_u8ConfigType=ledOn->LED_u8State;
	Port_setcfg(&cur_led);
}

/************* function to make led off *********************/

void LED_OFF(LED_StrCFG* ledOff)
{
	
	Portcfg_t cur_led;
	
	/* assign led port and pin to struct refer to port driver */
	cur_led.PORT_u8port=ledOff->LED_u8Port;
	cur_led.PORT_u8pin=ledOff->LED_u8Pin;
	/* check if mode of led is active high */
	if(ledOff->LED_u8ActiveState==ACTIVE_HIGH)
	{
		/* then make the led state to be off */
		ledOff->LED_u8State=OFF;
		
	}
	else
	{
		/* else make it ON */
		ledOff->LED_u8State=ON;
	}
	/* assign the state to struct of led which refer to port driver */ 
	cur_led.PORT_u8ConfigType=ledOff->LED_u8State;
	Port_setcfg(&cur_led);
}


