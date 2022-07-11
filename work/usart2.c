


#include <rtthread.h>
#include "mythread.h"
#define THREAD_PRIORITY      10
#define THREAD_TIMESLICE     5

/* 邮箱控制块 */
static struct rt_mailbox mb;
/* 用于放邮件的内存池 */
static char mb_pool[128]="0";
static char mb_str1[] = "I'm a mail!";
int fla=0;
ALIGN(RT_ALIGN_SIZE)
static char thread1_stack[1024];
static struct rt_thread thread1;


/* 线程 1 入口 */
 void sendask(void *parameter)
{
    char *str;
    int i;
    static int k=1;
    int t=500;
    uint8_t t1[]={0x0a,0X0b,0X14,0xaa,0x0d};//位标1地址0x0a,0X0b,0X14,地址2571，通道20
    uint8_t t2[]={0x0a,0X0c,0X14,0xaa,0x0d};//位标2地址0x0a,0X0c,0X14,地址2572，通道20
    uint8_t t3[]={0x0a,0xdd,0X14,0xaa,0x0d};//位标3地址0x0a,0X0d,0X14,地址2573，通道20
    uint8_t t4[]={0x0a,0X0e,0X14,0xaa,0x0d};//位标4地址0x0a,0X0e,0X14,地址2574，通道20
    uint8_t t5[]={0x0a,0X0f,0X14,0xaa,0x0d};//位标5地址0x0a,0X0f,0X14,地址2575，通道20
    while (1)
    {
        rt_thread_mdelay(t);
        if(k){
                for(i=0;i<5;i++)
                    uart_putstr(USART2,"%c",t1[i]); //以单个字符的方式输出
                fla=1;
                k=0;
                uart_putstr(USART1,"receive 1");
                rt_thread_mdelay(t);
              }
        else {
                if (rt_mb_recv(&mb, (rt_ubase_t *)&str, RT_WAITING_FOREVER) == RT_EOK)
                   {
                        for(i=0;i<5;i++)
                            uart_putstr(USART2,"%c",t1[i]); //以单个字符的方式输出

                        fla=1;
                        uart_putstr(USART1,"receive 1");
                        rt_thread_mdelay(t);//防止连续接收邮件

                   }
                }
                /* 从邮箱中收取邮件 */
                if (rt_mb_recv(&mb, (rt_ubase_t *)&str, RT_WAITING_FOREVER) == RT_EOK)
                {
                    for(i=0;i<5;i++)
                              uart_putstr(USART2,"%c",t2[i]); //以单个字符的方式输出

                    fla=1;
                    uart_putstr(USART1,"receive 2");
                    rt_thread_mdelay(t);
                }
                if (rt_mb_recv(&mb, (rt_ubase_t *)&str, RT_WAITING_FOREVER) == RT_EOK)
               {
                    for(i=0;i<5;i++)
                            uart_putstr(USART2,"%c",t3[i]); //以单个字符的方式输出

                    fla=1;
                    uart_putstr(USART1,"receive 3");
                    rt_thread_mdelay(t);
                }
                if (rt_mb_recv(&mb, (rt_ubase_t *)&str, RT_WAITING_FOREVER) == RT_EOK)
              {
                for(i=0;i<5;i++)
                   uart_putstr(USART2,"%c",t4[i]); //以单个字符的方式输出

              fla=1;
              uart_putstr(USART1,"receive 4");
              rt_thread_mdelay(t);
               }
                if (rt_mb_recv(&mb, (rt_ubase_t *)&str, RT_WAITING_FOREVER) == RT_EOK)
                           {
                for(i=0;i<5;i++)
                       uart_putstr(USART2,"%c",t5[i]); //以单个字符的方式输出

                fla=1;
                uart_putstr(USART1,"receive 5");
                rt_thread_mdelay(t);
                           }

    }

}

void mailbox_sample(void)
{
    rt_err_t result;

      /* 初始化一个 mailbox */
      result = rt_mb_init(&mb,
                          "mbt",                      /* 名称是 mbt */
                          &mb_pool[0],                /* 邮箱用到的内存池是 mb_pool */
                          sizeof(mb_pool) / 4,        /* 邮箱中的邮件数目，因为一封邮件占 4 字节 */
                          RT_IPC_FLAG_FIFO);          /* 采用 FIFO 方式进行线程等待 */
      if (result != RT_EOK)
      {
          rt_kprintf("init mailbox failed.\n");
      }

      rt_thread_init(&thread1,
                     "thread1",
                     sendask,
                     RT_NULL,
                     &thread1_stack[0],
                     sizeof(thread1_stack),
                     THREAD_PRIORITY, THREAD_TIMESLICE);
      rt_thread_startup(&thread1);


}



#include <rtthread.h>

#define SAMPLE_UART_NAME                 "uart2"
#define DATA_CMD_END                     '~'       /* 结束位设置为 \r，即回车符 */
#define ONE_DATA_MAXLEN                  512        /* 不定长数据的最大长度 */

/* 用于接收消息的信号量 */
static struct rt_semaphore rx_sem;
static rt_device_t serial;

/* 接收数据回调函数 */
static rt_err_t uart_rx_ind(rt_device_t dev, rt_size_t size)
{
    /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
    if (size > 0)
    {
        rt_sem_release(&rx_sem);
    }
 //   rt_kprintf("datass");
    if (fla)
              {rt_mb_send(&mb, (rt_uint32_t)&mb_str1);
              fla=0;
              }
    return RT_EOK;
}

static char uart_sample_get_char(void)
{
    char ch;

    while (rt_device_read(serial, 0, &ch, 1) == 0)
    {
        rt_sem_control(&rx_sem, RT_IPC_CMD_RESET, RT_NULL);
        rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
    }
    return ch;
}

/* 数据解析线程 */
char data[ONE_DATA_MAXLEN];
static void data_parsing(void)
{

    char ch;
    static char i = 0;

    while (1)
    {
        ch = uart_sample_get_char();
       // rt_device_write(serial, 0, &ch, 1);
        if(ch == DATA_CMD_END)
        {
            data[i++] = '\0';
            rt_kprintf("data=%s\r\n",data);
            i = 0;
            continue;
        }
        i = (i >= ONE_DATA_MAXLEN-1) ? ONE_DATA_MAXLEN-1 : i;
        data[i++] = ch;
    }
}

void uart2_sample(void)
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









/*
 * 程序清单：这是一个串口设备接收不定长数据的示例代码
 * 例程导出了 uart_dma_sample 命令到控制终端
 * 命令调用格式：uart_dma_sample uart2
 * 命令解释：命令第二个参数是要使用的串口设备名称，为空则使用默认的串口设备
 * 程序功能：通过串口 uart2 输出字符串"hello RT-Thread!"，并通过串口 uart2 输入一串字符（不定长），再通过数据解析后，使用控制台显示有效数据。
*/
//
// #include <rtthread.h>
// #include "usart2.h"
// #define SAMPLE_UART_NAME                 "uart2"
// #define DATA_CMD_END                     '~'       /* 结束位设置为 \r，即回车符 */
// #define ONE_DATA_MAXLEN                  128         /* 不定长数据的最大长度 */
// char data[ONE_DATA_MAXLEN];
// /* 用于接收消息的信号量 */
// struct rt_semaphore rx_sem;
// static rt_device_t serial;
//
// /* 接收数据回调函数 */
// static rt_err_t uart_rx_ind(rt_device_t dev, rt_size_t size)
// {//rt_kprintf("data\r");
//     /* 串口接收到数据后产生中断，调用此回调函数，然后发送接收信号量 */
//     if (size > 0)
//     {
//         rt_sem_release(&rx_sem);
//     }
//     if (fla)
//          {rt_mb_send(&mb, (rt_uint32_t)&mb_str1);
//          fla=0;
//          }
//     return RT_EOK;
// }
//
// static char uart_sample_get_char(void)
// {
//     char ch;
//
//     while (rt_device_read(serial, 0, &ch, 1) == 0)
//     {
//         rt_sem_control(&rx_sem, RT_IPC_CMD_RESET, RT_NULL);
//        // rt_sem_take(&rx_sem, RT_WAITING_FOREVER);
//     }
//     return ch;
// }
//
// /* 数据解析线程 */
// static void data_parsing(void)
// {
//     char ch;
//
//     static char i = 0;
//
//     while (1)
//     {
//         ch = uart_sample_get_char();
//
//         //rt_device_write(serial, 0, &ch, 1);
//         //rt_kprintf("%s",ch);//不注释掉会一直打印控
//         if(ch == DATA_CMD_END)
//         {
//             data[i++] = '\0';
//             rt_kprintf("data=%s\r\n",data);
//             //uart_putstr(USART2,"data=%s\r\n",data);
//             i = 0;
//             continue;
//         }
//         i = (i >= ONE_DATA_MAXLEN-1) ? ONE_DATA_MAXLEN-1 : i;
//         data[i++] = ch;
//     }
// }
//
// //void uart2_sample(void *parameter)
// void uart2_sample(void)
// {
//     char uart_name[RT_NAME_MAX];
//     char str2[] = "hello RT-Thread!\r\n";
//         rt_strncpy(uart_name, SAMPLE_UART_NAME, RT_NAME_MAX);
//     /* 查找系统中的串口设备 */
//     serial = rt_device_find(uart_name);
//     if (!serial)
//     {
//         rt_kprintf("find %s failed!\n", uart_name);
//     }
//
//     /* 初始化信号量 */
//     rt_sem_init(&rx_sem, "rx_sem", 0, RT_IPC_FLAG_FIFO);
//     /* 以中断接收及轮询发送模式打开串口设备 */
//     rt_device_open(serial, RT_DEVICE_FLAG_INT_RX);
//     /* 设置接收回调函数 */
//     rt_device_set_rx_indicate(serial, uart_rx_ind);
//     /* 发送字符串 */
//     rt_device_write(serial, 0, str2, (sizeof(str2) - 1));
//
//     /* 创建 serial 线程 */
//     rt_thread_t thread = rt_thread_create("serial", (void (*)(void *parameter))data_parsing, RT_NULL, 1024, 25, 10);
//     /* 创建成功则启动线程 */
//
//     if (thread != RT_NULL)
//     {
//         rt_thread_startup(thread);
//     }
//
// }
/*
* 程序清单：这是一个串口设备接收不定长数据的示例代码
* 例程导出了 uart_dma_sample 命令到控制终端
* 命令调用格式：uart_dma_sample uart2
* 命令解释：命令第二个参数是要使用的串口设备名称，为空则使用默认的串口设备
* 程序功能：通过串口 uart2 输出字符串"hello RT-Thread!"，并通过串口 uart2 输入一串字符（不定长），再通过数据解析后，使用控制台显示有效数据。
*/

