cmake_minimum_required(VERSION 3.24.0 FATAL_ERROR)

project(cpp_demos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

# https://cmake.org/cmake/help/latest/policy/CMP0077.html
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# # glog
# FetchContent_Declare(
#   glog
#   GIT_REPOSITORY https://github.com/google/glog.git
#   GIT_TAG v0.5.0
#   OVERRIDE_FIND_PACKAGE)
# set(WITH_GFLAGS OFF)
# set(WITH_GTEST OFF)
# set(WITH_UNWIND OFF)
# set(BUILD_TESTING OFF)
# FetchContent_MakeAvailable(glog)
# # backward_cpp
# FetchContent_Declare(
#   backwardcpp
#   GIT_REPOSITORY https://github.com/bombela/backward-cpp.git
#   GIT_TAG v1.6
#   OVERRIDE_FIND_PACKAGE)
# if(NOT backwardcpp_POPULATED)
#   FetchContent_Populate(backwardcpp)
#   set(Backward_ROOT ${backwardcpp_SOURCE_DIR})
# endif()
# # capnproto
# FetchContent_Declare(
#   capnproto
#   SYSTEM
#   GIT_REPOSITORY https://github.com/capnproto/capnproto
#   GIT_TAG v0.10.4
#   GIT_SHALLOW TRUE
#   OVERRIDE_FIND_PACKAGE)
# FetchContent_MakeAvailable(capnproto)

FetchContent_Declare(
  protobuf
  SYSTEM
  OVERRIDE_FIND_PACKAGE
  # GIT_REPOSITORY https://github.com/gglin001/protobuf-fork.git
  # GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  GIT_REPOSITORY file:///repos/cpp_demos/other_repos/protobuf
  # GIT_TAG d750fbf
  GIT_TAG v3.20.0
  SOURCE_SUBDIR cmake
  GIT_SHALLOW TRUE)
set(protobuf_BUILD_TESTS OFF)
FetchContent_MakeAvailable(protobuf)

# find_package(glog REQUIRED)
# find_package(Backward)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message("Python3_LIBRARIES: ${Python3_LIBRARIES}")

include(FindProtobuf)
# find_package(Protobuf REQUIRED PATHS "${protobuf_BINARY_DIR}/lib")
# find_package(Protobuf CONFIG REQUIRED)
# include_directories(${Protobuf_INCLUDE_DIRS})
# include_directories(${protobuf_SOURCE_DIR})
message("Protobuf_INCLUDE_DIRS: ${Protobuf_INCLUDE_DIRS}")
message("protobuf_BINARY_DIR: ${protobuf_BINARY_DIR}")

# add_subdirectory(glog)
# add_subdirectory(boost_variant)
# add_subdirectory(enum)
# add_subdirectory(fstream)
add_subdirectory(protobuf)

# need gcc compiler
# add_subdirectory(backward_cpp)

# add_subdirectory(glibc_version)
# add_subdirectory(python3)
# add_subdirectory(variadic_template)
# add_subdirectory(call_before_main)
# add_subdirectory(canproto)
