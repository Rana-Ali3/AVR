/*
 * SWITCH.c
 *
 * Created: 12/12/2023 4:01:40 AM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"
#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/PORT/port_config.h"

#include "SWITCH.h"

/******************** extern array of switches which contain switch configration *****************/

extern SWITCH_StrCFG SWITCHES[NUM_OF_SWITCHES];

/***************** function to init switches ***************************************/

void SWITCH_init()
{
   /* loop on number of the switches */
  for(u8 i=0;i<NUM_OF_SWITCHES;i++)
  {
	  Portcfg_t CurrSwitch;
	  /* accessing switch through port config through port and pin and state and mode is it active high or low */
	  CurrSwitch.PORT_u8port=SWITCHES[i].SWITCH_u8Port;  
	  CurrSwitch.PORT_u8pin=SWITCHES[i].SWITCH_u8Pin;
	  CurrSwitch.PORT_u8ConfigType=SWITCHES[i].SWITCH_u8ActiveState;
	  SWITCHES[i].SWITCH_u8State=NOT_PRESSED;
	  /* sending this config to port config function */
	Port_setcfg(&CurrSwitch);
  }
  
  
 }
 /*********************************** function to get the value applied on the switch *******************************************/
 void ispressed(SWITCH_StrCFG* pressd_switch)
 {
	 
	 u8 SWITCH_u8pressed;
	 
	 /******************************** Read state of pin of the swutch *****************************************************/
	 /* send port and pin and state */
	 DIO_enumReadStateOfPort(pressd_switch->SWITCH_u8Port,pressd_switch->SWITCH_u8Pin,&pressd_switch->SWITCH_u8State);
	 
	 
	 /**************************************** another sol ***************************************************/
	 /*switch(pressd_switch->SWITCH_u8Port)
	 {
		 case PORT_enumPORTA:
		 pressd_switch->SWITCH_u8State=GET_BIT(PINA_REG,pressd_switch->SWITCH_u8Pin);
		 break;
		 
		 case PORT_enumPORTB:
		 pressd_switch->SWITCH_u8State=GET_BIT(PINB_REG,pressd_switch->SWITCH_u8Pin);
		 break;
		 
		 case PORT_enumPORTC:
		 pressd_switch->SWITCH_u8State=GET_BIT(PINC_REG,pressd_switch->SWITCH_u8Pin);
		 break;
		 
		 case PORT_enumPORTD:
		 pressd_switch->SWITCH_u8State=GET_BIT(PIND_REG,pressd_switch->SWITCH_u8Pin);
		 break;
		 
		 default:
		 
		 break;
		 
	 }*/
	
	 
 }