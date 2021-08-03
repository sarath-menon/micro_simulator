#pragma once
#include "bldc_motor.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <matrix/math.hpp>

/// Represents the quadcopter
class Quadcopter : public RigidBody {

public:
  /// Quadcopter frame
  QuadcopterFrame frame;

  /// Quadcopter motors (4)
  BldcMotor motor[4];

  // Variables
protected:
  // Manually computed now. has to be automated later
  matrix::SquareMatrix<float, 3> inertia_matrix_q;

  // /// Orientation of the quadcopter as Rotation Matrix (R_OB)
  // Eigen::Matrix3d orientation_rotation_matrix = Eigen::Matrix3d::Zero();

  // /// Orientation of the quadcopter as Euler Angles (roll, pitch, yaw)
  // Eigen::Vector3d orientation_euler_angles = Eigen::Vector3d::Zero();

protected:
  // Varibles for the dynamics function. Alloss return by reference instead
  of
      // by value.
      const matrix::Vector<float, 3>
          gravity_vector;

  // velocity
  matrix::Vector<float, 3> position_dot_;
  // Acceleration
  matrix::Vector<float, 3> position_ddot_;
  // Quaternion derivative
  matrix::Vector<float, 3> orientation_dot;
  // Angular acceleration
  matrix::Vector<float, 3> angular_acceleration_;

public:
  /// Quadcopter Dynamics
  virtual void Dynamics();

public:
  // /// Getter function
  // float moment_arm() const { return moment_arm_; }
};
