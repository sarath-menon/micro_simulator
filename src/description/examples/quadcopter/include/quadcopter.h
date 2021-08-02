#pragma once
#include "bldc_motor.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <Eigen/Dense>
#include <kindr/Core>

/// Represents the quadcopter
class Quadcopter : public RigidBody {

private:
  // Frame
  std::string frame_parameters_file = "frame_parameters.yaml";

  // Motors
  std::string motor1_parameters_file =
      "parameters/actuators/motor1_parameters.yaml";

  std::string motor2_parameters_file =
      "parameters/actuators/motor2_parameters.yaml";

  std::string motor3_parameters_file =
      "parameters/actuators/motor3_parameters.yaml";

  std::string motor4_parameters_file = "parameters/sensors/imu_parameters.yaml";

  // Sensors
  std::string imu_parameters_file =
      "parameters/actuators/motor4_parameters.yaml";

public:
  /// Loads the quadcopter properties from the yaml file
  Quadcopter(std::string parameter_path);

  /// Quadcopter frame
  QuadcopterFrame frame{frame_parameters_file};

  /// Quadcopter motors (4)
  BldcMotor motor_1{motor1_parameters_file};
  BldcMotor motor_2{motor2_parameters_file};
  BldcMotor motor_3{motor3_parameters_file};
  BldcMotor motor_4{motor4_parameters_file};

  // Variables
protected:
  // Manually computed now. has to be automated later
  Eigen::Matrix3d inertia_matrix_q;

  // /// Orientation of the quadcopter as Rotation Matrix (R_OB)
  // Eigen::Matrix3d orientation_rotation_matrix = Eigen::Matrix3d::Zero();

  // /// Orientation of the quadcopter as Euler Angles (roll, pitch, yaw)
  // Eigen::Vector3d orientation_euler_angles = Eigen::Vector3d::Zero();

protected:
  // Varibles for the dynamics function. Alloss return by reference instead of
  // by value.
  Eigen::Vector3d gravity_vector;

  // velocity
  Eigen::Vector3d position_dot_;
  // Acceleration
  Eigen::Vector3d position_ddot_;
  // Quaternion derivative
  Eigen::Vector4d orientation_dot;
  // Angular acceleration
  Eigen::Vector3d angular_acceleration_;

public:
  /// Quadcopter Dynamics
  virtual void Dynamics();

  void set_mass();
  void set_inertia();

public:
  // /// Getter function
  // float moment_arm() const { return moment_arm_; }
};
