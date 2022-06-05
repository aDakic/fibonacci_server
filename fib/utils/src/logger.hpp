#pragma once

#include <string_view>
#include <utility>

#include "spdlog/spdlog.h"

namespace fib::log
{
    enum class level : std::uint8_t
    {
        error = 0,
        info  = 1,
        debug = 2
    };

    inline void setup(level log_level)
    {
        switch (log_level)
        {
            case level::error: spdlog::set_level(spdlog::level::err); break;
            case level::info: spdlog::set_level(spdlog::level::info); break;
            case level::debug: spdlog::set_level(spdlog::level::debug); break;
        }
    }

    inline void setup(std::string_view log_level)
    {
        if (log_level == "error")
        {
            spdlog::set_level(spdlog::level::err);
        }
        else if (log_level == "info")
        {
            spdlog::set_level(spdlog::level::info);
        }
        else if (log_level == "debug")
        {
            spdlog::set_level(spdlog::level::debug);
        }
    }

    template<typename Message, typename... Args>
    inline void error(Message&& msg, Args&&... args)
    {
        spdlog::error(std::forward<Message>(msg), std::forward<Args>(args)...);
    }

    template<typename Message, typename... Args>
    inline void info(Message&& msg, Args&&... args)
    {
        spdlog::info(std::forward<Message>(msg), std::forward<Args>(args)...);
    }

    template<typename Message, typename... Args>
    inline void debug(Message&& msg, Args&&... args)
    {
        spdlog::debug(std::forward<Message>(msg), std::forward<Args>(args)...);
    }
}  // namespace fib::log