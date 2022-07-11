/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-06-21     12630       the first version
 */
#include "new.h"
#ifndef WORK_NEW_C_
#define WORK_NEW_C_

#endif /* WORK_NEW_C_ */

u8 TxBuffer2 = 6;//这是发送的数据，可以分别配置Slave为不同的值
u8 RequestData=0;//检测请求命令是否正确
u8 RxBuffer2=0;
u8 Rxfinish2;
#define THREAD_PRIORITY      10
#define THREAD_TIMESLICE     5
//static struct rt_thread thread;
//static char thread_stack[1024];
//void USART2_IRQHandler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
//
//void sendask2(void *parameter)
//{
//    int i;
//    uint8_t t1[]={0x0a,0X0b,0X14,0xaa,0x0d};//位标1地址0x0a,0X0b,0X14,地址2571，通道20
//    uint8_t t2[]={0x0a,0X0c,0X14,0xaa,0x0d};//位标2地址0x0a,0X0c,0X14,地址2572，通道20
//    uint8_t t3[]={0x0a,0xdd,0X14,0xaa,0x0d};//位标3地址0x0a,0X0d,0X14,地址2573，通道20
//    uint8_t t4[]={0x0a,0X0e,0X14,0xaa,0x0d};//位标4地址0x0a,0X0e,0X14,地址2574，通道20
//    uint8_t t5[]={0x0a,0X0f,0X14,0xaa,0x0d};//位标5地址0x0a,0X0f,0X14,地址2575，通道20
//    while (1)
//    {
//        for(i=0;i<5;i++)
//        uart_putstr(USART2,"%c",t1[i]); //以单个字符的方式输出
//        if( Rxfinish2)
//        {
//        for(i=0;i<5;i++)
//        uart_putstr(USART2,"%c",t2[i]); //以单个字符的方式输出
//        for(i=0;i<5;i++)
//        uart_putstr(USART2,"%c",t3[i]); //以单个字符的方式输出
//        for(i=0;i<5;i++)
//        uart_putstr(USART2,"%c",t4[i]); //以单个字符的方式输出
//        for(i=0;i<5;i++)
//        uart_putstr(USART2,"%c",t5[i]); //以单个字符的方式输出
//        }
//
//
//    }
//
//}

//void sendinit(void)
//{
//
//
//
//       rt_thread_init(&thread,
//                      "thread1",
//                      sendask2,
//                      RT_NULL,
//                      &thread_stack[0],
//                      sizeof(thread_stack),
//                      THREAD_PRIORITY, THREAD_TIMESLICE);
//       rt_thread_startup(&thread);
//
//
//
//
//}




