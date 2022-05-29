cmake_minimum_required(VERSION 3.10)

project(riscv_gdb)

add_executable(hello hello.cpp)
target_link_libraries(hello)
