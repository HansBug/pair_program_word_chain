#include <iostream>     // cout
#include <cstdlib>      // exit
#include "error.h"

void error(const char *msg)
{
    std::cout << "error: " << msg << std::endl;
    std::exit(1);
}