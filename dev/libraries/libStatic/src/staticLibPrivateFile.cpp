#include "staticLibPrivateFile.hpp"
#include "basicLibPublicFile.hpp"
#include <iostream>

namespace staticLibPrivateFile
{
    void f(){
        basicLibPublicFile::f();
    }
}