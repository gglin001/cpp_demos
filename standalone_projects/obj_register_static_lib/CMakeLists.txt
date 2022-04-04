cmake_minimum_required(VERSION 3.5)

project(obj_register_static_lib)

set(CMAKE_CXX_STANDARD 14)

set(LIB_SRC "src/lib.cpp" "src/func.cpp")

# a ststic library
add_library(lib STATIC STATIC ${LIB_SRC})
target_include_directories(lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE lib)
