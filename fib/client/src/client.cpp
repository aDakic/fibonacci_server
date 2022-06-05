#include "client.hpp"

#include "factory.hpp"

namespace fib
{
    client::client(std::string address, int port)
        : m_sender{ rpc::factory::make_sender(rpc::type::grpc, std::move(address), port) }
    {
    }

    rpc::response client::fib(rpc::request req) { return m_sender->fib(req); }
}  // namespace fib
