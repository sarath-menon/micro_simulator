#pragma once
#include "rigidbody.h"

/// Represents the quadcopter
class QuadcopterFrame : public RigidBody {

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

  // Variables for dynamics function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// velocity of rigid body
  matrix::Vector3<float> velocity_;

  /// 2nd Time derivative of rigid body position
  matrix::Vector3<float> position_ddot_;

  /// Angular acceleration of the rigid body
  matrix::Vector3<float> angular_acceleration_;

  /// Rotation matrix - body to inertial frame
  matrix::Dcmf _R_OB;

  /// No need to computer inverse of inertia matrix for each function ca;;
  matrix::SquareMatrix<float, 3> inertia_matrix_inv_;

public:
  /// Quadcopter Dynamics
  virtual void Dynamics() override;

public:
  /// Getter function
  float linear_drag_coeff() const { return linear_drag_coeff_; }

  /// Getter function
  float angular_drag_coeff() const { return angular_drag_coeff_; }

public:
  /// Setter function
  void set_linear_drag_coeff(float linear_drag_coeff) {
    linear_drag_coeff_ = linear_drag_coeff;
  }
  /// Setter function
  void set_angular_drag_coeff(float angular_drag_coeff) {
    angular_drag_coeff_ = angular_drag_coeff;
  }
};
