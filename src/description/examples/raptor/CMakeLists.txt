add_executable(description_example
src/raptor.cpp
src/main.cpp
)

target_link_libraries(description_example PRIVATE
rigid_parts_lib
soft_parts_lib
Eigen3::Eigen
yaml-cpp
)
    
target_include_directories(description_example PUBLIC include)
