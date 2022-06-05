#pragma once

#include <memory>
#include <thread>

#include "grpcpp/grpcpp.h"
#include "proto/fib.grpc.pb.h"
#include "rpc_receiver_base.hpp"

namespace fib::rpc
{
    class grpc_receiver final : public rpc_receiver_base, private fib_grpc::Service
    {
    public:
        grpc_receiver(std::string address, int port, rpc_callback cb);
        ~grpc_receiver() noexcept override;
        void start() override;
        void stop() override;

    private:
        grpc::Status fib(grpc::ServerContext* /*context*/, const fib_request* request, fib_reply* response) override;

        grpc::ServerBuilder m_builder;
        std::unique_ptr<grpc::Server> m_server;
        std::thread m_server_task;
        bool m_running;
    };
}  // namespace fib::rpc