#include <control.hpp>


extern uint32_t Medical;





/// @brief 任务选择
void Task_Choose()
{
    static Control control;     //定义控制类对象,初始化了所有子类对象
    // 获取当前位置信息
    control.PATH_Site = control.PATH_Start_Check();
    
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
            control.Obj_ForLineControl->Put_PWM();
            break;
        case 2:
            
            break;
        case 5:

            break;
        default:break;
            
    }
    return;


}