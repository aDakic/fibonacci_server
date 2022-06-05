#pragma once

#include "proto/fib.grpc.pb.h"
#include "rpc_sender_base.hpp"

namespace fib::rpc
{
    class grpc_sender : public rpc_sender_base
    {
    public:
        grpc_sender(std::string address, int port);
        response fib(request req) override;
        ~grpc_sender() noexcept override = default;

    private:
        std::unique_ptr<fib_grpc::Stub> m_sender;
    };
}  // namespace fib::rpc