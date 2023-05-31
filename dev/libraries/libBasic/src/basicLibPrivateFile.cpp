#include "basicLibPrivateFile.hpp"
#include <iostream>

namespace basicLibPrivateFile
{
    void f()
    {
        std::cout << "Hello from " << __FILE__ << std::endl;
    }
}