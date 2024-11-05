#include <control.h>

extern uint32_t Medical;



/// @brief 控制系统初始化
void Control_Init()
{
    //初始化红外接口
    HW_Port_Init();
    //初始化控制任务
    Control_task_Init();
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
 

void LED_Init()
{
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    gpio_put(25,0);
}