# build with glog
find_package(glog REQUIRED)
add_executable(glog glog.cpp)
target_link_libraries(glog glog::glog)
