#include <main.h>
#include <pico/multicore.h>
#include <hardware/timer.h>

//这里验证一下是否能够正常调用
extern struct PID pid_test;
extern uint32_t encode1_count,encode2_count;
extern uint32_t encode_1_speed,encode_2_speed;

void core1_main();

uint32_t Medical = 1;

//主核心的main函数
int main()
{
    //开启串口
    stdio_init_all();
    //开启副核心
    multicore_launch_core1(core1_main);
    //初始化OLED
    

    //Control_Init();
    //Control_task_Init();
    PWM_Init();
    while (1) 
    {
        if(Medical==-1)
        {
            PWM_SetDuty(MotorLeft,5000);
            PWM_SetDuty(MotorRight,5000);
        }
        else if(Medical==1)
        {
            PWM_SetDuty(MotorLeft,0);
            PWM_SetDuty(MotorRight,0);
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
        OLED_Printf(0, 16,OLED_8X16, "speed_1:%d",encode_1_speed);
        OLED_Printf(0, 32,OLED_8X16, "speed_2:%d",encode_2_speed);
        OLED_Printf(0, 48,OLED_8X16, "Medical:%d",Medical);
        OLED_Update();
    }
}

