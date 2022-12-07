/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include"data_structures.h"
#include "gpio.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOC
#define LED_2_Pin GPIO_PIN_1
#define LED_2_GPIO_Port GPIOC
#define IN4_Pin GPIO_PIN_2
#define IN4_GPIO_Port GPIOA
#define IN3_Pin GPIO_PIN_3
#define IN3_GPIO_Port GPIOA
#define IN7_Pin GPIO_PIN_4
#define IN7_GPIO_Port GPIOC
#define IN6_Pin GPIO_PIN_5
#define IN6_GPIO_Port GPIOC
#define IN8_Pin GPIO_PIN_14
#define IN8_GPIO_Port GPIOB
#define IN1_Pin GPIO_PIN_15
#define IN1_GPIO_Port GPIOB
#define IN9_Pin GPIO_PIN_6
#define IN9_GPIO_Port GPIOC
#define IN10_Pin GPIO_PIN_7
#define IN10_GPIO_Port GPIOC
#define IN11_Pin GPIO_PIN_8
#define IN11_GPIO_Port GPIOC
#define IN12_Pin GPIO_PIN_9
#define IN12_GPIO_Port GPIOC
#define IN2_Pin GPIO_PIN_8
#define IN2_GPIO_Port GPIOA
#define IN5_Pin GPIO_PIN_10
#define IN5_GPIO_Port GPIOC
#define Btn_Int_1_Pin GPIO_PIN_6
#define Btn_Int_1_GPIO_Port GPIOB
#define Btn_Int_1_EXTI_IRQn EXTI9_5_IRQn
#define Btn_Int_2_Pin GPIO_PIN_7
#define Btn_Int_2_GPIO_Port GPIOB
#define Btn_Int_2_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */
#define LED_1_Pin GPIO_PIN_0
#define LED_1_GPIO_Port GPIOC
#define LED_2_Pin GPIO_PIN_1
#define LED_2_GPIO_Port GPIOC
#define EEP_CS_Pin GPIO_PIN_4
#define EEP_CS_GPIO_Port GPIOA
#define Nav_SW2_Pin GPIO_PIN_4
#define Nav_SW2_GPIO_Port GPIOC
#define Nav_SW3_Pin GPIO_PIN_5
#define Nav_SW3_GPIO_Port GPIOC
#define Hand_Break_Pin GPIO_PIN_15
#define Hand_Break_GPIO_Port GPIOB
#define Turn_L_Pin GPIO_PIN_6
#define Turn_L_GPIO_Port GPIOC
#define Turn_R_Pin GPIO_PIN_7
#define Turn_R_GPIO_Port GPIOC
#define High_Beam_Pin GPIO_PIN_8
#define High_Beam_GPIO_Port GPIOC
#define Park_Pin GPIO_PIN_9
#define Park_GPIO_Port GPIOC
#define Door_Pin GPIO_PIN_8
#define Door_GPIO_Port GPIOA
#define Reserve_Pin GPIO_PIN_9
#define Reserve_GPIO_Port GPIOA
#define Nav_SW5_Pin GPIO_PIN_10
#define Nav_SW5_GPIO_Port GPIOA
#define Nav_SW1_Pin GPIO_PIN_14
#define Nav_SW1_GPIO_Port GPIOA
#define Nav_SW4_Pin GPIO_PIN_10
#define Nav_SW4_GPIO_Port GPIOC
#define ExInt_1_Pin GPIO_PIN_6
#define ExInt_1_GPIO_Port GPIOB
#define ExInt_1_EXTI_IRQn EXTI9_5_IRQn
#define ExInt_2_Pin GPIO_PIN_7
#define ExInt_2_GPIO_Port GPIOB
#define ExInt_2_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
