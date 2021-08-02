#include "math_utils.h"
#include "quadcopter.h"
#include <yaml-cpp/yaml.h>

void Quadcopter::Dynamics() {

  // It is assumed that the motor thrusts have already been computed in some
  // function. Herw, we manually specify
  Eigen::Vector3d thrust_vector;
  Eigen::Vector3d torque_vector;

  // Kindr conversions
  // kindr::RotationQuaternionD q_wb(orientation_dot_);
  // kindr::LocalAngularVelocityD omega;
  // kindr::RotationQuaternionDiffD q_dot;

  // Applying the Equations of Motion

  // Velocity
  position_dot_ = velocity_;

  // Acceleration
  position_ddot_ =
      quaternion_transform_vector(orientation_, thrust_vector) + gravity_vector;

  // Angular velocity
  orientation_dot_ =
      quaternion_time_derivative(orientation_, angular_velocity_);

  // Angular acceleration
  angular_acceleration_ =
      inertia_matrix_q.inverse() * (torque_vector - angular_velocity_ -
                                    inertia_matrix_q * angular_velocity_);
};

// Setter functions
