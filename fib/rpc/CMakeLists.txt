set(sources
    src/rpc_receiver_base.cpp)

set(headers
    src/rpc_types.hpp
    src/rpc_receiver_base.hpp)

add_library(rpc ${headers} ${sources})
add_library(${PROJECT_NAME}::rpc ALIAS rpc)
target_include_directories(rpc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(rpc PUBLIC cxx_std_17)