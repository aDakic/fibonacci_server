#include "client.hpp"
#include "fmt/core.h"
#include "program_options.hpp"

int main(int argc, char* argv[])
{
    fib::po::client_options prog_ops;
    const auto success = fib::po::parse(argc, argv, prog_ops);
    if (!success)
    {
        return EXIT_FAILURE;
    }

    try
    {
        fib::client client{ prog_ops.server.ip_address, prog_ops.server.port };

        for (const auto& num : prog_ops.numbers)
        {
            const auto [result, timestamp, count] = client.fib({ num });
            fmt::print("fib({}): {} timestamp: {} count: {}\n", num, result, timestamp, count);
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}