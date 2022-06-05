cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(fib
        VERSION 1.0.0
        LANGUAGES CXX)

include(cmake/standard_settings.cmake)
include(cmake/tools.cmake)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR} ${CMAKE_MODULE_PATH})
set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR} ${CMAKE_PREFIX_PATH})

add_subdirectory(fib)
add_subdirectory(fib-client)
add_subdirectory(fib-server)