#include "../SERVICE_LAYER/SERVICE_LAYER.h"
#include "../MCAL/MDIO_Interface.h"
#include "HLCD_config.h"
#include <util/delay.h>

/*Function to write data on LCD (_8bit mode)*/
void HLCD_VoidSendChar_8bit(u8 Copy_u8Data)
{
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, DIO_u8PIN_HIGH); // Set RS HIGH to send data
	MDIO_VoidSetPortValue(HLCD_DATA_PORT, Copy_u8Data);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_HIGH); // Enabling sequence
	_delay_ms(2);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_LOW); // Disabling sequence
	_delay_ms(2);
}
/*_________________________________________________________________________________*/

/*Function to write data on LCD (_4bit mode)*/
void HLCD_VoidSendChar_4bit(u8 Copy_u8Data)
{
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, DIO_u8PIN_HIGH); // Set RS HIGH to send data
	MDIO_VoidSetPortValue(HLCD_DATA_PORT,WRITE_MOST(Copy_u8Data));
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_HIGH); // Enabling sequence
	_delay_ms(1);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_LOW); // Disabling sequence
	_delay_ms(1);
	MDIO_VoidSetPortValue(HLCD_DATA_PORT,WRITE_LEAST(Copy_u8Data));
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_HIGH); // Enabling sequence
	_delay_ms(1);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_LOW); // Disabling sequence
	_delay_ms(1);
}
/*_________________________________________________________________________________*/


/*Function to write Command on LCD (_8bit mode)*/
void HLCD_VoidSendCommand_8bit(u8 Copy_u8Command)
{
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, DIO_u8PIN_LOW); // Set RS LOW to send Command
	MDIO_VoidSetPortValue(HLCD_DATA_PORT, Copy_u8Command);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_HIGH); // Enabling sequence
	_delay_ms(2);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_LOW); // Disabling sequence
	_delay_ms(2);
}
/*_________________________________________________________________________________*/

/*Function to write Command on LCD (_8bit mode)*/
void HLCD_VoidSendCommand_4bit(u8 Copy_u8Command)
{
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_RS_PIN, DIO_u8PIN_HIGH); // Set RS LOW to send command
	MDIO_VoidSetPortValue(HLCD_DATA_PORT,WRITE_MOST(Copy_u8Command));
	_delay_us(100);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_HIGH); // Enabling sequence
	_delay_ms(1);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_LOW); // Disabling sequence
	_delay_ms(1);
	MDIO_VoidSetPortValue(HLCD_DATA_PORT,WRITE_LEAST(Copy_u8Command));
	_delay_us(100);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_HIGH); // Enabling sequence
	_delay_ms(1);
	MDIO_VoidSetPinValue(HLCD_CTRL_PORT, HLCD_E_PIN, DIO_u8PIN_LOW); // Disabling sequence
	_delay_ms(1);
}
/*_________________________________________________________________________________*/


/*Function to Init LCD*/
void HLCD_VoidInitLCD(char mode)
{
	_delay_ms(30);
	if(mode == _8BITMODE)
	{
	HLCD_VoidSendCommand_8bit(0x38); // for selecting mode(8bit or 4bit) & 2line mode & 5*8 dots
	_delay_ms(1);
	HLCD_VoidSendCommand_8bit(0b00001100); // for setting ON Entire Display & No Cursor & NO Cursor Blinking
	_delay_ms(1);
	HLCD_VoidSendCommand_8bit(0b00000001); //Clear LCD
	_delay_ms(3);
	}else if (mode == _4BITMODE)
	{
		HLCD_VoidSendCommand_8bit(0b00100000);// for selecting mode(8bit or 4bit) & 2line mode & 5*8 dots
		HLCD_VoidSendCommand_8bit(0b00100000);
		HLCD_VoidSendCommand_8bit(0b10000000);
		_delay_ms(1);
		HLCD_VoidSendCommand_8bit(0b00000000);
		HLCD_VoidSendCommand_8bit(0b11000000);// for setting ON Entire Display & No Cursor & NO Cursor Blinking
		_delay_ms(1);
		HLCD_VoidSendCommand_8bit(0b00000000); //Clear LCD
		HLCD_VoidSendCommand_8bit(0b00010000);
		_delay_ms(3);
	}

}
/*_________________________________________________________________________________*/

/*Function to CLR LCD*/
void HLCD_VoidCLRLCD(char mode)
{
	if(mode == _8BITMODE)
	{
		HLCD_VoidSendCommand_8bit(0x01);
		_delay_ms(5);
	}else if(mode == _4BITMODE)
	{
		HLCD_VoidSendCommand_8bit(0b00000000);
		HLCD_VoidSendCommand_8bit(0b00010000);
		_delay_ms(5);
	}

}
/*_________________________________________________________________________________*/

/*Function to Send String LCD (_8bit mode)*/
void HLCD_VoidSendStringLCD_8bit(char *Copy_string)
{
	int i = 0;
	while(Copy_string[i] != '\0')
	{
		HLCD_VoidSendChar_8bit(Copy_string[i]);
		i++;
	}
}
/*_________________________________________________________________________________*/

/*Function to Send String LCD (_4bit mode)*/
void HLCD_VoidSendStringLCD_4bit(char *Copy_string)
{
	int i = 0;
	while(Copy_string[i] != '\0')
	{
		HLCD_VoidSendChar_4bit(Copy_string[i]);
		i++;
	}
}
/*_________________________________________________________________________________*/

/*Function to Send number LCD (_8bit mode)*/
void HLCD_VoidSendnumberLCD_8bit(u32 Copy_u8num)
{
	if (Copy_u8num == 0)
	{
		HLCD_VoidSendChar_8bit(48);
	}else
	{
		u32 rev = 1;
		while(Copy_u8num > 0)
		{
			rev = (rev * 10) + (Copy_u8num % 10);
			Copy_u8num = Copy_u8num / 10;
		}
		while(rev > 1)
		{
			u8 n = rev % 10 ;
			HLCD_VoidSendChar_8bit(n+48);
			rev = rev / 10;
		}
	}
}
/*_________________________________________________________________________________*/

/*Function to Send number LCD (_4bit mode)*/
void HLCD_VoidSendnumberLCD_4bit(u32 Copy_u8num)
{
	if (Copy_u8num == 0)
	{
		HLCD_VoidSendChar_4bit(48);
	}else
	{
		u8 rev = 1;
		while(Copy_u8num > 0)
		{
			rev = (rev * 10) + (Copy_u8num % 10);
			Copy_u8num = Copy_u8num / 10;
		}
		while(rev > 1)
		{
			u8 n = rev % 10 ;
			HLCD_VoidSendChar_4bit(n+48);
			rev = rev / 10;
		}
	}
}
/*_________________________________________________________________________________*/

void HLCD_VoidSetPosition_8bit(u8 Copy_u8Row ,u8 Copy_u8Column)
{
	if(Copy_u8Row == 0)
	{
		HLCD_VoidSendCommand_8bit(128 + Copy_u8Column);
	}else if(Copy_u8Row == 1)
	{
		HLCD_VoidSendCommand_8bit(128 + 64 + Copy_u8Column);
	}
}

void HLCD_VoidSetPosition_4bit(u8 Copy_u8Row ,u8 Copy_u8Column)
{
	if(Copy_u8Row == 0)
	{
		HLCD_VoidSendCommand_4bit(128 + Copy_u8Column);
	}else if(Copy_u8Row == 1)
	{
		HLCD_VoidSendCommand_4bit(128 + 64 + Copy_u8Column);
	}
}

void HLCD_voidWriteSpecialCharacters(u8* Copy_pu8Pattern , u8 Copy_u8PatternNumber , u8 Copy_u8XPos , u8 Copy_u8YPos)
{
	u8 Local_CGRAM_Address , Copy_u8Iterator ;

	/*calculate CG RAM Address whose each block is 8 bytes*/
	 Local_CGRAM_Address = Copy_u8PatternNumber * 8 ;

	 /*Send CG RAM Address command to the LCD*/
	 HLCD_VoidSendCommand_8bit(Local_CGRAM_Address + 64);

	 /*Write the Pattern into CGRAM*/
	 for(Copy_u8Iterator = 0 ; Copy_u8Iterator < 8 ; Copy_u8Iterator++)
	 {
		 HLCD_VoidSendChar_8bit(Copy_pu8Pattern[Copy_u8Iterator]);
	 }

	 /*Go back to the DDRAM to display the Pattern*/
	 HLCD_VoidSetPosition_8bit(Copy_u8XPos, Copy_u8YPos);

	 /*Display the Pattern written in the LCD*/
	 HLCD_VoidSendChar_8bit(Copy_u8PatternNumber);

}


