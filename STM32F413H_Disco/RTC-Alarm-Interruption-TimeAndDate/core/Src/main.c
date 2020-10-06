/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
#include "STM32F413H-Discovery/stm32f413h_discovery_lcd.h"
#include "Fonts/fonts.h"
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
FMPI2C_HandleTypeDef hfmpi2c1;

RTC_HandleTypeDef hrtc;

UART_HandleTypeDef huart10;
UART_HandleTypeDef huart6;

SRAM_HandleTypeDef hsram1;
SRAM_HandleTypeDef hsram2;

/* USER CODE BEGIN PV */
RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};
  RTC_AlarmTypeDef sAlarm = {0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_FMPI2C1_Init(void);
static void MX_FSMC_Init(void);
static void MX_UART10_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_RTC_Init(void);
/* USER CODE BEGIN PFP */
static void InitializeScreen(void);
static void getTimeAndDate(void);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc);
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

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_FMPI2C1_Init();
  MX_FSMC_Init();
  MX_UART10_Init();
  MX_USART6_UART_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */
  InitializeScreen();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  if(RTC->ISR & RTC_FLAG_ALRAF)
	  {
		  HAL_GPIO_TogglePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin);
		  	HAL_Delay(200);
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
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_HSE
                              |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RTC|RCC_PERIPHCLK_FMPI2C1;
  PeriphClkInitStruct.RTCClockSelection = RCC_RTCCLKSOURCE_LSE;
  PeriphClkInitStruct.Fmpi2c1ClockSelection = RCC_FMPI2C1CLKSOURCE_HSI;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief FMPI2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_FMPI2C1_Init(void)
{

  /* USER CODE BEGIN FMPI2C1_Init 0 */

  /* USER CODE END FMPI2C1_Init 0 */

  /* USER CODE BEGIN FMPI2C1_Init 1 */

  /* USER CODE END FMPI2C1_Init 1 */
  hfmpi2c1.Instance = FMPI2C1;
  hfmpi2c1.Init.Timing = 0x00303D5B;
  hfmpi2c1.Init.OwnAddress1 = 0;
  hfmpi2c1.Init.AddressingMode = FMPI2C_ADDRESSINGMODE_7BIT;
  hfmpi2c1.Init.DualAddressMode = FMPI2C_DUALADDRESS_DISABLE;
  hfmpi2c1.Init.OwnAddress2 = 0;
  hfmpi2c1.Init.OwnAddress2Masks = FMPI2C_OA2_NOMASK;
  hfmpi2c1.Init.GeneralCallMode = FMPI2C_GENERALCALL_DISABLE;
  hfmpi2c1.Init.NoStretchMode = FMPI2C_NOSTRETCH_DISABLE;
  if (HAL_FMPI2C_Init(&hfmpi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter 
  */
  if (HAL_FMPI2CEx_ConfigAnalogFilter(&hfmpi2c1, FMPI2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FMPI2C1_Init 2 */

  /* USER CODE END FMPI2C1_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};
  RTC_AlarmTypeDef sAlarm = {0};

  /* USER CODE BEGIN RTC_Init 1 */

  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only 
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */
    
  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date 
  */
  sTime.Hours = 15;
  sTime.Minutes = 30;
  sTime.Seconds = 15;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_SUNDAY;
  sDate.Month = RTC_MONTH_OCTOBER;
  sDate.Date = 4;
  sDate.Year = 20;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable the Alarm A 
  */
  sAlarm.AlarmTime.Hours = 15;
  sAlarm.AlarmTime.Minutes = 30;
  sAlarm.AlarmTime.Seconds = 30;
  sAlarm.AlarmTime.SubSeconds = 0;
  sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
  sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_WEEKDAY;
  sAlarm.AlarmDateWeekDay = RTC_WEEKDAY_SUNDAY;
  sAlarm.Alarm = RTC_ALARM_A;
  if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable the WakeUp 
  */
  if (HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 0, RTC_WAKEUPCLOCK_RTCCLK_DIV16) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RTC_Init 2 */

  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief UART10 Initialization Function
  * @param None
  * @retval None
  */
static void MX_UART10_Init(void)
{

  /* USER CODE BEGIN UART10_Init 0 */

  /* USER CODE END UART10_Init 0 */

  /* USER CODE BEGIN UART10_Init 1 */

  /* USER CODE END UART10_Init 1 */
  huart10.Instance = UART10;
  huart10.Init.BaudRate = 115200;
  huart10.Init.WordLength = UART_WORDLENGTH_8B;
  huart10.Init.StopBits = UART_STOPBITS_1;
  huart10.Init.Parity = UART_PARITY_NONE;
  huart10.Init.Mode = UART_MODE_TX_RX;
  huart10.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart10.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart10) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN UART10_Init 2 */

  /* USER CODE END UART10_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LED1_RED_Pin|MEMS_LED_Pin|LCD_BL_CTRL_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED2_GREEN_GPIO_Port, LED2_GREEN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LCD_CTP_RST_Pin|LCD_TE_Pin|WIFI_WKUP_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOG, USB_OTG_FS_PWR_EN_Pin|ARD_D2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : QSPI_BK1_IO2_Pin */
  GPIO_InitStruct.Pin = QSPI_BK1_IO2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF9_QSPI;
  HAL_GPIO_Init(QSPI_BK1_IO2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED1_RED_Pin MEMS_LED_Pin LCD_BL_CTRL_Pin */
  GPIO_InitStruct.Pin = LED1_RED_Pin|MEMS_LED_Pin|LCD_BL_CTRL_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D5_Pin */
  GPIO_InitStruct.Pin = ARD_D5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF3_TIM9;
  HAL_GPIO_Init(ARD_D5_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : QSPI_BK1_IO0_Pin QSPI_BK1_IO1_Pin */
  GPIO_InitStruct.Pin = QSPI_BK1_IO0_Pin|QSPI_BK1_IO1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D3_Pin */
  GPIO_InitStruct.Pin = ARD_D3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
  HAL_GPIO_Init(ARD_D3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ARD_A0_Pin ARD_A5_Pin */
  GPIO_InitStruct.Pin = ARD_A0_Pin|ARD_A5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : CTP_INT_Pin */
  GPIO_InitStruct.Pin = CTP_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(CTP_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CODEC_ext_SD_Pin */
  GPIO_InitStruct.Pin = CODEC_ext_SD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI2;
  HAL_GPIO_Init(CODEC_ext_SD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CODEC_SD_Pin */
  GPIO_InitStruct.Pin = CODEC_SD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CODEC_SD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B_USER_Pin */
  GPIO_InitStruct.Pin = B_USER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B_USER_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ARD_A1_Pin ARD_A2_Pin ARD_D8_Pin ARD_A3_Pin */
  GPIO_InitStruct.Pin = ARD_A1_Pin|ARD_A2_Pin|ARD_D8_Pin|ARD_A3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : CODEC_MCK_Pin */
  GPIO_InitStruct.Pin = CODEC_MCK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CODEC_MCK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SD_CMD_Pin */
  GPIO_InitStruct.Pin = SD_CMD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_SDIO;
  HAL_GPIO_Init(SD_CMD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DFSDM2_DATIN1_Pin */
  GPIO_InitStruct.Pin = DFSDM2_DATIN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF7_DFSDM2;
  HAL_GPIO_Init(DFSDM2_DATIN1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED2_GREEN_Pin */
  GPIO_InitStruct.Pin = LED2_GREEN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED2_GREEN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D6_Pin */
  GPIO_InitStruct.Pin = ARD_D6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM3;
  HAL_GPIO_Init(ARD_D6_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_A4_Pin */
  GPIO_InitStruct.Pin = ARD_A4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ARD_A4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : QSPI_CLK_Pin */
  GPIO_InitStruct.Pin = QSPI_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF9_QSPI;
  HAL_GPIO_Init(QSPI_CLK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : SD_Detect_Pin */
  GPIO_InitStruct.Pin = SD_Detect_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SD_Detect_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ARD_D15_Pin ARD_D14_Pin */
  GPIO_InitStruct.Pin = ARD_D15_Pin|ARD_D14_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C2;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D13_Pin */
  GPIO_InitStruct.Pin = ARD_D13_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_SPI3;
  HAL_GPIO_Init(ARD_D13_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_CTP_RST_Pin LCD_TE_Pin WIFI_WKUP_Pin */
  GPIO_InitStruct.Pin = LCD_CTP_RST_Pin|LCD_TE_Pin|WIFI_WKUP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : QSPI_BK1_IO3_Pin */
  GPIO_InitStruct.Pin = QSPI_BK1_IO3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF9_QSPI;
  HAL_GPIO_Init(QSPI_BK1_IO3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : QSPI_BK1_NCS_Pin */
  GPIO_InitStruct.Pin = QSPI_BK1_NCS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(QSPI_BK1_NCS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USB_OTG_FS_OVRCR_Pin CODEC_INT_Pin */
  GPIO_InitStruct.Pin = USB_OTG_FS_OVRCR_Pin|CODEC_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : USB_OTG_FS_PWR_EN_Pin ARD_D2_Pin */
  GPIO_InitStruct.Pin = USB_OTG_FS_PWR_EN_Pin|ARD_D2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

  /*Configure GPIO pins : SD_D0_Pin SD_D1_Pin SD_D2_Pin SD_D3_Pin 
                           SD_CLK_Pin */
  GPIO_InitStruct.Pin = SD_D0_Pin|SD_D1_Pin|SD_D2_Pin|SD_D3_Pin 
                          |SD_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF12_SDIO;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : DFSDM1_CKOUT_Pin */
  GPIO_InitStruct.Pin = DFSDM1_CKOUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_DFSDM1;
  HAL_GPIO_Init(DFSDM1_CKOUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USB_OTG_FS_ID_Pin USB_OTG_FS_DM_Pin USB_OTG_FS_DP_Pin */
  GPIO_InitStruct.Pin = USB_OTG_FS_ID_Pin|USB_OTG_FS_DM_Pin|USB_OTG_FS_DP_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF10_OTG_FS;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D10_Pin */
  GPIO_InitStruct.Pin = ARD_D10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(ARD_D10_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DFSDM2_CKOUT_Pin */
  GPIO_InitStruct.Pin = DFSDM2_CKOUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF3_DFSDM2;
  HAL_GPIO_Init(DFSDM2_CKOUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CODEC_CK_Pin */
  GPIO_InitStruct.Pin = CODEC_CK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CODEC_CK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DFSDM1_DATIN1_Pin */
  GPIO_InitStruct.Pin = DFSDM1_DATIN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_DFSDM1;
  HAL_GPIO_Init(DFSDM1_DATIN1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : ARD_D12_Pin ARD_D11_Pin */
  GPIO_InitStruct.Pin = ARD_D12_Pin|ARD_D11_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D4_Pin */
  GPIO_InitStruct.Pin = ARD_D4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ARD_D4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DFSDM2_DATIN7_Pin */
  GPIO_InitStruct.Pin = DFSDM2_DATIN7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_DFSDM2;
  HAL_GPIO_Init(DFSDM2_DATIN7_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ARD_D9_Pin */
  GPIO_InitStruct.Pin = ARD_D9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF2_TIM4;
  HAL_GPIO_Init(ARD_D9_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CODEC_WS_Pin */
  GPIO_InitStruct.Pin = CODEC_WS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CODEC_WS_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

}

/* FSMC initialization function */
static void MX_FSMC_Init(void)
{

  /* USER CODE BEGIN FSMC_Init 0 */

  /* USER CODE END FSMC_Init 0 */

  FSMC_NORSRAM_TimingTypeDef Timing = {0};

  /* USER CODE BEGIN FSMC_Init 1 */

  /* USER CODE END FSMC_Init 1 */

  /** Perform the SRAM1 memory initialization sequence
  */
  hsram1.Instance = FSMC_NORSRAM_DEVICE;
  hsram1.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram1.Init */
  hsram1.Init.NSBank = FSMC_NORSRAM_BANK1;
  hsram1.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram1.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram1.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hsram1.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram1.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram1.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram1.Init.WriteOperation = FSMC_WRITE_OPERATION_DISABLE;
  hsram1.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram1.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hsram1.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram1.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram1.Init.ContinuousClock = FSMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  hsram1.Init.WriteFifo = FSMC_WRITE_FIFO_ENABLE;
  hsram1.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 15;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 255;
  Timing.BusTurnAroundDuration = 15;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_SRAM_Init(&hsram1, &Timing, NULL) != HAL_OK)
  {
    Error_Handler( );
  }

  /** Perform the SRAM2 memory initialization sequence
  */
  hsram2.Instance = FSMC_NORSRAM_DEVICE;
  hsram2.Extended = FSMC_NORSRAM_EXTENDED_DEVICE;
  /* hsram2.Init */
  hsram2.Init.NSBank = FSMC_NORSRAM_BANK3;
  hsram2.Init.DataAddressMux = FSMC_DATA_ADDRESS_MUX_DISABLE;
  hsram2.Init.MemoryType = FSMC_MEMORY_TYPE_SRAM;
  hsram2.Init.MemoryDataWidth = FSMC_NORSRAM_MEM_BUS_WIDTH_16;
  hsram2.Init.BurstAccessMode = FSMC_BURST_ACCESS_MODE_DISABLE;
  hsram2.Init.WaitSignalPolarity = FSMC_WAIT_SIGNAL_POLARITY_LOW;
  hsram2.Init.WaitSignalActive = FSMC_WAIT_TIMING_BEFORE_WS;
  hsram2.Init.WriteOperation = FSMC_WRITE_OPERATION_ENABLE;
  hsram2.Init.WaitSignal = FSMC_WAIT_SIGNAL_DISABLE;
  hsram2.Init.ExtendedMode = FSMC_EXTENDED_MODE_DISABLE;
  hsram2.Init.AsynchronousWait = FSMC_ASYNCHRONOUS_WAIT_DISABLE;
  hsram2.Init.WriteBurst = FSMC_WRITE_BURST_DISABLE;
  hsram2.Init.ContinuousClock = FSMC_CONTINUOUS_CLOCK_SYNC_ONLY;
  hsram2.Init.WriteFifo = FSMC_WRITE_FIFO_ENABLE;
  hsram2.Init.PageSize = FSMC_PAGE_SIZE_NONE;
  /* Timing */
  Timing.AddressSetupTime = 15;
  Timing.AddressHoldTime = 15;
  Timing.DataSetupTime = 255;
  Timing.BusTurnAroundDuration = 15;
  Timing.CLKDivision = 16;
  Timing.DataLatency = 17;
  Timing.AccessMode = FSMC_ACCESS_MODE_A;
  /* ExtTiming */

  if (HAL_SRAM_Init(&hsram2, &Timing, NULL) != HAL_OK)
  {
    Error_Handler( );
  }

  /* USER CODE BEGIN FSMC_Init 2 */

  /* USER CODE END FSMC_Init 2 */
}

/* USER CODE BEGIN 4 */
void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
{
	UNUSED(hrtc);
	getTimeAndDate();
	BSP_LCD_DisplayStringAt(10, 140, (uint8_t*)"Alarm set", CENTER_MODE);
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	getTimeAndDate();
}
void InitializeScreen(void)
{
	BSP_LCD_InitEx(LCD_ORIENTATION_LANDSCAPE_ROT180);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_SetFont(&Font12);
	BSP_LCD_DisplayStringAt(5, 50, (uint8_t*)"RTC & Alarm", CENTER_MODE);
	HAL_Delay(1000);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
}
void getTimeAndDate(void)
{
	HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
	HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);

	/*time*/
	char TimBuff[12];
	if(RTC->CR & RTC_CR_FMT)
	{
		//if(sTime.Hours>12)
		//	sTime.Hours-=12;
		if(RTC_TR_PM)
			sprintf(TimBuff,"%.2i:%.2i:%.2i %s",sTime.Hours,sTime.Minutes,sTime.Seconds,"PM");
		else
			sprintf(TimBuff,"%.2i:%.2i:%.2i %s",sTime.Hours,sTime.Minutes,sTime.Seconds,"AM");
	}
	else
		sprintf(TimBuff,"%.2i:%.2i:%.2i",sTime.Hours,sTime.Minutes,sTime.Seconds);
	/*if(!(RTC->CR & RTC_CR_FMT))
		RTC->CR = 1<<RTC_CR_FMT;
	else
		RTC->CR &=~RTC_CR_FMT;*/
	/*date*/
	char DatBuff[20];
	sprintf(DatBuff, "%.2i/%.2i/20%i", sDate.Date,sDate.Month,sDate.Year);
	switch(sDate.WeekDay)
	{
	case 1:
		strcat(DatBuff," Monday\0");
		break;
	case 2:
		strcat(DatBuff," Tuesday\0");
		break;
	case 3:
		strcat(DatBuff," Wednesday\0");
		break;
	case 4:
		strcat(DatBuff," Thursday\0");
		break;
	case 5:
		strcat(DatBuff," Friday\0");
		break;
	case 6:
		strcat(DatBuff," Saturday\0");
		break;
	case 7:
		strcat(DatBuff," Sunday\0");
		break;
	}
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	BSP_LCD_DisplayStringAt(10, 100, (uint8_t*)TimBuff, CENTER_MODE);
	BSP_LCD_DisplayStringAt(5, 120, (uint8_t*)DatBuff, CENTER_MODE);
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
