# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.13.1)
set(BOARD nucleo_l432kc)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(stm32_pm_blinky)

include_directories(external/PX4-Matrix)
include_directories(external/mavlink_c)

target_sources(app PRIVATE 
src/simulation/src/main.cpp
)

target_include_directories(app PRIVATE src/simulation/include)

target_link_libraries(app PRIVATE 
primitives_lib
parts_lib
helper_lib
)

add_subdirectory(src/helper)
add_subdirectory(src/description)
