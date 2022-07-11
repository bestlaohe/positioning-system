/*
 * led.c
 *
 *  Created on: 2022��4��9��
 *      Author: 12630
 */
#include "led.h"

extern char data[];


/*********************************************************************
 * @fn      LED1_BLINK_INIT
 *
 * @brief   LED1ͨ��ֱ�ӵ��õײ�����
 *
 * @return  none
 *********************************************************************/

void LED_INIT(void)
{
    GPIO_InitTypeDef GPIO_InitStructure={0};
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    rt_pin_write(LED0_PIN, PIN_LOW);

}

/*********************************************************************
 * @fn      led
 *
 * @brief   ����ʹ�������ӿڲ���I/O��
 *
 * @return  none
 */
int led(void)
{
    data[3]=2;

    rt_pin_mode(LED0_PIN, PIN_MODE_OUTPUT);

        if( data[3]!=2)
        {
             rt_pin_write(LED0_PIN, PIN_HIGH);
          //   rt_kprintf("led on, count : %d\r\n", count);
             rt_thread_mdelay(500);
        }
        else
        {
             rt_pin_write(LED0_PIN, PIN_LOW);
       // rt_kprintf("led off\r\n");
             rt_thread_mdelay(500);
        }
    return 0;
}


MSH_CMD_EXPORT(led,  led .sample by using I/O drivers);
