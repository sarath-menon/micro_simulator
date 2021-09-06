cmake_minimum_required(VERSION 3.10)
project(simulator_pc VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)

include_directories(external/PX4-Matrix)

###############################################################################
# Find installed packages
###############################################################################

find_package(fastcdr REQUIRED)
find_package(fastrtps REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

add_subdirectory(src/helper)
add_subdirectory(src/description)
add_subdirectory(src/simulator)
add_subdirectory(src/simulator_app)
