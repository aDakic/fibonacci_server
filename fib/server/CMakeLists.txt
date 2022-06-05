set(sources
    src/timestamper.cpp
    src/algorithm.cpp
    src/server.cpp)

set(headers
    src/timestamper.hpp
    src/algorithm.hpp
    src/server.hpp)

find_package(Boost REQUIRED)

add_library(server ${headers} ${sources})
add_library(${PROJECT_NAME}::server ALIAS server)

target_link_libraries(server PUBLIC fib::rpc Boost::boost fib::utils)
target_compile_features(server PUBLIC cxx_std_17)
target_include_directories(server INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)