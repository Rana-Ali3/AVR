/*
 * SEVEN_SEGMENT.c
 *
 * Created: 12/17/2023 9:36:32 PM
 *  Author: Rana
 */ 


#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"
#include "../../MCAL/PORT/port_config.h"

#include "SEVEN_SEGMENT.h"

/******************** extern array of switches which contain switch configration *****************/

extern SEVEN_SEGMENT_StrCFG SEVEN_SEGMENTS[NUM_OF_SEVEN_SEGMENTS];

void Seven_segment_init()
{
	/* loop on number of the seven_segments */
	for(u8 i=0;i<1;i++)
	{
		for(u8 j=0;j<NUM_OF_PIN_PER_7SEGMENT;j++)
		{
			
		
		Portcfg_t CurrSevenSegment[j];
		/**** accessing SEVENSEGMENT through PORT,PIN, and state and mode wehther it is active high or avtive low *****/
		
		CurrSevenSegment[j].PORT_u8port=SEVEN_SEGMENTS[i].PIN[j].SEVEN_SEGMENT_u8Port;
		CurrSevenSegment[j].PORT_u8pin=SEVEN_SEGMENTS[i].PIN[j].SEVEN_SEGMENT_u8Pin;
		/* check if it is active high */
		if(SEVEN_SEGMENTS[i].SEVEN_SEGMENT_u8ActiveState==COMMON_CATHODE)
		{
			/* give seven segment configuration to each pin be as it is chosen ON=high,OFF=low */
			CurrSevenSegment[j].PORT_u8ConfigType=SEVEN_SEGMENTS[i].PIN[j].SEVEN_SEGMENT_u8State;
		}
		else
		{
			/* give seven segment configuration to each pin opposite to be as it is chosen ON=low,OGG=high */
			CurrSevenSegment[j].PORT_u8ConfigType=!(SEVEN_SEGMENTS[i].PIN[j].SEVEN_SEGMENT_u8State);
		}
		/* sending this config to port config function */
		Port_setcfg(&CurrSevenSegment[j]);
		}
		
	}
}
/************** function to choose which seven segment to use and give it  value *******************/
void seven_segment_set_value(SEVEN_SEGMENT_StrCFG *selected_seven_segment,u8 local_u8Value)
{
	Portcfg_t CurrSeven[NUM_OF_PIN_PER_7SEGMENT];
	for(u8 i=0;i<NUM_OF_PIN_PER_7SEGMENT;i++)
	{
		
	CurrSeven[i].PORT_u8port=selected_seven_segment->PIN[i].SEVEN_SEGMENT_u8Port;
	CurrSeven[i].PORT_u8pin=selected_seven_segment->PIN[i].SEVEN_SEGMENT_u8Pin;
	}
	
	/*********** check whether it is mode is COMMON CATHODE OR COMMON ANODE **********************/
	
	if(selected_seven_segment->SEVEN_SEGMENT_u8ActiveState==COMMON_CATHODE)
	{
		/**************** switch on value is it 0 or 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 ********/
		switch(local_u8Value)
		{
			case ZERO:
			
			/*********** if its value is 0 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case ONE:
			
			/*********** if its value is 1 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case TWO:
			
			/*********** if its value is 2 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case THREE:
			
			/*********** if its value is 3 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case FOUR:
			
			/*********** if its value is 4 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case FIVE:
			
			/*********** if its value is 5 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case SIX:
			
			/*********** if its value is 6 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case SEVEN:
			
			/*********** if its value is 7 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case EIGHT:
			
			/*********** if its value is 8 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			case NINE:
			
			/*********** if its value is 9 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=OFF;
			
			break;
			
			
			
			default:
			
			break;
		}
		//selected_seven_segment->PIN->SEVEN_SEGMENT_u8State=local_u8Value;
	}
	//////////////////////////////////////////////////////////
	
	/*********** check whether it is mode is COMMON CATHODE OR COMMON ANODE **********************/
	
	if(selected_seven_segment->SEVEN_SEGMENT_u8ActiveState==COMMON_ANODE)
	{
		/**************** switch on value is it 0 or 1 or 2 or 3 or 4 or 5 or 6 or 7 or 8 or 9 ********/
		switch(local_u8Value)
		{
			case ZERO:
			
			/*********** if its value is 0 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case ONE:
			
			/*********** if its value is 1 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case TWO:
			
			/*********** if its value is 2 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case THREE:
			
			/*********** if its value is 3 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case FOUR:
			
			/*********** if its value is 4 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case FIVE:
			
			/*********** if its value is 5 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case SIX:
			
			/*********** if its value is 6 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case SEVEN:
			
			/*********** if its value is 7 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case EIGHT:
			
			/*********** if its value is 8 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			case NINE:
			
			/*********** if its value is 9 then set the right pins to make zero appear *************/
			selected_seven_segment->PIN[0].SEVEN_SEGMENT_u8State=OFF;
			
			selected_seven_segment->PIN[1].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[2].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[3].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[4].SEVEN_SEGMENT_u8State=ON;
			selected_seven_segment->PIN[5].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[6].SEVEN_SEGMENT_u8State=OFF;
			selected_seven_segment->PIN[7].SEVEN_SEGMENT_u8State=ON;
			
			break;
			
			
			
			default:
			
			break;
		}
	}
	
	/***************** send these values to port drivers **********************/
	for(u8 i=0;i<NUM_OF_PIN_PER_7SEGMENT;i++)
	{
		CurrSeven[i].PORT_u8ConfigType=selected_seven_segment->PIN[i].SEVEN_SEGMENT_u8State;
		Port_setcfg(&CurrSeven[i]);
	}
	
}

/************************** function to write value in seven segments ****************************/
void seven_segment_set_value_only(u32 local_u8Value)
{
	/************** check if value is less than 10 (1 digit) ***********************/
	if(local_u8Value<10)
	{
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT1 and value *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT1],local_u8Value);
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT2],0);
	}
	/************** check if value is less than 100 (2 digit) ***********************/
	if((local_u8Value>=10)&&(local_u8Value<100))
	{
		/************** get the first digit by mod the number with 10 ****************/
		u8 local_u8First;
		local_u8First=local_u8Value%10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT1 and First digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT1],local_u8First);
		/************** get the second digit by divide the number by 10 ****************/
		u8 local_u8Second;
		local_u8Second=local_u8Value/10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT2 and second digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT2],local_u8Second);
		
	}
	/************** check if value is greater than 100 and less than 1000 (3 digit) ***********************/
	if((local_u8Value>=100)&&(local_u8Value<1000))
	{
		/************** get the first digit by mod the number with 10 ****************/
		u8 local_u8First;
		local_u8First=local_u8Value%10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT1 and first digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT1],local_u8First);
		/****** get the second digit by divide the number by 10 then take the result and mod it with 10 *********/
		u8 local_u8Second;
		local_u8Second=(local_u8Value/10)%10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT2 and second digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT2],local_u8Second);
		/************** get the third digit by divide the number by 100 ****************/
		u8 local_u8Third;
		local_u8Third=local_u8Value/100;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT3 and third digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT3],local_u8Third);
		
	}
	/************** check if value is greater than 1000 and less than 10000 (4 digit) ***********************/
	if((local_u8Value>=1000)&&(local_u8Value<100000))
	{
		/************** get the first digit by mod the number with 10 ****************/
		u8 local_u8First;
		local_u8First=local_u8Value%10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT1 and first digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT1],local_u8First);
		/****** get the second digit by divide the number by 10 then take the result and mod it with 10 *********/
		u8 local_u8Second;
		local_u8Second=(local_u8Value/10)%10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT2 and second digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT2],local_u8Second);
		/************** get the third digit by divide the number by 100 then mod it with 10 ****************/
		u8 local_u8Third;
		local_u8Third=(local_u8Value/100)%10;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT3 and third digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT3],local_u8Third);
		/************** get the fourth digit by divide the number by 1000  ****************/
		u8 local_u8Fourth;
		local_u8Fourth=local_u8Value/1000;
		/********* use seven_segment_set_value function and its parameter is SEVEN_SEGMENT4 and fourth digit *******/
		seven_segment_set_value(&SEVEN_SEGMENTS[SEVEN_SEGMENT4],local_u8Fourth);
		
	}
	
	
	
	
	
}