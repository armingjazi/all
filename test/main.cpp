#include "TestRunner.h"
#include "SumGeneTestCase.h"

int main(int argc, char **argv) {
  entw::TestRunner testRunner{};
  testRunner.add(std::make_unique<SumGeneTestCase>());

  return testRunner.run(std::cout);
}