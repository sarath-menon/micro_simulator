#pragma once

#include <Mahi/Gui.hpp>
#include <Mahi/Util.hpp>
#include <yaml-cpp/yaml.h>

using namespace mahi::gui;
using namespace mahi::util;

// Load yaml file containing plotting properties
inline YAML::Node plot_yaml = YAML::LoadFile(
    "quadcopter_sim/quadcopter_sim_app/parameters/plot_parameters.yaml");

// Load properties from yaml file
const bool plot_flag = plot_yaml["plot_flag"].as<bool>();

const bool x_flag = plot_yaml["x_flag"].as<bool>();
const bool y_flag = plot_yaml["y_flag"].as<bool>();
const bool z_flag = plot_yaml["z_flag"].as<bool>();

const bool roll_angle_flag = plot_yaml["roll_angle_flag"].as<bool>();
const bool pitch_angle_flag = plot_yaml["pitch_angle_flag"].as<bool>();
const bool yaw_angle_flag = plot_yaml["yaw_angle_flag"].as<bool>();

const bool body_thrust_flag = plot_yaml["body_thrust_flag"].as<bool>();

const bool body_roll_torque_flag =
    plot_yaml["body_roll_torque_flag"].as<bool>();
const bool body_pitch_torque_flag =
    plot_yaml["body_pitch_torque_flag"].as<bool>();
const bool body_yaw_torque_flag = plot_yaml["body_yaw_torque_flag"].as<bool>();

// Inherit from Application
class MyApp : public Application {
public:
  // 640x480 px window
  MyApp() : Application(1080, 720, "My App") {}
  // Override update (called once per frame)

  void update() override;
};
