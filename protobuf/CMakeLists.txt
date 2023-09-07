include(FindProtobuf)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS message.proto)

add_library(proto STATIC ${PROTO_SRCS} ${PROTO_HDRS})
target_link_libraries(proto protobuf::libprotobuf)

add_executable(exe_protobuf protobuf.cpp)
target_link_libraries(exe_protobuf proto)
