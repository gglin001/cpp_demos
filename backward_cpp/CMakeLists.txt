add_executable(demo_backward backward.cpp)
target_link_libraries(demo_backward glog::glog Backward::Backward)
