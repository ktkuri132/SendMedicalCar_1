#ifndef __CONTORL_H_
#define __CONTORL_H_

#include <control.hpp>
#include <pid.h>

#define __Other_Control_
#define __PID_Control_

//巡线的坐标的目标值
#define Target_X_Site 118
#define Target_Y_Site 0

#ifdef __cplusplus
extern "C" {
#endif

#include <OLED.h>
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


// 前向声明
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

#ifdef __PID_Control_

/// @brief 定义PID类，继承控制类
class PID_Control :public Control
{
private:
    /* data */
    float error;
    float error_last;

    float integral;
    float derivative;

public:
    float target;
    float feedback;

    // 输出限幅
    float max_Output;
    // 积分限幅
    float max_integral;

    float kp;
    float ki;
    float kd;

    float OutPut;
    float PID_Update();
    PID_Control(/* args */);
    ~PID_Control();
};

#endif

#ifdef __Other_Control_

/// @brief 定义直线控制类，继承PID类
class Line_Control : public PID_Control
{

private:

public:
    Line_Control(/* args */);
    ~Line_Control();

    uint32_t OutPut;
    
    float Put_PWM()
    {   
        PID_Control::feedback = Control::PATH_Site[0][1];
        PID_Control::PID_Update();

        if(PID_Control::OutPut>0)
        {
            AllForward;
            this->OutPut = (uint32_t)PID_Control::OutPut;
        }
        else if(PID_Control::OutPut<0)
        {
            AllBackward;
            this->OutPut = (uint32_t)(-PID_Control::OutPut);
        }

        PWM_SetDuty(MotorLeft, this->OutPut);
        PWM_SetDuty(MotorRight, this->OutPut);
    }

};

/// @brief 定义转向控制类，继承PID类
class Turn_Control : public PID_Control
{
private:
    /* data */

public:
    PID_Control* Obj_ForPIDTurnControl;
    Turn_Control(/* args */);
    ~Turn_Control();
};

#endif


#endif



#endif 