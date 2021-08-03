#include "bldc_motor.h"
#include "quadcopter.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <stdio.h>
#include <sys/printk.h>
#include <zephyr.h>

int main() {

  QuadcopterFrame frame;
  frame.set_mass(0.7);

  /// Quadcopter motors (4)
  BldcMotor motor[4];

  return 0;
}
