#include "quadcopter.h"

/// Represents the quadcopter
void Quadcopter::dynamics(float motor_commands[4]) {

  // Convert motor speed to body thrust, torques produced
  motor_speed_to_thrust_torque(motor_commands);
  // Dynamics of the quadcopter frame
  frame.dynamics(body_thrust, body_torques);
}