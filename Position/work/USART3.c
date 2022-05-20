
//extern char Rx3_Buffer[];





 #include "USART3.h"


  /*
   * 程序清单：这是一个串口设备接收不定长数据的示例代码
   * 例程导出了 uart_dma_sample 命令到控制终端
   * 命令调用格式：uart_dma_sample uart2
   * 命令解释：命令第二个参数是要使用的串口设备名称，为空则使用默认的串口设备
   * 程序功能：通过串口 uart2 输出字符串"hello RT-Thread!"，并通过串口 uart2 输入一串字符（不定长），再通过数据解析后，使用控制台显示有效数据。
  */

  #include <rtthread.h>

  #define SAMPLE_UART_NAME                 "uart3"
  #define DATA_CMD_END                     '\r'       /* 结束位设置为 \r，即回车符 */
  #define ONE_DATA_MAXLEN                  128         /* 不定长数据的最大长度 */
  char data[ONE_DATA_MAXLEN];
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
      char f=0xaa;
      static char i = 0;

      while (1)
      {
          ch = uart_sample_get_char();

         // rt_device_write(serial, 0, &ch, 1);
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
          //uart_putstr(USART3,"%c",data[0]);

          if(data[0]==f)
          flagusart3=1;
      }
  }

  void uart3_sample(void *parameter)
  {
     // rt_err_t ret = RT_EOK;
      char uart_name[RT_NAME_MAX];
      char str[] = "hello RT-Thread!\r\n";

 //     if (argc == 2)
 //     {
 //         rt_strncpy(uart_name, argv[1], RT_NAME_MAX);
 //     }
 //     else
 //     {
          rt_strncpy(uart_name, SAMPLE_UART_NAME, RT_NAME_MAX);
 //     }

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
