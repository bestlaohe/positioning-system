
/*
 * 程序清单：这是一个 串口 设备使用例程
 * 例程导出了 uart_sample 命令到控制终端
 * 命令调用格式：uart_sample uart2
 * 命令解释：命令第二个参数是要使用的串口设备名称，为空则使用默认的串口设备
 * 程序功能：通过串口输出字符串"hello RT-Thread!"，然后错位输出输入的字符
*/

 #include <rtthread.h>
 #include "USART3.h"
 #define SAMPLE_UART_NAME                 "uart3"
 #define DATA_CMD_END                     '\r'       /* 结束位设置为 \r，即回车符 */
 #define ONE_DATA_MAXLEN                  128         /* 不定长数据的最大长度 */

 /* 用于接收消息的信号量 */
 struct rt_semaphore rx3_sem;
 static rt_device_t serial;

 /* 接收数据回调函数 */
 static rt_err_t uart_rx_ind(rt_device_t dev, rt_size_t size)
 {//rt_kprintf("data\r");
     /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
     if (size > 0)
     {
         rt_sem_release(&rx3_sem);
     }

     return RT_EOK;
 }

 static char uart_sample_get_char(void)
 {
     char ch;

     while (rt_device_read(serial, 0, &ch, 1) == 0)
     {
         rt_sem_control(&rx3_sem, RT_IPC_CMD_RESET, RT_NULL);
        // rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
     }
     return ch;
 }

 /* 数据解析线程 */
 static void data_parsing(void)
 {
     char ch;
     char data[ONE_DATA_MAXLEN];
     static char i = 0;

     while (1)
     {
         ch = uart_sample_get_char();

         //rt_device_write(serial, 0, &ch, 1);
         //rt_kprintf("d==%s\r\n",ch);
         if(ch == DATA_CMD_END)
         {
             data[i++] = '\0';
             rt_kprintf("data=%s\r\n",data);
             //uart_putstr(USART2,"data=%s\r\n",data);
             i = 0;
             continue;
         }
         i = (i >= ONE_DATA_MAXLEN-1) ? ONE_DATA_MAXLEN-1 : i;
         data[i++] = ch;
     }
 }

 //void uart2_sample(void *parameter)
 void uart3_sample(void)
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
     rt_sem_init(&rx3_sem, "rx3_sem", 0, RT_IPC_FLAG_FIFO);
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
