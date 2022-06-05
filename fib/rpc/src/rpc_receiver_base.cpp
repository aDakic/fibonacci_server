#include "rpc_receiver_base.hpp"

namespace fib::rpc
{
    rpc_receiver_base::rpc_receiver_base(std::string address, int port, rpc_callback cb)
        : m_ip_address{ std::move(address) }, m_port{ port }, m_on_receive{ std::move(cb) }
    {
    }
}  // namespace fib::rpc