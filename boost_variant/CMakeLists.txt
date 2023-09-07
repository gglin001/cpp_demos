find_package(Boost REQUIRED COMPONENTS variant)

add_executable(exe_boost_variant boost_variant.cpp)
target_link_libraries(exe_boost_variant glog::glog Boost::variant)
