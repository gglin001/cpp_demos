find_package(Python3 COMPONENTS Interpreter Development)
message("Python3_EXECUTABLE: ${Python3_EXECUTABLE}")
message("Python3_INCLUDE_DIRS: ${Python3_INCLUDE_DIRS}")
message("Python3_LIBRARIES: ${Python3_LIBRARIES}")

add_executable(py3 py3.cpp)
include_directories(${Python3_INCLUDE_DIRS})
target_link_libraries(py3 ${Python3_LIBRARIES})
