#pragma once

#include "motor_propeller_pair.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <matrix/math.hpp>

namespace quadcopter_simulation {

float initial_position[3] = {0, 0, 0};
float initial_orientation[4] = {1, 0, 0, 0};

void set_initial_conditions(QuadcopterFrame frame,
                            MotorPropellerPair motor[4]) {

  //////////////////////
}

} // namespace quadcopter_simulation