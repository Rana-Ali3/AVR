/*
 * Dio.c
 *
 * Created: 11/26/2023 8:56:08 PM
 *  Author: Rana
 */ 


//#include <xc.h>
#include<stdio.h>
#include<stdlib.h>
#include "dio.h"
#include "../PORT/port_config.h"


/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPullDown)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	else
	{
		Ret_enumErrorStatus=DIO_enumOk;
		/* code implementation */
		switch(Copy_enumPortNum)
		{
		case DIO_enumPortA:
		switch(Copy_enumConfig)
		{
			case DIO_enumOutput:
			SET_BIT(DDRA_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputInternalPullUp:
			CLR_BIT(DDRA_REG,Copy_enumPinNum);
			SET_BIT(PORTA_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputExternalPullDown:
			CLR_BIT(DDRA_REG,Copy_enumPinNum);
			CLR_BIT(PORTA_REG,Copy_enumPinNum);
			break;
			
			 default:
			
			break;
			
		}
		
		break;
		
		case DIO_enumPortB:
		switch(Copy_enumConfig)
		{
			case DIO_enumOutput:
			SET_BIT(DDRB_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputInternalPullUp:
			CLR_BIT(DDRB_REG,Copy_enumPinNum);
			SET_BIT(PORTB_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputExternalPullDown:
			CLR_BIT(DDRB_REG,Copy_enumPinNum);
			CLR_BIT(PORTB_REG,Copy_enumPinNum);
			break;
			
			default:
			
			break;
			
		}
		
		break;
		
		case DIO_enumPortC:
		switch(Copy_enumConfig)
		{
			case DIO_enumOutput:
			SET_BIT(DDRC_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputInternalPullUp:
			CLR_BIT(DDRC_REG,Copy_enumPinNum);
			SET_BIT(PORTC_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputExternalPullDown:
			CLR_BIT(DDRC_REG,Copy_enumPinNum);
			CLR_BIT(PORTC_REG,Copy_enumPinNum);
			break;
			
			default:
			
			break;
			
		}
		
		break;
		
		case DIO_enumPortD:
		switch(Copy_enumConfig)
		{
			case DIO_enumOutput:
			SET_BIT(DDRD_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputInternalPullUp:
			CLR_BIT(DDRD_REG,Copy_enumPinNum);
			SET_BIT(PORTD_REG,Copy_enumPinNum);
			break;
			
			case DIO_enumInputExternalPullDown:
			CLR_BIT(DDRD_REG,Copy_enumPinNum);
			CLR_BIT(PORTD_REG,Copy_enumPinNum);
			break;
			
			 default:
			
			break;
			
		}
		
		break;	
		
		default:
		
		break;
			
			
			
		}
		
	}
	
	return Ret_enumErrorStatus;
	
}

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumConfig>DIO_enumInputExternalPullDown)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	else
	{
		Ret_enumErrorStatus=DIO_enumOk;
		/* code implementation */
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumConfig)
			{
			case DIO_enumOutput:
			DDRA_REG=0xFF;
			break;
			
			case DIO_enumInputInternalPullUp:
			DDRA_REG=0x00;
			PORTA_REG=0xFF;
			break;
			
			case DIO_enumInputExternalPullDown:
			DDRA_REG=0x00;
			PORTA_REG=0x00;
			break;
			
			default:
			
			break;
				
			}
			break;
			
			case DIO_enumPortB:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRB_REG=0xFF;
				break;
				
				case DIO_enumInputInternalPullUp:
				DDRB_REG=0x00;
				PORTB_REG=0xFF;
				break;
				
				case DIO_enumInputExternalPullDown:
				DDRB_REG=0x00;
				PORTB_REG=0x00;
				break;
				
				default:
				
				break;
			}
			
			break;
			
			case DIO_enumPortC:
			switch(Copy_enumConfig)
			{
				case DIO_enumOutput:
				DDRC_REG=0xFF;
				break;
				
				case DIO_enumInputInternalPullUp:
				DDRC_REG=0x00;
				PORTC_REG=0xFF;
				break;
				
				case DIO_enumInputExternalPullDown:
				DDRC_REG=0x00;
				PORTC_REG=0x00;
				break;
				
				default:
				
				break;
				
			}
			
			break;
			
			case DIO_enumPortD:
			switch(Copy_enumConfig)
			{
				
				case DIO_enumOutput:
				DDRD_REG=0xFF;
				break;
				
				case DIO_enumInputInternalPullUp:
				DDRD_REG=0x00;
				PORTD_REG=0xFF;
				break;
				
				case DIO_enumInputExternalPullDown:
				DDRD_REG=0x00;
				PORTD_REG=0x00;
				break;
				
				default:
				
				break;
				
			}
			
			break;
			
			default:
			
			break;
			
			
		}
		
		
		
	}
	return Ret_enumErrorStatus;
	
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		Ret_enumErrorStatus=DIO_enumNok;
	}
	else
	{
	    Ret_enumErrorStatus=DIO_enumOk;	
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				CLR_BIT(PORTA_REG,Copy_enumPinNum);
				break;
				case DIO_enumLogicHigh:
				SET_BIT(PORTA_REG,Copy_enumPinNum);
				break;
				 default:
				
				break;
			}
			break;
			
			case DIO_enumPortB:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				CLR_BIT(PORTB_REG,Copy_enumPinNum);
				break;
				case DIO_enumLogicHigh:
				SET_BIT(PORTB_REG,Copy_enumPinNum);
				break;
				 default:
				
				break;
			}
			break;
			
			case DIO_enumPortC:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				CLR_BIT(PORTC_REG,Copy_enumPinNum);
				break;
				case DIO_enumLogicHigh:
				SET_BIT(PORTC_REG,Copy_enumPinNum);
				break;
				 default:
				
				break;
			}
			break;
			
			case DIO_enumPortD:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				CLR_BIT(PORTD_REG,Copy_enumPinNum);
				break;
				case DIO_enumLogicHigh:
				SET_BIT(PORTD_REG,Copy_enumPinNum);
				break;
				 default:
				
				break;
			}
			break;
			
			 default:
			
			break;
			
			
			
		}
	}
	
	return Ret_enumErrorStatus;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	
	else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		Ret_enumErrorStatus=DIO_enumNok;
	}
	else
	{
		Ret_enumErrorStatus=DIO_enumOk;	
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				PORTA_REG=0x00;
				break;
				
				case DIO_enumLogicHigh:
				PORTA_REG=0xFF;
				break;
				
				 default:
				
				break;
				
			}
			break;
			
			case DIO_enumPortB:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				PORTB_REG=0x00;
				break;
				
				case DIO_enumLogicHigh:
				PORTB_REG=0xFF;
				break;
				
				 default:
				
				break;
				
			}
			break;
			
			case DIO_enumPortC:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				PORTC_REG=0x00;
				break;
				
				case DIO_enumLogicHigh:
				PORTC_REG=0xFF;
				break;
				
				 default:
				
				break;
				
			}
			break;
			
			case DIO_enumPortD:
			switch(Copy_enumLogicState)
			{
				case DIO_enumLogicLow:
				PORTD_REG=0x00;
				break;
				
				case DIO_enumLogicHigh:
				PORTD_REG=0xFF;
				break;
				
				 default:
				
				break;
				
			}
			break;
			  default:
			 
			 break;
			
		
	}
	}
	return Ret_enumErrorStatus;
	
}

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	/*else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		Ret_enumErrorStatus=DIO_enumNok;
	}*/
	else
	{
	    Ret_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
		  case DIO_enumPortA:
		  *Add_Pu8PinValue=GET_BIT(PINA_REG,Copy_enumPinNum);
		  break;
		  
		  case DIO_enumPortB:
		  *Add_Pu8PinValue=GET_BIT(PINB_REG,Copy_enumPinNum);
		  break;
		  
		  case DIO_enumPortC:
		  *Add_Pu8PinValue=GET_BIT(PINC_REG,Copy_enumPinNum);
		  break;
		  
		  case DIO_enumPortD:
		  *Add_Pu8PinValue=GET_BIT(PIND_REG,Copy_enumPinNum);
		  break;
		  
		   default:
		  
		  break;
			
		}
		
		
	}
	return Ret_enumErrorStatus;
}

DIO_enumError_t DIO_enumReadStateOfPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else if(Copy_enumPinNum>DIO_enumPin7)
	{
		Ret_enumErrorStatus=DIO_enumWrongConfig;
	}
	/*else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		Ret_enumErrorStatus=DIO_enumNok;
	}*/
	else
	{
	    Ret_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
		  case DIO_enumPortA:
		  *Add_Pu8PinValue=GET_BIT(PINA_REG,Copy_enumPinNum);
		  break;
		  
		  case DIO_enumPortB:
		  *Add_Pu8PinValue=GET_BIT(PINB_REG,Copy_enumPinNum);
		  break;
		  
		  case DIO_enumPortC:
		  *Add_Pu8PinValue=GET_BIT(PINC_REG,Copy_enumPinNum);
		  break;
		  
		  case DIO_enumPortD:
		  *Add_Pu8PinValue=GET_BIT(PIND_REG,Copy_enumPinNum);
		  break;
		  
		   default:
		  
		  break;
			
		}
		
		
	}
	return Ret_enumErrorStatus;
}

DIO_enumError_t DIO_enumReadStateOfHalfPort(DIO_enumPorts_t Copy_enumPortNum,u8* Add_Pu8PinValue)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	
	/*else if(Copy_enumLogicState>DIO_enumLogicHigh)
	{
		Ret_enumErrorStatus=DIO_enumNok;
	}*/
	else
	{
	    Ret_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
		  case DIO_enumPortA:
		  *Add_Pu8PinValue=GET_LOW_NIB(PORTA_REG);
		  break;
		  
		  case DIO_enumPortB:
		  *Add_Pu8PinValue=GET_LOW_NIB(PORTB_REG);
		  break;
		  
		  case DIO_enumPortC:
		  *Add_Pu8PinValue=GET_LOW_NIB(PORTC_REG);
		  break;
		  
		  case DIO_enumPortD:
		  *Add_Pu8PinValue=GET_LOW_NIB(PORTD_REG);
		  break;
		  
		   default:
		  
		  break;
			
		}
		
		
	}
	return Ret_enumErrorStatus;
}


DIO_enumError_t DIO_giveValueToPort(DIO_enumPorts_t Copy_enumPortNum,u8 Copy_u8Value)
{
	DIO_enumError_t Ret_enumErrorStatus=DIO_enumNok;
	if(Copy_enumPortNum>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=DIO_enumWrongPort;
	}
	else
	{
		Ret_enumErrorStatus=DIO_enumOk;
		switch(Copy_enumPortNum)
		{
			case DIO_enumPortA:
			PORTA_REG=Copy_u8Value;
			break;
			
			case DIO_enumPortB:
			PORTB_REG=Copy_u8Value;
			break;
			
			case DIO_enumPortC:
			PORTC_REG=Copy_u8Value;
			break;
			
			case DIO_enumPortD:
			PORTD_REG=Copy_u8Value;
			break;
			
			default:
			
			break;
		
		
	}
	}
	return Ret_enumErrorStatus;
	
	
}