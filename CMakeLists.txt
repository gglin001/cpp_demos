cmake_minimum_required(VERSION 3.24.0 FATAL_ERROR)

project(cpp_demos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# https://cmake.org/cmake/help/latest/policy/CMP0077.html
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
include(FetchContent)

# glog
FetchContent_Declare(
  glog
  GIT_REPOSITORY https://github.com/google/glog.git
  GIT_TAG v0.5.0
  OVERRIDE_FIND_PACKAGE)
set(WITH_GFLAGS OFF)
FetchContent_MakeAvailable(glog)

add_subdirectory(glog)
# add_subdirectory(boost_variant)
add_subdirectory(enum)
add_subdirectory(fstream)
# add_subdirectory(protobuf)
# add_subdirectory(backward_cpp)
add_subdirectory(glibc_version)
add_subdirectory(python3)
add_subdirectory(variadic_template)
add_subdirectory(call_before_main)
