#include <pico/stdlib.h>
#include <pico/cyw43_arch.h>

void wifi_init()
{
    cyw43_init();
    cyw43_connect("SSID", "PASSWORD");
}   

