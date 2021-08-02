#pragma once

#include <matrix/math.hpp>
using namespace matrix;

/// Represents a Motor
class Motor {

public:
  /// Loads the Motor properties from the yaml file
  // Motor();

  // Variables
protected:
  // Mass and Inertia Matrix ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Mass of the Motor
  float mass_;

  /// Inertia matrix of the Motor
  matrix::SquareMatrix<float, 3> inertia_matrix_;

  // Relative Position and Orietnation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Position of the Motor
  matrix::Vector<float, 3> relative_position_;

  /// Orientation of the Motor as Quaternion (q_0, q_x, q_y, q_z)
  matrix::Quatf relative_orientation_;

  // Motor in RPM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  int speed_ = 0;

  // Other properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  // Maximum speed of the motor
  int max_speed_ = 0;

  // Minimum speed of the motor
  int min_speed_ = 0;

public:
  /// Have to be defined in the child class
  virtual void Dynamics(){};

  // Getter Functions
public:
  // /// Getter function
  // const float &mass() const { return mass_; }
  // /// Getter function
  // const Eigen::Matrix3d &inertia_matrix() const { return inertia_matrix_; }
  // /// Getter function

  // const Eigen::Vector3d &relative_position() const {
  //   return relative_position_;
  // }
  // /// Getter function
  // const Eigen::Vector4d &relative_orientation() const {
  //   return relative_orientation_;
  // }
  // /// Getter function
  // const int &speed() const { return speed_; }
  // /// Getter function
  // const int &min_speed() const { return min_speed_; }
  // /// Getter function
  // const int &max_speed() const { return max_speed_; }
};
