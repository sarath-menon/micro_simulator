#include "bldc_motor.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <stdio.h>
#include <sys/printk.h>
#include <zephyr.h>

int main() {
  RigidBody obj;
  obj.set_mass(5);

  QuadcopterFrame frame;

  /// Quadcopter motors (4)
  BldcMotor motor[4];

  return 0;
}
