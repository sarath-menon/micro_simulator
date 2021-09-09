#pragma once
#include "quadcopter.h"
#include <iostream>
#include <math.h>
#include <math_helper.h>
#include <matrix/math.hpp>

void motor_mixing(const Quadcopter &quad, float motor_commands[4],
                  const float thrust_command, const float torque_commands[3],
                  const float k_f, const float arm_length) {

  matrix::Vector<float, 4> body_thrust_torques;
  matrix::Vector<float, 4> motor_thrusts;

  body_thrust_torques(0) = thrust_command;
  body_thrust_torques(1) = torque_commands[0];
  body_thrust_torques(2) = torque_commands[1];
  body_thrust_torques(3) = torque_commands[2];

  motor_thrusts = quad.mixer_matrix() * body_thrust_torques;

  for (int i = 0; i < 4; i++) {
    motor_thrusts(i) = limit(motor_thrusts(i), quad.motor[i].thrust_max(),
                             quad.motor[i].thrust_min());
    motor_commands[i] = sqrt(motor_thrusts(i) / k_f);
  }

  // std::cout << "Actual Motor 1 command " << motor_commands[0] << std::endl;

  // std::cout << "Propeller thrusts in Controller: f1:" << motor_thrusts(0)
  //           << "\tf2:" << motor_thrusts(1) << "\tf3:" << motor_thrusts(2)
  //           << "\tf4:" << motor_thrusts(3) << std::endl;

  // std::cout << "Thrust command before  motor mixing:" << thrust_command <<
  // '\n'; std::cout << "Thrust command after motor mixing:"
  //           << motor_thrusts(0) + motor_thrusts(1) + motor_thrusts(2) +
  //                  motor_thrusts(3)
  //           << '\n';

  // std::cout << "Torque commands before  motor mixing:" << torque_commands[0]
  //           << '\t' << torque_commands[1] << '\t' << torque_commands[2] <<
  //           '\n';
  // std::cout << "Torque commands after motor mixing:" << (f2 - f4) *
  // arm_length
  //           << '\t' << (f1 - f3) * arm_length << '\t' << 0 << '\n';

  // std::cout << "Motor commands:" << motor_commands[0] << '\t'
  //           << motor_commands[1] << '\t' << motor_commands[2] << '\t'
  //           << motor_commands[3] << '\n';
}
