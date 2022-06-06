#include "client.hpp"

#include "factory.hpp"
#include "logger.hpp"

namespace fib
{
    client::client(std::string address, int port)
        : m_sender{ rpc::factory::make_sender(rpc::type::grpc, std::move(address), port) }
    {
        log::debug("Fibonacci client successfully created.");
    }

    rpc::response client::fib(const rpc::request req)
    {
        log::debug("Sending request: {}", req.number);
        return m_sender->fib(req);
    }
}  // namespace fib
