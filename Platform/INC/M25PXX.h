/**
  ******************************************************************************
  * @file    M25PXX.h 
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/22/2013
  * @brief   M25PXX.c module
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _M25PXX_H
#define _M25PXX_H


#include "WL9F_Monitor_IAP.h"


#define  FLASH_WriteAddress     0x000000
#define  FLASH_ReadAddress      FLASH_WriteAddress
#define  FLASH_SectorToErase    FLASH_WriteAddress
#define countof(a) (sizeof(a) / sizeof(*(a)))

#define SPI_FLASH_PageSize 256

#define WRITE 	0x02  // Write to Memory instruction 
#define WRSR 	0x01  // Write Status Register instruction  
#define WREN 	0x06  // Write enable instruction 

#define READ 	0x03  // Read from Memory instruction 
#define RDSR 	0x05  // Read Status Register instruction  
#define RDID 		0x9F  // Read identification 
#define SE 		0xD8  // Sector Erase instruction 
#define BE 		0xC7  // Bulk Erase instruction 

#define WIP_Flag 0x01  // Write In Progress (WIP) flag 

#define Dummy_Byte 0xA5


#define SPI_FLASH_CS_LOW()     GPIO_WriteBit(SFLASH_SPI1_PORT, SFLASH_SPI1_CS,Bit_RESET)
#define SPI_FLASH_CS_HIGH()    GPIO_WriteBit(SFLASH_SPI1_PORT, SFLASH_SPI1_CS,Bit_SET)

#define SPI_FLASH_SCK_LOW()     GPIO_WriteBit(SFLASH_SPI1_PORT, SFLASH_SPI1_SCK,Bit_RESET)
#define SPI_FLASH_SCK_HIGH()    GPIO_WriteBit(SFLASH_SPI1_PORT, SFLASH_SPI1_SCK,Bit_SET)

#define SPI_FLASH_MOSI_LOW()     GPIO_WriteBit(SFLASH_SPI1_PORT, SFLASH_SPI1_MOSI,Bit_RESET)
#define SPI_FLASH_MOSI_HIGH()    GPIO_WriteBit(SFLASH_SPI1_PORT, SFLASH_SPI1_MOSI,Bit_SET)

#define SPI_FLASH_HOLD_ENABLE()     	GPIO_WriteBit(SFLASH_PORT, SFLASH_HOLD,Bit_RESET)
#define SPI_FLASH_HOLD_DISABLE()    	GPIO_WriteBit(SFLASH_PORT, SFLASH_HOLD,Bit_SET)

#define SPI_FLASH_WP_ENABLE()     	GPIO_WriteBit(SFLASH_PORT, SFLASH_WP,Bit_RESET)
#define SPI_FLASH_WP_DISABLE()    	GPIO_WriteBit(SFLASH_PORT, SFLASH_WP,Bit_SET)

#define DOWNCMD 				0x4f

#define FILE_WRITE_ENABLE		1
#define FILE_WRITE_DISABLE		2
#define FILE_VERIFY				3




//extern void SPI_FLASH_Init(void);
extern void M25P32_Init(void);


extern void SPI_FLASH_SectorErase(unsigned long SectorAddr);
extern void SPI_FLASH_BulkErase(void);
extern void SPI_FLASH_PageWrite(unsigned char* pBuffer, unsigned long WriteAddr, unsigned short  NumByteToWrite);
extern void SPI_FLASH_BufferWrite(unsigned char* pBuffer, unsigned long WriteAddr, unsigned short  NumByteToWrite);
extern void SPI_FLASH_BufferRead(unsigned char* pBuffer, unsigned long ReadAddr, unsigned short  NumByteToRead);
extern unsigned long SPI_FLASH_ReadID(void);
extern void SPI_FLASH_StartReadSequence(unsigned long ReadAddr);
extern unsigned char SPI_FLASH_ReadByte(void);
extern unsigned char SPI_FLASH_SendByte(unsigned char byte);
extern void SPI_FLASH_WriteEnable(void);
extern void SPI_FLASH_WaitForWriteEnd(void);

unsigned char  SPI_Transfer(u8 data);

extern unsigned short MakeCrc16(unsigned char *data, unsigned short nLen);

#endif
