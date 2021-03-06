/**
  ******************************************************************************
  * @file    System_Init.c 
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/22/2013
  * @brief   System_Init.c module
  *
  * Project Name       : WL9F Display IAP
  * Project Enviroment : IAREmbedded Workbench for ARM 6.5x 
  *                      STM32F407ZGT6 Firmware Library
  * Project Workspace  : WL9F_Display_IAP
  * MCU Type           : STM32F407ZGT6
  *
  * TAEHA MECHATRONICS Co., Ltd (http://www.taeha.co.kr)				
  * ECS Division R&D Center. / Author by Young-Min Han (kutelf@taeha.co.kr)
  * 
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "WL9F_Display_IAP.h"	

#include "WL9F_Monitor_IAP.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
// EEPROM Clear Variables
WL9FM_SaveE2PROM1		*SaveE2PROM1;
WL9FM_SaveE2PROM2		*SaveE2PROM2;
WL9FM_SaveE2PROM3		*SaveE2PROM3;

WL9FM_SaveE2PROMoniInfo	*SaveE2PROMoniInfo;

WL9F_DATA_RTC   	    WL9FM_RTC;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

void Init_RTC(void)
{
    WL9FM_RTC.Year   = 0;
	WL9FM_RTC.Month  = 1;
	WL9FM_RTC.Date   = 1;
	WL9FM_RTC.Day    = 1;
	WL9FM_RTC.Hour   = 12;
	WL9FM_RTC.Minute = 0;
	WL9FM_RTC.Second = 0;

	WRITE_RTC(WL9FM_RTC);
}

void InitE2PROM(void)
{
	u8 i;
	u8 tmpBuf1[8];
	u8 tmpBuf2[8];
	u8 tmpBuf3[8];
	u8 tmpBuf4[21];
	
	SaveE2PROM1 = (WL9FM_SaveE2PROM1*)&tmpBuf1[0];
	SaveE2PROM2 = (WL9FM_SaveE2PROM2*)&tmpBuf2[0];
	SaveE2PROM3 = (WL9FM_SaveE2PROM3*)&tmpBuf3[0];
	SaveE2PROMoniInfo = (WL9FM_SaveE2PROMoniInfo*)&tmpBuf4[0];

	SaveE2PROM1->WorkLoad 				= 0;
	SaveE2PROM1->testWorkLoad 			= 0;
	SaveE2PROM1->Unit 					= 3;	//	섭씨 ( C ) , km/h
	SaveE2PROM1->DispType	 			= 0;
	SaveE2PROM1->InfoViewPriority 		= 0;
	SaveE2PROM1->UnitPressure 			= 0;
	SaveE2PROM1->Reserved0 				= 0;
	SaveE2PROM1->Lang 					= 0;
	SaveE2PROM1->ManualBackLight 		= 7;
	SaveE2PROM1->AutoBackLight 			= 0;
	SaveE2PROM1->TopInfoView 			= 1;	// 	Hyd Temp
	SaveE2PROM1->BottomInfoView 		= 3;	// 	Cool Temp
	SaveE2PROM1->InfoViewCnt 			= 2;
	SaveE2PROM1->HR_Start 				= 0;
	SaveE2PROM1->RearCamReverseMode 	= 0;	// 	Off
	SaveE2PROM1->ActiveCamNum 			= 1;
	SaveE2PROM1->FirstCam 				= 0;
	SaveE2PROM1->SecondCam 				= 1;
	SaveE2PROM1->ThirdCam 				= 2;
	SaveE2PROM1->Reserved1 				= 0;

	SaveE2PROM2->LightMode 				= 0;
	SaveE2PROM2->JobTimeView 			= 0;
	SaveE2PROM2->OdoMeterView 			= 0;
	SaveE2PROM2->JobOdoSelect 			= 0;
	SaveE2PROM2->LightLowTime 			= 8;
	SaveE2PROM2->LightUpperTime 		= 16;
	SaveE2PROM2->AutoLightDay 			= 0;
	SaveE2PROM2->AutoLightNight 		= 0;
	SaveE2PROM2->Reserved1 				= 0;

	SaveE2PROM3->Phone_1  				= 0;
	SaveE2PROM3->Phone_2  				= 8;
	SaveE2PROM3->Phone_3  				= 0;
	SaveE2PROM3->Phone_4  				= 5;
	SaveE2PROM3->Phone_5  				= 5;
	SaveE2PROM3->Phone_6  				= 5;
	SaveE2PROM3->Phone_7  				= 8;
	SaveE2PROM3->Phone_8  				= 2;
	SaveE2PROM3->Phone_9  				= 7;
	SaveE2PROM3->Phone_10 				= 2;
	SaveE2PROM3->Phone_11 				= 0xf;
	SaveE2PROM3->Phone_12 				= 0xf;

#if 1	// Monitor Change History - temp
	SaveE2PROMoniInfo->ManufactureYear  = 0;
	SaveE2PROMoniInfo->ManufactureMonth = 0;
	SaveE2PROMoniInfo->ManufactureDay   = 0;
	SaveE2PROMoniInfo->MoniPorgramVer   = 0;
	SaveE2PROMoniInfo->MoniSerialNo[0]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[1]  = 0;	// 9
	SaveE2PROMoniInfo->MoniSerialNo[2]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[3]  = 0;	// 8
	SaveE2PROMoniInfo->MoniSerialNo[4]  = 0;	// M
	SaveE2PROMoniInfo->MoniSerialNo[5]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[6]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[7]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[8]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[9]  = 0;	// 0
	SaveE2PROMoniInfo->MoniSerialNo[10] = 0;	// *
	SaveE2PROMoniInfo->MoniModel[0]     = 0;	// N
	SaveE2PROMoniInfo->MoniModel[1]     = 0;	// -
	SaveE2PROMoniInfo->MoniModel[2]     = 0;	// H
	SaveE2PROMoniInfo->MoniModel[3]     = 0;	// -
	SaveE2PROMoniInfo->MoniModel[4]     = 0;	// W
	SaveE2PROMoniInfo->MoniModel[5]     = 0;	// *
#endif

	SerialPutString("\n\rInitialize : 10 %%\n\r");

	EEPROM_Write(0, 0);	// tmp
	EEPROM_Write(0, 0);	// tmp
	EEPROM_Write(0, 0);	// tmp

	for(i = 0 ; i < 8 ; i++)
	{
		EEPROM_Write(i+8, tmpBuf1[i]);
		TimeDelay_msec(5);
		EEPROM_Write(i+16, tmpBuf2[i]);
		TimeDelay_msec(5);
		EEPROM_Write(i+24, tmpBuf3[i]);
		TimeDelay_msec(5);
	}

	SerialPutString("Initialize : 30 %%\n\r");
	
#if 1	// Monitor Change History - temp
	for(i = 0 ; i < 21 ; i++)
	{
		EEPROM_Write(i+50, tmpBuf4[i]);
		TimeDelay_msec(5);
	}
#endif

	for(i = 0 ; i < 79 ; i++)
	{
		EEPROM_Write(i+100, 0xff);
		TimeDelay_msec(5);
	}

	SerialPutString("Initialize : 60 %%\n\r");

	for(i = 0 ; i < 30 ; i++)
	{
		EEPROM_Write(i+200, 0xff);
		TimeDelay_msec(5);
	}

	for(i = 0 ; i < 29 ; i++)
	{
		EEPROM_Write(i+230, 0xff);
		TimeDelay_msec(5);
	}

	SerialPutString("Initialize : 95 %%\n\r");
	Init_RTC();
	SerialPutString("Initialize : 100 %%\n\r\n\r");
}

/**
  * @brief  Clock Setting.
  * @param  None
  * @retval None
  */

RCC_ClocksTypeDef RCC_Clocks;

void RCC_Configuration(void)
{
	

  	//	SysTick end of count event each 1ms
  	RCC_GetClocksFreq(&RCC_Clocks);

	//	SysTick Timer을 사용하려면, 아래의 설정을 해야되고, 아래의 설정값은 1msec 설정이다.
	#if 0	
	//	Setup SysTick Timer for 1 msec interrupts
	if (SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000))
	{ 
	    /* Capture error */ 
    	while (1);
  	}
	#endif
	
	RCC_ClockSecuritySystemCmd(ENABLE);

/**
  * @brief  Enables or disables the AHB1 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before 
  *         using it.   
  * @param  RCC_AHBPeriph: specifies the AHB1 peripheral to gates its clock.
  *          This parameter can be any combination of the following values:
  *            @arg RCC_AHB1Periph_GPIOA:       GPIOA clock
  *            @arg RCC_AHB1Periph_GPIOB:       GPIOB clock 
  *            @arg RCC_AHB1Periph_GPIOC:       GPIOC clock
  *            @arg RCC_AHB1Periph_GPIOD:       GPIOD clock
  *            @arg RCC_AHB1Periph_GPIOE:       GPIOE clock
  *            @arg RCC_AHB1Periph_GPIOF:       GPIOF clock
  *            @arg RCC_AHB1Periph_GPIOG:       GPIOG clock
  *            @arg RCC_AHB1Periph_GPIOG:       GPIOG clock
  *            @arg RCC_AHB1Periph_GPIOI:       GPIOI clock
  *            @arg RCC_AHB1Periph_CRC:         CRC clock
  *            @arg RCC_AHB1Periph_BKPSRAM:     BKPSRAM interface clock
  *            @arg RCC_AHB1Periph_CCMDATARAMEN CCM data RAM interface clock
  *            @arg RCC_AHB1Periph_DMA1:        DMA1 clock
  *            @arg RCC_AHB1Periph_DMA2:        DMA2 clock
  *            @arg RCC_AHB1Periph_ETH_MAC:     Ethernet MAC clock
  *            @arg RCC_AHB1Periph_ETH_MAC_Tx:  Ethernet Transmission clock
  *            @arg RCC_AHB1Periph_ETH_MAC_Rx:  Ethernet Reception clock
  *            @arg RCC_AHB1Periph_ETH_MAC_PTP: Ethernet PTP clock
  *            @arg RCC_AHB1Periph_OTG_HS:      USB OTG HS clock
  *            @arg RCC_AHB1Periph_OTG_HS_ULPI: USB OTG HS ULPI clock
  * @param  NewState: new state of the specified peripheral clock.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
        RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_DMA1, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);

/**
  * @brief  Enables or disables the AHB2 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before 
  *         using it. 
  * @param  RCC_AHBPeriph: specifies the AHB2 peripheral to gates its clock.
  *          This parameter can be any combination of the following values:
  *            @arg RCC_AHB2Periph_DCMI:   DCMI clock
  *            @arg RCC_AHB2Periph_CRYP:   CRYP clock
  *            @arg RCC_AHB2Periph_HASH:   HASH clock
  *            @arg RCC_AHB2Periph_RNG:    RNG clock
  *            @arg RCC_AHB2Periph_OTG_FS: USB OTG FS clock
  * @param  NewState: new state of the specified peripheral clock.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
	//RCC_AHB2PeriphClockCmd(uint32_t RCC_AHB2Periph, FunctionalState NewState)

/**
  * @brief  Enables or disables the AHB3 peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before 
  *         using it. 
  * @param  RCC_AHBPeriph: specifies the AHB3 peripheral to gates its clock.
  *          This parameter must be: RCC_AHB3Periph_FSMC
  * @param  NewState: new state of the specified peripheral clock.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
//	++, kutelf, 140801
//	RevD.01.01 
//	DPRAM 삭제 - FSMC 사용 안함. 
#if 1
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, DISABLE);
#else
	RCC_AHB3PeriphClockCmd(RCC_AHB3Periph_FSMC, ENABLE);
#endif
//	--, kutelf, 140801

/**
  * @brief  Enables or disables the Low Speed APB (APB1) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before 
  *         using it. 
  * @param  RCC_APB1Periph: specifies the APB1 peripheral to gates its clock.
  *          This parameter can be any combination of the following values:
  *            @arg RCC_APB1Periph_TIM2:   TIM2 clock
  *            @arg RCC_APB1Periph_TIM3:   TIM3 clock
  *            @arg RCC_APB1Periph_TIM4:   TIM4 clock
  *            @arg RCC_APB1Periph_TIM5:   TIM5 clock
  *            @arg RCC_APB1Periph_TIM6:   TIM6 clock
  *            @arg RCC_APB1Periph_TIM7:   TIM7 clock
  *            @arg RCC_APB1Periph_TIM12:  TIM12 clock
  *            @arg RCC_APB1Periph_TIM13:  TIM13 clock
  *            @arg RCC_APB1Periph_TIM14:  TIM14 clock
  *            @arg RCC_APB1Periph_WWDG:   WWDG clock
  *            @arg RCC_APB1Periph_SPI2:   SPI2 clock
  *            @arg RCC_APB1Periph_SPI3:   SPI3 clock
  *            @arg RCC_APB1Periph_USART2: USART2 clock
  *            @arg RCC_APB1Periph_USART3: USART3 clock
  *            @arg RCC_APB1Periph_UART4:  UART4 clock
  *            @arg RCC_APB1Periph_UART5:  UART5 clock
  *            @arg RCC_APB1Periph_I2C1:   I2C1 clock
  *            @arg RCC_APB1Periph_I2C2:   I2C2 clock
  *            @arg RCC_APB1Periph_I2C3:   I2C3 clock
  *            @arg RCC_APB1Periph_CAN1:   CAN1 clock
  *            @arg RCC_APB1Periph_CAN2:   CAN2 clock
  *            @arg RCC_APB1Periph_PWR:    PWR clock
  *            @arg RCC_APB1Periph_DAC:    DAC clock
  * @param  NewState: new state of the specified peripheral clock.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4  , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM5  , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2  , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4 , ENABLE);
	//RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1  , ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2  , ENABLE);

/**
  * @brief  Enables or disables the High Speed APB (APB2) peripheral clock.
  * @note   After reset, the peripheral clock (used for registers read/write access)
  *         is disabled and the application software has to enable this clock before 
  *         using it.
  * @param  RCC_APB2Periph: specifies the APB2 peripheral to gates its clock.
  *          This parameter can be any combination of the following values:
  *            @arg RCC_APB2Periph_TIM1:   TIM1 clock
  *            @arg RCC_APB2Periph_TIM8:   TIM8 clock
  *            @arg RCC_APB2Periph_USART1: USART1 clock
  *            @arg RCC_APB2Periph_USART6: USART6 clock
  *            @arg RCC_APB2Periph_ADC1:   ADC1 clock
  *            @arg RCC_APB2Periph_ADC2:   ADC2 clock
  *            @arg RCC_APB2Periph_ADC3:   ADC3 clock
  *            @arg RCC_APB2Periph_SDIO:   SDIO clock
  *            @arg RCC_APB2Periph_SPI1:   SPI1 clock
  *            @arg RCC_APB2Periph_SYSCFG: SYSCFG clock
  *            @arg RCC_APB2Periph_TIM9:   TIM9 clock
  *            @arg RCC_APB2Periph_TIM10:  TIM10 clock
  *            @arg RCC_APB2Periph_TIM11:  TIM11 clock
  * @param  NewState: new state of the specified peripheral clock.
  *          This parameter can be: ENABLE or DISABLE.
  * @retval None
  */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8  , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);
	//RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1  , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
}

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  NVIC Setting.
  * @param  Configures Vector Table base location.
  * @retval None
  */
void NVIC_Configuration(void)
{
}

/* Private functions ---------------------------------------------------------*/
/**
  * @brief  GPIO Setting.
  * @param  Configures the different GPIO ports.
  * @retval None
  */
void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;


	//  Configure UART1 pins: DEBUG_UART1TX, DEBUG_UART1RX 
	//  UART1은 Debugging으로 사용한다. 이미 설정되어 있음.
#if 0

	GPIO_InitStructure.GPIO_Pin   = DEBUG_UART1TX | DEBUG_UART1RX;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DEBUG_UART1_PORT, &GPIO_InitStructure);

	GPIO_PinAFConfig(DEBUG_UART1_PORT, DEBUG_UART1TX_PinSource, GPIO_AF_USART1);
	GPIO_PinAFConfig(DEBUG_UART1_PORT, DEBUG_UART1RX_PinSource, GPIO_AF_USART1);

#endif    
   
	//  CAN1_TX, CAN1_RX
	GPIO_InitStructure.GPIO_Pin   = CAN1_TX | CAN1_RX;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(CAN1_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(CAN1_PORT, CAN1_TX_PinSource, GPIO_AF_CAN1);
	GPIO_PinAFConfig(CAN1_PORT, CAN1_RX_PinSource, GPIO_AF_CAN1);

	//  CAN2_TX, CAN2_RX
	GPIO_InitStructure.GPIO_Pin   = CAN2_TX | CAN2_RX;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(CAN2_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(CAN2_PORT, CAN2_TX_PinSource, GPIO_AF_CAN2);
	GPIO_PinAFConfig(CAN2_PORT, CAN2_RX_PinSource, GPIO_AF_CAN2);

	//	STM32 UART2 <-> EXYNOS UART1
	GPIO_InitStructure.GPIO_Pin   = UART2TX_EXYNOS1 | UART2RX_EXYNOS1;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(UART2_EXYNOS1_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(UART2_EXYNOS1_PORT, UART2TX_EXYNOS1_PinSource, GPIO_AF_USART2);
	GPIO_PinAFConfig(UART2_EXYNOS1_PORT, UART2RX_EXYNOS1_PinSource, GPIO_AF_USART2);
#if 0
//	++, kutelf, 140801
//	RevD.01.01 
//	TW8832 -> TW8816 변경 
//  GPIO로 I2C2 사용
//  Alternate Function 사용안함
#ifdef BoardVersion_RevD
	GPIO_InitStructure.GPIO_Pin   = TW8816_I2C2_SCL | TW8816_I2C2_SDA;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(TW8816_I2C2_PORT, &GPIO_InitStructure);
#else
//	RevD 이하 버젼에서 사용 
	GPIO_InitStructure.GPIO_Pin   = TW8832_I2C2_SCL | TW8832_I2C2_SDA;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(TW8832_I2C2_PORT, &GPIO_InitStructure);
//	GPIO_PinAFConfig(TW8832_I2C2_PORT, TW8832_I2C2_SCL_PinSource, GPIO_AF_I2C2);
//	GPIO_PinAFConfig(TW8832_I2C2_PORT, TW8832_I2C2_SDA_PinSource, GPIO_AF_I2C2);
#endif
//	--, kutelf, 140801
#endif
	//	STM32 UART4 <-> EXYNOS UART3
	GPIO_InitStructure.GPIO_Pin   = UART4TX_EXYNOS3 | UART4RX_EXYNOS3;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(UART4_EXYNOS3_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(UART4_EXYNOS3_PORT, UART4TX_EXYNOS3_PinSource, GPIO_AF_UART4);
	GPIO_PinAFConfig(UART4_EXYNOS3_PORT, UART4RX_EXYNOS3_PinSource, GPIO_AF_UART4);

	//  EXYNOS PWR_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = EXYNOS_PWR_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EXYNOS_PWR_CTRL_PORT, &GPIO_InitStructure);

	//  EXYNOS PMIC_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = EXYNOS_PMIC_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EXYNOS_PMIC_CTRL_PORT, &GPIO_InitStructure);

	//	Serial Flash -> STM32 Update (SPI1)
	GPIO_InitStructure.GPIO_Pin   = SFLASH_SPI1_CS | SFLASH_SPI1_SCK | SFLASH_SPI1_MOSI;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SFLASH_SPI1_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = SFLASH_SPI1_MISO;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SFLASH_SPI1_PORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = SFLASH_HOLD | SFLASH_WP;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(SFLASH_PORT, &GPIO_InitStructure);

	//	LAMP GPIO (Serial Data -> Parallel Data
	GPIO_InitStructure.GPIO_Pin   = LAMP_CLR | LAMP_SLCLK | LAMP_SCLK | LAMP_SDATA;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LAMP_PORT, &GPIO_InitStructure);

	//	Hardware Version -> ADC
	GPIO_InitStructure.GPIO_Pin   = HW_VERSION;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AN;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(HW_VERSION_PORT, &GPIO_InitStructure);

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

	//  POWER_IGMON -> GPIO Input
	GPIO_InitStructure.GPIO_Pin   = PWR_IGMON;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWR_IGMON_PORT, &GPIO_InitStructure);

	//  POWER_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = PWR_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWR_CTRL_PORT, &GPIO_InitStructure);

	//  LCDPWR_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = LCDPWR_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCDPWR_PORT, &GPIO_InitStructure);
//	++, kutelf, 140801
//	RevD.01.01 
//	FW_UPDATE 삭제 
//	RevD 이하 버젼에서 사용 
#ifndef BoardVersion_RevD
	//  FW_UPDATE -> GPIO Input
	GPIO_InitStructure.GPIO_Pin   = FW_UPDATE;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(FW_UPDATE_PORT, &GPIO_InitStructure);
#endif
//	--, kutelf, 140801
	//	LCDBL_PWM -> PWM
	GPIO_InitStructure.GPIO_Pin   = LCDBL_PWM;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_Init(LCDBL_PORT, &GPIO_InitStructure);
	GPIO_PinAFConfig(LCDBL_PORT, LCDBL_PWM_PinSource, GPIO_AF_TIM8);

	//  LCDBL_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = LCDBL_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCDBL_PORT, &GPIO_InitStructure);
	
	//  LCD_STM32 -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = LCD_STM32;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_STM32_PORT, &GPIO_InitStructure);

	//  LCD_EXYNOS -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = LCD_EXYNOS;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD_EXYNOS_PORT, &GPIO_InitStructure);

	//  BUZZER_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = BUZZER_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(BUZZER_PORT, &GPIO_InitStructure);

	//  LED_CTRL -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = LED_CTRL;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LED_PORT, &GPIO_InitStructure);

	//  FM31X4(EEPROM) -> GPIO Output
	//  GPIO로 I2C1 사용
	//  Alternate Function 사용안함
	GPIO_InitStructure.GPIO_Pin   = FM31X4_I2C1_SCL | FM31X4_I2C1_SDA;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(FM31X4_I2C1_PORT, &GPIO_InitStructure);

//	++, kutelf, 140801
//	RevD.01.01 
//	TW2835 삭제 
//	RevD 이하 버젼에서 사용 
#ifndef BoardVersion_RevD
	//  TW2835 -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = TW2835_IRQ| TW2835_HALE | TW2835_HSPB;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(TW2835_CTRLPORT, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin   = TW2835_D0 | TW2835_D1 | TW2835_D2 | TW2835_D3 | TW2835_D4 | TW2835_D5 | TW2835_D6 | TW2835_D7;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(TW2835_DATAPORT, &GPIO_InitStructure);	

	GPIO_InitStructure.GPIO_Pin   = TW2835_CSB0 | TW2835_CSB1 | TW2835_nWE | TW2835_nOE;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(TW2835_DATAPORT, &GPIO_InitStructure);
#endif
//	--, kutelf, 140801

//	++, kutelf, 140801
//	RevD.01.01 
//	DPRAM 삭제 - FSMS 사용 안함. 
#if 0
	//  DPRAM INT -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = DPRAM_INT;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DPRAM_PORT, &GPIO_InitStructure);
#endif
//	--, kutelf, 140801

	//  CAMERA nRESET -> GPIO Output
	GPIO_InitStructure.GPIO_Pin   = CAMERA_nRESET;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(CAMERA_nRESET_PORT, &GPIO_InitStructure);

//	++, kutelf, 140801
//	RevD.01.01 
//	EXYNOS PMIC nRESET 추가 
#if 1
	GPIO_InitStructure.GPIO_Pin   = EXYNOS_PMIC_nRESET;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(EXYNOS_PMIC_nRESET_PORT, &GPIO_InitStructure);
#endif
//	--, kutelf, 140801


//	++, kutelf, 140801
//	RevD.01.01 
//	DPRAM 삭제 - FSMC 사용 안함. 
#if 0
	// 	FSMC Data Line
	//  D15 ~ D0 : D15  D14  D13 D12  D11  D10  D9   D8   D7   D6  D5  D4  D3  D2  D1   D0   
	//             PD10 PD9  PD8 PE15 PE14 PE13 PE12 PE11 PE10 PE9 PE8 PE7 PD1 PD0 PD15 PD14

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10| GPIO_Pin_9  | GPIO_Pin_8 | GPIO_Pin_1 |
	GPIO_Pin_0 | GPIO_Pin_15 | GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOD, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOD, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource9 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource8 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource1 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource0 , GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_FSMC);	
  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 |
								GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9  |
								GPIO_Pin_8  | GPIO_Pin_7;
	GPIO_Init(GPIOE, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOE, GPIO_PinSource15, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource14, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource13, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource12, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource11, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource10, GPIO_AF_FSMC);
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource9 , GPIO_AF_FSMC);	
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource8 , GPIO_AF_FSMC);	
	GPIO_PinAFConfig(GPIOE, GPIO_PinSource7 , GPIO_AF_FSMC);	

	//  nCLK, nOE, nWE, nWait
	GPIO_InitStructure.GPIO_Pin = FSMC_nOE | FSMC_nWE | FSMC_nWAIT | FSMC_nCLK;
	GPIO_Init(FSMC_PORT, &GPIO_InitStructure);

	GPIO_PinAFConfig(FSMC_PORT, FSMC_nOE_PinSource  , GPIO_AF_FSMC);
	GPIO_PinAFConfig(FSMC_PORT, FSMC_nWE_PinSource  , GPIO_AF_FSMC);
	GPIO_PinAFConfig(FSMC_PORT, FSMC_nWAIT_PinSource, GPIO_AF_FSMC);
	GPIO_PinAFConfig(FSMC_PORT, FSMC_nCLK_PinSource , GPIO_AF_FSMC);

	//  nBL0, nBL1
	GPIO_InitStructure.GPIO_Pin = FSMC_nBL0 | FSMC_nBL1;
	GPIO_Init(FSMC_nBL_PORT, &GPIO_InitStructure);

	GPIO_PinAFConfig(FSMC_nBL_PORT, FSMC_nBL0_PinSource  , GPIO_AF_FSMC);
	GPIO_PinAFConfig(FSMC_nBL_PORT, FSMC_nBL1_PinSource  , GPIO_AF_FSMC);

	//	nADV
	GPIO_InitStructure.GPIO_Pin = FSMC_nADV;
	GPIO_PinAFConfig(FSMC_ADVPORT, FSMC_nADV_PinSource  , GPIO_AF_FSMC);
	GPIO_Init(FSMC_ADVPORT, &GPIO_InitStructure);

	// NE1 configuration
	GPIO_InitStructure.GPIO_Pin = FSMC_nNE1;
	GPIO_Init(FSMC_nNE1_PORT, &GPIO_InitStructure);

	GPIO_PinAFConfig(FSMC_nNE1_PORT, FSMC_nNE1_PinSource  , GPIO_AF_FSMC);
#endif
//	--, kutelf, 140801

	//++, 160512 bwk
	// RevH.01.01부터 
	//	Configure CPU_DIE
	GPIO_InitStructure.GPIO_Pin   = CPU_DIE;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(CPU_DIE_PORT, &GPIO_InitStructure);	 

	// WATCH DOG ENABLE
	GPIO_InitStructure.GPIO_Pin   = WD_EN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_Init(WD_EN_PORT, &GPIO_InitStructure);	
	// --, 160512 bwk


    //  사용하지 않는 GPIO Pin은 Output -> Low 상태로 만들어 놓는다.
    //GPIO_Configuration_NotUsed();
}

/**
  * @brief  GPIO Setting.
  * @param  Configures the different GPIO ports. (사용하지 않는 GPIO는 Output Low 상태로 만든다.)
  * @retval None
  */
void GPIO_Configuration_NotUsed(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

//	++, kutelf, 140801
//	RevD.01.01 
//	사용하지 않는 핀 : Output Low 상태로 설정. 
#ifdef BoardVersion_RevD
	//  PB7
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

	//  PC0, PC1, PC2, PC5, PC8, PC13
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_5 | GPIO_Pin_8 | GPIO_Pin_13;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

	//  PD0, PD1, PD3, PD4, PD5, PD6, PD7, PD8, PD9, PD10, PD11, PD12, PD13, PD14, PD15
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
    								GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

	//  PE0, PE1, PE2, PE3, PE4, PE5, PE6, PE7, PE8, PE9, PE10, PE11, PE12, PE13, PE14, PE15
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 |
    								GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12 | GPIO_Pin_13 |
    								GPIO_Pin_14 | GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOE, &GPIO_InitStructure);


	//  PF3, PF4, PF5, PF6, PF7, PF8, PF9
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8 | GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOF, &GPIO_InitStructure);

	// ++, 160512 bwk
#if 0
	//  PG0, PG1, PG2, PG3, PG4, PG5, PG6, PG7, PG8, PG9, PG10, GP12, PG13, PG14
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 |
	GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
#else
	//  PG0, PG1, PG2, PG3, PG4, PG5, PG8, PG9, PG10, GP12, PG13, PG14
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | 
	GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14;
#endif
	// --, 160512 bwk    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOG, &GPIO_InitStructure);
	

    GPIO_ResetBits(GPIOB, GPIO_Pin_7); 

    GPIO_ResetBits(GPIOC, GPIO_Pin_0); 
    GPIO_ResetBits(GPIOC, GPIO_Pin_1); 
    GPIO_ResetBits(GPIOC, GPIO_Pin_2); 
    GPIO_ResetBits(GPIOC, GPIO_Pin_5); 
    GPIO_ResetBits(GPIOC, GPIO_Pin_8); 
    GPIO_ResetBits(GPIOC, GPIO_Pin_13); 	

    GPIO_ResetBits(GPIOD, GPIO_Pin_0); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_1); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_3); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_4); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_5); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_6); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_7); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_8); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_9); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_10); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_11); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_12); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_13); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_14); 		
    GPIO_ResetBits(GPIOD, GPIO_Pin_15); 		
	
    GPIO_ResetBits(GPIOE, GPIO_Pin_0); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_1); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_2); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_3); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_4); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_5); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_6); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_7); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_8); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_9); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_10); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_11); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_12); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_13); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_14); 		
    GPIO_ResetBits(GPIOE, GPIO_Pin_15); 		

    GPIO_ResetBits(GPIOF, GPIO_Pin_3); 		
    GPIO_ResetBits(GPIOF, GPIO_Pin_4); 		
    GPIO_ResetBits(GPIOF, GPIO_Pin_5); 		
    GPIO_ResetBits(GPIOF, GPIO_Pin_6); 		
    GPIO_ResetBits(GPIOF, GPIO_Pin_7); 		
    GPIO_ResetBits(GPIOF, GPIO_Pin_8); 		
    GPIO_ResetBits(GPIOF, GPIO_Pin_9); 		

    GPIO_ResetBits(GPIOG, GPIO_Pin_0); 		
    GPIO_ResetBits(GPIOG, GPIO_Pin_1); 			
    GPIO_ResetBits(GPIOG, GPIO_Pin_2); 		
    GPIO_ResetBits(GPIOG, GPIO_Pin_3); 			
    GPIO_ResetBits(GPIOG, GPIO_Pin_4); 		
    GPIO_ResetBits(GPIOG, GPIO_Pin_5); 			
    // ++, 160512 bwk
    #if 0
    GPIO_ResetBits(GPIOG, GPIO_Pin_6); 		
    GPIO_ResetBits(GPIOG, GPIO_Pin_7); 			
    #endif
    // --, 160512 bwk
    GPIO_ResetBits(GPIOG, GPIO_Pin_8); 		
    GPIO_ResetBits(GPIOG, GPIO_Pin_9); 			
    GPIO_ResetBits(GPIOG, GPIO_Pin_10); 			
    GPIO_ResetBits(GPIOG, GPIO_Pin_12); 			
    GPIO_ResetBits(GPIOG, GPIO_Pin_13); 			
    GPIO_ResetBits(GPIOG, GPIO_Pin_14); 				
	
#else
//	RevD 이하 버젼에서 사용 	
	//  PC2
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

	//  PC8
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);

	//  PB7
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

	//  PC15
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_15;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
  	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
	
    GPIO_ResetBits(GPIOC, GPIO_Pin_2);
    GPIO_ResetBits(GPIOC, GPIO_Pin_8);
    GPIO_ResetBits(GPIOC, GPIO_Pin_15);
    GPIO_ResetBits(GPIOB, GPIO_Pin_7);	
#endif
//	--, kutelf, 140801
}

/**
  * @brief  Hardware, Software System Configuration.
  * @param  None
  * @retval None
  */
void System_Configuration(void)
{
	RCC_Configuration();		    // 	Configure the system clocks
	NVIC_Configuration();		    //	NVIC Configuration
	GPIO_Configuration();		    // 	Configure the GPIO port	
}

void System_Initialize(void)
{
	//  PWR_CTRL -> BootLoader에서는 Sub Power Enable을 Off 
	GPIO_ResetBits(PWR_CTRL_PORT, PWR_CTRL);   	//	24V Power Enable 
	                                //  Set   : Power Enable On
	                                //  Reset : Power Enable Off    	

	//  LCDPWR_CTRL -> BootLoader에서는 VLCD12 Power Enable을 Off 
	GPIO_ResetBits(LCDPWR_PORT, LCDPWR_CTRL);  	//	LCD Power Enable 
	                                //  Set   : LCD Power Enable 
	                                //  Reset : LCD Power Disable	

	//  BootLoader Bootting시에, LCDBL는 Off 상태로 만든다.
	GPIO_ResetBits(LCDBL_PORT, LCDBL_CTRL);	    //	LCD BackLight Power On/Off (LCDBL_CTRL)
	                               	//  Set   : BackLight Power On
	                               	//  Reset : BackLight Power Off			
	                               	
	GPIO_ResetBits(BUZZER_PORT, BUZZER_CTRL);	//	BUZZER Off
	                                //  Set   : BUZZER On
	                                //  Reset : BUZZER Off

	GPIO_ResetBits(LED_PORT, LED_CTRL);			//	LED Enable Off
	                                //  Set   : LED Enable  -> On
	                                //  Reset : LED Disable -> Off


	// ++, 150811 sys 
	#if 0								
	                             			
	GPIO_ResetBits(EXYNOS_PMIC_CTRL_PORT, EXYNOS_PMIC_CTRL);	//	Exynos-4412 PMIC On/Off
	                                				//  PMIC On  : Low -> High
	                                				//       Off : Low -> High
	//	++, kutelf, 140801
	//	RevD.01.01 
	//	EXYNOS PMIC nRESET => Reset 상태로 초기화 
	GPIO_SetBits(EXYNOS_PMIC_nRESET_PORT, EXYNOS_PMIC_nRESET);	//	Exynos-4412 PMIC nRESET
	                                				//  PMIC On  : High
	                                				//       Off : Low
	//	--, kutelf, 140801

	#endif
	// --, 150811 sys
	
	GPIO_ResetBits(LCD_EXYNOS_PORT, LCD_EXYNOS);	//	Exynos-4412 LCD Display
	                                //  Set   : HI-Z
	                                //  Reset : Display
	                                    				
	GPIO_SetBits(LCD_STM32_PORT, LCD_STM32);	//	STM32 LCD Display
	                                //  Set   : HI-Z
	                                //  Reset : Display

	GPIO_ResetBits(CAMERA_nRESET_PORT, CAMERA_nRESET);	//	CAMERA nRESET
	                                        //  Set   : On
	                                        //  Reset : Off		
}
// ++, sys3215, 141211
void Camera_IO_Init(void)
{
        
  	GPIO_InitTypeDef GPIO_InitStructure;
        
  	GPIO_InitStructure.GPIO_Pin   = TW8816_I2C2_SCL | TW8816_I2C2_SDA;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;   
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(TW8816_I2C2_PORT, &GPIO_InitStructure);
        GPIO_Configuration_NotUsed();
}
/*********(C) COPYRIGHT 2013 TaeHa Mechatronics Co., Ltd. *****END OF FILE****/


