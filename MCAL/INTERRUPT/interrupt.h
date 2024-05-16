
/*
 * interrupt.h
 *
 * Created: 1/2/2024 10:34:48 AM
 *  Author: Rana
 */ 

/*#include<stdio.h>
#include<stdlib.h>*/

/*#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"*/

#include "../DIO/dio.h"

#include "interrupt_cfg.h"

#ifndef INTERRUPT_H_





/*************************** Masks to clear interrupt register MCUCR*********************/ 
#define INT0_MASK_CLEAR    0XFC
#define INT1_MASK_CLEAR    0XF3




/********************* init of interrupt *************************/

void INT_INIT();


typedef enum {
	INTERRUPT_enumOk,
	INTERRUPT_enumNOk
}INTERRUPT_enumError_t;

/************ interrupt ISR **********************************/

INTERRUPT_enumError_t EXTI_vidRegisterEXTI0Cbf (void (*arg) (void));
INTERRUPT_enumError_t EXTI_vidRegisterEXTI1Cbf (void (*arg) (void));
INTERRUPT_enumError_t EXTI_vidRegisterEXTI2Cbf (void (*arg) (void));

void __vector_1(void) __attribute__((signal));
void __vector_2(void) __attribute__((signal));
void __vector_3(void) __attribute__((signal));

#define NULL ((void*)0)

#endif