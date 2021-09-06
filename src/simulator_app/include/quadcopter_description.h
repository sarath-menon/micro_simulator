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
  /// Loads the quadcopter properties from the yaml file
  void set_parameters();

protected:
  // Geometrical Properties ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Linear drag coefficient
  // std::string which_numerical_integrator;

  /// Numerical Integrators
};
