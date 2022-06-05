#include "grpc_sender.hpp"

namespace fib::rpc
{
    grpc_sender::grpc_sender(std::string address, int port) : rpc_sender_base{ std::move(address), port } { }
    response grpc_sender::fib(request req) { }
    grpc_sender::~grpc_sender() noexcept { }
}  // namespace fib::rpc