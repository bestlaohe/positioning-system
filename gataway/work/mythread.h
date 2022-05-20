/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-10     12630       the first version
 */
#include "ch32v30x.h"
#include <rtthread.h>
#include <rthw.h>
#include "drivers/pin.h"
#include "board.h"
#include "led.h"
#include "usart2.h"
#include "usart2and3.h"
#include "USART3.h"
#include "uart6.h"


void sendandprocess(void *parameter);//本线程是发送坐标给lora
void ibeacon(void);
void sendask(void *parameter);
void Fibcom_L610_init(void);//L610初始化

