#pragma once

#include "types.hpp"

namespace fib::rpc
{
    class sender_base
    {
    public:
        sender_base(std::string address, int port);
        virtual response fib(request req) = 0;
        virtual ~sender_base()            = default;

    protected:
        std::string m_ip_address;
        int m_port;
    };
}  // namespace fib::rpc