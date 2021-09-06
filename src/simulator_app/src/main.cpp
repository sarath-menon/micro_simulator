#include "quadcopter_description.h"
#include "set_initial_conditions.h"
#include "simulator.h"
#include <iostream>

int main() {
  // Assume we are getting motor thrust commands from the low level controller
  // as an array of floats: [motor_1_speed,....., motor_4_speed]

  QuadcopterDescription quad;
  quad.set_parameters();
  std::cout << "Quadcopter Mass:" << quad.frame.mass() << '\n';

  std::cout << "Linear drag coefficients:" << quad.frame.linear_drag_coeff_x()
            << '\t' << quad.frame.linear_drag_coeff_y() << '\t'
            << quad.frame.linear_drag_coeff_z() << '\n';

  std::cout << "Length of Moment arm:" << quad.frame.moment_arm() << '\n';

  std::cout << "Maximum motor thrust:" << quad.motor[0].thrust_max() << '\n';

  std::cout << "Minimum motor thrust:" << quad.motor[0].thrust_min() << '\n';

  // QuadcopterFrame frame;
  // MotorPropellerPair motor[4];
  // Imu imu;
  // Simulator sim;

  // quadcopter_description::set_parameters(frame, motor);
  // quadcopter_simulation::set_initial_conditions(frame, motor);

  // for (int i = 0; i < 4; i++) {
  //   motor[i].Dynamics(commanded_motor_speeds[i]);
  //   sim.euler_forward_step(motor[i].actual_thrust(),
  //                          motor[i].actual_thrust_dot(), 0.01);
  // }

  // float motor_thrusts[4] = {motor[0].actual_thrust(),
  // motor[1].actual_thrust(),
  //                           motor[2].actual_thrust(),
  //                           motor[3].actual_thrust()};

  // frame.Dynamics(motor_thrusts);

  // frame.set_position(
  //     sim.euler_forward_step(frame.position(), frame.position_dot(),
  //     0.01));
  // frame.set_position(sim.euler_forward_step(frame.position_dot(),
  //                                           frame.position_ddot(),
  //                                           0.01));
  // frame.set_orientation(sim.euler_forward_step(frame.orientation(),
  //                                              frame.orientation_dot(),
  //                                              0.01));
  // frame.set_angular_velocity(sim.euler_forward_step(
  //     frame.angular_velocity(), frame.angular_acceleration(), 0.01));

  // imu.Dynamics();

  return 0;
}
