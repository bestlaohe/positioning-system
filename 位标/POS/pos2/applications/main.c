///********************************** (C) COPYRIGHT *******************************
//* File Name          : main.c
//* Author             : WCH
//* Version            : V1.0.0
//* Date               : 2020/04/30
//* Description        : Main program body.
//* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
//* SPDX-License-Identifier: Apache-2.0
//*******************************************************************************/
#include "ch32v30x.h"
#include <rtthread.h>
#include <rthw.h>
#include "drivers/pin.h"
#include "board.h"
#include "led.h"
#include "usart2.h"
#include "usart2and3.h"
#include "mythread.h"

///*********************************************************************
// * @fn      main
// *
// * @brief   main只是一个线程之一，除此之外还有tshell,idle
// *          本main只是一个LED闪烁，main线程的注册在rtthread_startup中，tshell使用了串口
// *         接收中断，中断栈和线程栈使用分开.
// *
// * @return  none
// *********************************************************************/
char Rx2_Buffer[]="0";
char Rx3_Buffer[]="0";
int flagusart2=0;
int flagusart3=0;
#define THREAD_PRIORITY 15
#define THREAD_TIMESLICE 20

/* 线程控制块指针 */
rt_thread_t open2 = RT_NULL;
rt_thread_t open3 = RT_NULL;
rt_thread_t sendtousart3 = RT_NULL;

int main()
    {
        rt_kprintf("\r\n MCU: CH32V307\r\n");
        rt_kprintf(" SysClk: %dHz\r\n",SystemCoreClock);
        rt_kprintf(" www.wch.cn\r\n");
        Delay_Init();
        USARTx_CFG();       //串口初始化
        I_INIT();  //火焰模块的初始化

        /*以下是线程的创建与使用*/
        open2 = rt_thread_create("thread1", uart2_sample, RT_NULL,//线程1是打开串口2的接收线程
        1024, THREAD_PRIORITY, THREAD_TIMESLICE);
        if(open2 != RT_NULL)
            {
            /* 启动线程 */
            rt_thread_startup(open2);
            }

        open3 = rt_thread_create("thread2", uart3_sample, RT_NULL,//线程2是打开串口3的接收线程
        1024, THREAD_PRIORITY, THREAD_TIMESLICE);
        if(open3 != RT_NULL)
            {
            /* 启动线程 */
            rt_thread_startup(open3);
            }
        ibeacon();                                                //打开观察者模式接收数据


        sendtousart3 = rt_thread_create("thread3", sendandprocess, RT_NULL,//线程3发送给串口3
        1024, THREAD_PRIORITY, THREAD_TIMESLICE);

        if(sendtousart3 != RT_NULL)
            {
            /* 启动线程 */
            rt_thread_startup(sendtousart3);
            }

       return 0;
    }

// LED1_BLINK_INIT();  //灯的初始化





