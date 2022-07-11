/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-10     12630       the first version
 */
#include "mythread.h"
#ifndef WORK_MYTHREAD_C_
#define WORK_MYTHREAD_C_
#define Position 5
extern int flagusart2;
extern int flagusart3;
extern int l;
extern int id;

int disten1;
int disten2;
int disten3;

#endif /* WORK_MYTHREAD_C_ */

uint8_t w1[]={0x0a,0X0a,0X14,     0x01,    0x01,      0x21,        0x02,        0x02};//终端地址0x0a,0X0a,0X14,地址2570，通道20,
uint8_t w2[]={0x0a,0X0a,0X14,     0x02,    0x02,      0x21,        0x02,        0x02};
uint8_t w3[]={0x0a,0X0a,0X14,     0x03,    0x03,      0x21,        0x02,        0x02};
//                               [3]位标号，  [4]徽章号，      [5]距离，         [6]报警      [7]数据处理完成标志
//                                2取消报警，  1是报警              2未处理，1处理完成
void ibeacon(void)
{
    rt_thread_mdelay(1000);
    uart_putstr(USART2,"+++");//串口2的发送
    rt_thread_mdelay(1000);
    uart_putstr(USART2,"AT+OBSERVER=1\r\n");//串口2的发送
}
void sendandprocess(void *parameter)//本线程是发送坐标给lora
{

    uint8_t i;
    //不同position是为了不同板子的烧录
    if (Position==1){
     w1[3]=0x01;//w[3]是位标号
     w2[3]=0x01;//w[3]是位标号
     w3[3]=0x01;//w[3]是位标号
    }
    if (Position==2){
     w1[3]=0x02;//w[3]是位标号
     w2[3]=0x02;//w[3]是位标号
     w3[3]=0x02;//w[3]是位标号
    }
    if (Position==3){
     w1[3]=0x03;//w[3]是位标号
     w2[3]=0x03;//w[3]是位标号
     w3[3]=0x03;//w[3]是位标号
    }
    if (Position==4){
     w1[3]=0x04;//w[3]是位标号
     w2[3]=0x04;//w[3]是位标号
     w3[3]=0x04;//w[3]是位标号
    }
    if (Position==5){
     w1[3]=0x05;//w[3]是位标号
     w2[3]=0x05;//w[3]是位标号
     w3[3]=0x05;//w[3]是位标号
    }

    while ( 1)
    {  //flagusart3=1;
       if(flagusart2&&flagusart3)
        {

//          数据转换
//           disten=30;
               for(i=0;i<3;i++)
                uart_putstr(USART3,"%c",w1[i]);
//           w1[4]=disten;
//           w1[6]=ala;
//           uart_putstr(USART3,"%c",w1[7]);
//           uart_putstr(USART3,"%c",w2[7]);
//           uart_putstr(USART3,"%c",w2[7]);
           if(w1[7]==1)
           { //此代码是向网关发送位置

               dataprocess1();
               //滚轮，一次1轮询

            for(i=3;i<8;i++)
                uart_putstr(USART3,"%c",w1[i]); //以单个字符的方式输出
            //报警和完成接收重置
            //uart_putstr(USART1,"receive 1");
            w1[6]=2;
            }
           if(w2[7]==1)
           { //此代码是向网关发送位置
               dataprocess2();
            for(i=3;i<8;i++)
                uart_putstr(USART3,"%c",w2[i]); //以单个字符的方式输出
            //uart_putstr(USART1,"receive 2");
            w2[6]=2;
            }
           if(w3[7]==1)
           { //此代码是向网关发送位置
               dataprocess3();
            for(i=3;i<8;i++)
                uart_putstr(USART3,"%c",w3[i]); //以单个字符的方式输出
            //uart_putstr(USART1,"receive 3");
            w3[6]=2;

            }
          if (Position==5)
              USART_SendData(USART3, 0x7e);//以单个字符的方式输出
        //    flagusart2=0;//取平均重置
            flagusart3=0;
        }

        /* 延时 500ms */
        rt_thread_mdelay(50);

    }
}
