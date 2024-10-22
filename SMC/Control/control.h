#ifndef __CONTORL_H_
#define __CONTORL_H_

void Control_Init();
void Control_task_Init();


/*
    ����ͨ��PID�ṹ��
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