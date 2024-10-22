#include <main.h>

int main()
{
    stdio_init_all();
    USART_Init();
    OLED_Init();
    Contorl_Init();
    while (1) 
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}   