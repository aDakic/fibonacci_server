#pragma once

#include <memory>

#include "grpc_receiver.hpp"
#include "grpc_sender.hpp"
#include "receiver_base.hpp"
#include "sender_base.hpp"

namespace fib::rpc
{
    enum class type : std::uint8_t
    {
        grpc = 0
    };

    struct factory
    {
        template<typename... Args>
        static std::unique_ptr<receiver_base> make_receiver(type rpc_type, Args&&... args)
        {
            if (rpc_type == type::grpc)
            {
                return std::make_unique<grpc_receiver>(std::forward<Args>(args)...);
            }
            else
            {
                throw std::runtime_error{ "Unsported RPC receiver" };
            }
        }

        template<typename... Args>
        static std::unique_ptr<sender_base> make_sender(type rpc_type, Args&&... args)
        {
            if (rpc_type == type::grpc)
            {
                return std::make_unique<grpc_sender>(std::forward<Args>(args)...);
            }
            else
            {
                throw std::runtime_error{ "Unsported RPC sender" };
            }
        }
    };
}  // namespace fib::rpc