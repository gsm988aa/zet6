#include "NetWork.h"
#include "wizchip_conf.h"
#include "SPI.h"


//以太网相关参数
wiz_NetInfo gWIZNETINFO = { .mac = {0x78, 0x83, 0x68, 0x88, 0x56, 0x38},
                            .ip =  {192, 168, 4,17},
                            .sn =  {255,255,255,0},
                            .gw =  {192, 168,4,1},
                            .dns = {10,230,194,1},							//修改成自己网络的DNS
                            .dhcp = NETINFO_DHCP};


														
void W5500_ChipInit(void)
{
	W5500_RESET();
	RegisterFunction();
	ChipParametersConfiguration();
	NetworkParameterConfiguration();
}	
																											
														
void RegisterFunction(void)
{  
  
  reg_wizchip_cris_cbfunc(SPI_CrisEnter, SPI_CrisExit);    //注册临界区函数

#if   _WIZCHIP_IO_MODE_ == _WIZCHIP_IO_MODE_SPI_VDM_
  reg_wizchip_cs_cbfunc(SPI_CS_Select, SPI_CS_Deselect);
#elif _WIZCHIP_IO_MODE_ == _WIZCHIP_IO_MODE_SPI_FDM_
  reg_wizchip_cs_cbfunc(SPI_CS_Select, SPI_CS_Deselect);  
#else
   #if (_WIZCHIP_IO_MODE_ & _WIZCHIP_IO_MODE_SIP_) != _WIZCHIP_IO_MODE_SIP_
      #error "Unknown _WIZCHIP_IO_MODE_"
   #else
      reg_wizchip_cs_cbfunc(wizchip_select, wizchip_deselect);
   #endif
#endif
  reg_wizchip_spi_cbfunc(SPI_ReadByte, SPI_WriteByte);    //注册SPI读写函数
}




void ChipParametersConfiguration(void)
{
  uint8_t tmp;
  uint8_t memsize[2][8] = {{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};
	if(ctlwizchip(CW_INIT_WIZCHIP,(void*)memsize) == -1)
		{
			printf("WIZCHIP Initialized fail.\r\n");
			while(1);
		}

	do{
		if(ctlwizchip(CW_GET_PHYLINK, (void*)&tmp) == -1)
			{
			printf("Unknown PHY Link stauts.\r\n");
			}
	  }while(tmp == PHY_LINK_OFF);
}



void NetworkParameterConfiguration(void)  //Intialize the network information to be used in WIZCHIP

{

  uint8_t tmpstr[6];

  ctlnetwork(CN_SET_NETINFO, (void*)&gWIZNETINFO);

  ctlnetwork(CN_GET_NETINFO, (void*)&gWIZNETINFO);

  ctlwizchip(CW_GET_ID,(void*)tmpstr);
	
	printf("\r\n=== %s NET CONF ===\r\n",(char*)tmpstr);
	printf("MAC: %02X:%02X:%02X:%02X:%02X:%02X\r\n",gWIZNETINFO.mac[0],gWIZNETINFO.mac[1],gWIZNETINFO.mac[2],
			gWIZNETINFO.mac[3],gWIZNETINFO.mac[4],gWIZNETINFO.mac[5]);
	printf("SIP: %d.%d.%d.%d\r\n", gWIZNETINFO.ip[0],gWIZNETINFO.ip[1],gWIZNETINFO.ip[2],gWIZNETINFO.ip[3]);
	printf("GAR: %d.%d.%d.%d\r\n", gWIZNETINFO.gw[0],gWIZNETINFO.gw[1],gWIZNETINFO.gw[2],gWIZNETINFO.gw[3]);
	printf("SUB: %d.%d.%d.%d\r\n", gWIZNETINFO.sn[0],gWIZNETINFO.sn[1],gWIZNETINFO.sn[2],gWIZNETINFO.sn[3]);
	printf("DNS: %d.%d.%d.%d\r\n", gWIZNETINFO.dns[0],gWIZNETINFO.dns[1],gWIZNETINFO.dns[2],gWIZNETINFO.dns[3]);
	printf("======================\r\n");

}


