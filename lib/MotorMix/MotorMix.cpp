#include"MotorMix.h"

float get_range (std::array<float, 4> list, float& min, float& max){
    min = list[0];
    max = list[0];

    for(float elem : list){
        if(elem < min){ min = elem; }
        if(elem > max){ max = elem; }
    }
    return max - min;
}

float clamp(float v, float min, float max){
    if(v < min){ return min; }
    if(v > max){ return max; }
    return v;
}

Mixer::Mixer(Control control):
output_{{0.0, 0.0, 0.0, 0.0}}, saturation_{false}, control_{control},
mix_{{
    {1.0, -1.0, 1.0, -1.0},
    {1.0, 1.0, -1.0, -1.0},
    {-1.0, 1.0, 1.0, -1.0}
}} {}

void Mixer::begin(float length, float width){
    if(length <= 0 || width <= 0){
        throw std::invalid_argument("input proper dimensions");
    }
    float m{std::max(length, width)};
    for(float& elem : mix_[PITCH]){ elem *= length / m; }
    for(float& elem : mix_[ROLL]){ elem *= width / m; }
}

void Mixer::steer() {
    for(int i = 0; i < 4; ++i){
        output_[i] = 
        control_.yaw * mix_[YAW][i] +
        control_.pitch * mix_[PITCH][i] +
        control_.roll * mix_[ROLL][i];
    }
    float output_min{0.0}, output_max{0.0}, throttle{0.0};
    float range{get_range(output_, output_min, output_max)};
    if(range < 1.0){
        throttle = clamp(control_.throttle, -output_min, 1 - output_max);
        for(float& elem : output_){
            elem += throttle;
        }
    } else{
        for(float& elem : output_){
            elem /= range;
        }
        range = get_range(output_, output_min, output_max);
        throttle = clamp(control_.throttle, -output_min, 1 - output_max);
        for(float& elem : output_){
            elem += throttle;
        }
    }
}