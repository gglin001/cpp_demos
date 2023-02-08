add_executable(py3 py3.cpp)
include_directories(${Python3_INCLUDE_DIRS})
target_link_libraries(py3 ${Python3_LIBRARIES})
