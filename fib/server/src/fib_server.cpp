#include "fib_server.hpp"
#include "grpc_receiver.hpp"

namespace fib
{
    fib_server::fib_server(std::string address, int port) : m_receiver { std::make_unique<rpc::grpc_receiver>(std::move(address), port, [&](auto req) { return get_fib(req); })} {}

    void fib_server::start() { m_receiver->start(); }
    void fib_server::stop() { m_receiver->stop(); }

    rpc::response fib_server::get_fib(rpc::request req) {}
}
