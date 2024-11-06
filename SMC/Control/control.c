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

/// @brief 巡线控制
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


void Turn_Control()
{
    #ifdef __PID

    static struct PID pid_left = {-20,0,0,500,3500,PID_Control};
    static struct PID pid_right ={20,0,0,500,3500,PID_Control};

    uint16_t temp_current = USART_Deal(5);        
    #endif

    static uint8_t Turn_Flag = 0;
    // 先不读坐标，开环跑
    if(!Turn_Flag)
    {
        Motor_Load(-5000,-5000);
        AllStop
        Turn_Flag = 1;
    }
    Motor_Load(4500,-500);
    
    

}


