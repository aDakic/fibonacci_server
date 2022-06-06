#pragma once

#include <memory>
#include <unordered_map>

#include "receiver_base.hpp"
#include "timestamper.hpp"

namespace fib
{
    class server
    {
    public:
        server(std::string address, int port);

        void start();
        void stop();

    private:
        rpc::response get_fib(const rpc::request req);

        std::unique_ptr<rpc::receiver_base> m_receiver;
        std::unordered_map<std::uint64_t, std::uint64_t> m_registry;
        timestamper m_timestamper;
    };

}  // namespace fib