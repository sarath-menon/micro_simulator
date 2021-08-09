#include "set_initial_conditions.h"
#include "set_parameters.h"

#include "motor_propeller_pair.h"
#include "quadcopter_frame.h"

#include <stdio.h>
// #include <sys/printk.h>
#include <zephyr.h>
#include "simulator.h"

int main()
{
  // Assume we are getting motor thrust commands from the low level controller as an array
  // of floats: [motor_1_speed,....., motor_4_speed]

  // For now, declare above variable
  float commanded_motor_speeds[4];

  QuadcopterFrame frame;
  MotorPropellerPair motor[4];
  // Imu imu;
  Simulator sim;

  quadcopter_description::set_parameters(frame, motor);
  quadcopter_simulation::set_initial_conditions(frame, motor);

  for (int i = 0; i < 4; i++){
    motor[i].Dynamics(commanded_motor_speeds[i]);
    sim.euler_forward_step(motor[i].actual_thrust(), motor[i].actual_thrust_dot(), 0.01);
  }

  float motor_thrusts[4] = {motor[0].actual_thrust(), motor[1].actual_thrust(),
                            motor[2].actual_thrust(), motor[3].actual_thrust()};

  frame.Dynamics(motor_thrusts);

  frame.set_position(sim.euler_forward_step(frame.position(), frame.position_dot(), 0.01));
  frame.set_position(sim.euler_forward_step(frame.position_dot(), frame.position_ddot(), 0.01));
  frame.set_orientation(sim.euler_forward_step(frame.orientation(), frame.orientation_dot(), 0.01));
  frame.set_angular_velocity(sim.euler_forward_step(frame.angular_velocity(), frame.angular_acceleration(), 0.01));

  // imu.Dynamics();

  return 0;
}
