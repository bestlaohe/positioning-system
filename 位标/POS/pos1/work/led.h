/*
 * led.h
 *
 *  Created on: 2022��4��9��
 *      Author: 12630
 */

#ifndef USER_LED_H_
#define USER_LED_H_
#include "ch32v30x.h"
#include <rtthread.h>

#include "drivers/pin.h"

#define  GPIOB5  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_5)) //获取输入电平
#define  GPIOB6  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_6)) //获取输入电平
#define  GPIOB7  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7)) //获取输入电平
#define  GPIOB8  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8)) //获取输入电平
#define  GPIOB9  (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9)) //获取输入电平

void LED1_BLINK_INIT(void);
void I_INIT(void);
int led(void);
#endif /* USER_LED_H_ */
