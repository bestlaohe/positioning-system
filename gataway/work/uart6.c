/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-05-08     86133       the first version
 */
 #include <rtthread.h>
 #include "uart6.h"
 #define SAMPLE_UART_NAME                 "uart6"
 #define DATA_CMD_END                     '\r'       /* 结束位设置为 \r，即回车符 */
 #define ONE_DATA_MAXLEN                  128         /* 不定长数据的最大长度 */
 char data3[ONE_DATA_MAXLEN];

int x=1;
int gata(int i)
 {
     int  z;
     for(z=0;z<i;z++)
      {
       if(data3[z]=='I'&&data3[z+1]=='P')
           x=0;
      }
 }


 /* 用于接收消息的信号量 */
 struct rt_semaphore rx6_sem;
 static rt_device_t serial;

 /* 接收数据回调函数 */
 static rt_err_t uart6_rx_ind(rt_device_t dev, rt_size_t size)
 {//rt_kprintf("data\r");
     /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
     if (size > 0)
     {
         rt_sem_release(&rx6_sem);
     }

     return RT_EOK;
 }

 static char uart6_sample_get_char(void)
 {
     char ch;

     while (rt_device_read(serial, 0, &ch, 1) == 0)
     {
         rt_sem_control(&rx6_sem, RT_IPC_CMD_RESET, RT_NULL);
        // rt_sem_take(&rx1_sem, RT_WAITING_FOREVER);
     }
     return ch;
 }
 /* 数据解析线程 */
 static void data6_parsing(void)
 {
     char ch;
     char data3[ONE_DATA_MAXLEN];
     static char i = 0;
     while (1)
     {
         ch = uart6_sample_get_char();


         //rt_device_write(serial, 0, &ch, 1);
         //rt_kprintf("d==%s\r\n",ch);
         if(ch == DATA_CMD_END)
         {
             data3[i++] = '\0';
             rt_kprintf("data3=%s\r\n",data3);
             gata(i);
             //uart_putstr(USART2,"data=%s\r\n",data);
             i = 0;
             continue;
         }
         i = (i >= ONE_DATA_MAXLEN-1) ? ONE_DATA_MAXLEN-1 : i;
         data3[i++] = ch;


     }
 }




 void gataway(void)
  {
       uart_putstr(UART6,"+++");
       rt_thread_mdelay(100);
       uart_putstr(UART6,"AT+CWJAP=\"zl\",\"985505401\"\r\n");
       rt_thread_mdelay(20000);
       uart_putstr(UART6,"AT+CIPSTART=\"TCP\",\"api.zhiyun360.com\",28082\r\n");
       rt_thread_mdelay(900);
       uart_putstr(UART6,"AT+CIPMODE=1\r\n");
       rt_thread_mdelay(900);
       uart_putstr(UART6,"AT+CIPSEND\r\n");
       rt_thread_mdelay(900);
       uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
       rt_thread_mdelay(100);
       uart_putstr(UART6,"{\"method\":\"echo\",\"timestamp\":1605141585800,\"seq\":5}\r\n");
       //uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
       //uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"minidata\",\"data\":\"{5,1,22,5,2,22,5,3,21,2,1,37,2,2,39,2,3,33,3,1,20,3,2,20,3,3,28}\"\r\n}");
  }

 void uart6_sample(void)
 {
     char uart_name[RT_NAME_MAX];
         rt_strncpy(uart_name, SAMPLE_UART_NAME, RT_NAME_MAX);
     /* 查找系统中的串口设备 */
     serial = rt_device_find(uart_name);
     if (!serial)
     {
         rt_kprintf("find %s failed!\n", uart_name);

     }

     /* 初始化信号量 */
     rt_sem_init(&rx6_sem, "rx6_sem", 0, RT_IPC_FLAG_FIFO);
     /* 以中断接收及轮询发送模式打开串口设备 */
     rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
     /* 设置接收回调函数 */
     rt_device_set_rx_indicate(serial, uart6_rx_ind);
     /* 发送字符串 */
    // rt_device_write(serial, 0, str, (sizeof(str) - 1));

     /* 创建 serial 线程 */
     rt_thread_t thread = rt_thread_create("serial", (void (*)(void *parameter))data6_parsing, RT_NULL, 1024, 25, 10);
     /* 创建成功则启动线程 */

     if (thread != RT_NULL)
     {
         rt_thread_startup(thread);
     }

 }

