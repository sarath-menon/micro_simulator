#include "arm.h"

#include <Eigen/Dense>
#include <filesystem>
#include <yaml-cpp/yaml.h>

Arm::Arm(std::string parameter_path) : RigidBody(parameter_path) {

  YAML::Node yaml_file = YAML::LoadFile(parameter_path);
  arm_length_ = yaml_file["arm_length"].as<float>();
}

// Setter functions
