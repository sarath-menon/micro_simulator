#pragma once
#include "motor.h"

/// Represents the swinging arm
class MotorPropellerPair : public Motor {

private:
public:
  /// Loads the arm properties from the yaml file
  // BldcMotor(std::string parameter_path);

  // By default, everything is initialized to zero
protected:
  // Position and Orientation ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Time constant of the bldc motor.
  float time_constant_ = 0;

  // Variables for dynamics function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  /// Thrust generated by the motor propellor pair
  float actual_thrust_ = 0;

  /// Rate of change of thrust for the motor propellor pair
  float actual_thrust_dot_ = 0;

  /// Maximum thrust produced by propeller
  float thrust_max_ = 0;

  // Minimum m thrust produced by propeller
  float thrust_min_ = 0;

  // Relation btw square of motor speed and motor thrust
  constexpr static float k_f_ = 0.0000000611;
  // Relation btw  motor thrust and drag torque
  constexpr static float k_t_ = 0.0000000611;

public:
  /// Arm Dynamics
  void dynamics(const float commanded_motor_speed);

  constexpr static float motor_speed_to_thrust_map(const float motor_command) {

    float commanded_thrust = motor_command * k_f_;

    // For now, let actual thrust = commanded thryst
    return commanded_thrust;
  }

public:
  /// Getter function
  float time_constant() const { return time_constant_; }

  /// Getter function
  float actual_thrust() { return actual_thrust_; }

  /// Getter function
  float actual_thrust_dot() const { return actual_thrust_dot_; }

  /// Getter function
  const float thrust_max() const { return thrust_max_; }

  /// Getter function
  const float thrust_min() const { return thrust_min_; }
  /// Getter function
  constexpr static float k_f() { return k_f_; }
  /// Getter function
  constexpr static float k_t() { return k_t_; }

public:
  /// Setter function
  void set_time_constant(float time_constant) {
    time_constant_ = time_constant;
  }

  /// Setter function
  void set_thrust_max(float thrust_max) { thrust_max_ = thrust_max; }

  /// Setter function
  void set_thrust_min(float thrust_min) { thrust_min_ = thrust_min; }
};