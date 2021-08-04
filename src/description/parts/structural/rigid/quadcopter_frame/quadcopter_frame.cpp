#include "quadcopter_frame.h"

// s
// Setter functions

QuadcopterFrame ::QuadcopterFrame() {
  inertia_matrix_inv_ = inv(inertia_matrix_);
}

void QuadcopterFrame::Dynamics() {

  matrix::Vector3f thrust;
  matrix::Vector3f torque;
  matrix::Vector3f gravity(0, 0, 9.81);

  /////////

  _R_OB = matrix::Dcm<float>(orientation_);
  // Velocity
  position_dot_ = velocity_;

  // Acceleration
  position_ddot_ = _R_OB * thrust + gravity;

  // Angular velocity
  orientation_dot_ = orientation_.derivative1(angular_velocity_);

  // Angular acceleration
  angular_acceleration_ =
      inertia_matrix_inv_ *
      (torque - angular_velocity_ - inertia_matrix_ * angular_velocity_);
}