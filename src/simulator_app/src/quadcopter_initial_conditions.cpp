#include "quadcopter.h"

/// Represents the quadcopter
void Quadcopter::set_initial_conditions() {

  // Load YAML file containing quadcopter properties
  YAML::Node yaml_file =
      YAML::LoadFile("src/simulator_app/parameters/initial_conditions.yaml");

  // Set position variables
  matrix::Vector3f intial_position;

  intial_position(0) = yaml_file["x"].as<float>();
  intial_position(1) = yaml_file["y"].as<float>();
  intial_position(2) = yaml_file["z"].as<float>();

  frame.set_position(intial_position); // [m]

  // Set orientation variables

  matrix::Quatf intial_orientation;

  intial_orientation(0) = yaml_file["q_w"].as<float>();
  intial_orientation(1) = yaml_file["q_x"].as<float>();
  intial_orientation(2) = yaml_file["q_y"].as<float>();
  intial_orientation(3) = yaml_file["q_z"].as<float>();

  frame.set_orientation(intial_orientation); // [m]
}
