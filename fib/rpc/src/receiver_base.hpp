#pragma once

#include "types.hpp"

namespace fib::rpc
{
    class receiver_base
    {
    public:
        receiver_base(std::string address, int port, rpc_callback cb);

        virtual void start()     = 0;
        virtual void stop()      = 0;
        virtual ~receiver_base() = default;

    protected:
        std::string m_ip_address;
        int m_port;
        rpc_callback m_on_receive;
    };
}  // namespace fib::rpc