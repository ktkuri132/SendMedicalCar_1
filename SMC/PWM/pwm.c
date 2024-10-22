#include <pwm.h>

void PWM_Init()
{
    pwm_config config = pwm_get_default_config();
    pwm_init(pwm_gpio_to_slice_num(2), &config, true);
    pwm_set_clkdiv(pwm_gpio_to_slice_num(2), 16.0f);
    pwm_set_wrap(pwm_gpio_to_slice_num(2), 1000);
    pwm_set_chan_level(pwm_gpio_to_slice_num(2), PWM_CHAN_A, 500);
    pwm_set_enabled(pwm_gpio_to_slice_num(2), true);
}