# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
set(BOARD nucleo_l432kc)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(micro_simulator)

include_directories(external/PX4-Matrix)
include_directories(external/mavlink_c)

add_subdirectory(src/helper)
add_subdirectory(src/description)
add_subdirectory(src/simulator)
add_subdirectory(src/simulator_app)
