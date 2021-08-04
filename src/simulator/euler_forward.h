
float euler_forward(float x_k, float f_x_k, float dt) {
  return f_x_k * dt + x_k
}
