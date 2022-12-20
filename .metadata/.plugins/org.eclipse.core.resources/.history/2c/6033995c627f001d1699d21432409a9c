/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "can.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "state_machine.h"
#include "test_function.h"
#include "timer.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

//Set TX header before transmitting the data
//Set RX header after transmitting the data
CAN_TxHeaderTypeDef txHeader;
CAN_RxHeaderTypeDef rxHeader;

CAN_TxHeaderTypeDef TxHeader2;
CAN_RxHeaderTypeDef RxHeader2;
//
uint32_t canMailbox;
uint32_t TxMailbox2;
//buffer for transmit and receive
uint8_t canRX[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t canTX[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
//uint8_t espData = {0, 0, 0, 0, 0, 0, 0, 0};

uint8_t TxData2[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
uint8_t RxData2[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

uint8_t counter = 0;
uint8_t counter2 = 0;
uint8_t counterTim = 0;
uint8_t can_Counter = 0;

uint8_t timCounter = 0;
uint8_t timCounter2;
bool  gpioSetFlag = false;

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	HAL_Delay(1000);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_CAN1_Init();
  MX_TIM2_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	txHeader.DLC = 8; //length of data
	txHeader.ExtId = 0; //Extended ID
	txHeader.IDE = CAN_ID_STD;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = 0x42;
	txHeader.TransmitGlobalTime = DISABLE;
	canTX[0] = 0xf3;

	TxHeader2.DLC = 8; //length of data
	TxHeader2.ExtId = 0; //Extended ID
	TxHeader2.IDE = CAN_ID_STD;
	TxHeader2.RTR = CAN_RTR_DATA;
	TxHeader2.StdId = 0x52;
	TxHeader2.TransmitGlobalTime = DISABLE;
	TxData2[0] = 0xf3;
	//HAL_CAN_AddTxMessage(&hcan2, &TxHeader, RxData, &TxMailbox);
	//HAL_CAN1_Config();
	//HAL_CAN2_Config();
	memset(strDATA, 0, 8);
	memset(strDATA2, 0, 10);
	//strData - Display data array
	strDATA[0] = 0x5A;
	strDATA[1] = 0xA5;
	strDATA[2] = 0x05;
	strDATA[3] = 0x82;

	strDATA2[0] = 0x5A;
	strDATA2[1] = 0xA5;
	strDATA2[2] = 0x07;
	strDATA2[3] = 0x82;

	HAL_CAN_Start(&hcan1);
	//HAL_CAN_Start(&hcan2);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
	//HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO1_MSG_PENDING);
	_fireModeEnable = 1;

	HAL_TIM_Base_Start_IT(&htim2);

//	HAL_DMA_RegisterCallback(&hdma_usart3_tx, HAL_DMA_XFER_CPLT_CB_ID,
//			&DMATransferComplete);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	//canTest();
	while (1) {

//		if (_fireModeEnable == 1) {
//			if (!_firePage) {
//				fireModePage();
//				_firePage = true;
//			}
//			fireData();
//			//goto end;
//		}
		counter++;
		counter2++;
		//HAL_Delay(10);

		if (gpioSetFlag) {
			getInputs();
			setInputs();
			gpioSetFlag = false;
			//mainStateMachine();
			counter = 0;

		}
		if (timeout.timeout_0_5s == true) {
			if (counter2 >= 10) {
				//transmit();
				counter2 = 0;
			}
		}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.Prediv1Source = RCC_PREDIV1_SOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  RCC_OscInitStruct.PLL2.PLL2State = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Configure the Systick interrupt time
  */
  __HAL_RCC_PLLI2S_ENABLE();
}

/* USER CODE BEGIN 4 */
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan1) {
	can_Counter++;
	HAL_GPIO_WritePin(GPIOC, LED_1_Pin, GPIO_PIN_SET);
	HAL_CAN_GetRxMessage(hcan1, CAN_RX_FIFO0, &rxHeader, canRX);
	if ((rxHeader.StdId == 0x40) && (rxHeader.IDE == CAN_ID_STD)) {
		EVCU_getData_read_40(canRX);
	}
	if ((rxHeader.StdId == 0x41) && (rxHeader.IDE == CAN_ID_STD)) {
		EVCU_getData_read_41(canRX);
	}
	if ((rxHeader.StdId == 0x43) && (rxHeader.IDE == CAN_ID_STD)) {
		EVCU_getData_read_43(canRX);
	}
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan2) {
	counter2++;
	HAL_GPIO_WritePin(GPIOC, LED_2_Pin, GPIO_PIN_SET);
	HAL_CAN_GetRxMessage(hcan2, CAN_RX_FIFO1, &RxHeader2, RxData2);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (Btn_Int_1_Pin) {
		buttonEn1 = true;
	}
	if (Btn_Int_2_Pin) {
		buttonEn2 = true;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	//Timer ---> 50ms
	tick_count(&timeout);
	gpioSetFlag = true;//50ms
	mainStateMachine();

	//Timer Indicator
	HAL_GPIO_TogglePin(GPIOC, LED_1_Pin);
	timCounter++;

//	if (_fireModeEnable == 1) {
//		if (!_firePage) {
//			fireModePage();
//			_firePage = true;
//		}
//		fireData();
//		//goto end;
//	}
	transmit();

	//gpioSetFlag = true;

	if (timeout.timeout_1s == true) {
		//CAN Transmit Starts After 1s
		EVCU_setData_write(canTX); //errorRead will send using this
		//tick_clear(&timeout);
	}
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart) {

}

void HAL_UART_TxHalfCpltCallback(UART_HandleTypeDef *huart) {

}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
