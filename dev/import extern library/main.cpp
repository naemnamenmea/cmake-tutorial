#include "test_runner.hpp"

void DummyTest()
{

}

int main()
{
  TestRunner tr;
  RUN_TEST(tr, DummyTest);

  return 0;
}
