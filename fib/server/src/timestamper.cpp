#include "timestamper.hpp"

namespace fib
{
    timestamper::timestamper() : m_start_point{ clock::duration::zero() }, m_running{ false } { }
    std::int64_t timestamper::elapsed()
    {
        if (m_running)
        {
            return std::chrono::duration_cast<resolution>(clock::now() - m_start_point).count();
        }

        else
        {
            m_running     = true;
            m_start_point = clock::now();
            return clock::duration::zero().count();
        }
    }
}  // namespace fib