/*
 * usart2and3.c
 *
 *  Created on: 2022��4��9��
 *      Author: 12630
 */
//#include "stdarg.h"
//#include <stdio.h>
//#include <stdint.h>

#include "usart2and3.h"
//void USARTx_CFG(void)
//{
//
////        GPIO_InitTypeDef  GPIO_InitStructure = {0};
////        USART_InitTypeDef USART_InitStructure = {0};
////        NVIC_InitTypeDef  NVIC_InitStructure = {0};
////
////        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 | RCC_APB1Periph_USART3, ENABLE);
////        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);
////        //串口1 A9 A10
////        /* USART2 TX-->A.2   RX-->A.3 */
////        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
////        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
////        GPIO_Init(GPIOA, &GPIO_InitStructure);
////        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
////        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
////        GPIO_Init(GPIOA, &GPIO_InitStructure);
////        /* USART3 TX-->B.10  RX-->B.11 */
////        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
////        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
////        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
////        GPIO_Init(GPIOB, &GPIO_InitStructure);
////        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
////        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
////        GPIO_Init(GPIOB, &GPIO_InitStructure);
////
////        USART_InitStructure.USART_BaudRate = 115200;
////        USART_InitStructure.USART_WordLength = USART_WordLength_8b;
////        USART_InitStructure.USART_StopBits = USART_StopBits_1;
////        USART_InitStructure.USART_Parity = USART_Parity_No;
////        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
////        USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
////
////        USART_Init(USART2, &USART_InitStructure);
////        USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
////
////        USART_Init(USART3, &USART_InitStructure);
////        USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
////
////        NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
////        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
////        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
////        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
////        NVIC_Init(&NVIC_InitStructure);
////
////        NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
////        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
////        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
////        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
////        NVIC_Init(&NVIC_InitStructure);
////
////        USART_Cmd(USART2, ENABLE);
////        USART_Cmd(USART3, ENABLE);
//
//
//
//
//
//
//        GPIO_InitTypeDef  GPIO_InitStructure = {0};
//        USART_InitTypeDef USART_InitStructure = {0};
//        NVIC_InitTypeDef  NVIC_InitStructure = {0};
//
//        RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2 | RCC_APB1Periph_USART3 |RCC_APB1Periph_UART6 , ENABLE);
//        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);
//        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE);   //打开重映射时钟和USART重映射后的I/O口引脚时钟
//        GPIO_PinRemapConfig(GPIO_FullRemap_USART3,ENABLE);           //管脚复用功能
//
//        /* USART2 TX-->A.2   RX-->A.3 */
//        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
//        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//        GPIO_Init(GPIOA, &GPIO_InitStructure);
//        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
//        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//        GPIO_Init(GPIOA, &GPIO_InitStructure);
//        /* USART3 TX-->D.8  RX-->D.9 */
//        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
//        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//        GPIO_Init(GPIOD, &GPIO_InitStructure);
//        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//        GPIO_Init(GPIOD, &GPIO_InitStructure);
//        /* UART6 TX-->pc0  RX-->pc1 */
//        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
//        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//        GPIO_Init(GPIOC, &GPIO_InitStructure);
//        GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
//        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//        GPIO_Init(GPIOC, &GPIO_InitStructure);
//
//        USART_InitStructure.USART_BaudRate = 115200;
//        USART_InitStructure.USART_WordLength = USART_WordLength_8b;
//        USART_InitStructure.USART_StopBits = USART_StopBits_1;
//        USART_InitStructure.USART_Parity = USART_Parity_No;
//        USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//        USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
//
//        USART_Init(USART2, &USART_InitStructure);
//        USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);
//
//        USART_Init(USART3, &USART_InitStructure);
//        USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
//
//        USART_Init(UART6, &USART_InitStructure);
//        USART_ITConfig(UART6, USART_IT_RXNE, ENABLE);
//
//        NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
//        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//        NVIC_Init(&NVIC_InitStructure);
//
//        NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
//        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//        NVIC_Init(&NVIC_InitStructure);
//
//        NVIC_InitStructure.NVIC_IRQChannel = UART6_IRQn;
//        NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//        NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//        NVIC_Init(&NVIC_InitStructure);
//
//        USART_Cmd(USART2, ENABLE);
//        USART_Cmd(USART3, ENABLE);
//        USART_Cmd(UART6 , ENABLE);
//}
void USARTx_CFG(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure = {0};
    USART_InitTypeDef USART_InitStructure = {0};
    NVIC_InitTypeDef  NVIC_InitStructure = {0};

    RCC_APB1PeriphClockCmd( RCC_APB1Periph_USART2|RCC_APB1Periph_USART3|RCC_APB1Periph_UART4|RCC_APB1Periph_UART5|RCC_APB1Periph_UART6|RCC_APB1Periph_UART7|RCC_APB1Periph_UART8, ENABLE);
//    RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE);   //打开重映射时钟和USART重映射后的I/O口引脚时钟
    GPIO_PinRemapConfig(GPIO_FullRemap_USART3,ENABLE);           //管脚复用功能
//    /* USART1 TX-->A.9  RX-->A.10 */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_Init(GPIOA, &GPIO_InitStructure);
    /* USART2 TX-->A.2  RX-->A.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    /* USART3 TX-->D.8  RX-->D.9 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    /* UART4 TX-->C.10  RX-->C.11 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    /* UART5 TX-->C.12  RX-->D.12 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
    /* UART6 TX-->C.0  RX-->C.1 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    /* UART7 TX-->C.2  RX-->C.3 */
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOC, &GPIO_InitStructure);
//    /* UART8 TX-->C.4  RX-->C.5 */
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
//    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIOC, &GPIO_InitStructure);
//    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
//    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_Init(GPIOC, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

//    USART_Init(USART1, &USART_InitStructure);
//    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    USART_Init(USART2, &USART_InitStructure);
    USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//初始化全部关闭
    USART_Init(USART3, &USART_InitStructure);
    USART_ITConfig(USART3, USART_IT_RXNE, DISABLE);
    USART_Init(UART4, &USART_InitStructure);
    USART_ITConfig(UART4, USART_IT_RXNE, DISABLE);
    USART_Init(UART5, &USART_InitStructure);
    USART_ITConfig(UART5, USART_IT_RXNE, DISABLE);
    USART_Init(UART6, &USART_InitStructure);
    USART_ITConfig(UART6, USART_IT_RXNE, DISABLE);
    USART_Init(UART7, &USART_InitStructure);
    USART_ITConfig(UART7, USART_IT_RXNE, ENABLE);
//    USART_Init(UART8, &USART_InitStructure);
//    USART_ITConfig(UART8, USART_IT_RXNE, DISABLE);

//    NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = UART5_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = UART6_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
    NVIC_InitStructure.NVIC_IRQChannel = UART7_IRQn;
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_InitStructure);
//    NVIC_InitStructure.NVIC_IRQChannel = UART8_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);

//    USART_Cmd(USART1, ENABLE);
    USART_Cmd(USART2, ENABLE);
    USART_Cmd(USART3, ENABLE);
    USART_Cmd(UART4, ENABLE);
    USART_Cmd(UART5, ENABLE);
    USART_Cmd(UART6, ENABLE);
    USART_Cmd(UART7, ENABLE);
//    USART_Cmd(UART8, ENABLE);
}

/*int fputc(int ch,FILE *f)
{
uint8_t temp=ch;
HAL_UART_Transmit(&huart1,&temp,1,2);
return temp;
}*/

