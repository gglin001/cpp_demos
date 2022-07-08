# build with glog
find_package(glog REQUIRED)
add_executable(variadic_template variadic_template.cpp)
target_link_libraries(variadic_template glog::glog)
