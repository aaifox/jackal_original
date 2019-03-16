cmake_minimum_required(VERSION 2.8.3)
project(control_base)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
)


## Generate added messages and services with any dependencies listed here
generate_messages(DEPENDENCIES geometry_msgs)

catkin_package()

include_directories(include ${catkin_INCLUDE_DIRS})

# necessary for control_*
add_executable(control_1 src/control_1.cpp)
add_executable(control_2 src/control_2.cpp) 

## Specify libraries to link a library or executable target against
# necessary for control_*
target_link_libraries(control_1  ${catkin_LIBRARIES})
target_link_libraries(control_2  ${catkin_LIBRARIES})

