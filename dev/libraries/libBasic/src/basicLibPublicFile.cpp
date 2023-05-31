#include "basicLibPrivateFile.hpp"
#include "basicLibPublicFile.hpp"

namespace basicLibPublicFile
{
    void f()
    {
        basicLibPrivateFile::f();
    }
}