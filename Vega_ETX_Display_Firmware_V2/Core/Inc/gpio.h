/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <stdlib.h>
#include <stm32f1xx_hal.h>
#include <string.h>
#include <stdbool.h>
#include"data_structures.h"
/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
//#define HAND_BREAK HAL_GPIO_ReadPin(GPIOB, Hand_Break_Pin)
//#define DOOR HAL_GPIO_ReadPin(GPIOA, Door_Pin)
//#define RESERVE HAL_GPIO_ReadPin(GPIOA, Reserve_Pin)
//
//#define NAV_SW1 HAL_GPIO_ReadPin(GPIOB, Nav_SW1_Pin)
//#define NAV_SW2 HAL_GPIO_ReadPin(GPIOC, Nav_SW2_Pin)
//#define NAV_SW3 HAL_GPIO_ReadPin(GPIOC, Nav_SW3_Pin)
//#define NAV_SW4 HAL_GPIO_ReadPin(GPIOC, Nav_SW4_Pin)
//#define NAV_SW5 HAL_GPIO_ReadPin(GPIOA, Nav_SW5_Pin)
//
//#define TURN_L HAL_GPIO_ReadPin(GPIOC, Turn_L_Pin)
//#define TURN_R HAL_GPIO_ReadPin(GPIOC, Turn_R_Pin)
//#define HIGH_BEAM HAL_GPIO_ReadPin(GPIOC, High_Beam_Pin)
//#define PARK HAL_GPIO_ReadPin(GPIOC, Park_Pin)
#define IN1 HAL_GPIO_ReadPin(GPIOB, IN1_Pin)
#define IN2 HAL_GPIO_ReadPin(GPIOA, IN2_Pin)
#define IN3 HAL_GPIO_ReadPin(GPIOA, IN3_Pin)
#define IN4 HAL_GPIO_ReadPin(GPIOA, IN4_Pin)
#define IN5 HAL_GPIO_ReadPin(GPIOC, IN5_Pin)
#define IN6 HAL_GPIO_ReadPin(GPIOC, IN6_Pin)
#define IN7 HAL_GPIO_ReadPin(GPIOC, IN7_Pin)
#define IN8 HAL_GPIO_ReadPin(GPIOB, IN8_Pin)
#define IN9 HAL_GPIO_ReadPin(GPIOC, IN9_Pin)
#define IN10 HAL_GPIO_ReadPin(GPIOC, IN10_Pin)
#define IN11 HAL_GPIO_ReadPin(GPIOC, IN11_Pin)
#define IN12 HAL_GPIO_ReadPin(GPIOC, IN12_Pin)
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
extern void getInputs();
extern void setInputs();
extern void buttonOkay(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

