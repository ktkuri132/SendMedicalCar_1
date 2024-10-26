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

uint8_t Res_note = 0;  //数据节点
uint8_t Res_len = 0;    //接收数据的下标

uint8_t UART_NOTE = 0;  //本次数据节点
uint8_t UART_LEN = 0;   //本次接收数据的长度

uint8_t UART_NOTE_LEN[20];  //某次数据节点的长度

void uart1_irq_handler()
{
    //判断是否是接收中断
    if(uart_is_readable(uart1))
    {
        c = uart_getc(uart1);   //获取第一个字符
        if(c=='s')          //如果是开始字符
        {
            UART_Strat = 1;     //开始接收
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
            if(UART_Strat)
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
    uint8_t sum = 0;
    uint8_t len = UART_NOTE_LEN[point_note];
    
    for (uint8_t i = 0; i < len; i++)
    {
        sum = sum * 10 + (Data[point_note][i] - '0');
    }

    return sum;
}