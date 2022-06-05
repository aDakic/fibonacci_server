#pragma once

#include <memory>
#include "rpc_receiver_base.hpp"

namespace fib
{


    class fib_server
    {
    public:
        fib_server(std::string address, int port);

        void start();
        void stop();
    private:
        rpc::response get_fib(rpc::request req);

        std::unique_ptr<rpc::rpc_receiver_base> m_receiver;

    };

    }