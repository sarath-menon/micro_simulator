#pragma once
#include <Eigen/Dense>
#include <iostream>

#include "arm.h"
#include "gripper.h"
#include "quadcopter.h"

/**
 * @brief Represents the swinging arm
 *
 * @param path_to_parameters Relative path to the parameters file
 * ### Example
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
 * RigidBody Arm("arm_parameters.yaml");
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */

/// Represents a Raptor vehicle
class Raptor {

private:
  std::string parameter_path_ =
      "/Users/sarathmenon/Desktop/eth_soft/code/Simulators/"
      "custom_simulator/src/description/examples/raptor/parameters";

  std::string quadcopter_parameters_file_ = "quadcopter_parameters.yaml";
  std::string arm_parameters_file_ = "arm_parameters.yaml";
  std::string gripper_parameters_file_ = "gripper_parameters.yaml";

public:
  Quadcopter quadcopter{parameter_path_ + '/' + quadcopter_parameters_file_};
  Arm arm{parameter_path_ + '/' + arm_parameters_file_};
  Gripper gripper{parameter_path_ + '/' + gripper_parameters_file_};

  // Getter Functions
public:
};