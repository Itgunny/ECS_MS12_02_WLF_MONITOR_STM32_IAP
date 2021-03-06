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
#include "WL9F_Monitor_IAP.h" //	++, --, kutelf, 130222

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

#define MAXSCAN 	            3           //  Scan Switch 
#define MAXSWITCH               6           //  Input Switch 
#define MAXINPUT               	6           //  Input Switch 

#define EXT_WATCHDOG_ENALBE(x)					GPIO_WriteBit(WD_EN_PORT, WD_EN,x)		// ++, --, 160512 bwk


/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
GPIO_TypeDef*  KEYSWITCH_SCANPORT[MAXSCAN]	=   {  
                                                KeySWXX_PORT, 
                                                KeySWXX_PORT, 
                                                KeySWXX_PORT, 
                                            };
const uint16_t KEYSWITCH_SCAN[MAXSCAN]  =   { 
                                                KeySCAN0, 
                                                KeySCAN1, 
                                                KeySCAN2, 
                                            };
GPIO_TypeDef*  KEYSWITCH_INPUTPORT[MAXINPUT]	=   {  
                                                KeySWXX_PORT, 
                                                KeySWXX_PORT, 
                                                KeySWXX_PORT, 
                                                KeySWXX_PORT, 
                                                KeySWXX_PORT,
                                                KeySWXX_PORT,                                                
                                            };
const uint16_t KEYSWITCH_INPUT[MAXINPUT]  =   { 
                                                KeyInput0, 
                                                KeyInput1, 
                                                KeyInput2, 
                                                KeyInput3,
                                                KeyInput4,
                                                KeyInput5,
                                            };

u8 fatoryinit_start_code[4]={0x4d,0x3c,0x2b,0x1a};
u8 fatoryinit_end_code[4]={0x8d,0x7c,0x6b,0x5a};

u8 FactoryInitFlag = 0;
u8 UpdateFlag = 0;
extern pFunction Jump_To_Application;
extern uint32_t JumpAddress;

u32 download_pattern;
u32 FactoryInit_Pattern;
u8 tmp1[6];
u8 tmp[4]={0xa1,0xb2,0xc3,0xd4};

u16 Index_Down;
WL9FM_LCDBL_DATA   		    WL9FM_LCDBL;
/* Private function prototypes -----------------------------------------------*/
static void IAP_Init(void);
static void Key_Init(void);
static uint32_t KeySwitch_Process(void);
void DisplayUpdateOSDInit(void);
/* Private functions ---------------------------------------------------------*/
unsigned char Confirm_SerialFalsh(void)
{
	unsigned char Data1[4]={0,};
	unsigned char Data2[4]={0,};
	unsigned char Data3[4]={0,};
	unsigned char Data4[4]={0,};

	Data2[0] = 0xaa;
	Data2[1] = 0x44;
	Data2[2] = 0xc0;
	Data2[3] = 0x0c;

	Data3[0] = 0xaa;
	Data3[1] = 0x44;
	Data3[2] = 0xc0;
	Data3[3] = 0x0c;


	SPI_FLASH_BufferRead(Data1,0x460000,4);		// Sector_70

	if ((memcmp(Data1, Data3, 4)) == 0)
	{		
		return 0;
	}
	else
	{
		SPI_FLASH_SectorErase(0x460000);
		SPI_FLASH_PageWrite(Data2, 0x460000, 4);
		SPI_FLASH_BufferRead(Data4, 0x460000, 4);
		return 1;
	}   
}
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  	unsigned char data[7];		// ++, --, 160512 bwk
  	/* Unlock the Flash Program Erase controller */
	
  	FLASH_If_Init();

	// Serial Flash Address
	/* 
	#define Sector_1 		0x10000		// STM32_UPDATE(MASS UPDATE)		
	#define Sector_10 	0xA0000		// STM32_UPDATE(factory init))
	#define Sector_60 	0x3c0000		// Serial Flash Test
	#define Sector_61 	0x3d0000		// fatoryinit_enable_code
	#define Sector_62 	0x3e0000		// fatoryinit_enable_code
	#define Sector_63 	0x3f0000		// download enable code
	#define Sector_70		0x460000		// RTC Init
	*/

	//	++, kutelf, 130222
	System_Configuration();	//	GPIO Setting
	System_Initialize();	//	System Initialize
	// ++, 160512 bwk
#if 0
	FM3164_Watchdog_Init(0x00);
#else
	EXT_WATCHDOG_ENALBE(1);
#endif
	// --, 160512 bwk	
		
	M25P32_Init();	
	Key_Init();
	memset(tmp1,0xff,6);
	//SPI_FLASH_SectorErase(0x3f0000);
	
	//SPI_FLASH_PageWrite(tmp,0x3f0000,4);
	// ++, 160518 bwk
	if(Confirm_SerialFalsh()==1)
	{
		data[0] = read_RTC_Companion(ADDRESS_RTC_YEAR);
		data[1] = read_RTC_Companion(ADDRESS_RTC_MONTH);
		data[2] = read_RTC_Companion(ADDRESS_RTC_DATE);
		data[3] = read_RTC_Companion(ADDRESS_RTC_DAY);
		data[4] = read_RTC_Companion(ADDRESS_RTC_HOUR);
		data[5] = read_RTC_Companion(ADDRESS_RTC_MINUTE);
		data[6] = read_RTC_Companion(ADDRESS_RTC_SECOND);

		if((data[0]>0x99)||(data[1]>0x12&&data[1]<0x1)||(data[2]>0x31)||(data[3]>0x7&&data[3]<0x1)||(data[4]>0x23)||(data[5]>0x59)||(data[6]>0x59))
		{
			Init_RTC();
		}
	}
      // --, 160518 bwk

        
	FactoryInitFlag = 0;
	UpdateFlag = 0;        
        
	SPI_FLASH_BufferRead(tmp1,0x3e0000,6);			// Sector_62

	FactoryInit_Pattern = (tmp1[3] << 24) | (tmp1[2] << 16) | (tmp1[1] << 8) | tmp1[0]; 

	if(FactoryInit_Pattern == 0x1a2b3c4d)
	{
		SPI_FLASH_BufferRead(tmp1,0x3d0000,6);
		
		Index_Down = (tmp1[5] << 8) | tmp1[4]; 
		
		FactoryInitFlag = 1;
		/* Execute the IAP driver in order to reprogram the Flash */
		IAP_Init();
		/* Display main menu */
		Main_Menu();	
	}
	else
	{
		if(KeySwitch_Process() == 0x1C && FactoryInit_Pattern == 0x5a6b7c8d) 	// Factory Init
		{
			SPI_FLASH_BufferRead(tmp1,0x3d0000,6);
			
			Index_Down = (tmp1[5] << 8) | tmp1[4]; 
			
			FactoryInitFlag = 1;
			/* Execute the IAP driver in order to reprogram the Flash */
			IAP_Init();
			/* Display main menu */
			Main_Menu();			
		}
		else
		{
			SPI_FLASH_BufferRead(tmp1,0x3f0000,6);
							
			download_pattern = (tmp1[3] << 24) | (tmp1[2] << 16) | (tmp1[1] << 8) | tmp1[0]; 
		
			Index_Down = (tmp1[5] << 8) | tmp1[4]; 
			if (download_pattern == 0xa1b2c3d4)
			{
				UpdateFlag = 1;
				/* Execute the IAP driver in order to reprogram the Flash */
				IAP_Init();
				/* Display main menu */
				Main_Menu();
			}	
		}
	}
	
	
	/* Test if user code is programmed starting from address "APPLICATION_ADDRESS" */
	if (((*(__IO uint32_t*)APPLICATION_ADDRESS) & 0x2FFE0000 ) == 0x20000000)
	{
		TurnOffOSD();         
		// ++, 150811 sys
		#if 0
		WL9FM_EXYNOS_POWER_ONOFF(EXYNOS_POWER_OFF);
		#endif
		// --, 150811 sys
		
		/* Jump to user application */
		JumpAddress = *(__IO uint32_t*) (APPLICATION_ADDRESS + 4);
		Jump_To_Application = (pFunction) JumpAddress;
		/* Initialize user application's Stack Pointer */
		__set_MSP(*(__IO uint32_t*) APPLICATION_ADDRESS);
		Jump_To_Application();
	}
  	
  	while (1){}
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

void Key_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	 //	KeySwitch Matrix -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = KeySCAN0 | KeySCAN1 | KeySCAN2;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KeySWXX_PORT, &GPIO_InitStructure);

	//	KeySwitch Matrix -> GPIO Input
	GPIO_InitStructure.GPIO_Pin   = KeyInput0 | KeyInput1 | KeyInput2 | KeyInput3 | KeyInput4 | KeyInput5;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(KeySWXX_PORT, &GPIO_InitStructure);
}
uint32_t KeySwitch_Process(void)
{
	uint8_t i, j, k;
	uint32_t New_Value;
	

	GPIO_WriteBit(KEYSWITCH_SCANPORT[0], KEYSWITCH_SCAN[0], Bit_RESET); //R
	GPIO_WriteBit(KEYSWITCH_SCANPORT[1], KEYSWITCH_SCAN[1], Bit_SET);
	GPIO_WriteBit(KEYSWITCH_SCANPORT[2], KEYSWITCH_SCAN[2], Bit_SET);					
	
	New_Value = 0;
	
	//  KeySwitch Press Check
	//Delay(100);
	
	for (i = 0; i < MAXSWITCH; i++)
	{
		k = 0;    
		k = GPIO_ReadInputDataBit(KEYSWITCH_INPUTPORT[i], KEYSWITCH_INPUT[i]); //  Read KeySwitch Input 

		if (k == 0) j = 1;    
		else        j = 0;

		New_Value <<= 1;    //  1Bit씩 Shitf하여 총 5Bit를 만든다.
		New_Value  += j;    //  0 or 1
	}


	return New_Value;
    
}

void DisplayUpdateOSDInit(void){
      //Camera Setting 
      Camera_IO_Init();
      
      WL9FM_CAMERA_nRESET();

      TW8816_Control_Init();

      LCD_POWER_ONOFF(LCDPWR_ON);
      LCDBL_ONOFF(LCDBL_OFF);
      LCD_Control_Init(); 
      
      SetFontOSDWindow();
      cam_mode_change(0x00);
      //LCD ON
      LCDBL_ONOFF(LCDBL_ON);	//  LCDBL Power On!!!
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
