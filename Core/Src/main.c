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
#include "stdio.h"

//#include "bsp_dht21.h"
#include "stdio.h"
#include "w5500.h"
#include "socket.h"
#include "wizchip_conf.h"
#include "loopback.h"



/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

enum
{
  TRANSFER_WAIT,
  TRANSFER_COMPLETE,
  TRANSFER_ERROR
};
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
wiz_NetInfo gWIZNETINFO = { .mac = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05},
                            .ip = {192, 168, 1, 88},
                            .sn = {255, 255, 255, 0},
                            .gw = {192, 168, 1, 1},
                            .dns = {8, 8, 8, 8},
                            .dhcp = NETINFO_STATIC };

uint8_t gDATABUF[2048];
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
uint16_t ADC_Receive_array[41];
uint8_t Spi_Buff[82];
uint8_t j,k;
void W5500_Select(void);
void W5500_Unselect(void);
void W5500_ReadBuff(uint8_t* buff, uint16_t len);
void W5500_WriteBuff(uint8_t* buff, uint16_t len);
uint8_t W5500_ReadByte(void);
void W5500_WriteByte(uint8_t byte);
void network_init(void);

#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))

#define BUFFERSIZE                       (COUNTOF(aTxBuffer) - 1)

/* Buffer used for transmission */
uint8_t aTxBuffer[82] ;

/* Buffer used for reception */
uint8_t aRxBuffer[81];

/* transfer state */
__IO uint32_t wTransferState = TRANSFER_WAIT;

#define SOCK_TCPS        0
#define SOCK_UDPS        1
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void W5500_Select(void) {
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
}

void W5500_Unselect(void) {
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
}

void W5500_ReadBuff(uint8_t* buff, uint16_t len) {
  HAL_SPI_Receive(&hspi2, buff, len, HAL_MAX_DELAY);
}

void W5500_WriteBuff(uint8_t* buff, uint16_t len) {
}

uint8_t W5500_ReadByte(void) {
  uint8_t byte;
  W5500_ReadBuff(&byte, sizeof(byte));
  return byte;
}

void W5500_WriteByte(uint8_t byte) {
  W5500_WriteBuff(&byte, sizeof(byte));
}

void network_init(void)
{
  uint8_t tmpstr[6];
  ctlnetwork(CN_SET_NETINFO, (void*)&gWIZNETINFO);
  ctlnetwork(CN_GET_NETINFO, (void*)&gWIZNETINFO);

  // Display Network Information
  ctlwizchip(CW_GET_ID,(void*)tmpstr);
  printf("\r\n=== %s NET CONF ===\r\n",(char*)tmpstr);
  printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\r\n",gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
  printf("SIP: %d.%d.%d.%d\r\n", gWIZNETINFO.ip[0],gWIZNETINFO.ip[1],gWIZNETINFO.ip[2],gWIZNETINFO.ip[3]);
  printf("GAR: %d.%d.%d.%d\r\n", gWIZNETINFO.gw[0],gWIZNETINFO.gw[1],gWIZNETINFO.gw[2],gWIZNETINFO.gw[3]);
  printf("SUB: %d.%d.%d.%d\r\n", gWIZNETINFO.sn[0],gWIZNETINFO.sn[1],gWIZNETINFO.sn[2],gWIZNETINFO.sn[3]);
  printf("DNS: %d.%d.%d.%d\r\n", gWIZNETINFO.dns[0],gWIZNETINFO.dns[1],gWIZNETINFO.dns[2],gWIZNETINFO.dns[3]);
  printf("======================\r\n");
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif
PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
  return ch;
}
//static uint16_t Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint16_t BufferLength);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t tmp;
  int32_t retr = 0;
  uint8_t memsize[2][8] = {{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
//  Spi_Buff[]=0;
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART1_UART_Init();
  MX_SPI2_Init();
  MX_ADC1_Init();
  MX_ADC3_Init();
  /* USER CODE BEGIN 2 */
  /*##-1- Start the Full Duplex Communication process ############
   * ############*/
  /* While the SPI in TransmitReceive process, user can transmit data through
     "aTxBuffer" buffer & receive data through "aRxBuffer" */
//  printf("y1");

    reg_wizchip_cs_cbfunc(W5500_Select, W5500_Unselect);
    reg_wizchip_spi_cbfunc(W5500_ReadByte, W5500_WriteByte);
    reg_wizchip_spiburst_cbfunc(W5500_ReadBuff, W5500_WriteBuff);



    /* WIZCHIP SOCKET Buffer initialize */
    if(ctlwizchip(CW_INIT_WIZCHIP,(void*)memsize) == -1)
    {
       printf("WIZCHIP Initialized fail.\r\n");
       while(1);
    }

    /* PHY link status check */
    do
    {
       if(ctlwizchip(CW_GET_PHYLINK, (void*)&tmp) == -1)
          printf("Unknown PHY Link stauts.\r\n");
    }while(tmp == PHY_LINK_OFF);
  	printf("SOCKET ERROR =1");
    network_init();


//  HAL_SPI_Receive_IT(&hspi1,(uint8_t *)Spi_Buff,sizeof((uint8_t *)Spi_Buff));
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
//  printf("init7 \r\n");

//	  ,HAL_MAX_DELAY
//	  HAL_SPI_Receive_DMA(&hspi1,(uint8_t *)Spi_Buff,sizeof(Spi_Buff));



//	  HAL_SPI_Receive_IT(&hspi1,(uint8_t *)Spi_Buff,sizeof(Spi_Buff));

//	  printf("size = %d \r\n", sizeof(Spi_Buff));_DMA
//      for (j = 0; j < 82; j++)
//      {
//        printf("SPIbuffer[%d] = %d \r\n", j, Spi_Buff[j]);
//        HAL_Delay(1);
//      }
//	  HAL_Delay(900);


//
//	  for (j = 0,k=0; j < 41; j++,k=k+2){
//		  ADC_Receive_array[j]= (uint16_t)(Spi_Buff[k+1]<<8)|Spi_Buff[k];
//		  printf("ADC_Receive_array[%d] = %d \r\n", j, ADC_Receive_array[j]);
//	  }

//	  if (HAL_SPI_TransmitReceive_DMA(&hspi1, (uint8_t *)aTxBuffer, (uint8_t *)aRxBuffer, BUFFERSIZE) != HAL_OK)
//	    {
//	      /* Transfer error in transmission process */
//	  	  printf("no1");
//	      Error_Handler();
//	    }
//
//	    /*##-2- Wait for the end of the transfer ###################################*/
//	    /*  Before starting a new communication transfer, you must wait the callback call
//	        to get the transfer complete confirmation or an error detection.
//	        For simplicity reasons, this example is just waiting till the end of the
//	        transfer, but application may perform other tasks while transfer operation
//	        is ongoing. */
//	    while (wTransferState == TRANSFER_WAIT)
//	    {printf("wait");
//	    }
//	    for (j = 0; j < 5; j++)
//	    {
//	      printf("SPIbuffer[%d] = %d \r\n", j, aRxBuffer[j]);
//	      HAL_Delay(1);
//	    }
//	    HAL_Delay(500);
//	    switch (wTransferState)
//	    {
//	      case TRANSFER_COMPLETE :
//	        /*##-3- Compare the sent and received buffers ##############################*/
//	        if (Buffercmp((uint8_t *)aTxBuffer, (uint8_t *)aRxBuffer, BUFFERSIZE))
//	        {printf("\n translate");
//	          /* Processing Error */
//	          Error_Handler();
//	        }
//	        break;
//	      default :
//	        Error_Handler();
//	        break;
//	    }
//	          for (j = 0; j < 5; j++)
//	          {
//	            printf("SPIbuffer[%d] = %d \r\n", j, aRxBuffer[j]);
//	            HAL_Delay(1);
//	          }
//	          HAL_Delay(500);
	  		if( (retr = loopback_udps(SOCK_UDPS, gDATABUF, 3000)) < 0) {
	  			printf("SOCKET ERROR : %ld\r\n", retr);
	  		}




	      //	  HAL_SPI_Receive_DMA(&hspi1, (uint16_t *)ADC_Receive_array,41);
	      //	  	      for (j = 0; j < 41; j++)
	      //	  	      {
	      //	  	        printf("ADC_Receive_array[%d] = %ld \r\n", j, ADC_Receive_array[j]);
	      //	  	        HAL_Delay(10);
	      //	  	      }
	      //	  	      HAL_Delay(550);

	      //	  HAL_SPI_Receive_DMA(&hspi1,(uint8_t *)Spi_Buff,82);
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
//void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
//{
//	if (hspi == &hspi1)
//	{
//		HAL_SPI_Transmit(&hspi1,(uint8_t *)Spi_Buff, sizeof((uint8_t *)Spi_Buff), 0xFFFF);
//		HAL_SPI_Receive_IT(&hspi1, (uint8_t *)Spi_Buff, sizeof((uint8_t *)Spi_Buff));
//	}
//}
//



//void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
//{
//	if (hspi == &hspi1)
//	{
//		HAL_SPI_Transmit(&hspi1, (uint8_t *)Spi_Buff, sizeof((uint8_t *)Spi_Buff), 0xFFFF);
//		HAL_SPI_Receive_IT(&hspi1, (uint8_t *)Spi_Buff, sizeof((uint8_t *)Spi_Buff));
//	}
//}
//void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
//{
//  /* Turn LED1 on: Transfer in transmission process is complete */
////  BSP_LED_On(LED1);
//  /* Turn LED2 on: Transfer in reception process is complete */
////  BSP_LED_On(LED2);
//  wTransferState = TRANSFER_COMPLETE;
//}

/**
  * @brief  SPI error callbacks.
  * @param  hspi: SPI handle
  * @note   This example shows a simple way to report transfer error, and you can
  *         add your own implementation.
  * @retval None
  */
//void HAL_SPI_ErrorCallback(SPI_HandleTypeDef *hspi)
//{
//  wTransferState = TRANSFER_ERROR;
//}
//
///**
//  * @brief  Compares two buffers.
//  * @param  pBuffer1, pBuffer2: buffers to be compared.
//  * @param  BufferLength: buffer's length
//  * @retval 0  : pBuffer1 identical to pBuffer2
//  *         >0 : pBuffer1 differs from pBuffer2
//  */
//static uint16_t Buffercmp(uint8_t *pBuffer1, uint8_t *pBuffer2, uint16_t BufferLength)
//{
//  while (BufferLength--)
//  {
//    if ((*pBuffer1) != *pBuffer2)
//    {
//      return BufferLength;
//    }
//    pBuffer1++;
//    pBuffer2++;
//  }
//
//  return 0;
//}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
//	printf("no");
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
