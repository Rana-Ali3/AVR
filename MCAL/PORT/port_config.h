#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

#define INPUT_PU	         0
#define INPUT_PD		     1
#define OUTPUT_HIGH		     2
#define OUTPUT_LOW		     3


#define NUM_OF_PORT          4

#define NUM_OF_PIN_PER_PORT  8

#define DISABLE		         0
#define ENABLE			     1

/****************************** Choosing the mode  you want enable andthe other ***************/
#define PRECONFIG      DISABLE
#define POSTCONFIG     ENABLE
// ro comment
/*#define CONFIG_TYPE  PRECONFIG

#if CONFIG_TYPE == PRECONFIG



#endif*/
/************************** PORT A configration ********************************/
#define DIO_PIN0_CONFIG    OUTPUT_LOW
#define DIO_PIN1_CONFIG    OUTPUT_LOW
#define DIO_PIN2_CONFIG    OUTPUT_LOW
#define DIO_PIN3_CONFIG    OUTPUT_LOW
#define DIO_PIN4_CONFIG    INPUT_PU
#define DIO_PIN5_CONFIG    INPUT_PU
#define DIO_PIN6_CONFIG    INPUT_PU
#define DIO_PIN7_CONFIG    INPUT_PU

/************************** PORT B configration ********************************/
#define DIO_PIN8_CONFIG    INPUT_PU
#define DIO_PIN9_CONFIG    INPUT_PU
#define DIO_PIN10_CONFIG   INPUT_PU
#define DIO_PIN11_CONFIG   INPUT_PU
#define DIO_PIN12_CONFIG   INPUT_PU
#define DIO_PIN13_CONFIG   INPUT_PU
#define DIO_PIN14_CONFIG   INPUT_PU
#define DIO_PIN15_CONFIG   INPUT_PU

/************************** PORT C configration ********************************/
#define DIO_PIN16_CONFIG   INPUT_PU
#define DIO_PIN17_CONFIG   INPUT_PU
#define DIO_PIN18_CONFIG   INPUT_PU
#define DIO_PIN19_CONFIG   INPUT_PU
#define DIO_PIN20_CONFIG   INPUT_PU
#define DIO_PIN21_CONFIG   INPUT_PU
#define DIO_PIN22_CONFIG   INPUT_PU
#define DIO_PIN23_CONFIG   INPUT_PU

/************************** PORT D configration ********************************/
#define DIO_PIN24_CONFIG   INPUT_PU
#define DIO_PIN25_CONFIG   INPUT_PU
#define DIO_PIN26_CONFIG   INPUT_PU
#define DIO_PIN27_CONFIG   INPUT_PU
#define DIO_PIN28_CONFIG   INPUT_PU
#define DIO_PIN29_CONFIG   INPUT_PU
#define DIO_PIN30_CONFIG   INPUT_PU
#define DIO_PIN31_CONFIG   INPUT_PU

/*********************** POSTCONFIGRATION *************************************/

#if ((PRECONFIG==DISABLE)&&(POSTCONFIG==ENABLE))

typedef enum{
	DIO_enumInput_PU,
	DIO_enumInput_PD,
	DIO_OUTPUT_HIGH,
	DIO_OUTPUT_LOW
}DIO_enumPinConf;

#endif


#endif