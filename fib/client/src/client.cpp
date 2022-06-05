#include "client.hpp"
#include "grpc_sender.hpp"

namespace fib
{
    fib_client::fib_client(std::string address, int port) : m_sender { std::make_unique<rpc::grpc_sender>(std::move(address), port)} {}
    rpc::response fib_client::fib(rpc::request req) { return m_sender->fib(req); }
}
