#ifndef __BSP_LED_H__
#define __BSP_LED_H__


#include "stm32f10x.h"





























void BSP_LED_ConfigInit(void);
void BSP_LED_On (uint8_t led);
void BSP_LED_Off (uint8_t led);
void BSP_LED_Toggle (uint8_t led);






#endif //__BSP_LED_H__
