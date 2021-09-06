#include "quadcopter.h"

// /// Represents the quadcopter
// void Quadcopter::euler_step() {
//   // Declare dt for now
//   constexpr static float dt = 0.01;

//   // Translation
//   position_ = position_ + position_dot_ * dt;
//   position_dot_ = position_dot_ + position_ddot_ * dt;

//   // Rotation
//   orientation_ = orientation_ * orientation_dot_;
//   orientation_.normalize();
//   orientation_dot_ = orientation_dot_ + orientation_ddot_ * dt;
// }