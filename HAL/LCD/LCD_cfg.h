
/*
 * lcd_config.h
 *
 * Created: 1/7/2024 6:12:00 PM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"

#ifndef LCD_cfg_H_

/************ struct to implement pin configuration of LCD *************/
typedef struct
{
	u8 LCD_u8Port;
	u8 LCD_u8Pin;
	u8 LCD_u8State;
	
}LCD_PIN_StrCFG;

# define NUM_OF_PIN_PER_LCD  8

/************** struct to store LCD configration ***********/
typedef struct
{
	LCD_PIN_StrCFG PIN[NUM_OF_PIN_PER_LCD];
	LCD_PIN_StrCFG RS_PIN;
	LCD_PIN_StrCFG RW_PIN;
	LCD_PIN_StrCFG ENABLE_PIN;
	/*u8 LCD_u8ActiveState;
	u8 LCD_u8CommonPin;*/
	
}LCD_StrCFG;


/********************* configure state of each pin of data on LCD *****************************/
#define HIGH   1
#define LOW  0

/********************* configure LCD of each pin state on(high) or off(low) *****************************/
#define ON   1
#define OFF  0

/********************* configure LCD mode common cathode or common anode *****************************/
#define COMMON_CATHODE  1
#define COMMON_ANODE    0

/********************* Common cathode pin (ground) and common anode pin (vcc) ***********************************/
#define GROUND 0
#define VCC    5
/********************* first line on LCD 0 and second line is 1 **************************************/
#define FIRST_LINE  0
#define SECOND_LINE 1
/********************* where LCD line start ************************************/
#define START_OF_LCD_LINE 0

/*********************** where second line start **********************/
#define SECOND_LINE_IN_LCD_ADDRESS 64
/*********************** where DDRAM address start **********************/
#define DDRAM_address_start 128

#define UBBER_BIT_FOR_NUM 0x30

#endif