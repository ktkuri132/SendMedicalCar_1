#include <main.h>

//这里验证一下是否能够正常调用
extern struct PID pid_test;

int main()
{
    stdio_init_all();
    USART_Init();
    OLED_Init();
    Control_Init();
    Control_task_Init();
    while (1) 
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}   