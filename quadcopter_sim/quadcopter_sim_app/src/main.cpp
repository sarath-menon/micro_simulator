#include "quadcopter.h"
#include "simulator.h"
#include <iostream>

int main() {

  Quadcopter quad;
  Simulator sim;
  quad.set_parameters();
  quad.set_initial_conditions();

  // Declare for now
  float motor_commands[4] = {0, 0, 0, 0};

  ///////////////////////////////////////////////////////////////////////////////////////////
  // Start Simulation
  ///////////////////////////////////////////////////////////////////////////////////////////

  // Get system state
  quad.sensor_read();

  // Dynamics function that accepts motor commands instead of thrusts
  quad.dynamics(motor_commands);

  // quad.dynamics(ff_thrust, torque_command);
  quad.euler_step(sim.dt());

  return 0;
}
