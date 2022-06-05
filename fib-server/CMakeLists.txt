add_executable(fib-server main.cpp)
target_compile_features(fib-server PUBLIC cxx_std_17)
target_link_libraries(fib-server PUBLIC fib::server fib::utils)