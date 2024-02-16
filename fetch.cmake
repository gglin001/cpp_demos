# spdlog
FetchContent_Declare(
  spdlog
  SYSTEM
  GIT_REPOSITORY https://github.com/gabime/spdlog
  GIT_TAG v1.13.0
  GIT_SHALLOW TRUE
  OVERRIDE_FIND_PACKAGE)
FetchContent_MakeAvailable(spdlog)

if(WITH_BOOST)
  # boost
  FetchContent_Declare(
    boost
    SYSTEM OVERRIDE_FIND_PACKAGE
    URL https://github.com/boostorg/boost/releases/download/boost-1.81.0/boost-1.81.0.tar.xz
  )
  FetchContent_MakeAvailable(boost)
endif()

if(WITH_CAPNP)
  # capnproto
  FetchContent_Declare(
    capnproto
    SYSTEM OVERRIDE_FIND_PACKAGE
    # TODO: ??
    GIT_REPOSITORY https://github.com/capnproto/capnproto
    # GIT_REPOSITORY "/repos/cpp_demos/_demos/capnproto"
    # URL "/repos/cpp_demos/_demos/capnproto"
    # GIT_TAG v0.10.4
    GIT_SHALLOW TRUE)
  FetchContent_MakeAvailable(capnproto)
endif()

if(WITH_PROTOBUF)
  # protobuf
  FetchContent_Declare(
    protobuf
    SYSTEM OVERRIDE_FIND_PACKAGE
    GIT_REPOSITORY https://github.com/protocolbuffers/protobuf.git
    GIT_TAG v3.20.0
    SOURCE_SUBDIR cmake
    GIT_SHALLOW TRUE)
  set(protobuf_BUILD_TESTS OFF)
  FetchContent_MakeAvailable(protobuf)

  if(WITH_GRPC)
    # grpc
    FetchContent_Declare(
      grpc
      SYSTEM
      GIT_REPOSITORY https://github.com/grpc/grpc
      GIT_TAG v1.49.2
      GIT_SHALLOW TRUE
      OVERRIDE_FIND_PACKAGE)
    set(gRPC_BUILD_CSHARP_EXT OFF)
    set(gRPC_BUILD_GRPC_CSHARP_PLUGIN OFF)
    set(gRPC_BUILD_GRPC_NODE_PLUGIN OFF)
    set(gRPC_BUILD_GRPC_OBJECTIVE_C_PLUGIN OFF)
    set(gRPC_BUILD_GRPC_PHP_PLUGIN OFF)
    set(gRPC_BUILD_GRPC_RUBY_PLUGIN OFF)
    FetchContent_MakeAvailable(grpc)
  endif()
endif()
