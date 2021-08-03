#pragma once

#include "utils.h"
#include <matrix/math.hpp>

/// Represents a Rigid body
class RigidBody {
private:
public:
  /// Loads the rigid body properties from the yaml file
  // RigidBody(std::string parameter_path);
  // RigidBody(){};

  // Variables
protected:
  // Mass and Inertia Matrix ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Mass of the rigid body
  float mass_;

  // Inertia matrix of the rigid body

  matrix::SquareMatrix<float, 3> inertia_matrix_;
  // Position and Orietnation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Position of the rigid body
  matrix::Vector<float, 3> position_;

  /// Orientation of the rigid body as Quaternion (q_0, q_x, q_y, q_z)

  matrix::Quatf orientation_;

  // Time derivatives of Position and Orientnation
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Velocity of the rigid body
  matrix::Vector<float, 3> velocity_;

  // /// Time derivative of rigid body position
  // Eigen::Vector3d position_dot_;

  /// Time derivative of quaternion representing rigid body orientation
  matrix::Vector<float, 4> orientation_dot_;

  /// Angular velocity of the rigid body
  matrix::Vector<float, 3> angular_velocity_;

public:
  /// Have to be defined in the child class
  virtual void Dynamics(){};

  // Getter Functions
public:
  /// Getter function
  const float &mass() const { return mass_; }
  /// Getter function
  const matrix::SquareMatrix<float, 3> &inertia_matrix() const {
    return inertia_matrix_;
  }
  /// Getter function
  const matrix::Vector<float, 3> &position() const { return position_; }
  /// Getter function
  const matrix::Quatf &orientation() const { return orientation_; }
  /// Getter function
  const matrix::Vector<float, 3> &velocity() const { return velocity_; }
  /// Getter function
  const matrix::Vector<float, 4> &orientation_dot() const {
    return orientation_dot_;
  }
  /// Getter function
  const matrix::Vector<float, 3> &angular_velocity() const {
    return angular_velocity_;
  }

  /// Setter function
  void set_mass(float mass) { mass_ = mass; }

  void set_inertia_matrix(float data[3][3]) {
    matrix::SquareMatrix<float, 3> inertia_matrix(data);
    inertia_matrix_ = inertia_matrix;
  }
  /// Getter function
  void set_position(matrix::Vector<float, 3> position) { position_ = position; }

  /// Getter function
  matrix::Quatf orientation() { return orientation_; }

  /// Getter function
  void set_velocity(matrix::Vector<float, 3> velocity) { velocity_ = velocity; }

  /// Getter function
  void set_orientation_dot(matrix::Vector<float, 4> orientation_dot) {
    orientation_dot_ = orientation_dot;
  }

  /// Getter function
  void angular_velocity(matrix::Vector<float, 3> set_angular_velocity) {
    angular_velocity_ = set_angular_velocity;
  }
};
