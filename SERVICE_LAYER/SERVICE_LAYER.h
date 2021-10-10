#ifndef SERVICE_LAYER_SERVICE_LAYER_H_
#define SERVICE_LAYER_SERVICE_LAYER_H_


typedef signed short int s16;
typedef unsigned long int u16;
typedef signed long int s32;
typedef unsigned long int u32;
typedef unsigned char u8;
typedef signed char s8;

#define SET_BIT(portname , pinnumber)			 (portname |= (1 << pinnumber))
#define CLR_BIT(portname , pinnumber)		 (portname &= ~(1 << pinnumber))
#define TOGGLE_BIT(portname , pinnumber)	 (portname ^= (1 << pinnumber))
#define GET_BIT(portname , pinnumber)		 ((portname >> pinnumber) &1)


#define WRITE_MOST(command)  	(command & 0xf0)
#define WRITE_LEAST(command)    ((command & 0x0f)<<4)

#define ZERO 0b00111111
#define ONE 0b00000110
#define TWO 0b01011011
#define THREE 0b01001111
#define FOUR 0b01100110
#define FIVE 0b01101101
#define SIX 0b01111101
#define SEVEN 0b00000111
#define EIGHT 0b01111111
#define NINE 0b01101111

enum{
	LOW,
	HIGH
};
enum{
	INPUT,
	OUTPUT
};
enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
};



#endif /* SERVICE_LAYER_SERVICE_LAYER_H_ */
