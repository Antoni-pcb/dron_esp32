#include"MotorMix.h"

Mixer::Mixer(float length, float width, Control control):
saturation_{false}, control_{control}, motor_pins_{{13, 18, 19, 23}},
mix_{{
    {1.0, -1.0, 1.0, -1.0},
    {1.0, 1.0, -1.0, -1.0},
    {-1.0, 1.0, 1.0, -1.0}
}} {
    if(length <= 0 || width <= 0){
        throw std::invalid_argument("input proper dimensions");
    }
    float m{std::max(length, width)};
    for(float elem : mix_[PITCH]){ elem *= length / m; }
    for(float elem : mix_[ROLL]){ elem *= width / m; }
}