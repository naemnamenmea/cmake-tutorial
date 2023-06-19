#include "test_runner.h"

void DummyTest()
{

}

int main()
{
  TestRunner tr;
  RUN_TEST(tr, DummyTest);

  return 0;
}