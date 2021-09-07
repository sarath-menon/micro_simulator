#include "quadcopter.h"
#include "simulator.h"
#include <iostream>

int main() {
  // Assume we are getting motor thrust commands from the low level controller
  // as an array of floats: [motor_1_speed,....., motor_4_speed]

  Quadcopter quad;
  quad.set_parameters();
  quad.set_initial_conditions();

  return 0;
}
