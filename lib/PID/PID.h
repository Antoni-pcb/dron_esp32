#ifndef PID_
#define PID_
#include<Arduino.h>

class PID{
public:
    PID(float* input, float* output, float* setpoint): 
        input_{input}, output_{output}, setpoint_{setpoint}, kp_{0.0}, ki_{0.0}, kd_{0.0}, last_error_{0.0}, integral_{0.0}
        { time_ = micros(); }
    void set_gains(float kp, float ki, float kd){ kp_ = kp; ki_ = ki; kd_ = kd; }
    void compute(const bool saturation=false);
private:
    static uint32_t time_;
    const float* const input_;
    const float* const setpoint_;
    float* const output_;
    float kp_;
    float ki_;
    float kd_;
    float last_error_;
    float integral_;
};

#endif