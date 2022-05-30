#include "client.hpp"
#include <iostream>

void client::hello()
{ std::cout << "Hello from client.\nand "; m_rpc.hello(); }