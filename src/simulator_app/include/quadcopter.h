#pragma once
#include "motor_propeller_pair.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"
#include <matrix/math.hpp>
#include <yaml-cpp/yaml.h>

/// Represents the quadcopter
class Quadcopter : public RigidBody {

public:
  // Load parts from the library
  QuadcopterFrame frame;
  MotorPropellerPair motor[4];

  // Private variables
private:
  float roll_pitch_max_ = 0;

  // Public function
public:
  /// Loads the quadcopter properties from the yaml file
  void set_parameters();
  // Set initial conditions of the quadcopter
  void set_initial_conditions();
  // Read sensor values
  void sensor_read();

public:
  /// Getter function
  const float roll_pitch_max() const { return roll_pitch_max_; }

public:
  /// Setter function
  void set_roll_pitch_max(float roll_pitch_max) {
    roll_pitch_max_ = roll_pitch_max;
  }
};
