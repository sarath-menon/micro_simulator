#pragma once
#include <math.h>

constexpr static float limit(float val, const float max, const float min) {
  if (val > max)
    val = max;
  else if (val < min)
    val = min;
  return val;
}
