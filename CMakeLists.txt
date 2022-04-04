cmake_minimum_required(VERSION 3.10)

# cmake_policy(SET CMP0003 NEW)

project(cpp_demos)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(glog)
add_subdirectory(boost_variant)
add_subdirectory(enum)
add_subdirectory(fstream)
add_subdirectory(protobuf)
