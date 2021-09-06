#pragma once
#include "rigidbody.h"

/// Represents the quadcopter
class QuadcopterFrame : public RigidBody {

public:
  /// Loads the quadcopter properties from the yaml file
  QuadcopterFrame();

  // Variables
protected:
  // Geometrical Properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Linear drag coefficient
  matrix::Vector3f linear_drag_coeff_;

  // /// Angular drag coefficient
  matrix::Vector3f angular_drag_coeff_;

  /// Distance from the quadcopter's center of mass to the propellor
  float moment_arm_ = 0;

  /// Layout matrix
  matrix::SquareMatrix<float, 4> layout_;

  // Variables for dynamics function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// velocity of rigid body
  matrix::Vector3<float> velocity_;

  /// 2nd Time derivative of rigid body position
  matrix::Vector3<float> position_ddot_;

  /// Angular acceleration of the rigid body
  matrix::Vector3<float> angular_acceleration_;

  /// Rotation matrix - body to inertial frame
  matrix::Dcmf _R_OB;

  /// No need to computer inverse of inertia matrix in each function call
  matrix::SquareMatrix<float, 3> inertia_matrix_inv_;

  // Constants
private:
  // Acceleration due to gravity
  const matrix::Vector3f gravity_acc = matrix::Vector3f(0, 0, 9.81);

public:
  /// Quadcopter Dynamics
  void dynamics(const matrix::Vector3<float> body_thrust,
                const matrix::Vector3<float> body_torque);

public:
  /// Getter function
  float linear_drag_coeff_x() const { return linear_drag_coeff_(0); }
  float linear_drag_coeff_y() const { return linear_drag_coeff_(1); }
  float linear_drag_coeff_z() const { return linear_drag_coeff_(2); }

  /// Getter function
  float angular_drag_coeff_x() const { return angular_drag_coeff_(0); }
  float angular_drag_coeff_y() const { return angular_drag_coeff_(1); }
  float angular_drag_coeff_z() const { return angular_drag_coeff_(2); }

  /// Getter function
  float moment_arm() const { return moment_arm_; }

  /// Getter function
  matrix::Vector3<float> position_ddot() const { return position_ddot_; }

  /// Getter function
  matrix::Vector3<float> angular_acceleration() const {
    return angular_acceleration_;
  }

public:
  void set_linear_drag_coeff(float data[3]) {
    matrix::Vector3f linear_drag_coeff(data);
    linear_drag_coeff_ = linear_drag_coeff;
  }

  void set_angular_drag_coeff(float data[3]) {
    matrix::Vector3f angular_drag_coeff(data);
    angular_drag_coeff_ = angular_drag_coeff;
  }

  void set_moment_arm(float moment_arm) { moment_arm_ = moment_arm; }
};
