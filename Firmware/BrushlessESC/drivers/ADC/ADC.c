/*!
***     \file	  ADC.c
***     \ingroup  ADC
***     \author   Daniel
***     \date	  9/20/2015 5:55:57 PM
***     \brief    TODO
***
******************************************************************************/

/*=============================================================================
 =======                            INCLUDES                             =======
 =============================================================================*/
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <avr/interrupt.h>
#include "ADC.h"
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
void ADC_Init(void)
{
	ADCSRA = _BV(ADIE)|_BV(ADPS0);
	ADCSRB = 0;
	DIDR0 = _BV(ADC0D);
	ADMUX = _BV(REFS0);
}

void ADC_Enable(void)
{
	ADCSRA |= _BV(ADEN);
}

void ADC_Disable(void)
{
	ADCSRA &= ~_BV(ADEN);
}

void ADC_SelectInput(ADC_Input_t input)
{
	ADMUX = (ADMUX & 0xE0) | input;
}

void ADC_StartConversion(void)
{
	ADCSRA |= _BV(ADSC);
}
/* -----------------------------------------------------
 * --               Private functions                  --
 * ----------------------------------------------------- */
ISR(ADC_vect)
{
	
}