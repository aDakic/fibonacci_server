#pragma once

#include <cstdint>
#include <functional>
#include <string>

namespace fib::rpc
{
    struct request
    {
        std::uint64_t number;
    };

    struct response
    {
        std::string result;
        std::int64_t timestamp;
        std::uint64_t count;
    };

    using rpc_callback = std::function<response(const request)>;
}  // namespace fib::rpc