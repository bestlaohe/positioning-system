/*
  * 程序清单：这是一个串口设备接收不定长数据的示例代码
  * 例程导出了 uart_dma_sample 命令到控制终端
  * 命令调用格式：uart_dma_sample uart2
  * 命令解释：命令第二个参数是要使用的串口设备名称，为空则使用默认的串口设备
  * 程序功能：通过串口 uart2 输出字符串"hello RT-Thread!"，并通过串口 uart2 输入一串字符（不定长），再通过数据解析后，使用控制台显示有效数据。
 */

 #include <rtthread.h>
 #include "usart2.h"
 #include "math.h"
 #include "led.h"
 #define  aver 10
 #define SAMPLE_UART_NAME                 "uart2"
 #define DATA_CMD_END                     '\r'       /* 结束位设置为 \r，即回车符 */
 #define ONE_DATA_MAXLEN                  512         /* 不定长数据的最大长度 */
 char data2[ONE_DATA_MAXLEN];
 extern int disten1;
 extern int disten2;
 extern int disten3;
 extern int flagusart2;
 extern uint8_t w1[];
 extern uint8_t w2[];
 extern uint8_t w3[];
 int rs1[aver]={0};//放平均数的缓存
 int rs2[aver]={0};
 int rs3[aver]={0};
 /* 用于接收消息的信号量 */
 static struct rt_semaphore rx_sem;
 static rt_device_t serial;
 void dataprocess1(void)
  {
     int i,j,min,max,sum;
      //         int a;
   //          float b;//MAC:84:BA:20:90:22:01,RSSI:-35,ADV:0201061AFF072102150102030405060708090A0B0C0D0EF01001020304CE00

          sum=0;
          min=max=0;


        for(i=0;i<aver;i++)
          {
              sum=sum+rs1[i];
              if(rs1[i]>max)
              {
                 max=rs1[i];
              }
          }
          min=rs1[0];
          for(j=1;j<aver;j++)
          {

              if(rs1[j]<min)
              {
                  min=rs1[j];
              }

          }
          sum=sum-(min+max);
            sum=sum/(aver-2);

            //     uart_putstr(USART1,"max=%d\r\n",max);
            //     uart_putstr(USART1,"min=%d\r\n",min);




            if(sum<70)
                            {
                                disten1=0;
                            }
                            else if(sum>=70&&sum<76)
                            {
                                disten1=1;
                            }
                            else if(sum>=76&&sum<82)
                            {
                                disten1=2;
                            }
                            else
                            {
                                disten1=3;
                            }

        /* a=sum-49;
         b=a/31.6;
         disten1=pow(10,b);*/

         w1[5]=disten1;
//         uart_putstr(USrART1,"disten1=%d\r\n",disten1);

  }
 void dataprocess2(void)
      {
     int i,j,min,max,sum;
      //         int a;
   //          float b;//MAC:84:BA:20:90:22:01,RSSI:-35,ADV:0201061AFF072102150102030405060708090A0B0C0D0EF01001020304CE00

         sum=0;
         min=max=rs2[0];
         for(i=0;i<aver;i++)
         {
             sum=sum+rs2[i];
             if(rs2[i]>max)
             {
                max=rs2[i];
             }
         }
         min=rs2[0];
         for(j=1;j<aver;j++)
         {

             if(rs2[j]<min)
             {
                 min=rs2[j];
             }

            }
//            uart_putstr(USART1,"max=%d\r\n",max);
//            uart_putstr(USART1,"min=%d\r\n",min);
            sum=sum-(min+max);
            sum=sum/(aver-2);
            if(sum<70)
                        {
                            disten2=0;
                        }
                        else if(sum>=70&&sum<76)
                        {
                            disten2=1;
                        }
                        else if(sum>=76&&sum<82)
                        {
                            disten2=2;
                        }
                        else
                        {
                            disten2=3;
                        }
//          uart_putstr(USART1,"sum=%d\r\n",sum);
  /*        a=sum-59;//1米d
//          uart_putstr(USART1,"a=%d\r\n",a);
            b=a/31.6;
            disten2=pow(10,b);*/
            w2[5]=disten2;
          //  uart_putstr(USART1,"disten2=%d\r\n",disten2);

      }
 void dataprocess3(void)
        {
     int i,j,min,max,sum;
      //         int a;
   //          float b;//MAC:84:BA:20:90:22:01,RSSI:-35,ADV:0201061AFF072102150102030405060708090A0B0C0D0EF01001020304CE00
        sum=0;
          min=max=rs3[0];
          for(i=0;i<aver;i++)
          {
              sum=sum+rs3[i];
              if(rs3[i]>max)
              {
                 max=rs3[i];
              }
          }

          min=rs3[0];
          for(j=1;j<aver;j++)
          {

              if(rs3[j]<min)
              {
                  min=rs3[j];
              }
              }

//              uart_putstr(USART1,"max=%d\r\n",max);
//               uart_putstr(USART1,"min=%d\r\n",min);
            sum=sum-(min+max);
            sum=sum/(aver-2);
            if(sum<70)
                        {
                            disten3=0;
                        }
                        else if(sum>=70&&sum<76)
                        {
                            disten3=1;
                        }
                        else if(sum>=76&&sum<82)
                        {
                            disten3=2;
                        }
                        else
                        {
                            disten3=3;
                        }

            uart_putstr(USART1,"sum=%d\r\n",sum);
            /*         a=sum-51;
            b=a/31.0;
            disten3=pow(10,b);*/
            w3[5]=disten3;
            uart_putstr(USART1,"disten3=%d\r\n",disten3);

        }

 int datap(int i)//整合all in
 {

           int  z;
           char l;
           int h;
           int b;
           int rssi1=0;
           int rssi2=0;
           int rssi3=0;
           static int x=0;
           static int t1=0;
           static int t2=0;
           static int t3=0;
           if(x==1)
             flagusart2=1;
           for(z=0;z<i;z++)
            {
             if(data2[z]=='M'&&data2[z+1]=='A'&&data2[z+2]=='C')
             {l=data2[z+20]-'0';
             if(l==1)
             {w1[4]=1;

             if(GPIOB5||GPIOB6||GPIOB7||GPIOB8||GPIOB9)
             {h=1;}
             else {
              h=0;
             }
             if(data2[z+32]=='S'&&data2[z+33]=='P'&&data2[z+48]=='3')
             {b=1;}
             else{
              b=0;}

             if(b==1&&h==0)
             {
                 w1[6]=1;

             }
             if(b==0&&h==1)
            {
                 w1[6]=3;
                 rt_kprintf("have fire\r\n");
            }
             if(b==1&&h==1)
               {
                   w1[6]=4;
                   rt_kprintf("have fire and alarm\r\n");
               }

             rssi1=(data2[z+28]-'0')*10+ (data2[z+29]-'0');
             rs1[t1]=rssi1;
             t1++;
             }
             if(t1>aver)
               {t1=0;
                w1[7]=1;//结束标志
                //flagusart2=1;
                x=1;
               }

             if(l==2)
             {
             w2[4]=2;


             if(GPIOB5||GPIOB6||GPIOB7||GPIOB8||GPIOB9)
                   {h=1;}
                   else {
                    h=0;
                   }
             if(data2[z+32]=='S'&&data2[z+33]=='P'&&data2[z+48]=='3')
             {b=1;}
             else{
             b=0;}

             if(b==1&&h==0)
                 {
                 w2[6]=1;

                 }
             if(b==0&&h==1)
                 {
                 w2[6]=3;
                 rt_kprintf("have fire \r\n");
                 }
             if(b==1&&h==1)
                 {
                 w2[6]=4;
                 rt_kprintf("have fire and alarm\r\n");
                 }



             rssi2=(data2[z+28]-'0')*10+ (data2[z+29]-'0');
             rs2[t2]=rssi2;
             t2++;

             }
             if(t2>aver)
              {t2=0;
              w2[7]=1;
             // flagusart2=1;
              x=1;
              }

             if(l==3)
             {
             w3[4]=3;


             if(GPIOB5||GPIOB6||GPIOB7||GPIOB8||GPIOB9)
                   {h=1;}
                   else {
                    h=0;
                   }
                   if(data2[z+32]=='S'&&data2[z+33]=='P'&&data2[z+48]=='3')
                   {b=1;}
                   else{
                    b=0;}

                   if(b==1&&h==0)
                   {
                       w3[6]=1;

                   }
                   if(b==0&&h==1)
                  {
                       w3[6]=3;
                       rt_kprintf("have fire\r\n");
                  }
                   if(b==1&&h==1)
                     {
                       w3[6]=4;
                       rt_kprintf("have fire and alarm\r\n");
                     }

             rssi3=(data2[z+28]-'0')*10+ (data2[z+29]-'0');
             rs3[t3]=rssi3;
             t3++;
             }
             if(t3>aver)
               {t3=0;
               w3[7]=1;
              //flagusart2=1;
               x=1;
               }

            }
            }
  }
 /* 接收数据回调函数 */
 static rt_err_t uart_rx_ind(rt_device_t dev, rt_size_t size)
 {
     /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */

     if (size > 0)
     {
         rt_sem_release(&rx_sem);
     }
     return RT_EOK;
 }

 static char uart_sample_get_char(void)
 {
     char ch;

     while (rt_device_read(serial, 0, &ch, 1) == 0)
     {
         rt_sem_control(&rx_sem, RT_IPC_CMD_RESET, RT_NULL);
        // rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
     }
     return ch;
 }

 /* 数据解析线程 */
 static void data_parsing(void)
 {
     char ch;

     static char i = 0;

     while (1)
     {
         ch = uart_sample_get_char();

         //rt_device_write(serial, 0, &ch, 1);
         if(ch == DATA_CMD_END)
         {
            data2[i++] = '\0';
            //rt_kprintf("data=%s\r\n",data2);
            datap(i);
           // uart_putstr(USART2,"data=%s\r\n",data2);
            i = 0;
            continue;
         }
         i = (i >= ONE_DATA_MAXLEN-1) ? ONE_DATA_MAXLEN-1 : i;
         data2[i++] = ch;
     }
 }

 void uart2_sample(void *parameter)
 {
     char uart_name[RT_NAME_MAX];
     char str[] = "hello RT-Thread!\r\n";
         rt_strncpy(uart_name, SAMPLE_UART_NAME, RT_NAME_MAX);
     /* 查找系统中的串口设备 */
     serial = rt_device_find(uart_name);
     if (!serial)
     {
         rt_kprintf("find %s failed!\n", uart_name);

     }

     /* 初始化信号量 */
     rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);
     /* 以中断接收及轮询发送模式打开串口设备 */
     rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
     /* 设置接收回调函数 */
     rt_device_set_rx_indicate(serial, uart_rx_ind);
     /* 发送字符串 */
     rt_device_write(serial, 0, str, (sizeof(str) - 1));

     /* 创建 serial 线程 */
     rt_thread_t thread = rt_thread_create("serial", (void (*)(void *parameter))data_parsing, RT_NULL, 1024, 25, 10);
     /* 创建成功则启动线程 */
     if (thread != RT_NULL)
     {
         rt_thread_startup(thread);
     }

 }
