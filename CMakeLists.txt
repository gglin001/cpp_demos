cmake_minimum_required(VERSION 3.26.0 FATAL_ERROR)

project(cpp_demos CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

option(WITH_BOOST "WITH_BOOST" OFF)
option(WITH_PROTOBUF "WITH_PROTOBUF" OFF)
option(WITH_CAPNP "WITH_CAPNP" OFF)

# FetchContent
include(fetch.cmake)

if(WITH_BOOST)
  find_package(Boost REQUIRED CONFIG)
endif()

find_package(glog REQUIRED)
find_package(Backward REQUIRED)

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message("Python3_LIBRARIES: ${Python3_LIBRARIES}")

add_subdirectory(glog)
add_subdirectory(fmt)
add_subdirectory(enum)
add_subdirectory(fstream)
# need gcc compiler
add_subdirectory(backward_cpp)
add_subdirectory(glibc_version)
add_subdirectory(python3)
add_subdirectory(variadic_template)
add_subdirectory(call_before_main)

if(WITH_CAPNP)
  add_subdirectory(canproto)
endif()

if(WITH_PROTOBUF)
  add_subdirectory(protobuf)
  if(WITH_GRPC)
    add_subdirectory(protobuf_grpc)
  endif()
endif()

if(WITH_BOOST)
  add_subdirectory(boost_variant)
endif()
