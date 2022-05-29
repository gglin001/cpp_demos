cmake_minimum_required(VERSION 3.10)

project(cpp_demos)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

# # use clangdev in conda env
# if(("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang") AND (DEFINED ENV{CONDA_PREFIX}))
#   add_compile_options(-stdlib=libc++)
#   # add_link_options(-stdlib=libc++ -lc++abi -L$ENV{CONDA_PREFIX}/lib)
#   add_link_options(-stdlib=libc++ -lc++abi)
# endif()

add_subdirectory(glog)
add_subdirectory(boost_variant)
add_subdirectory(enum)
add_subdirectory(fstream)
add_subdirectory(protobuf)
add_subdirectory(backward_cpp)
