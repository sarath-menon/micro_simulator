#include "quadcopter.h"

/// Represents the quadcopter
void Quadcopter::euler_step(const float dt) {
  frame.euler_step(dt);
  set_position(frame.position());
  set_orientation(frame.orientation());
}
