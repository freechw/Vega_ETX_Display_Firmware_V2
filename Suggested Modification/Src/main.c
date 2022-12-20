    // only showing main function to see how I'm calling PollingInit and PollingRoutine function
     
    int main(void)
    {
      /* USER CODE BEGIN 1 */
     
      /* USER CODE END 1 */
     
      /* MCU Configuration--------------------------------------------------------*/
     
      /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
      HAL_Init();
     
      /* USER CODE BEGIN Init */
     
      /* USER CODE END Init */
     
      /* Configure the system clock */
      SystemClock_Config();
     
      /* USER CODE BEGIN SysInit */
     
      /* USER CODE END SysInit */
     
      /* Initialize all configured peripherals */
      MX_GPIO_Init();
      MX_USART2_UART_Init();
      /* USER CODE BEGIN 2 */
     
      /* USER CODE END 2 */
     
      /* Infinite loop */
      /* USER CODE BEGIN WHILE */
      PollingInit();
      while (1)
      {
    	  PollingRoutine();
        /* USER CODE END WHILE */
     
        /* USER CODE BEGIN 3 */
      }
      /* USER CODE END 3 */
    }