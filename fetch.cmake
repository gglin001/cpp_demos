# https://cmake.org/cmake/help/latest/policy/CMP0077.html
set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# glog
FetchContent_Declare(
  glog
  GIT_REPOSITORY https://github.com/google/glog.git
  GIT_TAG v0.5.0
  OVERRIDE_FIND_PACKAGE)
set(WITH_GFLAGS OFF)
set(sWITH_GTEST OFF)
set(WITH_UNWIND OFF)
set(BUILD_TESTING OFF)
FetchContent_MakeAvailable(glog)

# backward_cpp
FetchContent_Declare(
  backwardcpp
  GIT_REPOSITORY https://github.com/bombela/backward-cpp.git
  GIT_TAG v1.6
  OVERRIDE_FIND_PACKAGE)
if(NOT backwardcpp_POPULATED)
  FetchContent_Populate(backwardcpp)
  set(Backward_ROOT ${backwardcpp_SOURCE_DIR})
endif()

# capnproto
FetchContent_Declare(
  capnproto
  SYSTEM
  GIT_REPOSITORY https://github.com/capnproto/capnproto
  GIT_TAG v0.10.4
  GIT_SHALLOW TRUE
  OVERRIDE_FIND_PACKAGE)
FetchContent_MakeAvailable(capnproto)

FetchContent_Declare(
  protobuf
  SYSTEM
  OVERRIDE_FIND_PACKAGE
  # GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
  GIT_REPOSITORY file:///repos/cpp_demos/other_repos/protobuf
  GIT_TAG v3.20.0
  SOURCE_SUBDIR cmake
  GIT_SHALLOW TRUE)
set(protobuf_BUILD_TESTS OFF)
FetchContent_MakeAvailable(protobuf)