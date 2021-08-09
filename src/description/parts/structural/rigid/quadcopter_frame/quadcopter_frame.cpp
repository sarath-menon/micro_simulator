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
  thrust_vector_ = layout_ * motor_thrusts_;
}

void QuadcopterFrame::Dynamics(const float motor_thrusts[4])
{

  // Call function to get net_thrust and torque from individual propeller thrusts

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