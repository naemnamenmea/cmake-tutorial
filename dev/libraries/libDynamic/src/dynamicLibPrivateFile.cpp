#include "dynamicLibPrivateFile.hpp"
#include <iostream>

namespace dynamicLibPrivateFile
{
    void f(){
        std::cout << "Hello from" << __FILE__ << std::endl;
    }
}