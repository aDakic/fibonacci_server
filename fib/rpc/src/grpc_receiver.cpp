#include "grpc_receiver.hpp"

#include "fmt/core.h"

namespace fib::rpc
{
    grpc_receiver::grpc_receiver(std::string address, int port, rpc_callback cb)
        : receiver_base{ std::move(address), port, std::move(cb) }, m_running{ false }
    {
        const auto server_address = fmt::format("{}:{}", m_ip_address, m_port);
        m_builder.AddListeningPort(server_address, grpc::InsecureServerCredentials()).RegisterService(this);
    }

    grpc_receiver::~grpc_receiver() noexcept { stop(); }

    void grpc_receiver::start()
    {
        if (!m_running)
        {
            m_server = m_builder.BuildAndStart();
            if (!m_server)
            {
                throw std::runtime_error{ fmt::format("Unable to start gRPC server {}:{}.", m_ip_address, m_port) };
            }

            m_server_task = std::thread{ [&]() { m_server->Wait(); } };
            m_running     = true;
        }
    }

    void grpc_receiver::stop()
    {
        if (m_running)
        {
            m_server->Shutdown();

            if (m_server_task.joinable())
            {
                m_server_task.join();
            }

            m_running = false;
        }
    }

    grpc::Status grpc_receiver::fib(grpc::ServerContext* /*context*/, const fib_request* request, fib_reply* response)
    {
        const auto number = request->number();
        auto [result]     = m_on_receive({ number });

        response->set_result(std::move(result));
        return grpc::Status::OK;
    }
}  // namespace fib::rpc