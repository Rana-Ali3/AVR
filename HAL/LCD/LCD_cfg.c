
/*
 * lcd_config.c
 *
 * Created: 1/7/2024 6:12:18 PM
 *  Author: Rana
 */ 

#include "LCD_cfg.h"
#include "../../MCAL/PORT/port.h"

LCD_StrCFG LCD={
	
	/******************* accessing struct that contain configration of LCD ************************/
	/* access port and pin initial state is it ON or OFF of each pin of it and choose whether it is common cathode or common anode */
		/****************************** PIN 0 configuration ****************************************/
		.PIN[0].LCD_u8Port=PORT_enumPORTA,
		.PIN[0].LCD_u8Pin=PORT_enumPin0,
		.PIN[0].LCD_u8State=OFF,
		/****************************** PIN 1 configuration ****************************************/
		.PIN[1].LCD_u8Port=PORT_enumPORTA,
		.PIN[1].LCD_u8Pin=PORT_enumPin1,
		.PIN[1].LCD_u8State=OFF,
		/****************************** PIN 2 configuration ****************************************/
		.PIN[2].LCD_u8Port=PORT_enumPORTA,
		.PIN[2].LCD_u8Pin=PORT_enumPin2,
		.PIN[2].LCD_u8State=OFF,
		/****************************** PIN 3 configuration ****************************************/
		.PIN[3].LCD_u8Port=PORT_enumPORTA,
		.PIN[3].LCD_u8Pin=PORT_enumPin3,
		.PIN[3].LCD_u8State=OFF,
		/****************************** PIN 4 configuration ****************************************/
		.PIN[4].LCD_u8Port=PORT_enumPORTA,
		.PIN[4].LCD_u8Pin=PORT_enumPin4,
		.PIN[4].LCD_u8State=OFF,
		/****************************** PIN 5 configuration ****************************************/
		.PIN[5].LCD_u8Port=PORT_enumPORTA,
		.PIN[5].LCD_u8Pin=PORT_enumPin5,
		.PIN[5].LCD_u8State=OFF,
		/****************************** PIN 6 configuration ****************************************/
		.PIN[6].LCD_u8Port=PORT_enumPORTA,
		.PIN[6].LCD_u8Pin=PORT_enumPin6,
		.PIN[6].LCD_u8State=OFF,
		/****************************** PIN 7 configuration ****************************************/
		.PIN[7].LCD_u8Port=PORT_enumPORTA,
		.PIN[7].LCD_u8Pin=PORT_enumPin7,
		.PIN[7].LCD_u8State=OFF,
		
		/****************************** RS configuration ****************************************/
		.RS_PIN.LCD_u8Port=PORT_enumPORTB,
		.RS_PIN.LCD_u8Pin=PORT_enumPin0,
		.RS_PIN.LCD_u8State=OFF,
		
		/****************************** RW configuration ****************************************/
		.RW_PIN.LCD_u8Port=PORT_enumPORTB,
		.RW_PIN.LCD_u8Pin=PORT_enumPin1,
		.RW_PIN.LCD_u8State=OFF,
		
		/****************************** Enable configuration ****************************************/
		.ENABLE_PIN.LCD_u8Port=PORT_enumPORTB,
		.ENABLE_PIN.LCD_u8Pin=PORT_enumPin2,
		.ENABLE_PIN.LCD_u8State=OFF,
		
		
		};