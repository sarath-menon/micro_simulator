#include <math.h>
#include <matrix/math.hpp>
#include <stdio.h>
#include <sys/printk.h>
#include <zephyr.h>

#include "rigidbody.h"

int main() {
  RigidBody obj;
  obj.set_mass(5);
  return 0;
}
