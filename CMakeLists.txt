cmake_minimum_required(VERSION 3.24.0 FATAL_ERROR)

project(cpp_demos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# FetchContent
include(fetch.cmake)

find_package(glog REQUIRED)
find_package(Backward REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message("Python3_LIBRARIES: ${Python3_LIBRARIES}")

add_subdirectory(glog)
# add_subdirectory(boost_variant)
add_subdirectory(enum)
add_subdirectory(fstream)
add_subdirectory(protobuf)

# need gcc compiler
add_subdirectory(backward_cpp)

add_subdirectory(glibc_version)
add_subdirectory(python3)
add_subdirectory(variadic_template)
add_subdirectory(call_before_main)
add_subdirectory(canproto)
