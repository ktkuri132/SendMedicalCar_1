extern "C" {

#include <control.h>

}


#include <pid.h>


int PID::pid_test()
{

}

PID::PID(/* args */)
{
    this->error = this->target - this->feedback;
}

PID::~PID()
{

}
