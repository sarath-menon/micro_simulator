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
    quad.dynamics(motor_commands, sim.dt());

    // quad.dynamics(ff_thrust, torque_command);
    quad.euler_step(sim.dt());

    // std::cout << "Altitude:" << quad.position()(2) << '\n';
    // std::cout << "Quadcopter acceleration:" << quad.frame.acceleration()(0)
    //           << '\t' << quad.frame.acceleration()(1) << '\t'
    //           << quad.frame.acceleration()(2) << '\n';
    std::cout << std::endl;

    if (plot_flags::plot_enable) {
      // Set variables for plotting
      plot_var::x_plot[i] = quad.position()(0);
      plot_var::y_plot[i] = quad.position()(1);
      plot_var::z_plot[i] = quad.position()(2);

      Eulerf euler_orientation(quad.orientation());
      plot_var::roll_angle_plot[i] = euler_orientation(0);
      plot_var::pitch_angle_plot[i] = euler_orientation(1);
      plot_var::yaw_angle_plot[i] = euler_orientation(2);

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
