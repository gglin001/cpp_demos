add_executable(exe_backward backward.cpp)
target_link_libraries(exe_backward glog::glog Backward::Backward)
