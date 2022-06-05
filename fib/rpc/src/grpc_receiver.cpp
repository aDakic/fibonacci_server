#include "grpc_receiver.hpp"

namespace fib::rpc
{
    grpc_receiver::grpc_receiver(std::string address, int port, rpc_callback cb)
        : rpc_receiver_base{ std::move(address), port, std::move(cb) }
    {
    }
    grpc_receiver::~grpc_receiver() noexcept { }
    void grpc_receiver::start() { }
    void grpc_receiver::stop() { }

}  // namespace fib::rpc