#include <pid.h>
#include <control.hpp>

#ifdef __PID_Control_

float PID_Control::PID_Update()
{
    this->error = this->target - this->feedback;
    //积分
    this->integral += this->error;  
    this->integral *= this->ki;
    //微分
    this->derivative = this->error - this->error_last;  
    // 积分限幅
    if(this->integral > this->max_integral)
    {
        this->integral = this->max_integral;
    }
    else if(this->integral < -this->max_integral)
    {
        this->integral = -this->max_integral;
    }

    // 输出限幅
    this->OutPut = this->kp * this->error + this->integral + this->kd * this->derivative;
    if(this->OutPut > this->max_Output)
    {
        this->OutPut = this->max_Output;
    }
    else if(this->OutPut < -this->max_Output)
    {
        this->OutPut = -this->max_Output;
    }
    //更新误差
    this->error_last = this->error;
    
}

PID_Control::PID_Control(/* args */)
{
    
}

PID_Control::~PID_Control()
{
   
}

#endif
