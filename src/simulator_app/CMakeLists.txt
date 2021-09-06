

add_executable(quad_3d
src/main.cpp
src/quadcopter_description.cpp
src/quadcopter_initial_conditions.cpp
)


target_include_directories(quad_3d PRIVATE include)

target_link_libraries(quad_3d  PRIVATE 
primitives_lib
parts_lib
simulator_lib
helper_lib
)


target_link_libraries(quad_3d  PRIVATE 
yaml-cpp
)