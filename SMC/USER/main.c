#include <main.h>
#include <pico/multicore.h>
#include <hardware/timer.h>

//这里验证一下是否能够正常调用
extern struct PID pid_test;
extern uint32_t encode1_count,encode2_count;
extern uint32_t encode_1_speed,encode_2_speed;

void core1_main();

uint32_t Medical = 1;
extern uint8_t c;
extern uint8_t Data[20][200],USART_array[20][200],UART_NOTE_LEN[20],Res_len,UART_LEN,Res_note,UART_NOTE;

//主核心的main函数
int main()
{
    //开启串口
    stdio_usb_init();
    
    //开启副核心
    multicore_launch_core1(core1_main);
    //初始化OLED
    
    PWM_Init();
    while (1) 
    {
        
        //printf("Data[0] = %d\n", Data[0]);
        if(Medical==-1)
        {
            
        }
        else if(Medical==1)
        {
            
        }
        
    }
}   



void Medical_interput_callback()
{
    Medical = -Medical;
}


//副核心的main函数
void core1_main() 
{
    
    //初始化编码器
    ENcoder_Init();
    //初始化OLED
    OLED_Init();
    //初始化串口
    USART_Init();

    gpio_set_irq_enabled_with_callback(ENCODER_A1, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, 
                                        true, encoder_interput_callback);
    gpio_set_irq_enabled_with_callback(ENCODER_A2, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, 
                                        true, encoder_interput_callback);
    gpio_set_irq_enabled_with_callback(HW201, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, 
                                        true,Medical_interput_callback);
    struct repeating_timer timer;
    add_repeating_timer_ms(5,encoder_timer_callback,NULL,&timer);
    
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

