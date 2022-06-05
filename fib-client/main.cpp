#include "fib_client.hpp"
#include "fmt/core.h"

int main()
{
    fib::fib_client client{ "localhost", 5000 };
    auto [result] = client.fib({ 3 });

    fmt::print("fib[{}] = {}\n", 3, result);
    return 0;
}