set(sources
    src/server.cpp)

set(headers
    src/server.hpp)

add_library(server ${headers} ${sources})
add_library(${PROJECT_NAME}::server ALIAS server)

target_link_libraries(server PUBLIC fib::rpc)
target_compile_features(server PUBLIC cxx_std_17)
target_include_directories(server INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)