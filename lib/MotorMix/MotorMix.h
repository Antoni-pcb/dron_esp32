#ifndef MIX
#define MIX
#include<cmath>
#include<array>

struct Control{
    const float& yaw;
    const float& pitch;
    const float& roll;
    const float& throttle; 
};

class Mixer{
public:
    Mixer(float length, float width, Control control);

private:
    const std::array<float, 4> mix_y_;
    const std::array<float, 4> mix_r_;
    const std::array<float, 4> mix_p_;
    bool saturation_;
    Control control_;
};

#endif