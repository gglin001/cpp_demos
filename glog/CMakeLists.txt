# glog
FetchContent_Declare(
  glog
  SYSTEM OVERRIDE_FIND_PACKAGE
  GIT_REPOSITORY https://github.com/google/glog.git
  GIT_TAG v0.5.0)
set(WITH_GFLAGS OFF)
set(sWITH_GTEST OFF)
set(WITH_UNWIND OFF)
set(BUILD_TESTING OFF)
FetchContent_MakeAvailable(glog)

find_package(glog REQUIRED)

add_executable(exe_glog glog.cpp)
target_link_libraries(exe_glog glog::glog)
