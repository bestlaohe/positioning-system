/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2022-04-10     12630       the first version
 */
#include<stdio.h>
#include "mythread.h"
#ifndef WORK_MYTHREAD_C_
#define WORK_MYTHREAD_C_
extern int flagusart2;
extern int flagusart3;
extern char Rx2_Buffer[];
extern char data[];

#endif /* WORK_MYTHREAD_C_ */

void ibeacon(void)
{
    uart_putstr(USART2,"+++");//串口3的发送
    uart_putstr(USART2,"AT+OBSERVER=1\r");//串口3的发送
}



void solvedata1(void)
{
    int k;
    char sw='0';
    for(k=0;k<16;k+=5)
    {
        if(data[2]>data[7+k])//4次
        {
            //完成data[7+k]和data[2]的交换
            sw=data[7+k];//将data[7+k]的值赋值给sw
            data[7+k]=data[2];//将data[2]的值赋值给data[7+k]
            data[2]=sw;//将sw的值赋值给data[2]

            //完成data[5+k]和data[0]的交换
            sw=data[5+k];//将data[5+k]的值赋值给sw
            data[5+k]=data[0];//将data[0]的值赋值给data[4+k]
            data[0]=sw;//将sw的值赋值给data[0]

            //完成data[6+k]和data[1]的交换
            sw=data[6+k];
            data[6+k]=data[1];
            data[1]=sw;

            //完成data[8+k]和data[3]的交换
            sw=data[8+k];
            data[8+k]=data[3];
            data[3]=sw;

            //完成data[9+k]和data[4]的交换
            sw=data[9+k];
            data[9+k]=data[4];
            data[4]=sw;
        }
    }
    for(k=0;k<11;k+=5)//3次
    {
        if(data[7]>data[12+k])
        {
            sw=data[12+k];
            data[12+k]=data[7];
            data[7]=sw;

            sw=data[10+k];
            data[10+k]=data[5];
            data[5]=sw;

            sw=data[11+k];
            data[11+k]=data[6];
            data[6]=sw;

            sw=data[13+k];
            data[13+k]=data[8];
            data[8]=sw;

            sw=data[14+k];
            data[14+k]=data[9];
            data[9]=sw;
        }
    }
    for(k=0;k<6;k+=5)//2次
    {
        if(data[12]>data[17+k])
        {
            sw=data[17+k];
            data[17+k]=data[12];
            data[12]=sw;

            sw=data[15+k];
            data[15+k]=data[10];
            data[10]=sw;

            sw=data[16+k];
            data[16+k]=data[11];
            data[11]=sw;

            sw=data[18+k];
            data[18+k]=data[13];
            data[13]=sw;

            sw=data[19+k];
            data[19+k]=data[14];
            data[14]=sw;
        }
    }
}

void solvedata2(void)
{
    int k;
    char sw='0';
    //组1，3，5，7，9，5个小组进行比较，前3小的放1，3，5，
    for(k=0;k<31;k+=10)
    {
        if(data[2]>data[12+k])//4次
        {
            sw=data[12+k];
            data[12+k]=data[2];
            data[2]=sw;

            sw=data[10+k];
            data[10+k]=data[0];
            data[0]=sw;

            sw=data[11+k];
            data[11+k]=data[1];
            data[1]=sw;

            sw=data[13+k];
            data[13+k]=data[3];
            data[3]=sw;

            sw=data[14+k];
            data[14+k]=data[4];
            data[4]=sw;
        }
    }
    for(k=0;k<21;k+=10)
    {
        if(data[12]>data[22+k])//3次
        {
            sw=data[22+k];
            data[22+k]=data[12];
            data[12]=sw;

            sw=data[20+k];
            data[20+k]=data[10];
            data[10]=sw;

            sw=data[21+k];
            data[21+k]=data[11];
            data[11]=sw;

            sw=data[23+k];
            data[23+k]=data[13];
            data[13]=sw;

            sw=data[24+k];
            data[24+k]=data[14];
            data[14]=sw;
        }
    }
    for(k=0;k<11;k+=10)//2次
    {
        if(data[22]>data[32+k])
        {
            sw=data[32+k];
            data[32+k]=data[22];
            data[22]=sw;

            sw=data[30+k];
            data[30+k]=data[20];
            data[20]=sw;

            sw=data[31+k];
            data[31+k]=data[21];
            data[21]=sw;

            sw=data[33+k];
            data[33+k]=data[23];
            data[23]=sw;

            sw=data[34+k];
            data[34+k]=data[24];
            data[24]=sw;
        }
    }
    //组2，4，6，8，10，5个小组进行比较，前3小的放2，4，6，
    for(k=0;k<31;k+=10)
    {
        if(data[7]>data[17+k])//4次
        {
            sw=data[17+k];
            data[17+k]=data[7];
            data[7]=sw;

            sw=data[15+k];
            data[15+k]=data[5];
            data[5]=sw;

            sw=data[16+k];
            data[16+k]=data[6];
            data[6]=sw;

            sw=data[18+k];
            data[18+k]=data[8];
            data[8]=sw;

            sw=data[19+k];
            data[19+k]=data[9];
            data[9]=sw;
        }
    }
    for(k=0;k<21;k+=10)
    {
        if(data[17]>data[27+k])//3次
        {
            sw=data[27+k];
            data[27+k]=data[17];
            data[17]=sw;

            sw=data[25+k];
            data[25+k]=data[15];
            data[15]=sw;

            sw=data[26+k];
            data[26+k]=data[16];
            data[16]=sw;

            sw=data[28+k];
            data[28+k]=data[18];
            data[18]=sw;

            sw=data[29+k];
            data[29+k]=data[19];
            data[19]=sw;
        }
    }
    for(k=0;k<11;k+=10)//2次
    {
        if(data[27]>data[37+k])
        {
            sw=data[37+k];
            data[37+k]=data[27];
            data[27]=sw;

            sw=data[35+k];
            data[35+k]=data[25];
            data[25]=sw;

            sw=data[36+k];
            data[36+k]=data[26];
            data[26]=sw;

            sw=data[38+k];
            data[38+k]=data[28];
            data[28]=sw;

            sw=data[39+k];
            data[39+k]=data[29];
            data[29]=sw;
        }
    }
}

void solvedata3(void)
{
    int k;
    char sw='0';
    //组1，4，7，10，13，5个小组进行比较，前3小的放1，4，7
    for(k=0;k<46;k+=15)
    {
        if(data[2]>data[17+k])//4次
        {
            sw=data[17+k];
            data[17+k]=data[2];
            data[2]=sw;

            sw=data[15+k];
            data[15+k]=data[0];
            data[0]=sw;

            sw=data[16+k];
            data[16+k]=data[1];
            data[1]=sw;

            sw=data[18+k];
            data[18+k]=data[3];
            data[3]=sw;

            sw=data[19+k];
            data[19+k]=data[4];
            data[4]=sw;
        }
    }
    for(k=0;k<31;k+=15)
    {
        if(data[17]>data[32+k])//3次
        {
            sw=data[32+k];
            data[32+k]=data[17];
            data[17]=sw;

            sw=data[30+k];
            data[30+k]=data[15];
            data[15]=sw;

            sw=data[31+k];
            data[31+k]=data[16];
            data[16]=sw;

            sw=data[33+k];
            data[33+k]=data[18];
            data[18]=sw;

            sw=data[34+k];
            data[34+k]=data[19];
            data[19]=sw;
        }
    }
    for(k=0;k<16;k+=15)//2次
    {
        if(data[32]>data[47+k])
        {
            sw=data[47+k];
            data[47+k]=data[32];
            data[32]=sw;

            sw=data[45+k];
            data[45+k]=data[30];
            data[30]=sw;

            sw=data[46+k];
            data[46+k]=data[31];
            data[31]=sw;

            sw=data[48+k];
            data[48+k]=data[33];
            data[33]=sw;

            sw=data[49+k];
            data[49+k]=data[34];
            data[34]=sw;
        }
    }
    //组2，5，8，11，14，5个小组进行比较，前3小的放2，5，8
        for(k=0;k<46;k+=15)
    {
        if(data[7]>data[22+k])//4次
        {
            sw=data[22+k];
            data[22+k]=data[7];
            data[7]=sw;

            sw=data[20+k];
            data[20+k]=data[5];
            data[5]=sw;

            sw=data[21+k];
            data[21+k]=data[6];
            data[6]=sw;

            sw=data[23+k];
            data[23+k]=data[8];
            data[8]=sw;

            sw=data[25+k];
            data[24+k]=data[9];
            data[9]=sw;
        }
    }
    for(k=0;k<31;k+=15)
    {
        if(data[22]>data[37+k])//3次
        {
            sw=data[37+k];
            data[37+k]=data[22];
            data[22]=sw;

            sw=data[35+k];
            data[35+k]=data[20];
            data[20]=sw;

            sw=data[36+k];
            data[36+k]=data[21];
            data[21]=sw;

            sw=data[38+k];
            data[38+k]=data[23];
            data[23]=sw;

            sw=data[39+k];
            data[39+k]=data[24];
            data[24]=sw;
        }
    }
    for(k=0;k<16;k+=15)//2次
    {
        if(data[37]>data[52+k])
        {
            sw=data[52+k];
            data[52+k]=data[37];
            data[37]=sw;

            sw=data[50+k];
            data[50+k]=data[35];
            data[35]=sw;

            sw=data[51+k];
            data[51+k]=data[36];
            data[36]=sw;

            sw=data[53+k];
            data[53+k]=data[38];
            data[38]=sw;

            sw=data[54+k];
            data[54+k]=data[39];
            data[39]=sw;
        }
    }
    //组3，6，9，12，15，5个小组进行比较，前3小的放3，6，9
    for(k=0;k<46;k+=15)
    {
        if(data[12]>data[27+k])//4次
        {
            sw=data[27+k];
            data[27+k]=data[12];
            data[12]=sw;

            sw=data[25+k];
            data[25+k]=data[10];
            data[10]=sw;

            sw=data[26+k];
            data[26+k]=data[11];
            data[11]=sw;

            sw=data[28+k];
            data[28+k]=data[13];
            data[13]=sw;

            sw=data[29+k];
            data[29+k]=data[14];
            data[14]=sw;
        }
    }
    for(k=0;k<31;k+=15)
    {
        if(data[27]>data[42+k])//3次
        {
            sw=data[42+k];
            data[42+k]=data[27];
            data[27]=sw;

            sw=data[40+k];
            data[40+k]=data[25];
            data[25]=sw;

            sw=data[41+k];
            data[41+k]=data[26];
            data[26]=sw;

            sw=data[43+k];
            data[43+k]=data[28];
            data[28]=sw;

            sw=data[44+k];
            data[44+k]=data[29];
            data[29]=sw;
        }
    }
    for(k=0;k<16;k+=15)//2次
    {
        if(data[42]>data[57+k])
        {
            sw=data[57+k];
            data[57+k]=data[42];
            data[42]=sw;

            sw=data[55+k];
            data[55+k]=data[40];
            data[40]=sw;

            sw=data[56+k];
            data[56+k]=data[41];
            data[41]=sw;

            sw=data[58+k];
            data[58+k]=data[43];
            data[43]=sw;

            sw=data[59+k];
            data[59+k]=data[44];
            data[44]=sw;
        }
    }
}

 void sendandprocess(void *parameter)//本线程是发送坐标给lora
 {

     int i;
     while (1)
     {


         /* 线程1采用低优先级运行，一直打印计数值 */
         //只有一个徽章的时候[0]位标号，  [1]徽章号，      [2]距离，         [3]报警               [4]数据处理完成标志
         // [0][1][2][3][4]  [0][1][2][3][4]      [0][1][2][3][4]     [0][1][2][3][4]     [0][1][2][3][4]

         if(data[0]==0x01&&data[5]==0x02&&data[10]==0x03&&data[15]==0x04&&data[20]==0x05)//如果没有采集到连续5个，说明被遮挡那就不计算，因为不准确
         {
             for(i=0;i<5;i++)
             {
                 if( data[3+i*5]==1)
                 {
                     uart_putstr(USART1,"Badge %d alarm\r\n",data[1+i*5]);
                     uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alert_One\\\":1}}\"\r\n");
                     uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alarm_Beacon_One\\\":%d}}\"\r\n",data[1+i*5]);
                     break;
                 }
             }
              uart_putstr(USART1,"just one badge\r\n");
              if(data[1]==1&&data[6]==1)
               {
                    uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                    uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h11=1,d11=%d,a11=%d,h21=1,d21=%d,a21=%d,h31=1,d31=%d,a31=%d,h41=1,d41=%d,a41=%d,h51=1,d51=%d,a51=%d}\"}\r\n",
                            data[2],data[3],data[7],data[8],data[12],data[13],data[17],data[18],data[22],data[23]);
               }
              if(data[1]==2&&data[6]==2)
               {
                    uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                    uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h12=1,d12=%d,a12=%d,h22=1,d22=%d,a22=%d,h32=1,d32=%d,a32=%d,h42=1,d42=%d,a42=%d,h52=1,d52=%d,a52=%d}\"}\r\n",
                            data[2],data[3],data[7],data[8],data[12],data[13],data[17],data[18],data[22],data[23]);
               }
              if(data[1]==3&&data[6]==3)
               {
                    uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                    uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h13=1,d13=%d,a13=%d,h23=1,d23=%d,a23=%d,h33=1,d33=%d,a33=%d,h43=1,d43=%d,a43=%d,h53=1,d53=%d,a53=%d}\"}\r\n",
                            data[2],data[3],data[7],data[8],data[12],data[13],data[17],data[18],data[22],data[23]);
               }
              solvedata1();//求最小的前3依次放置
                   uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                   uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"minidata\",\"data\":\"{%d,%d,%d,%d,%d,%d,%d,%d,%d}\"}\r\n",
                           data[0],data[1],data[2],data[5],data[6],data[7],data[10],data[11],data[12]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[0],data[2],data[1]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[5],data[7],data[6]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[10],data[12],data[11]);

              //胸章编号
              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"beacon_Num\\\":[%d]}}\"\r\n",data[1]);
              //距离信息
              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"distance\\\":[%d, %d, %d]}}\"\r\n", data[2], data[7], data[12]);
              //位标编号
              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"index_Num\\\":[%d, %d, %d]}}\"\r\n", data[0], data[5], data[10]);

//              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"Num_Ibeacon\\\":%d}}\"\r\n", data[1]);
//              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"distanceOne\\\":200}}\"\r\n");
//              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"index_Num\\\":%d}}\"\r\n", data[0]);

              data[0]=0x00;data[10]=0x00;data[20]=0x00;
              data[5]=0x00;data[15]=0x00;
          }
         //    [0]位标号，  [1]徽章号，      [2]距离，         [3]报警               [4]数据处理完成标志

         //只有两个个徽章的时候
         // [0][1][2][3][4]  [0][1][2][3][4]   [0][1][2][3][4]  [0][1][2][3][4]  [0][1][2][3][4]
         // [0][1][2][3][4]  [0][1][2][3][4]   [0][1][2][3][4]  [0][1][2][3][4]  [0][1][2][3][4]
         if (data[0]==0x01&&data[5]==0x01&&data[10]==0x02&&data[15]==0x02&&data[20]==0x03&&
             data[25]==0x03&&data[30]==0x04&&data[35]==0x04&&data[40]==0x05&&data[45]==0x05)
         {
             for(i=0;i<5;i++)
             {
                 if( data[3+i*10]==1)
                 {
                     uart_putstr(USART1,"Badge %d alarm\r\n",data[1+i*10]);
                     uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alert_One\\\":1}}\"\r\n");
                     uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alarm_Beacon_One\\\":%d}}\"\r\n",data[1+i*10]);
                                  break;
                 }
             }
             for(i=0;i<5;i++)
             {
                 if( data[8+i*10]==1)
                 {
                     uart_putstr(USART1,"Badge %d alarm\r\n",data[6+i*10]);
                     uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alert_Two\\\":1}}\"\r\n");
                     uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alarm_Beacon_Two\\\":%d}}\"\r\n",data[6+i*10]);

                     break;
                 }
             }

              uart_putstr(USART1,"just two badge\r\n");
              if(data[1]==1&&data[6]==2)
                  {
                  uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                  uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h11=1,h12=1,d11=%d,d12=%d,a11=%d,a12=%d,h21=1,h22=1,d21=%d,d22=%d,a21=%d,a22=%d,h31=1,h32=1,d31=%d,d32=%d,a31=%d,a32=%d,h41=1,h42=1,d41=%d,d42=%d,a41=%d,a42=%d,h51=1,h52=1,d51=%d,d52=%d,a51=%d,a52=%d}\"}\r\n",data[2],data[7],data[3],data[8],data[12],data[17],data[13],data[18],data[22],data[27],data[23],data[28],data[32],data[37],data[33],data[38],data[42],data[47],data[43],data[48]);}
              if(data[1]==1&&data[6]==3)
                  {uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                  uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h11=1,h13=1,d11=%d,d13=%d,a11=%d,a13=%d,h21=1,h23=1,d21=%d,d23=%d,a21=%d,a23=%d,h31=1,h33=1,d31=%d,d33=%d,a31=%d,a33=%d,h41=1,h43=1,d41=%d,d43=%d,a41=%d,a43=%d,h51=1,h53=1,d51=%d,d53=%d,a51=%d,a53=%d}\"}\r\n",data[2],data[7],data[3],data[8],data[12],data[17],data[13],data[18],data[22],data[27],data[23],data[28],data[32],data[37],data[33],data[38],data[42],data[47],data[43],data[48]);}
              if(data[1]==2&&data[6]==3)
                  {uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                  uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h12=1,h13=1,d12=%d,d13=%d,a12=%d,a13=%d,h22=1,h23=1,d22=%d,d23=%d,a22=%d,a23=%d,h32=1,h33=1,d32=%d,d33=%d,a32=%d,a33=%d,h42=1,h43=1,d42=%d,d43=%d,a42=%d,a43=%d,h52=1,h53=1,d52=%d,d53=%d,a52=%d,a53=%d}\"}\r\n",data[2],data[7],data[3],data[8],data[12],data[17],data[13],data[18],data[22],data[27],data[23],data[28],data[32],data[37],data[33],data[38],data[42],data[47],data[43],data[48]);}


              solvedata2();
              uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
              uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"minidata\",\"data\":\"{%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d}\"}\r\n",
                      data[0],data[1],data[2],data[5],data[6],data[7],data[10],data[11],data[12],data[15],data[16],data[17],data[20],data[21],data[22],data[25],data[26],data[27]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[0],data[2],data[1]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[10],data[12],data[11]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[20],data[22],data[21]);

              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[5],data[7],data[6]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[15],data[17],data[16]);
              uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[25],data[27],data[26]);

              //胸章编号
              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"beacon_Num\\\":[%d, %d]}}\"\r\n",data[1], data[6]);
              //距离信息
              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"distance\\\":[%d, %d, %d, %d, %d, %d]}}\"\r\n", data[2], data[12], data[22], data[7], data[17], data[27]);
              //位标编号
              uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"index_Num\\\":[%d, %d, %d, %d, %d, %d]}}\"\r\n", data[0], data[10], data[20], data[5], data[15], data[25]);

              data[0]=0x00;data[10]=0x00;data[20]=0x00;
              data[5]=0x00;data[15]=0x00;
          }
         //    [0]位标号，  [1]徽章号，      [2]距离，         [3]报警               [4]数据处理完成标志
         //只有3个徽章的时候
         // [0][1][2][3][4]  [0][1][2][3][4]   [0][1][2][3][4]  [0][1][2][3][4]  [0][1][2][3][4]
         // [0][1][2][3][4]  [0][1][2][3][4]   [0][1][2][3][4]  [0][1][2][3][4]  [0][1][2][3][4]
         // [0][1][2][3][4]  [0][1][2][3][4]   [0][1][2][3][4]  [0][1][2][3][4]  [0][1][2][3][4]
         if (  data[0]==0x01 &&data[5]==0x01&&data[10]==0x01
             &&data[15]==0x02&&data[20]==0x02&&data[25]==0x02
             &&data[30]==0x03&&data[35]==0x03&&data[40]==0x03
             &&data[45]==0x04&&data[50]==0x04&&data[55]==0x04
             &&data[60]==0x05&&data[65]==0x05&&data[70]==0x05)
         {
                    for(i=0;i<5;i++)
                        {if( data[3+i*15]==1)
                               {uart_putstr(USART1,"Badge %d alarm\r\n",data[1+i*15]);
                                uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alert_One\\\":1}}\"\r\n");
                                uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alarm_Beacon_One\\\":%d}}\"\r\n",data[1+i*15]);
                                 break;}
                        }
                    for(i=0;i<5;i++)
                    {
                        if( data[8+i*15]==1)
                        {
                            uart_putstr(USART1,"Badge %d alarm\r\n",data[6+i*15]);
                            uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alert_Two\\\":1}}\"\r\n");
                            uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alarm_Beacon_Two\\\":%d}}\"\r\n",data[1+i*15]);
                            break;
                        }
                    }
                    for(i=0;i<5;i++)
                    {
                        if( data[13+i*15]==1)
                        {
                            uart_putstr(USART1,"Badge %d alarm\r\n",data[11+i*15]);
                            uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alert_Three\\\":1}}\"\r\n");
                            uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"alarm_Beacon_Three\\\":%d}}\"\r\n",data[1+i*15]);
                            break;
                        }
                    }
                      uart_putstr(USART1,"just three badge\r\n");
                      uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                      uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"totaldata\",\"data\":\"{h11=1,h12=1,h13=1,d11=%d,d12=%d,d13=%d,a11=%d,a12=%d,a13=%d,h21=1,h22=1,h23=1,d21=%d,d22=%d,d23=%d,a21=%d,a22=%d,a23=%d,h31=1,h32=1,h33=1,d31=%d,d32=%d,d33=%d,a31=%d,a32=%d,a33=%d,h41=1,h42=1,h43=1,d41=%d,d42=%d,d43=%d,a41=%d,a42=%d,a43=%d,h51=1,h52=1,h53=1,d51=%d,d52=%d,d53=%d,a51=%d,a52=%d,a53=%d}\"}\r\n",
                              data[2],data[7],data[12],data[3],data[8],data[13],data[17],data[22],data[27],data[18],data[23],data[28],data[32],data[37],data[42],data[33],data[38],data[43],data[47],data[52],data[57],data[48],data[53],data[58],data[62],data[67],data[72],data[63],data[68],data[73]);

                      solvedata3();
                      uart_putstr(UART6,"{\"method\":\"authenticate\",\"uid\":\"736299660156\",\"key\":\"BgMAVF0AUABTCFFXYFpYVlZORWg\",\"version\":\"0.1.0\",\"autodb\":true}\r\n");
                      uart_putstr(USART1,"{\"method\":\"sensor\",\"addr\":\"minidata\",\"data\":\"{%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d}\"}\r\n",
                              data[0],data[1],data[2],data[5],data[6],data[7],data[10],data[11],data[12],data[15],data[16],data[17],data[20],data[21],data[22],data[25],data[26],data[27],data[30],data[31],data[32],data[35],data[36],data[37],data[40],data[41],data[42]);
                      uart_putstr(UART6,"{\"method\":\"sensor\",\"addr\":\"minidata\",\"data\":\"{%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d}\"}\r\n",
                              data[0],data[1],data[2],data[5],data[6],data[7],data[10],data[11],data[12],data[15],data[16],data[17],data[20],data[21],data[22],data[25],data[26],data[27],data[30],data[31],data[32],data[35],data[36],data[37],data[40],data[41],data[42]);


                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[0],data[2],data[1]);
                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[15],data[17],data[16]);
                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[30],data[32],data[31]);

                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[5],data[7],data[6]);
                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[20],data[22],data[21]);
                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[35],data[37],data[36]);

                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[10],data[12],data[11]);
                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[25],data[27],data[26]);
                      uart_putstr(USART1,"Position %d is %d meters away  from badge %d\r\n",data[40],data[42],data[41]);

                      //发送云端：
                      //胸章编号
                      uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"beacon_Num\\\":[%d, %d, %d]}}\"\r\n",data[1], data[6], data[11]);
                      //距离信息
                      uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"distance\\\":[%d, %d, %d, %d, %d, %d, %d, %d, %d]}}\"\r\n", data[2], data[17], data[32], data[7], data[22], data[37], data[12], data[27], data[42]);
                      //位标编号
                      uart_putstr(USART3,"AT+TCMQTTPUB=\"$thing/up/property/4M4I8WTBDA/L610_4G\",1,\"{\\\"method\\\":\\\"report\\\",\\\"clientToken\\\":\\\"123\\\",\\\"params\\\":{\\\"index_Num\\\":[%d, %d, %d, %d, %d, %d, %d, %d, %d]}}\"\r\n", data[0], data[15], data[30], data[5], data[20], data[35], data[10], data[25], data[40]);

                      data[0]=0x00;data[10]=0x00;data[20]=0x00;
                      data[5]=0x00;data[15]=0x00;
          }


         rt_thread_mdelay(100);

     }
 }
 void Fibcom_L610_init(void)//L610初始化
 {
     //L610连接云端
        uart_putstr(USART3,"ATI\r\n");
        uart_putstr(USART3,"AT+CGMR?\r\n");
        uart_putstr(USART3,"AT+MIPCALL?\r\n");
        uart_putstr(USART3,"AT+MIPCALL=1\r\n");//请求IP
        uart_putstr(USART3,"AT+TCDEVINFOSET=1,\"4M4I8WTBDA\",\"L610_4G\",\"mk/oVASMLdtQPmGnVgZrlQ==\"\r\n");//设置设备信息
        for( int e = 0; e<20; e++)
        {
            uart_putstr(USART3,"AT+TCMQTTCONN=1,20000,240,1,1\r\n");
        }
        uart_putstr(USART3,"AT+TCMQTTSUB=\"$thing/down/property/4M4I8WTBDA/L610_4G\",1\r\n");

 }
