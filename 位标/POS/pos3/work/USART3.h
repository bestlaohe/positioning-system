/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-15     12630       the first version
 */
#include "ch32v30x.h"
#include <rtthread.h>
#include <rthw.h>
#include "drivers/pin.h"
#include "board.h"
#include "led.h"
#include "usart2.h"
#include "usart2and3.h"
extern int flagusart3;
 //void serial_thread_entry(void *parameter);
//void uart_send();
void uart3_sample(void *parameter);




