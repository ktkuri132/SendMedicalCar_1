#include <control.h>

void Control_Init()
{
    
    ENcoder_Init();
    //开启定时器中断，5ms中断一次
    add_repeating_timer_ms(5,Control_task_Init,NULL,NULL);

}



void PID_Control(float target,float current,struct PID *pid)
{
    
    pid->error = target - current;
    pid->integral += pid->error;
    pid->derivative = pid->error - pid->error_last;

    // Integral windup guard
    if (pid->integral > pid->integral_max) {
        pid->integral = pid->integral_max;
    } else if (pid->integral < pid->integral_min) {
        pid->integral = pid->integral_min;
    }

    pid->output = pid->kp * pid->error + pid->ki * pid->integral + pid->kd * pid->derivative;
    pid->error_last = pid->error;
}