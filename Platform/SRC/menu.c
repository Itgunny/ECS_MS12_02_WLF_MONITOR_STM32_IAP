/**
  ******************************************************************************
  * @file    STM32F4xx_IAP/src/menu.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    10-October-2011
  * @brief   This file provides the software which contains the main menu routine.
  *          The main menu gives the options of:
  *             - downloading a new binary file, 
  *             - uploading internal flash memory,
  *             - executing the binary file already loaded 
  *             - disabling the write protection of the Flash sectors where the 
  *               user loads his binary file.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/** @addtogroup STM32F4xx_IAP
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "common.h"
#include "flash_if.h"
#include "menu.h"
#include "ymodem.h"
#include "WL9F_Display_IAP.h"	//	++, --, kutelf, 130222

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern u32 download_pattern;
extern u32 FactoryInit_Pattern;
extern u8 FactoryInitFlag;
extern u8 UpdateFlag;

pFunction Jump_To_Application;
uint32_t JumpAddress;
__IO uint32_t FlashProtection = 0;
uint8_t tab_1024[1024] =
  {
    0
  };
uint8_t FileName[FILE_NAME_LENGTH];

/* Private function prototypes -----------------------------------------------*/
void SerialDownload(void);
void SerialUpload(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Download a file via serial port
  * @param  None
  * @retval None
  */
void SerialDownload(void)
{
  uint8_t Number[10] = "          ";
  int32_t Size = 0;

  SerialPutString("Waiting for the file to be sent ... (press 'a' to abort)\n\r");

  //Size = Ymodem_Receive(&tab_1024[0]);
  
  if(FactoryInitFlag == 1)
  {
	  Size = Serial_Flash_FactoryInit_Down();
  }
  else if(UpdateFlag == 1)
  {
	Size = Serial_Flash_Down();
  }

  
  if (Size > 0)
  {
	//	++, kutelf, 130222
    //  File을 다 받은 후에 자동으로 Running
    #if 0
    SerialPutString("\n\n\r Programming Completed Successfully!\n\r--------------------------------\r\n Name: ");
    SerialPutString(FileName);
    Int2Str(Number, Size);
    SerialPutString("\n\r Size: ");
    SerialPutString(Number);
    SerialPutString(" Bytes\r\n");
    SerialPutString("-------------------\n");
	#else
    SerialPutString("\n\n\r Programming Completed Successfully!");
    SerialPutString("\n\r--------------------------------\r\n Send File Name: ");
    SerialPutString(FileName);
    Int2Str(Number, Size);
    SerialPutString("\n\r Send File Size: ");
    SerialPutString(Number);
    SerialPutString(" Bytes\r\n");
    SerialPutString("--------------------------------\n");
    SerialPutString("\r\n\r\n");
    SerialPutString("Application Program Running.....\r\n");
    
	/* Jump to user application */
	JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
	Jump_To_Application = (pFunction) JumpAddress;
	/* Initialize user application's Stack Pointer */
	__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
	Jump_To_Application();
	#endif
	//	--, kutelf, 130222
  }
  else if (Size == -1)
  {
    SerialPutString("\n\n\rThe image size is higher than the allowed space memory!\n\r");
  }
  else if (Size == -2)
  {
    SerialPutString("\n\n\rVerification failed!\n\r");
  }
  else if (Size == -3)
  {
    SerialPutString("\r\n\nAborted by user.\n\r");
  }
  else
  {
    SerialPutString("\n\rFailed to receive the file!\n\r");
  }
}

/**
  * @brief  Upload a file via serial port.
  * @param  None
  * @retval None
  */
void SerialUpload(void)
{
  uint8_t status = 0 ; 

  SerialPutString("\n\n\rSelect Receive File\n\r");

  if (GetKey() == CRC16)
  {
    /* Transmit the flash image through ymodem protocol */
    status = Ymodem_Transmit((uint8_t*)APPLICATION_ADDRESS, (const uint8_t*)"UploadedFlashImage.bin", USER_FLASH_SIZE);

    if (status != 0) 
    {
      SerialPutString("\n\rError Occurred while Transmitting File\n\r");
    }
    else
    {
      SerialPutString("\n\rFile uploaded successfully \n\r");
    }
  }
}

/**
  * @brief  Display the Main Menu on HyperTerminal
  * @param  None
  * @retval None
  */
void Main_Menu(void)
{
  uint8_t key = 0;

  //	++, kutelf, 130222	
  #if 0	
  SerialPutString("\r\n======================================================================");
  SerialPutString("\r\n=              (C) COPYRIGHT 2011 STMicroelectronics                 =");
  SerialPutString("\r\n=                                                                    =");
  SerialPutString("\r\n=  STM32F4xx In-Application Programming Application  (Version 1.0.0) =");
  SerialPutString("\r\n=                                                                    =");
  SerialPutString("\r\n=                                   By MCD Application Team          =");
  SerialPutString("\r\n======================================================================");
  SerialPutString("\r\n\r\n");
  #else
    SerialPutString("\r\n==========================================================");
    SerialPutString("\r\n=                                                        =");
    SerialPutString("\r\n=             TaeHa Mechatronics Co., Ltd.               =");
    SerialPutString("\r\n=                                                        =");
    SerialPutString("\r\n= In-Application Programming Application                 =");
    SerialPutString("\r\n=                                                        =");
    SerialPutString("\r\n= Project      : WL9F Display (Monitor & Cluster)        =");
    SerialPutString("\r\n= Environment  : EWARM v6.5, Library v1.0.0              ="); 
    SerialPutString("\r\n=                STM32F4xx Standard Peripherals Library  =");	
    SerialPutString("\r\n=                                                        =");
    SerialPutString("\r\n= By ECS Div. kutelf                                     =");
    SerialPutString("\r\n==========================================================");
    SerialPutString("\r\n");
  #endif
  //	--, kutelf, 130222
  
  /* Test if any sector of Flash memory where user application will be loaded is write protected */
  if (FLASH_If_GetWriteProtectionStatus() == 0)   
  {
    FlashProtection = 1;
  }
  else
  {
    FlashProtection = 0;
  }

  while (1)
  {
	//	++, kutelf, 130222

	SerialDownload();
	
	#if 0
    SerialPutString("\r\n================== Main Menu ============================\r\n\n");
    SerialPutString("  Download Image To the STM32F4xx Internal Flash ------- 1\r\n\n");
    SerialPutString("  Upload Image From the STM32F4xx Internal Flash ------- 2\r\n\n");
    SerialPutString("  Execute The New Program ------------------------------ 3\r\n\n");

    if(FlashProtection != 0)
    {
      SerialPutString("  Disable the write protection ------------------------- 4\r\n\n");
    }
    SerialPutString("==========================================================\r\n\n");
	#else
    SerialPutString("\r\n==================== Main Menu ===========================\r\n\n");
    if(FlashProtection != 0)
    {
    SerialPutString("  Disable the write protection (STM32F407 Internal Flash) 0\r\n\n");
    }
    SerialPutString("  Download Application to the STM32F407 Internal Flash -- 1\r\n\n");
    SerialPutString("  Upload   Application from   STM32F407 Internal Flash -- 2\r\n\n");
    SerialPutString("  Execute The New Program ------------------------------- 3\r\n\n");
	SerialPutString("  EEPROM Initialization --------------------------------- 4\r\n\n");
    SerialPutString("==========================================================\r\n\n");
	#endif
	//	--, kutelf, 130222

    /* Receive key */
    key = GetKey();

    if (key == 0x31)
    {
      /* Download user application in the Flash */
      SerialDownload();
    }
    else if (key == 0x32)
    {
      /* Upload user application from the Flash */
      SerialUpload();
    }
    else if (key == 0x33) /* execute the new program */
    {
      JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
      /* Jump to user application */
      Jump_To_Application = (pFunction) JumpAddress;
      /* Initialize user application's Stack Pointer */
      __set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
      Jump_To_Application();
    }
	//	++, kutelf, 130222
	//	EEPROM Clear Menu 추가.
	else if (key == 0x34)
	{
    	SerialPutString("EEPROM Initialize(Clear) Start...\n\r");
    	InitE2PROM();
    	SerialPutString("EEPROM Initialize(Clear) End...\n\r");
	}
	//	--, kutelf, 130222
	//	++, kutelf, 130222
	//	Write Pritection Menu Number 변경 
	#if 0
	else if ((key == 0x34) && (FlashProtection == 1))
	#else
	else if ((key == 0x30) && (FlashProtection == 1))
	#endif
	//	--, kutelf, 130222
    {
      /* Disable the write protection */
      switch (FLASH_If_DisableWriteProtection())
      {
        case 1:
        {
          SerialPutString("Write Protection disabled...\r\n");
          FlashProtection = 0;
          break;
        }
        case 2:
        {
          SerialPutString("Error: Flash write unprotection failed...\r\n");
          break;
        }
        default:
        {
        }
      }
    }
    else
    {
      if (FlashProtection == 0)
      {
		//	++, kutelf, 130222
		//	Write Pritection Menu Number 변경 
		#if 0
        SerialPutString("Invalid Number ! ==> The number should be either 1, 2 or 3\r");
		#else
        SerialPutString("Invalid Number ! ==> The number should be either 1, 2, 3 or 4\r");
		#endif
		//	--, kutelf, 130222
      }
      else
      {
		//	++, kutelf, 130222
		//	Write Pritection Menu Number 변경 
		#if 0
        SerialPutString("Invalid Number ! ==> The number should be either 1, 2, 3 or 4\r");
		#else
        SerialPutString("Invalid Number ! ==> The number should be either 0, 1, 2, 3 or 4\r");
		#endif
		//	--, kutelf, 130222
      }
    }
  }
}

/**
  * @}
  */

/*******************(C)COPYRIGHT 2011 STMicroelectronics *****END OF FILE******/
