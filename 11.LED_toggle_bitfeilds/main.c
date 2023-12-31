 /**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include "main.h"

/*
	uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14; */

int main(void)
{
	RCC_AHB1ENR_t volatile *const pClkCtrlReg   = (RCC_AHB1ENR_t*) 0x40023830;
	GPIOx_MODE_t  volatile *const pPortDModeReg = (GPIOx_MODE_t*) 0x40020C00;
	GPIOx_ODR_t   volatile *const pPortDOutReg  = (GPIOx_ODR_t*) 0x40020C14;

	//1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	pClkCtrlReg->gpiod_en = 1;


	//2. configure the mode of the IO pin as output
	pPortDModeReg->pin_12 = 1; //(green)
	pPortDModeReg->pin_13 = 1; //(orange)
	pPortDModeReg->pin_14 = 1; //(red)
	pPortDModeReg->pin_15 = 1; //(blue)

	while(1)
	{
		//Set 12th bit of the output data register to make I/O pin-12 as HIGH
		pPortDOutReg->pin_12  = 1; //(green)
		pPortDOutReg->pin_13  = 1; //(orange)
		pPortDOutReg->pin_14  = 1; //(red)
		pPortDOutReg->pin_15  = 1; //(blue)


		//introduce small human observable delay
		//This loop executes for 300K times
		for(uint32_t i=0 ; i < 300000 ; i++ );

		//Reset 12th bit of the output data register to make I/O pin-12 as LOW
		pPortDOutReg->pin_12  = 0; //(green)
		pPortDOutReg->pin_13  = 0; //(orange)
		pPortDOutReg->pin_14  = 0; //(red)
		pPortDOutReg->pin_15  = 0; //(blue)

		for(uint32_t i=0 ; i < 300000 ; i++ );
	}

                      // all 4 LEDs at time blinking.....
	for(;;);
}
