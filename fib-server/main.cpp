#include <iostream>
#include <atomic>
#include <condition_variable>
#include <csignal>
#include <mutex>

#include "program_options.hpp"
#include "server.hpp"

std::atomic<bool> g_exit{ false };
std::mutex g_mutex;
std::condition_variable g_cond;

int main(int argc, char* argv[])
{
    std::signal(SIGINT, [](int /*signum*/) {
        std::unique_lock lock(g_mutex);
        g_exit = true;
        g_cond.notify_one();
    });

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

        std::unique_lock lock(g_mutex);
        g_cond.wait(lock, []() -> bool { return g_exit; });

        server.stop();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}