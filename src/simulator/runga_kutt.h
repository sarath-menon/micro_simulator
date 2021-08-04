

float rungeKutta_step(float x0, float y0, float dt, int (*dynamics)(int, int)) {

  float f1, f2, f3, f4, f5;

  // Apply Runge futta Formulas to find
  // next value of y
  f1 = dt * dynamics(x0, y);
  f2 = dt * dynamics(x0 + 0.5 * dt, y + 0.5 * f1);
  f3 = dt * dynamics(x0 + 0.5 * dt, y + 0.5 * f2);
  f4 = dt * dynamics(x0 + dt, y + f3);

  // Update next value of y
  y = y + (1.0 / 6.0) * (f1 + 2 * f2 + 2 * f3 + f4);

  // Update next value of x
  x0 = x0 + dt;
}

return y;
}