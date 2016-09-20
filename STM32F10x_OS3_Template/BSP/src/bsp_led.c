#include "bsp_led.h"







void BSP_LED_ConfigInit(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;;


    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_Init(GPIOE, &GPIO_InitStructure);
    
    BSP_LED_Off(0);
}





void  BSP_LED_Off (uint8_t led)
{
    switch (led) {
        case 0:
             GPIO_SetBits(GPIOB, GPIO_Pin_5);
             GPIO_SetBits(GPIOE, GPIO_Pin_5);
             break;

        case 1:
             GPIO_SetBits(GPIOB, GPIO_Pin_5);
             break;

        case 2:
             GPIO_SetBits(GPIOE, GPIO_Pin_5);
             break;


        default:
             break;
    }
}

void  BSP_LED_On (uint8_t led)
{
    switch (led) {
        case 0:
             GPIO_ResetBits(GPIOB, GPIO_Pin_5);
             GPIO_ResetBits(GPIOE, GPIO_Pin_5);
             break;

        case 1:
             GPIO_ResetBits(GPIOB, GPIO_Pin_5);
             break;

        case 2:
             GPIO_ResetBits(GPIOE, GPIO_Pin_5);
             break;

        default:
             break;
    }
}

void  BSP_LED_Toggle (uint8_t led)
{
    switch (led) {
        case 0:
             GPIOB->ODR ^= GPIO_Pin_5;
             GPIOE->ODR ^= GPIO_Pin_5;
             break;

        case 1:
             GPIOB->ODR ^= GPIO_Pin_5;
             break;
        case 2:
             GPIOE->ODR ^= GPIO_Pin_5;
             break;


        default:
             break;
    }
}


