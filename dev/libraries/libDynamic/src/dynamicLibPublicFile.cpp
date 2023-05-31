#include "dynamicLibPublicFile.hpp"
#include "dynamicLibPrivateFile.hpp"

namespace dynamicLibPublicFile
{
    void f(){
        dynamicLibPrivateFile::f();
    }
}