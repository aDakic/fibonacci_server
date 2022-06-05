#include "sender_base.hpp"

namespace fib::rpc
{
    sender_base::sender_base(std::string address, int port) : m_ip_address{ std::move(address) }, m_port{ port } { }
}  // namespace fib::rpc