#include "fib_server.hpp"

int main()
{
    fib::fib_server server{ "localhost", 5000 };
    server.start();

    getchar();

    server.stop();

    return 0;
}