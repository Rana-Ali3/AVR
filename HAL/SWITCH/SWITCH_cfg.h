#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"

#ifndef SWITCH_cfg_H_

#define NUM_OF_SWITCHES   3
/********************* SWITCHES LIST ************************/
#define SWITCH1   0
#define SWITCH2   1
#define SWITCH3   2

/************** struct to store switch configration ***********/

typedef struct
{
	u8 SWITCH_u8Port;
	u8 SWITCH_u8Pin;
	u8 SWITCH_u8ActiveState;
	u8 SWITCH_u8State;
	
}SWITCH_StrCFG;

/********************* configure SWITCH *****************************/

#define PRESSED      0
#define NOT_PRESSED  1

#define PULL_UP     2
#define PULL_DOWN   3

#endif