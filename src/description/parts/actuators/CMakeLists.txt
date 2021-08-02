# ###############################################################################
# # Library of actuators
# ###############################################################################


add_library(actuator_lib STATIC
bldc_motor/bldc_motor.cpp
)

target_include_directories(actuator_lib PUBLIC 
bldc_motor
)

target_link_libraries(actuator_lib PRIVATE
primitives_lib
# Eigen3::Eigen
# helper_lib
# yaml-cpp
)



