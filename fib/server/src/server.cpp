#include "server.hpp"
#include <iostream>

void server::hello() { std::cout << "Hello from server.and\n"; m_rpc.hello(); }