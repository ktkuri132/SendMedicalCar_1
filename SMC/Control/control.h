#ifndef __CONTORL_H_
#define __CONTORL_H_

#include <sys.h>
#include <pwm.h>
#include <usart.h>

void LED_Init();
void Mode_Chose();
void Line_Control();
void Control_Init();
void Control_task_Init();
void Task_Choose();

void HW_Port_Init();
void Medical_interput_callback();

uint32_t (*PATH_Start_Check())[3];


//巡线的坐标的目标值
#define Target_X_Site 118
#define Target_Y_Site 0

// 基础电机PWM
#define Bash_Left_PWM  3000
#define Bash_Right_PWM 3000


//定义红外探测的接口
#define HW201 6

/*
    定义通用PID结构体
*/
typedef struct PID
{
    float kp;
    float ki;
    float kd;

    float integral_max;
    float output_max;

    void (*PID_Control)(float target,float current,struct PID *pid);

    float target;
    float current;

    float error;
    float error_last;

    float integral;
    float derivative;

    float output;

    
    
};

void PID_Control(float target,float current,struct PID *pid);




#endif // !__CONTORL_H_