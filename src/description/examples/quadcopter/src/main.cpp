#include "quadcopter.h"
#include <sys/printk.h>
#include <zephyr.h>

int main() {

  Quadcopter v1;

  Mass and Inertia Matrices v1.set_mass(0.5);
  printk("Mass:%d", m_q) v1.Dynamics();
}
