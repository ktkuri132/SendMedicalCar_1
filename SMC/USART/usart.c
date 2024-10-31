#include <usart.h>
#include <string.h>
#include <math.h>
uint8_t USART_array[20][200];

uint8_t Data[20][200];


uint8_t c;

void uart1_irq_handler();
void uart0_irq_handler();

void USART_Init()
{
    uart_init(uart1, 115200);
    gpio_set_function(4, GPIO_FUNC_UART);
    gpio_set_function(5, GPIO_FUNC_UART);

    //打开串口中断
    uart_set_irq_enables(uart1, true, false);  
    irq_set_exclusive_handler(UART1_IRQ, uart1_irq_handler);
    irq_set_enabled(UART1_IRQ, true);

}

void uart0_irq_handler()
{
    //判断是否是接收中断
    if(uart_is_readable(uart0))
    {
        c = uart_getc(uart0);
        uart_write_blocking(uart0, &c, 1);
        printf("c = %c\n", c);
    }
}

uint8_t UART_Strat = 0;
uint8_t UART_End = 0;

uint8_t Res_Data_type = 0;    //数据格式检测标志位
uint8_t UART_DATA_TYPE = 0;    //真实数据格式

uint8_t Res_note = 0;  //数据节点
uint8_t Res_len = 0;    //接收数据的下标

uint8_t UART_NOTE = 0;  //本次数据节点
uint8_t UART_LEN = 0;   //本次接收数据的长度

uint8_t UART_NOTE_LEN[20];  //某次数据指定节点的数据长度

void CMD_Callback()
{
    //处理命令
}

// 串口1中断处理函数：检测数据格式，接收数据
void uart1_irq_handler()
{
    //判断是否是接收中断
    if(uart_is_readable(uart1))
    {
        c = uart_getc(uart1);   //获取第一个字符
        if(c=='s')          //如果是开始字符
        {
            UART_Strat = 1;     //开始接收
            Res_Data_type = 1;    //开始检测数据格式
            Res_len = 0;        //下标清零
            Res_note = 0;       //数据节点清零
            return;
        }
        else if(c=='e')     //如果是结束字符
        {
            UART_NOTE_LEN[Res_note] = Res_len;  //保存最后一次数据节点的长度

            UART_Strat = 0;     //重新开始
            UART_LEN = Res_len;   //保存本次数据长度
            UART_NOTE = Res_note+1;  //保存本次数据节点

            Res_note = 0;       //数据节点清零
            Res_len=0;          //下标清零
            memcpy(Data,USART_array,sizeof(USART_array));   //将数据拷贝到Data数组
            memset(USART_array,0,sizeof(USART_array));   //清空USART_array数组
            return;
        }
        else if(c==',')
        {
            UART_NOTE_LEN[Res_note] = Res_len;  //保存本次数据节点的长度
            Res_note++;     //数据节点加1
            Res_len = 0;    //下标清零
        }
        else
        {
            if(Res_Data_type)     //先检测数据格式
            {
                switch (c)
                {
                    //若是是寻直线状态，只接收直线的两个数据
                    case '1':UART_DATA_TYPE=1;break;
                    //若是扫到了十字路口
                    case '2':UART_DATA_TYPE=2;break;
                    
                    // 其他数据格式......

                    // 检测：命令数据格式
                    case 'p':
                        UART_DATA_TYPE='p';
                        CMD_Callback();
                    break;

                    default:break;
                        
                }
                Res_Data_type=0;   //关闭数据格式检测
            }

            if(UART_Strat)      // 开始接收后，数组的第一个位置存储的是数据格式，读数据要从第二个位置开始
            {
                USART_array[Res_note][Res_len] = c;  //存储数据
                Res_len++;     //下标加1
            }
        }
        
    }
}



/// @brief 处理串口数据针对于数字
/// @param point_note 待处理的指定节点 
uint8_t USART_Deal(uint8_t point_note)
{
    //检查是否越界
    if(point_note > UART_NOTE)
    {
        return 0;
    }


    uint8_t sum = 0;
    uint8_t len = UART_NOTE_LEN[point_note];
    
    for (uint8_t i = 0; i < len; i++)
    {
        uint8_t temp_target = Data[point_note][i];
        // 判断临时目标数据的ascll码值
        if(!(temp_target >= '0' && temp_target <= '9'))     //如果不是数字字符
        {
            return temp_target;         //直接返回
        }
        

        sum = sum * 10 + (temp_target - '0');
    }

    return sum;
}

