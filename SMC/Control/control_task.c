#include <control.h>

extern uint32_t Medical;





/// @brief 控制系统初始化
void Control_task_Init()
{
    
    
    //pid_test.PID_Control(0,0,&pid_test);
}

/// @brief 任务选择
void Task_Choose()
{
    //Mode_Chose();
    
    printf("%d,",Medical);
    Line_Control();

}