#ifndef __PID_
#define __PID_

#ifdef __cplusplus


class PID
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
    int pid_test();
    PID(/* args */);
    ~PID();
};


#endif

#endif