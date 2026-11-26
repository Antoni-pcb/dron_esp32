#include"MotorMix.h"

Mixer::Mixer(float length, float width, Control control):
saturation_{false}, control_{control},
mix_y_{{1.0, -1.0, 1.0, -1.0}},
mix_p_{{1.0, 1.0, -1.0, -1.0}},
mix_r_{{-1.0, 1.0, 1.0, -1.0}} {
    if(length <= 0 || width <= 0){
        throw std::invalid_argument("input proper dimensions");
    }
    float x{ width / 2 }; float y{ length / 2 };
    float r{ sqrt(pow(length / 2, 2) + pow(width / 2, 2)) };
    for(float elem : mix_p_){ elem *= y / r; }
    for(float elem : mix_r_){ elem *= x / r; }
}