#include "pid_cascaded.h"
#include <iostream>

float PidCascadedController::altitude_controller(const Quadcopter &quad,
                                                 const float altitude_target,
                                                 const float dt) {
  // Compute error
  const float altitude_error = altitude_target - quad.position()(2);

  // Compute control input
  float thrust_command =
      altitude_pid(altitude_error, k_p__z, k_i__z, k_d__z, dt);

  std::cout << "raw thrust command:" << thrust_command << '\n';

  // Quadcopter Motors have a maximum and minimum speed limit
  thrust_command =
      limit(ff_thrust + thrust_command, quad.thrust_max(), quad.thrust_min());

  std::cout << "Altitue error:" << altitude_error << '\n';
  std::cout << "k_p__z:" << k_p__z << '\n';

  return thrust_command;
};

float PidCascadedController::horizontal_controller(
    const Quadcopter &quad, const float horizontal_target, const float dt) {

  // Compute error
  const float horizontal_error = horizontal_target - quad.position()(0);

  // Compute required attitude
  float attitude_command =
      horizontal_pid(horizontal_error, k_p__x, k_i__x, k_d__x, dt) / 9.81;

  attitude_command = limit(attitude_command, quad.roll_max(), -quad.roll_max());

  return attitude_command;
};

float PidCascadedController::attitude_controller(const Quadcopter &quad,
                                                 const float attitude_target,
                                                 const float dt) {
  const float angle_error = attitude_target - quad.frame.arm_length();

  float torque_command = attitude_pid(angle_error, k_p__b, k_i__b, k_d__b, dt);

  torque_command =
      limit(torque_command, quad.roll_torque_max(), -quad.pitch_torque_max());

  return torque_command;
};