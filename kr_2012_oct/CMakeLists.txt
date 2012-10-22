cmake_minimum_required (VERSION 2.6)
project (words)

set (sources main.cpp)
add_executable(words ${sources})

if(CMAKE_HOST_WIN32)
  set_target_properties(words PROPERTIES COMPILER_FLAGS "/O2" LINK_FLAGS "/MACHINE:X86")
endif(CMAKE_HOST_WIN32)
