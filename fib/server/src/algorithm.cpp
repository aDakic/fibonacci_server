#include "algorithm.hpp"

#include <boost/multiprecision/cpp_int.hpp>

namespace fib
{
    using big_int = boost::multiprecision::cpp_int;

    std::string default_algo::calculate(const std::uint64_t number)
    {
        if (number < overflow_limit)  // NOLINT: false positive
        {
            return std::to_string(calculate<std::uint64_t>(number));
        }
        else
        {
            return calculate<big_int>(number).str();
        }
    }
}  // namespace fib