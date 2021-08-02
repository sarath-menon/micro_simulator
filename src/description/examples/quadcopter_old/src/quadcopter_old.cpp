#include "quadcopter.h"
#include <yaml-cpp/yaml.h>

Quadcopter::Quadcopter(std::string parameter_path) : RigidBody(parameter_path) {
  YAML::Node yaml_file = YAML::LoadFile(parameter_path);

  moment_arm_ = yaml_file["moment_arm"].as<float>();
  thrust_speed_ratio_ = yaml_file["thrust_speed_ratio"].as<float>();
  torque_speed_ratio_ = yaml_file["torque_speed_ratio"].as<float>();
}

void Quadcopter::Dynamics(){

    // Get state variables

    // Apply Equations of Motion
};

// Setter functions
