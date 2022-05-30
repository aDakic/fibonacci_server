cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(fib
        VERSION 1.0.0
        LANGUAGES CXX)

include(cmake/standard_settings.cmake)
include(cmake/tools.cmake)

add_subdirectory(fib)
add_subdirectory(fib-client)
add_subdirectory(fib-server)