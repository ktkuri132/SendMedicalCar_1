#include <control.hpp>

extern uint32_t Medical;

uint32_t Medical = 1;

uint32_t   encode1_count;
uint32_t   encode2_count;
uint32_t    encode_1_speed;
uint32_t    encode_2_speed;

extern uint8_t UART_DATA_TYPE;

/// @brief 红外信号翻转
void Medical_interput_callback()
{
    Medical = -Medical;
}

/// @brief 读取编码器的值
/// @return 
bool encoder_GetSign()
{
    encode_1_speed = encode1_count;
    encode_2_speed = encode2_count;

    encode1_count = 0;
    encode2_count = 0;
    return true;

}

void temp_callback()
{
    static a=1;
    if(a)
    {
        a=0;
        PWM_SetDuty(MotorLeft, 0);
        PWM_SetDuty(MotorRight, 0);
    }
    else
    {
        a=1;
        PWM_SetDuty(MotorLeft, 3000);
    }
}


/// @brief 控制系统初始化
void Control_Init()
{
    //初始化红外接口
    HW_Port_Init();
    //产生红外信号中断
    gpio_set_irq_enabled_with_callback(HW201, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, 
                                        true,Medical_interput_callback);
    //开启定时器中断，5ms中断一次
    static struct repeating_timer timer;
    add_repeating_timer_ms(5,Task_Choose,NULL,&timer);
}

/// @brief 红外接口初始化
void HW_Port_Init()
{
    gpio_init(HW201);
    gpio_set_dir(HW201, GPIO_IN);
    gpio_pull_up(HW201);
}


