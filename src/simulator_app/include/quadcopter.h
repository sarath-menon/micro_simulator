#pragma once
#include "motor_propeller_pair.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"
#include <matrix/math.hpp>
#include <yaml-cpp/yaml.h>

/// Represents the quadcopter
class Quadcopter : public RigidBody {

public:
  // Load parts from the library
  QuadcopterFrame frame;
  MotorPropellerPair motor[4];

  // Private variables
private:
  float roll_pitch_max_ = 0;

  // Thrust produced by each propeller
  float propeller_thrusts[4] = {0, 0, 0, 0};

  // Net thrust acting on the quadcopter
  matrix::Vector3<float> body_thrust;
  // Net torques acting on the quadcopter
  matrix::Vector3<float> body_torques;

  // Public function
public:
  /// Loads the quadcopter properties from the yaml file
  void set_parameters();
  // Set initial conditions of the quadcopter
  void set_initial_conditions();
  // Read sensor values
  void sensor_read();
  // // COnvert motor speed to thrust and torque exerted in quadcopter frame
  void motor_speed_to_thrust_torque(float motor_commands[4]);
  // Quadcopter dynamics
  void dynamics(float motor_commands[4]);
  // Quadcopter dynamics
  void euler_step();

public:
  /// Getter function
  const float roll_pitch_max() const { return roll_pitch_max_; }

public:
  /// Setter function
  void set_roll_pitch_max(float roll_pitch_max) {
    roll_pitch_max_ = roll_pitch_max;
  }
};
