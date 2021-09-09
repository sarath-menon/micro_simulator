#include "motor_mixing.h"
#include "pid_cascaded.h"
#include "plot.h"
#include "quadcopter.h"
#include "simulator.h"
#include <iostream>

int main() {

  Quadcopter quad;
  Simulator sim;
  PidCascadedController controller;

  sim.set_parameters("quadcopter_sim/quadcopter_sim_app/parameters/"
                     "simulation_parameters.yaml");

  quad.set_parameters();
  quad.set_initial_conditions();

  // Declare for now
  float motor_commands[4] = {0, 0, 0, 0};
  float torque_commands[3] = {0, 0, 0};

  ///////////////////////////////////////////////////////////////////////////////////////////
  // Start Simulation
  ///////////////////////////////////////////////////////////////////////////////////////////

  for (int i = 0; i < sim.euler_steps(); i++) {
    // Print simulation timestep
    std::cout << "Timestep:" << i + 1 << '\n';

    // Get system state
    quad.sensor_read();

    // Outer loop
    const float thrust_command =
        controller.altitude_controller(quad, 5, sim.dt());

    const float attitude_command =
        controller.horizontal_controller(quad, 2, sim.dt());

    // torque_commands[0] =
    //     controller.attitude_controller(quad, attitude_command, sim.dt());

    // // test altitude controller first
    const float torque_commands[3] = {0, 0, 0};

    // Convert thrust, torque to motor speeds
    motor_mixing(quad, motor_commands, thrust_command, torque_commands,
                 quad.motor[0].k_f(), quad.frame.arm_length());

    // Dynamics function that accepts motor commands instead of thrusts
    quad.dynamics(motor_commands, sim.dt());

    // quad.dynamics(ff_thrust, torque_command);
    quad.euler_step(sim.dt());

    // Plot variables for debugging
    //////////////////////////////////////////////////////////////////////////////////

    std::cout << '\n';
    //////////////////////////////////////////////////////////////////////////////////

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
