#include "../SERVICE_LAYER/SERVICE_LAYER.h"
#include "MDIO_Interface.h"
#include "MGIE_Interface.h"
#include "MEXIT_Private.h"
#include <util/delay.h>

/* Enabling and Disabling Peripheral Interrupt for INT0*/
void MEXTI0_voidEnable()
{
	SET_BIT(GICR_REG , GICR_INT0_BIT);
}
void MEXTI0_voidDisable()
{
	CLR_BIT(GICR_REG , GICR_INT0_BIT);
}

/* Enabling and Disabling Peripheral Interrupt for INT1*/
void MEXTI1_voidEnable()
{
	SET_BIT(GICR_REG , GICR_INT1_BIT);
}
void MEXTI1_voidDisable()
{
	CLR_BIT(GICR_REG , GICR_INT1_BIT);
}

/* Enabling and Disabling Peripheral Interrupt for INT2*/
void MEXTI2_voidEnable()
{
	SET_BIT(GICR_REG , GICR_INT2_BIT);
}
void MEXTI2_voidDisable()
{
	CLR_BIT(GICR_REG , GICR_INT2_BIT);
}

/*The MCU Control Register for INT0.*/
void MEXTI0_voidInit()
{
	/* The falling edge of INT0 generates an interrupt request. */
	SET_BIT(MCUCR_REG , MCUCR_ISC01_BIT);
	CLR_BIT(MCUCR_REG , MCUCR_ISC00_BIT);
}

/*The MCU Control Register for INT1.*/
void MEXTI1_voidInit()
{
	/* The falling edge of INT1 generates an interrupt request. */
	SET_BIT(MCUCR_REG , MCUCR_ISC11_BIT);
	CLR_BIT(MCUCR_REG , MCUCR_ISC10_BIT);
}

/*The MCU Control Register for INT2.*/
void MEXTI2_voidInit()
{
	/* The falling edge of INT2 generates an interrupt request. */
	CLR_BIT(MCUCSR_REG , MCUCSR_ISC2_BIT);
}

void __vector_1(void)
{
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN0, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN0, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN1, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN1, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN2, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN2, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN3, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN3, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN4, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN4, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN5, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN5, LOW);
	_delay_ms(500);
}

void __vector_2(void)
{
	MGIE_VoidEnable();
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN5, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN5, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN4, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN4, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN3, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN3, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN2, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN2, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN1, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN1, LOW);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN0, HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_u8PORTB,DIO_u8PIN0, LOW);
	_delay_ms(500);
}

