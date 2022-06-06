#pragma once

#include <stdexcept>
#include <string_view>
#include <utility>

#include "fmt/core.h"

namespace fib
{
    struct exception : std::runtime_error
    {
        exception(std::string_view msg) : std::runtime_error{ msg.data() } { }
        template<typename Message, typename... Args>
        exception(Message&& msg, Args&&... args)
            : std::runtime_error{ fmt::format(std::forward<Message>(msg), std::forward<Args>(args)...) }
        {
        }
    };
}  // namespace fib