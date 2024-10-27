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
        OLED_Printf(0, 0,OLED_8X16, "Running...");
        //OLED_Printf(0, 16,OLED_8X16, "Res:%c%c%c",Data[1][0],Data[1][1],Data[1][2]);
        OLED_Printf(0, 32,OLED_8X16, "x:%d,y:%d",USART_Deal(0),USART_Deal(1));
        //OLED_Printf(0, 32,OLED_8X16, "note:%d",UART_NOTE);
        OLED_Printf(0,48,OLED_8X16,"Len:%d",UART_NOTE_LEN[1]);
        //OLED_Printf(0, 48,OLED_8X16, "Medical:%d",Medical);
        OLED_Update();
    }
}

