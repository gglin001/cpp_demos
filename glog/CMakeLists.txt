# build with glog
find_package(glog REQUIRED)
add_executable(demo_glog glog.cpp)
target_link_libraries(demo_glog glog::glog)
