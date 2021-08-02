#include "quadcopter.h"
#include <iostream>
#include <kindr/Core>

int main() {

  std::string parameter_path =
      "/Users/sarathmenon/Desktop/eth_soft/code/Simulators/"
      "custom_simulator/src/description/examples/quadcopter/parameters";

  std::string quadcopter_parameters_file = "quadcopter_parameters.yaml";

  // Quadcopter v1{parameter_path + '/' + quadcopter_parameters_file};
  // // Mass and Inertia Matrices

  // float m_q = v1.mass();
  // std::cout << m_q << std::endl;
  // v1.Dynamics();
}
