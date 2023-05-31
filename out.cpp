

// static lib headers

namespace staticLibPublicFile
{
    void f();
}

// dynamic lib headers

#define LibDynamicAPI __declspec(dllexport)

namespace dynamicLibPublicFile
{
    LibDynamicAPI void f();
}

#include <functional>
#include <iostream>
#include <tuple>

using namespace std;

int main()
{
#ifdef LOCAL_RUN
  cout << "Local run" << endl;
#else
  cout << "Remote run" << endl;
#endif

  {
    //auto [first, second] = []() -> pair<int, double> {return {};}();

    [out = ref(cout << "Hello ")] (){out.get() << "World!\n"; }();
  }

  // static lib
  {
    staticLibPublicFile::f();
  }

  // dynamic lib
  {
    dynamicLibPublicFile::f();
  }

  return 0;
}

namespace staticLibPrivateFile
{
    void f();
}

namespace staticLibPublicFile
{
    void f(){
        staticLibPrivateFile::f();
    }
}

namespace dynamicLibPrivateFile
{
    void f();
}

namespace dynamicLibPublicFile
{
    void f(){
        dynamicLibPrivateFile::f();
    }
}