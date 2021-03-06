/**
  ******************************************************************************
  * @file    TW8816_Control.c 
  * @author  kutelf (kutelf@taeha.co.kr)
  * @version V1.0.0
  * @date    02/22/2013
  * @brief   TW8816_Control.c module
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

// ++, sys3215, 141211
extern u8 Hardware_Revision;
// --, sys3215, 141211

#if 0
u8 InitCVBSAll_8816[] = 
{
	
	0xFF,0x0,	//Page 0
	0x0,0x22,	
	0x1,0x93,	
	0x2,0x40,	
	0x3,0x0,	
	0x4,0x0,	
	0x5,0x8D,	
	0x6,0x3,	
	0x7,0x2,	
	0x8,0x14,	
	0x9,0xF3,	
	0x0A,0x0F,	
	0x0B,0xD0,	
	0x0C,0xDC,	
	0x0D,0x15,	
	0x0E,0x80,	
	0x0F,0x0,	
	0x10,0x0,	
	0x11,0x5C,	
	0x12,0x13,	
	0x13,0x80,	
	0x14,0x80,	
	0x15,0x0,	
	0x16,0xC3,	
	0x17,0x30,	
	0x18,0x44,	
	0x19,0x0,	
	0x1A,0x90,	
	0x1B,0x0,	
	0x1C,0x27,	
	0x1D,0x7F,	
	0x1E,0x8,	
	0x1F,0x0,	
	0x20,0x50,	
	0x21,0x42,	
	0x22,0xF0,	
	0x23,0xD8,	
	0x24,0xBC,	
	0x25,0xB8,	
	0x26,0x44,	
	0x27,0x2A,	
	0x28,0x0,	
	0x29,0x0,	
	0x2A,0x78,	
	0x2B,0x44,	
	0x2C,0x30,	
	0x2D,0x4,	
	0x2E,0xA5,	
	0x2F,0xE0,	
	0x30,0x10,	
	0x31,0x0,	
	0x32,0x0,	
	0x33,0x5,	
	0x34,0x9A,	
	0x35,0x30,	
	0x36,0x0,	
	0x37,0x0,	
	0x38,0x8E,	
	0x39,0x0,	
	0x3A,0x0,	
	0x3B,0x0,	
	0x3C,0x0,	
	0x3D,0x0,	
	0x3E,0x0,	
	0x3F,0x0,	
	0x40,0x0,	
	0x41,0x20,	
	0x42,0x4,	
	0x43,0x22,	
	0x44,0x18,	
	0x45,0x50,	
	0x46,0x20,	
	0x47,0x0,	
	0x48,0xCF,	
	0x49,0x61,	
	0x4A,0x13,	
	0x4B,0x13,	
	0x4C,0x0,	
	0x4D,0x30,	
	0x4E,0x0,	
	0x4F,0x0,	
	0x50,0x0,	
	0x51,0x20,	
	0x52,0xFF,	
	0x53,0x10,	
	0x54,0x20,	
	0x55,0xFA,	
	0x56,0x0,	
	0x57,0x0,	
	0x58,0x0,	
	0x59,0x0,	
	0x5A,0x0,	
	0x5B,0x30,	
	0x5C,0x0,	
	0x5D,0x30,	
	0x5E,0x0,	
	0x5F,0x0,	
	0x60,0xE3,	
	0x61,0x80,	
	0x62,0x80,	
	0x63,0x0,	
	0x64,0x0,	
	0x65,0x80,	
	0x66,0x0,	
	0x67,0x0,	
	0x68,0x0,	
	0x69,0x0,	
	0x6A,0x0,	
	0x6B,0x0,	
	0x6C,0x0,	
	0x6D,0x0,	
	0x6E,0x0,	
	0x6F,0x0,	
	0x70,0x60,	
	0x71,0x80,	
	0x72,0x80,	
	0x73,0x80,	
	0x74,0x80,	
	0x75,0x80,	
	0x76,0x80,	
	0x77,0x3F,	
	0x78,0x0A,	
	0x79,0x0,	
	0x7A,0x30,	
	0x7B,0x0,	
	0x7C,0x1C,	
	0x7D,0x8,	
	0x7E,0xF6,	
	0x7F,0x8,	
	0x80,0x10,	
	0x81,0x0D,	
	0x82,0x3,	
	0x83,0x0,	
	0x84,0x67,	
	0x85,0x94,	
	0x86,0x18,	
	0x87,0xE8,	
	0x88,0xCA,	
	0x89,0x2,	
	0x8A,0x0A,	
	0x8B,0x4,	
	0x8C,0x0,	
	0x8D,0x0,	
	0x8E,0x0,	
	0x8F,0x0,	
	0x90,0x0,	
	0x91,0x6,	
	0x92,0x6,	
	0x93,0x6,	
	0x94,0x0,	
	0x95,0x40,	
	0x96,0x0,	
	0x97,0x0,	
	0x98,0x0,	
	0x99,0x8,	
	0x9A,0x0,	
	0x9B,0x31,	
	0x9C,0x0,	
	0x9D,0x0,	
	0x9E,0x0,	
	0x9F,0x0,	
	0xA0,0x0,	
	0xA1,0x0,	
	0xA2,0x0,	
	0xA3,0x0,	
	0xA4,0x0,	
	0xA5,0xE0,	
	0xA6,0x0,	
	0xA7,0x0,	
	0xA8,0x0,	
	0xA9,0x0,	
	0xAA,0x0,	
	0xAB,0x0,	
	0xAC,0x0,	
	0xAD,0x0,	
	0xAE,0x0,	
	0xAF,0x0,	
	0xB0,0x40,	
	0xB1,0x0,	
	0xB2,0xCC,	
	0xB3,0x1,	
	0xB4,0x10,	
	0xB5,0x20,	
	0xB6,0x33,	
	0xB7,0x12,	
	0xB8,0x1,	
	0xB9,0x29,	
	0xBA,0xE0,	
	0xBB,0x12,	
	0xBC,0x0,	
	0xBD,0x0C,	
	0xBE,0xC2,	
	0xBF,0x0,	
	0xC0,0x0,	
	0xC1,0x0,	
	0xC2,0x0,	
	0xC3,0x0,	
	0xC4,0x40,	
	0xC5,0x0,	
	0xC6,0x0,	
	0xC7,0x0,	
	0xC8,0x0,	
	0xC9,0x0,	
	0xCA,0x0,	
	0xCB,0x0,	
	0xCC,0x0,	
	0xCD,0x0,	
	0xCE,0x0,	
	0xCF,0x0,	
	0xD0,0xC9,	
	0xD1,0x4C,	
	0xD2,0xFF,	
	0xD3,0x7,	
	0xD4,0x0,	
	0xD5,0x3F,	
	0xD6,0x0,	
	0xD7,0x0,	
	0xD8,0x0,	
	0xD9,0x0,	
	0xDA,0x3D,	
	0xDB,0xC3,	
	0xDC,0xFC,	
	0xDD,0x0,	
	0xDE,0x0,	
	0xDF,0x0,	
	0xE0,0x0,	
	0xE1,0x0,	
	0xE2,0x0,	
	0xE3,0x0,	
	0xE4,0x0,	
	0xE5,0x0,	
	0xE6,0x0,	
	0xE7,0x0,	
	0xE8,0x0,	
	0xE9,0x0,	
	0xEA,0x0,	
	0xEB,0x0,	
	0xEC,0x0,	
	0xED,0x0,	
	0xEE,0x0,	
	0xEF,0x0,	
	0xF0,0x0,	
	0xF1,0x20,	
	0xF2,0x0,	
	0xF3,0x0,	
	0xF4,0x16,	
	0xF5,0x0,	
	0xF6,0x0,	
	0xF7,0x0,	
	0xF8,0x0,	
	0xF9,0x20,	
	0xFA,0x90,	
	0xFB,0x0,	
	0xFC,0x40,	
	0xFD,0x34,	
	0xFE,0x0,	
	0xFF,0x0,	
	
	0xFF,0x1,	//Page 1
	0x0,0x0,	
	0x1,0x40,	
	0x2,0xBF,	
	0x3,0x86,	
	0x4,0x0,	
	0x5,0x0,	
	0x6,0x0,	
	0x7,0x0,	
	0x8,0x0,	
	0x9,0x0,	
	0x0A,0x0,	
	0x0B,0x0,	
	0x0C,0x0,	
	0x0D,0x0,	
	0x0E,0x0,	
	0x0F,0x0,	
	0x10,0x0,	
	0x11,0x0,	
	0x12,0x0,	
	0x13,0x0,	
	0x14,0x0,	
	0x15,0x0,	
	0x16,0x0,	
	0x17,0x0,	
	0x18,0x0,	
	0x19,0x0,	
	0x1A,0x0,	
	0x1B,0x0,	
	0x1C,0x0,	
	0x1D,0x0,	
	0x1E,0x0,	
	0x1F,0x0,	
	0x20,0x0,	
	0x21,0x0,	
	0x22,0x0,	
	0x23,0x0,	
	0x24,0x0,	
	0x25,0x0,	
	0x26,0x0,	
	0x27,0x0,	
	0x28,0x0,	
	0x29,0x0,	
	0x2A,0x0,	
	0x2B,0x0,	
	0x2C,0x0,	
	0x2D,0x0,	
	0x2E,0x0,	
	0x2F,0x0,	
	0x30,0xF2,	
	0x31,0xAD,	
	0x32,0x4,	
	0x33,0x80,	
	0x34,0x84,	
	0x35,0x0,	
	0x36,0x20,	
	0x37,0x0,	
	0x38,0x0,	
	0x39,0x0,	
	0x3A,0x0,	
	0x3B,0x0,	
	0x3C,0x0,	
	0x3D,0x0,	
	0x3E,0x0,	
	0x3F,0x0,	
	0x40,0x0,	
	0x41,0x0,	
	0x42,0xEE,	
	0x43,0x0,	
	0x44,0x0,	
	0x45,0x0,	
	0x46,0x0,	
	0x47,0x0,	
	0x48,0x0,	
	0x49,0x0,	
	0x4A,0x0,	
	0x4B,0x0,	
	0x4C,0x0,	
	0x4D,0x0,	
	0x4E,0x0,	
	0x4F,0x0,	
	0x50,0x0,	
	0x51,0x0,	
	0x52,0x0,	
	0x53,0x0,	
	0x54,0x0,	
	0x55,0x0,	
	0x56,0x0,	
	0x57,0x41,	
	0x58,0x2,	
	0x59,0x0,	
	0x5A,0x0,	
	0x5B,0x0,	
	0x5C,0x0,	
	0x5D,0x0,	
	0x5E,0x0,	
	0x5F,0x0,	
	0x60,0x0,	
	0x61,0x0,	
	0x62,0x0,	
	0x63,0x0,	
	0x64,0x0,	
	0x65,0x0,	
	0x66,0x0,	
	0x67,0x0,	
	0x68,0x0,	
	0x69,0x0,	
	0x6A,0x0,	
	0x6B,0x0,	
	0x6C,0x0,	
	0x6D,0x0,	
	0x6E,0x0,	
	0x6F,0x0,	
	0x70,0x0,	
	0x71,0x0,	
	0x72,0x0,	
	0x73,0x0,	
	0x74,0x0,	
	0x75,0x0,	
	0x76,0x0,	
	0x77,0x5A,	
	0x78,0x0,	
	0x79,0x7F,	
	0x7A,0x1,	
	0x7B,0x0E,	
	0x7C,0x0,	
	0x7D,0x20,	
	0x7E,0x1,	
	0x7F,0xE2,	
	0x80,0x0,	
	0x81,0x0,	
	0x82,0x7,	
	0x83,0x1F,	
	0x84,0x64,	
	0x85,0x0,	
	0x86,0x0,	
	0x87,0x0,	
	0x88,0x0,	
	0x89,0x0,	
	0x8A,0x2,	
	0x8B,0x4D,	
	0x8C,0x0,	
	0x8D,0x0,	
	0x8E,0x2,	
	0x8F,0x0E,	
	0x90,0x3,	
	0x91,0x59,	
	0x92,0x3,	
	0x93,0x57,	
	0x94,0x0,	
	0x95,0x1,	
	0x96,0x0,	
	0x97,0x0,	
	0x98,0x0,	
	0x99,0x0,	
	0x9A,0x0,	
	0x9B,0x36,	
	0x9C,0x0,	
	0x9D,0x1,	
	0x9E,0x0,	
	0x9F,0x0,	
	0xA0,0x2,	
	0xA1,0x68,	
	0xA2,0x0,	
	0xA3,0x52,	
	0xA4,0x0,	
	0xA5,0x24,	
	0xA6,0x0,	
	0xA7,0x1,	
	0xA8,0x0,	
	0xA9,0x0,	
	0xAA,0x0,	
	0xAB,0x0,	
	0xAC,0x0,	
	0xAD,0xF6,	
	0xAE,0x0,	
	0xAF,0x6A,	
	0xB0,0x2,	
	0xB1,0x3,	
	0xB2,0x88,	
	0xB3,0x0,	
	0xB4,0x0,	
	0xB5,0x0,	
	0xB6,0x0,	
	0xB7,0x0,	
	0xB8,0x0,	
	0xB9,0x0,	
	0xBA,0x0,	
	0xBB,0x0,	
	0xBC,0x0,	
	0xBD,0x0,	
	0xBE,0x0,	
	0xBF,0x0,	
	0xC0,0x5,	
	0xC1,0xC7,	
	0xC2,0x3,	
	0xC3,0x3,	
	0xC4,0x5A,	
	0xC5,0x11,	
	0xC6,0x20,	
	0xC7,0x4,	
	0xC8,0x0,	
	0xC9,0x0,	
	0xCA,0x0,	
	0xCB,0x10,	
	0xCC,0x4,	
	0xCD,0x0,	
	0xCE,0x0,	
	0xCF,0x24,	
	0xD0,0x0,	
	0xD1,0xF0,	
	0xD2,0xF0,	
	0xD3,0xF0,	
	0xD4,0x20,	
	0xD5,0x0,	
	0xD6,0x10,	
	0xD7,0x0,	
	0xD8,0x42,	
	0xD9,0x10,	
	0xDA,0x80,	
	0xDB,0x80,	
	0xDC,0x20,	
	0xDD,0x1,	
	0xDE,0x0,	
	0xDF,0x0,	
	0xE0,0x0,	
	0xE1,0x0,	
	0xE2,0x0,	
	0xE3,0x0,	
	0xE4,0x0,	
	0xE5,0x0,	
	0xE6,0x0,	
	0xE7,0x0,	
	0xE8,0x0,	
	0xE9,0x0,	
	0xEA,0x0,	
	0xEB,0x0,	
	0xEC,0x0,	
	0xED,0x0,	
	0xEE,0x0,	
	0xEF,0x0,	
	0xF0,0xF0,	
	0xF1,0x0,	
	0xF2,0xAD,	
	0xF3,0x19,	
	0xF4,0x0,	
	0xF5,0xE8,	
	0xF6,0x0,	
	0xF7,0xE8,	
	0xF8,0x0,	
	0xF9,0x0,	
	0xFA,0x0,	
	0xFB,0x0,	
	0xFC,0x0,	
	0xFD,0x0,	
	0xFE,0x0,	
	0xFF,0x1	
	
} ;
#else
u8 InitCVBSAll_8816[] = 
{
	
	0xFF,0x0,	//Page 0
	0x0,0x22,	
	0x1,0x93,	
	0x2,0x40,	
	0x3,0x0,	
	0x4,0x0,	
	0x5,0x8D,	
	0x6,0x3,	
	0x7,0x2,	
	0x8,0x14,	
	0x9,0xF3,	
	0x0A,0x0F,	
	0x0B,0xD0,	
	0x0C,0xDC,	
	0x0D,0x15,	
	0x0E,0x80,	
	0x0F,0x0,	
	0x10,0x0,	
	0x11,0x5C,	
	0x12,0x13,	
	0x13,0x80,	
	0x14,0x80,	
	0x15,0x0,	
	0x16,0xC3,	
	0x17,0x30,	
	0x18,0x44,	
	0x19,0x0,	
	0x1A,0x90,	
	0x1B,0x0,	
	0x1C,0x27,	
	0x1D,0x7F,	
	0x1E,0x8,	
	0x1F,0x0,	
	0x20,0x50,	
	0x21,0x42,	
	0x22,0xF0,	
	0x23,0xD8,	
	0x24,0xBC,	
	0x25,0xB8,	
	0x26,0x44,	
	0x27,0x2A,	
	0x28,0x0,	
	0x29,0x0,	
	0x2A,0x78,	
	0x2B,0x44,	
	0x2C,0x30,	
	0x2D,0x4,	
	0x2E,0xA5,	
	0x2F,0xE0,	
	0x30,0x10,	
	0x31,0x0,	
	0x32,0x0,	
	0x33,0x5,	
	0x34,0x9A,	
	0x35,0x30,	
	0x36,0x0,	
	0x37,0x0,	
	0x38,0x8E,	
	0x39,0x0,	
	0x3A,0x0,	
	0x3B,0x0,	
	0x3C,0x0,	
	0x3D,0x0,	
	0x3E,0x0,	
	0x3F,0x0,	
	0x40,0x0,	
	0x41,0x20,	
	0x42,0x4,	
	0x43,0x22,	
	0x44,0x18,	
	0x45,0x50,	
	0x46,0x20,	
	0x47,0x0,	
	0x48,0xCF,	
	0x49,0x61,	
	0x4A,0x13,	
	0x4B,0x13,	
	0x4C,0x0,	
	0x4D,0x30,	
	0x4E,0x0,	
	0x4F,0x0,	
	0x50,0x0,	
	0x51,0x20,	
	0x52,0xFF,	
	0x53,0x10,	
	0x54,0x20,	
	0x55,0xFA,	
	0x56,0x0,	
	0x57,0x0,	
	0x58,0x0,	
	0x59,0x0,	
	0x5A,0x0,	
	0x5B,0x30,	
	0x5C,0x0,	
	0x5D,0x30,	
	0x5E,0x0,	
	0x5F,0x0,	
	
	//0x60,0xE3,	
	//0x61,0x80,	
	//0x62,0x80,	

	// ++, 150323 sys No zoom
	//0x60,0xE3,	
	//0x61,0x80,	
	//0x62,0x80,	
	//0x63,0x0,	
	
	0x60,0x00,  // X_SCALE_UP_MID
	0x61,0x80,	
	//0x62,0x80,
	//0x63,0x01,
	0x62,0x80,
	0x63,0x01,	

	// --, 150323 sys
	
	0x64,0x0,	
	0x65,0x80,	

	// ++, 150323 sys
	//0x66,0x0,	
	//0x67,0x0,
	0x66,0x2c,	// H_NON_DISPLAY
	0x67,0x0,
	// --, 150323 sys

	// ++, 150323 sys
	//0x68,0x0,	// X_SCALE_UP_LO
	
	0x68,000,	// X_SCALE_UP_LO
	// --, 150323 sys
	0x69,0x0,	
	0x6A,0x0,	
	0x6B,0x0,	
	0x6C,0x0,	
	0x6D,0x0,	
	0x6E,0x0,	
	0x6F,0x0,	
	0x70,0x60,	
	0x71,0x80,	
	0x72,0x80,	
	0x73,0x80,	
	0x74,0x80,	
	0x75,0x80,	
	0x76,0x80,	
	0x77,0x3F,	
	0x78,0x0A,	
	0x79,0x0,	
	0x7A,0x30,	
	0x7B,0x0,	
	0x7C,0x1C,	
	0x7D,0x8,	
	0x7E,0xF6,	
	0x7F,0x8,	
	0x80,0x10,	
	0x81,0x0D,	
	0x82,0x3,	
	0x83,0x0,	
	0x84,0x67,	
	0x85,0x94,	
	0x86,0x18,	
	0x87,0xE8,	
	0x88,0xCA,	
	0x89,0x2,	
	0x8A,0x0A,	
	0x8B,0x4,	
	0x8C,0x0,	
	0x8D,0x0,	
	0x8E,0x0,	
	0x8F,0x0,	
	0x90,0x0,	
	0x91,0x6,	
	0x92,0x6,	
	0x93,0x6,	
	0x94,0x0,	
	0x95,0x40,	
	0x96,0x0,	
	0x97,0x0,	
	0x98,0x0,	
	0x99,0x8,	
	0x9A,0x0,	
	0x9B,0x31,	
	0x9C,0x00,	
	0x9D,0x0,	
	
	0x9E,0x0,	
	0x9F,0x01,	
	0xA0,0x0,	
	0xA1,0x0,	
	0xA2,0x0,	
	0xA3,0x22,	
	0xA4,0x0E,	
	0xA5,0x32,	
	0xA6,0x0,	
	0xA7,0x0,	
	0xA8,0x0,	
	0xA9,0x50,	
	0xAA,0x0,	
	0xAB,0x44,	
	0xAC,0x0F,	
	0xAD,0x0,	
	0xAE,0x0,	
	0xAF,0x0,	
	0xB0,0x40,	
	0xB1,0x0,	
	0xB2,0xCC,	
	0xB3,0x1,	
	0xB4,0x10,	
	0xB5,0x20,	
	0xB6,0x33,	
	0xB7,0x12,	
	0xB8,0x1,	
	0xB9,0x29,	
	0xBA,0xE0,	
	0xBB,0x12,	
	0xBC,0x0,	
	0xBD,0x0C,	
	0xBE,0xC2,	
	0xBF,0x0,	
	0xC0,0x0,	
	0xC1,0x0,	
	0xC2,0x0,	
	0xC3,0x0,	
	0xC4,0x40,	
	0xC5,0x0,	
	0xC6,0x0,	
	0xC7,0x0,	
	0xC8,0x0,	
	0xC9,0x0,	
	0xCA,0x0,	
	0xCB,0x0,	
	0xCC,0x0,	
	0xCD,0x0,	
	0xCE,0x0,	
	0xCF,0x0,	
	0xD0,0xC9,	
	0xD1,0x4C,	
	0xD2,0xFF,	
	0xD3,0x7,	
	0xD4,0x0,	
	0xD5,0x3F,	
	0xD6,0x0,	
	0xD7,0x0,	
	0xD8,0x0,	
	0xD9,0x0,	
	0xDA,0x3D,	
	0xDB,0xC3,	
	0xDC,0xFC,	
	0xDD,0x0,	
	0xDE,0x0,	
	0xDF,0x0,	
	0xE0,0x0,	
	0xE1,0x0,	
	0xE2,0x0,	
	0xE3,0x0,	
	0xE4,0x0,	
	0xE5,0x0,	
	0xE6,0x0,	
	0xE7,0x0,	
	0xE8,0x0,	
	0xE9,0x0,	
	0xEA,0x0,	
	0xEB,0x0,	
	0xEC,0x0,	
	0xED,0x0,	
	0xEE,0x0,	
	0xEF,0x0,	
	0xF0,0x0,	
	0xF1,0x20,	
	0xF2,0x0,	
	0xF3,0x0,	
	0xF4,0x16,	
	0xF5,0x0,	
	0xF6,0x0,	
	0xF7,0x0,	
	0xF8,0x0,	
	0xF9,0x20,	
	0xFA,0x90,	
	0xFB,0x0,	
	0xFC,0x40,	
	0xFD,0x34,	
	0xFE,0x0,	
	0xFF,0x0,	
	
	0xFF,0x1,	//Page 1
	0x0,0x0,	
	0x1,0x40,	
	0x2,0xBF,	
	0x3,0x86,	
	0x4,0x0,	
	0x5,0x0,	
	0x6,0x0,	
	0x7,0x0,	
	0x8,0x0,	
	0x9,0x0,	
	0x0A,0x0,	
	0x0B,0x0,	
	0x0C,0x0,	
	0x0D,0x0,	
	0x0E,0x0,	
	0x0F,0x0,	
	0x10,0x0,	
	0x11,0x0,	
	0x12,0x0,	
	0x13,0x0,	
	0x14,0x0,	
	0x15,0x0,	
	0x16,0x0,	
	0x17,0x0,	
	0x18,0x0,	
	0x19,0x0,	
	0x1A,0x0,	
	0x1B,0x0,	
	0x1C,0x0,	
	0x1D,0x0,	
	0x1E,0x0,	
	0x1F,0x0,	
	0x20,0x0,	
	0x21,0x0,	
	0x22,0x0,	
	0x23,0x0,	
	0x24,0x0,	
	0x25,0x0,	
	0x26,0x0,	
	0x27,0x0,	
	0x28,0x0,	
	0x29,0x0,	
	0x2A,0x0,	
	0x2B,0x0,	
	0x2C,0x0,	
	0x2D,0x0,	
	0x2E,0x0,	
	0x2F,0x0,	
	0x30,0xF2,	
	0x31,0xAD,	
	0x32,0x4,	
	0x33,0x80,	
	0x34,0x84,	
	0x35,0x0,	
	0x36,0x20,	
	0x37,0x0,	
	0x38,0x0,	
	0x39,0x0,	
	0x3A,0x0,	
	0x3B,0x0,	
	0x3C,0x0,	
	0x3D,0x0,	
	0x3E,0x0,	
	0x3F,0x0,	
	0x40,0x0,	
	0x41,0x0,	
	0x42,0xEE,	
	0x43,0x0,	
	0x44,0x0,	
	0x45,0x0,	
	0x46,0x0,	
	0x47,0x0,	
	0x48,0x0,	
	0x49,0x0,	
	0x4A,0x0,	
	0x4B,0x0,	
	0x4C,0x0,	
	0x4D,0x0,	
	0x4E,0x0,	
	0x4F,0x0,	
	0x50,0x0,	
	0x51,0x0,	
	0x52,0x0,	
	0x53,0x0,	
	0x54,0x0,	
	0x55,0x0,	
	0x56,0x0,	
	0x57,0x41,	
	0x58,0x2,	
	0x59,0x0,	
	0x5A,0x0,	
	0x5B,0x0,	
	0x5C,0x0,	
	0x5D,0x0,	
	0x5E,0x0,	
	0x5F,0x0,	
	0x60,0x0,	
	0x61,0x0,	
	0x62,0x0,	
	0x63,0x0,	
	0x64,0x0,	
	0x65,0x0,	
	0x66,0x0,	
	0x67,0x0,	
	0x68,0x0,	
	0x69,0x0,	
	0x6A,0x0,	
	0x6B,0x0,	
	0x6C,0x0,	
	0x6D,0x0,	
	0x6E,0x0,	
	0x6F,0x0,	
	0x70,0x0,	
	0x71,0x0,	
	0x72,0x0,	
	0x73,0x0,	
	0x74,0x0,	
	0x75,0x0,	
	0x76,0x0,	
	0x77,0x5A,	
	0x78,0x0,	
	0x79,0x7F,	
	0x7A,0x1,	
	0x7B,0x0E,	
	0x7C,0x0,	
	0x7D,0x20,	
	0x7E,0x1,	
	0x7F,0xE2,	
	0x80,0x0,	
	0x81,0x0,	
	0x82,0x7,	
	0x83,0x1F,	
	0x84,0x64,	
	0x85,0x0,	
	0x86,0x0,	
	0x87,0x0,	
	0x88,0x0,	
	0x89,0x0,	
	0x8A,0x2,	
	0x8B,0x4D,	
	0x8C,0x0,	
	0x8D,0x0,	
	0x8E,0x2,	
	0x8F,0x0E,	
	0x90,0x3,	
	0x91,0x59,	
	0x92,0x3,	
	0x93,0x57,	
	0x94,0x0,	
	0x95,0x1,	
	0x96,0x0,	
	0x97,0x0,	
	0x98,0x0,	
	0x99,0x0,	
	0x9A,0x0,	
	0x9B,0x36,	
	0x9C,0x0,	
	0x9D,0x1,	
	
	0x9E,0x0,	
	0x9F,0x0,	
	0xA0,0x2,	
	0xA1,0x68,	
	0xA2,0x0,	
	0xA3,0x52,	
	0xA4,0x0,	
	0xA5,0x24,	
	0xA6,0x0,	
	0xA7,0x1,	
	0xA8,0x0,	
	0xA9,0x0,	
	0xAA,0x0,	
	0xAB,0x0,	
	0xAC,0x0,	
	0xAD,0xF6,	
	0xAE,0x0,	
	0xAF,0x6A,	
	0xB0,0x2,	
	0xB1,0x3,	
	0xB2,0x88,	
	0xB3,0x0,	
	0xB4,0x0,	
	0xB5,0x0,	
	0xB6,0x0,	
	0xB7,0x0,	
	0xB8,0x0,	
	0xB9,0x0,	
	0xBA,0x0,	
	0xBB,0x0,	
	0xBC,0x0,	
	0xBD,0x0,	
	0xBE,0x0,	
	0xBF,0x0,	
	0xC0,0x5,	
	0xC1,0xC7,	
	0xC2,0x3,	
	0xC3,0x3,	
	0xC4,0x5A,	
	0xC5,0x11,	
	0xC6,0x20,	
	0xC7,0x4,	
	0xC8,0x0,	
	0xC9,0x0,	
	0xCA,0x0,	
	0xCB,0x10,	
	0xCC,0x4,	
	0xCD,0x0,	
	0xCE,0x0,	
	0xCF,0x24,	
	0xD0,0x0,	
	0xD1,0xF0,	
	0xD2,0xF0,	
	0xD3,0xF0,	
	0xD4,0x20,	
	0xD5,0x0,	
	0xD6,0x10,	
	0xD7,0x0,	
	0xD8,0x42,	
	0xD9,0x10,	
	0xDA,0x80,	
	0xDB,0x80,	
	0xDC,0x20,	
	0xDD,0x1,	
	0xDE,0x0,	
	0xDF,0x0,	
	0xE0,0x0,	
	0xE1,0x0,	
	0xE2,0x0,	
	0xE3,0x0,	
	0xE4,0x0,	
	0xE5,0x0,	
	0xE6,0x0,	
	0xE7,0x0,	
	0xE8,0x0,	
	0xE9,0x0,	
	0xEA,0x0,	
	0xEB,0x0,	
	0xEC,0x0,	
	0xED,0x0,	
	0xEE,0x0,	
	0xEF,0x0,	
	0xF0,0xF0,	
	0xF1,0x0,	
	0xF2,0xAD,	
	0xF3,0x19,	
	0xF4,0x0,	
	0xF5,0xE8,	
	0xF6,0x0,	
	0xF7,0xE8,	
	0xF8,0x0,	
	0xF9,0x0,	
	0xFA,0x0,	
	0xFB,0x0,	
	0xFC,0x0,	
	0xFD,0x0,	
	0xFE,0x0,	
	0xFF,0x1	
	
} ;

#endif

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**\
  * @brief  None
  * @param  None
  * @retval None
  */

void NOP_TW8816(void)
{
	TimeDelay_usec(1);	
}


void TW8816_PortChange(unsigned char dir)
{
	unsigned short temp;
	
	GPIO_InitTypeDef GPIO_InitStructure;
	
	if (dir)// Output
	{
		temp = TW8816_I2C2_PORT->IDR;			//	GPIO_ReadInputData
		temp = ((~(TW8816_I2C2_SDA)) & temp);
		TW8816_I2C2_PORT->ODR = (temp);			//	GPIO_Write
		
		GPIO_InitStructure.GPIO_Pin   = TW8816_I2C2_SDA;
		GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_OUT;
		GPIO_InitStructure.GPIO_Speed = GPIO_Speed_25MHz;
		GPIO_Init(TW8816_I2C2_PORT, &GPIO_InitStructure);	
	}
	else	// Input
	{	
		temp = TW8816_I2C2_PORT->IDR;			//	GPIO_ReadInputData
		temp = ((~(TW8816_I2C2_SDA)) & temp);
		TW8816_I2C2_PORT->ODR = (temp);			//	GPIO_Write
		
		GPIO_InitStructure.GPIO_Pin  = TW8816_I2C2_SDA;
		GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
		GPIO_Init(TW8816_I2C2_PORT, &GPIO_InitStructure);	
	}
}

void I2C2_Write_8816(u8 WData)
{
	u8 i, j;

	NOP_TW8816();

	for (i = 0; i < 8; i++)
	{
		j = ( WData & 0x80 ) ? 1 : 0;
		(j) ? GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA) : GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
		NOP_TW8816();
		TW8816_SCL1;
		NOP_TW8816();		
		WData <<= 1;
		TW8816_SCL0;
		NOP_TW8816();
	}

	GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL1;
	NOP_TW8816();
	TW8816_SCL0;
}

void I2C2_ByteWrite_8816(u16 in_AddrVal, u8 in_DataVal)
{
	u16 tmp_index;

	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	TW8816_SDAOUT;
	// START
	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	TW8816_SCL1;
	NOP_TW8816();
	GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL0;
	// END

	I2C2_Write_8816(TW8816_I2C_Addr);
	I2C2_Write_8816((u8)in_AddrVal);
	I2C2_Write_8816(in_DataVal);

	GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL1;
	NOP_TW8816();
	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);

	for (tmp_index = 0; tmp_index < 15000; tmp_index++);
}
u8 I2C2_Read_8816(void)
{
	u8 i;
	u8 RData;

	NOP_TW8816();
	TW8816_SCL0;
	NOP_TW8816();
	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	TW8816_SDAIN;

	for ( i = 0; i < 8; i++ )
	{
		TW8816_SCL1;
		NOP_TW8816();
		NOP_TW8816();
		RData = (RData << 1) | TW8816_SDA_READ;
		TW8816_SCL0;
		NOP_TW8816();
		NOP_TW8816();
	}
	GPIO_ResetBits(TW8816_I2C2_PORT, GPIO_Pin_7);
	TW8816_SDAOUT;
	return (RData );
}

u8 I2C2_ByteRead_8816(u16 in_AddrVal)
{
	u8 RData = 0;
	u16 tmp_index;

	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	TW8816_SDAOUT;
	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	TW8816_SCL1;
	NOP_TW8816();
	GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL0;

	I2C2_Write_8816(TW8816_I2C_Addr);
	I2C2_Write_8816((u8)in_AddrVal);

	NOP_TW8816();
	NOP_TW8816();

	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL1;
	NOP_TW8816();

	GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL0;

	I2C2_Write_8816(0x8b);

	RData = I2C2_Read_8816();

	// NAK
	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL1;
	NOP_TW8816();
	TW8816_SCL0;
	NOP_TW8816();

	// STOP
	GPIO_ResetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);
	NOP_TW8816();
	TW8816_SCL1;
	NOP_TW8816();
	GPIO_SetBits(TW8816_I2C2_PORT, TW8816_I2C2_SDA);

	for (tmp_index = 0; tmp_index < 15000; tmp_index++);
	return (RData);
}

void WriteTW8816(u8 in_AddrVal, u8 in_DataVal)
{
	I2C2_ByteWrite_8816(in_AddrVal, in_DataVal);
	TimeDelay_usec(500);
}

u8 ReadTW8816(u8 in_AddrVal)
{
	u8 val;

	val = I2C2_ByteRead_8816(in_AddrVal);

	return(val);
}

void I2C2DeviceInitialize_8816(u8 *RegSet)  
{
	u8 Addr, val;
       
	RegSet += 2;
	
	// 0xff, 0xff is end of data
	while (( RegSet[0] != 0xFF ) || ( RegSet[1]!= 0xFF )) 
	{			
		Addr = *RegSet;
		val = *(RegSet+1);
		I2C2_ByteWrite_8816(Addr, val);
		RegSet+=2;
	}

	WriteTW8816(0xff, 0x00);	// Set page 0
}


void InitCVBSRegister_8816( void )
{
	I2C2DeviceInitialize_8816( InitCVBSAll_8816 );
}

void TW8816_Control_Init(void)
{
	//DebugMsg_printf("++ TW8816_Control_Init (I2C2 & SPI2), ADC Initialize START\r\n");

	InitCVBSRegister_8816();

	//DebugMsg_printf("-- TW8816_Control_Init (I2C2 & SPI2), ADC Initialize END\r\n");
}

u8 CAMSig_1;

void TW8816_CheckCamera_Input(u8 Mode)
{
	
	WriteTW8816(0xff, 0x00);
	CAMSig_1 = ReadTW8816(0x01);
	if((CAMSig_1 & 0x80) >> 7== 0x01)
	{
          SetBackgroundBlueOSD();
          SetDisplayUpdate();         
	}
	else
	{
          SetBackgroundBlueOSD();
          SetDisplayUpdate();
	}
	
}
void TW8816_CameraMode(u8 Mode, u8 OSD)
{
	SetDisplayUpdate();
        SetBackgroundBlueOSD();
        //WriteTW8816(0xff, 0x00);
	//WriteTW8816(0x02, 0x40);
}
// ++, sys3215, 141211
void WL9F_CAMERA_Init(void)
{
	TW8816_Control_Init();
}
// --, sys3215, 141211
/*********(C) COPYRIGHT 2010 TaeHa Mechatronics Co., Ltd. *****END OF FILE****/

