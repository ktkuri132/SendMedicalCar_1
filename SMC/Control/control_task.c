#include <control.h>

struct PID pid_test = {0,0,0,0,0,0,0,0,0,0,PID_Control};

void Control_task_Init()
{
    pid_test.PID_Control(0,0,&pid_test);
}