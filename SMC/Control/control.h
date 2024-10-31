#ifndef __CONTORL_H_
#define __CONTORL_H_

#include <sys.h>
#include <pwm.h>
#include <usart.h>

void Control_Init();
void Control_task_Init();
void Task_Choose();

void HW_Port_Init();
void Medical_interput_callback();

uint32_t (*PATH_Start_Check())[2];


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

    float error;
    float error_last;

    float integral;
    float derivative;

    float output;
    float integral_max;
    float integral_min;
    void (*PID_Control)(float target,float current,struct PID *pid);
};

void PID_Control(float target,float current,struct PID *pid);

#endif // !__CONTORL_H_