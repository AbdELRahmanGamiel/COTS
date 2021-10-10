/*
 * HLCD_Interface.h
 *
 *  Created on: Sep 18, 2021
 *      Author: Gamiel
 */

#ifndef HAL_HLCD_INTERFACE_H_
#define HAL_HLCD_INTERFACE_H_


#define _8BITMODE  1
#define _4BITMODE  2

void HLCD_VoidSendChar_8bit(u8 Copy_u8Data);
void HLCD_VoidSendChar_4bit(u8 Copy_u8Data);
void HLCD_VoidSendCommand_8bit(u8 Copy_u8Command);
void HLCD_VoidSendCommand_4bit(u8 Copy_u8Command);
void HLCD_VoidSendStringLCD_8bit(char *Copy_string);
void HLCD_VoidSendStringLCD_4bit(char *Copy_string);
void HLCD_VoidSendnumberLCD_8bit(u32 Copy_u8num);
void HLCD_VoidSendnumberLCD_4bit(u32 Copy_u8num);
void HLCD_VoidSetPosition_8bit(u8 Row ,u8 Column);
void HLCD_VoidSetPosition_4bit(u8 Row ,u8 Column);
void HLCD_VoidInitLCD(char mode);
void HLCD_VoidCLRLCD(char mode);

enum{
	First_Row,
	Second_Row
};




#endif /* HAL_HLCD_INTERFACE_H_ */
