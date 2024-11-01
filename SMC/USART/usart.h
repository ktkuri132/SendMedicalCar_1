#ifndef __USART_H_
#define __USART_H_

#include <pico/stdlib.h>
#include <pico/types.h> 
#include <hardware/uart.h>

#ifdef __cplusplus
extern "C" {
#endif

void USART_Init();
uint8_t USART_Deal(uint8_t point_note);

#ifdef __cplusplus
}
#endif



#endif