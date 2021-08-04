#include "motor_propeller_pair.h"

// BldcMotor::BldcMotor(std::string parameter_path) : Motor(parameter_path) {}

void MotorPropellerPair::Dynamics() {
  float thrust_desired;
  float thrust_current;

  /////////

  thrust_dot = (1 / time_constant_) * (thrust_desired - thrust_current);
}

// Setter functions
