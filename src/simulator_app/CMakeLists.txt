
target_sources(app PRIVATE 
src/main.cpp
)

target_include_directories(app  PRIVATE include)

target_link_libraries(app  PRIVATE 
primitives_lib
parts_lib
simulator_lib
helper_lib
)

