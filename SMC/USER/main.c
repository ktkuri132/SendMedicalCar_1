#include <main.h>
#include <pico/multicore.h>
#include <hardware/timer.h>

//这里验证一下是否能够正常调用
extern struct PID pid_test;
extern uint32_t encode1_count,encode2_count;
extern uint32_t encode_1_speed,encode_2_speed;

void core1_main();

extern uint32_t Medical;
extern uint8_t c;
extern uint8_t Data[20][200],USART_array[20][200],UART_NOTE_LEN[20],Res_len,UART_LEN,Res_note,UART_NOTE;

//主核心的main函数
int main()
{
    //开启USB串口
    stdio_usb_init();
    
    //开启副核心
    multicore_launch_core1(core1_main);
    //初始化控制系统
    Control_Init();
    //初始化PWM
    PWM_Init();
    while (1) 
    {
        
        
    }
}   



extern uint8_t UART_PATH_STRAT;


//副核心的main函数
void core1_main() 
{
    
    
    //初始化OLED
    OLED_Init();
    //初始化串口
    USART_Init();
    //编码器接口初始化
    Encoder_Port_Init();

    while (1) 
    {
        OLED_Clear();

        //检擦路径状态
        switch (UART_PATH_STRAT)
        {
            case 1:
                OLED_Clear();
                OLED_Printf(0, 0,OLED_8X16, "ex:%d,ey:%d",USART_Deal(1),USART_Deal(2));
                break;
            case 2:
                OLED_Clear();
                OLED_Printf(0, 0,OLED_8X16, "cx:%d,cy:%d",USART_Deal(1),USART_Deal(2));
                OLED_Printf(0,16,OLED_8X16,"mx:%d,my:%d",USART_Deal(3),USART_Deal(4));
                OLED_Printf(0,32,OLED_8X16,"lx:%d,ly:%d",USART_Deal(5),USART_Deal(6));
                break;

            default:
                break;
        }

    /*     OLED_Printf(0, 0,OLED_8X16, "rx:%d,ry:%d",USART_Deal(0),USART_Deal(1));
        OLED_Printf(0, 16,OLED_8X16, "mx:%d,my:%d",USART_Deal(2),USART_Deal(3));
        OLED_Printf(0,32,OLED_8X16,"lx:%d,ly:%d",USART_Deal(4),USART_Deal(5));*/
        OLED_Printf(0,48,OLED_8X16,"PS:%d",UART_PATH_STRAT); 
        OLED_Update();
    }
}

