cmake_minimum_required (VERSION 2.6)
project (shops)

set (sources main.cpp shop.cpp)
add_executable(shops ${sources})

if(CMAKE_HOST_WIN32)
  set_target_properties(shops PROPERTIES COMPILER_FLAGS "/O2" LINK_FLAGS "/MACHINE:X86")
endif(CMAKE_HOST_WIN32)
