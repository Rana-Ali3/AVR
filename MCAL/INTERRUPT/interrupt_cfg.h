/*
 * interrupt_cfg.h
 *
 * Created: 1/2/2024 12:12:38 PM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../PORT/port.h"
//#include "interrupt.h"

#ifndef INTERRUPT_cfg_H_

#define ENABLE  1
#define DISABLE 0
/*********** choose which interrupt do you want to enable or disable **************/
#define INT0  ENABLE
#define INT1  ENABLE
#define INT2  DISABLE

/***************** Activation mode of external interupt 0,1 *****************************/
#define INT_LOW             0
#define INT_CHANGE_LEVEL    1
#define INT_FALLING_EDGE    2
#define INT_RISING_EDGE     3

/***************** Activation mode of external interrupt 2  *****************************/
#define INT2_FALLING_EDGE    0
#define INT2_RISINGING_EDGE  1

/* choose interrupt 0 mode*/
#define INT0_MODE  INT_FALLING_EDGE
/* choose interrupt 1 mode*/
#define INT1_MODE  INT_FALLING_EDGE
/* choose interrupt 2 mode*/
#define INT2_MODE  INT2_FALLING_EDGE


#define PULL_UP     2
#define PULL_DOWN   3

#define INT0_ACTIVE PULL_UP
#define INT1_ACTIVE PULL_UP
#define INT2_ACTIVE PULL_UP


#endif