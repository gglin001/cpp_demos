include_directories(${Python3_INCLUDE_DIRS})

add_executable(exe_py3 py3.cpp)
target_link_libraries(exe_py3 ${Python3_LIBRARIES})
