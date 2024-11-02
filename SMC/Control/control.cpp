#include <control.hpp>

extern uint8_t UART_DATA_TYPE;


//****************************控制基类*********************************
/// @brief 控制系统初始化
Control::Control()
{   
    Obj_ForLineControl = new Line_Control;
    Obj_ForTurnControl = new Turn_Control;
}

Control::~Control()
{
    delete Obj_ForLineControl;
    delete Obj_ForTurnControl;
}

/// @brief 路径状态检查
uint32_t (*Control::PATH_Start_Check())[3]
{
    static uint32_t Site[3];
    if(UART_DATA_TYPE==1)
    {

    }
    else if(UART_DATA_TYPE==2)
    {

    }
    else if(UART_DATA_TYPE==5)
    {

    }
    Site[0] = UART_DATA_TYPE;
    Site[1] = USART_Deal(1);
    Site[2] = USART_Deal(2);
    return &Site;
}

//**********************************直线控制类********************************* */

Line_Control::Line_Control()
{
    // 设置目标值
    PID_Control::target = Target_X_Site;

    // 设置PID参数
    PID_Control::kp = 500;
    PID_Control::ki = 0;
    PID_Control::kd = 120;

    // 设置输出限幅，积分限幅
    PID_Control::max_Output = 1000;
    PID_Control::max_integral = 1000;
}

Line_Control::~Line_Control()
{
    
}


//***************************************转向控制类****************************** */


Turn_Control::Turn_Control()
{
   
}

Turn_Control::~Turn_Control()
{
    
}