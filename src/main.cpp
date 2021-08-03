#include "bldc_motor.h"
#include "quadcopter.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <stdio.h>
// #include <sys/printk.h>
#include <zephyr.h>

int main() {

  QuadcopterFrame frame;
  frame.set_mass(0.7);
  float frame_intertia_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  frame.set_inertia_matrix(frame_intertia_matrix);

  /// Quadcopter motors (4)
  BldcMotor motor[4];
  float motor_intertia_matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  for (int i = 0; i < 4; i++) {
    motor[i].set_mass(0.05);
    motor[i].set_max_speed(20000);
    motor[i].set_min_speed(2000);
    motor[i].set_inertia_matrix(motor_intertia_matrix);
  }

  matrix::Vector3f relative_position_motor1(0.2f, 0, 0);
  matrix::Vector3f relative_position_motor2(0, 0.2f, 0);
  matrix::Vector3f relative_position_motor3(-0.2f, 0, 0);
  matrix::Vector3f relative_position_motor4(0, -0.2f, 0);

  motor[0].set_relative_position(relative_position_motor1);
  motor[1].set_relative_position(relative_position_motor1);
  motor[2].set_relative_position(relative_position_motor1);
  motor[3].set_relative_position(relative_position_motor1);

  return 0;
}
