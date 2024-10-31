#ifndef __PID_
#define __PID_

#ifdef __cplusplus


class __PID
{
private:
    /* data */
    float error;
    float error_last;

    float target;
    float feedback;

    float integral;
    float derivative;
public:
    float kp;
    float ki;
    float kd;
    int __pid_test();
    __PID(/* args */);
    ~__PID();
};


#endif

#endif