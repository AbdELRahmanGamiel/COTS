#include "../SERVICE_LAYER/SERVICE_LAYER.h"
#include "MGIE_Private.h"

/* Enabling the global Interrupt */
void MGIE_VoidEnable()
{
	SET_BIT(SREG_REG , GIE_BIT);
}

/* Disabling the global Interrupt */
void MGIE_VoidDisable()
{
	CLR_BIT(SREG_REG , GIE_BIT);
}
