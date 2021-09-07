#pragma once
#include <math.h>

static float limit(float val, const float max, const float min) {
  val = fmax(val, min);
  val = fmin(val, max);
  return val;
}
