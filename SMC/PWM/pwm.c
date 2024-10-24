#include <pwm.h>

uint16_t wrap = 12500;

void PWM_Init()
{
    gpio_init(PWMA);
    gpio_init(PWMB);

    gpio_set_function(PWMA, GPIO_FUNC_PWM);
    gpio_set_function(PWMB, GPIO_FUNC_PWM);

    uint slice_num_1 = pwm_gpio_to_slice_num(PWMA);
    uint slice_num_2 = pwm_gpio_to_slice_num(PWMB);

    pwm_set_wrap(slice_num_1, 12500-1);
    pwm_set_wrap(slice_num_2, 12500-1);

    pwm_set_chan_level(slice_num_1,PWM_CHAN_A,wrap/2);
    pwm_set_chan_level(slice_num_2,PWM_CHAN_A,wrap/2);

    /* 输出使能  */
    pwm_set_enabled(slice_num_1,true);
    pwm_set_enabled(slice_num_2,true);

    gpio_set_dir(PWMA, GPIO_OUT);
    gpio_set_dir(PWMB, GPIO_OUT);

    gpio_init(AIN_1);
    gpio_init(AIN_2);
    gpio_init(BIN_1);
    gpio_init(BIN_2);

    gpio_set_dir(AIN_1, GPIO_OUT);
    gpio_set_dir(AIN_2, GPIO_OUT);
    gpio_set_dir(BIN_1, GPIO_OUT);
    gpio_set_dir(BIN_2, GPIO_OUT);

    gpio_put(AIN_1,1);
    gpio_put(AIN_2,0);
    gpio_put(BIN_1,0);
    gpio_put(BIN_2,1);

}

void PWM_SetDuty(uint8_t motor, uint16_t duty)
{
    uint slice_num = pwm_gpio_to_slice_num(motor);
    pwm_set_chan_level(slice_num,PWM_CHAN_A,duty);
}

//编码器接口初始化
void ENcoder_Init()
{
    gpio_init(ENCODER_A1);
    gpio_init(ENCODER_A2);
    gpio_init(ENCODER_B1);
    gpio_init(ENCODER_B2);

    gpio_set_dir(ENCODER_A1, GPIO_IN);
    gpio_set_dir(ENCODER_A2, GPIO_IN);
    gpio_set_dir(ENCODER_B1, GPIO_IN);
    gpio_set_dir(ENCODER_B2, GPIO_IN);

    gpio_pull_up(ENCODER_A1);
    gpio_pull_up(ENCODER_A2);
    gpio_pull_up(ENCODER_B1);
    gpio_pull_up(ENCODER_B2);

}

uint32_t   encode1_count = 0;
uint32_t   encode2_count = 0;
uint32_t    encode_1_speed = 0;
uint32_t    encode_2_speed = 0;

//读取编码器的值
void encoder_interput_callback()
{
    static bool last_A1 = false;
    static bool last_A2 = false;

    bool current_A1 = gpio_get(ENCODER_A1);
    bool current_A2 = gpio_get(ENCODER_A2);

    if (current_A1 != last_A1) 
    {
        encode1_count++;
    }

    if (current_A2 != last_A2) 
    {
        encode2_count++;
    }

    last_A1 = current_A1;
    last_A2 = current_A2;
}

bool encoder_timer_callback()
{
    encode_1_speed = encode1_count;
    encode_2_speed = encode2_count;

    encode1_count = 0;
    encode2_count = 0;
    return true;

}