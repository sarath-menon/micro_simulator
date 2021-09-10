#include "quadcopter_frame.h"
#include <iostream>

// Setter functions

QuadcopterFrame ::QuadcopterFrame() {
  inertia_matrix_inv_ = inv(inertia_matrix_);
}

/// Equations of motion for a quadcopter frames
void QuadcopterFrame::dynamics(const matrix::Vector3<float> body_thrust,
                               const matrix::Vector3<float> body_torque,
                               const float dt) {

  // Compute body to inertial frame transformation
  _R_OB = matrix::Dcm<float>(orientation_);

  // Acceleration
  acceleration_ =
      (_R_OB * body_thrust) - gravity_acc - (linear_drag_coeff_ * velocity_);

  // Angular velocity
  orientation_dot_ = matrix::Quatf::expq(0.5f * dt * angular_velocity_);

  // Angular acceleration
  angular_acceleration_ =
      inertia_matrix_inv_ *
      (body_torque -
       angular_velocity_.cross(inertia_matrix_ * angular_velocity_) -
       (angular_drag_coeff_ * angular_velocity_));

  // Plot variables for debugging
  // std::cout << "Acceleration:" << acceleration_(0) << '\t' <<
  // acceleration_(1)
  //           << '\t' << acceleration_(2) << '\n';

  std::cout << "Angular acceleration:" << angular_acceleration_(0) << '\t'
            << angular_acceleration_(1) << '\t' << angular_acceleration_(2)
            << '\n';

  // std::cout << "Body thrust:" << body_thrust(0) << '\t' << body_thrust(1)
  //           << '\t' << body_thrust(2) << '\n';

  const matrix::Vector3<float> air_drag = linear_drag_coeff_ * velocity_;
  std::cout << "Drag term:" << air_drag(0) << '\t' << air_drag(1) << '\t'
            << air_drag(2) << '\t' << '\n';
}

/// Represents the quadcopter
void QuadcopterFrame::euler_step(const float dt) {

  // Translation
  position_ = position_ + velocity_ * dt;
  velocity_ = velocity_ + acceleration_ * dt;

  // Rotation
  orientation_ = orientation_ * orientation_dot_;
  // Is normalization required here ?
  orientation_.normalize();

  angular_velocity_ = angular_velocity_ + angular_acceleration_ * dt;

  // Plot variables for debugging
  std::cout << "Position:" << position_(0) << '\t' << position_(1) << '\t'
            << position_(2) << '\n';
  std::cout << "Velocity:" << velocity_(0) << '\t' << velocity_(1) << '\t'
            << velocity_(2) << '\n';
  std::cout << "Orientation:" << orientation_(0) << '\t' << orientation_(1)
            << '\t' << orientation_(2) << '\t' << orientation_(3) << '\n';
  std::cout << "Angular Velocity:" << angular_velocity_(0) << '\t'
            << angular_velocity_(1) << '\t' << angular_velocity_(2) << '\n';
}