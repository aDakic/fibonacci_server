#include "client.hpp"
#include "logger.hpp"
#include "program_options.hpp"

int main(int argc, char* argv[])
{
    fib::po::client_options prog_ops;
    const auto success = fib::po::parse(argc, argv, prog_ops);
    if (!success)
    {
        return EXIT_FAILURE;
    }

    fib::log::setup(prog_ops.server.log_level);

    try
    {
        fib::client client{ prog_ops.server.ip_address, prog_ops.server.port };

        for (const auto& num : prog_ops.numbers)
        {
            const auto [result, timestamp, count] = client.fib(fib::rpc::request{ num });
            fib::log::info("fib({}): {} timestamp: {} count: {}\n", num, result, timestamp, count);
        }
    }
    catch (const std::exception& e)
    {
        fib::log::error("{}", e.what());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}