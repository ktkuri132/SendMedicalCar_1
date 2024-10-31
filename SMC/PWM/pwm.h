#ifndef __PWM_H_
#define __PWM_H_

#include <pico/stdlib.h>
#include <hardware/pwm.h>
#include <sys.h>

void PWM_Init();
void Encoder_Port_Init();
void PWM_SetDuty(uint8_t motor, uint16_t duty);
void encoder_interput_callback();
bool encoder_GetSign();



//PWM�ӿ�
#define PWMA 22
#define PWMB 20

//����ʹ�ܽӿ�
#define AIN_2 26
#define AIN_1 16
#define BIN_1 17
#define BIN_2 21

//PWM���νӿ�
#define MotorLeft PWMA
#define MotorRight PWMB

//�������
#define LeftForward {gpio_put(AIN_1,1);gpio_put(AIN_2,0);}
#define LeftBackward {gpio_put(AIN_1,0);gpio_put(AIN_2,1);}
#define RightForward {gpio_put(BIN_1,0);gpio_put(BIN_2,1);}
#define RightBackward {gpio_put(BIN_1,1);gpio_put(BIN_2,0);}
#define AllForward {LeftForward;RightForward;}
#define AllBackward {LeftBackward;RightBackward;}
#define AllStop {gpio_put(AIN_1,0);gpio_put(AIN_2,0);gpio_put(BIN_1,0);gpio_put(BIN_2,0);}

//�������ӿ�
#define ENCODER_A1 18
#define ENCODER_A2 19
#define ENCODER_B1 29
#define ENCODER_B2 30

/*

����С��1��PWM����

�����������

*/




#endif // !__PWM_H_
