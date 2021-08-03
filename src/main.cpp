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
  float temp[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  frame.set_inertia_matrix(temp);

  /// Quadcopter motors (4)
  BldcMotor motor[4];
  motor[0].set_mass(4);

  return 0;
}
