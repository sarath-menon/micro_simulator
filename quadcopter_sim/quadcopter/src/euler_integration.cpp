#include "quadcopter.h"

/// Represents the quadcopter
void Quadcopter::euler_step(const float dt) {
  frame.euler_step(dt);
  set_position(frame.position());
  set_velocity(frame.velocity());
  set_orientation(frame.orientation());
  set_angular_velocity(frame.angular_velocity());
}
