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

enum Angle{
    YAW = 0,
    PITCH = 1,
    ROLL = 2,
};

class Mixer{
public:
    Mixer(float length, float width, Control control);
    bool get_saturation() { return saturation_; }
    const std::array<float, 4>& get_output() const { return output_; }
    void steer();
private:
    const std::array<std::array<float, 4>, 3> mix_;
    std::array<float, 4> output_;
    bool saturation_;
    Control control_;
};

#endif