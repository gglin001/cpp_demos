add_library(lib_a SHARED lib_a.cpp)
target_link_libraries(lib_a glog::glog)

add_library(lib_b SHARED lib_b.cpp)
target_link_libraries(lib_b glog::glog)

add_executable(call_before_main main.cpp)
target_link_libraries(call_before_main lib_a lib_b)
