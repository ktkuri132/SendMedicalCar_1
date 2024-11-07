#ifndef __CONTORL_H_
#define __CONTORL_H_

#include <sys.h>
#include <pwm.h>
#include <usart.h>

void LED_Init();
void Mode_Chose();


void Line_Control();
void Turn_Control(uint8_t orientation);

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
#define Bash_Left_PWM  3500
#define Bash_Right_PWM 3500

// 定义转向方向
#define left 1
#define right 2

// 定义转向次数,最多转4次
#define Turn_Times_0 0  // 不转向
#define Turn_Times_1 1  // 转1次,当前使用与否看转向使能
#define Turn_Times_2 2
#define Turn_Times_3 3
#define Turn_Times_4 4

// 定义某次转向的使能与否，方向如何
#define Time_1_Enable_Left 1
#define Time_1_Enable_Right 2
#define Time_1_Disable 3

#define Time_2_Enable_Left 4
#define Time_2_Enable_Right 5
#define Time_2_Disable 6

#define Time_3_Enable_Left 7
#define Time_3_Enable_Right 8
#define Time_3_Disable 9

#define Time_4_Enable_Left 10
#define Time_4_Enable_Right 11
#define Time_4_Disable 12

#define Enable_Left 1
#define Enable_Right 2
#define Disable_Turn 3

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