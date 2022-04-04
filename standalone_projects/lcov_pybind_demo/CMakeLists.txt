cmake_minimum_required(VERSION 3.5)

# https://stackoverflow.com/questions/32197663
cmake_policy(SET CMP0026 OLD)

project(lcov_pybind11)

option(WITH_COVERAGE "build with coverage" ON)

# https://pybind11.readthedocs.io/en/stable/compiling.html#building-with-cmake
find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

pybind11_add_module(lib lib.cpp)
get_target_property(lib_loc lib LOCATION)

enable_testing()
# may need to set Python_EXECUTABLE manually
# https://cmake.org/cmake/help/git-stage/module/FindPython.html
add_test(test_py ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/test.py)

if(WITH_COVERAGE)
  set(CMAKE_CXX_FLAGS
      "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

  add_custom_target(
    coverage
    COMMAND cp ${lib_loc} ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    COMMAND sh ${CMAKE_SOURCE_DIR}/scripts/coverage.sh
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  add_dependencies(coverage lib)
endif(WITH_COVERAGE)
