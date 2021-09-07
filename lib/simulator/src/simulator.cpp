#include "simulator.h"

void Simulator::set_parameter(std::string path) {

  // Load simulation properties from yaml file
  YAML::Node yaml_file =
      YAML::LoadFile("project/parameters/simulation_parameters.yaml");

  dt_ = yaml_file["dt"].as<float>();

  euler_steps_ = yaml_file["euler_steps"].as<float>();

  pose_pub_flag_ = yaml_file["pose_pub"].as<bool>();
}