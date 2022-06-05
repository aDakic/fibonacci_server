#pragma once

#include "rpc_receiver_base.hpp"

namespace fib::rpc
{
    class grpc_receiver final : public rpc_receiver_base
    {
    public:
        grpc_receiver(std::string address, int port, rpc_callback cb);
        ~grpc_receiver() noexcept override;
        void start() override;
        void stop() override;
    };
}  // namespace fib::rpc