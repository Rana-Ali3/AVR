/*
 * SEVEN_SEGMENT_cfg.c
 *
 * Created: 12/17/2023 9:37:30 PM
 *  Author: Rana
 */ 


#include "SEVEN_SEGMENT_cfg.h"
#include "../../MCAL/PORT/port.h"

/******************************** array of SEVEN_SEGMENT structs ********************************/

SEVEN_SEGMENT_StrCFG SEVEN_SEGMENTS[NUM_OF_SEVEN_SEGMENTS]={
	
	/******************* accessing struct that contain configration of SEVEN_SEGMENT ************************/
	/* access port and pin initial state is it ON or OFF of each pin of it and choose whether it is common cathode or common anode */
	
		
		/******************* accessing struct that contain configration of SEVEN_SEGMENT ************************/
		/* access port and pin initial state is it ON or OFF of each pin of it and choose whether it is common cathode or common anode */
		
		[SEVEN_SEGMENT1]={
			/****************************** PIN 0 configuration ****************************************/
			.PIN[0].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[0].SEVEN_SEGMENT_u8Pin=PORT_enumPin0,
			.PIN[0].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 1 configuration ****************************************/
			.PIN[1].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[1].SEVEN_SEGMENT_u8Pin=PORT_enumPin1,
			.PIN[1].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 2 configuration ****************************************/
			.PIN[2].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[2].SEVEN_SEGMENT_u8Pin=PORT_enumPin2,
			.PIN[2].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 3 configuration ****************************************/
			.PIN[3].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[3].SEVEN_SEGMENT_u8Pin=PORT_enumPin3,
			.PIN[3].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 4 configuration ****************************************/
			.PIN[4].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[4].SEVEN_SEGMENT_u8Pin=PORT_enumPin4,
			.PIN[4].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 5 configuration ****************************************/
			.PIN[5].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[5].SEVEN_SEGMENT_u8Pin=PORT_enumPin5,
			.PIN[5].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 6 configuration ****************************************/
			.PIN[6].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[6].SEVEN_SEGMENT_u8Pin=PORT_enumPin6,
			.PIN[6].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 7 configuration ****************************************/
			.PIN[7].SEVEN_SEGMENT_u8Port=PORT_enumPORTA,
			.PIN[7].SEVEN_SEGMENT_u8Pin=PORT_enumPin7,
			.PIN[7].SEVEN_SEGMENT_u8State=OFF,
			
			/****************** Active state is it Common cathode or Common anode ****************/
			.SEVEN_SEGMENT_u8ActiveState=COMMON_CATHODE,
			/******* Common pin is it ground if it is common cathode or vcc if it is common anode ********/
		.SEVEN_SEGMENT_u8CommonPin=GROUND},
		
		[SEVEN_SEGMENT2]={/****************************** PIN 0 configuration ****************************************/
			.PIN[0].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[0].SEVEN_SEGMENT_u8Pin=PORT_enumPin0,
			.PIN[0].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 1 configuration ****************************************/
			.PIN[1].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[1].SEVEN_SEGMENT_u8Pin=PORT_enumPin1,
			.PIN[1].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 2 configuration ****************************************/
			.PIN[2].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[2].SEVEN_SEGMENT_u8Pin=PORT_enumPin2,
			.PIN[2].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 3 configuration ****************************************/
			.PIN[3].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[3].SEVEN_SEGMENT_u8Pin=PORT_enumPin3,
			.PIN[3].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 4 configuration ****************************************/
			.PIN[4].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[4].SEVEN_SEGMENT_u8Pin=PORT_enumPin4,
			.PIN[4].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 5 configuration ****************************************/
			.PIN[5].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[5].SEVEN_SEGMENT_u8Pin=PORT_enumPin5,
			.PIN[5].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 6 configuration ****************************************/
			.PIN[6].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[6].SEVEN_SEGMENT_u8Pin=PORT_enumPin6,
			.PIN[6].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 7 configuration ****************************************/
			.PIN[7].SEVEN_SEGMENT_u8Port=PORT_enumPORTB,
			.PIN[7].SEVEN_SEGMENT_u8Pin=PORT_enumPin7,
			.PIN[7].SEVEN_SEGMENT_u8State=OFF,
			
			/****************** Active state is it Common cathode or Common anode ****************/
			.SEVEN_SEGMENT_u8ActiveState=COMMON_CATHODE,
			/******* Common pin is it ground if it is common cathode or vcc if it is common anode ********/
		.SEVEN_SEGMENT_u8CommonPin=GROUND},
		
		[SEVEN_SEGMENT3]={/****************************** PIN 0 configuration ****************************************/
			.PIN[0].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[0].SEVEN_SEGMENT_u8Pin=PORT_enumPin0,
			.PIN[0].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 1 configuration ****************************************/
			.PIN[1].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[1].SEVEN_SEGMENT_u8Pin=PORT_enumPin1,
			.PIN[1].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 2 configuration ****************************************/
			.PIN[2].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[2].SEVEN_SEGMENT_u8Pin=PORT_enumPin2,
			.PIN[2].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 3 configuration ****************************************/
			.PIN[3].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[3].SEVEN_SEGMENT_u8Pin=PORT_enumPin3,
			.PIN[3].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 4 configuration ****************************************/
			.PIN[4].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[4].SEVEN_SEGMENT_u8Pin=PORT_enumPin4,
			.PIN[4].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 5 configuration ****************************************/
			.PIN[5].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[5].SEVEN_SEGMENT_u8Pin=PORT_enumPin5,
			.PIN[5].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 6 configuration ****************************************/
			.PIN[6].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[6].SEVEN_SEGMENT_u8Pin=PORT_enumPin6,
			.PIN[6].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 7 configuration ****************************************/
			.PIN[7].SEVEN_SEGMENT_u8Port=PORT_enumPORTC,
			.PIN[7].SEVEN_SEGMENT_u8Pin=PORT_enumPin7,
			.PIN[7].SEVEN_SEGMENT_u8State=OFF,
			
			/****************** Active state is it Common cathode or Common anode ****************/
			.SEVEN_SEGMENT_u8ActiveState=COMMON_CATHODE,
			/******* Common pin is it ground if it is common cathode or vcc if it is common anode ********/
		.SEVEN_SEGMENT_u8CommonPin=GROUND},
		
		[SEVEN_SEGMENT4]={/****************************** PIN 0 configuration ****************************************/
			.PIN[0].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[0].SEVEN_SEGMENT_u8Pin=PORT_enumPin0,
			.PIN[0].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 1 configuration ****************************************/
			.PIN[1].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[1].SEVEN_SEGMENT_u8Pin=PORT_enumPin1,
			.PIN[1].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 2 configuration ****************************************/
			.PIN[2].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[2].SEVEN_SEGMENT_u8Pin=PORT_enumPin2,
			.PIN[2].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 3 configuration ****************************************/
			.PIN[3].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[3].SEVEN_SEGMENT_u8Pin=PORT_enumPin3,
			.PIN[3].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 4 configuration ****************************************/
			.PIN[4].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[4].SEVEN_SEGMENT_u8Pin=PORT_enumPin4,
			.PIN[4].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 5 configuration ****************************************/
			.PIN[5].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[5].SEVEN_SEGMENT_u8Pin=PORT_enumPin5,
			.PIN[5].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 6 configuration ****************************************/
			.PIN[6].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[6].SEVEN_SEGMENT_u8Pin=PORT_enumPin6,
			.PIN[6].SEVEN_SEGMENT_u8State=OFF,
			/****************************** PIN 7 configuration ****************************************/
			.PIN[7].SEVEN_SEGMENT_u8Port=PORT_enumPORTD,
			.PIN[7].SEVEN_SEGMENT_u8Pin=PORT_enumPin7,
			.PIN[7].SEVEN_SEGMENT_u8State=OFF,
			
			/****************** Active state is it Common cathode or Common anode ****************/
			.SEVEN_SEGMENT_u8ActiveState=COMMON_CATHODE,
			/******* Common pin is it ground if it is common cathode or vcc if it is common anode ********/
		.SEVEN_SEGMENT_u8CommonPin=GROUND},
		
		
		
	};
	