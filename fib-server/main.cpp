#include <iostream>
#include <thread>

#include "program_options.hpp"
#include "server.hpp"

int main(int argc, char* argv[])
{
    fib::po::server_options prog_ops;
    const auto success = fib::po::parse(argc, argv, prog_ops);
    if (!success)
    {
        return EXIT_FAILURE;
    }

    try
    {
        fib::server server{ prog_ops.ip_address, prog_ops.port };

        server.start();

        getchar();

        server.stop();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}