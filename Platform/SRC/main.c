/**
  ******************************************************************************
  * @file    STM32F4xx_IAP/src/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    10-October-2011
  * @brief   Main program body
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
#include "menu.h"
#include "stm324xg_eval.h"
#include "WL9F_Display_IAP.h" //	++, --, kutelf, 130222

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;

u32 download_pattern;

u8 tmp1[6];
u8 tmp[4]={0xa1,0xb2,0xc3,0xd4};

u16 Index_Down;
/* Private function prototypes -----------------------------------------------*/
static void IAP_Init(void);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  	/* Unlock the Flash Program Erase controller */
  	FLASH_If_Init();

	//	++, kutelf, 130222
	System_Configuration();	//	GPIO Setting
	System_Initialize();	//	System Initialize
	FM3164_Watchdog_Init(0x00);
		
	M25P32_Init();	
	
	memset(tmp1,0xff,6);
	
	//SPI_FLASH_SectorErase(0x3f0000);
	
	//SPI_FLASH_PageWrite(tmp,0x3f0000,4);
	
	SPI_FLASH_BufferRead(tmp1,0x3f0000,6);

	download_pattern = (tmp1[3] << 24) | (tmp1[2] << 16) | (tmp1[1] << 8) | tmp1[0]; 

	Index_Down = (tmp1[5] << 8) | tmp1[4]; 

	SPI_FLASH_SectorErase(0x3f0000);		
	//	FW_UPDATE Pin Check -> if Low  = IAP Running
	//							  High = APP Running
	#if 1
	if (download_pattern == 0xa1b2c3d4)
	{
    	/* Execute the IAP driver in order to reprogram the Flash */
    	IAP_Init();
    	/* Display main menu */
    	Main_Menu();
	}	
	#else
	/* Initialize Key Button mounted on STM324xG-EVAL board */
  	STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_GPIO);

  	/* Test if Key push-button on STM324xG-EVAL Board is pressed */
  	if (STM_EVAL_PBGetState(BUTTON_KEY) == 0x00)
  	{ 
    	/* Execute the IAP driver in order to reprogram the Flash */
    	IAP_Init();
    	/* Display main menu */
    	Main_Menu();
  	}
	#endif
	//	--, kutelf, 130222
  	/* Keep the user application running */
  	else
  	{
    	/* Test if user code is programmed starting from address "APPLICATION_ADDRESS" */
    	if (((*(__IO uint32_t*)APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
    	{ 
      		/* Jump to user application */
      		JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
      		Jump_To_Application = (pFunction) JumpAddress;
      		/* Initialize user application's Stack Pointer */
      		__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
      		Jump_To_Application();
    	}
  	}

  	while (1)
  	{}
}

/**
  * @brief  Initialize the IAP: Configure USART.
  * @param  None
  * @retval None
  */
void IAP_Init(void)
{
 USART_InitTypeDef USART_InitStructure;

  /* USART resources configuration (Clock, GPIO pins and USART registers) ----*/
  /* USART configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled
  */
  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  STM_EVAL_COMInit(COM1, &USART_InitStructure);
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
