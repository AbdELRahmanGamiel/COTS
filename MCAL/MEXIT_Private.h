/*
 * MEXIT_private.h
 *
 *  Created on: Oct 9, 2021
 *      Author: Gamiel
 */

#ifndef MCAL_MEXIT_PRIVATE_H_
#define MCAL_MEXIT_PRIVATE_H_


#define MCUCR_REG    *((u8 *)0x55)
#define MCUCSR_REG  *((u8 *)0x54)
#define GICR_REG        *((u8 *)0x5B)
#define GIFR_REG        *((u8 *)0x5A)


void __vector_1(void)  __attribute__((signal));
void __vector_2(void)  __attribute__((signal));

#define GICR_INT0_BIT		6
#define GICR_INT1_BIT		7
#define GICR_INT2_BIT		5

#define MCUCR_ISC00_BIT	0
#define MCUCR_ISC01_BIT	1
#define MCUCR_ISC10_BIT	2
#define MCUCR_ISC11_BIT		3

#define MCUCSR_ISC2_BIT	6


#endif /* MCAL_MEXIT_PRIVATE_H_ */
