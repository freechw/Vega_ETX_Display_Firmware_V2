/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    gpio.c
 * @brief   This file provides code for the configuration
 *          of all used GPIO pins.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */
uint8_t buttonCounterLongPress = 0;
uint8_t buttonCounterForward = 0;
uint8_t buttonCounterBackward = 0;
uint8_t buttonCounterBack = 0;
uint8_t buttonCounterOkay = 0;
uint8_t buttonCounterMode = 0;

//#define P2
#define TestBench

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LED_1_Pin|LED_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PCPin PCPin */
  GPIO_InitStruct.Pin = LED_1_Pin|LED_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = IN4_Pin|IN3_Pin|IN2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin
                           PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = IN7_Pin|IN6_Pin|IN9_Pin|IN10_Pin
                          |IN11_Pin|IN12_Pin|IN5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = IN8_Pin|IN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin */
  GPIO_InitStruct.Pin = Btn_Int_1_Pin|Btn_Int_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 2 */
void getInputs() {
//	gpio.buttonInputs.bit.button_hand_Break = HAND_BREAK;
//	gpio.buttonInputs.bit.button_door = DOOR;
//	gpio.buttonInputs.bit.button_high_Beam = HIGH_BEAM;
//
//	gpio.buttonInputs.bit.button_nav_SW1 = NAV_SW1;
//	gpio.buttonInputs.bit.button_nav_SW2 = NAV_SW2;
//	gpio.buttonInputs.bit.button_nav_SW3 = NAV_SW3;
//	gpio.buttonInputs.bit.button_nav_SW4 = NAV_SW4;
//	gpio.buttonInputs.bit.button_nav_SW5 = NAV_SW5;
//
//	gpio.buttonInputs.bit.button_reserve = RESERVE;
//	gpio.buttonInputs.bit.button_turn_L = TURN_L;
//	gpio.buttonInputs.bit.button_turn_R = TURN_R;
//	gpio.buttonInputs.bit.button_park = PARK;
	gpio.buttonInputs.bit.in1 = IN1;
	gpio.buttonInputs.bit.in2 = IN2;
	gpio.buttonInputs.bit.in3 = IN3;
	gpio.buttonInputs.bit.in4 = IN4;
	gpio.buttonInputs.bit.in5 = IN5;
	gpio.buttonInputs.bit.in6 = IN6;
	gpio.buttonInputs.bit.in7 = IN7;
	gpio.buttonInputs.bit.in8 = IN8;
	gpio.buttonInputs.bit.in9 = IN9;
	gpio.buttonInputs.bit.in10 = IN10;
	gpio.buttonInputs.bit.in11 = IN11;
	gpio.buttonInputs.bit.in12 = IN12;

	buttonOkay();
}


#ifdef TestBench
void setInputs() {
//	if (gpio.buttonInputs.bit.in11) //pageUp
//	{
//		hand_Break = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.in10) //pageUp
//	{
//		door = true;
//		HAL_Delay(50);
//	}


	if (gpio.buttonInputs.bit.in7) //pageUp
	{
		buttonCounterForward++;
		if (buttonCounterForward < 2) {
			forward = true;
		}
		else {
			forward = false;
		}
	} else {
		buttonCounterForward = 0;
	}

	if (gpio.buttonInputs.bit.in5) //pageDown
	{
		buttonCounterBackward++;
		if (buttonCounterBackward < 2) {
			backward = true;
		}
		else {
			backward = false;
		}
	} else {
		buttonCounterBackward = 0;
	}

	if (gpio.buttonInputs.bit.in8) //back
	{
		buttonCounterBack++;
		if (buttonCounterBack < 2) {
			back = true;
		}
		else {
			back = false;
		}
	}
	else
	{
		buttonCounterBack = 0;
	}

	if (gpio.buttonInputs.bit.in4) //mode //After fixing the okay button change mode to okay
	{
		buttonCounterMode++;
		if (buttonCounterMode<2) {
			mode = true;
			//_modeChanged = true;
		}
		//else
		//{
			//mode = false;
		//}
	}
	else
	{
		buttonCounterMode = 0;
	}

	if (gpio.buttonInputs.bit.in6 == 1) //okay
	{
		buttonCounterOkay++;
		if (buttonCounterOkay<2) {
			okay = true;
		}
		else
		{
			okay = false;
		}
	}
	else
	{
		buttonCounterOkay = 0;
	}
//	if (gpio.buttonInputs.bit.button_turn_R) {
//		turn_R = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.button_turn_L) {
//		turn_L = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.button_high_Beam) {
//		high_Beam = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.button_park) {
//		park = true;
//		HAL_Delay(50);
//	}
}

void buttonOkay(void) {
	if (gpio.buttonInputs.bit.in6 == 1) {
		buttonCounterLongPress++;
	} else {
		buttonCounterLongPress = 0;
		okay = false;
	}

	if (buttonCounterLongPress >= longPress_Time) {
		longpress = true;
		okay = false;
		buttonCounterLongPress = 0;
	}

}


#endif

#ifdef P2
void setInputs() {
//	if (gpio.buttonInputs.bit.in11) //pageUp
//	{
//		hand_Break = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.in10) //pageUp
//	{
//		door = true;
//		HAL_Delay(50);
//	}

	//P2 Buttons
	//  3 - Okay
	//	4 - Back
	//	5 - Forward
	//	6 - Backward
	//	7 - Mode
	if (gpio.buttonInputs.bit.in5) //pageUp
	{
		buttonCounterForward++;
		if (buttonCounterForward < 2) {
			forward = true;
		}
		else {
			forward = false;
		}
	} else {
		buttonCounterForward = 0;
	}

	if (gpio.buttonInputs.bit.in6) //pageDown
	{
		buttonCounterBackward++;
		if (buttonCounterBackward < 2) {
			backward = true;
		}
		else {
			backward = false;
		}
	} else {
		buttonCounterBackward = 0;
	}

	if (gpio.buttonInputs.bit.in4) //back
	{
		buttonCounterBack++;
		if (buttonCounterBack < 2) {
			back = true;
		}
		else {
			back = false;
		}
	}
	else
	{
		buttonCounterBack = 0;
	}

	if (gpio.buttonInputs.bit.in7) //mode //After fixing the okay button change mode to okay
	{
		buttonCounterMode++;
		if (buttonCounterMode<2) {
			mode = true;
			//_modeChanged = true;
		}
		//else
		//{
			//mode = false;
		//}
	}
	else
	{
		buttonCounterMode = 0;
	}

	if (gpio.buttonInputs.bit.in6 == 3) //okay
	{
		buttonCounterOkay++;
		if (buttonCounterOkay<2) {
			okay = true;
		}
		else
		{
			okay = false;
		}
	}
	else
	{
		buttonCounterOkay = 0;
	}
//	if (gpio.buttonInputs.bit.button_turn_R) {
//		turn_R = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.button_turn_L) {
//		turn_L = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.button_high_Beam) {
//		high_Beam = true;
//		HAL_Delay(50);
//	}
//	if (gpio.buttonInputs.bit.button_park) {
//		park = true;
//		HAL_Delay(50);
//	}
}

void buttonOkay(void) {
	if (gpio.buttonInputs.bit.in6 == 3) {
		buttonCounterLongPress++;
	} else {
		buttonCounterLongPress = 0;
		okay = false;
	}

	if (buttonCounterLongPress >= longPress_Time) {
		longpress = true;
		okay = false;
		buttonCounterLongPress = 0;
	}

}

#endif

/* USER CODE END 2 */
