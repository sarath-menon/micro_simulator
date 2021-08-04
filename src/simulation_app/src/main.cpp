#include "set_initial_conditions.h"
#include "set_parameters.h"

#include "motor_propeller_pair.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <stdio.h>
// #include <sys/printk.h>
#include <zephyr.h>

int main() {
  QuadcopterFrame frame;
  MotorPropellerPair motor[4];

  quadcopter_description::set_parameters(frame, motor);
  quadcopter_simulation::set_initial_conditions(frame, motor);

  return 0;
}
