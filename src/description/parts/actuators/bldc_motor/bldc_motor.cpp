#include "bldc_motor.h"

// BldcMotor::BldcMotor(std::string parameter_path) : Motor(parameter_path) {}

float BldcMotor::Dynamics(float thrust_desired, float thrust_current) {
  float thrust_dot = (1 / time_constant_) * (thrust_desired - thrust_current);
  return thrust_dot;
}

// Setter functions
