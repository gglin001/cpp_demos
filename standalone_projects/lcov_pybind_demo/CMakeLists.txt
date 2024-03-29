cmake_minimum_required(VERSION 3.5)

project(lcov_pybind11)

option(WITH_COVERAGE "build with coverage" ON)

# https://pybind11.readthedocs.io/en/stable/compiling.html#building-with-cmake
find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

pybind11_add_module(lib lib.cpp)
# https://cmake.org/cmake/help/latest/policy/CMP0026.html
set(LIB_LOC $<TARGET_FILE:lib>)

enable_testing()
# may need to set Python_EXECUTABLE manually
# https://cmake.org/cmake/help/git-stage/module/FindPython.html
add_test(test_py ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/test.py)

if(WITH_COVERAGE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage")

  add_custom_target(
    coverage
    COMMENT "do coverage test"
    COMMAND cp ${LIB_LOC} ${CMAKE_SOURCE_DIR}
    COMMAND ${CMAKE_MAKE_PROGRAM} test
    COMMAND sh ${CMAKE_SOURCE_DIR}/scripts/coverage.sh
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
  add_dependencies(coverage lib)
endif(WITH_COVERAGE)
