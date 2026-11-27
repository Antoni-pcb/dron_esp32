#include"MotorMix.h"

float get_range (std::array<float, 4> list, float& min, float& max){
  min = list[0];
  max = list[0];

  for(float elem : list){
    if(elem < min){
      min = elem;
    }
    if(elem > max){
      max = elem;
    }
  }
  return max - min;
}

float clamp(float v, float min, float max){
  if(v < min){
    return min;
  }
  if(v > max){
    return max;
  }
  else{
    return v;
  }
}

Mixer::Mixer(float length, float width, Control control):
output_{{0.0, 0.0, 0.0, 0.0}}, saturation_{false}, control_{control},
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