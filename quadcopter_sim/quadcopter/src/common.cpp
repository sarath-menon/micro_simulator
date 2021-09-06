#include "quadcopter.h"

void Quadcopter::motor_speed_to_thrust_torque(float motor_commands[4]) {

  // Get thrust corresponding to motor speed
  for (int i = 0; i < 4; i++) {
    propeller_thrusts[i] =
        MotorPropellerPair::motor_speed_to_thrust_map(motor_commands[i]);
  }
  // Compute net thrust acting on quadcopter
  body_thrust(2) = propeller_thrusts[0] + propeller_thrusts[2] +
                   propeller_thrusts[2] + propeller_thrusts[3];

  // Compute net torque acting on the quadcopter
  body_torques(0) =
      (propeller_thrusts[1] - propeller_thrusts[3]) * frame.moment_arm();

  body_torques(1) =
      (propeller_thrusts[0] - propeller_thrusts[2]) * frame.moment_arm();

  body_torques(2) = (propeller_thrusts[0] - propeller_thrusts[1] +
                     propeller_thrusts[2] - propeller_thrusts[2]) *
                    MotorPropellerPair::k_t();
}
