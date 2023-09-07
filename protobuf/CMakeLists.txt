# include(FindProtobuf)
# find_package(Protobuf CONFIG REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

message("Protobuf: ${Protobuf}")
message("PROTOBUF_LIBRARY: ${PROTOBUF_LIBRARY}")
message("PROTOC: ${PROTOC}")
message("protobuf: ${protobuf}")

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS message.proto)

# add_executable(protobuf protobuf.cpp ${PROTO_SRCS} ${PROTO_HDRS})
# target_link_libraries(protobuf ${Protobuf_LIBRARIES})

# # or

add_library(proto SHARED ${PROTO_SRCS} ${PROTO_HDRS})
# add_library(proto STATIC ${PROTO_HDRS} ${PROTO_SRCS})
# target_link_libraries(proto ${PROTOBUF_LIBRARY})
target_link_libraries(proto protobuf::libprotobuf)

add_executable(demo_protobuf protobuf.cpp)
# target_link_libraries(demo_protobuf ${Protobuf_LIBRARIES} proto)
# target_link_libraries(demo_protobuf proto protobuf::libprotobuf)
target_link_libraries(demo_protobuf proto)
