/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: HLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-9/2029		 	**************/
/*********************************************************/

/*Preprocessor file guard*/
#ifndef HLCD_CONFIG_H_
#define HLCD_CONFIG_H_


#define HLCD_DATA_PORT		DIO_u8PORTD

#define HLCD_CTRL_PORT		DIO_u8PORTC
#define HLCD_RS_PIN			DIO_u8PIN7
#define HLCD_E_PIN				DIO_u8PIN6

#define _8BITMODE  1
#define _4BITMODE  2

enum{
	First_Row,
	Second_Row
};


#endif
