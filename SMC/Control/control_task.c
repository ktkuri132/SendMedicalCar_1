#include <control.h>

extern uint32_t Medical;

//巡线的坐标的目标值
#define Target_X_Site 0
#define Target_Y_Site 0

struct PID pid_test = {0,0,0,0,0,0,0,0,0,0,PID_Control};

/// @brief 控制系统初始化
void Control_task_Init()
{
    pid_test.PID_Control(0,0,&pid_test);
}

void Task_Choose()
{
    //编码器读值
    encoder_GetSign();

    if(Medical==1)
    {
        goto start;
    }
    else if(Medical==-1)
    {
        goto stop;
    }

start:

    return;


stop:
    
    return;

}