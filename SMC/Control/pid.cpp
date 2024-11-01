#include <pid.h>
#include <control.hpp>

float PID_Control::PID_Update()
{
    this->error = this->target - this->feedback;
    this->integral += this->error;  //积分
    this->derivative = this->error - this->error_last;  //微分

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
    this->OutPut = this->kp * this->error + this->ki * this->integral + this->kd * this->derivative;
    if(this->OutPut > this->max_Output)
    {
        this->OutPut = this->max_Output;
    }
    else if(this->OutPut < -this->max_Output)
    {
        this->OutPut = -this->max_Output;
    }
    this->error_last = this->error;
    
}

PID_Control::PID_Control(/* args */)
{
    Obj_ForLineControl = new Line_Control;
    Obj_ForTurnControl = new Turn_Control;
}

PID_Control::~PID_Control()
{
    delete Obj_ForLineControl;
    delete Obj_ForTurnControl;
}
