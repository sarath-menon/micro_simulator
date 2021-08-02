#pragma once
#include "motor.h"

/// Represents the swinging arm
class BldcMotor : public Motor {

private:
public:
  /// Loads the arm properties from the yaml file
  // BldcMotor(std::string parameter_path);

  // By default, everything is initialized to zero
protected:
  // Position and Orientation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Time constant of the bldc motor.
  float time_constant_ = 0;

public:
  /// Arm Dynamics
  float Dynamics(float thrust_desired, float thrust_current);

public:
  /// Getter function
  float time_constant() const { return time_constant_; }
};