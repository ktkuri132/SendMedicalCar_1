extern "C" {

#include <control.h>

}


#include <pid.h>


int __PID::__pid_test()
{

}

__PID::__PID(/* args */)
{
    this->error = this->target - this->feedback;
}

__PID::~__PID()
{

}
