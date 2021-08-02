#include "quadcopter_frame.h"
#include <yaml-cpp/yaml.h>

QuadcopterFrame::QuadcopterFrame(std::string parameter_path)
    : RigidBody(parameter_path) {
  YAML::Node yaml_file = YAML::LoadFile(parameter_path);

  moment_arm_ = yaml_file["moment_arm"].as<float>();
}

// Setter functions
