#include <control.hpp>


extern uint32_t Medical;

//巡线的坐标的目标值
#define Target_X_Site 118
#define Target_Y_Site 0



/// @brief 任务选择
void Task_Choose()
{
    static Control control;
    // 获取当前位置信息
    control.PATH_Site =  control.PATH_Start_Check();
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
    switch (control.PATH_Site[0][0])
    {
        case 1:
            
            break;
        case 2:

            break;
        case 5:

            break;
        default:break;
            
    }
    return;


}