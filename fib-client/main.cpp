#include "client.hpp"

int main()
{
    fib::fib_client client{ "localhost", 5000};
    client.fib({ 3 });

    return 0;
}