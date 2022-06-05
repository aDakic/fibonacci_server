#include "server.hpp"

#include "factory.hpp"
#include "fmt/core.h"

namespace fib
{
    server::server(std::string address, int port)
        : m_receiver{ rpc::factory::make_receiver(rpc::type::grpc, std::move(address), port,
                                                  [&](auto req) { return get_fib(req); }) }
    {
    }

    void server::start() { m_receiver->start(); }
    void server::stop() { m_receiver->stop(); }

    rpc::response server::get_fib(rpc::request req)
    {
        const auto result = calculate(req.number);
        return { std::to_string(result) };
    }

    std::uint64_t server::calculate(std::uint64_t number) noexcept
    {
        std::uint64_t a = 0;
        std::uint64_t b = 1;
        std::uint64_t c = 0;

        for (std::uint64_t i = 2; i <= number; ++i)
        {
            c = a + b;
            a = b;
            b = c;
        }

        return c;
    }
}  // namespace fib
