#pragma once
#include <string>
#include <yaml-cpp/yaml.h>

/// Represents the quadcopter
class Simulator {

private:
  // Euler integration timestep
  float dt_ = 0;
  // Number of numerical integration steps
  float euler_steps_ = 0;
  // Activate fastdds pose publisher
  bool pose_pub_flag_ = false;

public:
  // Loads the quadcopter properties from the yaml file
  void set_parameter(std::string path);

public:
  /// Getter function
  const float dt() const { return dt_; }
  /// Getter function
  const float euler_steps() const { return euler_steps_; }
};
