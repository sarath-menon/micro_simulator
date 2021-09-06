#pragma once
#include "motor_propeller_pair.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"
#include <matrix/math.hpp>
#include <yaml-cpp/yaml.h>

/// Represents the quadcopter
class QuadcopterDescription : public RigidBody {

private:
  // Load YAML file containing quadcopter properties
  YAML::Node yaml_file =
      YAML::LoadFile("src/simulator_app/parameters/quadcopter.yaml");

public:
  // Load parts from the library
  QuadcopterFrame frame;
  MotorPropellerPair motor[4];

public:
  float roll_pitch_max_ = 0;

public:
  /// Loads the quadcopter properties from the yaml file
  void set_parameters();

public:
  /// Getter function
  const float roll_pitch_max() const { return roll_pitch_max_; }

public:
  /// Setter function
  void set_roll_pitch_max(float roll_pitch_max) {
    roll_pitch_max_ = roll_pitch_max;
  }

protected:
  // Geometrical Properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Linear drag coefficient
  // std::string which_numerical_integrator;

  /// Numerical Integrators
};
