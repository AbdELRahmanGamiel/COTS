#include "../SERVICE_LAYER/SERVICE_LAYER.h"
#include "../MCAL/MDIO_Interface.h"
#include "../HAL/HLCD_Interface.h"
#include "../MCAL/MGIE_Interface.h"
#include "../MCAL/MEXIT_Interface.h"
#include <util/delay.h>


int main()
{
	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_OUTPUT);
	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_OUTPUT);

	MDIO_VoidSetPinDir(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_INPUT);
	MDIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);

	MDIO_VoidSetPinDir(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_INPUT);
	MDIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_HIGH);

	MEXTI0_voidInit();
	MGIE_VoidEnable();
	MEXTI0_voidEnable();

	MEXTI1_voidInit();
	MGIE_VoidEnable();
	MEXTI1_voidEnable();

	while(1)
	{

	}
}




//		HLCD_VoidSendChar_4bit('G');
//		HLCD_VoidSendChar_4bit('A');
//		HLCD_VoidSendChar_4bit('M');
//		HLCD_VoidSendChar_4bit('I');
//		HLCD_VoidSendChar_4bit('E');
//		HLCD_VoidSendChar_4bit('L');
//		_delay_ms(1000);
//		HLCD_VoidCLRLCD(_4BITMODE);
//		HLCD_VoidSendChar_4bit('M');
//		HLCD_VoidSendChar_4bit('A');
//		HLCD_VoidSendChar_4bit('R');
//		HLCD_VoidSendChar_4bit('A');
//		HLCD_VoidSendChar_4bit('W');
//		HLCD_VoidSendChar_4bit('A');
//		HLCD_VoidSendChar_4bit('N');
//		_delay_ms(1000);
//		HLCD_VoidCLRLCD(_4BITMODE);
