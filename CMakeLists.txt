cmake_minimum_required(VERSION 3.6)

project (example)
add_definitions("-g")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules;${CMAKE_MODULE_PATH}")

find_package(Gperftools REQUIRED)
include_directories(GPERFTOOLS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/profiler)

add_executable(profiler_test ${CMAKE_CURRENT_SOURCE_DIR}/example/profiler_test.cpp)
add_executable(heapprofiler_test ${CMAKE_CURRENT_SOURCE_DIR}/example/heapprofiler_test.cpp)

target_link_libraries(profiler_test ${GPERFTOOLS_LIBRARIES})
target_link_libraries(heapprofiler_test ${GPERFTOOLS_LIBRARIES})

