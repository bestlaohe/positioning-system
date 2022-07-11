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
#define LED0_PIN 16   //PB0
void LED_INIT(void);
int led(void);
#endif /* USER_LED_H_ */
