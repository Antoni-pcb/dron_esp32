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
    void set_motor_pins(std::array<int, 4> pins) { motor_pins_ = pins; }
    bool get_saturation() { return saturation_; }
    void steer();
private:
    const std::array<std::array<float, 4>, 3> mix_;
    std::array<int, 4> motor_pins_;
    bool saturation_;
    Control control_;
};

#endif