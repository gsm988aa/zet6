#include "SPI_gpio.h"


//SPI2��ʼ������
void SPI2_init(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin =  W5500_REST | W5500_DO;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct); 	

	GPIO_InitStruct.Pin =  W5500_SCLK | W5500_NSS;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct); 

	GPIO_InitStruct.Pin =  W5500_DI |W5500_INTn ; 
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	W5500_NSS_H;
}
//us��ʱ
void delay_us(uint16_t time)
{
	uint16_t i,j;
	for(i=0;i<time;i++)
	{
		j=32;
		while(j>1)j--;
	}
}

//W5500��λ����
void W5500_RESET(void)
{
	W5500_REST_L;
	HAL_Delay(50);
	W5500_REST_H;	
	HAL_Delay(50);
}

//SPIд��һ���ֽ�����
void SPI_WriteByte(uint8_t Tdata)
{
	uint8_t i,temp;
	temp=Tdata;
	for(i=0;i<8;i++)
	{
		if(temp&0x80)
			W5500_DO_H;
		else
			W5500_DO_L;
		delay_us(2);
		W5500_SCLK_H; 
		temp=(temp<<1);
		W5500_SCLK_L;
	}
}

//SPIд��һ���ֽ�����
uint8_t SPI_ReadByte(void)
{
	uint8_t i,j=0;	
	for(i=0;i<8;i++)
	{
		W5500_SCLK_H; 
		j=(j<<1);
		if(W5500_DINPUT==GPIO_PIN_SET)
			j=j|0x01;
		delay_us(2);		
		W5500_SCLK_L;
	}
	return j;
}


//�����ٽ���
void SPI_CrisEnter(void)
{
	__set_PRIMASK(1);
}
//�˳��ٽ���
void SPI_CrisExit(void)
{
	__set_PRIMASK(0);
}

//Ƭѡ�ź�����͵�ƽ
void SPI_CS_Select(void)
{
	W5500_NSS_L;
}
//Ƭѡ�ź�����ߵ�ƽ
void SPI_CS_Deselect(void)
{
	W5500_NSS_H;
}
