#include "motor_propeller_pair.h"

// BldcMotor::BldcMotor(std::string parameter_path) : Motor(parameter_path) {}

void MotorPropellerPair::Dynamics(const float &commanded_motor_speed)
{
  // get motor thrust from motor speed here. For now, declsre variable
  float commanded_thrust;

  actual_thrust_dot_ = (1 / time_constant_) * (commanded_thrust - actual_thrust_);
}

// Setter functions
