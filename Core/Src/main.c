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
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "bsp_dht21.h"
#include "stdio.h"
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

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define Log 1
#define USER_MAIN_DEBUG 1

#ifdef USER_MAIN_DEBUG
#define user_main_printf(format, ...) printf( format "\r\n", ##__VA_ARGS__)
#define user_main_info(format, ...) printf("[\tmain]info:" format "\r\n", ##__VA_ARGS__)
#define user_main_debug(format, ...) printf("[\tmain]debug:" format "\r\n", ##__VA_ARGS__)
#define user_main_error(format, ...) printf("[\tmain]error:" format "\r\n",##__VA_ARGS__)
#else
#define user_main_printf(format, ...)
#define user_main_info(format, ...)
#define user_main_debug(format, ...)
#define user_main_error(format, ...)
#endif

//		HAL_Delay(500);
//		HAL_ADC_Start(&hadc1); 
//		HAL_ADC_PollForConversion(&hadc1, 50);
//		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC)){
//		AD_Value = HAL_ADC_GetValue(&hadc1); 
//		printf("[\tmain]info:v=%.1fmv\r\n",AD_Value*3300.0/4096); }

int fputc(int ch, FILE *f){
	uint8_t temp[1] = {ch};
	HAL_UART_Transmit(&huart1, temp, 1, 2);//huart1??????????
	return ch;
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint16_t	AD_Value,AD_Value_get;
	uint8_t ADC_Convert_array[2];
//				 high = (s >> 8) & 0xff; //?8?
//  low = s & 0xff; //?8?
//	s = (short) (high << 8) | low; //java short?????
 
			
 
			
	
	
	
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
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  MX_USART1_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
 			HAL_Delay(500);
			/* USER CODE END WHILE */ 
		DHT_data d = DHT_getData(DHT22);
     printf("Temp: %2.1f \r\n", d.temp  );
 
		
		
		
		HAL_ADC_Start(&hadc1); 
		HAL_ADC_PollForConversion(&hadc1, 50);
		if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC)){
		AD_Value = HAL_ADC_GetValue(&hadc1); 
		HAL_SPI_Receive(&hspi1,ADC_Convert_array,1,2);
			 AD_Value_get= ( ADC_Convert_array[1]   <<8 )+ ADC_Convert_array[0]; 
			printf("[\tmain]Slave2:v=%.3f\r\n",AD_Value_get*3.3/4096  );
			printf("[\tmain]Master:v=%.3f\r\n",AD_Value*3.3/4096);
		}

		// ADC_Conert_array[0]=AD_Value*256/4096; 
//			 	printf("[\tmain]infohigh:v=%d \r\n ",ADC_Conert_array[1]); 
//			printf("[\tmain]infolow:v=%d \r\n ",ADC_Conert_array[0]); 
//   	printf("[\tmain]info:v=%.1fmv\r\n ",AD_Value*3300.0/4096); 
//		 HAL_SPI_Transmit(&hspi1, ADC_Conert_array, 1 ,2);
 

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
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

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
