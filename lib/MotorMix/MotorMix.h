#ifndef MIX
#define MIX
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
    Mixer(Control control);
    void begin(float length, float width);
    const bool& get_saturation() const { return saturation_; }
    const std::array<float, 4>& get_output() const { return output_; }
    bool get_init() const { return init_; }
    void steer();
private:
    std::array<std::array<float, 4>, 3> mix_;
    std::array<float, 4> output_;
    bool saturation_;
    bool init_;
    Control control_;
};

#endif