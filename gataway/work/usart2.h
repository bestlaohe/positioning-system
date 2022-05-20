/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-09     12630       the first version
 */
#ifndef APPLICATIONS_USART2_H_
#define APPLICATIONS_USART2_H_
#include "ch32v30x.h"
#include <rtthread.h>
#include <rthw.h>
#include "drivers/pin.h"
#include "board.h"
#include "led.h"
#include "usart2.h"
#include "usart2and3.h"
#include "USART3.h"
extern char Rx2_Buffer[];
extern int flagusart2;
//void uart2_sample(void *parameter);
void uart2_sample(void);
int mailbox_sample(void);
#endif /* APPLICATIONS_USART2_H_ */
