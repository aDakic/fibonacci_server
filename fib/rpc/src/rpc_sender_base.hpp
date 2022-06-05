#pragma once

#include "rpc_types.hpp"

namespace fib::rpc
{
    class rpc_sender_base
    {
    public:
        rpc_sender_base(std::string address, int port);
        virtual response fib(request req) = 0;
        virtual ~rpc_sender_base()        = default;

    protected:
        std::string m_ip_address;
        int m_port;
    };
}  // namespace fib::rpc