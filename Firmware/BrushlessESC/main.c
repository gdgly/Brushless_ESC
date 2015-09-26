/*!
***     \file	  main.c
***     \ingroup  main
***     \author   Daniel
***     \date	  9/19/2015 12:38:27 PM
***     \brief    TODO
***
******************************************************************************/

/*=============================================================================
 =======                            INCLUDES                             =======
 =============================================================================*/

#include "drivers/ACP/ACP.h"
#include "drivers/ADC/ADC.h"
#include "drivers/ICP/ICP.h"
#include "drivers/PWM/PWM.h"
#include "drivers/SPI/SPI_slave.h"
#include "EngineSpeedController.h"
/*=============================================================================
 =======               DEFINES & MACROS FOR GENERAL PURPOSE              =======
 =============================================================================*/

/*=============================================================================
 =======                       CONSTANTS  &  TYPES                       =======
 =============================================================================*/

/*=============================================================================
 =======                VARIABLES & MESSAGES & RESSOURCEN                =======
 =============================================================================*/

/*=============================================================================
 =======                              METHODS                           =======
 =============================================================================*/

/* -----------------------------------------------------
 * --               Public functions                  --
 * ----------------------------------------------------- */
int main(void)
{
	ACP_Init();
	ADC_Init();
	ICP_Init();
	PWM_Init();
	SPI_SlaveInit();
	BLDC_Init();

	BLDC_Start();

	do 
	{
		BLDC_StateMachine();
	} while (1);
}
/* -----------------------------------------------------
 * --               Private functions                  --
 * ----------------------------------------------------- */