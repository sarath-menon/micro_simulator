

add_executable(quad_3d
src/main.cpp
src/plot.cpp
#src/display_parameters_demo.cpp
)


target_include_directories(quad_3d PUBLIC include)

target_link_libraries(quad_3d  PRIVATE 
quadcopter_lib
primitives_lib
parts_lib
helper_lib
)


target_link_libraries(quad_3d  PRIVATE 
yaml-cpp
simulator_lib
mahi::gui
msg_lib
mocap_fastdds_lib
fastcdr 
fastrtps
)