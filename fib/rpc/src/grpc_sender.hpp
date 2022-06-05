#pragma once

#include "rpc_sender_base.hpp"

namespace fib::rpc
{
    class grpc_sender : public rpc_sender_base
    {
    public:
        grpc_sender(std::string address, int port);
        response fib(request req) override;
        ~grpc_sender() noexcept override;
    };
}  // namespace fib::rpc