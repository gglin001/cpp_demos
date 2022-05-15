# build with glog & Backward

find_package(glog REQUIRED)

# https://github.com/bombela/backward-cpp
find_package(Backward)

add_executable(backward backward.cpp)
target_link_libraries(backward glog::glog Backward::Backward)
