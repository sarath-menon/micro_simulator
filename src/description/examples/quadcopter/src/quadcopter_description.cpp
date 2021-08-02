#include "quadcopter.h"
#include <yaml-cpp/yaml.h>

Quadcopter::Quadcopter(std::string parameter_path) : RigidBody() {
  YAML::Node yaml_file = YAML::LoadFile(parameter_path);

  // Declare gravity vector
  gravity_vector << 0, 0, 9.81;
}

void Quadcopter::set_mass() {
  mass_ = motor_1.mass() + motor_2.mass() + motor_3.mass() + motor_4.mass() +
          frame.mass();
}
void Quadcopter::set_inertia() {
  inertia_matrix_ << 0.2, 0, 0, 0, 0.2, 0, 0, 0, 0.2;
};

// Setter functions
