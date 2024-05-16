/*
 * port_config.c
 *
 * Created: 12/3/2023 3:35:52 AM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "port_config.h"
#if ((PRECONFIG==DISABLE)&&(POSTCONFIG==ENABLE))

DIO_enumPinConf DIO_Pincfg[]={
	/************************************ PORTA_PINS *********************************************/
	DIO_OUTPUT_LOW,  /* PIN0  */
	DIO_OUTPUT_LOW,  /* PIN1  */
	DIO_OUTPUT_LOW,  /* PIN2  */
	DIO_OUTPUT_LOW,  /* PIN3  */
	DIO_enumInput_PU,  /* PIN4  */
	DIO_enumInput_PU,  /* PIN5  */
	DIO_enumInput_PU,  /* PIN6  */
	DIO_enumInput_PU,  /* PIN7  */
	/************************************ PORTB_PINS *********************************************/
	DIO_enumInput_PU,  /* PIN8  */
	DIO_enumInput_PU,  /* PIN9  */
	DIO_enumInput_PU,  /* PIN10 */
	DIO_enumInput_PU,  /* PIN11 */
	DIO_enumInput_PU,  /* PIN12 */
	DIO_enumInput_PU,  /* PIN13 */
	DIO_enumInput_PU,  /* PIN14 */
	DIO_enumInput_PU,  /* PIN15 */
	/************************************ PORTC_PINS *********************************************/
	DIO_enumInput_PU,  /* PIN16 */
	DIO_enumInput_PU,  /* PIN17 */
	DIO_enumInput_PU,  /* PIN18 */
	DIO_enumInput_PU,  /* PIN19 */
	DIO_enumInput_PU,  /* PIN20 */
	DIO_enumInput_PU,  /* PIN21 */
	DIO_enumInput_PU,  /* PIN22 */
	DIO_enumInput_PU,  /* PIN23 */
	/************************************ PORTD_PINS *********************************************/
	DIO_enumInput_PU,  /* PIN24 */
	DIO_enumInput_PU,  /* PIN25 */
	DIO_enumInput_PU,  /* PIN26 */
	DIO_enumInput_PU,  /* PIN27 */
	DIO_enumInput_PU,  /* PIN28 */
	DIO_enumInput_PU,  /* PIN29 */
	DIO_enumInput_PU,  /* PIN30 */
	DIO_enumInput_PU   /* PIN31 */
	
 };

#endif