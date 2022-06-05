#pragma once

#include <memory>

#include "sender_base.hpp"

namespace fib
{
    class client
    {
    public:
        client(std::string address, int port);
        rpc::response fib(rpc::request req);

    private:
        std::unique_ptr<rpc::sender_base> m_sender;
    };
}  // namespace fib