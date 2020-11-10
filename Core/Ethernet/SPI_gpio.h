#ifndef _SPI_GPIO_H
#define _SPI_GPIO_H
#include "stm32f4xx_hal.h"

#define W5500_REST   GPIO_PIN_12  //PB12
#define W5500_NSS    GPIO_PIN_9   //PD9
#define W5500_SCLK   GPIO_PIN_8	  //PD8
#define W5500_DO     GPIO_PIN_14  //PB14
#define W5500_DI     GPIO_PIN_15	//PB15
#define W5500_INTn   GPIO_PIN_13	//PB13

#define  W5500_REST_H			    					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,GPIO_PIN_SET)
#define  W5500_REST_L			    					HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,GPIO_PIN_RESET)	     

#define  W5500_NSS_H 										HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9,GPIO_PIN_SET)
#define  W5500_NSS_L										HAL_GPIO_WritePin(GPIOD, GPIO_PIN_9,GPIO_PIN_RESET)

#define  W5500_SCLK_H                   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8,GPIO_PIN_SET) 
#define  W5500_SCLK_L                   HAL_GPIO_WritePin(GPIOD, GPIO_PIN_8,GPIO_PIN_RESET)

#define  W5500_DO_H                     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,GPIO_PIN_SET) 
#define  W5500_DO_L                     HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,GPIO_PIN_RESET)     

#define  W5500_DINPUT                       HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_15)

void delay_us(uint16_t time);
void W5500_RESET(void);
void SPI2_init(void);
void SPI_WriteByte(uint8_t Tdata);
uint8_t SPI_ReadByte(void);

void SPI_CrisEnter(void);
void SPI_CrisExit(void);
void SPI_CS_Select(void);
void SPI_CS_Deselect(void);




#endif

