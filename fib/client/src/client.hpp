#pragma once

#include "rpc.hpp"

struct client
{
    void hello();

private:
    rpc m_rpc;
};