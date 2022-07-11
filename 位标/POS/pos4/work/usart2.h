/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-09     12630       the first version
 */
#include "ch32v30x.h"
#include <rtthread.h>

#ifndef APPLICATIONS_USART2_H_
#define APPLICATIONS_USART2_H_

 //void serial_thread_entry(void *parameter);
//void uart_send();
void uart2_sample(void *parameter);
void dataprocess();
#endif /* APPLICATIONS_USART2_H_ */
