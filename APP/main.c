#include "../SERVICE_LAYER/SERVICE_LAYER.h"
#include "../MCAL/MDIO_Interface.h"
#include "../HAL/HLCD_Interface.h"
#include "../MCAL/MGIE_Interface.h"
#include "../MCAL/MEXIT_Interface.h"
#include <util/delay.h>


int main()
{
	u8 Heart_Shape[] = {
			0B00000,
			  0B01010,
			  0B11111,
			  0B11111,
			  0B01110,
			  0B00100,
			  0B00000,
			  0B00000
	};
	MDIO_VoidSetPinDir(DIO_u8PORTC, DIO_u8PIN7, DIO_u8PIN_OUTPUT	); // set RS pin as an OUTPUT
	MDIO_VoidSetPinDir(DIO_u8PORTC, DIO_u8PIN6, DIO_u8PIN_OUTPUT	); // set EN pin as an OUTPUT
	MDIO_VoidSetPortDir(DIO_u8PORTD, 0xff); //set data port as an OUTPUT
	HLCD_VoidInitLCD(_8BITMODE);


	while(1)
	{
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,0);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,1);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,2);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,3);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,4);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,5);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,6);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,7);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,8);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,9);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,10);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,11);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,12);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,13);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,14);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 0 ,15);
		HLCD_VoidSetPosition_8bit(0, 5);
		HLCD_VoidSendStringLCD_8bit("Mahmoud");
		HLCD_VoidSetPosition_8bit(1, 7);
		HLCD_VoidSendStringLCD_8bit("EZZT");
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,0);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,1);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,2);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,3);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,4);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,5);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,6);

		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,11);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,12);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,13);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,14);
		HLCD_voidWriteSpecialCharacters(Heart_Shape, 0, 1 ,15);
		_delay_ms(1000);
		HLCD_VoidCLRLCD(_8BITMODE);
		_delay_ms(1000);

	}
}




//	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN0, DIO_u8PIN_OUTPUT);
//	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN1, DIO_u8PIN_OUTPUT);
//	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN2, DIO_u8PIN_OUTPUT);
//	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN3, DIO_u8PIN_OUTPUT);
//	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN4, DIO_u8PIN_OUTPUT);
//	MDIO_VoidSetPinDir(DIO_u8PORTB, DIO_u8PIN5, DIO_u8PIN_OUTPUT);
//
//	MDIO_VoidSetPinDir(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_INPUT);
//	MDIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN2, DIO_u8PIN_HIGH);
//
//	MDIO_VoidSetPinDir(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_INPUT);
//	MDIO_VoidSetPinValue(DIO_u8PORTD, DIO_u8PIN3, DIO_u8PIN_HIGH);
//
//	MEXTI0_voidInit();
//	MGIE_VoidEnable();
//	MEXTI0_voidEnable();
//
//	MEXTI1_voidInit();
//	MGIE_VoidEnable();
//	MEXTI1_voidEnable();

