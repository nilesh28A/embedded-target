/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include<stdint.h>

int main(void)
{
	uint32_t  volatile *const pClkCtrlReg =   (uint32_t*)0x40023830;
	uint32_t  volatile *const pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t  volatile *const pPortDOutReg =  (uint32_t*)0x40020C14;

	uint32_t volatile *const pPortAModeReg =     (uint32_t*)0x40020000;
	uint32_t const volatile *const pPortAInReg = (uint32_t*)0x40020010;  // programmer should not write (read only)


	//enable the clock for GPOID , GPIOA peripherals in the AHB1ENR
	*pClkCtrlReg |= ( 1 << 3);
	*pClkCtrlReg |= ( 1 << 0);

    //configuring PD12 as output
	*pPortDModeReg &= ~( 3 << 24); //(green)
	*pPortDModeReg &= ~( 3 << 28); //(red)

	//make 24th bit position as 1 (SET)
	*pPortDModeReg |= ( 1 << 24); //(green)
	*pPortDModeReg |= ( 1 << 28); //(red)

	//Configure PA0 & PA1 as input mode (GPIOA MODE REGISTER)

	*pPortAModeReg &= ~(3<<0); //PA0

	while(1)
	{


		//read the pin status of the pin PA1 (GPIOA INPUT DATA REGISTER)
		uint8_t  pinStatus0 = (*pPortAInReg & 0x1); // PA0 zero out all other bits except bit 0



		if(pinStatus0) {
			//turn on the LED
			*pPortDOutReg |= ( 1 << 14); //(red)
			*pPortDOutReg |= ( 1 << 12); //(green)
		}else{
			//turn off the LED

			*pPortDOutReg &= ~( 1 << 14); //(red)
			*pPortDOutReg &= ~( 1 << 12); //(green)
		}

	}

 //// not able to use PA1, PA2, PA3 as a input ...... ???? 

}
