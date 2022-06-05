#include "client.hpp"
#include "fmt/core.h"

int main()
{
    fib::client client{ "localhost", 5000 };
    auto [result, count] = client.fib({ 3 });

    fmt::print("fib[{}] = {}, count: {}\n", 3, result, count);
    return 0;
}