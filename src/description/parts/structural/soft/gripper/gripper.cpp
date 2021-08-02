#include "gripper.h"
#include <yaml-cpp/yaml.h>

Gripper::Gripper(std::string parameter_path) : SoftBody(parameter_path) {

  YAML::Node yaml_file = YAML::LoadFile(parameter_path);
}

// Setter functions
