/**
  ******************************************************************************
  * @file    GPIO_Control.h 
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/28/2013
  * @brief   
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_Control_H
#define __GPIO_Control_H

/* Includes ------------------------------------------------------------------*/
#include "WL9F_Monitor_IAP.h"	

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

//  System PowerIG On/Off
#define     PowerIG_ON              		1           //  PowerIG On
#define     PowerIG_OFF             		0           //  PowerIG Off

#define		EXYNOS_POWER_ON					1			//	Exynos-4412 Power On
#define		EXYNOS_POWER_OFF				0			//	Exynos-4412 Power Off

#define		EXYNOS_PMIC_ON					1			//	Exynos-4412 RESET On
#define		EXYNOS_PMIC_OFF					0			//	Exynos-4412 RESET Off

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
extern void WL9FM_EXYNOS_POWER_ONOFF(uint8_t BitData);
extern void WL9FM_EXYNOS_PMIC_PWRON(void);
//	++, kutelf, 140801
//	RevD.01.01
//	�Լ� ����
extern void WL9FM_EXYNOS_PMIC_PWRONOFF(uint8_t BitData);
//	--, kutelf, 140801
extern void WL9FM_CAMERA_nRESET(void);
extern void WL9FM_PowerIG(uint8_t BitData);
extern uint8_t WL9FM_GetPowerIG(void);
//	++, kutelf, 140801
//	RevD.01.01
//	PMIC nRESET �߰� 
extern void WL9FM_EXYNOS_PMIC_PWROFF(void);
extern void WL9FM_EXYNOS_PMIC_nRESET(void);
extern void WL9FM_EXYNOS_PMIC_nRESET_ONOFF(uint8_t BitData);
//	--, kutelf, 140801

#endif /* __GPIO_Control_H */

