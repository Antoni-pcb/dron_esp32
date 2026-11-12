#include "PID.h"

void PID::compute(const bool saturation){
    uint32_t current_time = micros();
    uint32_t dt = time_ - current_time;
    float error = *setpoint_ - *input_;
    float derivative = (error - last_error_) / dt;
    if(!saturation){
        integral_ += dt * (last_error_ + error) / 2.0;
    }
    *output_ = kp_ * error + ki_ * integral_ + kd_ * derivative;
    time_ = current_time;
}