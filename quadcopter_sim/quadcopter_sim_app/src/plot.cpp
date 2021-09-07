
#include "plot.h"

void MyApp::update() {

  // App logic and/or ImGui code goes here
  ImGui::Begin("Quadcopter plots");

  static float alpha = 0.25f;
  ImPlot::PushColormap(ImPlotColormap_Pastel);

  // x axis distance
  if (plot_flags::x_flag) {
    // Translation plot
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, 0, 5);
    if (ImPlot::BeginPlot("x axis distance vs time", "time", "x distance [m]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("vertical distance", plot_var::t_plot, plot_var::x_plot,
                       plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // y axis distance
  if (plot_flags::y_flag) {
    // Translation plot
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, 0, 5);
    if (ImPlot::BeginPlot("y axis distance vs time", "time", "y distance [m]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("vertical distance", plot_var::t_plot, plot_var::y_plot,
                       plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // z axis distance
  if (plot_flags::z_flag) {
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, 0, 8);
    if (ImPlot::BeginPlot("z axis distance vs time", "time", "z distance [m]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("altitude", plot_var::t_plot, plot_var::z_plot,
                       plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // Roll angle plot
  if (plot_flags::roll_angle_flag) {
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, -50, 50);
    ImPlot::PushColormap(ImPlotColormap_Pastel);
    if (ImPlot::BeginPlot("roll angle vs Time", "time", "roll angle [deg]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("torque input", plot_var::t_plot,
                       plot_var::roll_angle_plot, plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // pitch angle plot
  if (plot_flags::pitch_angle_flag) {
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, -50, 50);
    ImPlot::PushColormap(ImPlotColormap_Pastel);
    if (ImPlot::BeginPlot("pitch angle vs Time", "time", "pitch angle [deg]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("torque input", plot_var::t_plot,
                       plot_var::pitch_angle_plot, plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // yaw angle plot
  if (plot_flags::yaw_angle_flag) {
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, -50, 50);
    ImPlot::PushColormap(ImPlotColormap_Pastel);
    if (ImPlot::BeginPlot("yaw angle vs Time", "time", "yaw angle [deg]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("torque input", plot_var::t_plot,
                       plot_var::yaw_angle_plot, plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // Thrust input plot
  if (plot_flags::body_thrust_flag) {
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, 0, 25);
    ImPlot::PushColormap(ImPlotColormap_Pastel);
    if (ImPlot::BeginPlot("Thrust input vs Time", "time", "thrust input [N/kg]",
                          ImVec2(-1, 200))) {
      ImPlot::PlotLine("thrust input", plot_var::t_plot, plot_var::thrust_plot,
                       plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  // Torque input plot
  if (plot_flags::body_roll_torque_flag) {
    ImPlot::SetNextPlotLimits(plot_var::x_min, plot_var::x_max, -5, 5);
    ImPlot::PushColormap(ImPlotColormap_Pastel);
    if (ImPlot::BeginPlot("Torque input vs Time", "time",
                          "Torque Input [Nm/kg]", ImVec2(-1, 200))) {
      ImPlot::PlotLine("torque input", plot_var::t_plot,
                       plot_var::torque_roll_plot, plot_var::euler_timesteps);
      ImPlot::EndPlot();
    }
  }

  ImGui::End();
}
