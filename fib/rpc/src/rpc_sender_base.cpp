#include "rpc_sender_base.hpp"

namespace fib::rpc
{
    rpc_sender_base::rpc_sender_base(std::string address, int port) : m_ip_address { std::move(address) }, m_port { port } {}
}