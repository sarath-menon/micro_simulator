#pragma once
#include "rigidbody.h"

/// Represents the quadcopter
class Quadcopter : public RigidBody {

private:
public:
  /// Loads the quadcopter properties from the yaml file
  Quadcopter(std::string parameter_path);

  // Variables
protected:
  // /// Orientation of the quadcopter as Rotation Matrix (R_OB)
  // Eigen::Matrix3d orientation_rotation_matrix = Eigen::Matrix3d::Zero();

  // /// Orientation of the quadcopter as Euler Angles (roll, pitch, yaw)
  // Eigen::Vector3d orientation_euler_angles = Eigen::Vector3d::Zero();

  // Other Properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Constant that relates the thrust produced by a propeller to the square of
  // the square of its angular velocity
  float thrust_speed_ratio_ = 0;

  /// Constant that relates the torque produced by a propeller with respect to
  // the quadcopter center of gravity, to the square of the angular velocity
  float torque_speed_ratio_ = 0;

public:
  /// Quadcopter Dynamics
  virtual void Dynamics() override;

public:
  /// Getter function
  float moment_arm() const { return moment_arm_; }
  /// Getter function
  float thrust_speed_ratio() const { return thrust_speed_ratio_; }
  /// Getter function
  float torque_speed_ratio() const { return torque_speed_ratio_; }
};
