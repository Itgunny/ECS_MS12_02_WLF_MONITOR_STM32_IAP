/**
  ******************************************************************************
  * @file    WL9F_Display_IAP.h
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/22/2013
  * @brief   Main Header
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __WL9F_Display_IAP_H
#define __WL9F_Display_IAP_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#include "stm32f4xx.h"
#include "stm324xg_eval.h"
#include "common.h"

#include "System_Init.h"
#include "TimeDelay.h"
#include "FM31X4.h"
#include "M25PXX.h"

//	++, kutelf, 140801
//	RevD.01.01
//	RevD 부터 이런 기능을 추가..
//	TW2835, TW8816 호환하기 위하여 수정. 
//#define BoardVersion_RevA
#define BoardVersion_RevB
//#define BoardVersion_RevC
//#define BoardVersion_RevD
//	--, kutelf, 140801

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __WL9F_Display_IAP_H */
