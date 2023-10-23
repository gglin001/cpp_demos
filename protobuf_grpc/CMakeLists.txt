include(FindProtobuf)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

find_package(gRPC CONFIG REQUIRED)
find_package(Protobuf REQUIRED)
add_library(ProtoTest message.proto)
target_link_libraries(ProtoTest PUBLIC gRPC::grpc++)
protobuf_generate(TARGET ProtoTest)
protobuf_generate(
    TARGET ProtoTest
    LANGUAGE grpc
    PLUGIN protoc-gen-grpc=$<TARGET_FILE:gRPC::grpc_cpp_plugin>
    PLUGIN_OPTIONS generate_mock_code=true
    GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc)

# protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS message.proto)
# protobuf_generate(${_append_arg} LANGUAGE cpp EXPORT_MACRO ${protobuf_generate_cpp_EXPORT_MACRO} OUT_VAR _outvar ${_import_arg} PROTOS ${_proto_files})
# protobuf_generate(LANGUAGE gprc OUT_VAR PROTO_GPRC_SRCS PROTOS message.proto)
# protobuf_generate(
#   #   TARGET
#   #   my-service
#   OUT_VAR
#   PROTO_GPRC_SRCS
#   LANGUAGE
#   grpc
#   GENERATE_EXTENSIONS
#   .grpc.pb.h
#   .grpc.pb.cc
#   PLUGIN
#   "protoc-gen-grpc=${grpc_cpp_plugin_location}")
# message("PROTO_GPRC_SRCS: ${PROTO_GPRC_SRCS}")

# add_library(proto STATIC ${PROTO_SRCS} ${PROTO_HDRS})
# target_link_libraries(proto protobuf::libprotobuf)

add_executable(exe_protobuf_grpc main.cpp)
target_link_libraries(exe_protobuf_grpc ProtoTest)
