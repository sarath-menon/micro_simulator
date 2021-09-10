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
    float thrust_command = controller.altitude_controller(quad, 5, sim.dt());

    float attitude_command =
        controller.horizontal_controller(quad, 4, sim.dt());

    attitude_command = 30;
    thrust_command = 0;

    torque_commands[0] =
        controller.roll_angle_controller(quad, attitude_command, sim.dt());

    // std::cout << "Roll torque command:" << torque_commands[0] << '\n';
    // // // test altitude controller first
    // float torque_commands[3] = {0, 0, 0};

    // Convert thrust, torque to motor speeds
    motor_mixing(quad, motor_commands, thrust_command, torque_commands,
                 quad.motor[0].k_f(), quad.frame.arm_length());

    // Dynamics function that accepts motor commands instead of thrusts
    quad.dynamics(motor_commands, sim.dt());

    // // Simulate using explicit Euler integration
    // quad.euler_step(sim.dt());

    // Simulate only rotational dynamics
    quad.attitude_tune_euler_step(sim.dt());

    // Plot variables for debugging
    //////////////////////////////////////////////////////////////////////////////////

    std::cout << "Euler angle:" << quad.frame.euler_orientation()(0) << '\t'
              << quad.frame.euler_orientation()(1) << '\t'
              << quad.frame.euler_orientation()(2) << '\n';

    std::cout << '\n';
    //////////////////////////////////////////////////////////////////////////////////

    if (plot_flags::plot_enable) {
      // Set variables for plotting
      plot_var::x_plot[i] = quad.position()(0);
      plot_var::y_plot[i] = quad.position()(1);
      plot_var::z_plot[i] = quad.position()(2);

      plot_var::roll_angle_plot[i] = quad.frame.euler_orientation()(0);
      plot_var::pitch_angle_plot[i] = quad.frame.euler_orientation()(1);
      plot_var::yaw_angle_plot[i] = quad.frame.euler_orientation()(2);

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
