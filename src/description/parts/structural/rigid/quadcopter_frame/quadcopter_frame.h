#pragma once
#include "rigidbody.h"

/// Represents the quadcopter
class QuadcopterFrame : public RigidBody {

private:
public:
  /// Loads the quadcopter properties from the yaml file
  QuadcopterFrame(std::string parameter_path);

  // Variables
protected:
  // /// Orientation of the quadcopter as Rotation Matrix (R_OB)
  // Eigen::Matrix3d orientation_rotation_matrix = Eigen::Matrix3d::Zero();

  // /// Orientation of the quadcopter as Euler Angles (roll, pitch, yaw)
  // Eigen::Vector3d orientation_euler_angles = Eigen::Vector3d::Zero();

  // Geometrical Properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Distance from the quadcopter's center of mass to the propellor
  float moment_arm_ = 0;

public:
  /// Quadcopter Dynamics
  virtual void Dynamics(){};

public:
  /// Getter function
  float moment_arm() const { return moment_arm_; }
};
