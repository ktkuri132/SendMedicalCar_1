#include <pico/stdio.h>
#include <pico/cyw43_arch.h>

void wifi_scan(void)
{
    cyw43_t *cyw43 = cyw43_get();
    cyw43_scan(cyw43);
}
