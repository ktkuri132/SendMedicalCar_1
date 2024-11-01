#include <control.h>


extern uint32_t Medical;

//巡线的坐标的目标值
#define Target_X_Site 118
#define Target_Y_Site 0

PID pid_forline;

/// @brief 控制系统初始化
void Control_task_Init()
{
    
    pid_forline.kp = 0.1;
    pid_forline.ki = 0.1;
    pid_forline.kd = 0.1;
    
}

/// @brief 任务选择
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

stop:
    
    return;

start:
    uint32_t (*temp_Site)[2] = PATH_Start_Check();
    uint32_t temp_X_Site = *temp_Site[0];
    pid_forline.pid_test();
    return;


}