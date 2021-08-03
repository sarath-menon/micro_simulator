#include "bldc_motor.h"
#include "quadcopter.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <stdio.h>
// #include <sys/printk.h>
#include <zephyr.h>

int main() {

  QuadcopterFrame frame;
  BldcMotor motor[4];

  float quadcopter_mass = 0.3;
  float frame_intertia_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  float motor_mass = 0.05;
  float motor_intertia_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int motor_max_speed = 20000;
  int motor_min_speed = 1000;
  float motor_distance = 0.05;

  frame.set_mass(quadcopter_mass);
  frame.set_inertia_matrix(frame_intertia_matrix);

  for (int i = 0; i < 4; i++) {
    motor[i].set_mass(motor_mass);
    motor[i].set_max_speed(motor_max_speed);
    motor[i].set_min_speed(motor_min_speed);
    motor[i].set_inertia_matrix(motor_intertia_matrix);
  }

  matrix::Vector3f relative_position_motor1(motor_distance, 0, 0);
  matrix::Vector3f relative_position_motor2(0, motor_distance, 0);
  matrix::Vector3f relative_position_motor3(-motor_distance, 0, 0);
  matrix::Vector3f relative_position_motor4(0, -motor_distance, 0);

  motor[0].set_relative_position(relative_position_motor1);
  motor[1].set_relative_position(relative_position_motor1);
  motor[2].set_relative_position(relative_position_motor1);
  motor[3].set_relative_position(relative_position_motor1);

  return 0;
}
