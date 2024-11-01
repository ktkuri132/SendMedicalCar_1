#ifndef __CONTORL_H_
#define __CONTORL_H_

#include <control.hpp>
#include <pid.h>

#ifdef __cplusplus
extern "C" {
#endif

#include <sys.h>
#include <pwm.h>
#include <usart.h>

void Control_Init();
void Control_task_Init();
void Task_Choose();

void HW_Port_Init();
void Medical_interput_callback();


//定义红外探测的接口
#define HW201 6

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus


// 前向声明PID类
class PID_Control;
class Line_Control;
class Turn_Control;


/// @brief 定义控制基类
class Control
{
private:
    /* data */
    
public:
    // 用于存储路径的坐标
    uint32_t (*PATH_Site)[3];
    // 定义不同的控制对象的指针
    Line_Control* Obj_ForLineControl;
    Turn_Control* Obj_ForTurnControl;
    // 路径检查函数
    uint32_t (*PATH_Start_Check())[3];
    Control(/* args */);
    ~Control();
    
};



/// @brief 定义直线线控制类，继承控制类
class Line_Control : public Control
{

private:

public:
    PID_Control* Obj_ForPIDLineControl;
    uint32_t OutPut;
    Line_Control(/* args */);
    ~Line_Control();

    float Put_PWM()
    {
        this->OutPut =  uint32_t(Obj_ForPIDLineControl->PID_Update());
    }

};

class Turn_Control : public Control
{
private:
    /* data */

public:
    PID_Control* Obj_ForPIDTurnControl;
    Turn_Control(/* args */);
    ~Turn_Control();
};


/// @brief 定义PID类，继承控制类
class PID_Control : public Line_Control,Turn_Control
{
private:
    /* data */
    float error;
    float error_last;

    

    float integral;
    float derivative;
    // 输出限幅
    float max_Output;
    // 积分限幅
    float max_integral;
public:
    float target;
    float feedback;

    float kp;
    float ki;
    float kd;
    float PID_Update();
    PID_Control(/* args */);
    ~PID_Control();
};

#endif



#endif 