/*
 * interrupt.c
 *
 * Created: 1/2/2024 10:35:14 AM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../PORT/port.h"
#include "../PORT/port_config.h"

#include "interrupt.h"


static volatile void (*EXTI0_ISR) (void) = NULL;
static volatile void (*EXTI1_ISR) (void) = NULL;
static volatile void (*EXTI2_ISR) (void) = NULL;



void INT_INIT()
{
	/*************************** enable global interrupt register *******************/
	SET_BIT(SREG_REG,7);
	/************** if choosen interrupt is interrupt 0 **************/
	if(INT0==ENABLE)
	{
		/******************* make pin of interrupt as input pull up *******************/
		DIO_enumSetPinConfig(DIO_enumPortD,DIO_enumPin2,DIO_enumInputInternalPullUp);
	/********** choose mode to enable interrupt0 ********************/
	u8 loc_u8RegValue=MCUCR_REG;
	loc_u8RegValue&=INT0_MASK_CLEAR;
	loc_u8RegValue|=(INT0_MODE);
	MCUCR_REG=loc_u8RegValue;
	/************* enable nterupt 0 ********************************/
	SET_BIT(GICR_REG,6);
	}
	
	/************** if choosen interrupt is interrupt 1 **************/
	if(INT1==ENABLE)
	{
		/******************* make pin of interrupt as input pull up *******************/
		DIO_enumSetPinConfig(DIO_enumPortD,DIO_enumPin3,DIO_enumInputInternalPullUp);
	/********** choose mode to enable interrupt0 ********************/
	u8 loc_u8RegValue=MCUCR_REG;
	loc_u8RegValue&=INT1_MASK_CLEAR;
	loc_u8RegValue|=(INT1_MODE<<2);
	MCUCR_REG=loc_u8RegValue;
	/************* enable nterupt 1 ********************************/
	SET_BIT(GICR_REG,7);
	}
	
	/************** if choosen interrupt is interrupt 2 **************/
	if(INT2==ENABLE)
	{
		/******************* make pin of interrupt as input pull up *******************/
		DIO_enumSetPinConfig(DIO_enumPortB,DIO_enumPin2,DIO_enumInputInternalPullUp);
	/********** choose mode to enable interrupt2 ********************/
	if(INT2_MODE==INT2_FALLING_EDGE)
	{
		CLR_BIT(MCUCSR_REG,6);
	}
	else if(INT2_MODE==INT2_RISINGING_EDGE)
	{
		SET_BIT(MCUCSR_REG,6);
	}
	/************* enable nterupt 2 ********************************/
	SET_BIT(GICR_REG,5);
	}
	
}

INTERRUPT_enumError_t EXTI_vidRegisterEXTI0Cbf (void (*arg) (void))
{
	
	INTERRUPT_enumError_t Ret_enumErrorStatus=INTERRUPT_enumNOk;
	if(arg == NULL)
	{
		Ret_enumErrorStatus=INTERRUPT_enumNOk;
	}
	else
	{
		Ret_enumErrorStatus=INTERRUPT_enumOk;
		EXTI0_ISR = arg;
	}
	return Ret_enumErrorStatus;
}

INTERRUPT_enumError_t EXTI_vidRegisterEXTI1Cbf (void (*arg) (void))
{
	INTERRUPT_enumError_t Ret_enumErrorStatus=INTERRUPT_enumNOk;
	if(arg == NULL)
	{
		Ret_enumErrorStatus=INTERRUPT_enumNOk;
	}
	else
	{
		Ret_enumErrorStatus=INTERRUPT_enumOk;
		EXTI1_ISR = arg;
	}
	return Ret_enumErrorStatus;
}


INTERRUPT_enumError_t EXTI_vidRegisterEXTI2Cbf (void (*arg) (void))
{
	INTERRUPT_enumError_t Ret_enumErrorStatus=INTERRUPT_enumNOk;
	if(arg == NULL)
	{
		Ret_enumErrorStatus=INTERRUPT_enumNOk;
	}
	else
	{
		Ret_enumErrorStatus=INTERRUPT_enumOk;
		EXTI2_ISR = arg;
	}
	return Ret_enumErrorStatus;
}

/* ISR of EXT0 */



void __vector_1(void)
{
	if(EXTI0_ISR!=NULL)
	{
		EXTI0_ISR();
	}
}


/* ISR of EXT1 */


void __vector_2(void)
{
	if(EXTI1_ISR!=NULL)
	{
		EXTI1_ISR();
	}
}


/* ISR of EXT2 */


void __vector_3(void)
{
	if(EXTI2_ISR)
	{
		EXTI2_ISR();
	}
}
