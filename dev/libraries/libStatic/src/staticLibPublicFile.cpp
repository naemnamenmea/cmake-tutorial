#include "staticLibPublicFile.hpp"
#include "staticLibPrivateFile.hpp"

namespace staticLibPublicFile
{
    void f(){
        staticLibPrivateFile::f();
    }
}