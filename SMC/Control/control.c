#include <control.h>

uint32_t Medical = -1;

uint32_t   encode1_count;
uint32_t   encode2_count;
uint32_t    encode_1_speed;
uint32_t    encode_2_speed;

extern uint8_t UART_DATA_TYPE;

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

    // 积分限幅
    if ((pid->integral > pid->integral_max)||(pid->integral<(-pid->integral_max)))
    {
        pid->integral = pid->integral_max;
    } 

    pid->output = pid->kp * pid->error + pid->ki * pid->integral + pid->kd * pid->derivative;

    // 输出限幅
    if((pid->output>pid->output_max)||(pid->output<(-pid->output_max)))
    {
        pid->output = pid->output_max;
    }

    pid->error_last = pid->error;
}

/// @brief 路径状态检查
uint32_t (*PATH_Start_Check())[3]
{
    static uint32_t Site[3];

    Site[0] = UART_DATA_TYPE;
    Site[1] = USART_Deal(1);
    Site[2] = USART_Deal(2);
    return &Site;
}

/// @brief 基础电机装载
/// @param Motor_Left 左
/// @param Motor_Right 右
void Motor_Load(float Motor_Left,float Motor_Right)
{
    if(Motor_Left>=0)
    {   
        LeftForward
        PWM_SetDuty(MotorLeft,(uint16_t)Motor_Left);
    }
    else
    {
        LeftBackward
        PWM_SetDuty(MotorLeft,(uint16_t)-Motor_Left);
    }

    if(Motor_Right)
    {
        RightForward
        PWM_SetDuty(MotorRight,(uint16_t)Motor_Right);
    }
    else
    {
        RightBackward
        PWM_SetDuty(MotorRight,(uint16_t)-Motor_Right);
    }
}

// @brief 巡线控制
void Line_Control()
{
    static struct PID pid_left = {-10,0,-5,500,3500,PID_Control};
    static struct PID pid_right ={10,0,5,500,3500,PID_Control};
    uint16_t temp_current = USART_Deal(1);

    pid_left.PID_Control(Target_X_Site,temp_current,&pid_left);
    pid_right.PID_Control(Target_X_Site,temp_current,&pid_right);

    //gpio_put(25,1);
    //编码器读值
    encoder_GetSign();

    if(Medical==1)
    {
        goto start;
    }
    else if(Medical==-1)
    {
        goto stop;
    }

stop:
    AllStop
    printf("%f\n",pid_left.output);
    return;

start:
    float Letf_output = Bash_Left_PWM + pid_left.output;
    float Right_output = Bash_Right_PWM + pid_right.output;
    printf("out:%d",Letf_output);
    Motor_Load(Letf_output,Right_output);
    return;
}


uint8_t Turn_Data=0;


/// @brief 对转向情况的初始化，对于转向的处理：在单次，摄像头扫到数字时，此时转向系统就要初始化，以此规定单次的路径，比如第几个路口转向，转向方向
/// @param Turn_Time 第几个路口转向 
/// @param Turn_Strat 左转还是右转
void Turn_Init(uint8_t Turn_Time,uint8_t Turn_Strat)
{
                   
}

/// @brief 转向检查：研究转向状态的细节
void Turn_Check()
{
    static uint8_t Turn_Times = Turn_Times_2;        // 转向次数
    static uint8_t Time_Strat = Time_1_Enable_Left; // 转向情况：转不转，转哪边
    // 转向要有两个前提：1.转向次数大于0  2.本次路口可以转向
    while ((UART_DATA_TYPE==2)&&(Turn_Times>0))     // 只要转向机会大于0，就转向，转向后机会减1
    {
        Turn_Control(Time_Strat);
    }
    Turn_Times--;

}

// 定义转向使能，控制是否转向
uint8_t Turn_Flag = 0;

void Turn_Control(uint8_t orientation)
{

    if(!Turn_Flag)  // 如果没打开转向，就不转
    {
        return;
    }

    // 定义转向缓冲
    static uint8_t Turn_buffer = 0;
    if(!Turn_buffer)
    {
        Motor_Load(0,0);
        AllStop
        Turn_buffer = 1;
    }

    if(orientation==right)
    {
        Motor_Load(-10500,10500);
    }
    else if(orientation==left)
    {
        Motor_Load(12500,-12500);
    }
    else
    {
        return;
    }
    

}


