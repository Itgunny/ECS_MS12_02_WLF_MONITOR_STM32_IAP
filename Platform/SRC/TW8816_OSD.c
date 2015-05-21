/**
  ******************************************************************************
  * @file    TW8816_OSD.c 
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/22/2013
  * @brief   TW8816_OSD.c module
  *
  * Project Name       : WL9F Monitor APP
  * Project Enviroment : IAREmbedded Workbench for ARM 6.5x 
  *                      STM32F407ZGT6 Firmware Library
  * Project Workspace  : WL9F_Monitor_APP
  * MCU Type           : STM32F407ZGT6
  *
  * TAEHA MECHATRONICS Co., Ltd (http://www.taeha.co.kr)				
  * ECS Division R&D Center. / Author by Young-Min Han (kutelf@taeha.co.kr)
  * 
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "WL9F_Monitor_IAP.h"	

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
#if 1
void SetFontOSDWindow(void)
{
	WriteTW8816(0xff, 0x00);

	WriteTW8816(0x94, 0x00);
	WriteTW8816(0x9e, 0x00);
	WriteTW8816(0x9f, 0x01);
	WriteTW8816(0xa0, 0x00);
	WriteTW8816(0xa1, 0x00);
	WriteTW8816(0xa2, 0x00);
	WriteTW8816(0xa3, 0x22);
	WriteTW8816(0xa4, 0x0e);
	WriteTW8816(0xa5, 0x32);
	WriteTW8816(0xa6, 0x00);
	WriteTW8816(0xa7, 0x00);
	WriteTW8816(0xa8, 0x00);
	WriteTW8816(0xa9, 0x50);
	WriteTW8816(0xaa, 0x00);
	WriteTW8816(0xab, 0x55);
	WriteTW8816(0xac, 0x00);
	WriteTW8816(0xad, 0x00);
	WriteTW8816(0xae, 0x00);

	WriteTW8816(0x94, 0x11);
	WriteTW8816(0x94, 0x02);
}


void SetDisplayUpdate(void)
{
  
	WriteTW8816(0xff, 0x00);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xd8);
	WriteTW8816(0x97, 0x55);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xd9);
	WriteTW8816(0x97, 0x50);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xda);
	WriteTW8816(0x97, 0x44);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xdb);
	WriteTW8816(0x97, 0x41);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xdc);
	WriteTW8816(0x97, 0x54);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xdd);
	WriteTW8816(0x97, 0x45);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xde);
	WriteTW8816(0x97, 0x2E);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xdf);
	WriteTW8816(0x97, 0x2E);
	WriteTW8816(0x98, 0x06);

	WriteTW8816(0x95, 0x80);
	WriteTW8816(0x96, 0xe0);
	WriteTW8816(0x97, 0x2E);
	WriteTW8816(0x98, 0x06);
	
}
void SetBackgroundBlueOSD(){
      WriteTW8816(0xff, 0x00);
      WriteTW8816(0x94, 0x00);
      WriteTW8816(0x95, 0x80);
      WriteTW8816(0x9C, 0x80);
      WriteTW8816(0x9D, 0x00);
      WriteTW8816(0x9E, 0x01);
      WriteTW8816(0x9F, 0x71);
      WriteTW8816(0x94, 0x00);
      WriteTW8816(0x9E, 0x00);
}
void SetProgressLineOSD(u8 index){
      	WriteTW8816(0xff, 0x00);
        WriteTW8816(0x95, 0x81);
        WriteTW8816(0x96, index);
        WriteTW8816(0x97, 0x7F);
        WriteTW8816(0x98, 0x06);
}
void TurnOffOSD(){
      WriteTW8816(0x9C, 0x10);
}
#else


void SetFontOSDWindow(void)
{
	I2C2_ByteWrite_8816(0xff, 0x00);

	I2C2_ByteWrite_8816(0x94, 0x00);
	I2C2_ByteWrite_8816(0x9e, 0x00);
	I2C2_ByteWrite_8816(0x9f, 0x01);
	I2C2_ByteWrite_8816(0xa0, 0x00);
	I2C2_ByteWrite_8816(0xa1, 0x00);
	I2C2_ByteWrite_8816(0xa2, 0x00);
	I2C2_ByteWrite_8816(0xa3, 0x22);
	I2C2_ByteWrite_8816(0xa4, 0x0e);
	I2C2_ByteWrite_8816(0xa5, 0x32);
	I2C2_ByteWrite_8816(0xa6, 0x00);
	I2C2_ByteWrite_8816(0xa7, 0x00);
	I2C2_ByteWrite_8816(0xa8, 0x00);
	I2C2_ByteWrite_8816(0xa9, 0x50);
	I2C2_ByteWrite_8816(0xaa, 0x00);
	I2C2_ByteWrite_8816(0xab, 0x55);
	I2C2_ByteWrite_8816(0xac, 0x0f);
	I2C2_ByteWrite_8816(0xad, 0x00);
	I2C2_ByteWrite_8816(0xae, 0x00);

	I2C2_ByteWrite_8816(0x94, 0x11);
	I2C2_ByteWrite_8816(0x94, 0x02);
}

void SetDisplayUpdate(void)
{
	I2C2_ByteWrite_8816(0xff, 0x00);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xd8);
	I2C2_ByteWrite_8816(0x97, 0x55);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xd9);
	I2C2_ByteWrite_8816(0x97, 0x50);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xda);
	I2C2_ByteWrite_8816(0x97, 0x44);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xdb);
	I2C2_ByteWrite_8816(0x97, 0x41);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xdc);
	I2C2_ByteWrite_8816(0x97, 0x54);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xdd);
	I2C2_ByteWrite_8816(0x97, 0x45);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xde);
	I2C2_ByteWrite_8816(0x97, 0x2e);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xdf);
	I2C2_ByteWrite_8816(0x97, 0x2e);
	I2C2_ByteWrite_8816(0x98, 0x06);

	I2C2_ByteWrite_8816(0x95, 0x80);
	I2C2_ByteWrite_8816(0x96, 0xe0);
	I2C2_ByteWrite_8816(0x97, 0x2e);
	I2C2_ByteWrite_8816(0x98, 0x06);
	
}

#endif


/*********(C) COPYRIGHT 2010 TaeHa Mechatronics Co., Ltd. *****END OF FILE****/
