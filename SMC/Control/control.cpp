#include <control.h>

uint32_t Medical = 1;

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


/// @brief 路径状态检查
uint32_t (*PATH_Start_Check())[2]
{
    static uint32_t Site[2];
    if(UART_DATA_TYPE==1)       // 扫到直线
    {
        // 读取坐标
        uint32_t X_Site = USART_Deal(1);
        uint32_t Y_Site = USART_Deal(2);
        return &Site;
    }
    else if(UART_DATA_TYPE==2)  // 扫到十字
    {
        // 读取左边的坐标
        uint32_t RX_Site = USART_Deal(1);
        uint32_t RY_Site = USART_Deal(2);
        return &Site;
    }
    else
    {
        Site[0] = 0;
        Site[1] = 0;
        return &Site;
    }
}