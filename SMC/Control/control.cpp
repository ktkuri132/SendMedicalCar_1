#include <control.hpp>

extern uint8_t UART_DATA_TYPE;


/****************************控制基类******************** */
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

/**********************************直线控制类********************************* */

Line_Control::Line_Control()
{
    Obj_ForPIDLineControl = new class PID_Control;
    Obj_ForPIDLineControl->kp = 0.1;
    Obj_ForPIDLineControl->ki = 0.1;
    Obj_ForPIDLineControl->kd = 0.1;
}

Line_Control::~Line_Control()
{
    delete Obj_ForPIDLineControl;
}


/***************************************转向控制类****************************** */


Turn_Control::Turn_Control()
{
    Obj_ForPIDTurnControl = new class PID_Control;
    Obj_ForPIDTurnControl->kp = 0.1;
    Obj_ForPIDTurnControl->ki = 0.1;
    Obj_ForPIDTurnControl->kd = 0.1;
}

Turn_Control::~Turn_Control()
{
    delete Obj_ForTurnControl;
}