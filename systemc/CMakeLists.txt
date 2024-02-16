# systemc
FetchContent_Declare(
  systemc
  SYSTEM OVERRIDE_FIND_PACKAGE
  GIT_REPOSITORY https://github.com/accellera-official/systemc.git
  GIT_TAG 2.3.4
  GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(systemc)

find_package(SystemCLanguage CONFIG REQUIRED)

add_executable(sc_simple_async main.cpp)
target_include_directories(sc_simple_async PUBLIC "${systemc_SOURCE_DIR}/src")
target_link_libraries(sc_simple_async SystemC::systemc)
