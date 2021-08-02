#include "softbody.h"

#include "utils.h"
#include <yaml-cpp/yaml.h>

SoftBody::SoftBody(std::string parameter_path) {
  YAML::Node yaml_file = YAML::LoadFile(parameter_path);

  mass_ = yaml_file["mass"].as<float>(); // [kg]
  inertia_matrix_ = yaml_to_eigen_matrix3d(yaml_file, "inertia_matrix");
}

// Setter functions
