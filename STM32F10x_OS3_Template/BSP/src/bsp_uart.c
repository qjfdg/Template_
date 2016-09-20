#include "stm32f10x.h"
#include "bsp_uart.h"
#include <stdio.h>




void BSP_UART_ConfigInit(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    /* Enable GPIO clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);

    /* Enable USART1 clock */
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE); 
    
    /* Configure USART Tx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    /* Configure USART Rx as alternate function push-pull */
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;//∏°ø’ ‰»Î
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    
    
    /* USART resources configuration (Clock, GPIO pins and USART registers) ----*/
    /* USART configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Hardware flow control disabled (RTS and CTS signals)
        - Receive and transmit enabled 
    */
    USART_InitStructure.USART_BaudRate            = 115200;
    USART_InitStructure.USART_WordLength          = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits            = USART_StopBits_1;
    USART_InitStructure.USART_Parity              = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode                = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    
    /* Enable USART */
    USART_Cmd(USART1, ENABLE);
}


#ifdef TRACE_UART

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;

#if (APP_CFG_SERIAL_EN == DEF_ENABLED)
int fputc(int ch, FILE *f) 
{
    USART_SendData(USART1, ch);
    while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)!=SET){;}
    return(ch);
}
#endif
#endif







