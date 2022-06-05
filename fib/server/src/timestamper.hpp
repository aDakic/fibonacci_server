#pragma once

#include <chrono>
namespace fib
{
    class timestamper
    {
    public:
        using clock      = std::chrono::steady_clock;
        using resolution = std::chrono::milliseconds;

        timestamper();
        std::int64_t elapsed();

    private:
        bool m_running;
        clock::time_point m_start_point;
    };
}  // namespace fib