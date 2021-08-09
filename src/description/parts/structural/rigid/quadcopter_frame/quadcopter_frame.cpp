#include "quadcopter_frame.h"

// s
// Setter functions

QuadcopterFrame ::QuadcopterFrame()
{
  inertia_matrix_inv_ = inv(inertia_matrix_);
}

void QuadcopterFrame::Motorthrust_to_BodyThrustTorque(const float motor_thrusts[4])
{
  matrix::Vector<float, 4> motor_thrusts_;
  motor_thrusts_(0) = motor_thrusts[0];
  motor_thrusts_(1) = motor_thrusts[1];
  motor_thrusts_(2) = motor_thrusts[2];
  motor_thrusts_(3) = motor_thrusts[3];

  matrix::Vector<float, 4> thrust_vector_ = layout_ * motor_thrusts_;

  thrust_(0) = 0;
  thrust_(1) = 0;
  thrust_(2) = thrust_vector_(0);

  torque_(0) = thrust_vector_(1);
  torque_(1) = thrust_vector_(2);
  torque_(2) = thrust_vector_(3);
}

/// Equations of motion for a quadcopter frames
void QuadcopterFrame::Dynamics(const float motor_thrusts[4])
{
  matrix::Vector3f gravity(0, 0, 9.81);

  _R_OB = matrix::Dcm<float>(orientation_);
  // Velocity
  position_dot_ = velocity_;

  // Acceleration
  position_ddot_ = _R_OB * thrust_ + gravity;

  // Angular velocity
  orientation_dot_ = orientation_.derivative1(angular_velocity_);

  // Angular acceleration
  angular_acceleration_ =
      inertia_matrix_inv_ *
      (torque_ - angular_velocity_ - inertia_matrix_ * angular_velocity_);
}