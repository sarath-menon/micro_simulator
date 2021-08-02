#include "raptor.h"
#include <iostream>
#include <kindr/Core>

int main() {

  Raptor r1;

  // Mass and Inertia Matrices

  float m_q = r1.quadcopter.mass();
  float m_a = r1.arm.mass();
  float m_g = r1.gripper.mass();
  std::cout << m_q << '\n' << m_a << '\n' << m_g;

  Eigen::Matrix3d J_q = r1.quadcopter.inertia_matrix();
  Eigen::Matrix3d J_a = r1.arm.inertia_matrix();
  Eigen::Matrix3d J_g = r1.gripper.inertia_matrix();
  std::cout << J_q << '\n' << J_a << '\n' << J_g;

  // Position and Orientation

  Eigen::Vector3d quad_position = r1.quadcopter.position();
  Eigen::Vector3d arm_position = r1.arm.position();
  Eigen::Vector3d gripper_position = r1.gripper.position();

  Eigen::Vector4d quad_orientation = r1.quadcopter.orientation();
  Eigen::Vector4d arm_orientation = r1.arm.orientation();
  Eigen::Vector4d gripper_orientation = r1.gripper.orientation();

  // Time derivaties of Position and Orientation

  Eigen::Vector3d quad_position_dot = r1.quadcopter.position_dot();
  Eigen::Vector3d arm_position_dot = r1.arm.position_dot();
  Eigen::Vector3d gripper_position_dot = r1.gripper.position_dot();

  Eigen::Vector4d quad_orientation_dot = r1.quadcopter.orientation_dot();
  Eigen::Vector4d arm_orientation_dot = r1.arm.orientation_dot();
  Eigen::Vector4d gripper_orientation_dot = r1.gripper.orientation_dot();

  // Geometrical Properties

  float l_q = r1.quadcopter.moment_arm();
  float l_g = r1.arm.arm_length();

  // Other Properties

  float k_t = r1.quadcopter.thrust_speed_ratio();
  float k_m = r1.quadcopter.torque_speed_ratio();
}
