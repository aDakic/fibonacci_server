#pragma once

#include <memory>
#include <unordered_map>
#include "receiver_base.hpp"

namespace fib
{
    class server
    {
    public:
        server(std::string address, int port);

        void start();
        void stop();

    private:
        rpc::response get_fib(rpc::request req);
        static std::uint64_t calculate(std::uint64_t number) noexcept;

        std::unique_ptr<rpc::receiver_base> m_receiver;
        std::unordered_map<std::uint64_t, std::uint64_t> m_registry;
    };

}  // namespace fib