#pragma once

#include "bldc_motor.h"
#include "quadcopter_frame.h"
#include "rigidbody.h"

#include <matrix/math.hpp>

namespace quadcopter_simulation {

void set_initial_conditions(QuadcopterFrame frame, BldcMotor motor[4]) {}

} // namespace quadcopter_simulation