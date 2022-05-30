set(sources
    src/rpc.cpp)

set(headers
    src/rpc.hpp)

add_library(rpc ${headers} ${sources})
add_library(${PROJECT_NAME}::rpc ALIAS rpc)
target_include_directories(rpc INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(rpc PUBLIC cxx_std_17)