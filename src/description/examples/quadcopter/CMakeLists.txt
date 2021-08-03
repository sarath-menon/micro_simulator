add_executable(quadcopter_example
src/main.cpp
# src/quadcopter_description.cpp
# src/quadcopter_dynamics.cpp
)
target_include_directories(quadcopter_example PUBLIC include )

target_link_libraries(quadcopter_example 
parts_lib
primitives_lib
)
    

