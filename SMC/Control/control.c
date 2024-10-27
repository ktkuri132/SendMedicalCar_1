#include <control.h>

uint32_t Medical = 1;

uint32_t   encode1_count;
uint32_t   encode2_count;
uint32_t    encode_1_speed;
uint32_t    encode_2_speed;


/// @brief 红外信号翻转
void Medical_interput_callback()
{
    Medical = -Medical;
}

/// @brief 读取编码器的值
/// @return 
bool encoder_GetSign()
{
    encode_1_speed = encode1_count;
    encode_2_speed = encode2_count;

    encode1_count = 0;
    encode2_count = 0;
    return true;

}

/// @brief 基本PID计算函数
/// @param target 目标值
/// @param current 当前值
/// @param pid PID结构体对象
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

