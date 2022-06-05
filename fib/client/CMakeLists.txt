set(sources
    src/client.cpp)

set(headers
    src/client.hpp)

add_library(client ${headers} ${sources})
add_library(${PROJECT_NAME}::client ALIAS client)

target_link_libraries(client PUBLIC fib::rpc fib::utils)
target_compile_features(client PUBLIC cxx_std_17)
target_include_directories(client INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)