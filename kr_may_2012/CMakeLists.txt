cmake_minimum_required (VERSION 2.6)
project (kr_may_2012)

set (sort_sources main.cpp input_output.cpp custom_qsort.cpp randomized_qsort.cpp intro_sort.cpp heap_sort.cpp)

set (speedtest_sources speedtest.cpp generators.cpp custom_qsort.cpp randomized_qsort.cpp intro_sort.cpp heap_sort.cpp)

add_executable(quick_sort ${sort_sources})
add_executable(random_quick_sort ${sort_sources})
add_executable(intro_sort ${sort_sources})
add_executable(speedtest ${speedtest_sources})

set_target_properties(quick_sort PROPERTIES COMPILE_DEFINITIONS "SORT_FUNCTION=customQsort")
set_target_properties(random_quick_sort PROPERTIES COMPILE_DEFINITIONS "SORT_FUNCTION=randomizedQsort")
set_target_properties(intro_sort PROPERTIES COMPILE_DEFINITIONS "SORT_FUNCTION=introSort")

if(CMAKE_HOST_WIN32)
  set_target_properties(quick_sort random_quick_sort intro_sort speedtest PROPERTIES COMPILER_FLAGS "/O2" LINK_FLAGS "/MACHINE:X86")
endif(CMAKE_HOST_WIN32)
