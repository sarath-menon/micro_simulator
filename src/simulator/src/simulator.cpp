#include "simulator.h"

float Simulator::euler_forward_step(float x_k, float f_dot_x, float dt)
{
    return x_k + f_dot_x * dt;
}

float Simulator::rungeKutta_step(float x_k, float f_dot_x, float dt)
{
    // Apply Runge futta Formulas to find
    // next value of y
    // float f1 = dt * dynamics(x0, y);
    // float f2 = dt * dynamics(x0 + 0.5 * dt, y + 0.5 * f1);
    // float f3 = dt * dynamics(x0 + 0.5 * dt, y + 0.5 * f2);
    // float f4 = dt * dynamics(x0 + dt, y + f3);

    // // Update next value of y
    // y0 = y0 + (1 / 6) * (f1 + 2 * f2 + 2 * f3 + f4);

    return 0;
}