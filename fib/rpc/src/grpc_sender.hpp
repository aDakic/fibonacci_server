#pragma once

#include "proto/fib.grpc.pb.h"
#include "sender_base.hpp"

namespace fib::rpc
{
    class grpc_sender : public sender_base
    {
    public:
        grpc_sender(std::string address, int port);
        response fib(const request req) override;
        ~grpc_sender() noexcept override = default;

    private:
        std::unique_ptr<fib_grpc::Stub> m_sender;
    };
}  // namespace fib::rpc