#include "plot.h"
#include "quadcopter.h"
#include "simulator.h"
#include <iostream>

int main() {

  Quadcopter quad;
  Simulator sim;
  sim.set_parameters("quadcopter_sim/quadcopter_sim_app/parameters/"
                     "simulation_parameters.yaml");

  quad.set_parameters();
  quad.set_initial_conditions();

  // Declare for now
  float motor_commands[4] = {0, 0, 0, 0};

  ///////////////////////////////////////////////////////////////////////////////////////////
  // Start Simulation
  ///////////////////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < sim.euler_steps(); i++) {
    // Get system state
    quad.sensor_read();

    // Dynamics function that accepts motor commands instead of thrusts
    quad.dynamics(motor_commands);

    // quad.dynamics(ff_thrust, torque_command);
    quad.euler_step(sim.dt());

    std::cout << "Altitude:" << quad.position()(2) << '\n';

    if (plot_flags::plot_enable) {
      // Set variables for plotting
      plot_var::z_plot[i] = quad.position()(2);
      plot_var::t_plot[i] = i * sim.dt();
    }
  }

  if (plot_flags::plot_enable) {
    // Initialize visualizer
    MyApp app;
    app.run();
  }

  return 0;
}
