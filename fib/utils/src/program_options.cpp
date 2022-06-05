#include "program_options.hpp"

namespace fib::po
{
    void server_options::add_options(boost_po::options_description& description)
    {
        // clang-format off
        description.add_options()
        ("ip_address,ip", boost_po::value<std::string>(&ip_address)->default_value("localhost"), "Server IP address")
        ("port,p", boost_po::value<int>(&port)->required(), "Server port");
        // clang-format on
    }

    void client_options::add_options(boost_po::options_description& description)
    {
        server.add_options(description);

        // clang-format off
        description.add_options()
        ("numbers", boost_po::value<std::vector<std::uint64_t>>(&numbers)->multitoken()->required(), "Numbers for calculation");
        // clang-format on
    }
}