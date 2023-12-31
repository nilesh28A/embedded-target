/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	uint32_t *pClkCtrlReg =   (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =  (uint32_t*)0x40020C14;

	//1. enable the clock for GPOID peripheral in the AHB1ENR (SET the 3rd bit position)
	*pClkCtrlReg |= ( 1 << 3);

	//2. configure the mode of the IO pin as output
	//a. clear the 24th and 25th bit positions (CLEAR)
	*pPortDModeReg &= ~( 3 << 24); //(green)
	*pPortDModeReg &= ~( 3 << 26); //(orange)
	*pPortDModeReg &= ~( 3 << 28); //(red)
	*pPortDModeReg &= ~( 3 << 30); //(blue)

	//b. make 24th bit position as 1 (SET)
	*pPortDModeReg |= ( 1 << 24); //(green)
	*pPortDModeReg |= ( 1 << 26); //(orange)
	*pPortDModeReg |= ( 1 << 28); //(red)
	*pPortDModeReg |= ( 1 << 30); //(blue)

	while(1)
	{
		*pPortDOutReg |= ( 1 << 13); //(orange)
		*pPortDOutReg |= ( 1 << 14); //(red)
		*pPortDOutReg |= ( 1 << 15); //(blue)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg &= ~( 1 << 13); //(orange)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg |= ( 1 << 13); //(orange)
		*pPortDOutReg &= ~( 1 << 14); //(red)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg &= ~( 1 << 13); //(orange)
		*pPortDOutReg &= ~( 1 << 15); //(blue)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg |= ( 1 << 13); //(orange)
		*pPortDOutReg |= ( 1 << 14); //(red)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg &= ~( 1 << 13); //(orange)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg |= ( 1 << 13); //(orange)
		*pPortDOutReg &= ~( 1 << 14); //(red)
		*pPortDOutReg |= ( 1 << 15); //(blue)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg &= ~( 1 << 13); //(orange)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg |= ( 1 << 13); //(orange)
		*pPortDOutReg |= ( 1 << 14); //(red)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg &= ~( 1 << 13); //(orange)
		*pPortDOutReg &= ~( 1 << 15); //(blue)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg |= ( 1 << 13); //(orange)
		*pPortDOutReg &= ~( 1 << 14); //(red)
		for(uint32_t i=0 ; i < 300000 ; i++ );

		*pPortDOutReg &= ~( 1 << 13); //(orange)
		for(uint32_t i=0 ; i < 300000 ; i++ );
	}

}
