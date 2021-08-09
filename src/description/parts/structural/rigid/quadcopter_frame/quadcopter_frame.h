#pragma once
#include "rigidbody.h"

/// Represents the quadcopter
class QuadcopterFrame : public RigidBody
{

private:
public:
  /// Loads the quadcopter properties from the yaml file
  QuadcopterFrame();

  // Variables
protected:
  // Geometrical Properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Linear drag coefficient
  float linear_drag_coeff_ = 0;

  /// Angular drag coefficient
  float angular_drag_coeff_ = 0;

  /// Distance from the quadcopter's center of mass to the propellor
  float moment_arm_ = 0;

  /// Layout matrix
  matrix::SquareMatrix<float, 4> layout_;

  matrix::Vector3f thrust_;
  matrix::Vector3f torque_;

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

public:
  /// Converts individual motor thrusts to net body thrust and torues about x,y,x, axes
  void Motorthrust_to_BodyThrustTorque(const float motor_thrusts[4]);

  /// Quadcopter Dynamics
  void Dynamics(const float motor_thrusts[4]);

public:
  /// Getter function
  float linear_drag_coeff() const { return linear_drag_coeff_; }

  /// Getter function
  float angular_drag_coeff() const { return angular_drag_coeff_; }

  /// Getter function
  float moment_arm() const { return moment_arm_; }

  /// Getter function
  matrix::Vector3<float> position_ddot() const { return position_ddot_; }

  /// Getter function
  matrix::Vector3<float> angular_acceleration() const { return angular_acceleration_; }

public:
  /// Setter function
  void set_linear_drag_coeff(float linear_drag_coeff)
  {
    linear_drag_coeff_ = linear_drag_coeff;
  }
  /// Setter function
  void set_angular_drag_coeff(float angular_drag_coeff)
  {
    angular_drag_coeff_ = angular_drag_coeff;
  }

  void set_moment_arm(float moment_arm)
  {
    angular_drag_coeff_ = moment_arm;
  }
};
