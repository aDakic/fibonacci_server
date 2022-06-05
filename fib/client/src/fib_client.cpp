#include "fib_client.hpp"

#include "factory.hpp"

namespace fib
{
    fib_client::fib_client(std::string address, int port)
        : m_sender{ rpc::factory::make_sender(rpc::type::grpc, std::move(address), port) }
    {
    }

    rpc::response fib_client::fib(rpc::request req) { return m_sender->fib(req); }
}  // namespace fib
