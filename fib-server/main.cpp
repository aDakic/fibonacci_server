#include <iostream>
#include <thread>

#include "server.hpp"
#include "timestamper.hpp"
int main()
{
    using namespace std::chrono_literals;
    fib::server server{ "localhost", 5000 };
    server.start();

    getchar();

    server.stop();
}