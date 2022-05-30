#pragma once

#include "rpc.hpp"

struct server
{
    void hello();

private:
    rpc m_rpc;
};