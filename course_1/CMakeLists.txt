cmake_minimum_required (VERSION 2.6)
project (course_1)

set (sources main.cpp passenger_structures.cpp passenger_input.cpp passenger_logic.cpp)
add_executable(passengers ${sources})

if(CMAKE_HOST_WIN32)
  set_target_properties(passengers PROPERTIES COMPILER_FLAGS "/O2" LINK_FLAGS "/MACHINE:X86")
endif(CMAKE_HOST_WIN32)
