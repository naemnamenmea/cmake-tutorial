#include "main.hpp"
#include "numeric_math.hpp"

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

  // imported lib
  {
    cout << round(0.7,1) << endl;
    cout << round(0.3,1) << endl;

    cout << round(0.7,0) << endl;
    cout << round(0.7,2) << endl;
  }  

  return 0;
}