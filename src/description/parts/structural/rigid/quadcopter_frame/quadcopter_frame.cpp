#include "quadcopter_frame.h"

// Setter functions

QuadcopterFrame ::QuadcopterFrame() {
  inertia_matrix_inv_ = inv(inertia_matrix_);
}

// void QuadcopterFrame::Motorthrust_to_BodyThrustTorque(
//     const float motor_thrusts[4]) {
//   matrix::Vector<float, 4> motor_thrusts_;
//   motor_thrusts_(0) = motor_thrusts[0];
//   motor_thrusts_(1) = motor_thrusts[1];
//   motor_thrusts_(2) = motor_thrusts[2];
//   motor_thrusts_(3) = motor_thrusts[3];

//   matrix::Vector<float, 4> thrust_vector_ = layout_ * motor_thrusts_;

//   thrust_(0) = 0;
//   thrust_(1) = 0;
//   thrust_(2) = thrust_vector_(0);

//   torque_(0) = thrust_vector_(1);
//   torque_(1) = thrust_vector_(2);
//   torque_(2) = thrust_vector_(3);
// }

/// Equations of motion for a quadcopter frames
void QuadcopterFrame::dynamics(const matrix::Vector3<float> body_thrust,
                               const matrix::Vector3<float> body_torque) {

  // Declare for now
  constexpr static float dt = 0.01;

  // Compute body to inertial frame transformation
  _R_OB = matrix::Dcm<float>(orientation_);

  // Velocity
  position_dot_ = velocity_;

  // Acceleration
  position_ddot_ =
      (_R_OB * body_thrust) - gravity_acc - (velocity_ * linear_drag_coeff_);

  // Angular velocity
  orientation_dot_ = matrix::Quatf::expq(0.5f * dt * angular_velocity_);

  // Angular acceleration
  angular_acceleration_ =
      inertia_matrix_inv_ *
      (body_torque -
       angular_velocity_.cross(inertia_matrix_ * angular_velocity_) -
       (angular_velocity_ * angular_drag_coeff_));
}
