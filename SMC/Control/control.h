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


//定义红外探测的接口
#define HW201 6

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
#define Current_Enable_Left 1
#define Current_Enable_Right 2
#define Current_Disable 3


/*                              
    定义转向的数据格式：      1  2  3   | 4  5  6  7  8 |    9    | 10
                           病房号    |     路口       | 转向使能 | 转向方向

                 定义路径的状态：共有4个路口          
*/

// 近端病房
#define Inpatient_Ward_1_Goto (0B00010011)  // 前往病房1，在路口0转向，转向方向为左
#define Inpatient_Ward_2_Goto (0B00100010)  // 前往病房2，在路口0转向，转向方向为右

// 中端病房
#define Inpatient_Ward_3_Goto (0B00110111)  // 前往病房3，在路口1转向，转向方向为左
#define Inpatient_Ward_3_Stop (0B00110100)  // 前往病房3，在路口1不转向

#define Inpatient_Ward_4_Goto (0B01000110)  // 前往病房4，在路口1转向，转向方向为右
#define Inpatient_Ward_4_Stop (0B01000100)  // 前往病房4，在路口1不转向

// 远端病房
#define Inpatient_Ward_5_Goto (0B01010111)  // 前往病房5，在路口2转向，转向方向为左
#define Inpatient_Ward_5_Stop (0B01010100)  // 前往病房5，在路口2不转向





#endif // !__CONTORL_H_