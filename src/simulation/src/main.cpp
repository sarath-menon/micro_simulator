#include "set_initial_conditions.h"
#include "set_parameters.h"

#include "bldc_motor.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <stdio.h>
// #include <sys/printk.h>
#include <zephyr.h>

int main() {
  QuadcopterFrame frame;
  BldcMotor motor[4];

  quadcopter_description::set_parameters(frame, motor);
  quadcopter_simulation::set_initial_conditions(frame, motor);

  return 0;
}
