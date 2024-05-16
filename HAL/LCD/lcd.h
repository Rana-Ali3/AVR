
/*
 * lcd.h
 *
 * Created: 1/7/2024 6:10:48 PM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/dio.h"


#include "LCD_cfg.h"

#ifndef LCD_H_
/************************** enum to vreprasent errors ************************************/
typedef enum
{
	LCD_enumOK,
	LCD_enumNok
}LCD_enuErrorStatus;


/********************* first line on LCD 0 and second line is 1 **************************************/
#define FIRST_LINE  0
#define SECOND_LINE 1



/**************************** function to initilize LCD configuration **********************/
void LCD_config_init();
/**************************** function to initilize LCD **********************************/
void LCD_init();
/**************************** function to write data on LCD ******************************/
LCD_enuErrorStatus LCD_enuWriteData(u8 Copy_u8Data);
/*************************** function to write command on LCD ***************************/
LCD_enuErrorStatus LCD_enuWriteCommand(u8 Copy_u8Command);
/************************** function to go to specific location on LCD ******************/
/*  it take input Copy_u8X is FIRST_LINE or SECOND_LINE */
/*  it take input Copy_u8Y from 4 to 19 */
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y);
/************************** function to write number on LCD ****************************/
LCD_enuErrorStatus LCD_enuWriteNumber(u8 Copy_u8Number);
/************************* function to write string on LCD ****************************/
LCD_enuErrorStatus LCD_enuWriteString(char* Copy_pchPattern, u8 Copy_u8Length,u8 Copy_u8X,u8 Copy_u8Y);
/************************* function to write spicial characters on LCD ****************/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y);


#endif