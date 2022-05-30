cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(fib
        VERSION 1.0.0
        LANGUAGES CXX)

add_subdirectory(fib)
add_subdirectory(fib-client)
add_subdirectory(fib-server)