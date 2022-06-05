set(PROTO
    proto/fib.proto)

find_package(gRPC REQUIRED)

add_library(grpc-proto ${PROTO})
target_link_libraries(grpc-proto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++)

target_include_directories(grpc-proto PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET grpc-proto LANGUAGE cpp)
protobuf_generate(TARGET grpc-proto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
set_target_properties(grpc-proto PROPERTIES CXX_CLANG_TIDY "")
