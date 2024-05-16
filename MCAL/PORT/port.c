/*
 * port.c
 *
 * Created: 12/2/2023 11:55:26 PM
 *  Author: Rana
 */ 

#include<stdio.h>
#include<stdlib.h>
#include "port.h"
//#include "port_config.c"
extern DIO_enumPinConf DIO_Pincfg[];
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/**************************************** PRECONFIG MODE ********************************************/
#if ((PRECONFIG==ENABLE)&&(POSTCONFIG==DISABLE))

/**************************************** concat function *******************************************/

#define CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)           (0b##b7##b6##b5##b4##b3##b2##b1##b0)
#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)                CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)

/*#define CONC_HELP(b7, b6, b5, b4, b3, b2, b1, b0) \
((((b7 << 7) | (b6 << 6) | (b5 << 5) | (b4 << 4) | (b3 << 3) | (b2 << 2) | (b1 << 1)) | b0))

#define CONC(b7, b6, b5, b4, b3, b2, b1, b0) CONC_HELP(b7, b6, b5, b4, b3, b2, b1, b0)*/


/******************************************* PORTA **************************************************/
#if (DIO_PIN0_CONFIG==INPUT_PU)
#define PIN0_DIR   PORT_u8LOW
#define PIN0_PORT  PORT_u8HIGH

#elif (DIO_PIN0_CONFIG==INPUT_PD)
#define PIN0_DIR   PORT_u8LOW
#define PIN0_PORT  PORT_u8LOW

#elif (DIO_PIN0_CONFIG==OUTPUT_HIGH)
#define PIN0_DIR   PORT_u8HIGH
#define PIN0_PORT  PORT_u8HIGH

#elif (DIO_PIN0_CONFIG==OUTPUT_LOW)
#define PIN0_DIR   PORT_u8HIGH
#define PIN0_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN1_CONFIG==INPUT_PU)
#define PIN1_DIR   PORT_u8LOW
#define PIN1_PORT  PORT_u8HIGH

#elif (DIO_PIN1_CONFIG==INPUT_PD)
#define PIN1_DIR   PORT_u8LOW
#define PIN1_PORT  PORT_u8LOW

#elif (DIO_PIN1_CONFIG==OUTPUT_HIGH)
#define PIN1_DIR   PORT_u8HIGH
#define PIN1_PORT  PORT_u8HIGH

#elif (DIO_PIN1_CONFIG==OUTPUT_LOW)
#define PIN1_DIR   PORT_u8HIGH
#define PIN1_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN2_CONFIG==INPUT_PU)
#define PIN2_DIR   PORT_u8LOW
#define PIN2_PORT  PORT_u8HIGH

#elif (DIO_PIN2_CONFIG==INPUT_PD)
#define PIN2_DIR   PORT_u8LOW
#define PIN2_PORT  PORT_u8LOW

#elif (DIO_PIN2_CONFIG==OUTPUT_HIGH)
#define PIN2_DIR   PORT_u8HIGH
#define PIN2_PORT  PORT_u8HIGH

#elif (DIO_PIN2_CONFIG==OUTPUT_LOW)
#define PIN2_DIR   PORT_u8HIGH
#define PIN2_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif


#if (DIO_PIN3_CONFIG==INPUT_PU)
#define PIN3_DIR   PORT_u8LOW
#define PIN3_PORT  PORT_u8HIGH

#elif (DIO_PIN3_CONFIG==INPUT_PD)
#define PIN3_DIR   PORT_u8LOW
#define PIN3_PORT  PORT_u8LOW

#elif (DIO_PIN3_CONFIG==OUTPUT_HIGH)
#define PIN3_DIR   PORT_u8HIGH
#define PIN3_PORT  PORT_u8HIGH

#elif (DIO_PIN3_CONFIG==OUTPUT_LOW)
#define PIN3_DIR   PORT_u8HIGH
#define PIN3_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif


#if (DIO_PIN4_CONFIG==INPUT_PU)
#define PIN4_DIR   PORT_u8LOW
#define PIN4_PORT  PORT_u8HIGH

#elif (DIO_PIN4_CONFIG==INPUT_PD)
#define PIN4_DIR   PORT_u8LOW
#define PIN4_PORT  PORT_u8LOW

#elif (DIO_PIN4_CONFIG==OUTPUT_HIGH)
#define PIN4_DIR   PORT_u8HIGH
#define PIN4_PORT  PORT_u8HIGH

#elif (DIO_PIN4_CONFIG==OUTPUT_LOW)
#define PIN4_DIR   PORT_u8HIGH
#define PIN4_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN5_CONFIG==INPUT_PU)
#define PIN5_DIR   PORT_u8LOW
#define PIN5_PORT  PORT_u8HIGH

#elif (DIO_PIN5_CONFIG==INPUT_PD)
#define PIN5_DIR   PORT_u8LOW
#define PIN5_PORT  PORT_u8LOW

#elif (DIO_PIN5_CONFIG==OUTPUT_HIGH)
#define PIN5_DIR   PORT_u8HIGH
#define PIN5_PORT  PORT_u8HIGH

#elif (DIO_PIN5_CONFIG==OUTPUT_LOW)
#define PIN0_DIR   PORT_u8HIGH
#define PIN5_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN6_CONFIG==INPUT_PU)
#define PIN6_DIR   PORT_u8LOW
#define PIN6_PORT  PORT_u8HIGH

#elif (DIO_PIN5_CONFIG==INPUT_PD)
#define PIN6_DIR   PORT_u8LOW
#define PIN6_PORT  PORT_u8LOW

#elif (DIO_PIN5_CONFIG==OUTPUT_HIGH)
#define PIN6_DIR   PORT_u8HIGH
#define PIN6_PORT  PORT_u8HIGH

#elif (DIO_PIN5_CONFIG==OUTPUT_LOW)
#define PIN6_DIR   PORT_u8HIGH
#define PIN6_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN7_CONFIG==INPUT_PU)
#define PIN7_DIR   PORT_u8LOW
#define PIN7_PORT  PORT_u8HIGH

#elif (DIO_PIN7_CONFIG==INPUT_PD)
#define PIN7_DIR   PORT_u8LOW
#define PIN6_PORT  PORT_u8LOW

#elif (DIO_PIN7_CONFIG==OUTPUT_HIGH)
#define PIN7_DIR   PORT_u8HIGH
#define PIN7_PORT  PORT_u8HIGH

#elif (DIO_PIN7_CONFIG==OUTPUT_LOW)
#define PIN7_DIR   PORT_u8HIGH
#define PIN7_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

/******************************************* PORTB **************************************************/

#if (DIO_PIN8_CONFIG==INPUT_PU)
#define PIN8_DIR   PORT_u8LOW
#define PIN8_PORT  PORT_u8HIGH

#elif (DIO_PIN8_CONFIG==INPUT_PD)
#define PIN8_DIR   PORT_u8LOW
#define PIN8_PORT  PORT_u8LOW

#elif (DIO_PIN8_CONFIG==OUTPUT_HIGH)
#define PIN8_DIR   PORT_u8HIGH
#define PIN8_PORT  PORT_u8HIGH

#elif (DIO_PIN8_CONFIG==OUTPUT_LOW)
#define PIN8_DIR   PORT_u8HIGH
#define PIN8_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN9_CONFIG==INPUT_PU)
#define PIN9_DIR   PORT_u8LOW
#define PIN9_PORT  PORT_u8HIGH

#elif (DIO_PIN9_CONFIG==INPUT_PD)
#define PIN9_DIR   PORT_u8LOW
#define PIN9_PORT  PORT_u8LOW

#elif (DIO_PIN9_CONFIG==OUTPUT_HIGH)
#define PIN9_DIR   PORT_u8HIGH
#define PIN9_PORT  PORT_u8HIGH

#elif (DIO_PIN9_CONFIG==OUTPUT_LOW)
#define PIN9_DIR   PORT_u8HIGH
#define PIN9_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN10_CONFIG==INPUT_PU)
#define PIN10_DIR   PORT_u8LOW
#define PIN10_PORT  PORT_u8HIGH

#elif (DIO_PIN10_CONFIG==INPUT_PD)
#define PIN10_DIR   PORT_u8LOW
#define PIN10_PORT  PORT_u8LOW

#elif (DIO_PIN10_CONFIG==OUTPUT_HIGH)
#define PIN10_DIR   PORT_u8HIGH
#define PIN10_PORT  PORT_u8HIGH

#elif (DIO_PIN10_CONFIG==OUTPUT_LOW)
#define PIN10_DIR   PORT_u8HIGH
#define PIN10_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN11_CONFIG==INPUT_PU)
#define PIN11_DIR   PORT_u8LOW
#define PIN11_PORT  PORT_u8HIGH

#elif (DIO_PIN11_CONFIG==INPUT_PD)
#define PIN11_DIR   PORT_u8LOW
#define PIN11_PORT  PORT_u8LOW

#elif (DIO_PIN11_CONFIG==OUTPUT_HIGH)
#define PIN11_DIR   PORT_u8HIGH
#define PIN11_PORT  PORT_u8HIGH

#elif (DIO_PIN11_CONFIG==OUTPUT_LOW)
#define PIN11_DIR   PORT_u8HIGH
#define PIN11_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN12_CONFIG==INPUT_PU)
#define PIN12_DIR   PORT_u8LOW
#define PIN12_PORT  PORT_u8HIGH

#elif (DIO_PIN12_CONFIG==INPUT_PD)
#define PIN12_DIR   PORT_u8LOW
#define PIN12_PORT  PORT_u8LOW

#elif (DIO_PIN12_CONFIG==OUTPUT_HIGH)
#define PIN12_DIR   PORT_u8HIGH
#define PIN12_PORT  PORT_u8HIGH

#elif (DIO_PIN12_CONFIG==OUTPUT_LOW)
#define PIN12_DIR   PORT_u8HIGH
#define PIN12_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN13_CONFIG==INPUT_PU)
#define PIN13_DIR   PORT_u8LOW
#define PIN13_PORT  PORT_u8HIGH

#elif (DIO_PIN13_CONFIG==INPUT_PD)
#define PIN13_DIR   PORT_u8LOW
#define PIN13_PORT  PORT_u8LOW

#elif (DIO_PIN13_CONFIG==OUTPUT_HIGH)
#define PIN13_DIR   PORT_u8HIGH
#define PIN13_PORT  PORT_u8HIGH

#elif (DIO_PIN13_CONFIG==OUTPUT_LOW)
#define PIN13_DIR   PORT_u8HIGH
#define PIN13_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN14_CONFIG==INPUT_PU)
#define PIN14_DIR   PORT_u8LOW
#define PIN14_PORT  PORT_u8HIGH

#elif (DIO_PIN14_CONFIG==INPUT_PD)
#define PIN14_DIR   PORT_u8LOW
#define PIN14_PORT  PORT_u8LOW

#elif (DIO_PIN14_CONFIG==OUTPUT_HIGH)
#define PIN14_DIR   PORT_u8HIGH
#define PIN14_PORT  PORT_u8HIGH

#elif (DIO_PIN14_CONFIG==OUTPUT_LOW)
#define PIN14_DIR   PORT_u8HIGH
#define PIN14_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN15_CONFIG==INPUT_PU)
#define PIN15_DIR   PORT_u8LOW
#define PIN15_PORT  PORT_u8HIGH

#elif (DIO_PIN15_CONFIG==INPUT_PD)
#define PIN15_DIR   PORT_u8LOW
#define PIN15_PORT  PORT_u8LOW

#elif (DIO_PIN15_CONFIG==OUTPUT_HIGH)
#define PIN15_DIR   PORT_u8HIGH
#define PIN15_PORT  PORT_u8HIGH

#elif (DIO_PIN15_CONFIG==OUTPUT_LOW)
#define PIN15_DIR   PORT_u8HIGH
#define PIN15_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

/******************************************* PORTC **************************************************/

#if (DIO_PIN16_CONFIG==INPUT_PU)
#define PIN16_DIR   PORT_u8LOW
#define PIN16_PORT  PORT_u8HIGH

#elif (DIO_PIN16_CONFIG==INPUT_PD)
#define PIN16_DIR   PORT_u8LOW
#define PIN16_PORT  PORT_u8LOW

#elif (DIO_PIN16_CONFIG==OUTPUT_HIGH)
#define PIN16_DIR   PORT_u8HIGH
#define PIN16_PORT  PORT_u8HIGH

#elif (DIO_PIN16_CONFIG==OUTPUT_LOW)
#define PIN16_DIR   PORT_u8HIGH
#define PIN16_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN17_CONFIG==INPUT_PU)
#define PIN17_DIR   PORT_u8LOW
#define PIN17_PORT  PORT_u8HIGH

#elif (DIO_PIN17_CONFIG==INPUT_PD)
#define PIN17_DIR   PORT_u8LOW
#define PIN17_PORT  PORT_u8LOW

#elif (DIO_PIN17_CONFIG==OUTPUT_HIGH)
#define PIN17_DIR   PORT_u8HIGH
#define PIN17_PORT  PORT_u8HIGH

#elif (DIO_PIN17_CONFIG==OUTPUT_LOW)
#define PIN17_DIR   PORT_u8HIGH
#define PIN17_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN18_CONFIG==INPUT_PU)
#define PIN18_DIR   PORT_u8LOW
#define PIN18_PORT  PORT_u8HIGH

#elif (DIO_PIN18_CONFIG==INPUT_PD)
#define PIN18_DIR   PORT_u8LOW
#define PIN18_PORT  PORT_u8LOW

#elif (DIO_PIN18_CONFIG==OUTPUT_HIGH)
#define PIN18_DIR   PORT_u8HIGH
#define PIN18_PORT  PORT_u8HIGH

#elif (DIO_PIN18_CONFIG==OUTPUT_LOW)
#define PIN18_DIR   PORT_u8HIGH
#define PIN18_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN19_CONFIG==INPUT_PU)
#define PIN19_DIR   PORT_u8LOW
#define PIN19_PORT  PORT_u8HIGH

#elif (DIO_PIN19_CONFIG==INPUT_PD)
#define PIN19_DIR   PORT_u8LOW
#define PIN19_PORT  PORT_u8LOW

#elif (DIO_PIN19_CONFIG==OUTPUT_HIGH)
#define PIN19_DIR   PORT_u8HIGH
#define PIN19_PORT  PORT_u8HIGH

#elif (DIO_PIN19_CONFIG==OUTPUT_LOW)
#define PIN19_DIR   PORT_u8HIGH
#define PIN19_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN20_CONFIG==INPUT_PU)
#define PIN20_DIR   PORT_u8LOW
#define PIN20_PORT  PORT_u8HIGH

#elif (DIO_PIN20_CONFIG==INPUT_PD)
#define PIN20_DIR   PORT_u8LOW
#define PIN20_PORT  PORT_u8LOW

#elif (DIO_PIN20_CONFIG==OUTPUT_HIGH)
#define PIN20_DIR   PORT_u8HIGH
#define PIN20_PORT  PORT_u8HIGH

#elif (DIO_PIN20_CONFIG==OUTPUT_LOW)
#define PIN20_DIR   PORT_u8HIGH
#define PIN20_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN21_CONFIG==INPUT_PU)
#define PIN21_DIR   PORT_u8LOW
#define PIN21_PORT  PORT_u8HIGH

#elif (DIO_PIN21_CONFIG==INPUT_PD)
#define PIN21_DIR   PORT_u8LOW
#define PIN21_PORT  PORT_u8LOW

#elif (DIO_PIN21_CONFIG==OUTPUT_HIGH)
#define PIN21_DIR   PORT_u8HIGH
#define PIN21_PORT  PORT_u8HIGH

#elif (DIO_PIN21_CONFIG==OUTPUT_LOW)
#define PIN21_DIR   PORT_u8HIGH
#define PIN21_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN22_CONFIG==INPUT_PU)
#define PIN22_DIR   PORT_u8LOW
#define PIN22_PORT  PORT_u8HIGH

#elif (DIO_PIN22_CONFIG==INPUT_PD)
#define PIN22_DIR   PORT_u8LOW
#define PIN22_PORT  PORT_u8LOW

#elif (DIO_PIN22_CONFIG==OUTPUT_HIGH)
#define PIN22_DIR   PORT_u8HIGH
#define PIN22_PORT  PORT_u8HIGH

#elif (DIO_PIN22_CONFIG==OUTPUT_LOW)
#define PIN22_DIR   PORT_u8HIGH
#define PIN22_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN23_CONFIG==INPUT_PU)
#define PIN23_DIR   PORT_u8LOW
#define PIN23_PORT  PORT_u8HIGH

#elif (DIO_PIN23_CONFIG==INPUT_PD)
#define PIN23_DIR   PORT_u8LOW
#define PIN23_PORT  PORT_u8LOW

#elif (DIO_PIN23_CONFIG==OUTPUT_HIGH)
#define PIN23_DIR   PORT_u8HIGH
#define PIN23_PORT  PORT_u8HIGH

#elif (DIO_PIN23_CONFIG==OUTPUT_LOW)
#define PIN23_DIR   PORT_u8HIGH
#define PIN23_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

/******************************************* PORTD **************************************************/

#if (DIO_PIN24_CONFIG==INPUT_PU)
#define PIN24_DIR   PORT_u8LOW
#define PIN24_PORT  PORT_u8HIGH

#elif (DIO_PIN24_CONFIG==INPUT_PD)
#define PIN24_DIR   PORT_u8LOW
#define PIN24_PORT  PORT_u8LOW

#elif (DIO_PIN24_CONFIG==OUTPUT_HIGH)
#define PIN24_DIR   PORT_u8HIGH
#define PIN24_PORT  PORT_u8HIGH

#elif (DIO_PIN24_CONFIG==OUTPUT_LOW)
#define PIN24_DIR   PORT_u8HIGH
#define PIN24_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN25_CONFIG==INPUT_PU)
#define PIN25_DIR   PORT_u8LOW
#define PIN25_PORT  PORT_u8HIGH

#elif (DIO_PIN25_CONFIG==INPUT_PD)
#define PIN25_DIR   PORT_u8LOW
#define PIN25_PORT  PORT_u8LOW

#elif (DIO_PIN25_CONFIG==OUTPUT_HIGH)
#define PIN25_DIR   PORT_u8HIGH
#define PIN25_PORT  PORT_u8HIGH

#elif (DIO_PIN25_CONFIG==OUTPUT_LOW)
#define PIN25_DIR   PORT_u8HIGH
#define PIN25_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN26_CONFIG==INPUT_PU)
#define PIN26_DIR   PORT_u8LOW
#define PIN26_PORT  PORT_u8HIGH

#elif (DIO_PIN26_CONFIG==INPUT_PD)
#define PIN26_DIR   PORT_u8LOW
#define PIN26_PORT  PORT_u8LOW

#elif (DIO_PIN26_CONFIG==OUTPUT_HIGH)
#define PIN26_DIR   PORT_u8HIGH
#define PIN26_PORT  PORT_u8HIGH

#elif (DIO_PIN26_CONFIG==OUTPUT_LOW)
#define PIN26_DIR   PORT_u8HIGH
#define PIN26_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN27_CONFIG==INPUT_PU)
#define PIN27_DIR   PORT_u8LOW
#define PIN27_PORT  PORT_u8HIGH

#elif (DIO_PIN27_CONFIG==INPUT_PD)
#define PIN27_DIR   PORT_u8LOW
#define PIN27_PORT  PORT_u8LOW

#elif (DIO_PIN27_CONFIG==OUTPUT_HIGH)
#define PIN27_DIR   PORT_u8HIGH
#define PIN27_PORT  PORT_u8HIGH

#elif (DIO_PIN27_CONFIG==OUTPUT_LOW)
#define PIN27_DIR   PORT_u8HIGH
#define PIN27_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN28_CONFIG==INPUT_PU)
#define PIN28_DIR   PORT_u8LOW
#define PIN28_PORT  PORT_u8HIGH

#elif (DIO_PIN28_CONFIG==INPUT_PD)
#define PIN28_DIR   PORT_u8LOW
#define PIN28_PORT  PORT_u8LOW

#elif (DIO_PIN28_CONFIG==OUTPUT_HIGH)
#define PIN28_DIR   PORT_u8HIGH
#define PIN28_PORT  PORT_u8HIGH

#elif (DIO_PIN28_CONFIG==OUTPUT_LOW)
#define PIN28_DIR   PORT_u8HIGH
#define PIN28_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN29_CONFIG==INPUT_PU)
#define PIN29_DIR   PORT_u8LOW
#define PIN29_PORT  PORT_u8HIGH

#elif (DIO_PIN29_CONFIG==INPUT_PD)
#define PIN29_DIR   PORT_u8LOW
#define PIN29_PORT  PORT_u8LOW

#elif (DIO_PIN29_CONFIG==OUTPUT_HIGH)
#define PIN29_DIR   PORT_u8HIGH
#define PIN29_PORT  PORT_u8HIGH

#elif (DIO_PIN29_CONFIG==OUTPUT_LOW)
#define PIN29_DIR   PORT_u8HIGH
#define PIN29_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN30_CONFIG==INPUT_PU)
#define PIN30_DIR   PORT_u8LOW
#define PIN30_PORT  PORT_u8HIGH

#elif (DIO_PIN30_CONFIG==INPUT_PD)
#define PIN30_DIR   PORT_u8LOW
#define PIN30_PORT  PORT_u8LOW

#elif (DIO_PIN30_CONFIG==OUTPUT_HIGH)
#define PIN30_DIR   PORT_u8HIGH
#define PIN30_PORT  PORT_u8HIGH

#elif (DIO_PIN30_CONFIG==OUTPUT_LOW)
#define PIN30_DIR   PORT_u8HIGH
#define PIN30_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

#if (DIO_PIN31_CONFIG==INPUT_PU)
#define PIN31_DIR   PORT_u8LOW
#define PIN31_PORT  PORT_u8HIGH

#elif (DIO_PIN31_CONFIG==INPUT_PD)
#define PIN31_DIR   PORT_u8LOW
#define PIN31_PORT  PORT_u8LOW

#elif (DIO_PIN31_CONFIG==OUTPUT_HIGH)
#define PIN31_DIR   PORT_u8HIGH
#define PIN31_PORT  PORT_u8HIGH

#elif (DIO_PIN31_CONFIG==OUTPUT_LOW)
#define PIN31_DIR   PORT_u8HIGH
#define PIN31_PORT  PORT_u8LOW

#else
#error"error_wrong_configration"

#endif

void PORT_vidInit(void)
{
	/**************************** case PRECONFIG *********************************/
 	
	/*********************** Accessing PORTA REGISTERS****************************/
	DDRA_REG=CONC(PIN7_DIR,PIN6_DIR,PIN5_DIR,PIN4_DIR,PIN3_DIR,PIN2_DIR,PIN1_DIR,PIN0_DIR);
	PORTA_REG=CONC(PIN7_PORT,PIN6_PORT,PIN5_PORT,PIN4_PORT,PIN3_PORT,PIN2_PORT,PIN1_PORT,PIN0_PORT);
	
	/*********************** Accessing PORTB REGISTERS***********************************/
	DDRB_REG=CONC(PIN15_DIR,PIN14_DIR,PIN13_DIR,PIN12_DIR,PIN11_DIR,PIN10_DIR,PIN9_DIR,PIN8_DIR);
	PORTB_REG=CONC(PIN15_PORT,PIN14_PORT,PIN13_PORT,PIN12_PORT,PIN11_PORT,PIN10_PORT,PIN9_PORT,PIN8_PORT);
	
	 #if (NUM_OF_PORT==3)
	/*********************** Accessing PORTC REGISTERS**********************************/
	DDRC_REG=CONC(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR);
	PORTC_REG=CONC(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT);
	
	#elif (NUM_OF_PORT==4)
	
	/*********************** Accessing PORTC REGISTERS*********************************/
	DDRC_REG=CONC(PIN23_DIR,PIN22_DIR,PIN21_DIR,PIN20_DIR,PIN19_DIR,PIN18_DIR,PIN17_DIR,PIN16_DIR);
	PORTC_REG=CONC(PIN23_PORT,PIN22_PORT,PIN21_PORT,PIN20_PORT,PIN19_PORT,PIN18_PORT,PIN17_PORT,PIN16_PORT);
	/*********************** Accessing PORTD REGISTERS********************************/
	DDRD_REG=CONC(PIN31_DIR,PIN30_DIR,PIN29_DIR,PIN28_DIR,PIN27_DIR,PIN26_DIR,PIN25_DIR,PIN24_DIR);
	PORTD_REG=CONC(PIN31_PORT,PIN30_PORT,PIN29_PORT,PIN28_PORT,PIN27_PORT,PIN26_PORT,PIN25_PORT,PIN24_PORT);
	#endif
	
}

#endif

/*********************************** POSTCONFIG MODE **************************************/
#if ((PRECONFIG==DISABLE)&&(POSTCONFIG==ENABLE))

void PORT_vidInit(void)
{
	for(u8 i=0;i<(NUM_OF_PORT*NUM_OF_PIN_PER_PORT);i++)
	{
		u8 Loc_u8PortNum=i/8;
		u8 Loc_u8PinNum=i%8;
		
		switch(Loc_u8PortNum)
		{
			/************************************** PORTA CONFIGRATION *************************************/
			case PORT_enumPORTA:
			switch(DIO_Pincfg[i])
			{
				case DIO_enumInput_PU:
				CLR_BIT(DDRA_REG,Loc_u8PinNum);
				SET_BIT(PORTA_REG,Loc_u8PinNum);
				break;
				
				case DIO_enumInput_PD:
				CLR_BIT(DDRA_REG,Loc_u8PinNum);
				CLR_BIT(PORTA_REG,Loc_u8PinNum);
				break;
				
				case DIO_OUTPUT_HIGH:
				SET_BIT(DDRA_REG,Loc_u8PinNum);
				SET_BIT(PORTA_REG,Loc_u8PinNum);
				break;
				
				case DIO_OUTPUT_LOW:
				SET_BIT(DDRA_REG,Loc_u8PinNum);
				CLR_BIT(PORTA_REG,Loc_u8PinNum);
				break;
				default:
				
				break;
			}
			break;
			/************************************** PORTB CONFIGRATION *************************************/
			case PORT_enumPORTB:
			switch(DIO_Pincfg[i])
			{
				case DIO_enumInput_PU:
				CLR_BIT(DDRB_REG,Loc_u8PinNum);
				SET_BIT(PORTB_REG,Loc_u8PinNum);
				break;
				
				case DIO_enumInput_PD:
				CLR_BIT(DDRB_REG,Loc_u8PinNum);
				CLR_BIT(PORTB_REG,Loc_u8PinNum);
				break;
				
				case DIO_OUTPUT_HIGH:
				SET_BIT(DDRB_REG,Loc_u8PinNum);
				SET_BIT(PORTB_REG,Loc_u8PinNum);
				break;
				
				case DIO_OUTPUT_LOW:
				SET_BIT(DDRB_REG,Loc_u8PinNum);
				CLR_BIT(PORTB_REG,Loc_u8PinNum);
				break;
				default:
				
				break;
			}
			break;
			/************************************** PORTC CONFIGRATION *************************************/
			case PORT_enumPORTC:
			switch(DIO_Pincfg[i])
			{
				case DIO_enumInput_PU:
				CLR_BIT(DDRC_REG,Loc_u8PinNum);
				SET_BIT(PORTC_REG,Loc_u8PinNum);
				break;
				
				case DIO_enumInput_PD:
				CLR_BIT(DDRC_REG,Loc_u8PinNum);
				CLR_BIT(PORTC_REG,Loc_u8PinNum);
				break;
				
				case DIO_OUTPUT_HIGH:
				SET_BIT(DDRC_REG,Loc_u8PinNum);
				SET_BIT(PORTC_REG,Loc_u8PinNum);
				break;
				
				case DIO_OUTPUT_LOW:
				SET_BIT(DDRC_REG,Loc_u8PinNum);
				CLR_BIT(PORTC_REG,Loc_u8PinNum);
				break;
				default:
				
				break;
			}
			break;
				/************************************** PORTD CONFIGRATION *************************************/
				case PORT_enumPORTD:
				switch(DIO_Pincfg[i])
				{
					case DIO_enumInput_PU:
					CLR_BIT(DDRD_REG,Loc_u8PinNum);
					SET_BIT(PORTD_REG,Loc_u8PinNum);
					break;
					
					case DIO_enumInput_PD:
					CLR_BIT(DDRD_REG,Loc_u8PinNum);
					CLR_BIT(PORTD_REG,Loc_u8PinNum);
					break;
					
					case DIO_OUTPUT_HIGH:
					SET_BIT(DDRD_REG,Loc_u8PinNum);
					SET_BIT(PORTD_REG,Loc_u8PinNum);
					break;
					
					case DIO_OUTPUT_LOW:
					SET_BIT(DDRD_REG,Loc_u8PinNum);
					CLR_BIT(PORTD_REG,Loc_u8PinNum);
					break;
					default:
					
					break;
				}
				break;
				
				 default:
				
				break;
			}
			
			
			
			
		
				
	}
	
	
}

PORT_enumError_t Port_setcfg(Portcfg_t *AddPortConfig)
{
	PORT_enumError_t Ret_enumErrorStatus=PORT_enumNok;
	
	if(AddPortConfig->PORT_u8port>NUM_OF_PORT)
	{
		Ret_enumErrorStatus=PORT_enumWrongPort;
	}
	else if(AddPortConfig->PORT_u8pin>NUM_OF_PIN_PER_PORT)
	{
		Ret_enumErrorStatus=PORT_enumWrongConfig;
	}
	else if(AddPortConfig->PORT_u8ConfigType>PORT_enumInputExternalPullDown)
	{
		Ret_enumErrorStatus=PORT_enumWrongConfig;
	}
	else
	{
		Ret_enumErrorStatus=PORT_enumOk;
		/* code implementation */
		switch(AddPortConfig->PORT_u8port)
		{
			case PORT_enumPORTA:
			switch(AddPortConfig->PORT_u8ConfigType)
			{
				case PORT_enumOutputHigh:
				SET_BIT(DDRA_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTA_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumOutputLow:
				SET_BIT(DDRA_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTA_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputInternalPullUp:
				CLR_BIT(DDRA_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTA_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputExternalPullDown:
				CLR_BIT(DDRA_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTA_REG,AddPortConfig->PORT_u8pin);
				break;
				
				default:
				
				break;
				
			}
			
			break;
			
			case PORT_enumPORTB:
			switch(AddPortConfig->PORT_u8ConfigType)
			{
				case PORT_enumOutputHigh:
				SET_BIT(DDRB_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTB_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumOutputLow:
				SET_BIT(DDRB_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTB_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputInternalPullUp:
				CLR_BIT(DDRB_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTB_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputExternalPullDown:
				CLR_BIT(DDRB_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTB_REG,AddPortConfig->PORT_u8pin);
				break;
				
				default:
				
				break;
				
			}
			
			break;
			
			case PORT_enumPORTC:
			switch(AddPortConfig->PORT_u8ConfigType)
			{
				case PORT_enumOutputHigh:
				SET_BIT(DDRC_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTC_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumOutputLow:
				SET_BIT(DDRC_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTC_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputInternalPullUp:
				CLR_BIT(DDRC_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTC_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputExternalPullDown:
				CLR_BIT(DDRC_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTC_REG,AddPortConfig->PORT_u8pin);
				break;
				
				default:
				
				break;
				
			}
			
			break;
			
			case PORT_enumPORTD:
			switch(AddPortConfig->PORT_u8ConfigType)
			{
				case PORT_enumOutputHigh:
				SET_BIT(DDRD_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTD_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumOutputLow:
				SET_BIT(DDRD_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTD_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputInternalPullUp:
				CLR_BIT(DDRD_REG,AddPortConfig->PORT_u8pin);
				SET_BIT(PORTD_REG,AddPortConfig->PORT_u8pin);
				break;
				
				case PORT_enumInputExternalPullDown:
				CLR_BIT(DDRD_REG,AddPortConfig->PORT_u8pin);
				CLR_BIT(PORTD_REG,AddPortConfig->PORT_u8pin);
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

#endif