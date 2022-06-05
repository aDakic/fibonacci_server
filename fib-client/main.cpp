#include "client.hpp"
#include "fmt/core.h"

int main()
{
    fib::client client{ "localhost", 5000 };
    auto [result, timestamp, count] = client.fib({ 3 });

    fmt::print("fib[{}] = {}, timestamp: {} count: {}\n", 3, result, timestamp, count);
    return 0;
}