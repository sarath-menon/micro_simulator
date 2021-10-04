#pragma once
#include "math_helper.h"
#include "quadcopter.h"

class PidCascadedController {

private:
  YAML::Node controller_yaml = YAML::LoadFile(
      "quadcopter_sim/controller/pid_cascaded/controller_parameters.yaml");

protected:
  // Altitude controller parameters
  const float k_p__z = controller_yaml["k_p__z"].as<float>(); // [constant]
  const float k_i__z = controller_yaml["k_i__z"].as<float>(); // [constant]
  const float k_d__z = controller_yaml["k_d__z"].as<float>(); // [constant]
  // Vertical controller parameters
  const float k_p__x = controller_yaml["k_p__x"].as<float>(); // [constant]
  const float k_i__x = controller_yaml["k_i__x"].as<float>(); // [constant]
  const float k_d__x = controller_yaml["k_d__x"].as<float>(); // [constant]
  // Angle controller parameters
  const float k_p__b = controller_yaml["k_p__b"].as<float>(); // [constant]
  const float k_i__b = controller_yaml["k_i__b"].as<float>(); // [constant]
  const float k_d__b = controller_yaml["k_d__b"].as<float>(); // [constant]

  // Feedforward thrust
  constexpr static float ff_thrust = 9.81;

private:
  // Vertical controller pid loops float
  float z_pos_pid(const float e, const float k_p, const float k_i,
                  const float k_d, const float dt);

  // Horizontal controller pid loops
  float x_pos_pid(const float e, const float k_p, const float k_i,
                  const float k_d, const float dt);
  float y_pos_pid(const float e, const float k_p, const float k_i,
                  const float k_d, const float dt);

  float roll_angle_pid(const float e, const float k_p, const float k_i,
                       const float k_d, const float dt);

public:
  float altitude_controller(const Quadcopter &quad, const float altitude_target,
                            const float dt);
  float horizontal_controller(const Quadcopter &quad,
                              const float horizontal_target, const float dt);
  float roll_angle_controller(const Quadcopter &quad,
                              const float attitude_target, const float dt);
};