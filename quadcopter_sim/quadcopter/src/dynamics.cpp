#include "quadcopter.h"
#include <iostream>

/// Represents the quadcopter
void Quadcopter::dynamics(const float motor_commands[4], const float dt) {

  // Convert motor speed to body thrust, torques produced
  motor_speed_to_thrust_torque(motor_commands);
  // Dynamics of the quadcopter frame
  frame.dynamics(body_thrust, body_torques, dt);

  // std::cout << "Body thrust:" << body_thrust(2) << '\t'
  //           << "Body torques:" << body_torques(0) << '\t' << body_torques(1)
  //           << '\t' << body_torques(2) << '\n';
}