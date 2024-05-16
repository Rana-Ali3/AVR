
/*
 * lcd.c
 *
 * Created: 1/7/2024 6:11:08 PM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include<util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/PORT/port.h"
#include "../../MCAL/PORT/port_config.h"

#include "LCD.h"

extern LCD_StrCFG LCD;
void LCD_config_init()
{
		for(u8 j=0;j<NUM_OF_PIN_PER_LCD;j++)
		{
			
			
			Portcfg_t CurrLCD[j];
			/**** accessing LCD through PORT,PIN, and state and mode wehther it is active high or avtive low *****/
			
			CurrLCD[j].PORT_u8port=LCD.PIN[j].LCD_u8Port;
			CurrLCD[j].PORT_u8pin=LCD.PIN[j].LCD_u8Pin;
			/* check if it is active high */
			
				CurrLCD[j].PORT_u8ConfigType=LCD.PIN[j].LCD_u8State;
			
			/* sending this config to port config function */
			Port_setcfg(&CurrLCD[j]);
		}
		Portcfg_t CurrLCD_RS;
		CurrLCD_RS.PORT_u8port=LCD.RS_PIN.LCD_u8Port;
		CurrLCD_RS.PORT_u8pin=LCD.RS_PIN.LCD_u8Pin;
		CurrLCD_RS.PORT_u8ConfigType=LCD.RS_PIN.LCD_u8State;
		Port_setcfg(&CurrLCD_RS);
		
		Portcfg_t CurrLCD_RW;
		CurrLCD_RW.PORT_u8port=LCD.RW_PIN.LCD_u8Port;
		CurrLCD_RW.PORT_u8pin=LCD.RW_PIN.LCD_u8Pin;
		CurrLCD_RW.PORT_u8ConfigType=LCD.RW_PIN.LCD_u8State;
		Port_setcfg(&CurrLCD_RW);
		
		Portcfg_t CurrLCD_ENABLE;
		CurrLCD_ENABLE.PORT_u8port=LCD.ENABLE_PIN.LCD_u8Port;
		CurrLCD_ENABLE.PORT_u8pin=LCD.ENABLE_PIN.LCD_u8Pin;
		CurrLCD_ENABLE.PORT_u8ConfigType=LCD.ENABLE_PIN.LCD_u8State;
		Port_setcfg(&CurrLCD_ENABLE);
	
}

/**************** init LCD **********************/
void LCD_init()
{
	_delay_ms(35);
	LCD_enuWriteCommand(0b00111000);
	_delay_ms(40);
	LCD_enuWriteCommand(0b00001100);
	_delay_ms(40);
	LCD_enuWriteCommand(0b00000001);
	_delay_ms(3);
	//LCD_enuWriteCommand(0b00001110);
	//LCD_enuWriteCommand(0b00000111);
}


LCD_enuErrorStatus LCD_enuWriteCommand(u8 Copy_u8Command)
{
	LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumOK;
	if(Copy_u8Command>0X40)
	{
		Ret_enumErrorStatus=LCD_enumNok;
	}
	else
	{
		Ret_enumErrorStatus=LCD_enumOK;
	}
	/********************* make RS=0 ***************************************/
	 DIO_enumSetPin(LCD.RS_PIN.LCD_u8Port,LCD.RS_PIN.LCD_u8Pin,LOW);
	/********************* make RW=0 ***************************************/
	 DIO_enumSetPin(LCD.RW_PIN.LCD_u8Port,LCD.RW_PIN.LCD_u8Pin,LOW);
	/********************* pass command to data pins ***********************/
	 u8 i=0;
	 for(i=0;i<NUM_OF_PIN_PER_LCD;i++)
	 {
		 /**************** pass data bit by bit ****************************/
		 if((Copy_u8Command>>i)&1==1)
		 {
			 /***************** if bit[i]==1 then pass high****************/
			 DIO_enumSetPin(LCD.PIN[i].LCD_u8Port,LCD.PIN[i].LCD_u8Pin,HIGH);
		 }
		 else
		 {
			 /*********** else if it is =0 then pass low ****************/
			 DIO_enumSetPin(LCD.PIN[i].LCD_u8Port,LCD.PIN[i].LCD_u8Pin,LOW);
		 }
	 }
	 
	 /********************* Trigger enable ***************************************/
	 DIO_enumSetPin(LCD.ENABLE_PIN.LCD_u8Port,LCD.ENABLE_PIN.LCD_u8Pin,HIGH);
	 _delay_ms(2);
	 DIO_enumSetPin(LCD.ENABLE_PIN.LCD_u8Port,LCD.ENABLE_PIN.LCD_u8Pin,LOW);
	  _delay_ms(2);
	 return Ret_enumErrorStatus;
	
}



/************************** function to go to specific location on LCD ******************/
LCD_enuErrorStatus LCD_enuGotoDDRAM_XY(u8 Copy_u8X, u8 Copy_u8Y)
{
	LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumOK;
	
	if(Copy_u8X>SECOND_LINE)
	{
		LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumNok;
	}
	if(Copy_u8Y>15)
	{
		LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumNok;
	}
	else
	{
		LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumOK;
	}
	u8 local_u8loc;
	/****** check whether we are in first line or second line *********/
	if(Copy_u8X==FIRST_LINE)
	{
		/******** if we are in first line then be in the Y location *******/
		local_u8loc=Copy_u8Y+START_OF_LCD_LINE;
	}
	else if(Copy_u8X==SECOND_LINE)
	{
		/******** if we are in second line then add 0x40 to Y location to be in the right place in DDRAM*******/
		local_u8loc=Copy_u8Y+SECOND_LINE_IN_LCD_ADDRESS+START_OF_LCD_LINE;//0x40
	}
	
	LCD_enuWriteCommand(local_u8loc+DDRAM_address_start);
	return Ret_enumErrorStatus;
}

LCD_enuErrorStatus LCD_enuWriteData(u8 Copy_u8Data)
{	
	LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumOK;
	
	/********************* make RS=1 ***************************************/
	DIO_enumSetPin(LCD.RS_PIN.LCD_u8Port,LCD.RS_PIN.LCD_u8Pin,HIGH);
	/********************* make RW=0 ***************************************/
	DIO_enumSetPin(LCD.RW_PIN.LCD_u8Port,LCD.RW_PIN.LCD_u8Pin,LOW);
	/********************* pass command to data pins ***********************/
	u8 i=0;
	for(i=0;i<NUM_OF_PIN_PER_LCD;i++)
	{
		/**************** pass data bit by bit ****************************/
		if((Copy_u8Data>>i)&1==1)
		{
			/***************** if bit[i]==1 then pass high****************/
			DIO_enumSetPin(LCD.PIN[i].LCD_u8Port,LCD.PIN[i].LCD_u8Pin,HIGH);
		}
		else
		{
			/*********** else if it is =0 then pass low ****************/
			DIO_enumSetPin(LCD.PIN[i].LCD_u8Port,LCD.PIN[i].LCD_u8Pin,LOW);
		}
	}
	
	/********************* Trigger enable ***************************************/
	DIO_enumSetPin(LCD.ENABLE_PIN.LCD_u8Port,LCD.ENABLE_PIN.LCD_u8Pin,HIGH);
	_delay_ms(2);
	DIO_enumSetPin(LCD.ENABLE_PIN.LCD_u8Port,LCD.ENABLE_PIN.LCD_u8Pin,LOW);
	_delay_ms(2);
	return Ret_enumErrorStatus;
}

/************************* function to write string on LCD ****************************/
LCD_enuErrorStatus LCD_enuWriteString(char* Copy_pchPattern, u8 Copy_u8Length,u8 Copy_u8X,u8 Copy_u8Y)
{
	LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumOK;
	
	LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
	for(u8 i=0;i<Copy_u8Length;i++)
	{
		LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
		LCD_enuWriteData(Copy_pchPattern[i]);
		Copy_u8Y=Copy_u8Y+1;
		LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
	}
	return Ret_enumErrorStatus;
}


/************************** function to write number on LCD ****************************/
LCD_enuErrorStatus LCD_enuWriteNumber(u8 Copy_u8Number)
{
	
   LCD_enuErrorStatus Ret_enumErrorStatus=LCD_enumOK;
   if(Copy_u8Number>255)
   {
	   Ret_enumErrorStatus=LCD_enumNok;
   }
   else
   {
	    Ret_enumErrorStatus=LCD_enumOK;
   }
   /*********** check if number less than 10 ************/
   if(Copy_u8Number<10)
   {
	   /* then add UBBER_BIT_FOR_NUM in LCD table of CGROM to my number */
	   u8 loc_u8Num=UBBER_BIT_FOR_NUM+Copy_u8Number;
	   /* then send it to LCD_enuWriteData with its  right address*/
	   LCD_enuWriteData(loc_u8Num);
   }
   /* if it is greater than 10*/
   if((Copy_u8Number>10)&&(Copy_u8Number<256))
   {
	   /* then take second bit of the number through divide it by 10 */
	   u8 loc_u8Num1=Copy_u8Number/10;
	    /* then send it to LCD_enuWriteData with its  right address*/
	    LCD_enuWriteData(UBBER_BIT_FOR_NUM+loc_u8Num1);
		/* and take first bit of the number through mod it by 10 */
		u8 loc_u8Num2=Copy_u8Number%10;
		/* then send it to LCD_enuWriteData with its  right address*/
		LCD_enuWriteData(UBBER_BIT_FOR_NUM+loc_u8Num2);
   }
   /* if it is greater than 100 and less than 256 as it is u8*/
   if((Copy_u8Number>100)&&(Copy_u8Number<256))
   {
	   /* then take third bit of the number through divide it by 100 */
	   u8 loc_u8Num1=Copy_u8Number/100;
	   /* then send it to LCD_enuWriteData with its  right address*/
	   LCD_enuWriteData(UBBER_BIT_FOR_NUM+loc_u8Num1);
	   /* then take second bit of the number through mod it by 100 then divide it by 10 */
	   u8 loc_u8Num2=Copy_u8Number%100;
	   u8 loc_u8Num3=loc_u8Num2/10;
	    /* then send it to LCD_enuWriteData with its  right address*/
	   LCD_enuWriteData(UBBER_BIT_FOR_NUM+loc_u8Num3);
	   /* then take first bit of the number through mod it by 100 then nod it by 10 */
	   u8 loc_u8Num4=loc_u8Num2%10;
	   /* then send it to LCD_enuWriteData with its  right address*/
	   LCD_enuWriteData(UBBER_BIT_FOR_NUM+loc_u8Num4);
   }
   return Ret_enumErrorStatus;
}

/************************* function to write spicial characters on LCD ****************/
LCD_enuErrorStatus LCD_enuDisplaySpecialPattern(u8* Copy_pu8Pattern, u8 Copy_u8CGRAMBlockNumber, u8 Copy_u8X, u8 Copy_u8Y)
{
	u8 loc_u8CGRAMLocation=Copy_u8CGRAMBlockNumber*8;
	LCD_enuWriteCommand(loc_u8CGRAMLocation+64);
	for(u8 i=0;i<8;i++)
	{
		LCD_enuWriteData(Copy_pu8Pattern[i]);
	}
	LCD_enuGotoDDRAM_XY(Copy_u8X,Copy_u8Y);
	LCD_enuWriteData(Copy_u8CGRAMBlockNumber);
}