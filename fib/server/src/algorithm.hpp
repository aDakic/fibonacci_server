#pragma once

#include <cstdint>
#include <string>

namespace fib
{
    class default_algo
    {
    public:
        static std::string calculate(std::uint64_t number);

    private:
        template<typename T>
        static T calculate(std::uint64_t number)
        {
            T a = 0;
            T b = 1;
            T c = 0;

            for (std::uint64_t i = 2; i <= number; ++i)
            {
                c = a + b;
                a = b;
                b = c;
            }

            return c;
        }

        static constexpr std::uint64_t overflow_limit = 94;
    };
}  // namespace fib