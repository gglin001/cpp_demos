# fmt
FetchContent_Declare(
  fmt
  SYSTEM OVERRIDE_FIND_PACKAGE
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG 10.1.1
  GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(fmt)

add_executable(exe_fmt main.cpp)
target_link_libraries(exe_fmt fmt::fmt)
