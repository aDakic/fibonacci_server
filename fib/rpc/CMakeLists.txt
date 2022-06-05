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

set(sources
    src/receiver_base.cpp
    src/sender_base.cpp
    src/grpc_receiver.cpp
    src/grpc_sender.cpp)

set(headers
    src/types.hpp
    src/receiver_base.hpp
    src/sender_base.hpp
    src/grpc_receiver.hpp
    src/grpc_sender.hpp
    src/factory.hpp)

find_package(fmt REQUIRED)

add_library(rpc ${headers} ${sources})
add_library(${PROJECT_NAME}::rpc ALIAS rpc)

target_include_directories(rpc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(rpc PUBLIC cxx_std_17)
target_link_libraries(rpc grpc-proto fmt::fmt)