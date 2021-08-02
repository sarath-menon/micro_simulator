#include "bldc_motor.h"

#include <Eigen/Dense>
#include <filesystem>
#include <yaml-cpp/yaml.h>

BldcMotor::BldcMotor(std::string parameter_path) : Motor(parameter_path) {

  YAML::Node yaml_file = YAML::LoadFile(parameter_path);
  time_constant_ = yaml_file["time_constant"].as<float>();
}

float BldcMotor::Dynamics(float thrust_desired, float thrust_current) {
  float thrust_dot = (1 / time_constant_) * (thrust_desired - thrust_current);
  return thrust_dot;
}

// Setter functions
