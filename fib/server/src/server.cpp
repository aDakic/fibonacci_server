#include "server.hpp"

#include "algorithm.hpp"
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
        auto result          = default_algo::calculate(req.number);
        const auto timestamp = m_timestamper.elapsed();

        auto [iter, is_new_element] = m_registry.emplace(req.number, 1);
        auto& count                 = iter->second;

        if (!is_new_element)
        {
            count += 1;
        }

        return { result, timestamp, count };
    }
}  // namespace fib
