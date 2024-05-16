#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "port_config.h"

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#include "../PRIVATE.h"




typedef enum{
 PORT_enumPORTA,         
 PORT_enumPORTB,         
 PORT_enumPORTC,         
 PORT_enumPORTD         
}Ports;


/************************* New approach for port driver **************************/

typedef enum
{
	PORT_enumPin0,
	PORT_enumPin1,
	PORT_enumPin2,
	PORT_enumPin3,
	PORT_enumPin4,
	PORT_enumPin5,
	PORT_enumPin6,
	PORT_enumPin7
}PORT_enumPins_t;



typedef enum 
{
	/**
	 *@brief : Everything Ok, Function had Performed Correctly.
	 */
	PORT_enumOk,             
	/**
	 *@brief : NULL Pointer is passed.
	 */
	PORT_enumNullPointer,
	/**
	 *@brief : Select Port Not exist ! .
	 */    
	PORT_enumWrongPort,      
	/**
	 *@brief : Select Pin Not exist ! .
	 */
	PORT_enumWrongPin, 
	/**
	 *@brief : Select Configuration type Not Found .
	 */     
	PORT_enumWrongConfig,
	
	PORT_enumNok    
	
}PORT_enumError_t;

typedef enum
{	
	/**
	 *@brief : Select Pin Configuration to be Output high .
	 */
	PORT_enumOutputLow,
	
	/**
	 *@brief : Select Pin Configuration to be Output low .
	 */
	PORT_enumOutputHigh,
	/**
	 *@brief : Select Pin Configuration to be Input Internal PullUp .
	 */             
	PORT_enumInputInternalPullUp,
	/**
	 *@brief : Select Pin Configuration to be Input External PullDown
	 */    
	PORT_enumInputExternalPullDown   
}PORT_enumConfig_t;

typedef struct
{
	Ports PORT_u8port;
	PORT_enumPins_t PORT_u8pin;
	PORT_enumConfig_t PORT_u8ConfigType;
	
}Portcfg_t;


/********* Function to set configiration of the pins ************/
PORT_enumError_t Port_setcfg(Portcfg_t *AddPortConfig);



/*******************************************************************************/
/*
#define DIO_u8PIN0         0
#define DIO_u8PIN1         1
#define DIO_u8PIN2         2
#define DIO_u8PIN3         3
#define DIO_u8PIN4         4
#define DIO_u8PIN5         5
#define DIO_u8PIN6         6
#define DIO_u8PIN7         7
*/

#define PORT_u8INPUT          0
#define PORT_u8OUTPUT         1

#define PORT_u8LOW            0
#define PORT_u8HIGH           1




void PORT_vidInit(void);





/*#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)           0b##b7##b6##b5##b4##b3##b2##b1##b0*/


#endif