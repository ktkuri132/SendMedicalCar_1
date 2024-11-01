#include <pid.h>


float PID_Control::PID_Update()
{
    this->error = this->target - this->feedback;
    
}

PID_Control::PID_Control(/* args */)
{
    
}

PID_Control::~PID_Control()
{

}
