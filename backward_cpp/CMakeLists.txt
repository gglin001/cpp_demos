# backward_cpp
FetchContent_Declare(
  backwardcpp
  SYSTEM OVERRIDE_FIND_PACKAGE
  GIT_REPOSITORY https://github.com/bombela/backward-cpp.git
  GIT_TAG v1.6)
if(NOT backwardcpp_POPULATED)
  FetchContent_Populate(backwardcpp)
  set(Backward_ROOT ${backwardcpp_SOURCE_DIR})
endif()

find_package(Backward REQUIRED)

add_executable(exe_backward backward.cpp)
target_link_libraries(exe_backward glog::glog Backward::Backward)
