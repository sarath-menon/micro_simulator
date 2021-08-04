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

  // Variables for dynamics function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Thrust generated by the motor propellor pair
  float thrust_dot;

public:
  /// Arm Dynamics
  virtual void Dynamics() override;

public:
  /// Getter function
  float time_constant() const { return time_constant_; }

  /// Setter function
  void set_time_constant(float time_constant) {
    time_constant_ = time_constant;
  }
};