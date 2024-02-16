add_library(lib_a SHARED lib_a.cpp)
target_link_libraries(lib_a spdlog)

add_library(lib_b SHARED lib_b.cpp)
target_link_libraries(lib_b spdlog)

add_executable(exe_call_before_main main.cpp)
target_link_libraries(exe_call_before_main lib_a lib_b)
