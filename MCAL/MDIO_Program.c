#include "MDIO_Private.h"
#include "../SERVICE_LAYER/SERVICE_LAYER.h"

/*Function To Set Pin Direction*/
void MDIO_VoidSetPinDir(u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8Dir)
{
	switch(Copy_u8PortName)
	{
		case 0:
			if (Copy_u8Dir == OUTPUT)
			{
				SET_BIT(DDRA_REG,Copy_u8PinNumber);
			}else if(Copy_u8Dir == INPUT)
			{
				CLR_BIT(DDRA_REG,Copy_u8PinNumber);
				SET_BIT(PORTA_REG,Copy_u8PinNumber);
			}
		break;
		case 1:
			if (Copy_u8Dir == OUTPUT)
			{
				SET_BIT(DDRB_REG,Copy_u8PinNumber);
			}else if(Copy_u8Dir == INPUT)
			{
				CLR_BIT(DDRB_REG,Copy_u8PinNumber);
				SET_BIT(PORTB_REG,Copy_u8PinNumber);
			}
		break;
		case 2:
			if (Copy_u8Dir == OUTPUT)
			{
				SET_BIT(DDRC_REG,Copy_u8PinNumber);
			}else if(Copy_u8Dir == INPUT)
			{
				CLR_BIT(DDRC_REG,Copy_u8PinNumber);
				SET_BIT(PORTC_REG,Copy_u8PinNumber);
			}
		break;
		case 3:
			if (Copy_u8Dir == OUTPUT)
			{
				SET_BIT(DDRD_REG,Copy_u8PinNumber);
			}else if(Copy_u8Dir == INPUT)
			{
				CLR_BIT(DDRD_REG,Copy_u8PinNumber);
				SET_BIT(PORTA_REG,Copy_u8PinNumber);
			}
		break;
	}
}
/*---------------------------------------------------------------------------------------------------------------*/

/*Function To Set Pin Value*/
void MDIO_VoidSetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8Value)
{
	switch(Copy_u8PortName)
	{
		case 0:
			if (Copy_u8Value == HIGH)
			{
				SET_BIT(PORTA_REG,Copy_u8PinNumber);
			}else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTA_REG,Copy_u8PinNumber);
			}
		break;
		case 1:
			if (Copy_u8Value == HIGH)
			{
				SET_BIT(PORTB_REG,Copy_u8PinNumber);
			}else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTB_REG,Copy_u8PinNumber);
			}
		break;
		case 2:
			if (Copy_u8Value == HIGH)
			{
				SET_BIT(PORTC_REG,Copy_u8PinNumber);
			}else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTC_REG,Copy_u8PinNumber);
			}
		break;
		case 3:
			if (Copy_u8Value == HIGH)
			{
				SET_BIT(PORTD_REG,Copy_u8PinNumber);
			}else if(Copy_u8Value == LOW)
			{
				CLR_BIT(PORTD_REG,Copy_u8PinNumber);
			}
		break;
	}
}
/*---------------------------------------------------------------------------------------------------------------*/

/*Function To Toggle Pin Value*/
void MDIO_VoidTogglePin(u8 Copy_u8PortName , u8 Copy_u8PinNumber)
{
	switch(Copy_u8PortName)
	{
		case 0:
			TOGGLE_BIT(PORTA_REG,Copy_u8PinNumber);
		break;
		case 1:
			TOGGLE_BIT(PORTB_REG,Copy_u8PinNumber);
		break;
		case 2:
			TOGGLE_BIT(PORTC_REG,Copy_u8PinNumber);
		break;
		case 3:
			TOGGLE_BIT(PORTD_REG,Copy_u8PinNumber);
		break;
	}
}
/*---------------------------------------------------------------------------------------------------------------*/

/*Function To Read Pin Value*/
u8 MDIO_VoidReadPin(u8 Copy_u8PortName , u8 Copy_u8PinNumber)
{
	u8 LOC_u8RetValue = 0;
	switch(Copy_u8PortName)
	{
		case 0:
			 LOC_u8RetValue =GET_BIT(PINA_REG,Copy_u8PinNumber);
		break;
		case 1:
			 LOC_u8RetValue = GET_BIT(PINB_REG,Copy_u8PinNumber);
		break;
		case 2:
			 LOC_u8RetValue = GET_BIT(PINC_REG,Copy_u8PinNumber);
		break;
		case 3:
			 LOC_u8RetValue = GET_BIT(PIND_REG,Copy_u8PinNumber);
		break;
	}
	return LOC_u8RetValue;
}
/*---------------------------------------------------------------------------------------------------------------*/

/*Function To Set Port Direction*/
void MDIO_VoidSetPortDir(u8 Copy_u8PortName , u8 Copy_u8Dir)
{
	switch(Copy_u8PortName)
	{
		case 0:
			DDRA_REG = Copy_u8Dir;
		break;
		case 1:
			DDRB_REG = Copy_u8Dir;
		break;
		case 2:
			DDRC_REG = Copy_u8Dir;
		break;
		case 3:
			DDRD_REG = Copy_u8Dir;
		break;
	}
}
/*---------------------------------------------------------------------------------------------------------------*/

/*Function To Set Port Value*/
void MDIO_VoidSetPortValue(u8 Copy_u8PortName , u8 Copy_u8Value)
{
	switch(Copy_u8PortName)
	{
		case 0:
			PORTA_REG = Copy_u8Value;
		break;
		case 1:
			PORTB_REG = Copy_u8Value;
		break;
		case 2:
			PORTC_REG = Copy_u8Value;
		break;
		case 3:
			PORTD_REG = Copy_u8Value;
		break;
	}
}
/*---------------------------------------------------------------------------------------------------------------*/
