cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)

project(cpp_demos CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

option(WITH_BOOST "WITH_BOOST" OFF)
option(WITH_CAPNP "WITH_CAPNP" OFF)
option(WITH_GLOG "WITH_GLOG" OFF)
option(WITH_PROTOBUF "WITH_PROTOBUF" OFF)
option(WITH_SYSTEMC "WITH_SYSTEMC" OFF)

# https://cmake.org/cmake/help/latest/policy/CMP0077.html
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# FetchContent
include(fetch.cmake)

if(WITH_BOOST)
  find_package(Boost REQUIRED CONFIG)
endif()

# spdlog is always required
find_package(spdlog REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message("Python3_LIBRARIES: ${Python3_LIBRARIES}")

add_subdirectory(call_before_main)
add_subdirectory(enum)
add_subdirectory(fstream)
add_subdirectory(glibc_version)
add_subdirectory(python3)
add_subdirectory(spdlog)
add_subdirectory(variadic_template)

# need 3rd libs, but disbale manually
add_subdirectory(backward_cpp)
add_subdirectory(fmt)

if(WITH_BOOST)
  add_subdirectory(boost_variant)
endif()

if(WITH_CAPNP)
  add_subdirectory(canproto)
endif()

if(WITH_GLOG)
  add_subdirectory(glog)
endif()

if(WITH_PROTOBUF)
  add_subdirectory(protobuf)
  if(WITH_GRPC)
    add_subdirectory(protobuf_grpc)
  endif()
endif()

if(WITH_SYSTEMC)
  add_subdirectory(systemc)
endif()
