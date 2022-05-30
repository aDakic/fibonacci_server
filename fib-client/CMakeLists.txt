add_executable(fib-client main.cpp)
target_compile_features(fib-client PUBLIC cxx_std_17)
target_link_libraries(fib-client PUBLIC fib::client)