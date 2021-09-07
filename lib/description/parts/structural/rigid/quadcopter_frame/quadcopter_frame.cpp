#include "quadcopter_frame.h"

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
}