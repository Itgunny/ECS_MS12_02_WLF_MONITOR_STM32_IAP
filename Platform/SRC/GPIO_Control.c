/**
  ******************************************************************************
  * @file    GPIO_Control.c 
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/22/2013
  * @brief   GPIO_Control.c module
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

void WL9FM_EXYNOS_POWER_ONOFF(uint8_t BitData)
{
	GPIO_WriteBit(EXYNOS_PWR_CTRL_PORT, EXYNOS_PWR_CTRL, (BitAction) BitData);
}

//	�� �Լ��� �����Ű��, �ȵ���̵忡�� ���� �˾��� ����
//		=> 500msec �̻� Set�� ���� ���Ѿ� ���� ����..
void WL9FM_EXYNOS_PMIC_PWRON(void)
{
	GPIO_WriteBit(EXYNOS_PMIC_CTRL_PORT, EXYNOS_PMIC_CTRL, Bit_SET);
	TimeDelay_msec(1000);
	GPIO_WriteBit(EXYNOS_PMIC_CTRL_PORT, EXYNOS_PMIC_CTRL, Bit_RESET);
}

//	++, kutelf, 140801
//	RevD.01.01
//	�Լ� �߰�
void WL9FM_EXYNOS_PMIC_PWROFF(void)
{
	GPIO_WriteBit(EXYNOS_PMIC_nRESET_PORT, EXYNOS_PMIC_nRESET, Bit_SET);
	GPIO_WriteBit(EXYNOS_PMIC_CTRL_PORT, EXYNOS_PMIC_CTRL, Bit_SET);
	TimeDelay_msec(1000);
	GPIO_WriteBit(EXYNOS_PMIC_CTRL_PORT, EXYNOS_PMIC_CTRL, Bit_RESET);
	GPIO_WriteBit(EXYNOS_PMIC_nRESET_PORT, EXYNOS_PMIC_nRESET, Bit_RESET);
}
//	--, kutelf, 140801

//	++, kutelf, 140801
//	RevD.01.01
//	�Լ� ���� 
void WL9FM_EXYNOS_PMIC_PWRONOFF(uint8_t BitData)
{
	GPIO_WriteBit(EXYNOS_PMIC_CTRL_PORT, EXYNOS_PMIC_CTRL, (BitAction) BitData);
}
//	--, kutelf, 140801

//	++, kutelf, 140801
//	RevD.01.01 
//	PMIC nRESET �߰� 
void WL9FM_EXYNOS_PMIC_nRESET(void)
{
	GPIO_WriteBit(EXYNOS_PMIC_nRESET_PORT, EXYNOS_PMIC_nRESET, Bit_SET);
	TimeDelay_msec(500);
	GPIO_WriteBit(EXYNOS_PMIC_nRESET_PORT, EXYNOS_PMIC_nRESET, Bit_RESET);
}

void WL9FM_EXYNOS_PMIC_nRESET_ONOFF(uint8_t BitData)
{
	GPIO_WriteBit(EXYNOS_PMIC_nRESET_PORT, EXYNOS_PMIC_nRESET, (BitAction) BitData);
}
//	--, kutelf, 140801

void WL9FM_CAMERA_nRESET(void)
{
	GPIO_WriteBit(CAMERA_nRESET_PORT, CAMERA_nRESET, Bit_RESET);
	TimeDelay_msec(100);
	GPIO_WriteBit(CAMERA_nRESET_PORT, CAMERA_nRESET, Bit_SET);
}

void WL9FM_PowerIG(uint8_t BitData)
{
    GPIO_WriteBit(PWR_CTRL_PORT, PWR_CTRL, (BitAction) BitData);
}

uint8_t WL9FM_GetPowerIG(void)
{
    return GPIO_ReadInputDataBit(PWR_IGMON_PORT, PWR_IGMON);
}

/*********(C) COPYRIGHT 2013 TaeHa Mechatronics Co., Ltd. *****END OF FILE****/
