#include "quadcopter_description.h"

/// Represents the quadcopter
void QuadcopterDescription::set_parameters() {
  // Set arm length
  frame.set_mass(yaml_file["mass"].as<float>());

  // Set mass
  frame.set_moment_arm(yaml_file["arm_length"].as<float>());

  // Set inertia matrix
  float frame_intertia[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  frame_intertia[0][0] = yaml_file["inertia_xx"].as<float>();
  frame_intertia[1][1] = yaml_file["inertia_xx"].as<float>();
  frame_intertia[2][2] = yaml_file["inertia_xx"].as<float>();

  frame.set_inertia_matrix(frame_intertia);

  // Set linear and angular drag coeffeicnts
  float linear_drag_coeff[3] = {0, 0, 0};
  float angular_drag_coeff[3] = {0, 0, 0};

  linear_drag_coeff[0] = yaml_file["linear_drag_coeff_x"].as<float>();
  linear_drag_coeff[1] = yaml_file["linear_drag_coeff_y"].as<float>();
  linear_drag_coeff[2] = yaml_file["linear_drag_coeff_z"].as<float>();

  angular_drag_coeff[0] = yaml_file["angular_drag_coeff_x"].as<float>();
  angular_drag_coeff[1] = yaml_file["angular_drag_coeff_y"].as<float>();
  angular_drag_coeff[2] = yaml_file["angular_drag_coeff_z"].as<float>();

  frame.set_linear_drag_coeff(linear_drag_coeff);
  frame.set_angular_drag_coeff(angular_drag_coeff);
}
