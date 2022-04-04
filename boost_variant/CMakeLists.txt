find_package(glog REQUIRED)
find_package(Boost REQUIRED COMPONENTS)

add_executable(boost_variant boost_variant.cpp)
target_link_libraries(boost_variant glog::glog ${Boost_LIBRARIES})
