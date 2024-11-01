#ifndef __CONTORL_H_
#define __CONTORL_H_

#ifdef __cplusplus

#include <pid.h>

extern "C" {
#endif

#include <sys.h>
#include <pwm.h>
#include <usart.h>


void Control_Init();
void Control_task_Init();
void Task_Choose();

void HW_Port_Init();
void Medical_interput_callback();

uint32_t (*PATH_Start_Check())[2];


//定义红外探测的接口
#define HW201 6

#ifdef __cplusplus
}
#endif


#endif // !__CONTORL_H_