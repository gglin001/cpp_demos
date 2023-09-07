add_executable(demo_boost_variant boost_variant.cpp)
target_link_libraries(demo_boost_variant glog::glog ${Boost_LIBRARIES})
