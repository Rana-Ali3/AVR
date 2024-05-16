#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"

#ifndef SEVEN_SEGMENT_cfg_H_

#define NUM_OF_SEVEN_SEGMENTS   4

/********************* 7 SEGMENTS LIST ************************/

#define SEVEN_SEGMENT1   0
#define SEVEN_SEGMENT2   1
#define SEVEN_SEGMENT3   2
#define SEVEN_SEGMENT4   3

/************ struct to implement pin configuration of 7 segment *************/
typedef struct
{
	u8 SEVEN_SEGMENT_u8Port;
	u8 SEVEN_SEGMENT_u8Pin;
	//u8 SEVEN_SEGMENT_u8ActiveState;
	u8 SEVEN_SEGMENT_u8State;
	
}SEVEN_SEGMENT_PIN_StrCFG;

# define NUM_OF_PIN_PER_7SEGMENT  8


/************** struct to store SEVEN_SEGMENT configration ***********/
typedef struct
{
	SEVEN_SEGMENT_PIN_StrCFG PIN[NUM_OF_PIN_PER_7SEGMENT];
	u8 SEVEN_SEGMENT_u8ActiveState;
	u8 SEVEN_SEGMENT_u8CommonPin;
	
}SEVEN_SEGMENT_StrCFG;

/********************* configure SEVEN_SEGMENT mode common cathode or common anode *****************************/
#define COMMON_CATHODE  1
#define COMMON_ANODE    0

/********************* configure SEVEN_SEGMENT of each pin state on(high) or off(low) *****************************/
#define ON   1
#define OFF  0

/********************* Common cathode pin (ground) and common anode pin (vcc) ***********************************/
#define GROUND 0
#define VCC    5

#endif