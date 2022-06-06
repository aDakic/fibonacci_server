#include "grpc_receiver.hpp"

#include "exception.hpp"
#include "fmt/core.h"
#include "logger.hpp"

namespace fib::rpc
{
    grpc_receiver::grpc_receiver(std::string address, int port, rpc_callback cb)
        : receiver_base{ std::move(address), port, std::move(cb) }, m_running{ false }
    {
        const auto server_address = fmt::format("{}:{}", m_ip_address, m_port);
        m_builder.AddListeningPort(server_address, grpc::InsecureServerCredentials()).RegisterService(this);

        log::debug("gRPC receiver successfully created.");
    }

    grpc_receiver::~grpc_receiver() noexcept { stop(); }

    void grpc_receiver::start()
    {
        if (!m_running)
        {
            m_server = m_builder.BuildAndStart();
            if (!m_server)
            {
                throw exception{ "Unable to start gRPC server {}:{}.", m_ip_address, m_port };
            }

            m_server_task = std::thread{ [&]() { m_server->Wait(); } };
            m_running     = true;
            log::debug("gRPC receiver successfully started.");
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
            log::debug("gRPC receiver successfully stopped.");
        }
    }

    grpc::Status grpc_receiver::fib(grpc::ServerContext* /*context*/, const fib_request* request, fib_reply* response)
    {
        const auto number = request->number();
        log::debug("Request received for fib[{}]", number);

        auto [result, timestamp, count] = m_on_receive({ number });

        response->set_result(std::move(result));
        response->set_timestamp(timestamp);
        response->set_count(count);

        return grpc::Status::OK;
    }
}  // namespace fib::rpc