/*
 * SWUTCH_cfg.c
 *
 * Created: 12/12/2023 4:02:03 AM
 *  Author: Rana
 */ 

#include "SWITCH_cfg.h"
#include "../../MCAL/PORT/port.h"


 /******************************** array of switches structs ********************************/

SWITCH_StrCFG SWITCHES[NUM_OF_SWITCHES]={
	
	/******************* accessing struct that contain configration of switch ************************/
	/* access port and pin and choose whether it is PULL UP or PULL DOWN and initial state is it pressed or not */
	
	[SWITCH1]={.SWITCH_u8Port=PORT_enumPORTC,
		.SWITCH_u8Pin=PORT_enumPin0,
		.SWITCH_u8ActiveState=PULL_UP,
	.SWITCH_u8State=NOT_PRESSED},
	
	[SWITCH2]={.SWITCH_u8Port=PORT_enumPORTC,
		.SWITCH_u8Pin=PORT_enumPin1,
		.SWITCH_u8ActiveState=PULL_UP,
	.SWITCH_u8State=NOT_PRESSED},	
	
	[SWITCH3]={.SWITCH_u8Port=PORT_enumPORTC,
		.SWITCH_u8Pin=PORT_enumPin2,
		.SWITCH_u8ActiveState=PULL_UP,
	.SWITCH_u8State=NOT_PRESSED},
	
};
