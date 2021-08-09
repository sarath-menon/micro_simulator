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
  // Simulator sim;

  quadcopter_description::set_parameters(frame, motor);
  quadcopter_simulation::set_initial_conditions(frame, motor);

  motor[0].Dynamics(commanded_motor_speeds[0]);
  motor[1].Dynamics(commanded_motor_speeds[1]);
  motor[2].Dynamics(commanded_motor_speeds[2]);
  motor[3].Dynamics(commanded_motor_speeds[3]);

  float motor_thrusts[4] = {motor[0].actual_thrust(), motor[1].actual_thrust(),
                            motor[2].actual_thrust(), motor[3].actual_thrust()};

  frame.Dynamics(motor_thrusts);
  // imu.Dynamics();

  return 0;
}
