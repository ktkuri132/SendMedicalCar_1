#include <control.h>

extern uint32_t Medical;

extern uint8_t UART_DATA_TYPE;



/// @brief 控制系统初始化
void Control_task_Init()
{
    
}





void Mode_test()
{
    if(UART_DATA_TYPE==6)
    {
        AllStop
    }
    else if(UART_DATA_TYPE==1)
    {
        Line_Control();
    }
    else if(UART_DATA_TYPE==2)
    {
        
        
        
        
    }
    else
    {
        //Medical_interput_callback();
    }
}




/// @brief 任务选择
void Task_Choose()
{
    //Mode_Chose();
    Mode_test();
    //printf("%d,",Medical);

}