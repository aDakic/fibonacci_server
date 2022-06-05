#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "boost/program_options.hpp"
#include "logger.hpp"

namespace fib::po
{
    namespace boost_po = boost::program_options;

    struct server_options
    {
        std::string ip_address;
        int port;
        std::string log_level;

        void add_options(boost_po::options_description& description);
    };

    struct client_options
    {
        server_options server;
        std::vector<std::uint64_t> numbers;

        void add_options(boost_po::options_description& description);
    };

    template <typename Options>
    inline bool parse(int argc, char* argv[], Options& opts)
    {
        boost_po::options_description description("Usage");

        try
        {
            description.add_options()("help,h", "Display this help message");
            opts.add_options(description);

            boost_po::variables_map vm;
            boost_po::store(boost_po::command_line_parser(argc, argv).options(description).run(), vm);

            if (vm.count("help") == 1)
            {
                std::cerr << description;
                return false;
            }

            boost_po::notify(vm);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << "\n\n";
            std::cerr << description;

            return false;
        }

        return true;
    }

}  // namespace fib::po
