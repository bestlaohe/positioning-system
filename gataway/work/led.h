/*
 * led.h
 *
 *  Created on: 2022Äê4ÔÂ9ÈÕ
 *      Author: 12630
 */

#ifndef USER_LED_H_
#define USER_LED_H_
#include "ch32v30x.h"
#include <rtthread.h>

#include "drivers/pin.h"
void LED1_BLINK_INIT(void);
int led(void);
#endif /* USER_LED_H_ */
