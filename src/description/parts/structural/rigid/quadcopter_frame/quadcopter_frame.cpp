#include "quadcopter_frame.h"

// s
// Setter functions

void QuadcopterFrame::Dynamics() {

  matrix::Vector3f thrust;
  matrix::Vector3f torque;
  matrix::Vector3f gravity(0, 0, 9.81);

  _R_OB = matrix::Dcm<float>(orientation_);
  // Velocity
  position_dot_ = velocity_;

  // Acceleration
  position_ddot_ = _R_OB * thrust + gravity;

  //   // Angular velocity
  //   orientation_dot_ =
  //       quaternion_time_derivative(orientation_, angular_velocity_);

  //   // Angular acceleration
  //   angular_acceleration_ =
  //       inertia_matrix_q.inverse() * (torque_vector - angular_velocity_ -
  //                                     inertia_matrix_q * angular_velocity_);
}