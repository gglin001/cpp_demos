cmake_minimum_required(VERSION 3.5)

project(a.out)
set(CMAKE_CXX_STANDARD 14)

option(WITH_COVERAGE "build with coverage" ON)

add_executable(a.out main.cpp)

enable_testing()

add_test(test_a.out ${CMAKE_CURRENT_BINARY_DIR}/a.out)

if(WITH_COVERAGE)
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

  add_custom_target(
    coverage
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    COMMAND sh ${CMAKE_SOURCE_DIR}/scripts/coverage.sh
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  add_dependencies(coverage a.out)
endif(WITH_COVERAGE)
