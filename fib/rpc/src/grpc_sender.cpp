#include "grpc_sender.hpp"

#include "fmt/core.h"
#include "grpcpp/grpcpp.h"

namespace fib::rpc
{
    grpc_sender::grpc_sender(std::string address, int port)
        : sender_base{ std::move(address), port },
          m_sender{ fib_grpc::NewStub(
              grpc::CreateChannel(fmt::format("{}:{}", m_ip_address, m_port), grpc::InsecureChannelCredentials())) }
    {
    }

    response grpc_sender::fib(request req)
    {
        fib_request request;
        request.set_number(req.number);

        fib_reply reply;
        grpc::ClientContext context;

        const auto status = m_sender->fib(&context, request, &reply);

        if (!status.ok())
        {
            throw std::runtime_error{ fmt::format("{}:{}", status.error_code(), status.error_message()) };
        }
        else
        {
            return { reply.result() };
        }
    }
}  // namespace fib::rpc