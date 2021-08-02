add_executable(quadcopter_example
src/main.cpp
src/quadcopter.cpp
)

target_include_directories(quadcopter_example PUBLIC include)

target_link_libraries(quadcopter_example PRIVATE
actuators_lib
sensors_lib
structural_lib
primitives_lib
helper_lib
Eigen3::Eigen
yaml-cpp
)
    

